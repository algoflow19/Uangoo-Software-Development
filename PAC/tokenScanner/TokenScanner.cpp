#include "TokenScanner.h"
#include<sstream>
#include <cctype>
#include<iostream>


TokenScanner::TokenScanner()
{
}

TokenScanner::TokenScanner(std::string instr)
{
	setInput(instr);  // Good Practice!

}
void TokenScanner::setInput(std::string instr)
{
	
	sourceStr = instr;
	start = 0;
	pos = 0;
	ignoreSet = "";
	wskipflag = false;
	stringScannFlag = false;
	numberScannFlag = false;
	stringStack = "";
	stackPointer = "";

}
void TokenScanner::setInput(std::istream & infile)
{
	this->infile = &infile; // Attention that this is a pointer!
	sourceStrReflash();
}
std::string TokenScanner::nextToken()
{
	std::string tmpStr = "";
		if (!stringStack.empty())
			return stackpop();
		if (wskipflag)
			skipWhiteSpace();
		if (stringScannFlag) {
			scannString();
			if (pos != start) {
				tmpStr = sourceStr.substr(start, pos - start);
				start = pos;
				return tmpStr;
			}
		}
		if (numberScannFlag) {
			scannNumber();
			if (start != pos) {
				tmpStr = sourceStr.substr(start, pos - start);
				start = pos;
				return tmpStr;
			}
		}
		return scannDefault();

	
	
	
}

bool TokenScanner::hasMoreTokens()
{
	return (pos<sourceStr.length());
}

void TokenScanner::setStringscannFlag()
{
	stringScannFlag = true;
}

void TokenScanner::setWhiteSpaceSkipFlag()
{
	wskipflag = true;
}

void TokenScanner::setNumberscannFlag()
{
	numberScannFlag = true;
}



void TokenScanner::saveToken(std::string token)
{
	std::string tmpStr = "";
	std::stringstream ss;
	ss << token.length();
	ss >> tmpStr;
	stackPointer = tmpStr + "X" + stackPointer;
	stringStack = token + stringStack;

}

TokenScanner::~TokenScanner()
{
}


char TokenScanner::scannString()
{
	if (sourceStr[pos] == '\'' || sourceStr[pos] == '\"') {
		if (sourceStr.find(sourceStr[pos], pos + 1) == std::string::npos)
		{
			return sourceStr[pos - 1];
		}
		else
		{
			pos = sourceStr.find(sourceStr[pos], pos + 1) + 1;
			return sourceStr[pos - 1];
		}
	}
	else
	{
		return ' ';
	}
}


/* This Need to be rebuilded! */
std::string TokenScanner::scannNumber()
{
	int caseNumber = 0;
	while (true)
	{
		switch (caseNumber)
		{
		case 0:
			if (isdigit(sourceStr[pos])) {
				caseNumber = 1;
				pos++;
				break;
			}
			else
				return "";
		case 1:
			if (isdigit(sourceStr[pos])) {
				caseNumber = 1;
				pos++;
				break;
			}
			else
				if (sourceStr[pos] == '.') {
					caseNumber = 2;
					pos++;
					break;
				}
				else if (sourceStr[pos] == 'E')
				{
					caseNumber = 3;
					pos++;
					break;
				}
				else return "";
		case 2:
			if (isdigit(sourceStr[pos])) {
				caseNumber = 2;
				pos++;
				break;
			}
			else if (sourceStr[pos] == 'E') {
				caseNumber = 3;
				pos++;
				break;
			}
			else return "";
		case 3:
			if (isdigit(sourceStr[pos])) {
				caseNumber = 5;
				pos++;
				break;
			}
			else if (sourceStr[pos] == '+' || sourceStr[pos] == '-') {
				caseNumber = 4;
				pos++;
				break;
			}
			else {
				pos = start;
				return "";
			}
		case 4:
			if (isdigit(sourceStr[pos])) {
				caseNumber = 5;
				pos++;
				break;
			}
			else {
				pos = start;
				return "";
			}
		case 5:
			if (isdigit(sourceStr[pos])) {
				caseNumber = 5;
				pos++;
				break;
			}
			else return "";
		default:
			return "Error Happened!";
		}
	}

}

std::string TokenScanner::scannDefault() {
	std::string tmpStr;
	if (pos<sourceStr.length())
		while (ignoreSet.find(sourceStr[pos]) != std::string::npos) {
			pos++;
		}
	if (!isalnum(sourceStr[pos]) && sourceStr[pos] != '\0') {
		//Reason for make this mistake: Not actually see the runs! <-------
		tmpStr += sourceStr[pos];
		pos++;
	}
	else
		while (isalnum(sourceStr[pos])) {
			if (ignoreSet.find(sourceStr[pos]) == std::string::npos)
				tmpStr += sourceStr[pos];
			pos++;
		}
	start = pos;
	return tmpStr;
}

void TokenScanner::skipWhiteSpace()
{
	if (sourceStr[pos] == ' ') {
		while (sourceStr[pos] == ' ')
		{
			pos++;
			start++;
		}
	}
}

std::string TokenScanner::stackpop()
{
	if (stringStack == "")
		return "Error";

	std::stringstream ss;
	ss << stackPointer.substr(0, stackPointer.find("X"));
	int tmpint;
	ss >> tmpint;

	stackPointer.erase(0, stackPointer.find("X") + 1);
	std::string tmpStr = stringStack.substr(0, tmpint);
	stringStack.erase(0, tmpint);
	return tmpStr;
}

void TokenScanner::sourceStrReflash()
{
	
	std::string tmpStr;
	std::string store;
	while (!infile->fail())
	{
		std::getline(*infile, tmpStr);
		store += tmpStr;
	}
	infile->clear();
	this->setInput(store);
}
