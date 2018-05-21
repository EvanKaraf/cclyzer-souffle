#include "predicate_groups.hpp"
#include "debuginfo_predicate_groups.hpp"

using namespace cclyzer::predicates;

// Basic Blocks
pred_t basic_block::predecessor("basicblock_preds");

// Global

pred_t global_var::id("global_variable");
pred_t global_var::name("global_variable_has_name");
pred_t global_var::unmangl_name("global_variable_has_unmangled_name");
pred_t global_var::type("global_variable_has_type");
pred_t global_var::initializer("global_variable_has_initializer");
pred_t global_var::section("global_variable_in_section");
pred_t global_var::align("global_variable_aligned_to");
pred_t global_var::flag("global_variable_has_flag");
pred_t global_var::linkage("global_variable_has_linkage_type");
pred_t global_var::visibility("global_variable_has_visibility");
pred_t global_var::threadlocal_mode("global_variable_in_threadlocal_mode");

pred_t alias::id("alias");
pred_t alias::name("alias_has_name");
pred_t alias::type("alias_has_type");
pred_t alias::linkage("alias_has_linkage_type");
pred_t alias::visibility("alias_has_visibility");
pred_t alias::aliasee("alias_aliasee");

// Function

pred_t function::id_defn("function");
pred_t function::id_decl("function_decl");
pred_t function::unnamed_addr("function_with_unnamed_addr");
pred_t function::linkage("function_has_linkage_type");
pred_t function::visibility("function_has_visibility");
pred_t function::calling_conv("function_with_calling_convention");
pred_t function::section("function_in_section");
pred_t function::alignment("function_alignment");
pred_t function::fn_attr("function_with_attribute");
pred_t function::gc("function_with_gc");
pred_t function::pers_fn("function_with_pers_fn");
pred_t function::name("function_has_name");
pred_t function::type("function_has_type");
pred_t function::signature("function_has_signature");
pred_t function::param("function_param");
pred_t function::ret_attr("function_with_return_attribute");
pred_t function::param_attr("function_with_param_attribute");

// Instructions

pred_t instruction::to("instruction_assigns_to");
pred_t instruction::flag("instruction_has_flag");
pred_t instruction::next("next_instruction");
pred_t instruction::bb_entry("instruction_bb_entry");
pred_t instruction::function("instruction_in_function");
pred_t instruction::pos("instruction_pos");
pred_t instruction::location("instruction_at_location");

// Binary Instructions

pred_t add::instr("add_instruction");
pred_t add::first_operand("add_instruction_first_operand");
pred_t add::second_operand("add_instruction_second_operand");

pred_t fadd::instr("fadd_instruction");
pred_t fadd::first_operand("fadd_instruction_first_operand");
pred_t fadd::second_operand("fadd_instruction_second_operand");

pred_t sub::instr("sub_instruction");
pred_t sub::first_operand("sub_instruction_first_operand");
pred_t sub::second_operand("sub_instruction_second_operand");

pred_t fsub::instr("fsub_instruction");
pred_t fsub::first_operand("fsub_instruction_first_operand");
pred_t fsub::second_operand("fsub_instruction_second_operand");

pred_t mul::instr("mul_instruction");
pred_t mul::first_operand("mul_instruction_first_operand");
pred_t mul::second_operand("mul_instruction_second_operand");

pred_t fmul::instr("fmul_instruction");
pred_t fmul::first_operand("fmul_instruction_first_operand");
pred_t fmul::second_operand("fmul_instruction_second_operand");

pred_t udiv::instr("udiv_instruction");
pred_t udiv::first_operand("udiv_instruction_first_operand");
pred_t udiv::second_operand("udiv_instruction_second_operand");

pred_t fdiv::instr("fdiv_instruction");
pred_t fdiv::first_operand("fdiv_instruction_first_operand");
pred_t fdiv::second_operand("fdiv_instruction_second_operand");

