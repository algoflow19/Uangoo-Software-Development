#pragma once
#include<string>

struct node
{
	node* list[26];
	bool isWord;
};

class Lexicon
{
public:
	Lexicon();
	Lexicon(std::string file);
	~Lexicon();
	int size() const;
	bool isEmpty() const;
	void add(std::string str);
	void addWordFormFile(const std::string & file);
	bool contains(std::string word) const;
	bool containsPrefix(std::string prefix) const;
	void clear();
private:
	node* head;
	int count;
	void initList(node* & pt);
	void doClear(node* & pt);
};

