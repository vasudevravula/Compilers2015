#include "FiniteStateAutomaton.h"

#include <iostream>

bool FiniteStateAutomaton::charIsWhiteSpace(char c)
{
	if (c == ' ') return true;
	if (c == '\t') return true;
	if (c == '\n') return true;

	return false;
}

bool FiniteStateAutomaton::charIsDigit(char c)
{
	if (c == '1') return true;
	if (c == '2') return true;
	if (c == '3') return true;
	if (c == '4') return true;
	if (c == '5') return true;
	if (c == '6') return true;
	if (c == '7') return true;
	if (c == '8') return true;
	if (c == '9') return true;
	if (c == '0') return true;
	
	return false;
}

bool FiniteStateAutomaton::charIsUpperAlphabet(char c)
{
	if (c == 'A') return true;
	if (c == 'B') return true;
	if (c == 'C') return true;
	if (c == 'D') return true;
	if (c == 'E') return true;
	if (c == 'F') return true;
	if (c == 'G') return true;
	if (c == 'H') return true;
	if (c == 'I') return true;
	if (c == 'J') return true;
	if (c == 'K') return true;
	if (c == 'L') return true;
	if (c == 'M') return true;
	if (c == 'N') return true;
	if (c == 'O') return true;
	if (c == 'P') return true;
	if (c == 'Q') return true;
	if (c == 'R') return true;
	if (c == 'S') return true;
	if (c == 'T') return true;
	if (c == 'U') return true;
	if (c == 'V') return true;
	if (c == 'W') return true;
	if (c == 'X') return true;
	if (c == 'Y') return true;
	if (c == 'Z') return true;

	return false;
}

bool FiniteStateAutomaton::charIsLowerAlphabet(char c)
{
	if (c == 'a') return true;
	if (c == 'b') return true;
	if (c == 'c') return true;
	if (c == 'd') return true;
	if (c == 'e') return true;
	if (c == 'f') return true;
	if (c == 'g') return true;
	if (c == 'h') return true;
	if (c == 'i') return true;
	if (c == 'j') return true;
	if (c == 'k') return true;
	if (c == 'l') return true;
	if (c == 'm') return true;
	if (c == 'n') return true;
	if (c == 'o') return true;
	if (c == 'p') return true;
	if (c == 'q') return true;
	if (c == 'r') return true;
	if (c == 's') return true;
	if (c == 't') return true;
	if (c == 'u') return true;
	if (c == 'v') return true;
	if (c == 'w') return true;
	if (c == 'x') return true;
	if (c == 'y') return true;
	if (c == 'z') return true;

	return false;
}

Token FiniteStateAutomaton::singleCharFSA(istream* stream, char c, Lexeme::LexemeType type, int& line, int& currentColumn)
{
	char next;
	string name;
	//Start State
	{
		next = stream->peek();
		if (next == c){ //transition
			name += stream->get();
			currentColumn++;
			goto Accept;
		}
		goto Reject;
	}
Accept:
	{
		return Token(type, name, line, currentColumn);
	}
Reject:
	{
		return Token();
	}
}

Token FiniteStateAutomaton::greaterThan(istream* stream, int& line, int& currentColumn)
{
	char next;
	string name;
//Start State
	{
		//look without taking
		next = stream->peek();
		if (next == '>'){ //transition
			//move ahead next char
			name += stream->get(); //we already know it is a '>'
			currentColumn++;
			goto GreaterThan;
		}
		//default condition
		goto Reject;
	}

GreaterThan:
	{
		next = stream->peek();
		if (next == '='){ //transition
			//take the '='
			name += stream->get();
			currentColumn++;
			goto GreaterThanOrEqual;
		}
		//accept greater than
		return Token(Lexeme::LexemeType::MP_GTHAN, name, line, currentColumn);
	}

GreaterThanOrEqual:
	{
		//can go no further
		return Token(Lexeme::LexemeType::MP_GEQUAL, name, line, currentColumn);
	}

Reject:
	{
		//nothing here, return default init token (invalid)
		return Token();
	}
}

