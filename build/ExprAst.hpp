/* ExprAst.hpp.  Generated automatically by treecc */
#ifndef __yy_ExprAst_hpp
#define __yy_ExprAst_hpp
#line 5 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"

    #include <memory> 
    #include <string>
    #include <iostream>
    #include <sstream>
    #include <unordered_map>
    #include <vector>
    #include <optional>
    
    using string_t = std::string;
    struct variables{
        std::string methodIdentifier;
        std::optional<int>  value;
        variables* ref = nullptr;
        bool isArgument = false;
        bool isRef = false;
    };
    
    using symbol_table = std::unordered_map<std::string, variables>;
    using arguments = std::vector<std::string>;
    

    struct arrayVariables{
        std::string methodIdentifier;
        std::vector<std::optional<int>> values;
        variables* ref = nullptr;
        bool isArgument = false;
       
    };

    using ArrayVariables_Table = std::unordered_map<
    std::string, 
    arrayVariables // Mantener consistencia
    >;

    using Texts_Table = std::unordered_map<std::string, std::string>;


    namespace Ast {
        class Node;
    }
    

    struct methodVariable{
        std::string methodName;
        std::string Type;
        std::vector<std::string> params;
        bool hasReturnStmt = false;
    };

    // Luego Method_Table que lo referencia
    // using Method_Table = std::unordered_map<std::string, Ast::Node*>;
    using Method_Table = std::unordered_map<std::string, methodVariable>;

    struct CodegenResult{
        std::string code;
        std::string place;
        std::vector<std::string> args;
        int argsNum = 0;
    };

    
    

#line 70 "ExprAst.hpp"

#include <new>

namespace Ast
{

const int Node_kind = 1;
const int Program_kind = 2;
const int VarMethodDeclList_kind = 3;
const int VariableDeclList_kind = 4;
const int VariableDecl_kind = 5;
const int VariableDecl_Body_kind = 6;
const int IdentList_kind = 7;
const int Type_kind = 8;
const int ArrayOptional_kind = 9;
const int MethodDeclList_kind = 10;
const int MethodDecl_kind = 11;
const int MethodDecl_Body_kind = 12;
const int MethodType_kind = 13;
const int OptParamDeclList_kind = 14;
const int ParamList_kind = 15;
const int ParamDecl_kind = 16;
const int RefOptional_kind = 17;
const int StmtList_kind = 18;
const int Stmt_kind = 19;
const int ArrayAccess_kind = 21;
const int ElseOptional_kind = 24;
const int Block_kind = 25;
const int CallParamList_kind = 28;
const int CallParamRest_kind = 29;
const int PrintParam_kind = 31;
const int BinaryExpr_kind = 33;
const int UnaryExpr_kind = 34;
const int Expr_kind = 51;
const int ArrayVariable_kind = 54;
const int AssignStmt_kind = 20;
const int ReturnStmt_kind = 22;
const int IfStmt_kind = 23;
const int WhileStmt_kind = 26;
const int CallStmt_kind = 27;
const int PrintStmt_kind = 30;
const int ReadStmt_kind = 32;
const int FunctionCall_kind = 55;
const int EqualBoolean_kind = 35;
const int NEqualBoolean_kind = 36;
const int Less_ThanBoolean_kind = 37;
const int Greater_ThanBoolean_kind = 38;
const int LessEqualBoolean_kind = 39;
const int GreaterEqualBoolean_kind = 40;
const int OrBoolean_kind = 41;
const int AndBoolean_kind = 42;
const int SumExpr_kind = 44;
const int SubExpr_kind = 45;
const int MulExpr_kind = 46;
const int DivExpr_kind = 47;
const int ModExpr_kind = 48;
const int UnaryNotBoolean_kind = 43;
const int UnaryAddExpr_kind = 49;
const int UnarySubExpr_kind = 50;
const int Number_kind = 52;
const int Identifier_kind = 53;

class Node;
class Program;
class VarMethodDeclList;
class VariableDeclList;
class VariableDecl;
class VariableDecl_Body;
class IdentList;
class Type;
class ArrayOptional;
class MethodDeclList;
class MethodDecl;
class MethodDecl_Body;
class MethodType;
class OptParamDeclList;
class ParamList;
class ParamDecl;
class RefOptional;
class StmtList;
class Stmt;
class ArrayAccess;
class ElseOptional;
class Block;
class CallParamList;
class CallParamRest;
class PrintParam;
class BinaryExpr;
class UnaryExpr;
class Expr;
class ArrayVariable;
class AssignStmt;
class ReturnStmt;
class IfStmt;
class WhileStmt;
class CallStmt;
class PrintStmt;
class ReadStmt;
class FunctionCall;
class EqualBoolean;
class NEqualBoolean;
class Less_ThanBoolean;
class Greater_ThanBoolean;
class LessEqualBoolean;
class GreaterEqualBoolean;
class OrBoolean;
class AndBoolean;
class SumExpr;
class SubExpr;
class MulExpr;
class DivExpr;
class ModExpr;
class UnaryNotBoolean;
class UnaryAddExpr;
class UnarySubExpr;
class Number;
class Identifier;

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
#line 202 "ExprAst.hpp"
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

