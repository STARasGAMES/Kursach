#pragma once

#ifndef SYMDEF_H
#define SYMDEF_H



#include <vector>
#include <string>
#include <map>
#include "token.h"

std::vector<std::string> keywords;
std::vector<std::string> operators;
std::vector<std::string> delimiters;

std::vector<TokenType> keywordsTokens = {
	tkKeywordIF, tkKeywordELSE, tkKeywordINT, tkKeywordBOOL, tkKeywordVOID, 
	tkKeywordSWITCH, tkKeywordCASE, tkKeywordBREAK, tkKeywordDEFAULT, tkKeywordTRUE, tkKeywordFALSE
};

std::vector<TokenType> operatorsTokens = {
	// Relational Operators (==  <  >  =!=    =>  =<)
	tkOperatorEQUAL, tkOperatorGREATER, tkOperatorLESS, tkOperatorGREATER_EQUAL, tkOperatorLESS_EQUAL, tkOperatorNOT_EQUAL,

	// Other operators (= :  +  -  *  / %  !=  ++  --  +=  -=)
	tkOperatorASSIGN, tkOperatorCOLON, tkOperatorADD,
	tkOperatorSUBTRACT, tkOperatorMUL, tkOperatorDIV,
	tkOperatorREMAINDER, tkOperatorINC, tkOperatorDEC,
	tkOperatorADD_ASSIGN, tkOperatorSUB_ASSIGN,
	tkOperatorAND, tkOperatorOR, tkOperatorXOR,
	tkOperatorLOGICAL_AND, tkOperatorLOGICAL_OR
};

std::vector<TokenType> delimitersTokens = {
	// Delimiters (. (  ) , { } ; [ ])
	tkDelimiterDOT, tkDelimiterLEFT_PA, tkDelimiterRIGHT_PA, tkDelimiterCOMMA, tkDelimiterLEFT_BRACE, tkDelimiterRIGHT_BRACE,
	tkDelimiterSEMICOLON, tkDelimiterLEFT_BRACKET, tkDelimiterRIGHT_BRACKET
};

std::map<TokenType, std::string> tokenToStringMap =
{
	{tkEOF, "\n"},
	{tkNA, "N/A token"},
	// KEYWORDS
	{ tkKeywordIF, "if" },
	{ tkKeywordELSE, "else" },
	{ tkKeywordINT, "int" },
	{ tkKeywordBOOL, "bool" },
	{ tkKeywordTRUE, "true" },
	{ tkKeywordFALSE, "false" },
	{ tkKeywordVOID, "void" },
	{ tkKeywordSWITCH, "switch" },
	{ tkKeywordCASE, "case" },
	{ tkKeywordBREAK, "break" },
	{ tkKeywordDEFAULT, "default" },


	// OPERATORS
	{ tkOperatorADD, "+" },
	{ tkOperatorASSIGN, "=" },
	{ tkOperatorCOLON, ":"},
	{ tkOperatorDIV, "/" },
	{ tkOperatorEQUAL, "==" },
	{ tkOperatorGREATER, ">" },
	{ tkOperatorGREATER_EQUAL, ">=" },
	{ tkOperatorLESS, "<" },
	{ tkOperatorLESS_EQUAL, "<=" },
	{ tkOperatorREMAINDER, "%" },
	{ tkOperatorMUL, "*" },
	{ tkOperatorNOT_EQUAL, "!=" },
	{ tkOperatorSUBTRACT, "-" },
	{ tkOperatorINC, "++" },
	{ tkOperatorDEC, "--" },
	{ tkOperatorADD_ASSIGN, "+=" },
	{ tkOperatorSUB_ASSIGN, "-=" },
	{ tkOperatorAND, "&" },
	{ tkOperatorOR, "|" },
	{ tkOperatorXOR, "^" },
	{ tkOperatorLOGICAL_AND, "&&" },
	{ tkOperatorLOGICAL_OR, "||" },
	{ tkOperatorQUESTION_MARK, "?" },

	// DELIMITERS
	{ tkDelimiterCOMMA, ","},
	{ tkDelimiterDOT, "." },
	{ tkDelimiterLEFT_BRACKET, "[" },
	{ tkDelimiterLEFT_PA, "(" },
	{ tkDelimiterLEFT_BRACE, "{" },
	{ tkDelimiterRIGHT_BRACE, "}" },
	{ tkDelimiterRIGHT_BRACKET, "]" },
	{ tkDelimiterRIGHT_PA, ")" },
	{ tkDelimiterSEMICOLON, ";" }
};

std::map<std::string, TokenType> stringToTokenTypeMap;

std::string word;
int wi = 0; // index of word string

std::string numStr;

void InitSymbols() {
	for (const auto& pair : tokenToStringMap)
	{
		stringToTokenTypeMap[pair.second] = pair.first;
	}
	// SETUP KEYWORDS
	for (int i = 0; i < keywordsTokens.size(); i++)
	{
		keywords.push_back(tokenToStringMap[keywordsTokens[i]]);
	}
	// SETUP OPERATORS
	for (int i = 0; i < operatorsTokens.size(); i++)
	{
		operators.push_back(tokenToStringMap[operatorsTokens[i]]);
	}
	// SETUP DELIMITERS
	for (int i = 0; i < delimitersTokens.size(); i++)
	{
		delimiters.push_back(tokenToStringMap[delimitersTokens[i]]);
	}
}


#endif // !SYMDEF_H