pred_t sdiv::instr("sdiv_instruction");
pred_t sdiv::first_operand("sdiv_instruction_first_operand");
pred_t sdiv::second_operand("sdiv_instruction_second_operand");

pred_t urem::instr("urem_instruction");
pred_t urem::first_operand("urem_instruction_first_operand");
pred_t urem::second_operand("urem_instruction_second_operand");

pred_t srem::instr("srem_instruction");
pred_t srem::first_operand("srem_instruction_first_operand");
pred_t srem::second_operand("srem_instruction_second_operand");

pred_t frem::instr("frem_instruction");
pred_t frem::first_operand("frem_instruction_first_operand");
pred_t frem::second_operand("frem_instruction_second_operand");

// Bitwise Binary Instructions

pred_t shl::instr("shl_instruction");
pred_t shl::first_operand("shl_instruction_first_operand");
pred_t shl::second_operand("shl_instruction_second_operand");

pred_t lshr::instr("lshr_instruction");
pred_t lshr::first_operand("lshr_instruction_first_operand");
pred_t lshr::second_operand("lshr_instruction_second_operand");

pred_t ashr::instr("ashr_instruction");
pred_t ashr::first_operand("ashr_instruction_first_operand");
pred_t ashr::second_operand("ashr_instruction_second_operand");

pred_t and_::instr("and_instruction");
pred_t and_::first_operand("and_instruction_first_operand");
pred_t and_::second_operand("and_instruction_second_operand");

pred_t or_::instr("or_instruction");
pred_t or_::first_operand("or_instruction_first_operand");
pred_t or_::second_operand("or_instruction_second_operand");

pred_t xor_::instr("xor_instruction");
pred_t xor_::first_operand("xor_instruction_first_operand");
pred_t xor_::second_operand("xor_instruction_second_operand");

// Terminator Instructions

pred_t ret::instr("ret_instruction");
pred_t ret::instr_void("void_ret_instruction");
pred_t ret::operand("ret_instruction_value");

pred_t br::instr("br_instruction");
pred_t br::instr_cond("br_cond_instruction");
pred_t br::condition("br_cond_instruction_condition");
pred_t br::cond_iftrue("br_cond_instruction_iftrue_label");
pred_t br::cond_iffalse("br_cond_instruction_iffalse_label");
pred_t br::instr_uncond("br_uncond_instruction");
pred_t br::uncond_dest("br_uncond_instruction_dest_label");

pred_t switch_::instr("switch_instruction");
pred_t switch_::operand("switch_instruction_operand");
pred_t switch_::default_label("switch_instruction_default_label");
pred_t switch_::case_value("switch_instruction_case_value");
pred_t switch_::case_label("switch_instruction_case_label");
pred_t switch_::ncases("switch_instruction_ncases");

pred_t indirectbr::instr("indirectbr_instruction");
pred_t indirectbr::address("indirectbr_instruction_address");
pred_t indirectbr::label("indirectbr_instruction_label");
pred_t indirectbr::nlabels("indirectbr_instruction_nlabels");

pred_t resume::instr("resume_instruction");
pred_t resume::operand("resume_instruction_operand");

pred_t instruction::unreachable("unreachable_instruction");

pred_t invoke::instr("invoke_instruction");
pred_t invoke::instr_direct("direct_invoke_instruction");
pred_t invoke::instr_indirect("indirect_invoke_instruction");
pred_t invoke::function("invoke_instruction_fn_operand");
pred_t invoke::arg("invoke_instruction_arg");
pred_t invoke::calling_conv("invoke_instruction_with_calling_convention");
pred_t invoke::ret_attr("invoke_instruction_with_return_attribute");
pred_t invoke::param_attr("invoke_instruction_with_param_attribute");
pred_t invoke::fn_attr("invoke_instruction_with_fn_attribute");
pred_t invoke::normal_label("invoke_instruction_normal_label");
pred_t invoke::exc_label("invoke_instruction_exception_label");

// Vector Operations

