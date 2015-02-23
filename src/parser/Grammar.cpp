#include "Grammar.h"

using namespace LexemeResources;
using namespace std;


//this is only used to move ahead to the next token
bool Grammar::match(){
	return _currentTokens.moveAhead();
}


void Grammar::error(string expectedTokenNames)
{
	//found
	Token next;
	_currentTokens.nextToken(next);

	string found(LexemeNames[(int)next.getType()]);
	int line = next.getLineNumber();
	int column = next.getColumnNumber();

	char buffer[200] = { 0 };
	sprintf(buffer, "ERROR - Expected %s found %s, at line %d and column %d!!", expectedTokenNames.c_str(), found.c_str(), line, column);

	_errString = string(buffer);
}


LexemeType Grammar::nextTokenType() const
{
	return _currentTokens.nextTokenType();
}

/*  Rule 99
Parses strings in the language generated by
<Factor> -> Integer|Float|String Literal|"True"|"False"|"not" <factor>|"(" <expression> ")"
			|<FunctionIdentifier> <OptionalActualParameterList> */
bool Grammar::factor()
{

	//switch (_lookAheadToken.getLexeme().getType())
	//{
	//	case Lexeme::
	//}

	return false;
}

/*  Rule 61
Parses strings in the language generated by
<ForStatement> -> "for" <ControlVariable> ":=" <InitialValue> <StepValue> <FinalValue> "do" <Statement> */
bool Grammar::forStatement()
{

	return false;
}

/*  Rule 94
Parses strings in the language generated by
<MultiplyingOperator> -> "*"|"/"|"div"|"mod"|"and"  */
bool Grammar::multiplyingOperator()
{

	return false;
}

/*  Rule 72
Parses strings in the language generated by
<ActualParameter> -> <OrdinalExpression> */
bool Grammar::actualParameter()
{

	return false;
}

/*  Rule 70
Parses strings in the language generated by
<ActualParameterTail> -> ","  <ActualParameter> <ActualParameterTail>
					  ->  E    */
bool Grammar::actualParameterTail()
{

	return false;
}

/*  Rule 88
Parses strings in the language generated by
<AddingOperator> -> "+"|"-"|"or"  */
bool Grammar::addingOperator()
{

	return false;
}

/*  Rule 54
Parses strings in the language generated by
<AssignmentStatement> ->  <VariableIdentifier> ":=" <Expression>
					  ->  <FunctionIdentifier> ":=" <Expression>       */
bool Grammar::assignmentStatement()
{

	return false;
}

/*  Rule 4
Parses strings in the language generated by
<Block> ->  <VariableDeclarationPart> <ProcedureAndFunctionDeclarationPart> <StatementPart>  */
bool Grammar::block()
{

	return false;
}

/*  Rule 111
Parses strings in the language generated by
<BooleanExpression> ->  <Expression> */
bool Grammar::booleanExpression()
{

	return false;
}

/*  Rule 30
Parses strings in the language generated by
<CompoundStatement> -> "begin" <StatementSequence> "end" */
bool Grammar::compoundStatement()
{

	return false;
}

/*  Rule 62
Parses strings in the language generated by
<ControlVariable> ->  <VariableIdentifier> */
bool Grammar::controlVariable()
{

	return false;
}

/*  Rule 44
Parses strings in the language generated by
<EmptyStatement> ->  E   */
bool Grammar::emptyStatement()
{

	return false;
}

/*  Rule 73
Parses strings in the language generated by
<Expression> ->  <SimpleExpression> [OptionalRelationalPart]  */
bool Grammar::expression()
{

	return false;
}

/*  Rule 92
Parses strings in the language generated by
<FactorTail> ->  <MultiplyingOperator> <Factor> <FactorTail> 
			 ->  E    */
bool Grammar::factorTail()
{

	return false;
}

/*  Rule 66
Parses strings in the language generated by
<FinalValue> ->  <OrdinalExpression> */
bool Grammar::finalValue()
{

	return false;
}

/*  Rule 25
Parses strings in the language generated by
<FormalParameterSection> ->  <ValueParameterSection> | <VariableParameterSection>  */
bool Grammar::formalParameterSection()
{

	return false;
}

/*  Rule 23
Parses strings in the language generated by
<FormalParameterSectionTail> ->  ";" <FormalParameterSection> <FormalParameterSectionTail>
							 ->  E	*/
bool Grammar::formalParameterSectionTail()
{

	return false;
}

/*  Rule 18
Parses strings in the language generated by
<FunctionDeclaration> -> <FunctionHeading> ";" <Block> ";" */
bool Grammar::functionDeclaration()
{

	return false;
}

