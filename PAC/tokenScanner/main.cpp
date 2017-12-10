// PAC++.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"TokenScanner.h"

using namespace std;

// Have to rebuild the system 

int main()
{
	ifstream infile;
	infile.open("testfile.txt");
	TokenScanner scanner;
	scanner.setInput(infile);
	scanner.setWhiteSpaceSkipFlag();
	cout << scanner.nextToken() << endl;
	cout << scanner.nextToken() << endl;
	cout << scanner.nextToken() << endl;
	cout << scanner.nextToken() << endl;
	
    return 0;
}

