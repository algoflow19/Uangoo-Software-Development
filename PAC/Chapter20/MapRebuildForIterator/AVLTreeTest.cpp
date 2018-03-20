#include <iostream>
#include <string>
#include"avl_balanced_tree.h"
#include"assert.h"
using namespace std;

typedef mapNode<int,int> IntNode;


int main() {

    AVL_Balanced_tree<IntNode,int> tree;
    for(int i=0;i<10;i++){
        IntNode* node=new IntNode;
        node->key=i;
        node->value=i;
        tree.insertNode(node);
    }
    tree.eraserNode(1);
    tree.eraserNode(3);
    tree.eraserNode(5);
    tree.eraserNode(7);
    tree.eraserNode(9);
    for(int i=0;i<10;i++){
        if(tree.getNode(i)!=NULL)
        cout<<tree.getNode(i)->value<<endl;
    }
    for(int i=11;i<15;i++){
        IntNode* node=new IntNode;
        node->key=i;
        node->value=i;
        tree.insertNode(node);
    }
    tree.eraserNode(13);
    for(int i=11;i<15;i++){
        if(tree.getNode(i)!=NULL)
        cout<<tree.getNode(i)->value<<endl;
    }
    tree.clear();
    assert(tree.size()==0);

    return 0;
}
