/* ExprAst.hpp.  Generated automatically by treecc */
#ifndef __yy_ExprAst_hpp
#define __yy_ExprAst_hpp
#line 4 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"

    #include <string>
    #include <iostream>
    #include <sstream>
    #include <unordered_map>
    using string_t = std::string;
    using symbol_table = std::unordered_map<std::string, int>;
#line 13 "ExprAst.hpp"

#include <new>

namespace Ast
{

const int Node_kind = 1;
const int Program_kind = 2;
const int LineSeq_kind = 3;
const int Expr_kind = 4;
const int Number_kind = 5;
const int Identifier_kind = 6;
const int BinaryExpr_kind = 7;
const int AddExpr_kind = 8;
const int SubExpr_kind = 9;
const int MulExpr_kind = 10;
const int DivExpr_kind = 11;

class Node;
class Program;
class LineSeq;
class Expr;
class Number;
class Identifier;
class BinaryExpr;
class AddExpr;
class SubExpr;
class MulExpr;
class DivExpr;

class YYNODESTATE
{
public:

	YYNODESTATE();
	virtual ~YYNODESTATE();

#line 1 "cpp_skel.h"
private:

	struct YYNODESTATE_block *blocks__;
	struct YYNODESTATE_push *push_stack__;
	int used__;
#line 57 "ExprAst.hpp"
private:

	static YYNODESTATE *state__;

public:

	static YYNODESTATE *getState()
		{
			if(state__) return state__;
			state__ = new YYNODESTATE();
			return state__;
		}

public:

	void *alloc(size_t);
	void dealloc(void *, size_t);
	int push();
	void pop();
	void clear();
	virtual void failed();
	virtual const char *currFilename() const;
	virtual long currLinenum() const;

};

class Node
{
protected:

	int kind__;
	const char *filename__;
	long linenum__;

public:

	int getKind() const { return kind__; }
	const char *getFilename() const { return filename__; }
	long getLinenum() const { return linenum__; }
	void setFilename(const char *filename) { filename__ = filename; }
	void setLinenum(long linenum) { linenum__ = linenum; }

	void *operator new(size_t);
	void operator delete(void *, size_t);

protected:

	Node();

public:

	virtual string_t toString() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Node();

};

class Program : public Node
{
public:

	Program(Node * lines);

public:

	Node * lines;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Program();

};

class LineSeq : public Node
{
public:

	LineSeq(Node * first_line, Node * rest_lines);

public:

	Node * first_line;
	Node * rest_lines;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LineSeq();

};

class Expr : public Node
{
protected:

	Expr();

public:

	virtual string_t toString() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Expr();

};

class Number : public Expr
{
public:

	Number(int value);

public:

	int value;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Number();

};

class Identifier : public Expr
{
public:

	Identifier(string_t name);

public:

	string_t name;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Identifier();

};

class BinaryExpr : public Expr
{
protected:

	BinaryExpr(Node * left, Node * right);

public:

	Node * left;
	Node * right;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BinaryExpr();

};

class AddExpr : public BinaryExpr
{
public:

	AddExpr(Node * left, Node * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AddExpr();

};

class SubExpr : public BinaryExpr
{
public:

	SubExpr(Node * left, Node * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~SubExpr();

};

class MulExpr : public BinaryExpr
{
public:

	MulExpr(Node * left, Node * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MulExpr();

};

class DivExpr : public BinaryExpr
{
public:

	DivExpr(Node * left, Node * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DivExpr();

};


int eval(Node * node, symbol_table & vars);

}
#endif
