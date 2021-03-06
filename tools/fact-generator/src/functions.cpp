#include <llvm/Config/llvm-config.h>
#include <llvm/IR/Attributes.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/Function.h>
#include "debuginfo_predicate_groups.hpp"
#include "predicate_groups.hpp"
#include "FactGenerator.hpp"
#include <iostream>

using cclyzer::FactGenerator;
namespace pred = cclyzer::predicates;


//------------------------------------------------------------------------------
// Record Function (but not the function body)
//------------------------------------------------------------------------------

void
FactGenerator::writeFunction(
    const llvm::Function& func,
    const refmode_t& funcref)
{
    // Serialize function properties
    refmode_t visibility = refmode(func.getVisibility());
    refmode_t linkage = refmode(func.getLinkage());
    refmode_t typeSignature = recordType(func.getFunctionType());

#if LLVM_VERSION_MAJOR == 3
# if LLVM_VERSION_MINOR >= 8
    // Record function subprogram
    if (const llvm::DISubprogram *subprogram = func.getSubprogram()) {
        refmode_t subprogramId = refmode<llvm::DINode>(*subprogram);
        writeFact(pred::di_subprogram::function, subprogramId, funcref);
    }
# endif
#else
    if (const llvm::DISubprogram *subprogram = func.getSubprogram()) {
        refmode_t subprogramId = refmode<llvm::DINode>(*subprogram);
        writeFact(pred::di_subprogram::function, subprogramId, funcref);
    }
#endif

    // Record function type signature
    writeFact(pred::function::type, funcref, typeSignature);

    // Record function signature (name plus type signature) after
    // unmangling
    writeFact(pred::function::signature, funcref, demangle(func.getName().data()));

    // Record function linkage, visibility, alignment, and GC
    if (!linkage.empty())
        writeFact(pred::function::linkage, funcref, linkage);

    if (!visibility.empty())
        writeFact(pred::function::visibility, funcref, visibility);

    if (func.getAlignment())
        writeFact(pred::function::alignment, funcref, func.getAlignment());

    if (func.hasGC())
        writeFact(pred::function::gc, funcref, func.getGC());

    if (func.hasPersonalityFn()) {
        llvm::Constant *pers_fn = func.getPersonalityFn();
        refmode_t pers_fn_ref = writeConstant(*pers_fn);

        writeFact(pred::function::pers_fn, funcref, pers_fn_ref);
    }

    // Record calling convection if it not defaults to C
    if (func.getCallingConv() != llvm::CallingConv::C) {
        refmode_t cconv = refmode(func.getCallingConv());
        writeFact(pred::function::calling_conv, funcref, cconv);
    }

    // Record function name
    const std::string funcname = "@" + func.getName().str();
    writeFact(pred::function::name, funcref, funcname);

    // Address not significant
#if LLVM_VERSION_MAJOR == 3 && LLVM_VERSION_MINOR >= 9
    if (func.hasGlobalUnnamedAddr()) {
        writeFact(pred::function::unnamed_addr, funcref);
    }

    // TODO Record appropriately
    if (func.hasAtLeastLocalUnnamedAddr()) {
    }
#else
    if (func.getUnnamedAddr() != llvm::Function::UnnamedAddr::None) {
        writeFact(pred::function::unnamed_addr, funcref);
    }
#endif

    // Record function attributes TODO
    const llvm::AttributeList &Attrs = func.getAttributes();

    if (Attrs.hasAttributes(llvm::AttributeList::ReturnIndex))
        writeFact(pred::function::ret_attr, funcref,
                  Attrs.getAsString(llvm::AttributeList::ReturnIndex));

    writeFnAttributes<pred::function>(funcref, Attrs);

    if (func.isDeclaration()) {
        // Record as a function declaration entity
        writeFact(pred::function::id_decl, funcref);

        // Nothing more to do for function declarations
        return;
    }

    // Record function definition entity
    writeFact(pred::function::id_defn, funcref);

    // Record section
    if (func.hasSection()) {
#if LLVM_VERSION_MAJOR == 3 && LLVM_VERSION_MINOR >= 9
        writeFact(pred::function::section, funcref, func.getSection().str());
#else
        writeFact(pred::function::section, funcref, func.getSection().data());
#endif
    }

    // Record function parameters
    int index = 0;

    for (llvm::Function::const_arg_iterator
             arg = func.arg_begin(), arg_end = func.arg_end();
         arg != arg_end; arg++)
    {
        refmode_t varId = refmode<llvm::Value>(*arg);

        writeFact(pred::function::param, funcref, index++, varId);
        recordVariable(varId, arg->getType());
    }
}


//------------------------------------------------------------------------------
// Record Function Attributes
//------------------------------------------------------------------------------

template<typename PredGroup>
void FactGenerator::writeFnAttributes(
    const refmode_t &refmode,
    const llvm::AttributeList allAttrs)
{
    using llvm::AttributeList;

    for (unsigned i = allAttrs.index_begin(), e = allAttrs.index_end(); i != e; ++i)//(auto allAttr : allAttrs)//unsigned i = 0; i < allAttrs.getNumAttrSets(); ++i)
    {
        uint64_t index;// = static_cast<unsigned int>(allAttr.getAttribute(llvm::Attribute::AttrKind::None).getValueAsInt());

        // Write out each attribute for this slot
        for (llvm::AttributeSet::iterator
                 it = allAttrs.getAttributes(i).begin(), end = allAttrs.getAttributes(i).end();
             it != end; ++it)
        {
            std::string attr = it->getAsString();
            attr.erase (std::remove(attr.begin(), attr.end(), '"'), attr.end());

            index = i;//it->getValueAsInt();

            // Record target-dependent attributes
            if (it->isStringAttribute()){
                writeFact(pred::attribute::target_dependent, attr);
            }

            // Record attribute by kind
            switch (index) {
                case llvm::AttributeList::AttrIndex::ReturnIndex:
                  writeFact(PredGroup::ret_attr, refmode, attr);
                  break;
                case llvm::AttributeList::AttrIndex::FunctionIndex:
                  writeFact(PredGroup::fn_attr, refmode, attr);
                  break;
              default:
                  //std::cout << index << std::endl;
                  writeFact(PredGroup::param_attr, refmode, index - 1, attr);
                  break;
            }
        }
    }
}

// Instantiate template method

template void FactGenerator::writeFnAttributes<pred::function>(
    const refmode_t &refmode,
    const llvm::AttributeList Attrs);

template void FactGenerator::writeFnAttributes<pred::call>(
    const refmode_t &refmode,
    const llvm::AttributeList Attrs);

template void FactGenerator::writeFnAttributes<pred::invoke>(
    const refmode_t &refmode,
    const llvm::AttributeList Attrs);
