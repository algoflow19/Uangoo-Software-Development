#ifndef FAMILYTREENODE_H
#define FAMILYTREENODE_H

#include<string>
#include<fstream>

class FamilyTreeNode
{
public:

    FamilyTreeNode(const std::string name);
    std::string getName() const;
    void addChild(FamilyTreeNode * child);
    FamilyTreeNode* getPartent() const;
    FamilyTreeNode* getChild(int index) const;
    int countChild() const;
    void ListChilde() const;

private:
    std::string name;
    FamilyTreeNode* partent;
    FamilyTreeNode* OldestChild;
    FamilyTreeNode* YoungerBrother;


};

#endif // FAMILYTREENODE_H