Token FiniteStateAutomaton::equals(istream* stream, int& line, int& currentColumn)
{
	return singleCharFSA(stream, '=', Lexeme::LexemeType::MP_EQUAL, line, currentColumn);
}

Token FiniteStateAutomaton::backslash(istream* stream, int& line, int& currentColumn)
{
	return singleCharFSA(stream, '/', Lexeme::LexemeType::MP_FLOAT_DIVIDE, line, currentColumn);
}

Token FiniteStateAutomaton::period(istream* stream, int& line, int& currentColumn)
{
	return singleCharFSA(stream, '.', Lexeme::LexemeType::MP_PERIOD, line, currentColumn);
}

Token FiniteStateAutomaton::endOfFile(istream* stream, int& line, int& currentColumn)
{
	char next;
	string name;
	if (stream->peek() < 0){//then this is the end of the file
		next = stream->get();
		return Token(Lexeme::LexemeType::MP_EOF, name , line, currentColumn);
	}
	return Token();
}

Token FiniteStateAutomaton::number(istream* stream, int& line, int& currentColumn)
{
	char next;
	string name;

	Lexeme::LexemeType lastGoodType = Lexeme::LexemeType::MP_INVALID;
	int lastGoodPosition = stream->tellg();
	string temp;

	//start state
	{
		next = stream->peek();
		if (charIsDigit(next)){
			name += stream->get();
			currentColumn++;
			goto IntegerLit;
		}
		goto Reject;
	}

IntegerLit://digit{digit}
	{
		next = stream->peek();

		if (charIsDigit(next)){
			name += stream->get();
			currentColumn++;
			goto IntegerLit;
		}

		lastGoodType == Lexeme::LexemeType::MP_INTEGER_LIT;

		if (next == '.'){
			lastGoodPosition = stream->tellg();
			temp += stream->get();
			goto FixedLit;
		}

		if (next == 'e' || next == 'E'){
			lastGoodPosition = stream->tellg();
			temp += stream->get();
			goto FloatLitE;
		}

		return Token(lastGoodType, name, line, currentColumn);
	}

FixedLit: //got here from a "." 
	{
		next = stream->peek();

		if (charIsDigit(next)){
			temp += stream->get();
			goto FixedLitTrailingInt;
		}
		
		goto Reject;
	}

FixedLitTrailingInt:
	{
		next = stream->peek();

		if (next == 'e' || next == 'E'){
			//fixedlit is done 
			name += temp;
			currentColumn += temp.size();
			lastGoodType = Lexeme::LexemeType::MP_FIXED_LIT;
			temp.clear();

			//go for the float lit
			lastGoodPosition = stream->tellg();
			temp += stream->get(); //get the 'e'
			goto FloatLitE;
		}

		name += temp;
		currentColumn += temp.size();

		return Token(Lexeme::LexemeType::MP_FIXED_LIT, name, line, currentColumn);
	}

FloatLitE:
	{
		next = stream->peek();
		
		if (next == '+' || next == '-'){
			temp += stream->get();
			goto FloatLitPlusMinus;
		}

		goto Reject;
	}

FloatLitPlusMinus:
	{
		next = stream->peek();

		if (charIsDigit(next)){
			temp += stream->get();
			goto FloatLitTrailingInt;
		}

		goto Reject;
	}

FloatLitTrailingInt:
	{
		next = stream->peek();

		if (charIsDigit(next)){
			temp += stream->get();
			goto FloatLitTrailingInt;
		}

		name += temp;
		currentColumn += temp.size();
		return Token(Lexeme::LexemeType::MP_FLOAT_LIT, name, line, currentColumn);
	}

Reject:
	{
		if (lastGoodType == Lexeme::LexemeType::MP_INVALID){
			return Token();
		}
		stream->seekg(lastGoodPosition);
		return Token(lastGoodType, name, line, currentColumn);	
	}

}