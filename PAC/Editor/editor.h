#pragma once
#include<string>
#include<iostream>
#include "buffer.h"

enum commond
{
	cursorForware,cursorBackware,cursorToEnd,cursorToStart,
	del,backspace,
	mulLineInsert, chInsert,
	showHelp,showText,
	forwareWord,backwareWord,delWord,
	quitEditor
};

class Editor
{
public:
	Editor();
	~Editor();
	void loadUserInput();
	void doOperation();
	bool shouldQuit() const;

private:
	std::string currentInputLine;
	commond currenCommond;
	Buffer buffer;
	bool quitFlag;
	int executeTimes;
	void extractExecuteTimes();
	inline void loadInput();
	void extractCommond();
	void getHelp() const;

	std::string selfTestToken;
	std::string getCurrentToken();
};

