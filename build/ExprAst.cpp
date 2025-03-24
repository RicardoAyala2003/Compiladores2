/* ExprAst.cpp.  Generated automatically by treecc */
#line 72 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"

    #include "ExprAst.hpp"
    #include "exceptions.hpp"

    

    std::string newVariable(){
        static int index = 0;

        return "t" + std::to_string(index++);
    }

    std::string newLabel(){
        static int index = 0;

        return "L" + std::to_string(index++);
    }


    std::string newFmts(){
        static int index = 0;

        return "@.fmt" + std::to_string(index++);
    }




    


#line 35 "ExprAst.cpp"

#include <cstddef>

namespace Ast
{

#define YYNODESTATE_TRACK_LINES 1
#define YYNODESTATE_USE_ALLOCATOR 1
#line 1 "cpp_skel.cc"
/*
 * treecc node allocation routines for C++.
 *
 * Copyright (C) 2001  Southern Storm Software, Pty Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * As a special exception, when this file is copied by treecc into
 * a treecc output file, you may use that output file without restriction.
 */

#ifndef YYNODESTATE_BLKSIZ
#define	YYNODESTATE_BLKSIZ	2048
#endif

/*
 * Types used by the allocation routines.
 */
struct YYNODESTATE_block
{
	char data__[YYNODESTATE_BLKSIZ];
	struct YYNODESTATE_block *next__;

};
struct YYNODESTATE_push
{
	struct YYNODESTATE_push *next__;
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
};

/*
 * Initialize the singleton instance.
 */
#ifndef YYNODESTATE_REENTRANT
YYNODESTATE *YYNODESTATE::state__ = 0;
#endif

/*
 * Some macro magic to determine the default alignment
 * on this machine.  This will compile down to a constant.
 */
#define	YYNODESTATE_ALIGN_CHECK_TYPE(type,name)	\
	struct _YYNODESTATE_align_##name { \
		char pad; \
		type field; \
	}
#define	YYNODESTATE_ALIGN_FOR_TYPE(type)	\
	offsetof(_YYNODESTATE_align_##type, field)
#define	YYNODESTATE_ALIGN_MAX(a,b)	\
	((a) > (b) ? (a) : (b))
#define	YYNODESTATE_ALIGN_MAX3(a,b,c) \
	(YYNODESTATE_ALIGN_MAX((a), YYNODESTATE_ALIGN_MAX((b), (c))))
YYNODESTATE_ALIGN_CHECK_TYPE(int, int);
YYNODESTATE_ALIGN_CHECK_TYPE(long, long);
#if defined(WIN32) && !defined(__CYGWIN__)
YYNODESTATE_ALIGN_CHECK_TYPE(__int64, long_long);
#else
YYNODESTATE_ALIGN_CHECK_TYPE(long long, long_long);
#endif
YYNODESTATE_ALIGN_CHECK_TYPE(void *, void_p);
YYNODESTATE_ALIGN_CHECK_TYPE(float, float);
YYNODESTATE_ALIGN_CHECK_TYPE(double, double);
#define	YYNODESTATE_ALIGNMENT	\
	YYNODESTATE_ALIGN_MAX( \
			YYNODESTATE_ALIGN_MAX3	\
			(YYNODESTATE_ALIGN_FOR_TYPE(int), \
		     YYNODESTATE_ALIGN_FOR_TYPE(long), \
			 YYNODESTATE_ALIGN_FOR_TYPE(long_long)), \
  	     YYNODESTATE_ALIGN_MAX3 \
		 	(YYNODESTATE_ALIGN_FOR_TYPE(void_p), \
			 YYNODESTATE_ALIGN_FOR_TYPE(float), \
			 YYNODESTATE_ALIGN_FOR_TYPE(double)))

/*
 * Constructor for YYNODESTATE.
 */
YYNODESTATE::YYNODESTATE()
{
	/* Initialize the allocation state */
	blocks__ = 0;
	push_stack__ = 0;
	used__ = 0;

#ifndef YYNODESTATE_REENTRANT
	/* Register this object as the singleton instance */
	if(!state__)
	{
		state__ = this;
	}
#endif
}

/*
 * Destructor for YYNODESTATE.
 */
YYNODESTATE::~YYNODESTATE()
{
	/* Free all node memory */
	clear();

#ifndef YYNODESTATE_REENTRANT
	/* We are no longer the singleton instance */
	if(state__ == this)
	{
		state__ = 0;
	}
#endif
}

#ifdef YYNODESTATE_USE_ALLOCATOR

/*
 * Allocate a block of memory.
 */
void *YYNODESTATE::alloc(size_t size__)
{
	struct YYNODESTATE_block *block__;
	void *result__;

	/* Round the size to the next alignment boundary */
	size__ = (size__ + YYNODESTATE_ALIGNMENT - 1) &
				~(YYNODESTATE_ALIGNMENT - 1);

	/* Do we need to allocate a new block? */
	block__ = blocks__;
	if(!block__ || (used__ + size__) > YYNODESTATE_BLKSIZ)
	{
		if(size__ > YYNODESTATE_BLKSIZ)
		{
			/* The allocation is too big for the node pool */
			return (void *)0;
		}
		block__ = new YYNODESTATE_block;
		if(!block__)
		{
			/* The system is out of memory.  The programmer can
			   inherit the "failed" method to report the
			   out of memory state and/or abort the program */
			failed();
			return (void *)0;
		}
		block__->next__ = blocks__;
		blocks__ = block__;
		used__ = 0;
	}

	/* Allocate the memory and return it */
	result__ = (void *)(block__->data__ + used__);
	used__ += size__;
	return result__;
}

/*
 * Deallocate a block of memory.
 */
void YYNODESTATE::dealloc(void *ptr__, size_t size__)
{
	/* Nothing to do for this type of node allocator */
}

/*
 * Push the node allocation state.
 */
int YYNODESTATE::push()
{
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
	struct YYNODESTATE_push *push_item__;

	/* Save the current state of the node allocation pool */
	saved_block__ = blocks__;
	saved_used__ = used__;

	/* Allocate space for a push item */
	push_item__ = (struct YYNODESTATE_push *)
			alloc(sizeof(struct YYNODESTATE_push));
	if(!push_item__)
	{
		return 0;
	}

	/* Copy the saved information to the push item */
	push_item__->saved_block__ = saved_block__;
	push_item__->saved_used__ = saved_used__;

	/* Add the push item to the push stack */
	push_item__->next__ = push_stack__;
	push_stack__ = push_item__;
	return 1;
}

/*
 * Pop the node allocation state.
 */
void YYNODESTATE::pop()
{
	struct YYNODESTATE_push *push_item__;
	struct YYNODESTATE_block *saved_block__;
	struct YYNODESTATE_block *temp_block__;

	/* Pop the top of the push stack */
	push_item__ = push_stack__;
	if(push_item__ == 0)
	{
		saved_block__ = 0;
		used__ = 0;
	}
	else
	{
		saved_block__ = push_item__->saved_block__;
		used__ = push_item__->saved_used__;
		push_stack__ = push_item__->next__;
	}

	/* Free unnecessary blocks */
	while(blocks__ != saved_block__)
	{
		temp_block__ = blocks__;
		blocks__ = temp_block__->next__;
		delete temp_block__;
	}
}

/*
 * Clear the node allocation pool completely.
 */
void YYNODESTATE::clear()
{
	struct YYNODESTATE_block *temp_block__;
	while(blocks__ != 0)
	{
		temp_block__ = blocks__;
		blocks__ = temp_block__->next__;
		delete temp_block__;
	}
	push_stack__ = 0;
	used__ = 0;
}

#endif /* YYNODESTATE_USE_ALLOCATOR */

/*
 * Default implementation of functions which may be overridden.
 */
void YYNODESTATE::failed()
{
}

#ifdef YYNODESTATE_TRACK_LINES

const char *YYNODESTATE::currFilename() const
{
	return (const char *)0;
}

long YYNODESTATE::currLinenum() const
{
	return 0;
}

#endif
#line 319 "ExprAst.cpp"
void *Node::operator new(size_t size__)
{
	return YYNODESTATE::getState()->alloc(size__);
}

void Node::operator delete(void *ptr__, size_t size__)
{
	YYNODESTATE::getState()->dealloc(ptr__, size__);
}

Node::Node()
{
	this->kind__ = Node_kind;
	this->filename__ = YYNODESTATE::getState()->currFilename();
	this->linenum__ = YYNODESTATE::getState()->currLinenum();
}

Node::~Node()
{
	// not used
}

int Node::isA(int kind) const
{
	if(kind == Node_kind)
		return 1;
	else
		return 0;
}

const char *Node::getKindName() const
{
	return "Node";
}

Program::Program(string_t class_name, Node * varmethod_decls, Node * method_decls)
	: Node()
{
	this->kind__ = Program_kind;
	this->class_name = class_name;
	this->varmethod_decls = varmethod_decls;
	this->method_decls = method_decls;
}

Program::~Program()
{
	// not used
}

string_t Program::toString()
#line 354 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;

 
    os << "Program "
  << ")";
    
    return os.str();
}
#line 380 "ExprAst.cpp"

