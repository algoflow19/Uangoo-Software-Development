#include<iostream>
#include<string>
#include"bst.h"
#include"MorseCode.h"
using namespace std;


int main() {
	MorseCode finder;
	cout << finder.getMorseCodeLetter("-") <<" is T"<< endl;
	cout << finder.getMorseCodeLetter("..") << " is I" << endl;
	cout << finder.getMorseCodeLetter("....") << " is H" << endl;
	cout << finder.getMorseCodeLetter("...-") << " is V" << endl;
	cout << finder.getMorseCodeLetter("-..-") << " is X" << endl;
	cout << finder.getMorseCodeLetter("---") << " is O" << endl;
	cout << finder.getMorseCodeLetter("--.-") << " is Q" << endl;
	cout << finder.getMorseCodeLetter("--..") << " is Z" << endl;
	cout << finder.getMorseCodeLetter("-...") << " is B" << endl;
	return 0;
}

