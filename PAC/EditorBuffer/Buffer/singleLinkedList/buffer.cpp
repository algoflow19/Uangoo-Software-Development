#include "buffer.h"
#include<iostream>
using namespace std;

/*
*
* This is the single pointer version of buffer   -> S
*
*/

Buffer::Buffer()
{

	start = cursor = new node;
	start->Nlink = NULL;

}

Buffer::~Buffer()
{
	node *tmp = start;
	while (tmp!=NULL){
		node* nextNode = tmp->Nlink;
		delete  tmp;
		tmp = nextNode;
	}

}

void Buffer::moveCursorForware()
{
	if (cursor->Nlink != NULL)
		cursor = cursor->Nlink;
}

void Buffer::moveCursorBackware()
{
	if (cursor != start) {   // I've noticed that I have many ways to perform the same logic operation.
		node* tmpP;
		tmpP = start;
		while (tmpP->Nlink != cursor)
			tmpP = tmpP->Nlink;
		cursor = tmpP;
	}
	else
		cout << "Caution: You has reach the start!" << endl;
}

void Buffer::moveCursorStart()
{
	cursor = start;
}

void Buffer::moveCursorEnd()
{
	if (cursor->Nlink == NULL) {
		cout << "Caution: you has reach the end!" << endl;
		return;
	}
	node* tmpP = cursor;
	while (tmpP->Nlink != NULL)
		tmpP = tmpP->Nlink;
	cursor = tmpP;
}

void Buffer::insertChar(char word)
{
	node* insertNode = new node;
	insertNode->word = word;
	insertNode->Nlink = cursor->Nlink;
	cursor->Nlink = insertNode;
	cursor = insertNode;
}

void Buffer::delChar()   //
{
	if (cursor->Nlink != NULL) {
		node* oldNode = cursor->Nlink;
		cursor->Nlink = cursor->Nlink->Nlink;
		delete oldNode;
		return;
	}
	cout << " The cursor is at the end of text!" << endl;
}

void Buffer::backspaceChar() // Normal text edit
{
	if (cursor == start) {
		cout << " Caution: The text area has been empty!" << endl;
		return;
	}
	moveCursorBackware();
	node* tmpP = cursor->Nlink;
	cursor->Nlink = tmpP->Nlink;
	delete tmpP;
}

string Buffer::getText() const
{
	string text = "";
	string tmp = " ";
	for (node* tmpP = start->Nlink; tmpP != NULL; tmpP = tmpP->Nlink) {
		tmp[0] = tmpP->word;
		text += tmp;
	}
	return text;
}

int Buffer::getCursor() const
{
	int nChars = 0;
	for (node* tmpP = start; tmpP != cursor; tmpP = tmpP->Nlink)
		nChars++;
	return nChars;
}

