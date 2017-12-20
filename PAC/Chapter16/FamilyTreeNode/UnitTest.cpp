#include<iostream>
#include<string>
#include"familytreenode.h"
using namespace std;

void displayFamilyTreeNode(FamilyTreeNode * tree);
FamilyTreeNode* readFamilyTree(string fileName);
FamilyTreeNode* findPeole(FamilyTreeNode *tree, string name);
void DodisplayFamilyTreeNode(FamilyTreeNode* tree,string prefix);
FamilyTreeNode* commonAncestor(FamilyTreeNode* p1, FamilyTreeNode* p2);

static const int MAX_HEIGHT = 5;

int main() {


	FamilyTreeNode* tmp=readFamilyTree("testfile");
	displayFamilyTreeNode(tmp);
	FamilyTreeNode* p1 = findPeole(tmp, "Adela");
	FamilyTreeNode* p2 = findPeole(tmp, "Stephen");
	cout << commonAncestor(p1, p2)->getName() << endl;

	return 0;
}


FamilyTreeNode* readFamilyTree(string fileName) {
	fstream infile;
	infile.open(fileName);
	string tmpstr;
	getline(infile, tmpstr);
	FamilyTreeNode* tree = new FamilyTreeNode(tmpstr);
	while (true) {
		string line;
		getline(infile, line);
		if (infile.fail()) break;

		int cutPos = line.find(":");
		string child = line.substr(0, cutPos);
		string partent = line.substr(cutPos + 1);

		findPeole(tree, partent)->addChild(new FamilyTreeNode(child));
	}
	return tree;
}

FamilyTreeNode* findPeole(FamilyTreeNode* tree, string name) {
	if (tree->getName() == name)
		return tree;
	for (int i = 0; i<tree->countChild(); i++) {
		FamilyTreeNode* tmp = tree->getChild(i);
		if ((tmp=findPeole(tmp, name)) != NULL)
			return tmp;
	}
	return NULL;
}

void displayFamilyTreeNode(FamilyTreeNode * tree) {
	DodisplayFamilyTreeNode(tree, "");
}

void DodisplayFamilyTreeNode(FamilyTreeNode* tree, string prefix) {
	if (tree != NULL)
		cout << prefix << tree->getName() << endl;
	for (int i = 0; i<tree->countChild(); i++) {
		FamilyTreeNode* tmp = tree->getChild(i);
		DodisplayFamilyTreeNode(tmp, prefix+"  ");
	}
}

FamilyTreeNode* commonAncestor(FamilyTreeNode* p1, FamilyTreeNode* p2) {
	FamilyTreeNode** List1 = new FamilyTreeNode*[MAX_HEIGHT];
	for (int i = 0; ; i++) {
		if (p1->getPartent() != NULL) {
			List1[i] = p1->getPartent();
			p1 = List1[i];
		}
		else {
			List1[i] = NULL;
			break;
		}
	}

	while (p2->getPartent()!=NULL)
	{
		for (int i = 0; ; i++) {
			if (List1[i] == NULL) break;
			if (List1[i] == p2->getPartent()) {
				delete[] List1;
				return p2->getPartent();
			}
		}
		p2 = p2->getPartent();
	}

	return NULL;
}