	Program(string_t class_name, Node * varmethod_decls, Node * method_decls);

public:

	string_t class_name;
	Node * varmethod_decls;
	Node * method_decls;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Program();

};

class VarMethodDeclList : public Node
{
public:

	VarMethodDeclList(Node * first_decl, Node * rest_decls);

public:

	Node * first_decl;
	Node * rest_decls;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~VarMethodDeclList();

};

class VariableDeclList : public Node
{
public:

	VariableDeclList(Node * first_decl, Node * rest_decls);

public:

	Node * first_decl;
	Node * rest_decls;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~VariableDeclList();

};

class VariableDecl : public Node
{
public:

	VariableDecl(Node * type, string_t identifier, Node * variableDecl_Body);

public:

	Node * type;
	string_t identifier;
	Node * variableDecl_Body;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~VariableDecl();

};

class VariableDecl_Body : public Node
{
public:

	VariableDecl_Body(Node * ident_list);

public:

	Node * ident_list;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~VariableDecl_Body();

};

class IdentList : public Node
{
public:

	IdentList(string_t identifier, Node * IdentListParam);

public:

	string_t identifier;
	Node * IdentListParam;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IdentList();

};

class Type : public Node
{
public:

	Type(string_t type_name, Node * array_optional);

public:

	string_t type_name;
	Node * array_optional;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Type();

};

class ArrayOptional : public Node
{
public:

	ArrayOptional(int size);

public:

	int size;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ArrayOptional();

};

class MethodDeclList : public Node
{
public:

	MethodDeclList(Node * first_decl, Node * rest_decls);

public:

	Node * first_decl;
	Node * rest_decls;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MethodDeclList();

};

class MethodDecl : public Node
{
public:

	MethodDecl(Node * method_type, string_t identifier, Node * MethodDecl_Body);

public:

	Node * method_type;
	string_t identifier;
	Node * MethodDecl_Body;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MethodDecl();

};

class MethodDecl_Body : public Node
{
public:

	MethodDecl_Body(Node * opt_param_decl_list, Node * variable_decls, Node * stmt_list);

public:

	Node * opt_param_decl_list;
	Node * variable_decls;
	Node * stmt_list;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MethodDecl_Body();

};

class MethodType : public Node
{
public:

	MethodType(string_t type);

public:

	string_t type;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MethodType();

};

class OptParamDeclList : public Node
{
public:

	OptParamDeclList(Node * first_param, Node * rest_params);

public:

	Node * first_param;
	Node * rest_params;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~OptParamDeclList();

};

class ParamList : public Node
{
public:

	ParamList(Node * first_param, Node * rest_params);

public:

	Node * first_param;
	Node * rest_params;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ParamList();

};

class ParamDecl : public Node
{
public:

	ParamDecl(Node * ref_optional, Node * type, string_t identifier);

public:

	Node * ref_optional;
	Node * type;
	string_t identifier;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ParamDecl();

};

class RefOptional : public Node
{
public:

	RefOptional(bool is_ref);

public:

	bool is_ref;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~RefOptional();

};

class StmtList : public Node
{
public:

	StmtList(Node * first_stmt, Node * rest_stmts);

public:

	Node * first_stmt;
	Node * rest_stmts;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~StmtList();

};

class Stmt : public Node
{
protected:

	Stmt();

public:

	virtual string_t toString() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Stmt();

};

class ArrayAccess : public Node
{
public:

	ArrayAccess(Node * expression);

public:

	Node * expression;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ArrayAccess();

};

class ElseOptional : public Node
{
public:

	ElseOptional(Node * block);

public:

	Node * block;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ElseOptional();

};

class Block : public Node
{
public:

	Block(Node * stmt_list);

public:

	Node * stmt_list;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Block();

};

class CallParamList : public Node
{
public:

	CallParamList(Node * expression, Node * call_param_rest);

public:

