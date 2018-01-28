#pragma once
#include<string>
class MorseCode
{
public:
	MorseCode();
	~MorseCode();
	std::string getMorseCodeLetter(std::string code) const;

private:

	struct MorseNode {

		std::string letter;
		MorseNode* Left;
		MorseNode* Right;
	};
	MorseNode* head;
	void buildMorseCodeTree(const  std::string  & letter,  std::string & code, MorseNode* &Node);
	void DeleteTree(MorseNode* Node);
	std::string doGetMorseCodeLetter(std::string code, MorseNode* Node) const;
};