/*  Rule 20
Parses strings in the language generated by
<FunctionHeading> ->  "function" <functionIdentifier> [OptionalFormalParameterList] ":" <Type> */
bool Grammar::functionHeading()
{

	return false;
}

/*  Rule 110
Parses strings in the language generated by
<FunctionIdentifier> ->  identifier */
bool Grammar::functionIdentifier()
{

	return false;
}

/*  Rule 113
Parses strings in the language generated by
<IdentifierList> -> identifier <IdentifierTail> */
bool Grammar::identifierList()
{

	return false;
}

/*  Rule 114
Parses strings in the language generated by
<IdentifierTail> -> "," identifier <IdentifierTail>
				 ->  E	*/
bool Grammar::identifierTail()
{

	return false;
}

/*  Rule 56
Parses strings in the language generated by
<IfStatement> -> "if" <BooleanExpression> "then" <Statement> [OptionalElsePart] */
bool Grammar::ifStatement()
{

	return false;
}

/*  Rule 63
Parses strings in the language generated by
<InitialValue> -> <OrdinalExpression> */
bool Grammar::initialValue()
{
	switch (nextTokenType())
	{
		// NEED CASE FOR "*"
	case MP_DIV:
	case MP_MOD:
	case MP_AND:
		//all of the above cases fall through to accept
		return match();

	default:
		//Everythng else fails
		error("Type");
	}
	//return false;
}

/*  Rule 68
Parses strings in the language generated by
<OptionalActualParameterList> -> "(" <ActualParameter> <ActualParameterTail> ")" 
							  ->  E		*/
bool Grammar::optionalActualParameterList()
{

	return false;
}

/*  Rule 57
Parses strings in the language generated by
<OptionalElsePart> -> "else" <Statement> 
				   ->  E	*/
bool Grammar::optionalElsePart()
{

	return false;
}

/*  Rule 21
Parses strings in the language generated by
<OptionalFormalParameterList> -> "(" <FormalParameterSection> <FormalParameterSectionTail> ")" 
							  ->  E		*/
bool Grammar::optionalFormalParameterList()
{

	return false;
}

/*  Rule 74
Parses strings in the language generated by
<OptionalRelationalPart> -> <RelationalOperator> <SimpleExpression>
						 ->  E    */
bool Grammar::optionalRelationalPart()
{

	return false;
}

/*  Rule 85
Parses strings in the language generated by
<OptionalSign> -> "+"|"-"| E   */
bool Grammar::optionalSign()
{

	return false;
}

/*  Rule 112
Parses strings in the language generated by
<OrdinalExpression> -> <Expression> */
bool Grammar::ordinalExpression()
{

	return false;
}

/*  Rule 14
Parses strings in the language generated by
<ProcedureAndFunctionDeclarationPart> -> <ProcedureDeclaration> <ProcedureAndFunctionDeclarationPart>
									  -> <FunctionDeclaration> <ProcedureAndFunctionDeclarationPart>  */
bool Grammar::procedureAndFunctionDeclarationPart()
{
	switch (nextTokenType())
	{
	case MP_PROCEDURE:
		procedureDeclaration();
		return procedureAndFunctionDeclarationPart();
	case MP_FUNCTION:
		functionDeclaration();
		return procedureAndFunctionDeclarationPart();
	default:
		error("Error");
	}

	return false;
}

/*  Rule 17
Parses strings in the language generated by
<ProcedureDeclaration> -> <ProcedureHeading> ";" <Block> ";" */
bool Grammar::procedureDeclaration()
{
	if (!procedureHeading())
		return false;
	else if (nextTokenType() == MP_SCOLON)
	{
		block();
		MP_SCOLON;
		return match();
	}
	else error("Error");
	return false;
}

/*  Rule 19
Parses strings in the language generated by
<ProcedureHeading> -> "procedure" <procedureIdentifier> [OptionalFormalParameterList] */
bool Grammar::procedureHeading()
{

	return false;
}

/*  Rule 109
Parses strings in the language generated by
<ProcedureIdentifier> -> identifier */
bool Grammar::procedureIdentifier()
{

	return false;
}

/*  Rule 67
Parses strings in the language generated by
<ProcedureStatement> -> <ProcedureIdentifier> [OptionalActualParameterList] */
bool Grammar::procedureStatement()
{

	return false;
}

