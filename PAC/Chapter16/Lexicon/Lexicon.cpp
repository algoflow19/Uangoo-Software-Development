#include "Lexicon.h"
#include<fstream>
using namespace std;

Lexicon::Lexicon()
{
	head = new node;
	initList(head);
	count = 0;
}

Lexicon::Lexicon(std::string file)
{
	head = new node;
	initList(head);
	count = 0;
	addWordFormFile(file);
}


Lexicon::~Lexicon()
{
	clear();
	delete head;
}

int Lexicon::size() const
{
	return count;
}

bool Lexicon::isEmpty() const
{
	return count==0;
}

void Lexicon::add(std::string str)
{
	node* tmp = head;
	for (int i = 0; i < str.length(); i++) {
		node* & Next = tmp->list[str[i] - 'a'];
		if (Next == NULL) {
			Next = new node;
			initList(Next);
		}
		tmp = Next;
	}
	if (!tmp->isWord) {
		tmp->isWord = true;
		count++;
	}

}

void Lexicon::addWordFormFile(const std::string & file)
{
	ifstream infile;
	infile.open(file);
	string word;
	while (true)
	{
		getline(infile, word);
		if (infile.fail()) break;
		add(word);
	}
	infile.close();
}

bool Lexicon::contains(std::string word) const
{
	node* tmp = head;
	for (int i = 0; i < word.length(); i++) {
		node* Next = tmp->list[word[i] - 'a'];
		if (Next == NULL) return false;
		tmp = Next;
	}
	return tmp->isWord;
}

bool Lexicon::containsPrefix(std::string prefix) const
{
	node* tmp = head;
	for (int i = 0; i < prefix.length(); i++) {
		if (tmp->list[prefix[i] - 'a'] == NULL) return false;
		for (int index = 0; index < 26; index++) {
			if (tmp->list[index] != NULL&& index != prefix[i] - 'a')
				return false;
		}
		tmp = tmp->list[prefix[i] - 'a'];
	}
	return true;
}

void Lexicon::clear()
{
	doClear(head);
	head = new node;
	initList(head);
}

void Lexicon::initList(node *& pt)
{
	for (int i = 0; i <= 25; i++)
		pt->list[i] = NULL;
	pt->isWord = false;
}

void Lexicon::doClear(node *& pt)
{
	if (pt == NULL) return;
	for (int i = 0; i < 26; i++)
		doClear(pt->list[i]);
	delete pt;
	pt = NULL;
	count = 0;
}
