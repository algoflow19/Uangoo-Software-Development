#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include"buffer.h"
using namespace std;

// This file perform a simple Buffer class test!

int main() {
	Buffer buf;
	buf.insertChar('A');
	buf.insertChar('A');
	buf.insertChar('A');
	buf.insertChar('A');
	buf.insertChar('A');
	buf.insertChar('A');
	buf.insertChar('B');
	cout << buf.getCursor()<<endl;

	buf.moveCursorBackware();
	cout << buf.getCursor() << endl;
	buf.moveCursorStart();
	cout << buf.getCursor() << endl;
	buf.moveCursorForware();
	cout << buf.getCursor() << endl;
	buf.moveCursorEnd();
	cout << buf.getCursor() << endl;
	
	cout << " I\'m reach here!" << endl;
	return 0;
}
