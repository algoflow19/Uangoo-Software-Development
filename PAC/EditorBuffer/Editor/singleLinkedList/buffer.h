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
	void copy(int count);
	void paste();
	void insertChar(char word);
	void delChar();
	void backspaceChar();
	bool search(std::string str);

	std::string getText() const;
	int getCursor() const;

private:

	struct node {
		char word;
		node* Nlink;
		//node* Blink;
	};
	bool isThisPlace(node * tmpNode,std::string str) const;
	std::string copyStore;
	node* start;
	node* cursor;

};