pred_t extract_element::instr("extractelement_instruction");
pred_t extract_element::base("extractelement_instruction_base");
pred_t extract_element::index("extractelement_instruction_index");

pred_t insert_element::instr("insertelement_instruction");
pred_t insert_element::base("insertelement_instruction_base");
pred_t insert_element::index("insertelement_instruction_index");
pred_t insert_element::value("insertelement_instruction_value");

pred_t shuffle_vector::instr("shufflevector_instruction");
pred_t shuffle_vector::first_vector("shufflevector_instruction_first_vector");
pred_t shuffle_vector::second_vector("shufflevector_instruction_second_vector");
pred_t shuffle_vector::mask("shufflevector_instruction_mask");

// Aggregate Operations

pred_t extract_value::instr("extractvalue_instruction");
pred_t extract_value::base("extractvalue_instruction_base");
pred_t extract_value::index("extractvalue_instruction_index");
pred_t extract_value::nindices("extractvalue_instruction_nindices");

pred_t insert_value::instr("insertvalue_instruction");
pred_t insert_value::base("insertvalue_instruction_base");
pred_t insert_value::value("insertvalue_instruction_value");
pred_t insert_value::index("insertvalue_instruction_index");
pred_t insert_value::nindices("insertvalue_instruction_nindices");

// Memory Operations

pred_t alloca::instr("alloca_instruction");
pred_t alloca::size("alloca_instruction_size");
pred_t alloca::alignment("alloca_instruction_alignment");
pred_t alloca::type("alloca_instruction_type");

pred_t load::instr("load_instruction");
pred_t load::alignment("load_instruction_alignment");
pred_t load::ordering("load_instruction_ordering");
pred_t load::address("load_instruction_address");
pred_t load::isvolatile("load_instruction_is_volatile");

pred_t store::instr("store_instruction");
pred_t store::alignment("store_instruction_alignment");
pred_t store::ordering("store_instruction_ordering");
pred_t store::value("store_instruction_value");
pred_t store::address("store_instruction_address");
pred_t store::isvolatile("store_instruction_is_volatile");

pred_t fence::instr("fence_instruction");
pred_t fence::ordering("fence_instruction_ordering");

pred_t atomicrmw::instr("atomicrmw_instruction");
pred_t atomicrmw::ordering("atomicrmw_instruction_ordering");
pred_t atomicrmw::operation("atomicrmw_instruction_operation");
pred_t atomicrmw::address("atomicrmw_instruction_address");
pred_t atomicrmw::value("atomicrmw_instruction_value");
pred_t atomicrmw::isvolatile("atomicrmw_instruction_is_volatile");

pred_t cmpxchg::instr("cmpxchg_instruction");
pred_t cmpxchg::ordering("cmpxchg_instruction_ordering");
pred_t cmpxchg::address("cmpxchg_instruction_address");
pred_t cmpxchg::cmp_value("cmpxchg_instruction_cmp_value");
pred_t cmpxchg::new_value("cmpxchg_instruction_new_value");
pred_t cmpxchg::type("cmpxchg_instruction_type");
pred_t cmpxchg::isvolatile("cmpxchg_instruction_is_volatile");

pred_t gep::instr("getelementptr_instruction");
pred_t gep::base("getelementptr_instruction_base");
pred_t gep::index("getelementptr_instruction_index");
pred_t gep::nindices("getelementptr_instruction_nindices");
pred_t gep::inbounds("getelementptr_instruction_is_inbounds");

// Conversion Operations

pred_t trunc::instr("trunc_instruction");
pred_t trunc::from_operand("trunc_instruction_from_operand");
pred_t trunc::to_type("trunc_instruction_to_type");

pred_t zext::instr("zext_instruction");
pred_t zext::from_operand("zext_instruction_from_operand");
pred_t zext::to_type("zext_instruction_to_type");

pred_t sext::instr("sext_instruction");
pred_t sext::from_operand("sext_instruction_from_operand");
pred_t sext::to_type("sext_instruction_to_type");

