#include "editor.h"
#include"mystrlib.h"
using namespace std;


Editor::Editor()
{
	quitFlag = false;
	currentInputLine = "";
	selfTestToken = "IThis is the test word.\nT\nWF\nT\nJ\nT\nWB\nT\nWB\nT\nWD\nT\nQ\n";
	//selfTestToken = "IThis is the test word.\nT\nJ\nT\nB\nT\nE\nT\nF\nD\nT\nH\nQ\n";
}


Editor::~Editor()
{
}

void Editor::loadUserInput()
{
	cout << "*";
	loadInput();
	extractExecuteTimes();
	extractCommond();
}

void Editor::doOperation()
{
	string tmp;
	int jumpLength = 0;
	int cursorPos = 0;

	for (int i = 1; i <= executeTimes;i++)
	switch (currenCommond) {
	case cursorForware:
		buffer.moveCursorForware();
		break;
	case cursorBackware:
		buffer.moveCursorBackware();
		break;
	case cursorToStart:
		buffer.moveCursorStart();
		break;
	case cursorToEnd:
		buffer.moveCursorEnd();
		break;
	case mulLineInsert:
		while (true)
		{
			getline(cin, tmp);
			currentInputLine += ("\n" + tmp);
			if (tmp.length()>0 && tmp[tmp.length() - 1] == '.') {
				currentInputLine.erase(currentInputLine.length() - 1);
				break;
			}
		}
	case chInsert:
		for (int index = 0; index < currentInputLine.length(); index++) {
			buffer.insertChar(currentInputLine[index]);
		}
		break;
	case del:
		buffer.delChar();
		break;
	case forwareWord:
		tmp = buffer.getText();
		cursorPos = buffer.getCursor();
		cout << "This is cursorPos: "<<cursorPos << endl;
		while (cursorPos-jumpLength-1>=0&&!isalnum(tmp[cursorPos - jumpLength-1])){
			jumpLength++;
		}
		while (cursorPos - jumpLength - 1 >= 0 && isalnum(tmp[cursorPos - jumpLength - 1])) {
			jumpLength++;
		}
		if (jumpLength != 0) {
			executeTimes = jumpLength;
			currenCommond = cursorForware;
			doOperation();
			executeTimes = 1;
		}
		break;
	case backwareWord:
	case delWord:
		tmp = buffer.getText();
		cursorPos = buffer.getCursor();
		while (cursorPos + jumpLength <tmp.length() && !isalnum(tmp[cursorPos + jumpLength ])) {
			jumpLength++;
		}
		while (cursorPos + jumpLength <tmp.length() && isalnum(tmp[cursorPos + jumpLength])) {
			jumpLength++;
		}
		if (currenCommond==backwareWord&&jumpLength != 0) {
			executeTimes = jumpLength;
			currenCommond = cursorBackware;
			doOperation();
			executeTimes = 1;
		}
		else if (jumpLength != 0) {
			executeTimes = jumpLength;
			currenCommond = del;
			doOperation();
			executeTimes = 1;
		}
		break;
		
	case showHelp:
		getHelp();
		break;
	case showText:
		tmp = buffer.getText();
		tmp.insert(buffer.getCursor(),"|" );
		cout << tmp << endl;
		break;
	case quitEditor:
		quitFlag = true;
		break;
	default:
		cout << "Program error!" << endl;
	}
}

bool Editor::shouldQuit() const
{
	return quitFlag;
}

void Editor::extractExecuteTimes()
{
	string tmpstr = "";
	int numLength = 0;
	for (int i = 0; currentInputLine[i] >= '0'&&currentInputLine[i] <= '9'; i++)
		numLength++;
	if (numLength != 0) {
		tmpstr = currentInputLine.substr(0, numLength);
		currentInputLine.erase(0, numLength);
		executeTimes = stringToInteger(tmpstr);
	}
	else executeTimes = 1;
}

inline void Editor::loadInput()
{
	//getline(cin, currentInputLine);
	string tmp= getCurrentToken();
	currentInputLine = tmp;
	cout << tmp << endl;
}

void Editor::extractCommond()
{
	switch (currentInputLine[0])
	{

	case 'F':
		currenCommond = cursorForware;
		currentInputLine.erase(0, 1);
		break;
	case 'B':
		currenCommond = cursorBackware;
		currentInputLine.erase(0, 1);
		break;
	case 'J':
		currenCommond = cursorToStart;
		currentInputLine.erase(0, 1);
		break;
	case 'E':
		currenCommond = cursorToEnd;
		currentInputLine.erase(0, 1);
		break;
	case 'A':
		currenCommond = mulLineInsert;
		currentInputLine.erase(0, 1);
		break;
	case 'I':
		currenCommond = chInsert;
		currentInputLine.erase(0, 1);
		break;
	case 'D':
		currenCommond = del;
		currentInputLine.erase(0, 1);
		break;
	case 'H':
		currenCommond = showHelp;
		currentInputLine.erase(0, 1);
		break;
	case 'T':
		currenCommond = showText;
		currentInputLine.erase(0, 1);
		break;
	case 'W':
		currentInputLine.erase(0, 1);
		extractCommond();
		switch (currenCommond) {
		case cursorForware:
			currenCommond = forwareWord;
			break;
		case cursorBackware:
			currenCommond = backwareWord;
			break;
		case del:
			currenCommond = delWord;
			break;
		}
		break;
	case 'Q':
		currenCommond = quitEditor;
		break;
	default:
		cout << "You had a incorrect input!" << endl;
		getHelp();
		loadUserInput();
		break;
	}
}

void Editor::getHelp() const
{
	cout << "Sorry this is used to program practice...." << endl;
	cout << "Try F B J E Ixxx D H Q for help" << endl;
}

std::string Editor::getCurrentToken()
{
	string tmp;
	int tokenLength = 0;
	while (selfTestToken[tokenLength] != '\n')
		tokenLength++;
	tmp = selfTestToken.substr(0, tokenLength);
	selfTestToken.erase(0, tokenLength + 1);
	return tmp;
}
