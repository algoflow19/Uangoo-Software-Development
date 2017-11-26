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
	copyStore = "";
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

void Buffer::moveCursorBackware()
{
	if (cursor->Nlink != NULL)
		cursor = cursor->Nlink;
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

void Buffer::copy(int count)
{
	copyStore = getText().substr(getCursor(), count);
}

void Buffer::paste()
{
	int length = copyStore.length();
	for (int i = 0; i < length; i++)
		insertChar(copyStore[i]);

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
	moveCursorForware();
	node* tmpP = cursor->Nlink;
	cursor->Nlink = tmpP->Nlink;
	delete tmpP;
}

bool Buffer::search(std::string str)
{
	node* tmpNode = start;

	while (tmpNode!=NULL)
	{
		if (isThisPlace(tmpNode,str)) {
			for (int i = 1; i <= str.length(); i++)
				tmpNode = tmpNode->Nlink;
			cursor = tmpNode;
			return true;
		}
		tmpNode = tmpNode->Nlink;
	}

	return false;
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

bool Buffer::isThisPlace(node * tmpNode, std::string str) const
{
	for (int i = 0; i < str.length(); i++) {
		if (tmpNode->Nlink == NULL) return false;
		tmpNode = tmpNode->Nlink;
		if (tmpNode->word != str[i]) return false;
	}
	return true;
}

