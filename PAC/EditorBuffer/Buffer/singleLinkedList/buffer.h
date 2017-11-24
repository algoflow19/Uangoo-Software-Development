#pragma once

/*
*
* This is the single pointer version of buffer   -> S
*
*/

#include<string>


/* We use chain list to implment this class */
class Buffer
{
public:
	Buffer();
	~Buffer();

	void moveCursorForware();
	void moveCursorBackware();
	void moveCursorStart();
	void moveCursorEnd();

	void insertChar(char word);
	void delChar();
	void backspaceChar();

	std::string getText() const;
	int getCursor() const;

private:

	struct node {
		char word;
		node* Nlink;
		//node* Blink;
	};

	node* start;
	node* cursor;


};
