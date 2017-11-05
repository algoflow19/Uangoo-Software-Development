// PAC++.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"TokenScanner.h"

using namespace std;

// Have to rebuild the system 

int main()
{
	TokenScanner scanner;
	scanner.setInput("   abcddef   \"ABC\" 123445E+777 12345E+ 1234.133E+19  \"aaaaaaa123\" ");
	scanner.setWhiteSpaceSkipFlag();
	scanner.setStringscannFlag();
	scanner.setNumberscannFlag();
	cout << scanner.nextToken() << endl;
	cout << scanner.nextToken()<<endl;
	cout << scanner.nextToken() << endl;
	cout << scanner.nextToken() << endl;
	cout << scanner.nextToken() << endl;
	cout << scanner.nextToken() << endl;
	cout << scanner.nextToken() << endl;
    return 0;
}

