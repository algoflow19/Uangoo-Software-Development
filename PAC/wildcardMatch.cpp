#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

bool wildcardMatch(string filename, string pattern);
bool doneWildcardMatch(string filename, string pattern,int fPos,int sPos);

int main() {

	cout << wildcardMatch("US.txt", "*.*") << endl;
	cout << wildcardMatch("test", "*.*") << endl;
	cout << wildcardMatch("test.h", "test.?") << endl;
	cout << wildcardMatch("test.cpp", "test.?") << endl;
	cout << wildcardMatch("x", "??*") << endl;
	cout << wildcardMatch("yy", "??**") << endl;
	cout << wildcardMatch("zzz", "??*") << endl;

}

bool wildcardMatch(string filename, string pattern) {
	int fPos, pPos;
	fPos = pPos = 0;
	string editedPattern = pattern;
	if (editedPattern.length() >= 2)
		while (true) {
			if (editedPattern[editedPattern.length() - 1] == '*') {
				if (editedPattern[editedPattern.length() - 1] == editedPattern[editedPattern.length() - 2]) {
					editedPattern.erase(editedPattern.length() - 1);
				}
				else break;
			}
			else break;
		};

	return doneWildcardMatch(filename, editedPattern, fPos, pPos);

}

bool doneWildcardMatch(string filename, string pattern, int fPos, int pPos) {
	if (fPos == filename.length() && pPos == pattern.length())
		return true;
	if (pPos == (pattern.length() - 1))
		if (pattern[pPos] == '*')
			return true;
	if (fPos == filename.length() || pPos == pattern.length())
		return false;

	switch (pattern[pPos]) {
	case '?':
		pPos++; fPos++;
		if (doneWildcardMatch(filename, pattern, fPos, pPos))
			return true;
		pPos--; fPos--;
		break;
	case '*':
		pPos++;
		if (doneWildcardMatch(filename, pattern, fPos, pPos))
			return true;
		pPos--;
		pPos++; fPos++;
		if (doneWildcardMatch(filename, pattern, fPos, pPos))
			return true;
		pPos--; fPos--;
		fPos++;
		if (doneWildcardMatch(filename, pattern, fPos, pPos))
			return true;
		fPos--;
		break;
	default:
		if (filename[fPos] == pattern[pPos]) {
			pPos++; fPos++;
			if(doneWildcardMatch(filename, pattern, fPos, pPos))
				return true;
			pPos--; fPos--;
			break;
		}

	}
	return false;
}