pred_t fptrunc::instr("fptrunc_instruction");
pred_t fptrunc::from_operand("fptrunc_instruction_from_operand");
pred_t fptrunc::to_type("fptrunc_instruction_to_type");

pred_t fpext::instr("fpext_instruction");
pred_t fpext::from_operand("fpext_instruction_from_operand");
pred_t fpext::to_type("fpext_instruction_to_type");

pred_t fptoui::instr("fptoui_instruction");
pred_t fptoui::from_operand("fptoui_instruction_from_operand");
pred_t fptoui::to_type("fptoui_instruction_to_type");

pred_t fptosi::instr("fptosi_instruction");
pred_t fptosi::from_operand("fptosi_instruction_from_operand");
pred_t fptosi::to_type("fptosi_instruction_to_type");

pred_t uitofp::instr("uitofp_instruction");
pred_t uitofp::from_operand("uitofp_instruction_from_operand");
pred_t uitofp::to_type("uitofp_instruction_to_type");

pred_t sitofp::instr("sitofp_instruction");
pred_t sitofp::from_operand("sitofp_instruction_from_operand");
pred_t sitofp::to_type("sitofp_instruction_to_type");

pred_t ptrtoint::instr("ptrtoint_instruction");
pred_t ptrtoint::from_operand("ptrtoint_instruction_from_operand");
pred_t ptrtoint::to_type("ptrtoint_instruction_to_type");

pred_t inttoptr::instr("inttoptr_instruction");
pred_t inttoptr::from_operand("inttoptr_instruction_from_operand");
pred_t inttoptr::to_type("inttoptr_instruction_to_type");

pred_t bitcast::instr("bitcast_instruction");
pred_t bitcast::from_operand("bitcast_instruction_from_operand");
pred_t bitcast::to_type("bitcast_instruction_to_type");

// Other Operations

pred_t icmp::instr("icmp_instruction");
pred_t icmp::condition("icmp_instruction_condition");
pred_t icmp::first_operand("icmp_instruction_first_operand");
pred_t icmp::second_operand("icmp_instruction_second_operand");

pred_t fcmp::instr("fcmp_instruction");
pred_t fcmp::condition("fcmp_instruction_condition");
pred_t fcmp::first_operand("fcmp_instruction_first_operand");
pred_t fcmp::second_operand("fcmp_instruction_second_operand");

pred_t phi::instr("phi_instruction");
pred_t phi::type("phi_instruction_type");
pred_t phi::pair_value("phi_instruction_pair_value");
pred_t phi::pair_label("phi_instruction_pair_label");
pred_t phi::npairs("phi_instruction_npairs");

pred_t select::instr("select_instruction");
pred_t select::condition("select_instruction_condition");
pred_t select::first_operand("select_instruction_first_operand");
pred_t select::second_operand("select_instruction_second_operand");

pred_t va_arg::instr("va_arg_instruction");
pred_t va_arg::va_list("va_arg_instruction_va_list");
pred_t va_arg::type("va_arg_instruction_type");

pred_t call::instr("call_instruction");
pred_t call::instr_direct("direct_call_instruction");
pred_t call::instr_indirect("indirect_call_instruction");
pred_t call::function("call_instruction_fn_operand");
pred_t call::arg("call_instruction_arg");
pred_t call::calling_conv("call_instruction_with_calling_convention");
pred_t call::ret_attr("call_instruction_with_return_attribute");
pred_t call::param_attr("call_instruction_with_param_attribute");
pred_t call::fn_attr("call_instruction_with_fn_attribute");
pred_t call::tail("call_instruction_is_tail_opt");

pred_t landingpad::instr("landingpad_instruction");
pred_t landingpad::type("landingpad_instruction_type");
pred_t landingpad::catch_clause("landingpad_instruction_catch_clause");
pred_t landingpad::filter_clause("landingpad_instruction_filter_clause");
pred_t landingpad::nclauses("landingpad_instruction_nclauses");
pred_t landingpad::cleanup("landingpad_instruction_is_cleanup");