/*  Rule 2
Parses strings in the language generated by
<Program> -> <ProgramHeading> ";" <Block> "." */
bool Grammar::program()
{

	if (!programHeading()){
		return false;
	}
	else if (nextTokenType() == MP_SCOLON)
	{ 
		block();
		MP_PERIOD;
		return match();
	}
	else error("Error");
	return false;
}

/*  Rule 3
Parses strings in the language generated by
<ProgramHeading> -> "program" <ProgramIdentifier> */
bool Grammar::programHeading()
{
	switch (nextTokenType())
	{
	case MP_PROGRAM:
		return programIdentifier();
	default:
		error("Error");
	}
	return false;
}

/*  Rule 107
Parses strings in the language generated by
<ProgramIdentifier> -> identifier */
bool Grammar::programIdentifier()
{

	return false;
}

/*  Rule 48
Parses strings in the language generated by
<ReadParameter> -> <VariableIdentifier> */
bool Grammar::readParameter()
{

	return false;
}

/*  Rule 46
Parses strings in the language generated by
<ReadParameterTail> -> "," <ReadParameter> <ReadParameterTail> */
bool Grammar::readParameterTail()
{

	return false;
}

/*  Rule 45
Parses strings in the language generated by
<ReadStatement> -> "read" "(" <ReadParameter> <ReadParameterTail> ")" */
bool Grammar::readStatement()
{

	return false;
}

/*  Rule 76
Parses strings in the language generated by
<RelationalOperator> -> "="|"<"|">"|"<="|">="|"<>" */
bool Grammar::relationalOperator()
{

	return false;
}

/*  Rule 59
Parses strings in the language generated by
<RepeatStatement> -> "repeat" <StatementSequence> "until" <BooleanExpression>    */
bool Grammar::repeatStatement()
{

	return false;
}

/*  Rule 82
	Parses strings in the language generated by 
	<SimpleExpression> -> [ OptionalSign ] <Term> <TermTail>   */
bool Grammar::simpleExpression()
{
	switch (nextTokenType())
	{
	case MP_PLUS:
	case MP_MINUS:
		optionalSign();
	}

	switch (nextTokenType())
	{
	case MP_INTEGER_LIT:
	case MP_FLOAT_LIT:
	case MP_STRING_LIT:
	case MP_BOOLEAN:
	case MP_NOT:
	case MP_LPAREN:
	case MP_IDENTIFIER:
		//all of the above cases fall through to parse <Term> <TermTail>
		term();
		return termTail();

	default:
		//Everythng else fails
		error("Sign Integer Float String Boolean Not LParen Identifier");
		return false;
	}

}

/*  Rule 34
Parses strings in the language generated by
<Statement> -> <EmptyStatement>|<CompoundStatment>|<ReadStatement>|<WriteStatement>|<AssignmentStatment>|
				<IfStatement>|<WhileStatement>|<RepeatStatement>|<ForStatement>|<ProcedureStatement> */
bool Grammar::statement()
{
	switch (nextTokenType())
	{
	case MP_BEGIN:
		return compoundStatement();
	case MP_READ:
		return readStatement();
	case MP_WRITE:
		return writeStatement();
	case MP_IF:
		return ifStatement();
	case MP_WHILE:
		return whileStatement();
	case MP_REPEAT:
		return repeatStatement();
	case MP_FOR:
		return forStatement();
	case MP_IDENTIFIER:
		assignmentStatement();
		procedureStatement();
		break;
	default:
		error("Begin, Read, Write, Writeln, If, While, Repeat, For, Identifier");
	}
	return false;
}

/*  Rule 29
Parses strings in the language generated by
<StatementPart> -> <CompoundStatement> */
bool Grammar::statementPart()
{
	switch (nextTokenType())
	{
	case MP_BEGIN:
		return compoundStatement();
	default:
		error("Keyword begin");
	}
	return false;
}

/*  Rule 31
Parses strings in the language generated by
<StatementSequence> -> <Statement> <StatementTail> */
bool Grammar::statementSequence()
{
	switch (nextTokenType())
	{
	case MP_BEGIN:
	case MP_READ:
	case MP_WRITE:
	case MP_IF:
	case MP_WHILE:
	case MP_REPEAT:
	case MP_FOR:
	case MP_IDENTIFIER:
		statement();
		return statementTail();
	default:
		error("Begin, Read, Write, Writeln, If, While, Repeat, For, Identifier");
	}
	return false;
}

/*  Rule 32
Parses strings in the language generated by
<StatementTail> -> ";" <Statement> <StatementTail>
				-> E */
bool Grammar::statementTail()
{
	switch (nextTokenType())
	{
	case MP_SCOLON:
		match();
		statement();
		return statementTail();
	default:
		error(";");
	}
	return false;
}

