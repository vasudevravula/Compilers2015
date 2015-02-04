#ifndef FINITE_STATE_AUTOMATON
#define FINITE_STATE_AUTOMATON

#include "Token.h"
#include <istream>

using namespace std;

class FiniteStateAutomaton {
   
public:

	//static helper functions (regex definitions)
	//use these for now we can change the underlying logic if we want
	//to use different library functions
	static bool charIsWhiteSpace(char c);
	static bool charIsDigit(char c);
	static bool charIsUpperAlphabet(char c);
	static bool charIsLowerAlphabet(char c);

	//this can be used to do all the work for the single character FSAs
	static Token singleCharFSA(istream* stream, char c, Lexeme::LexemeType type, int& line, int& currentColumn);


	static Token greaterThan(istream* stream, int& line, int& currentColumn);
	static Token equals(istream* stream, int& line, int& currentColumn);
	static Token backslash(istream* stream, int& line, int& currentColumn);
	static Token period(istream* stream, int& line, int& currentColumn);
	static Token endOfFile(istream* stream, int& line, int& currentColumn);

	static Token lessThan(istream* stream, int& line, int& currentColumn);
	static Token roundLeftBracket(istream* stream, int& line, int& currentColumn);
	static Token roundRightBracket(istream* stream, int& line, int& currentColumn);
	static Token plus(istream* stream, int& line, int& currentColumn);

	static Token colon(istream* stream, int& line, int& currentColumn);
	static Token scolon(istream* stream, int& line, int& currentColumn);
	static Token comma(istream* stream, int& line, int& currentColumn);
	static Token minus(istream* stream, int& line, int& currentColumn);
	static Token times(istream* stream, int& line, int& currentColumn);

	static Token number(istream* stream, int&line, int& currentColumn);
	static Token identifier(istream* stream, int&line, int& currentColumn);
	static Token stringLiteral(istream* stream, int& line, int& currentColumn);



};

#endif //FINITE_STATE_AUTOMATON