// Types

pred_t primitive_type::id("primitive_type");
pred_t integer_type::id("integer_type");
pred_t fp_type::id("fp_type");

pred_t func_type::id("function_type");
pred_t func_type::varargs("function_type_has_varargs");
pred_t func_type::return_type("function_type_return");
pred_t func_type::param_type("function_type_param");
pred_t func_type::nparams("function_type_nparams");

pred_t ptr_type::id("pointer_type");
pred_t ptr_type::component_type("pointer_type_has_component");
pred_t ptr_type::addr_space("pointer_type_has_addr_space");

pred_t vector_type::id("vector_type");
pred_t vector_type::component_type("vector_type_has_component");
pred_t vector_type::size("vector_type_has_size");

pred_t array_type::id("array_type");
pred_t array_type::component_type("array_type_has_component");
pred_t array_type::size("array_type_has_size");

pred_t struct_type::id("struct_type");
pred_t struct_type::field_type("struct_type_field");
pred_t struct_type::field_offset("struct_type_field_offset");
pred_t struct_type::field_bit_offset("struct_type_field_bit_offset");
pred_t struct_type::nfields("struct_type_nfields");
pred_t struct_type::opaque("opaque_struct_type");

pred_t type::alloc_size("type_has_size");
pred_t type::store_size("type_has_unpadded_size");

// Variables and constants

pred_t variable::id("variable");
pred_t variable::type("variable_has_type");
pred_t variable::source_name("variable_has_debug_source_name");
pred_t variable::pos("variable_has_debug_decl_pos");
pred_t variable::in_function("variable_in_fn");
pred_t variable::name("variable_has_name");

pred_t constant::id("constant");
pred_t constant::type("constant_has_type");
pred_t constant::value("constant_has_value");
pred_t constant::hash("constant_hashes_to");
pred_t constant::in_function("constant_in_fn");

pred_t constant::expr("constant_expression");
pred_t constant::to_integer("constant_to_int");


// Constant hierarchy

pred_t integer_constant::id("integer_constant");
pred_t fp_constant::id("fp_constant");
pred_t nullptr_constant::id("nullptr_constant");

pred_t function_constant::id("function_constant");
pred_t function_constant::name("function_constant_fn_name");

pred_t global_variable_constant::id("global_variable_constant");
pred_t global_variable_constant::name("global_variable_constant_name");

pred_t constant_array::id("constant_array");
pred_t constant_array::index("constant_array_index");
pred_t constant_array::size("constant_array_has_size");

pred_t constant_struct::id("constant_struct");
pred_t constant_struct::index("constant_struct_index");
pred_t constant_struct::size("constant_struct_has_size");

pred_t constant_vector::id("constant_vector");
pred_t constant_vector::index("constant_vector_index");
pred_t constant_vector::size("constant_vector_has_size");

pred_t constant_expr::id("constant_expression");

pred_t bitcast_constant_expr::id("bitcast_constant_expression");
pred_t bitcast_constant_expr::from_constant("bitcast_constant_expression_from");

pred_t inttoptr_constant_expr::id("inttoptr_constant_expression");
pred_t inttoptr_constant_expr::from_int_constant("inttoptr_constant_expression_from");

pred_t ptrtoint_constant_expr::id("ptrtoint_constant_expression");
pred_t ptrtoint_constant_expr::from_ptr_constant("ptrtoint_constant_expression_from");

pred_t gep_constant_expr::id("getelementptr_constant_expression");
pred_t gep_constant_expr::base("getelementptr_constant_expression_base");
pred_t gep_constant_expr::index("getelementptr_constant_expression_index");
pred_t gep_constant_expr::nindices("getelementptr_constant_expression_nindices");

pred_t inline_asm::id("inline_asm");
pred_t inline_asm::text("inline_asm_text");
pred_t inline_asm::constraints("inline_asm_constraints");

pred_t attribute::target_dependent("target_dependent_attribute");