/*  Rule 64
Parses strings in the language generated by
<StepValue> -> "to" | "downto" */
bool Grammar::stepValue()
{
	switch (nextTokenType())
	{
	case MP_TO:
	case MP_DOWNTO:
		return match();
	default:
		error("Keyword to, Keyword downto");
	}
	return false;
}

/*  Rule 1
Parses strings in the language generated by
<SystemGoal> -> <Program> EOF */
bool Grammar::systemGoal()
{
	switch (nextTokenType())
	{
	case MP_PROGRAM:
		program();
		if (nextTokenType() == MP_EOF)
		{
			return true;
		}
	default:
		error("Keyword Program");
	}
	return false;
}

/*  Rule 91
Parses strings in the language generated by
<Term> -> <Factor> <FactorTail> */
bool Grammar::term()
{
	switch (nextTokenType())
	{
	case MP_INTEGER_LIT:
	case MP_FLOAT_LIT:
	case MP_STRING_LIT:
	case MP_BOOLEAN:
	case MP_NOT:
	case MP_LPAREN:
	case MP_IDENTIFIER:
		//all of the above cases fall through to parse <Term> <TermTail>
		factor();
		return factorTail();

	default:
		//Everythng else fails
		error("Integer Float String Boolean Not LParen Identifier");
		return false;
	}
}

/*  Rule 83
Parses strings in the language generated by
<TermTail> -> <AddingOperator> <Term> <TermTail> */
bool Grammar::termTail()
{
	switch (nextTokenType())
	{
	case MP_PLUS:
	case MP_MINUS:
	case MP_OR:
		addingOperator();
		term();
		return termTail();
	default:
		error("+ - Keyword or");
	}
	return false;
}

/*  Rule 10
Parses strings in the language generated by
<Type> -> "Integer"|"Float"|"String"|"Boolean" */
bool Grammar::type()
{

	switch (nextTokenType())
	{
	case MP_INTEGER:
	case MP_BOOLEAN:
	case MP_FLOAT:
	case MP_STRING:
		//all of the above cases fall through to accept
		return match();

	default:
		//Everythng else fails
		error("Type");
	}

	return false;
}

/*  Rule 27
Parses strings in the language generated by
<ValueParameterSection> -> <IdentifierList> ":" <Type> */
bool Grammar::valueParameterSection()
{
	switch (nextTokenType())
	{
	case MP_IDENTIFIER:
		identifierList();
		if (nextTokenType() == MP_COLON)
		{
			return type();
		}
	default:
		error("Identifier");
	}
	return false;
}

/*  Rule 9
Parses strings in the language generated by
<VariableDeclaration> -> <IdentifierList> ":" <Type> */
bool Grammar::variableDeclaration()
{

	return false;
}

/*  Rule 5
Parses strings in the language generated by
<VariableDeclarationPart> -> "var" <VariableDeclaration> ";" <VariableDeclarationTail>
						  ->  E  */
bool Grammar::variableDeclarationPart()
{

	return false;
}

/*  Rule 7
Parses strings in the language generated by
<VariableDeclarationTail> -> <VariableDeclaration> ";" <VariableDeclarationTail> */
bool Grammar::variableDeclarationTail()
{

	return false;
}

/*  Rule 108
Parses strings in the language generated by
<VariableIdentifier> -> Identifier */
bool Grammar::variableIdentifier()
{

	return false;
}

/*  Rule 28
Parses strings in the language generated by
<VariableParameterSEction> -> "var" <IdentifierList> ":" <Type>  */
bool Grammar::variableParameterSection()
{

	return false;
}

/*  Rule 60
Parses strings in the language generated by
<WhileStatement> -> "while" <BooleanExpression> "do" <Statement> */
bool Grammar::whileStatement()
{

	return false;
}

/*  Rule 53
Parses strings in the language generated by
<WriteParameter> -> <OrdinalExpression>   */
bool Grammar::writeParameter()
{

	return false;
}

/*  Rule 51
Parses strings in the language generated by
<WriteParameterTail> -> "," <WriteParameter> <WriteParameterTail>
					 ->  E  */
bool Grammar::writeParameterTail()
{

	return false;
}

/*  Rule 49
Parses strings in the language generated by
<WriteStatement> -> "write"  "(" <WriteParameter> <WriteParameterTail> ")" 
				 -> "writeln" "(" <WriteParameter> <WriteParameterTail> ")"  */
bool Grammar::writeStatement()
{

	return false;
}