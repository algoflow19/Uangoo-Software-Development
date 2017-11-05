#pragma once
#include<string>


class TokenScanner
{
public:

	TokenScanner();
	~TokenScanner();
	TokenScanner(std::string instr);
	void setInput(std::string instr);

	std::string nextToken();
	void saveToken(std::string token);
	bool hasMoreTokens();
	
	void setStringscannFlag();
	void setWhiteSpaceSkipFlag();
	void setNumberscannFlag();

private:

	std::string scannDefault();

	char scannString();

	std::string scannNumber();

	void skipWhiteSpace();

	std::string stackpop();

	int start,pos;

	std::string ignoreSet;
	std::string sourceStr;
	std::string stringStack;

	std::string stackPointer;


	bool wskipflag;
	bool stringScannFlag;
	bool numberScannFlag;

};

