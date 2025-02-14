/* ExprAst.cpp.  Generated automatically by treecc */
#line 13 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"

    #include "ExprAst.hpp"
#line 6 "ExprAst.cpp"

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
#line 290 "ExprAst.cpp"
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

Program::Program(Node * lines)
	: Node()
{
	this->kind__ = Program_kind;
	this->lines = lines;
}

Program::~Program()
{
	// not used
}

string_t Program::toString()
#line 54 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "Program(" << lines->toString() << ")";
    return os.str();
}
#line 345 "ExprAst.cpp"

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

LineSeq::LineSeq(Node * first_line, Node * rest_lines)
	: Node()
{
	this->kind__ = LineSeq_kind;
	this->first_line = first_line;
	this->rest_lines = rest_lines;
}

LineSeq::~LineSeq()
{
	// not used
}

string_t LineSeq::toString()
#line 60 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "LineSeq(" << first_line->toString() << '\n';
    
    if(rest_lines){
        os << ", " << rest_lines->toString() << ")";
    }
    return os.str();
}
#line 384 "ExprAst.cpp"

int LineSeq::isA(int kind) const
{
	if(kind == LineSeq_kind)
		return 1;
	else
		return Node::isA(kind);
}

const char *LineSeq::getKindName() const
{
	return "LineSeq";
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
#line 70 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "Number(" << value << ")";
    return os.str();
}
#line 442 "ExprAst.cpp"

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
#line 76 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "Identifier(" << name << ")";
    return os.str();
}
#line 476 "ExprAst.cpp"

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

BinaryExpr::BinaryExpr(Node * left, Node * right)
	: Expr()
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
#line 82 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "BinaryExpr(" 
       << left->toString() 
       << ", " << right->toString() 
       << ")";
    return os.str();
}
#line 514 "ExprAst.cpp"

int BinaryExpr::isA(int kind) const
{
	if(kind == BinaryExpr_kind)
		return 1;
	else
		return Expr::isA(kind);
}

const char *BinaryExpr::getKindName() const
{
	return "BinaryExpr";
}

AddExpr::AddExpr(Node * left, Node * right)
	: BinaryExpr(left, right)
{
	this->kind__ = AddExpr_kind;
}

AddExpr::~AddExpr()
{
	// not used
}

string_t AddExpr::toString()
#line 91 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "AddExpr(" << left->toString() 
       << ", " << right->toString() 
       << ")";
    return os.str();
}
#line 549 "ExprAst.cpp"

int AddExpr::isA(int kind) const
{
	if(kind == AddExpr_kind)
		return 1;
	else
		return BinaryExpr::isA(kind);
}

const char *AddExpr::getKindName() const
{
	return "AddExpr";
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
#line 99 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "SubExpr(" << left->toString()
       << ", " << right->toString() 
       << ")";
    return os.str();
}
#line 584 "ExprAst.cpp"

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
#line 107 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "MulExpr(" << left->toString() 
       << ", " << right->toString() 
       << ")";
    return os.str();
}
#line 619 "ExprAst.cpp"

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
#line 115 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    std::ostringstream os;
    os << "DivExpr(" << left->toString() << ", " << right->toString() << ")";
    return os.str();
}
#line 652 "ExprAst.cpp"

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

static int eval_1__(Program *node, symbol_table & vars)
#line 123 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return eval(node->lines, vars);
}
#line 672 "ExprAst.cpp"

static int eval_2__(LineSeq *node, symbol_table & vars)
#line 127 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    int val1 = eval(node->first_line, vars);
    int val2 = 0;

    if(node->rest_lines){
        val2 = eval(node->rest_lines, vars);
    }

    return val1 + val2;
}
#line 686 "ExprAst.cpp"

static int eval_3__(Number *node, symbol_table & vars)
#line 146 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return node->value;
}
#line 693 "ExprAst.cpp"

static int eval_4__(Identifier *node, symbol_table & vars)
#line 138 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    auto it = vars.find(node->name);
    if(it == vars.end()){
        throw std::runtime_error("Variable not found");
    }
    return it->second;
}
#line 704 "ExprAst.cpp"

static int eval_5__(AddExpr *node, symbol_table & vars)
#line 150 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return eval(node->left, vars) + eval(node->right, vars);
}
#line 711 "ExprAst.cpp"

static int eval_6__(SubExpr *node, symbol_table & vars)
#line 154 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return eval(node->left, vars) - eval(node->right, vars);
}
#line 718 "ExprAst.cpp"

static int eval_7__(MulExpr *node, symbol_table & vars)
#line 158 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    return eval(node->left, vars) * eval(node->right, vars);
}
#line 725 "ExprAst.cpp"

static int eval_8__(DivExpr *node, symbol_table & vars)
#line 162 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"
{
    int val2 = eval(node->right, vars);
    if(val2 == 0){
        throw std::runtime_error("Division by zero");
    }else{
        return eval(node->left, vars) / val2;
    }

}
#line 738 "ExprAst.cpp"

int eval(Node * node__, symbol_table & vars)
{
	switch(node__->getKind())
	{
		case Program_kind:
		{
			return eval_1__((Program *)node__, vars);
		}
		break;

		case LineSeq_kind:
		{
			return eval_2__((LineSeq *)node__, vars);
		}
		break;

		case Number_kind:
		{
			return eval_3__((Number *)node__, vars);
		}
		break;

		case Identifier_kind:
		{
			return eval_4__((Identifier *)node__, vars);
		}
		break;

		case AddExpr_kind:
		{
			return eval_5__((AddExpr *)node__, vars);
		}
		break;

		case SubExpr_kind:
		{
			return eval_6__((SubExpr *)node__, vars);
		}
		break;

		case MulExpr_kind:
		{
			return eval_7__((MulExpr *)node__, vars);
		}
		break;

		case DivExpr_kind:
		{
			return eval_8__((DivExpr *)node__, vars);
		}
		break;

		default: break;
	}
	return (0);
}

}
