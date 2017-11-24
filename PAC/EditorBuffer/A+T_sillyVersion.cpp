#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include"buffer.h"
using namespace std;

// This file 

void showTextContent(Buffer & buffer);
void doOperate(Buffer & buffer,string commond);
void getHelp();
char loadCommond(Buffer & buffer);

int main() {
	Buffer buf;
	string commond;
	while (true)
	{
		cout << "*";
		getline(cin, commond);
		if (commond[0] == 'Q') return 0;
		doOperate(buf, commond);
		
	}
	
	return 0;
}

void showTextContent(Buffer & buffer) {
	string tmpStr = buffer.getText();
	//int tmpInt = buffer.getCursor();
	//tmpStr.insert(tmpInt,"|" );
	cout << tmpStr << endl;
}
void doOperate(Buffer & buffer, string commond) {
	string tmp;
	switch (commond[0]) {
	case 'F':
		buffer.moveCursorForware();
		break;
	case 'B':
		buffer.moveCursorBackware();
		break;
	case 'J':
		buffer.moveCursorStart();
		break;
	case 'E':
		buffer.moveCursorEnd();
		break;
	case 'A':
		commond = "";
		while (true)
		{
			getline(cin, tmp);
			commond += ("\n" + tmp);
			if (tmp.length()>0&&tmp[tmp.length() - 1] == '.') {
				commond.erase(commond.length() - 1);
				break;
			}
		}
	case 'I':
		for (int index = 1; index < commond.length(); index++) {
			buffer.insertChar(commond[index]);
		}
		break;
	case 'D':
		buffer.delChar();
		break;
	case 'H':
		getHelp();
		break;
	case 'T':
		showTextContent(buffer);
		break;
	default:
		cout << "Incorrect input!" << endl;
		getHelp();
	}
}
void getHelp() {
	cout << "Sorry this is used to program practice...." << endl;
	cout << "Try F B J E Ixxx D H Q for help" << endl;
}