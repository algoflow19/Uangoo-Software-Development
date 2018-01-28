#include "MorseCode.h"
#include<string>
#include<iostream>
using namespace std;


MorseCode::MorseCode()
{
	head = new MorseNode;
	head->letter = "";
	head->Left = NULL;
	head->Right = NULL;

	string letter = "E";
	string code = ".";
	buildMorseCodeTree(letter, code, head);
	letter = "T";
	code = "-";
	buildMorseCodeTree(letter, code, head);
	letter = "I";
	code = "..";
	buildMorseCodeTree(letter, code, head);
	letter = "S";
	code = "...";
	buildMorseCodeTree(letter, code, head);
	letter = "U";
	code = "..-";
	buildMorseCodeTree(letter, code, head);
	letter = "H";
	code = "....";
	buildMorseCodeTree(letter, code, head);
	letter = "V";
	code = "...-";
	buildMorseCodeTree(letter, code, head);
	letter = "F";
	code = "..-.";
	buildMorseCodeTree(letter, code, head);
	letter = "A";
	code = ".-";
	buildMorseCodeTree(letter, code, head);
	letter = "R";
	code = ".-.";
	buildMorseCodeTree(letter, code, head);
	letter = "W";
	code = ".--";
	buildMorseCodeTree(letter, code, head);
	letter = "L";
	code = ".-..";
	buildMorseCodeTree(letter, code, head);
	letter = "P";
	code = ".--.";
	buildMorseCodeTree(letter, code, head);
	letter = "J";
	code = ".---";
	buildMorseCodeTree(letter, code, head);
	letter = "N";
	code = "-.";
	buildMorseCodeTree(letter, code, head);
	letter = "D";
	code = "-..";
	buildMorseCodeTree(letter, code, head);
	letter = "K";
	code = "-.-";
	buildMorseCodeTree(letter, code, head);
	letter = "B";
	code = "-...";
	buildMorseCodeTree(letter, code, head);
	letter = "X";
	code = "-..-";
	buildMorseCodeTree(letter, code, head);
	letter = "C";
	code = "-.-.";
	buildMorseCodeTree(letter, code, head);
	letter = "Y";
	code = "-.--";
	buildMorseCodeTree(letter, code, head);
	letter = "M";
	code = "--";
	buildMorseCodeTree(letter, code, head);
	letter = "G";
	code = "--.";
	buildMorseCodeTree(letter, code, head);
	letter = "O";
	code = "---";
	buildMorseCodeTree(letter, code, head);
	letter = "Z";
	code = "--..";
	buildMorseCodeTree(letter, code, head);
	letter = "Q";
	code = "--.-";
	buildMorseCodeTree(letter, code, head);
}


MorseCode::~MorseCode()
{

}

std::string MorseCode::getMorseCodeLetter(std::string code) const
{
	return doGetMorseCodeLetter(code, head);
}

void MorseCode::buildMorseCodeTree(const std::string & letter, std::string & code, MorseNode*  &Node)
{
	if (code.length() == 0) {
		if (Node != NULL) cout << "Error! " << "The letter is " << letter << ", The code is " << code << endl;
		Node = new MorseNode;
		Node->letter = letter;
		Node->Left = NULL;
		Node->Right = NULL;
		return;
	}
	if (code[0] == '.') {
		code.erase(0, 1);
		buildMorseCodeTree(letter, code, Node->Left);
		return;
	}
	else {
		code.erase(0, 1);
		buildMorseCodeTree(letter, code, Node->Right);
		return;
	}
	
}

void MorseCode::DeleteTree(MorseNode * Node)
{
	if (Node == NULL) return;
	DeleteTree(Node->Left);
	DeleteTree(Node->Right);
	delete Node;
	return;
}

std::string MorseCode::doGetMorseCodeLetter(std::string code, MorseNode * Node) const
{
	if (code.length() == 0) {
		return Node->letter;
	}
	if (code[0] == '.') {
		code.erase(0, 1);
		return doGetMorseCodeLetter(code, Node->Left);
	}
	else {
		code.erase(0, 1);
		return doGetMorseCodeLetter(code, Node->Right);
	}
}