//------------------------------------------------------------------------------
// DWARF-like Debug Information Predicates
//------------------------------------------------------------------------------

// Scope Entry
pred_t di_scope_entry::id("di:scope");

// File Entry
pred_t di_file::id("di:file");
pred_t di_file::filename("di:file:filename");
pred_t di_file::directory("di:file:directory");

// Namespace Entry
pred_t di_namespace::id("di:namespace");
pred_t di_namespace::name("di:namespace:name");
pred_t di_namespace::file("di:namespace:file");
pred_t di_namespace::line("di:namespace:line");
pred_t di_namespace::scope("di:namespace:scope");

// Lexical Block Entry
pred_t di_lex_block::id("di:lexical_block");
pred_t di_lex_block::file("di:lexical_block:file");
pred_t di_lex_block::line("di:lexical_block:line");
pred_t di_lex_block::column("di:lexical_block:column");
pred_t di_lex_block::scope("di:lexical_block:scope");

// Lexical Block File Entry
pred_t di_lex_block_file::id("di:lexical_block_file");
pred_t di_lex_block_file::file("di:lexical_block_file:file");
pred_t di_lex_block_file::discriminator("di:lexical_block_file:discrim");
pred_t di_lex_block_file::scope("di:lexical_block_file:scope");

// Subprogram Entry
pred_t di_subprogram::id("di:subprogram");
pred_t di_subprogram::name("di:subprogram:name");
pred_t di_subprogram::linkage_name("di:subprogram:linkage_name");
pred_t di_subprogram::file("di:subprogram:file");
pred_t di_subprogram::line("di:subprogram:line");
pred_t di_subprogram::scope::node("di:subprogram:scope");
pred_t di_subprogram::scope::raw("di:subprogram:raw_scope");
pred_t di_subprogram::scope_line("di:subprogram:scope_line");
pred_t di_subprogram::type("di:subprogram:type");
pred_t di_subprogram::containing_type::node("di:subprogram:containing_type");
pred_t di_subprogram::containing_type::raw("di:subprogram:raw_containing_type");
pred_t di_subprogram::declaration("di:subprogram:declaration");
pred_t di_subprogram::virtuality("di:subprogram:virtuality");
pred_t di_subprogram::virtual_index("di:subprogram:virtual_index");
pred_t di_subprogram::flag("di:subprogram:flag");
pred_t di_subprogram::template_param("di:subprogram:template_param");
pred_t di_subprogram::variable("di:subprogram:variable");
pred_t di_subprogram::is_definition("di:subprogram:is_definition");
pred_t di_subprogram::is_local_to_unit("di:subprogram:is_local_to_unit");
pred_t di_subprogram::is_optimized("di:subprogram:is_optimized");
pred_t di_subprogram::function("di:subprogram:function");

// Type Entry
pred_t di_type::id("di:type_entry");
pred_t di_type::name("di:type_entry:name");
pred_t di_type::line("di:type_entry:line");
pred_t di_type::scope::node("di:type_entry:scope");
pred_t di_type::scope::raw("di:type_entry:raw_scope");
pred_t di_type::flag("di:type_entry:flag");
pred_t di_type::bitsize("di:type_entry:bit_size");
pred_t di_type::bitalign("di:type_entry:bit_align");
pred_t di_type::bitoffset("di:type_entry:bit_offset");

pred_t di_basic_type::id("di:basic_type_entry");

