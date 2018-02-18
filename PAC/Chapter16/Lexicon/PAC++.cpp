#include<iostream>
#include<string>
#include<assert.h>
#include"Lexicon.h"

using namespace std;

int main() {
	
	Lexicon Lex("testfile");
	assert(Lex.contains("qwe"));
	assert(Lex.contains("asd"));
	assert(Lex.contains("zxc"));
	assert(Lex.contains("rty"));
	assert(Lex.size() == 9);
	assert(!Lex.contains("kk"));
	Lex.add("kk");
	assert(Lex.contains("kk"));
	assert(!Lex.containsPrefix("q"));
	Lex.clear();
	assert(Lex.isEmpty());
	assert(!Lex.contains("kk"));
	Lex.add("kk");
	assert(Lex.contains("kk"));
	Lexicon Lex2;
	assert(Lex2.isEmpty());
	Lex2.addWordFormFile("testfile");
	assert(Lex2.contains("qwe"));
	Lex2.add("asd");
	assert(Lex2.contains("asd"));
	assert(Lex2.contains("zxc"));
	Lex2.clear();
	Lex2.add("asdf");
	Lex2.add("asdz");
	Lex2.add("asdq");
	Lex2.add("asdw");
	assert(Lex2.containsPrefix("asd"));
	assert(Lex2.containsPrefix("a"));
	assert(!Lex2.containsPrefix("sd"));
	assert(!Lex2.containsPrefix("asdf"));
	return 0;
}