	Node * expression;
	Node * call_param_rest;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~CallParamList();

};

class CallParamRest : public Node
{
public:

	CallParamRest(Node * expression, Node * call_param_rest);

public:

	Node * expression;
	Node * call_param_rest;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~CallParamRest();

};

class PrintParam : public Node
{
public:

	PrintParam(Node * expression, string_t string_literal);

public:

	Node * expression;
	string_t string_literal;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~PrintParam();

};

class BinaryExpr : public Node
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

class UnaryExpr : public Node
{
protected:

	UnaryExpr(Node * expr);

public:

	Node * expr;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~UnaryExpr();

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

class ArrayVariable : public Node
{
public:

	ArrayVariable(string_t name, Node * indexExpr);

public:

	string_t name;
	Node * indexExpr;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ArrayVariable();

};

class AssignStmt : public Stmt
{
public:

	AssignStmt(string_t identifier, Node * array_access, Node * expression);

public:

	string_t identifier;
	Node * array_access;
	Node * expression;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AssignStmt();

};

class ReturnStmt : public Stmt
{
public:

	ReturnStmt(Node * expression);

public:

	Node * expression;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ReturnStmt();

};

class IfStmt : public Stmt
{
public:

	IfStmt(Node * expression, Node * block, Node * else_optional);

public:

	Node * expression;
	Node * block;
	Node * else_optional;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IfStmt();

};

class WhileStmt : public Stmt
{
public:

	WhileStmt(Node * expression, Node * block);

public:

	Node * expression;
	Node * block;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~WhileStmt();

};

class CallStmt : public Stmt
{
public:

	CallStmt(string_t identifier, Node * call_param_list);

public:

	string_t identifier;
	Node * call_param_list;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~CallStmt();

};

class PrintStmt : public Stmt
{
public:

	PrintStmt(Node * print_param);

public:

	Node * print_param;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~PrintStmt();

};

class ReadStmt : public Stmt
{
public:

	ReadStmt(string_t identifier);

public:

	string_t identifier;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ReadStmt();

};

class FunctionCall : public Stmt
{
public:

	FunctionCall(string_t identifier, Node * call_param_list);

public:

	string_t identifier;
	Node * call_param_list;

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FunctionCall();

};

class EqualBoolean : public BinaryExpr
{
public:

	EqualBoolean(Node * left, Node * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~EqualBoolean();

};

class NEqualBoolean : public BinaryExpr
{
public:

	NEqualBoolean(Node * left, Node * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NEqualBoolean();

};

class Less_ThanBoolean : public BinaryExpr
{
public:

	Less_ThanBoolean(Node * left, Node * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Less_ThanBoolean();

};

class Greater_ThanBoolean : public BinaryExpr
{
public:

	Greater_ThanBoolean(Node * left, Node * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Greater_ThanBoolean();

};

class LessEqualBoolean : public BinaryExpr
{
public:

	LessEqualBoolean(Node * left, Node * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LessEqualBoolean();

};

class GreaterEqualBoolean : public BinaryExpr
{
public:

	GreaterEqualBoolean(Node * left, Node * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~GreaterEqualBoolean();

};

class OrBoolean : public BinaryExpr
{
public:

	OrBoolean(Node * left, Node * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~OrBoolean();

};

class AndBoolean : public BinaryExpr
{
public:

	AndBoolean(Node * left, Node * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AndBoolean();

};

class SumExpr : public BinaryExpr
{
public:

	SumExpr(Node * left, Node * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~SumExpr();

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

class ModExpr : public BinaryExpr
{
public:

	ModExpr(Node * left, Node * right);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ModExpr();

};

class UnaryNotBoolean : public UnaryExpr
{
public:

	UnaryNotBoolean(Node * expr);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~UnaryNotBoolean();

};

class UnaryAddExpr : public UnaryExpr
{
public:

	UnaryAddExpr(Node * expr);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~UnaryAddExpr();

};

class UnarySubExpr : public UnaryExpr
{
public:

	UnarySubExpr(Node * expr);

public:

	virtual string_t toString();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~UnarySubExpr();

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


CodegenResult exprCompile(Node * root, symbol_table & vars, Method_Table & methodTable, arguments & args, ArrayVariables_Table & arrayvarTable, string_t actualmethodName, Texts_Table & textsTable, int paramPos);

}
#line 106 "/home/ricardo/Compi2/RE-flex-master/RE-flex-master/SimpleLexer/ExprAst.tc"


 
    using NodeVector = std::vector<Ast::Node*>;

#line 1403 "ExprAst.hpp"
#endif