pred_t di_composite_type::id("di:composite_type_entry");
pred_t di_composite_type::file("di:composite_type_entry:file");
pred_t di_composite_type::abi_id("di:composite_type_entry:abi_id");
pred_t di_composite_type::field("di:composite_type_entry:field");
pred_t di_composite_type::enumerator("di:composite_type_entry:enumerator");
pred_t di_composite_type::subrange("di:composite_type_entry:subrange");
pred_t di_composite_type::template_param("di:composite_type_entry:template_param");
pred_t di_composite_type::vtable::node("di:composite_type_entry:vtable");
pred_t di_composite_type::vtable::raw("di:composite_type_entry:raw_vtable");
pred_t di_composite_type::basetype::node("di:composite_type_entry:base_type");
pred_t di_composite_type::basetype::raw("di:composite_type_entry:raw_base_type");
pred_t di_composite_type::kind("di:composite_type_entry:kind");
pred_t di_composite_type::structures("di:structure_type_entry");
pred_t di_composite_type::classes("di:class_type_entry");
pred_t di_composite_type::arrays("di:array_type_entry");
pred_t di_composite_type::unions("di:union_type_entry");
pred_t di_composite_type::enumerations("di:enum_type_entry");

pred_t di_derived_type::id("di:derived_type_entry");
pred_t di_derived_type::kind("di:derived_type_entry:kind");
pred_t di_derived_type::file("di:derived_type_entry:file");
pred_t di_derived_type::basetype::node("di:derived_type_entry:base_type");
pred_t di_derived_type::basetype::raw("di:derived_type_entry:raw_base_type");

pred_t di_subroutine_type::id("di:subroutine_type_entry");
pred_t di_subroutine_type::type_elem("di:subroutine_type_entry:type_elem");
pred_t di_subroutine_type::raw_type_elem("di:subroutine_type_entry:raw_type_elem");

// Template Parameter Entry
pred_t di_template_param::id("di:template_param");
pred_t di_template_param::name("di:template_param:name");
pred_t di_template_param::type::node("di:template_param:type");
pred_t di_template_param::type::raw("di:template_param:raw_type");

pred_t di_template_type_param::id("di:template_type_param");
pred_t di_template_value_param::id("di:template_value_param");
pred_t di_template_value_param::value("di:template_value_param:value");
pred_t di_template_value_param::elements("di:template_value_param:elements");

// Variable Entry
pred_t di_variable::id("di:variable");
pred_t di_variable::name("di:variable:name");
pred_t di_variable::file("di:variable:file");
pred_t di_variable::line("di:variable:line");
pred_t di_variable::scope("di:variable:scope");
pred_t di_variable::type::node("di:variable:type");
pred_t di_variable::type::raw("di:variable:raw_type");

pred_t di_local_var::id("di:local_variable");
pred_t di_local_var::arg_num("di:local_variable:arg_num");
pred_t di_local_var::flag("di:local_variable:flag");
pred_t di_local_var::variable("di:local_variable_declaration");

pred_t di_global_var::id("di:global_variable");
pred_t di_global_var::variable("di:global_variable:resolved_name");
pred_t di_global_var::linkage_name("di:global_variable:linkage_name");
pred_t di_global_var::is_definition("di:global_variable:is_definition");
pred_t di_global_var::is_local_to_unit("di:global_variable:is_local_to_unit");
pred_t di_global_var::static_data_member_decl("di:global_variable:static_data_member_decl");

// Enumerator Entry
pred_t di_enumerator::id("di:enumerator");
pred_t di_enumerator::name("di:enumerator:name");
pred_t di_enumerator::value("di:enumerator:value");

// Subrange Entry
pred_t di_subrange::id("di:subrange");
pred_t di_subrange::lower_bound("di:subrange:lower_bound");
pred_t di_subrange::count("di:subrange:count");

// Imported Entity Entry
pred_t di_imported_entity::id("di:imported_entity");
pred_t di_imported_entity::name("di:imported_entity:name");
pred_t di_imported_entity::line("di:imported_entity:line");
pred_t di_imported_entity::scope("di:imported_entity:scope");
pred_t di_imported_entity::entity::node("di:imported_entity:entity");
pred_t di_imported_entity::entity::raw("di:imported_entity:raw_entity");

// Location Entry
pred_t di_location::id("di:location");
pred_t di_location::line("di:location:line");
pred_t di_location::column("di:location:column");
pred_t di_location::scope("di:location:scope");
pred_t di_location::inlined_at("di:location:inlined_at");