int Program::isA(int kind) const
{
	if(kind == Program_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *Program::getKindName() const
{
	return "Program";
}

VarMethodDeclList::VarMethodDeclList(Node * first_decl, Node * rest_decls)
	: Node()
{
	this->kind__ = VarMethodDeclList_kind;
	this->first_decl = first_decl;
	this->rest_decls = rest_decls;
}

VarMethodDeclList::~VarMethodDeclList()
{
	// not used
}

string_t VarMethodDeclList::toString()
#line 364 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    if (!first_decl) return "VariableDeclList()";
    std::ostringstream os;
    os << "VariableDeclList(" << first_decl->toString();
    if (rest_decls) os << ", " << rest_decls->toString();
    os << ")";


    return os.str();
}
#line 420 "ExprAst.cpp"

int VarMethodDeclList::isA(int kind) const
{
	if(kind == VarMethodDeclList_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *VarMethodDeclList::getKindName() const
{
	return "VarMethodDeclList";
}

VariableDeclList::VariableDeclList(Node * first_decl, Node * rest_decls)
	: Node()
{
	this->kind__ = VariableDeclList_kind;
	this->first_decl = first_decl;
	this->rest_decls = rest_decls;
}

VariableDeclList::~VariableDeclList()
{
	// not used
}

string_t VariableDeclList::toString()
#line 375 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
   


    if (!first_decl) return "VariableDeclList()";
    std::ostringstream os;
    os << "VariableDeclList(" << first_decl->toString();
    if (rest_decls) os << ", " << rest_decls->toString();
    os << ")";


    return os.str();
}
#line 463 "ExprAst.cpp"

int VariableDeclList::isA(int kind) const
{
	if(kind == VariableDeclList_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *VariableDeclList::getKindName() const
{
	return "VariableDeclList";
}

VariableDecl::VariableDecl(Node * type, string_t identifier, Node * variableDecl_Body)
	: Node()
{
	this->kind__ = VariableDecl_kind;
	this->type = type;
	this->identifier = identifier;
	this->variableDecl_Body = variableDecl_Body;
}

VariableDecl::~VariableDecl()
{
	// not used
}

string_t VariableDecl::toString()
#line 389 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
  os << "VARIABLEDECL" ;
    return os.str();
}
#line 499 "ExprAst.cpp"

int VariableDecl::isA(int kind) const
{
	if(kind == VariableDecl_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *VariableDecl::getKindName() const
{
	return "VariableDecl";
}

VariableDecl_Body::VariableDecl_Body(Node * ident_list)
	: Node()
{
	this->kind__ = VariableDecl_Body_kind;
	this->ident_list = ident_list;
}

VariableDecl_Body::~VariableDecl_Body()
{
	// not used
}

string_t VariableDecl_Body::toString()
#line 395 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "VariableDecl_Body(" <<  ")";

    return os.str();
}
#line 534 "ExprAst.cpp"

int VariableDecl_Body::isA(int kind) const
{
	if(kind == VariableDecl_Body_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *VariableDecl_Body::getKindName() const
{
	return "VariableDecl_Body";
}

IdentList::IdentList(string_t identifier, Node * IdentListParam)
	: Node()
{
	this->kind__ = IdentList_kind;
	this->identifier = identifier;
	this->IdentListParam = IdentListParam;
}

IdentList::~IdentList()
{
	// not used
}

string_t IdentList::toString()
#line 402 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    
    std::ostringstream os;
    os << "IdentList(" <<  ")";
    return os.str();
}
#line 570 "ExprAst.cpp"

int IdentList::isA(int kind) const
{
	if(kind == IdentList_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *IdentList::getKindName() const
{
	return "IdentList";
}

Type::Type(string_t type_name, Node * array_optional)
	: Node()
{
	this->kind__ = Type_kind;
	this->type_name = type_name;
	this->array_optional = array_optional;
}

Type::~Type()
{
	// not used
}

string_t Type::toString()
#line 409 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "Type(" << type_name;
    if (array_optional) os << ", " << array_optional->toString();
    os << ")";
    return os.str();
}
#line 607 "ExprAst.cpp"

int Type::isA(int kind) const
{
	if(kind == Type_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *Type::getKindName() const
{
	return "Type";
}

ArrayOptional::ArrayOptional(int size)
	: Node()
{
	this->kind__ = ArrayOptional_kind;
	this->size = size;
}

ArrayOptional::~ArrayOptional()
{
	// not used
}

string_t ArrayOptional::toString()
#line 417 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
 
    std::ostringstream os;
    os << "ArrayOptional(" <<  ")";
    return os.str();
}
#line 642 "ExprAst.cpp"

int ArrayOptional::isA(int kind) const
{
	if(kind == ArrayOptional_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *ArrayOptional::getKindName() const
{
	return "ArrayOptional";
}

MethodDeclList::MethodDeclList(Node * first_decl, Node * rest_decls)
	: Node()
{
	this->kind__ = MethodDeclList_kind;
	this->first_decl = first_decl;
	this->rest_decls = rest_decls;
}

MethodDeclList::~MethodDeclList()
{
	// not used
}

string_t MethodDeclList::toString()
#line 424 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{

    std::ostringstream os;
    os << "MethodDeclList(" << ")";
    return os.str();
}
#line 678 "ExprAst.cpp"

int MethodDeclList::isA(int kind) const
{
	if(kind == MethodDeclList_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *MethodDeclList::getKindName() const
{
	return "MethodDeclList";
}

MethodDecl::MethodDecl(Node * method_type, string_t identifier, Node * MethodDecl_Body)
	: Node()
{
	this->kind__ = MethodDecl_kind;
	this->method_type = method_type;
	this->identifier = identifier;
	this->MethodDecl_Body = MethodDecl_Body;
}

MethodDecl::~MethodDecl()
{
	// not used
}

string_t MethodDecl::toString()
#line 431 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "MethodDecl(" << ")";
    return os.str();
}
#line 714 "ExprAst.cpp"

int MethodDecl::isA(int kind) const
{
	if(kind == MethodDecl_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *MethodDecl::getKindName() const
{
	return "MethodDecl";
}

MethodDecl_Body::MethodDecl_Body(Node * opt_param_decl_list, Node * variable_decls, Node * stmt_list)
	: Node()
{
	this->kind__ = MethodDecl_Body_kind;
	this->opt_param_decl_list = opt_param_decl_list;
	this->variable_decls = variable_decls;
	this->stmt_list = stmt_list;
}

MethodDecl_Body::~MethodDecl_Body()
{
	// not used
}

string_t MethodDecl_Body::toString()
#line 437 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "MethodDecl_Body(" << ")";
    return os.str();
}
#line 750 "ExprAst.cpp"

int MethodDecl_Body::isA(int kind) const
{
	if(kind == MethodDecl_Body_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *MethodDecl_Body::getKindName() const
{
	return "MethodDecl_Body";
}

MethodType::MethodType(string_t type)
	: Node()
{
	this->kind__ = MethodType_kind;
	this->type = type;
}

MethodType::~MethodType()
{
	// not used
}

string_t MethodType::toString()
#line 443 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "MethodType()";
}
#line 782 "ExprAst.cpp"

int MethodType::isA(int kind) const
{
	if(kind == MethodType_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *MethodType::getKindName() const
{
	return "MethodType";
}

OptParamDeclList::OptParamDeclList(Node * first_param, Node * rest_params)
	: Node()
{
	this->kind__ = OptParamDeclList_kind;
	this->first_param = first_param;
	this->rest_params = rest_params;
}

OptParamDeclList::~OptParamDeclList()
{
	// not used
}

string_t OptParamDeclList::toString()
#line 517 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    if (!first_param) return "OptParamDeclList()";
    std::ostringstream os;
    os << "OptParamDeclList(" << first_param->toString();
    if (rest_params) os << ", " << rest_params->toString();
    os << ")";
    return os.str();
}
#line 820 "ExprAst.cpp"

int OptParamDeclList::isA(int kind) const
{
	if(kind == OptParamDeclList_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *OptParamDeclList::getKindName() const
{
	return "OptParamDeclList";
}

ParamList::ParamList(Node * first_param, Node * rest_params)
	: Node()
{
	this->kind__ = ParamList_kind;
	this->first_param = first_param;
	this->rest_params = rest_params;
}

ParamList::~ParamList()
{
	// not used
}

string_t ParamList::toString()
#line 448 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    if (first_param) return "ParamList()";
    std::ostringstream os;
    os << "ParamList(" << first_param->toString();
    if (rest_params) os << ", " << rest_params->toString();
    os << ")";
    return os.str();
}
#line 858 "ExprAst.cpp"

int ParamList::isA(int kind) const
{
	if(kind == ParamList_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *ParamList::getKindName() const
{
	return "ParamList";
}

ParamDecl::ParamDecl(Node * ref_optional, Node * type, string_t identifier)
	: Node()
{
	this->kind__ = ParamDecl_kind;
	this->ref_optional = ref_optional;
	this->type = type;
	this->identifier = identifier;
}

ParamDecl::~ParamDecl()
{
	// not used
}

string_t ParamDecl::toString()
#line 457 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "ParamDecl(";
    if (ref_optional) os << ref_optional->toString() << ", ";
    os << type->toString() << ", " << identifier << ")";
    return os.str();
}
#line 896 "ExprAst.cpp"

int ParamDecl::isA(int kind) const
{
	if(kind == ParamDecl_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *ParamDecl::getKindName() const
{
	return "ParamDecl";
}

RefOptional::RefOptional(bool is_ref)
	: Node()
{
	this->kind__ = RefOptional_kind;
	this->is_ref = is_ref;
}

RefOptional::~RefOptional()
{
	// not used
}

string_t RefOptional::toString()
#line 465 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return is_ref ? "RefOptional(ref)" : "RefOptional()";
}
#line 928 "ExprAst.cpp"

int RefOptional::isA(int kind) const
{
	if(kind == RefOptional_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *RefOptional::getKindName() const
{
	return "RefOptional";
}

StmtList::StmtList(Node * first_stmt, Node * rest_stmts)
	: Node()
{
	this->kind__ = StmtList_kind;
	this->first_stmt = first_stmt;
	this->rest_stmts = rest_stmts;
}

StmtList::~StmtList()
{
	// not used
}

string_t StmtList::toString()
#line 469 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    if (!first_stmt) return "StmtList()";
    std::ostringstream os;
    os << "StmtList(" << first_stmt->toString();
    if (rest_stmts) os << ", " << rest_stmts->toString();
    os << ")";
    return os.str();
}
#line 966 "ExprAst.cpp"

int StmtList::isA(int kind) const
{
	if(kind == StmtList_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *StmtList::getKindName() const
{
	return "StmtList";
}

Stmt::Stmt()
	: Node()
{
	this->kind__ = Stmt_kind;
}

Stmt::~Stmt()
{
	// not used
}

int Stmt::isA(int kind) const
{
	if(kind == Stmt_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *Stmt::getKindName() const
{
	return "Stmt";
}

ArrayAccess::ArrayAccess(Node * expression)
	: Node()
{
	this->kind__ = ArrayAccess_kind;
	this->expression = expression;
}

ArrayAccess::~ArrayAccess()
{
	// not used
}

string_t ArrayAccess::toString()
#line 530 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    if (!expression) return "ArrayAccess()";
    return "ArrayAccess(" + expression->toString() + ")";
}
#line 1023 "ExprAst.cpp"

int ArrayAccess::isA(int kind) const
{
	if(kind == ArrayAccess_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *ArrayAccess::getKindName() const
{
	return "ArrayAccess";
}

ElseOptional::ElseOptional(Node * block)
	: Node()
{
	this->kind__ = ElseOptional_kind;
	this->block = block;
}

ElseOptional::~ElseOptional()
{
	// not used
}

string_t ElseOptional::toString()
#line 535 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    if (!block) return "ElseOptional()";
    return "ElseOptional(" + block->toString() + ")";
}
#line 1056 "ExprAst.cpp"

int ElseOptional::isA(int kind) const
{
	if(kind == ElseOptional_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *ElseOptional::getKindName() const
{
	return "ElseOptional";
}

Block::Block(Node * stmt_list)
	: Node()
{
	this->kind__ = Block_kind;
	this->stmt_list = stmt_list;
}

Block::~Block()
{
	// not used
}

string_t Block::toString()
#line 540 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "Block(" + stmt_list->toString() + ")";
}
#line 1088 "ExprAst.cpp"

int Block::isA(int kind) const
{
	if(kind == Block_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *Block::getKindName() const
{
	return "Block";
}

CallParamList::CallParamList(Node * expression, Node * call_param_rest)
	: Node()
{
	this->kind__ = CallParamList_kind;
	this->expression = expression;
	this->call_param_rest = call_param_rest;
}

CallParamList::~CallParamList()
{
	// not used
}

string_t CallParamList::toString()
#line 545 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
  
    return "CallParamList()";
}
#line 1122 "ExprAst.cpp"

int CallParamList::isA(int kind) const
{
	if(kind == CallParamList_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *CallParamList::getKindName() const
{
	return "CallParamList";
}

CallParamRest::CallParamRest(Node * expression, Node * call_param_rest)
	: Node()
{
	this->kind__ = CallParamRest_kind;
	this->expression = expression;
	this->call_param_rest = call_param_rest;
}

CallParamRest::~CallParamRest()
{
	// not used
}

string_t CallParamRest::toString()
#line 550 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
  
    return "CallParamRest()";
}
#line 1156 "ExprAst.cpp"

int CallParamRest::isA(int kind) const
{
	if(kind == CallParamRest_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *CallParamRest::getKindName() const
{
	return "CallParamRest";
}

PrintParam::PrintParam(Node * expression, string_t string_literal)
	: Node()
{
	this->kind__ = PrintParam_kind;
	this->expression = expression;
	this->string_literal = string_literal;
}

PrintParam::~PrintParam()
{
	// not used
}

string_t PrintParam::toString()
#line 555 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "PrintParam()";
}
#line 1189 "ExprAst.cpp"

int PrintParam::isA(int kind) const
{
	if(kind == PrintParam_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *PrintParam::getKindName() const
{
	return "PrintParam";
}

BinaryExpr::BinaryExpr(Node * left, Node * right)
	: Node()
{
	this->kind__ = BinaryExpr_kind;
	this->left = left;
	this->right = right;
}

BinaryExpr::~BinaryExpr()
{
	// not used
}

string_t BinaryExpr::toString()
#line 561 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "BinaryExpr(" 
       << left->toString() 
       << ", " << right->toString() 
       << ")";
    return os.str();
}
#line 1227 "ExprAst.cpp"

int BinaryExpr::isA(int kind) const
{
	if(kind == BinaryExpr_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *BinaryExpr::getKindName() const
{
	return "BinaryExpr";
}

UnaryExpr::UnaryExpr(Node * expr)
	: Node()
{
	this->kind__ = UnaryExpr_kind;
	this->expr = expr;
}

UnaryExpr::~UnaryExpr()
{
	// not used
}

string_t UnaryExpr::toString()
#line 571 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "UnaryExpr(" 
       << expr->toString() 
     
       << ")";
    return os.str();
}
#line 1264 "ExprAst.cpp"

int UnaryExpr::isA(int kind) const
{
	if(kind == UnaryExpr_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *UnaryExpr::getKindName() const
{
	return "UnaryExpr";
}

Expr::Expr()
	: Node()
{
	this->kind__ = Expr_kind;
}

Expr::~Expr()
{
	// not used
}

int Expr::isA(int kind) const
{
	if(kind == Expr_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *Expr::getKindName() const
{
	return "Expr";
}

ArrayVariable::ArrayVariable(string_t name, Node * indexExpr)
	: Node()
{
	this->kind__ = ArrayVariable_kind;
	this->name = name;
	this->indexExpr = indexExpr;
}

ArrayVariable::~ArrayVariable()
{
	// not used
}

string_t ArrayVariable::toString()
#line 658 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "ArrayVariable(" << name << ", " << indexExpr->toString() << ")";
    return os.str();
}
#line 1323 "ExprAst.cpp"

int ArrayVariable::isA(int kind) const
{
	if(kind == ArrayVariable_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *ArrayVariable::getKindName() const
{
	return "ArrayVariable";
}

AssignStmt::AssignStmt(string_t identifier, Node * array_access, Node * expression)
	: Stmt()
{
	this->kind__ = AssignStmt_kind;
	this->identifier = identifier;
	this->array_access = array_access;
	this->expression = expression;
}

AssignStmt::~AssignStmt()
{
	// not used
}

string_t AssignStmt::toString()
#line 478 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "AssignStmt(" << identifier;
    if (array_access) os << array_access->toString();
    os << ", " << expression->toString() << ")";
    return os.str();
}
#line 1361 "ExprAst.cpp"

int AssignStmt::isA(int kind) const
{
	if(kind == AssignStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *AssignStmt::getKindName() const
{
	return "AssignStmt";
}

ReturnStmt::ReturnStmt(Node * expression)
	: Stmt()
{
	this->kind__ = ReturnStmt_kind;
	this->expression = expression;
}

ReturnStmt::~ReturnStmt()
{
	// not used
}

string_t ReturnStmt::toString()
#line 486 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "ReturnStmt(" + expression->toString() + ")";
}
#line 1393 "ExprAst.cpp"

int ReturnStmt::isA(int kind) const
{
	if(kind == ReturnStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *ReturnStmt::getKindName() const
{
	return "ReturnStmt";
}

IfStmt::IfStmt(Node * expression, Node * block, Node * else_optional)
	: Stmt()
{
	this->kind__ = IfStmt_kind;
	this->expression = expression;
	this->block = block;
	this->else_optional = else_optional;
}

IfStmt::~IfStmt()
{
	// not used
}

string_t IfStmt::toString()
#line 490 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "IfStmt(" << expression->toString() << ", " << block->toString();
    if (else_optional) os << ", " << else_optional->toString();
    os << ")";
    return os.str();
}
#line 1431 "ExprAst.cpp"

int IfStmt::isA(int kind) const
{
	if(kind == IfStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *IfStmt::getKindName() const
{
	return "IfStmt";
}

WhileStmt::WhileStmt(Node * expression, Node * block)
	: Stmt()
{
	this->kind__ = WhileStmt_kind;
	this->expression = expression;
	this->block = block;
}

WhileStmt::~WhileStmt()
{
	// not used
}

string_t WhileStmt::toString()
#line 498 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "WhileStmt(" + expression->toString() + ", " + block->toString() + ")";
}
#line 1464 "ExprAst.cpp"

int WhileStmt::isA(int kind) const
{
	if(kind == WhileStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *WhileStmt::getKindName() const
{
	return "WhileStmt";
}

CallStmt::CallStmt(string_t identifier, Node * call_param_list)
	: Stmt()
{
	this->kind__ = CallStmt_kind;
	this->identifier = identifier;
	this->call_param_list = call_param_list;
}

CallStmt::~CallStmt()
{
	// not used
}

string_t CallStmt::toString()
#line 502 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "CallStmt(" << identifier << ", ";
    if (call_param_list) os << call_param_list->toString();
    os << ")";
    return os.str();
}
#line 1501 "ExprAst.cpp"

int CallStmt::isA(int kind) const
{
	if(kind == CallStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *CallStmt::getKindName() const
{
	return "CallStmt";
}

PrintStmt::PrintStmt(Node * print_param)
	: Stmt()
{
	this->kind__ = PrintStmt_kind;
	this->print_param = print_param;
}

PrintStmt::~PrintStmt()
{
	// not used
}

string_t PrintStmt::toString()
#line 510 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "PrintStmt(" + print_param->toString() + ")";
}
#line 1533 "ExprAst.cpp"

int PrintStmt::isA(int kind) const
{
	if(kind == PrintStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *PrintStmt::getKindName() const
{
	return "PrintStmt";
}

ReadStmt::ReadStmt(string_t identifier)
	: Stmt()
{
	this->kind__ = ReadStmt_kind;
	this->identifier = identifier;
}

ReadStmt::~ReadStmt()
{
	// not used
}

string_t ReadStmt::toString()
#line 526 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "ReadStmt(" + identifier + ")";
}
#line 1565 "ExprAst.cpp"

int ReadStmt::isA(int kind) const
{
	if(kind == ReadStmt_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *ReadStmt::getKindName() const
{
	return "ReadStmt";
}

FunctionCall::FunctionCall(string_t identifier, Node * call_param_list)
	: Stmt()
{
	this->kind__ = FunctionCall_kind;
	this->identifier = identifier;
	this->call_param_list = call_param_list;
}

FunctionCall::~FunctionCall()
{
	// not used
}

string_t FunctionCall::toString()
#line 663 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "FunctionCall(" << identifier << ", ";
    if (call_param_list) os << call_param_list->toString();
    os << ")";
    return os.str();
}
#line 1602 "ExprAst.cpp"

int FunctionCall::isA(int kind) const
{
	if(kind == FunctionCall_kind)
		return 1;
	else
		return Stmt::isA(kind);
}

const char *FunctionCall::getKindName() const
{
	return "FunctionCall";
}

EqualBoolean::EqualBoolean(Node * left, Node * right)
	: BinaryExpr(left, right)
{
	this->kind__ = EqualBoolean_kind;
}

EqualBoolean::~EqualBoolean()
{
	// not used
}

string_t EqualBoolean::toString()
#line 581 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "EqualBoolean(" + left->toString() + " == " + right->toString() + ")";
}
#line 1633 "ExprAst.cpp"

int EqualBoolean::isA(int kind) const
{
	if(kind == EqualBoolean_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *EqualBoolean::getKindName() const
{
	return "EqualBoolean";
}

NEqualBoolean::NEqualBoolean(Node * left, Node * right)
	: BinaryExpr(left, right)
{
	this->kind__ = NEqualBoolean_kind;
}

NEqualBoolean::~NEqualBoolean()
{
	// not used
}

string_t NEqualBoolean::toString()
#line 585 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "NEqualBoolean(" + left->toString() + " != " + right->toString() + ")";
}
#line 1664 "ExprAst.cpp"

int NEqualBoolean::isA(int kind) const
{
	if(kind == NEqualBoolean_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *NEqualBoolean::getKindName() const
{
	return "NEqualBoolean";
}

Less_ThanBoolean::Less_ThanBoolean(Node * left, Node * right)
	: BinaryExpr(left, right)
{
	this->kind__ = Less_ThanBoolean_kind;
}

Less_ThanBoolean::~Less_ThanBoolean()
{
	// not used
}

string_t Less_ThanBoolean::toString()
#line 589 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "Less_ThanBoolean(" + left->toString() + " < " + right->toString() + ")";
}
#line 1695 "ExprAst.cpp"

int Less_ThanBoolean::isA(int kind) const
{
	if(kind == Less_ThanBoolean_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *Less_ThanBoolean::getKindName() const
{
	return "Less_ThanBoolean";
}

Greater_ThanBoolean::Greater_ThanBoolean(Node * left, Node * right)
	: BinaryExpr(left, right)
{
	this->kind__ = Greater_ThanBoolean_kind;
}

Greater_ThanBoolean::~Greater_ThanBoolean()
{
	// not used
}

string_t Greater_ThanBoolean::toString()
#line 593 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "Greater_ThanBoolean(" + left->toString() + " > " + right->toString() + ")";
}
#line 1726 "ExprAst.cpp"

int Greater_ThanBoolean::isA(int kind) const
{
	if(kind == Greater_ThanBoolean_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *Greater_ThanBoolean::getKindName() const
{
	return "Greater_ThanBoolean";
}

LessEqualBoolean::LessEqualBoolean(Node * left, Node * right)
	: BinaryExpr(left, right)
{
	this->kind__ = LessEqualBoolean_kind;
}

LessEqualBoolean::~LessEqualBoolean()
{
	// not used
}

string_t LessEqualBoolean::toString()
#line 597 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "LessEqualBoolean(" + left->toString() + " <= " + right->toString() + ")";
}
#line 1757 "ExprAst.cpp"

int LessEqualBoolean::isA(int kind) const
{
	if(kind == LessEqualBoolean_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *LessEqualBoolean::getKindName() const
{
	return "LessEqualBoolean";
}

GreaterEqualBoolean::GreaterEqualBoolean(Node * left, Node * right)
	: BinaryExpr(left, right)
{
	this->kind__ = GreaterEqualBoolean_kind;
}

GreaterEqualBoolean::~GreaterEqualBoolean()
{
	// not used
}

string_t GreaterEqualBoolean::toString()
#line 601 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "GreaterEqualBoolean(" + left->toString() + " >= " + right->toString() + ")";
}
#line 1788 "ExprAst.cpp"

int GreaterEqualBoolean::isA(int kind) const
{
	if(kind == GreaterEqualBoolean_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *GreaterEqualBoolean::getKindName() const
{
	return "GreaterEqualBoolean";
}

OrBoolean::OrBoolean(Node * left, Node * right)
	: BinaryExpr(left, right)
{
	this->kind__ = OrBoolean_kind;
}

OrBoolean::~OrBoolean()
{
	// not used
}

string_t OrBoolean::toString()
#line 606 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "OrBoolean(" + left->toString() + " || " + right->toString() + ")";
}
#line 1819 "ExprAst.cpp"

int OrBoolean::isA(int kind) const
{
	if(kind == OrBoolean_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *OrBoolean::getKindName() const
{
	return "OrBoolean";
}

AndBoolean::AndBoolean(Node * left, Node * right)
	: BinaryExpr(left, right)
{
	this->kind__ = AndBoolean_kind;
}

AndBoolean::~AndBoolean()
{
	// not used
}

string_t AndBoolean::toString()
#line 610 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "AndBoolean(" + left->toString() + " && " + right->toString() + ")";
}
#line 1850 "ExprAst.cpp"

int AndBoolean::isA(int kind) const
{
	if(kind == AndBoolean_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *AndBoolean::getKindName() const
{
	return "AndBoolean";
}

SumExpr::SumExpr(Node * left, Node * right)
	: BinaryExpr(left, right)
{
	this->kind__ = SumExpr_kind;
}

SumExpr::~SumExpr()
{
	// not used
}

string_t SumExpr::toString()
#line 618 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "SumExpr(" + left->toString() + " + " + right->toString() + ")";
}
#line 1881 "ExprAst.cpp"

int SumExpr::isA(int kind) const
{
	if(kind == SumExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *SumExpr::getKindName() const
{
	return "SumExpr";
}

SubExpr::SubExpr(Node * left, Node * right)
	: BinaryExpr(left, right)
{
	this->kind__ = SubExpr_kind;
}

SubExpr::~SubExpr()
{
	// not used
}

string_t SubExpr::toString()
#line 622 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "SubExpr(" + left->toString() + " - " + right->toString() + ")";
}
#line 1912 "ExprAst.cpp"

int SubExpr::isA(int kind) const
{
	if(kind == SubExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *SubExpr::getKindName() const
{
	return "SubExpr";
}

MulExpr::MulExpr(Node * left, Node * right)
	: BinaryExpr(left, right)
{
	this->kind__ = MulExpr_kind;
}

MulExpr::~MulExpr()
{
	// not used
}

string_t MulExpr::toString()
#line 626 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "MulExpr(" + left->toString() + " * " + right->toString() + ")";
}
#line 1943 "ExprAst.cpp"

int MulExpr::isA(int kind) const
{
	if(kind == MulExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *MulExpr::getKindName() const
{
	return "MulExpr";
}

DivExpr::DivExpr(Node * left, Node * right)
	: BinaryExpr(left, right)
{
	this->kind__ = DivExpr_kind;
}

DivExpr::~DivExpr()
{
	// not used
}

string_t DivExpr::toString()
#line 630 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "DivExpr(" + left->toString() + " / " + right->toString() + ")";
}
#line 1974 "ExprAst.cpp"

int DivExpr::isA(int kind) const
{
	if(kind == DivExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *DivExpr::getKindName() const
{
	return "DivExpr";
}

ModExpr::ModExpr(Node * left, Node * right)
	: BinaryExpr(left, right)
{
	this->kind__ = ModExpr_kind;
}

ModExpr::~ModExpr()
{
	// not used
}

string_t ModExpr::toString()
#line 634 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "ModExpr(" + left->toString() + " % " + right->toString() + ")";
}
#line 2005 "ExprAst.cpp"

int ModExpr::isA(int kind) const
{
	if(kind == ModExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *ModExpr::getKindName() const
{
	return "ModExpr";
}

UnaryNotBoolean::UnaryNotBoolean(Node * expr)
	: UnaryExpr(expr)
{
	this->kind__ = UnaryNotBoolean_kind;
}

UnaryNotBoolean::~UnaryNotBoolean()
{
	// not used
}

string_t UnaryNotBoolean::toString()
#line 614 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "UnaryNotBoolean(!" + expr->toString() + ")";
}
#line 2036 "ExprAst.cpp"

int UnaryNotBoolean::isA(int kind) const
{
	if(kind == UnaryNotBoolean_kind)
		return 1;
	else
		return UnaryExpr::isA(kind);
}

const char *UnaryNotBoolean::getKindName() const
{
	return "UnaryNotBoolean";
}

UnaryAddExpr::UnaryAddExpr(Node * expr)
	: UnaryExpr(expr)
{
	this->kind__ = UnaryAddExpr_kind;
}

UnaryAddExpr::~UnaryAddExpr()
{
	// not used
}

string_t UnaryAddExpr::toString()
#line 638 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "UnaryAddExpr(" + expr->toString() + ")";
}
#line 2067 "ExprAst.cpp"

int UnaryAddExpr::isA(int kind) const
{
	if(kind == UnaryAddExpr_kind)
		return 1;
	else
		return UnaryExpr::isA(kind);
}

const char *UnaryAddExpr::getKindName() const
{
	return "UnaryAddExpr";
}

UnarySubExpr::UnarySubExpr(Node * expr)
	: UnaryExpr(expr)
{
	this->kind__ = UnarySubExpr_kind;
}

UnarySubExpr::~UnarySubExpr()
{
	// not used
}

string_t UnarySubExpr::toString()
#line 642 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return "UnarySubExpr(-" + expr->toString() + ")";
}
#line 2098 "ExprAst.cpp"

int UnarySubExpr::isA(int kind) const
{
	if(kind == UnarySubExpr_kind)
		return 1;
	else
		return UnaryExpr::isA(kind);
}

const char *UnarySubExpr::getKindName() const
{
	return "UnarySubExpr";
}

Number::Number(int value)
	: Expr()
{
	this->kind__ = Number_kind;
	this->value = value;
}

Number::~Number()
{
	// not used
}

string_t Number::toString()
#line 646 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "Number(" << value << ")";
    return os.str();
}
#line 2132 "ExprAst.cpp"

int Number::isA(int kind) const
{
	if(kind == Number_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *Number::getKindName() const
{
	return "Number";
}

Identifier::Identifier(string_t name)
	: Expr()
{
	this->kind__ = Identifier_kind;
	this->name = name;
}

Identifier::~Identifier()
{
	// not used
}

string_t Identifier::toString()
#line 652 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "Identifier(" << name << ")";
    return os.str();
}
#line 2166 "ExprAst.cpp"

int Identifier::isA(int kind) const
{
	if(kind == Identifier_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *Identifier::getKindName() const
{
	return "Identifier";
}

static CodegenResult exprCompile_1__(Program *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 676 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // string_t class_name;
    // Node *variable_decls;
    // Node *method_decls;

    std::ostringstream os;
    os << "\n\ndeclare i32 @printf(i8*, ...)\n";
    os << "declare i32 @exit(i32)\n";
    // os << "define i32 @main() {\n";
       
    if(root->varmethod_decls) {
         CodegenResult r2 = exprCompile(root->varmethod_decls, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
           os << r2.code << "\n";
        //    os << r2.place;
           std::cout << "SIII HAY METODOS" << std::endl;
    }else{
        std::cout << "NO HAY METODOS" << std::endl;
    }

        
   

    if(root->method_decls) {
        CodegenResult r2 = exprCompile(root->method_decls, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
        os << r2.code;
    }
 

    os << "@.fmt = private constant [4 x i8] c\"%d\\0A\\00\", align 1\n";

    for (const auto& [lit, var] : textsTable) {
        int size = lit.size() + 2;
        os << var << " = private constant [" << size << " x i8] c\"" << lit << "\\0A\\00\", align 1\n";
    }

    return { os.str(), "" };
}
#line 2220 "ExprAst.cpp"

static CodegenResult exprCompile_2__(VarMethodDeclList *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 715 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *first_decl;   variables 
    // Node *rest_decls;   metodos
    std::ostringstream os;
    std::string NoMethod;
    CodegenResult r;
    // Variables
    Ast::MethodDeclList* Method_DLIST = dynamic_cast<Ast::MethodDeclList*>(root->first_decl);
    Ast::MethodDeclList* Method_DLIST_2 = dynamic_cast<Ast::MethodDeclList*>(root->rest_decls);
  // os << "ITERACION " << "\n";
  CodegenResult r1 =exprCompile(root->first_decl, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    if(Method_DLIST ){
        std::cout << "ES METOODO ------------ antes de declarar variables" << std::endl;
        // os << "ES METOODO";
        // os << "ret i32 0\n";
        // os << "}\n\n";

        for (const auto& [var, variable] : vars) {
            if (variable.methodIdentifier == actualmethodName) {
                if(variable.methodIdentifier.empty()){ // son globales
                    os << "    @" << var << " = global i32 zeroinitializer\n";
                    // @x = global i32 0 
                }else{
                    os << "    %" << var << " = alloca i32, align 4\n";
                }
               
            }
        }

        for (const auto& [arrVarIdent, arrayVariable] : arrayvarTable) {
            if (arrayVariable.methodIdentifier == actualmethodName) {
                if(arrayVariable.methodIdentifier.empty()){ // son globales
                    os << "    @" << arrVarIdent << " = global ["<< arrayVariable.values.size() <<" x i32] zeroinitializer\n";
                 
                    // @global_array = global [10 x i32] zeroinitializer
                }else{
                    os << "    %" << arrVarIdent << " = alloca i32, align 4\n";
                       // %array = alloca [10 x i32], align 4 
                }
               
            }
        }

    }else{
        std::cout << "ES METOODO ------------ antes de declarar variables" << std::endl;
        NoMethod="";
        for (const auto& [var, variable] : vars) {
            if (variable.methodIdentifier == actualmethodName) {
                if(variable.methodIdentifier.empty()){ // son globales
                    NoMethod  +="    @" +  var + " = global i32 zeroinitializer\n";
                    // @x = global i32 0 
                }else{
                    NoMethod  += "    %" +  var +  " = alloca i32, align 4\n";
                }
               
            }
        }

        for (const auto& [arrVarIdent, arrayVariable] : arrayvarTable) {
            if (arrayVariable.methodIdentifier == actualmethodName) {
                if(arrayVariable.methodIdentifier.empty()){ // son globales
                    NoMethod += "    @" + arrVarIdent +  " = global ["+ std::to_string(arrayVariable.values.size()) +" x i32] zeroinitializer\n";
                 
                    // @global_array = global [10 x i32] zeroinitializer
                }else{
                    NoMethod  += "    %" + arrVarIdent +  " = alloca i32, align 4\n";
                       // %array = alloca [10 x i32], align 4 
                }
               
            }
        }

        
    }
  
    os << r1.code;
   
   
  
   
    if(root->rest_decls){
    os << exprCompile(root->rest_decls, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos).code;
    }


   r.place = NoMethod;
   r.code = os.str();

    return r;
}
#line 2314 "ExprAst.cpp"

static CodegenResult exprCompile_3__(VariableDeclList *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 807 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *first_decl;
    // Node *rest_decls;
    std::ostringstream os;

    if (root->first_decl) {
        CodegenResult r = exprCompile(root->first_decl, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
        os << r.code;
    }
    if (root->rest_decls) {
        CodegenResult r = exprCompile(root->rest_decls, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
        os << r.code;
    }

    return {os.str(), ""};
}
#line 2334 "ExprAst.cpp"

static CodegenResult exprCompile_4__(VariableDecl *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 824 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *type;
    // string_t identifier;
    // Node *variableDecl_Body;
    std::ostringstream os;

    Ast::Type* arrayAccessNode = dynamic_cast<Ast::Type*>(root->type);
    if (arrayAccessNode && arrayAccessNode->array_optional) {
        auto it = arrayvarTable.find(root->identifier + actualmethodName);
        if (it != arrayvarTable.end()) {
            throw std::runtime_error("Error (VD): Array '" + root->identifier + "' already declared.");
        }
        it = arrayvarTable.find(root->identifier);
        if (it != arrayvarTable.end()) {
            throw std::runtime_error("Error (VD): Global Array '" + root->identifier + "' already declared.");
        }


        CodegenResult r = exprCompile( arrayAccessNode->array_optional, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
        arrayvarTable[root->identifier + actualmethodName] = {actualmethodName, std::vector<std::optional<int>> (std::stoi(r.code), std::nullopt), nullptr}; 
        std::cout << "ARRAY CREADO 1" << root->identifier + actualmethodName << std::endl;
    } else {

        auto it = vars.find(root->identifier + actualmethodName);
        if (it != vars.end()) {
            throw std::runtime_error("Error (VD): Variable '" + root->identifier + "' already declared.");
        }
        it = vars.find(root->identifier);
        if (it != vars.end()) {
            throw std::runtime_error("Error (VD): Global Variable '" + root->identifier + "' already declared.");
        }
        

        vars[root->identifier + actualmethodName] = {actualmethodName, std::nullopt, nullptr};
        
        std::cout << "VARIABLE CREADA" << root->identifier + actualmethodName << std::endl;

    }
    if (root->variableDecl_Body) {
        exprCompile(root->variableDecl_Body, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    }

 
    

    return {os.str(), ""};
}
#line 2385 "ExprAst.cpp"

static CodegenResult exprCompile_5__(VariableDecl_Body *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 872 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *ident_list;
    std::ostringstream os;
    if(root->ident_list) {
        os << exprCompile(root->ident_list, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos).code;
    }
    return {os.str(), ""};
}
#line 2397 "ExprAst.cpp"

static CodegenResult exprCompile_6__(IdentList *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 881 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // string_t identifier;
    // Node *IdentListParam;
    std::ostringstream os;
    vars[root->identifier + actualmethodName] ={actualmethodName, std::nullopt, nullptr}; 

    if(root->IdentListParam) exprCompile(root->IdentListParam, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    os << "";
    return {os.str(), ""};
}
#line 2411 "ExprAst.cpp"

static CodegenResult exprCompile_7__(Type *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 892 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // string_t type_name;
    // Node *array_optional;
    std::ostringstream os;
    // os << "Type(" << root->type_name;

    CodegenResult r;
    r.place = "";
    // os << root->type_name;
    if(root->array_optional){
        // os << exprCompile(root->array_optional, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos).code;
        r.place = "arr";
    }
    if(root->type_name == "INT"){
       r.code = " i32";
    }

    
        // os << ")";
    return r;
}
#line 2436 "ExprAst.cpp"

static CodegenResult exprCompile_8__(ArrayOptional *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 914 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // int size;
    std::ostringstream os;
    os << std::to_string(root->size);
    return {os.str(), ""};
}
#line 2446 "ExprAst.cpp"

static CodegenResult exprCompile_9__(MethodDeclList *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 921 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *first_decl;
    // Node *rest_decls;
    std::ostringstream os;
 
    if(root->first_decl)
        os << exprCompile(root->first_decl, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos).code;
    if(root->rest_decls)
        os << exprCompile(root->rest_decls, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos).code;
  
    return {os.str(), ""};
}
#line 2462 "ExprAst.cpp"

static CodegenResult exprCompile_10__(MethodDecl *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 933 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;

 

    // Obtener el tipo del método
    CodegenResult r = exprCompile(root->method_type, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    
    os << "define " << r.code;
    os << "@" << root->identifier;

    // Corrección: Verificar el dynamic_cast
    auto *methodBody = dynamic_cast<MethodDecl_Body*>(root->MethodDecl_Body);
    if (!methodBody) {
        throw std::runtime_error("Invalid method body structure");
    }

    // Extraer parámetros del método
    std::vector<std::string> paramTypes;
    // Node *paramNode = methodBody->opt_param_decl_list;
    // while (paramNode) {
    //     // Verificar tipo antes de acceder
    //     auto *paramDeclList = dynamic_cast<OptParamDeclList*>(paramNode);
    //     if (!paramDeclList) break;

    //     auto *paramDecl = dynamic_cast<ParamDecl*>(paramDeclList->first_param);
    //     if (paramDecl) { // Solo procesar si el cast es válido
    //         CodegenResult paramResult = exprCompile(paramDecl, vars, methodTable, args, arrayvarTable, root->identifier, textsTable, paramPos);
    //         paramTypes.push_back(paramResult.code);
    //     }

    //     paramNode = paramDeclList->rest_params;
    // }

   
    // Buscar el método en la tabla
    auto it = methodTable.find(root->identifier);
    if (it == methodTable.end()) {
        // Insertar el nuevo método en la tabla
        methodVariable newMethod;
        newMethod.methodName = root->identifier;
        newMethod.Type = r.code; // Tipo de retorno
        newMethod.params = paramTypes;

        methodTable[root->identifier] = newMethod;
    } else {
        // Si ya existe y no es main, actualizamos el tipo de retorno
        if (root->identifier != "main") {
            it->second.Type = r.code;
        }
    }

 
     // Compilar el cuerpo del método
     os << exprCompile(root->MethodDecl_Body, vars, methodTable, args, arrayvarTable, root->identifier, textsTable, paramPos).code;


     bool hasReturns = false;

     auto itMethod = methodTable.find(root->identifier);
        if (itMethod != methodTable.end()) {
            hasReturns = itMethod->second.hasReturnStmt;
        }
     
     Ast::MethodDecl_Body* MethodBodyNode = dynamic_cast<Ast::MethodDecl_Body*>(root->MethodDecl_Body);


      
        
    // YA NO ES NECESARIO HACER ESTO
        // if(MethodBodyNode->stmt_list){
        //     hasReturns = false;
        //     Ast::StmtList* StmtListNode = dynamic_cast<Ast::StmtList*>(MethodBodyNode->stmt_list);
            
        //     while(StmtListNode){
        //         Ast::Stmt* Statement = dynamic_cast<Ast::Stmt*>(StmtListNode->first_stmt);
               
        //         if(Statement){
        //             std::cout << "STATEMENT" << std::endl;
        //             if(dynamic_cast<Ast::ReturnStmt*>(Statement)){
        //                 hasReturns = true;
        //                 break;
        //             }

        //             StmtListNode = dynamic_cast<Ast::StmtList*>(StmtListNode->rest_stmts);
        //         }
        //     }
               
        // }
        

     
    if (r.code == "i32 ") {

        if (!hasReturns) {
            throw std::runtime_error("Error (MD): Method '" + root->identifier + "' must return a value.");
        }


        os << "ret i32 0\n"; //
    }else{
        os << "ret void\n";
    }



    os << "}\n\n";

    return {os.str(), ""};
}
#line 2576 "ExprAst.cpp"

static CodegenResult exprCompile_11__(MethodDecl_Body *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1047 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *opt_param_decl_list;
    // Node *variable_decls;
    // Node *stmt_list;
    std::ostringstream os;
    os << "(";
    if(root->opt_param_decl_list){
         os << exprCompile(root->opt_param_decl_list, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos).code;
    }
    os << ")";
    os << "{" << "\n";
    if(root->variable_decls){
        os << exprCompile(root->variable_decls, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos).code;
        for (const auto& [var, variable] : vars) {
            if (variable.methodIdentifier == actualmethodName && !variable.isArgument) {
                if(variable.methodIdentifier.empty()){ // son globales
                    os << "    @" << var << " = global i32 zeroinitializer\n";
                    // @x = global i32 0 
                }else{
                    os << "    %" << var << " = alloca i32, align 4\n";
                }
               
            }
        }
        for (const auto& [arrVarIdent, arrayVariable] : arrayvarTable) {
            if (arrayVariable.methodIdentifier == actualmethodName && !arrayVariable.isArgument) {
                if(arrayVariable.methodIdentifier.empty()){ // son globales
                    os << "    @" << arrVarIdent << " = global ["<< arrayVariable.values.size() <<" x i32] zeroinitializer\n";
                 
                    // @global_array = global [10 x i32] zeroinitializer
                }else{
                    os << "    %" << arrVarIdent << " = alloca ["<< arrayVariable.values.size() <<" x i32], align 4\n";
                       // %array = alloca [10 x i32], align 4 
                }
               
            }
        }
    }
    if(root->stmt_list)
        os << exprCompile(root->stmt_list, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos).code;
    // os << ")";

    return {os.str(), ""};
}
#line 2624 "ExprAst.cpp"

static CodegenResult exprCompile_12__(MethodType *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1092 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // string_t type;
    std::ostringstream os;
    // os << "MethodType(" << root->type << ")";

    if(root->type == "INT" ){
        os << "i32 ";
    }else if(root->type == "VOID"){
        os << "void ";
    }

    return {os.str(), ""};
}
#line 2641 "ExprAst.cpp"

static CodegenResult exprCompile_13__(OptParamDeclList *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1106 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *first_param;
    // Node *rest_params;
    std::ostringstream os;
    // os << "OptParamDeclList(";
    if(root->first_param){
        os << exprCompile(root->first_param, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos).code;
    }
    if(root->rest_params){
        os << exprCompile(root->rest_params, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos).code;
    }
        // os << ")";
    return {os.str(), ""};
}
#line 2659 "ExprAst.cpp"

static CodegenResult exprCompile_14__(ParamList *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1174 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *first_param;
    // Node *rest_params;
    std::ostringstream os;
    // os << "ParamList(";
    os << ", ";
    if(root->first_param)
        os << exprCompile(root->first_param, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos).code;
   
    if(root->rest_params)
        os << exprCompile(root->rest_params, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos).code;
    // os << ")";
    return {os.str(), ""};
}
#line 2677 "ExprAst.cpp"

static CodegenResult exprCompile_15__(ParamDecl *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1121 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *ref_optional;
    // Node *type;
    // string_t identifier;
    std::ostringstream os;

    
    CodegenResult r2 = exprCompile(root->type, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    CodegenResult r1;
    r1.code == "";
    os << "i32";
    if(root->ref_optional){
    r1 = exprCompile(root->ref_optional, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
   
    if((r1.code == "true")){
        os <<  "* ";
    }
    }else if (  r2.place != "") {
        os <<  "* ";
    }
    else{
        os <<  " ";
    }
    os << "%";
    os << root->identifier << actualmethodName;

    // Desconocemos el tamano
    if (  r2.place != "") {
    
       std::cout << "ARRAY CREADO"<< root->identifier + actualmethodName << std::endl;
        // FIX: DESCONOCEMOS EL TAMANHO DEL ARREGLO
        // FIX: POSIBLE SOLUCION MARCAR COMO YA TIENEN VALOR LOS PARAMS
        arrayvarTable[root->identifier + actualmethodName] = {actualmethodName, std::vector<std::optional<int>> (1, 1), nullptr, true}; 
        methodTable[actualmethodName].params.push_back("ARRAY");
    } else {
       
        if((r1.code == "true")){
            methodTable[actualmethodName].params.push_back("REF");
            vars[root->identifier+ actualmethodName] = {actualmethodName, 1, nullptr, true, true}; 
            std::cout << "REF CREADO" << std::endl;
        }else{
            methodTable[actualmethodName].params.push_back("VAR");
            vars[root->identifier+ actualmethodName] = {actualmethodName, 1, nullptr, true, false}; 
        }
        
    }



    
    return {os.str(), ""};
}
#line 2733 "ExprAst.cpp"

static CodegenResult exprCompile_16__(RefOptional *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1402 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // bool is_ref;
    std::ostringstream os;
    os << (root->is_ref ? "true" : "false");
    return {os.str(), ""};
}
#line 2743 "ExprAst.cpp"

static CodegenResult exprCompile_17__(StmtList *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1409 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *first_stmt;
    // Node *rest_stmts;
    std::ostringstream os;

    if(root->first_stmt)
        os << exprCompile(root->first_stmt, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos).code;
    if(root->rest_stmts)
        os << exprCompile(root->rest_stmts, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos).code;

    return {os.str(), ""};
}
#line 2759 "ExprAst.cpp"

static CodegenResult exprCompile_18__(AssignStmt *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1191 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // string_t identifier;
    // Node *array_access;
    // Node *expression;
    std::ostringstream os;
    // os << "AssignStmt(" << root->identifier;
        if(root->array_access){
            auto it_global = arrayvarTable.find( root->identifier);

            if (it_global != arrayvarTable.end()){
                CodegenResult r;
                //Valor a Ingresar
                CodegenResult r2 = exprCompile(root->expression, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
                os << r2.code << "\n";

                // Indice de Arreglo
                CodegenResult r1 = exprCompile(root->array_access, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
                os << r1.code << "\n";
                r.place = newVariable();

                os << "%"<< r.place <<" = getelementptr ["<< it_global->second.values.size()<<" x i32], ["<< it_global->second.values.size()<<" x i32]* @"<< root->identifier <<", i32 0, i32 %"<< r1.place << "\n";
                os << "store i32 %"<< r2.place << ", i32* %"<< r.place << ", align 4" << "\n";

            }else{
            auto it = arrayvarTable.find( root->identifier + actualmethodName);
                if (it == arrayvarTable.end()){
                    throw std::runtime_error("Error (AS): Array '" + root->identifier +actualmethodName + "' not declared.");
                }else{
                    CodegenResult r;
                    //Valor a Ingresar
                    CodegenResult r2 = exprCompile(root->expression, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
                    os << r2.code << "\n";

                    // Indice de Arreglo
                    CodegenResult r1 = exprCompile(root->array_access, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
                    os << r1.code << "\n";
                    r.place = newVariable();

                    os << "%"<< r.place <<" = getelementptr ["<< it->second.values.size()<<" x i32], ["<< it->second.values.size()<<" x i32]* %"<< root->identifier<<actualmethodName <<", i32 0, i32 %"<< r1.place << "\n";
                    os << "store i32 %"<< r2.place << ", i32* %"<< r.place << ", align 4" << "\n";

                }

            }
               

            // ; Obtener dirección de la posición 2 del array global
            // %idx = getelementptr [5 x i32], [5 x i32]* @global_array, i32 0, i32 2

            // ; Almacenar el valor 42 en la posición 2
            // store i32 42, i32* %idx
        }else{
          

            if(root->expression){
                auto it_global = vars.find( root->identifier);

                if (it_global != vars.end()){
                    CodegenResult r = exprCompile(root->expression, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
                    os << r.code << "\n";
        
                    // auto it = vars.find( root->identifier + actualmethodName);
                    if (it_global != vars.end()){ it_global->second.value = 1; //Solucion Posible para determinar que tiene un valor
                    os << "store " << "i32 %" << r.place << ", i32* @" << root->identifier << "\n";
                    }else{
                        throw std::runtime_error("Error (AS): Variable '" + root->identifier + "' not declared.");
                    }
                }else{


                CodegenResult r = exprCompile(root->expression, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
                os << r.code << "\n";
    
                auto it = vars.find( root->identifier + actualmethodName);
                if (it != vars.end()) {
                
                it->second.value = 1; //Solucion Posible para determinar que tiene un valor
                os << "store " << "i32 %" << r.place << ", i32* %" << root->identifier<<actualmethodName << "\n";
                }else{
                    throw std::runtime_error("Error (AS): Variable '" + root->identifier + "' not declared.");
                }
                
                 }



            }

    
    
    
    }
  
    
        // os << ")";
    return {os.str(), ""};
}
#line 2860 "ExprAst.cpp"

static CodegenResult exprCompile_19__(ReturnStmt *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1289 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *expression;
    std::ostringstream os;
    
    CodegenResult r;
    if(root->expression){
        r = exprCompile(root->expression, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
        os << r.code << "\n";
        os << "ret i32 %" << r.place << "" << "\n";
        r.code = os.str();
    }

    auto it = methodTable.find(actualmethodName);
    if (it != methodTable.end()) {
        it->second.hasReturnStmt = true;
    }
    return r;
}
#line 2882 "ExprAst.cpp"

static CodegenResult exprCompile_20__(IfStmt *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1308 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *expression;
    // Node *block;
    // Node *else_optional;
    std::ostringstream os;
    // os << "IfStmt(";
    CodegenResult r;
    CodegenResult rBool = exprCompile(root->expression, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    // os << "br "<< rBool.place << ""
    
    std::string ifPart_label = newLabel();
    std::string endif_label = newLabel();

    // CodegenResult rTrueBlock
    CodegenResult rTrue;
    if(root->block){
        rTrue = exprCompile(root->block, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    }

    os << rBool.code << "\n";
    r.place = newVariable();
    os << "%" << r.place << " = icmp ne i32 %" << rBool.place << ", 0\n";
    // %t4 = icmp ne i32 %t2, 0 
    
    if(root->else_optional){

        std::string elsePart_label = newLabel();
        os << "br i1 %" <<  r.place << ", label %" << ifPart_label <<", label %"<< elsePart_label << "\n";
        os << ifPart_label << ":" << "\n";
       
        os << rTrue.code << "\n";
        os << "br label %" << endif_label << "\n";
        os << elsePart_label << ":" << "\n";
        os << exprCompile(root->else_optional, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos).code;
        
        os << "br label %" << endif_label << "\n";
    }else{
        os << "br i1 %" <<  r.place  << ", label %" <<  ifPart_label <<", label %"<< endif_label << "\n";
        os << ifPart_label << ":" << "\n";
       
        os << rTrue.code << "\n";

        os << "br label %" << endif_label << "\n";
    }

    os << endif_label << ":" << "\n";




        // os << ")";
    return {os.str(), ""};
}
#line 2939 "ExprAst.cpp"

static CodegenResult exprCompile_21__(WhileStmt *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1362 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *expression;
    // Node *block;

        std::ostringstream os;
        CodegenResult r;
    
       
        std::string cond_label = newLabel();  
        std::string body_label = newLabel();  
        std::string exit_label = newLabel(); 
    
     
        os << "br label %" << cond_label << "\n";
    
        
        os << cond_label << ":\n";
        
        CodegenResult cond_result = exprCompile(root->expression, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
        os << cond_result.code << "\n";
    
    
        std::string bool_var = newVariable();
        os << "%" << bool_var << " = icmp ne i32 %" << cond_result.place << ", 0\n";
     
        os << "br i1 %" << bool_var << ", label %" << body_label << ", label %" << exit_label << "\n";
   
        os << body_label << ":\n";
     
        CodegenResult body_result = exprCompile(root->block, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
        os << body_result.code << "\n";

        os << "br label %" << cond_label << "\n";
    
     
        os << exit_label << ":\n";
    
        return { os.str(), "" };
    }
#line 2982 "ExprAst.cpp"

static CodegenResult exprCompile_22__(CallStmt *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1422 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;

    auto it = methodTable.find(root->identifier);

    if(it == methodTable.end()){
        // FIX: IMPLEMENTAR ERRORES NO HAY METODO CON ESE NONBRE
        throw std::runtime_error("Error: Method '" + root->identifier + "' not declared.");
    }

    std::string methodType = it->second.Type;


    CodegenResult r; 
    CodegenResult r1; 

    arguments argsMethod = it->second.params; 
    std::cout << "Method: " << root->identifier << " Arguments" << std::endl;
    std::cout << "args: " << argsMethod.size() << std::endl;
    for (int i = 0; i < argsMethod.size(); i++) {
        std::cout << "args: " << argsMethod[i] << std::endl;
    }
    paramPos=0;
    args = argsMethod;
    
    int argumentsCount = 0;
    CallParamList* CallParamListNode = dynamic_cast<CallParamList*>(root->call_param_list);
    if(CallParamListNode){
        argumentsCount++;

        CallParamRest* CallParamRestNode = dynamic_cast<CallParamRest*>(CallParamListNode->call_param_rest);
        while(CallParamRestNode){
            argumentsCount++;
          
            CallParamRestNode= dynamic_cast<CallParamRest*>(CallParamRestNode->call_param_rest);

        }
    }

    if(argumentsCount != args.size()){
        throw std::runtime_error("Error as CallStmt: Argument number mismatch." + std::to_string(argumentsCount) + " " + std::to_string(args.size()));
    }


    //           if(r1.args.size() != args.size()){
    //     throw std::runtime_error("Error as CallStmt: Argument number mismatch.");
    // }



    if(root->call_param_list){
        r1 = exprCompile(root->call_param_list, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
 
    }

    std::cout << "CallStmt: " << root->identifier << " Params" << std::endl;
    std::cout << "args: " << args.size() << std::endl;
    std::cout << "args paramPos: " <<  r1.argsNum << std::endl;
    std::cout << "args paramPos2: " <<  r1.args.size() << std::endl;
    for (int i = 0; i < r1.args.size(); i++) {
        std::cout << "args: " << r1.args[i] << std::endl;
    }

  
  
    r.place = newVariable();
    os << r1.code << "\n";
    os <<"call "<< it->second.Type << "@" << root->identifier <<"(";
    // os << TIPO;

    os << r1.place;
    os << ")" << "\n";

    r.code = os.str();
   
    
   
    return r;
}
#line 3065 "ExprAst.cpp"

static CodegenResult exprCompile_23__(PrintStmt *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1643 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *print_param;
    std::ostringstream os;
    if(root->print_param){
 
        // os << exprCompile(root->print_param, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos).code;
        CodegenResult r = exprCompile(root->print_param, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
        os << r.code << "\n";
    }
    return {os.str(), ""};
}
#line 3080 "ExprAst.cpp"

static CodegenResult exprCompile_24__(ReadStmt *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1713 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // string_t identifier;

        std::ostringstream os;
        std::string varName = root->identifier + actualmethodName;
    

        auto varIt = vars.find(varName+ actualmethodName);
        if (varIt == vars.end()) {
            if (arrayvarTable.find(varName + actualmethodName) != arrayvarTable.end()) {
                throw std::runtime_error("Error: Cannot read into array variable '" + varName + "'.");
            } else {
                throw std::runtime_error("Error: Variable '" + varName + "' not declared.");
            }
        }
    
      
        std::string varPtr;
        if (varIt->second.methodIdentifier.empty()) {
            varPtr = "@" + varName; 
        } else {
            varPtr = "%" + varName;  
        }
    
  
        std::string resultVar = newVariable();
        os << "%" << resultVar << " = call i32 (i8*, ...) @printf("
           << "i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.printf, i32 0, i32 0), "
           << "i32* " << varPtr << ")\n";
    
        return { os.str(), "" };
    }
#line 3116 "ExprAst.cpp"

static CodegenResult exprCompile_25__(FunctionCall *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 2289 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // string_t identifier;
    // Node *call_param_list;
    std::ostringstream os;

    auto it = methodTable.find(root->identifier);

    if(it == methodTable.end()){
        // FIX: IMPLEMENTAR ERRORES NO HAY METODO CON ESE NONBRE
        throw std::runtime_error("Error: Method '" + root->identifier + actualmethodName+ "' not declared.");
    }

    std::string methodType = it->second.Type;


    CodegenResult r; 
    CodegenResult r1; 

    arguments argsMethod = it->second.params; 
    std::cout << "Method: " << root->identifier << " Arguments" << std::endl;
    std::cout << "args: " << argsMethod.size() << std::endl;
    for (int i = 0; i < argsMethod.size(); i++) {
        std::cout << "args: " << argsMethod[i] << std::endl;
    }

    args = argsMethod;
    paramPos=0;

    int argumentsCount = 0;
    CallParamList* CallParamListNode = dynamic_cast<CallParamList*>(root->call_param_list);
    if(CallParamListNode){
        argumentsCount++;

        CallParamRest* CallParamRestNode = dynamic_cast<CallParamRest*>(CallParamListNode->call_param_rest);
        while(CallParamRestNode){
            argumentsCount++;
          
            CallParamRestNode= dynamic_cast<CallParamRest*>(CallParamRestNode->call_param_rest);

        }
    }

    if(argumentsCount != args.size()){
        throw std::runtime_error("Error as FuncCallStmt: Argument number mismatch." + std::to_string(argumentsCount) + " " + std::to_string(args.size()));
    }


    if(root->call_param_list){
        r1 = exprCompile(root->call_param_list, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
 
    }

    std::cout << "Function Call: " << root->identifier << " Params" << std::endl;
    std::cout << "args: " << args.size() << std::endl;
    std::cout << "args paramPos: " << paramPos << std::endl;
    std::cout << "args paramPos2: " <<  r1.args.size() << std::endl;
    for (int i = 0; i < r1.args.size(); i++) {
        std::cout << "args: " << r1.args[i] << std::endl;
    }

    if(r1.args.size() != args.size()){
        throw std::runtime_error("Error as FunctionCall: Argument number mismatch.");
    }



  
    r.place = newVariable();
    os << r1.code << "\n";
    os << "%"<< r.place  <<" = call "<< it->second.Type << "@" << root->identifier <<"(";
    // os << TIPO;

    os << r1.place;
    os << ")" << "\n";

    r.code = os.str();
   
    
   
    return r;
}
#line 3201 "ExprAst.cpp"

static CodegenResult exprCompile_26__(ArrayAccess *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1745 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *expression;
    std::ostringstream os;
    
    CodegenResult r;
    if(root->expression){
        r = exprCompile(root->expression, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    }
    return r;
}
#line 3215 "ExprAst.cpp"

static CodegenResult exprCompile_27__(ElseOptional *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1756 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *block;
    std::ostringstream os;
    // os << "ElseOptional(";
    CodegenResult r = exprCompile(root->block, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    // os << ")";
    return r;
}
#line 3227 "ExprAst.cpp"

static CodegenResult exprCompile_28__(Block *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1765 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *stmt_list;
    std::ostringstream os;
    // os << "Block(";
    if(root->stmt_list)
        os << exprCompile(root->stmt_list, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos).code;
    // os << ")";
    return {os.str(), ""};
}
#line 3240 "ExprAst.cpp"

static CodegenResult exprCompile_29__(CallParamList *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1503 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    CodegenResult r;
    // std::vector<std::string> localargs;
    if (root->expression) {
        CodegenResult r1 = exprCompile(root->expression, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
        r.code = r1.code + "\n";
        // Inferir tipo directamente aquí
        std::string argType = "VAR"; // Valor por defecto
        std::string llvmType = "i32 %";
        
        // Caso 1: Es un identificador
        if (auto* ident = dynamic_cast<Identifier*>(root->expression)) {
            // Buscar en tablas de símbolos
            if (arrayvarTable.find(ident->name + actualmethodName) != arrayvarTable.end()) {
                argType = "ARRAY";
                llvmType = "i32* %";
                r1.place = ident->name + actualmethodName;
            }
            else if (vars.find(ident->name + actualmethodName) != vars.end()) {
                // FIX DESHABILITADO TEMPORALMENTE
                // if(vars[ident->name].isRef ){
                if(args[paramPos] == "REF"){
                    argType = "REF";
                    llvmType = "i32* %";
                    r1.place = ident->name+ actualmethodName;
                }else{
                    argType = "VAR";
                    llvmType = "i32 %";
                    std::cout << "32B: " << ident->name << std::endl;
                }
                
            
            }
            else {
                throw std::runtime_error("Variable no declarada: " + ident->name);
            }
        }
        // Caso 2: Acceso a array (arr[5])
        else if (dynamic_cast<ArrayVariable*>(root->expression)) {
            argType = "VAR"; // Tratamos elementos de array como valores
            std::string llvmType = "i32 %";
        }

        // Registrar tipo en args
          r.place += llvmType + r1.place;
          r.args.push_back(argType);
        if(argType != args[paramPos]){
            throw std::runtime_error("Error as CallStmt: Argument type mismatch." + argType + " " + args[paramPos]);
        }
        paramPos++;
        r.argsNum = paramPos;
        std::cout << paramPos << std::endl;

        // Procesar parámetros restantes
        if (root->call_param_rest) {
            CodegenResult r2 = exprCompile(root->call_param_rest, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
            r.code += r2.code;
            r.place += (r.place.empty() ? "" : ", ") + r2.place;
            r.argsNum += r2.argsNum;

            for (int i = 0; i < r2.args.size(); i++) {
                r.args.push_back(r2.args[i]);
            }
        }
    }

   
    return r;
}
#line 3313 "ExprAst.cpp"

static CodegenResult exprCompile_30__(CallParamRest *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1573 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    CodegenResult r;

    if (root->expression) {
        CodegenResult r1 = exprCompile(root->expression, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
        r.code = r1.code;
       

        // Misma lógica de inferencia que en CallParamList
        std::string argType = "VAR";
        std::string llvmType = "i32 %";
        
        if (auto* ident = dynamic_cast<Identifier*>(root->expression)) {
            if (arrayvarTable.find(ident->name + actualmethodName) != arrayvarTable.end()) {
                argType = "ARRAY";
                llvmType = "i32* %";
                r1.place = ident->name + actualmethodName;
            }
            else if (vars.find(ident->name+ actualmethodName) != vars.end()) {
                // FIX DESHABILITADO TEMPORALMENTE
                // argType = vars[ident->name].isRef ? "REF" : "VAR";
                // if(vars[ident->name].isRef ){
                if(args[paramPos] == "REF"){
                    argType = "REF";
                    llvmType = "i32* %";
                    r1.place = ident->name+ actualmethodName;
                }else{
                    argType = "VAR";
                    llvmType = "i32 %";
                }
            
            }
            else {
                throw std::runtime_error("Variable no declarada: " + ident->name);
            }
        }
        else if (dynamic_cast<ArrayVariable*>(root->expression)) {
            argType = "VAR";
            llvmType = "i32 %";
        }

        
        r.place += llvmType + r1.place;
        r.args.push_back(argType);
        // args.push_back(argType);
        if(argType != args[paramPos]){
            throw std::runtime_error("Error as CallStmt: Argument type mismatch." + argType + " " + args[paramPos]);
        }

     
        paramPos++;
        r.argsNum = paramPos;
        // paramPos ++;
        std::cout <<paramPos << std::endl;

        if (root->call_param_rest) {
            CodegenResult r2 = exprCompile(root->call_param_rest, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
            r.code += r2.code;
            r.place += (r.place.empty() ? "" : ", ") + r2.place;

            for(int i = 0; i < r2.args.size(); i++){
                r.args.push_back(r2.args[i]);
            }
        }
    }
  
    return r;
}
#line 3385 "ExprAst.cpp"

static CodegenResult exprCompile_31__(PrintParam *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1657 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *expression;
    // string_t string_literal;
    std::ostringstream os;

    CodegenResult r;

    if(root->expression){ //es expresion
        CodegenResult r1 = exprCompile(root->expression, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
        os << r1.code << "\n";
        os << "call i32(i8*, ...) @printf(i8* @.fmt, i32 %"<< r1.place <<")";



    }else{ //Es un literal

        auto it = textsTable.find(root->string_literal);

        if(it == textsTable.end()){

            std::string tagt = newFmts();

            textsTable.insert({root->string_literal, tagt});


            os << "call i32(i8*, ...) @printf(i8* "<< tagt <<")";

            // "call i32(i8*, ...) @printf(i8* @.fmt)"
        }else{
            // it.second
            //FIX: FALTA IMPLEMENTAR
        }

   
    }

    r.code = os.str();
    return r;



// Print Literal

// std::ostringstream os;

// auto it - texts.find(root->literal);

// if(it == texts.end()) {
//    os << "call i32 (i8*, ...)* @printf(i8* )";
// } else {
    



}
#line 3444 "ExprAst.cpp"

static CodegenResult exprCompile_32__(EqualBoolean *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1776 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *left;
    // Node *right;
    std::ostringstream os;

    CodegenResult r;
    CodegenResult r1 = exprCompile(root->left, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    CodegenResult r2 = exprCompile(root->right, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);

    os << r1.code << "\n";
    os << r2.code << "\n";

    r.place = newVariable();

    os << "%" << r.place << "_1 = icmp eq i32 %" << r1.place << ", %" << r2.place << "\n";
    os << "%" << r.place << " = zext i1 %" << r.place << "_1 to i32"<< "\n";

    r.code = os.str();
    return r;
}
#line 3468 "ExprAst.cpp"

static CodegenResult exprCompile_33__(NEqualBoolean *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1797 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *left;
    // Node *right;
    std::ostringstream os;

    CodegenResult r;
    CodegenResult r1 = exprCompile(root->left, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    CodegenResult r2 = exprCompile(root->right, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);

    os << r1.code << "\n";
    os << r2.code << "\n";

    r.place = newVariable();

    os << "%" << r.place << "_1 = icmp ne i32 %" << r1.place << ", %" << r2.place << "\n";
    os << "%" << r.place << " = zext i1 %" << r.place << "_1 to i32"<< "\n";

    r.code = os.str();
    return r;
}
#line 3492 "ExprAst.cpp"

static CodegenResult exprCompile_34__(Less_ThanBoolean *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1818 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *left;
    // Node *right;
    std::ostringstream os;

    CodegenResult r;
    CodegenResult r1 = exprCompile(root->left, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    CodegenResult r2 = exprCompile(root->right, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);

    os << r1.code << "\n";
    os << r2.code << "\n";

    r.place = newVariable();

    os << "%" << r.place << "_1 = icmp slt i32 %" << r1.place << ", %" << r2.place << "\n";
    os << "%" << r.place << " = zext i1 %" << r.place << "_1 to i32"<< "\n";

    r.code = os.str();
    return r;
}
#line 3516 "ExprAst.cpp"

static CodegenResult exprCompile_35__(Greater_ThanBoolean *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1839 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *left;
    // Node *right;
    std::ostringstream os;

    CodegenResult r;
    CodegenResult r1 = exprCompile(root->left, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    CodegenResult r2 = exprCompile(root->right, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);

    os << r1.code << "\n";
    os << r2.code << "\n";

    r.place = newVariable();

    os << "%" << r.place << "_1 = icmp sgt i32 %" << r1.place << ", %" << r2.place << "\n";
    os << "%" << r.place << " = zext i1 %" << r.place << "_1 to i32"<< "\n";

    r.code = os.str();
    return r;
}
#line 3540 "ExprAst.cpp"

static CodegenResult exprCompile_36__(LessEqualBoolean *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1860 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *left;
    // Node *right;
    std::ostringstream os;

    CodegenResult r;
    CodegenResult r1 = exprCompile(root->left, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    CodegenResult r2 = exprCompile(root->right, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);

    os << r1.code << "\n";
    os << r2.code << "\n";

    r.place = newVariable();

    os << "%" << r.place << "_1 = icmp sle i32 %" << r1.place << ", %" << r2.place << "\n";
    os << "%" << r.place << " = zext i1 %" << r.place << "_1 to i32"<< "\n";

    r.code = os.str();
    return r;
}
#line 3564 "ExprAst.cpp"

static CodegenResult exprCompile_37__(GreaterEqualBoolean *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1881 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *left;
    // Node *right;
    std::ostringstream os;

    CodegenResult r;
    CodegenResult r1 = exprCompile(root->left, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    CodegenResult r2 = exprCompile(root->right, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);

    os << r1.code << "\n";
    os << r2.code << "\n";

    r.place = newVariable();

    os << "%" << r.place << "_1 = icmp sge i32 %" << r1.place << ", %" << r2.place << "\n";
    os << "%" << r.place << " = zext i1 %" << r.place << "_1 to i32"<< "\n";

    r.code = os.str();
    return r;
}
#line 3588 "ExprAst.cpp"

static CodegenResult exprCompile_38__(OrBoolean *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1901 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
     // Node *left;
    // Node *right;
    std::ostringstream os;
    CodegenResult r;

    // Compilar subexpresiones izquierda y derecha
    CodegenResult r1 = exprCompile(root->left, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    CodegenResult r2 = exprCompile(root->right, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    
    os << r1.code << "\n";
    os << r2.code << "\n";

   
    r.place = newVariable();
    os << "%" << r.place << " = or i32 %" << r1.place << ", %" << r2.place << "\n";

    r.code = os.str();
    return r;
}
#line 3612 "ExprAst.cpp"

static CodegenResult exprCompile_39__(AndBoolean *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1922 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *left;
    // Node *right;
    std::ostringstream os;
    CodegenResult r;


    CodegenResult r1 = exprCompile(root->left, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    CodegenResult r2 = exprCompile(root->right, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    
    os << r1.code << "\n";
    os << r2.code << "\n";

   
    r.place = newVariable();
    os << "%" << r.place << " = and i32 %" << r1.place << ", %" << r2.place << "\n";

    r.code = os.str();
    return r;
}
#line 3636 "ExprAst.cpp"

static CodegenResult exprCompile_40__(SumExpr *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1960 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *left;
    // Node *right;
    std::ostringstream os;
    
    CodegenResult r1 = exprCompile(root->left, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    CodegenResult r2 = exprCompile(root->right, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    CodegenResult r;
    r.place = newVariable();

    os << r1.code << "\n";
    os << r2.code << "\n";


    os << "%" << r.place << " = add i32 %" << r1.place <<", %"<< r2.place;
    r.code = os.str();
    return r;
}
#line 3658 "ExprAst.cpp"

static CodegenResult exprCompile_41__(SubExpr *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1979 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *left;
    // Node *right;
    std::ostringstream os;
    
    CodegenResult r1 = exprCompile(root->left, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    CodegenResult r2 = exprCompile(root->right, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    CodegenResult r;
    r.place = newVariable();

    os << r1.code << "\n";
    os << r2.code << "\n";



    os << "%" << r.place << " = sub i32 %" << r1.place <<", %"<< r2.place << "\n";
    r.code = os.str();
    return r;
}
#line 3681 "ExprAst.cpp"

static CodegenResult exprCompile_42__(MulExpr *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1999 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *left;
    // Node *right;
    
     std::ostringstream os;
    
    CodegenResult r1 = exprCompile(root->left, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    CodegenResult r2 = exprCompile(root->right, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    CodegenResult r;
    r.place = newVariable();

    os << r1.code << "\n";
    os << r2.code << "\n";



    os << "%" << r.place << " = mul i32 %" << r1.place <<", %"<< r2.place << "\n";
    r.code = os.str();
    return r;
}
#line 3705 "ExprAst.cpp"

static CodegenResult exprCompile_43__(DivExpr *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 2020 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *left;
    // Node *right;
    std::ostringstream os;
    
    CodegenResult r1 = exprCompile(root->left, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    CodegenResult r2 = exprCompile(root->right, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    CodegenResult r;
    r.place = newVariable();

    os << r1.code << "\n";
    os << r2.code << "\n";



    os << "%" << r.place << " = div i32 %" << r1.place <<", %"<< r2.place << "\n";
    r.code = os.str();
    return r;
}
#line 3728 "ExprAst.cpp"

static CodegenResult exprCompile_44__(ModExpr *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 2040 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *left;
    // Node *right;
    std::ostringstream os;
    
    CodegenResult r1 = exprCompile(root->left, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    CodegenResult r2 = exprCompile(root->right, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    CodegenResult r;
    r.place = newVariable();

    os << r1.code << "\n";
    os << r2.code << "\n";

    os << "%" << r.place << " = srem i32 %" << r1.place <<", %"<< r2.place << "\n";
    r.code = os.str();
    return r;
}
#line 3749 "ExprAst.cpp"

static CodegenResult exprCompile_45__(UnaryNotBoolean *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 1943 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *expr;
    std::ostringstream os;
    CodegenResult r;


    CodegenResult r1 = exprCompile(root->expr, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    os << r1.code << "\n";

  
    r.place = newVariable();
    os << "%" << r.place << " = xor i32 %" << r1.place << ", 1\n";

    r.code = os.str();
    return r;
}
#line 3769 "ExprAst.cpp"

static CodegenResult exprCompile_46__(UnaryAddExpr *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 2058 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
        // Node *expr;
    std::ostringstream os;
    CodegenResult r;


    CodegenResult exprResult = exprCompile(root->expr, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
    
    os << exprResult.code;
    r.place = exprResult.place;

    r.code = os.str();
    return r;
}
#line 3787 "ExprAst.cpp"

static CodegenResult exprCompile_47__(UnarySubExpr *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 2073 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // Node *expr;

        std::ostringstream os;
        CodegenResult r;
    
      
        CodegenResult exprResult = exprCompile(root->expr, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
        os << exprResult.code << "\n";
    

        r.place = newVariable();
        os << "%" << r.place << " = sub i32 0, %" << exprResult.place << "\n";
    
        r.code = os.str();
        return r;
}
#line 3808 "ExprAst.cpp"

static CodegenResult exprCompile_48__(Number *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 2091 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // int value;
    std::ostringstream os;
    // os << "Number(" << root->value << ")";

    CodegenResult r;

    r.place = newVariable();
    // r.code = std::to_string(root->value);
    os << "%" << r.place << " = add i32 " << root->value << ", 0" << "\n";
    // r.place = std::to_string(root->value);
    // r.code = "%" + r.place + " = i32 " + std::to_string(root->value);
    r.code = os.str();
    return r;
}
#line 3827 "ExprAst.cpp"

static CodegenResult exprCompile_49__(Identifier *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 2107 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // string_t name;
    std::ostringstream os;
    CodegenResult r; 
    r.place = newVariable();

    auto it = vars.find(root->name + actualmethodName);
    auto it_global = vars.find(root->name);


    auto itarray = arrayvarTable.find(root->name + actualmethodName);
    auto itarray_global = arrayvarTable.find(root->name);

    std::string arrayKey = root->name + actualmethodName;
    auto itArray = arrayvarTable.find(arrayKey);
    bool isArray = false;

    // 1. Verificar si es un array
    if (itArray != arrayvarTable.end()) {
        isArray = true;
    } else {
        // Buscar versión global del array
        itArray = arrayvarTable.find(root->name);
        if (itArray != arrayvarTable.end()) {
            isArray = true;
        }else{
            std::cout << "NO Se encontro el array " << root->name << std::endl;
        }
    }

    if (isArray) {
        // Manejar acceso a array
        if (itArray->second.isArgument) {
           
            r.place = root->name + actualmethodName; // Acceso directo para argumentos
        } else {
            std::runtime_error("Error: Array variable '" + root->name + "' cannot be accessed directly.");
        }
        return r;
    }

   
    if ( it_global != vars.end() ){
        if (it_global->second.value.has_value()) {
            //FIX HACE OTRO QUE CONSIDERE LOS REFS
            // if( it->second.methodIdentifier.empty()){//es global
            //     os << "%" << r.place << " = load i32, i32* @" << root->name << ", align 4";
            // }else{
            //     os << "%" << r.place << " = load i32, i32* %" << root->name << ", align 4";
            // }

            if( it_global->second.methodIdentifier.empty()){//es global
                
                os << "%" << r.place << " = load i32, i32* @" << root->name  << ", align 4";
            }else{
                os << "%" << r.place << " = load i32, i32* %" << root->name  << ", align 4";
            }
           
        } else {
            // FIX: ERROR TEMPORALY DISABLED
            throw std::runtime_error("Error: Variable '" + root->name+ actualmethodName + "' has no value.");
        }

    }else{

    if (it == vars.end()) { 
        // La variable no existe en la tabla de símbolos
    //FIX: VOLVER A ASIGNAR LOS EXCEPTIONS
         throw std::runtime_error("Error: Variable (ID)'" + root->name + actualmethodName+ "' not declared.");
    }

    if (it->second.isArgument) {
        // Es un argumento del método actual, se debe acceder de manera distinta
        if(it->second.isRef){
            os << "%" << r.place << " = load i32, i32* %" << root->name << actualmethodName << ", align 4";
        }else{
            // os << "%" << r.place << " = add i32 %" << root->name << ", 0";
            r.place = root->name + actualmethodName;
        }
        r.code = os.str();
        
        return r;
    } 

    if (it == vars.end()) { 
        // La variable no existe en la tabla de símbolos
    //FIX: VOLVER A ASIGNAR LOS EXCEPTIONS
         throw std::runtime_error("Error: Variable (ID) 2'" + root->name + "' not declared.");
    } else if (!it->second.methodIdentifier.empty() && it->second.methodIdentifier != actualmethodName) {
        // Existe pero no pertenece al método actual ni es global
         throw std::runtime_error("Error: Variable '" + root->name + "' is not accessible in the current scope.");
    } else {
        // Existe y es alcanzable
        
        if (it->second.value.has_value()) {
            //FIX HACE OTRO QUE CONSIDERE LOS REFS
            // if( it->second.methodIdentifier.empty()){//es global
            //     os << "%" << r.place << " = load i32, i32* @" << root->name << ", align 4";
            // }else{
            //     os << "%" << r.place << " = load i32, i32* %" << root->name << ", align 4";
            // }

            if( it->second.methodIdentifier.empty()){//es global
                
                os << "%" << r.place << " = load i32, i32* @" << root->name << actualmethodName << ", align 4";
            }else{
                os << "%" << r.place << " = load i32, i32* %" << root->name << actualmethodName << ", align 4";
            }
           
        } else {
     
            throw std::runtime_error("Error: Variable '" + root->name+ actualmethodName + "' has no value.");
        }


    }
}
    // os << "%" << r.place << " = load i32, i32* %" << root->name << ", align 4";
    // vars.insert({ r.place , variables{"", std::nullopt, nullptr}});
    
    r.code = os.str();
    r.place =  r.place;
    return r;
}
#line 3955 "ExprAst.cpp"

static CodegenResult exprCompile_50__(ArrayVariable *root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
#line 2232 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    // string_t name;
    // Node *indexExpr;    array access es el expr que me retorna el indice
    // x[3]

    // %node ArrayAccess Node = {
    //     Node *expression;
    // }

//     ; Escribir un valor en el índice 2
// %idx = getelementptr [10 x i32], [10 x i32]* %array, i32 0, i32 2
// store i32 5, i32* %idx, align 4       ; Guardar el valor 5 en la posición 2

// ; Leer el valor en el índice 2
// %val = load i32, i32* %idx, align 4   ; Cargar el valor almacenado en %idx

    std::ostringstream os;
    CodegenResult r;

    auto it = arrayvarTable.find( root->name+ actualmethodName);
    auto it_global = arrayvarTable.find( root->name);

    if(it_global != arrayvarTable.end()){
        os<< ";ArrayVariable -----------" << "\n"; //COMMENT
        // Indice de Arreglo
        CodegenResult r1 = exprCompile(root->indexExpr, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
        os << r1.code << "\n";
        r.place = newVariable();
        os << "%"<< r.place <<" = getelementptr ["<< it_global->second.values.size()<<" x i32], ["<< it_global->second.values.size()<<" x i32]* @"<< root->name <<", i32 0, i32 %"<< r1.place << "\n";
        std::string index = r.place ; 
        r.place = newVariable();
        os << "%" << r.place << " = load i32, i32* %" << index << ", align 4";
        os<< "\n;FIN - ArrayVariable --------" << "\n"; //COMMENT
        r.code = os.str();
    }else{
    if (it == arrayvarTable.end()){
        throw std::runtime_error("Error: Array '" + root->name+ actualmethodName + "' not declared.");
    }else{

    os<< ";ArrayVariable -----------" << "\n"; //COMMENT
     // Indice de Arreglo
     CodegenResult r1 = exprCompile(root->indexExpr, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
     os << r1.code << "\n";
     r.place = newVariable();
     os << "%"<< r.place <<" = getelementptr ["<< it->second.values.size()<<" x i32], ["<< it->second.values.size()<<" x i32]* %"<< root->name << actualmethodName<<", i32 0, i32 %"<< r1.place << "\n";
     std::string index = r.place ; 
     r.place = newVariable();
     os << "%" << r.place << " = load i32, i32* %" << index << ", align 4";
     os<< "\n;FIN - ArrayVariable --------" << "\n"; //COMMENT
     r.code = os.str();
    }
    }
    return r;
}
#line 4013 "ExprAst.cpp"

CodegenResult exprCompile(Node * root__, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos)
{
	switch(root__->getKind())
	{
		case Program_kind:
		{
			return exprCompile_1__((Program *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case VarMethodDeclList_kind:
		{
			return exprCompile_2__((VarMethodDeclList *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case VariableDeclList_kind:
		{
			return exprCompile_3__((VariableDeclList *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case VariableDecl_kind:
		{
			return exprCompile_4__((VariableDecl *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case VariableDecl_Body_kind:
		{
			return exprCompile_5__((VariableDecl_Body *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case IdentList_kind:
		{
			return exprCompile_6__((IdentList *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case Type_kind:
		{
			return exprCompile_7__((Type *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case ArrayOptional_kind:
		{
			return exprCompile_8__((ArrayOptional *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case MethodDeclList_kind:
		{
			return exprCompile_9__((MethodDeclList *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case MethodDecl_kind:
		{
			return exprCompile_10__((MethodDecl *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case MethodDecl_Body_kind:
		{
			return exprCompile_11__((MethodDecl_Body *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case MethodType_kind:
		{
			return exprCompile_12__((MethodType *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case OptParamDeclList_kind:
		{
			return exprCompile_13__((OptParamDeclList *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case ParamList_kind:
		{
			return exprCompile_14__((ParamList *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case ParamDecl_kind:
		{
			return exprCompile_15__((ParamDecl *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case RefOptional_kind:
		{
			return exprCompile_16__((RefOptional *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case StmtList_kind:
		{
			return exprCompile_17__((StmtList *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case AssignStmt_kind:
		{
			return exprCompile_18__((AssignStmt *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case ReturnStmt_kind:
		{
			return exprCompile_19__((ReturnStmt *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case IfStmt_kind:
		{
			return exprCompile_20__((IfStmt *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case WhileStmt_kind:
		{
			return exprCompile_21__((WhileStmt *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case CallStmt_kind:
		{
			return exprCompile_22__((CallStmt *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case PrintStmt_kind:
		{
			return exprCompile_23__((PrintStmt *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case ReadStmt_kind:
		{
			return exprCompile_24__((ReadStmt *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case FunctionCall_kind:
		{
			return exprCompile_25__((FunctionCall *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case ArrayAccess_kind:
		{
			return exprCompile_26__((ArrayAccess *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case ElseOptional_kind:
		{
			return exprCompile_27__((ElseOptional *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case Block_kind:
		{
			return exprCompile_28__((Block *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case CallParamList_kind:
		{
			return exprCompile_29__((CallParamList *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case CallParamRest_kind:
		{
			return exprCompile_30__((CallParamRest *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case PrintParam_kind:
		{
			return exprCompile_31__((PrintParam *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case EqualBoolean_kind:
		{
			return exprCompile_32__((EqualBoolean *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case NEqualBoolean_kind:
		{
			return exprCompile_33__((NEqualBoolean *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case Less_ThanBoolean_kind:
		{
			return exprCompile_34__((Less_ThanBoolean *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case Greater_ThanBoolean_kind:
		{
			return exprCompile_35__((Greater_ThanBoolean *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case LessEqualBoolean_kind:
		{
			return exprCompile_36__((LessEqualBoolean *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case GreaterEqualBoolean_kind:
		{
			return exprCompile_37__((GreaterEqualBoolean *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case OrBoolean_kind:
		{
			return exprCompile_38__((OrBoolean *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case AndBoolean_kind:
		{
			return exprCompile_39__((AndBoolean *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case SumExpr_kind:
		{
			return exprCompile_40__((SumExpr *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case SubExpr_kind:
		{
			return exprCompile_41__((SubExpr *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case MulExpr_kind:
		{
			return exprCompile_42__((MulExpr *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case DivExpr_kind:
		{
			return exprCompile_43__((DivExpr *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case ModExpr_kind:
		{
			return exprCompile_44__((ModExpr *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case UnaryNotBoolean_kind:
		{
			return exprCompile_45__((UnaryNotBoolean *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case UnaryAddExpr_kind:
		{
			return exprCompile_46__((UnaryAddExpr *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case UnarySubExpr_kind:
		{
			return exprCompile_47__((UnarySubExpr *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case Number_kind:
		{
			return exprCompile_48__((Number *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case Identifier_kind:
		{
			return exprCompile_49__((Identifier *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		case ArrayVariable_kind:
		{
			return exprCompile_50__((ArrayVariable *)root__, vars, methodTable, args, arrayvarTable, actualmethodName, textsTable, paramPos);
		}
		break;

		default: break;
	}
	return (CodegenResult{} );
}

}
