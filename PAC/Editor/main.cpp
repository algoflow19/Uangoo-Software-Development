#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include <cctype>
#include "editor.h"
using namespace std;

// This file 


int main() {
	
	Editor editor;
	while (true)
	{
		editor.loadUserInput();
		editor.doOperation();
		if (editor.shouldQuit()) break;
	}

	return 0;
}

