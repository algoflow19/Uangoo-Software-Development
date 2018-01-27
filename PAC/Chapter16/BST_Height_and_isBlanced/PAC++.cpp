#include<iostream>
#include<string>
#include"bst.h"
using namespace std;

int height(BSTNode * tree);
bool hasBinarySearchProperty(BSTNode* tree);
int doHasBinarySearchProperty(BSTNode* tree, bool &flag);

int main() {
	BSTNode* tree = loadTree("testfile");
	showTreeSturct(tree); 
	cout << height(tree) << endl;
	cout << hasBinarySearchProperty(tree) << endl;
	return 0;
}

int height(BSTNode * tree)
{
	if (tree == NULL) return -1;
	int left = height(tree->left);
	int right = height(tree->right);
	return (left >= right ? left : right) + 1;
}

bool hasBinarySearchProperty(BSTNode* tree) {
	bool flag = true;
	doHasBinarySearchProperty(tree, flag);
	return flag;
}

int doHasBinarySearchProperty(BSTNode* tree, bool &flag) {
	if (tree == NULL) return -1;
	int left = doHasBinarySearchProperty(tree->left,flag);
	int right = doHasBinarySearchProperty(tree->right,flag);
	if (left - right > 1 || left - right < -1)
		flag = false;
	return (left >= right ? left : right) + 1;

}