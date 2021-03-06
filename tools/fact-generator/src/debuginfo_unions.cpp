#include <llvm/ADT/SmallVector.h>
#include "DebugInfoProcessorImpl.hpp"
#include "debuginfo_predicate_groups.hpp"

using cclyzer::DebugInfoProcessor;
using cclyzer::refmode_t;
using llvm::cast;
using llvm::dyn_cast;
using llvm::SmallVector;
using std::string;
namespace pred = cclyzer::predicates;
namespace dwarf = llvm::dwarf;


// template<typename P, typename W, typename T> void
// DebugInfoProcessor::Impl::recordUnionAttribute(
//     const refmode_t& nodeId, const llvm::TypedDINodeRef<T>& attribute)
// {
//     typedef P pred;
//     typedef di_recorder<T, W> recorder;

//     if (attribute) {
//         using llvm::MDString;
//         const llvm::Metadata& meta = *attribute;

//         if (const MDString *mds = dyn_cast<MDString>(&meta)) {
//             std::string attribStr = mds->getString();
//             writeFact(pred::raw, nodeId, attribStr);
//         }
//         else {
//             refmode_t attribId = recorder::record(cast<T>(*attribute), *this);
//             writeFact(pred::node, nodeId, attribId);
//         }
//     }
// }


template<typename P, typename W, typename T> void
DebugInfoProcessor::Impl::recordUnionAttribute(
    const refmode_t& nodeId, const llvm::Metadata* attribute)
{
    typedef P pred;
    typedef di_recorder<T, W> recorder;

    if (attribute) {
        using llvm::MDString;
        const llvm::Metadata& meta = *attribute;

        if (const MDString *mds = dyn_cast<MDString>(&meta)) {
            std::string attribStr = mds->getString();
            writeFact(pred::raw, nodeId, attribStr);
        }
        else {
            refmode_t attribId = recorder::record(cast<T>(*attribute), *this);
            writeFact(pred::node, nodeId, attribId);
        }
    }
}

//------------------------------------------------------------------------------
// Helper method to record bit flags
//------------------------------------------------------------------------------

void
DebugInfoProcessor::Impl::recordFlags(
    const Predicate& pred, const refmode_t& nodeId, unsigned flags)
{
    if (flags) {
        // Split flags inside vector
        string fl = std::to_string(flags);
        llvm::DINode::DIFlags f = llvm::DINode::getFlag(fl);
        typedef SmallVector<llvm::DINode::DIFlags ,8> FlagVectorT;
        FlagVectorT flagsVector;
        llvm::DINode::splitFlags(f, flagsVector);

        for (FlagVectorT::iterator it = flagsVector.begin(),
                 end = flagsVector.end(); it != end; ++it )
        {
            const char *flag = llvm::DINode::getFlagString(*it).data();
            writeFact(pred, nodeId, flag);
        }
    }
}

//------------------------------------------------------------------------------
// Explicit template instantiations
//------------------------------------------------------------------------------

template void
DebugInfoProcessor::Impl
::recordUnionAttribute<pred::di_subprogram::containing_type,
                       DebugInfoProcessor::Impl::write_di_type,
                       llvm::DIType>(
    const refmode_t &, const llvm::Metadata * );

template void
DebugInfoProcessor::Impl
::recordUnionAttribute<pred::di_subprogram::scope,
                       DebugInfoProcessor::Impl::write_di_scope,
                       llvm::DIScope>(
    const refmode_t &, const llvm::Metadata * );

template void
DebugInfoProcessor::Impl
::recordUnionAttribute<pred::di_template_param::type,
                       DebugInfoProcessor::Impl::write_di_type,
                       llvm::DIType>(
    const refmode_t &, const llvm::Metadata * );

template void
DebugInfoProcessor::Impl
::recordUnionAttribute<pred::di_variable::type,
                       DebugInfoProcessor::Impl::write_di_type,
                       llvm::DIType>(
    const refmode_t &, const llvm::Metadata * );

template void
DebugInfoProcessor::Impl
::recordUnionAttribute<pred::di_composite_type::basetype,
                       DebugInfoProcessor::Impl::write_di_type,
                       llvm::DIType>(
    const refmode_t &, const llvm::Metadata * );

template void
DebugInfoProcessor::Impl
::recordUnionAttribute<pred::di_composite_type::vtable,
                       DebugInfoProcessor::Impl::write_di_type,
                       llvm::DIType>(
    const refmode_t &, const llvm::Metadata * );

template void
DebugInfoProcessor::Impl
::recordUnionAttribute<pred::di_derived_type::basetype,
                       DebugInfoProcessor::Impl::write_di_type,
                       llvm::DIType>(
    const refmode_t &, const llvm::Metadata * );

template void
DebugInfoProcessor::Impl
::recordUnionAttribute<pred::di_type::scope,
                       DebugInfoProcessor::Impl::write_di_scope,
                       llvm::DIScope>(
    const refmode_t &, const llvm::Metadata * );
