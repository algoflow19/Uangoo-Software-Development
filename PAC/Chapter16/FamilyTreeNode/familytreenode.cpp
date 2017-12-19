#include "familytreenode.h"
#include<string>
#include<fstream>
#include<iostream>

using namespace std;


FamilyTreeNode::FamilyTreeNode(const std::string name)
{
    this->name=name;
    partent=NULL;
    YoungerBrother=NULL;
    OldestChild=NULL;
}

string FamilyTreeNode::getName() const
{
    return name;
}

void FamilyTreeNode::addChild(FamilyTreeNode *child)
{
    if(OldestChild==NULL){
        OldestChild=child;
        child->partent=this;
        return;
    }
    FamilyTreeNode* tmp=OldestChild;
    while(tmp->YoungerBrother!=NULL) tmp=tmp->YoungerBrother;
    tmp->YoungerBrother=child;
    child->partent=this;
}

FamilyTreeNode *FamilyTreeNode::getPartent() const
{
    return partent;
}

FamilyTreeNode *FamilyTreeNode::getChild(int index) const
{
    FamilyTreeNode* tmp=OldestChild;
    for(int i=0;i<index;i++)
        tmp=tmp->YoungerBrother;
    return tmp;
}

int FamilyTreeNode::countChild() const
{
    FamilyTreeNode* tmp=OldestChild;
    int count=0;
    while(tmp!=NULL){
        count++;
        tmp=tmp->YoungerBrother;
    }
    return count;
}

void FamilyTreeNode::ListChilde() const
{
    FamilyTreeNode* tmp=OldestChild;
    while(tmp!=NULL){
        cout<< tmp->name <<endl;
        tmp=tmp->YoungerBrother;
    }
}
