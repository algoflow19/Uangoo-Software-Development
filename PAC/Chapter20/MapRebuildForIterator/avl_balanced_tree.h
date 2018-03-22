#ifndef AVL_BALANCED_TREE_H
#define AVL_BALANCED_TREE_H

#include<iostream>

// Still Can have a Node template here!


template<typename NodeType,typename keyType>
class AVL_Balanced_tree
{
public:
    AVL_Balanced_tree();
    ~AVL_Balanced_tree();
    NodeType* getNode(const keyType& key);

    /*
     * Method: insertNode(NodeType* node);
     * -----------------------------------
     * This method will referened the given node point,
     * so you should not destroy the node or release it
     * by yourself,this class will do maintain work for you.
     * Please note that modify key-value always cause unknow error.
     */
    void insertNode(NodeType* node);
    void insertNode(const keyType& key);
    NodeType* getRoot(){ return root; }
    void eraserNode(const keyType& key);
    void clear();
    void displayTree();
    int size() const;

private:

    void doDisPlay(std::string str,NodeType* &toSearch);
    NodeType* root;
    int count;

    int doEraserWork(NodeType* &toSearch,const keyType& key);
    int AVLReplaceAndFix(NodeType* &toSearch,NodeType* &toReplace);
    int AVLInsertNode(NodeType* &toSerach,NodeType* &toAdd);
    // fix balance operator
    void rotateLeft(NodeType* &node);
    void rotateRight(NodeType* &node);
    void fixLeftBalanced(NodeType* &node);
    void fixRightBalance(NodeType* &node);
    void fixDleteRightBalance(NodeType* &node);
    void fixDleteLeftBalance(NodeType* &node);

    NodeType* BSTsearch(NodeType* toSearch,const keyType& key);
    void releaseNode(NodeType* node);

};

template<typename NodeType,typename keyType>
AVL_Balanced_tree<NodeType,keyType>::~AVL_Balanced_tree()
{
    clear();
}

template<typename NodeType,typename keyType>
NodeType* AVL_Balanced_tree<NodeType,keyType>::getNode(const keyType &key)
{
    return BSTsearch(root,key);
}

template<typename NodeType,typename keyType>
void AVL_Balanced_tree<NodeType,keyType>::insertNode(NodeType *node)
{
    AVLInsertNode(root,node);
}

template<typename NodeType,typename keyType>
void AVL_Balanced_tree<NodeType,keyType>::insertNode(const keyType &key)
{
    NodeType* node;
    node->key=key;
    insertNode(node);
}

template<typename NodeType,typename keyType>
void AVL_Balanced_tree<NodeType,keyType>::eraserNode(const keyType &key)
{
    doEraserWork(root,key);
}


template<typename NodeType,typename keyType>
AVL_Balanced_tree<NodeType,keyType>::AVL_Balanced_tree(){
    root=NULL;
    count=0;
}


template<typename NodeType,typename keyType>
void AVL_Balanced_tree<NodeType,keyType>::clear(){
    releaseNode(root);
    root=NULL;
}

template<typename NodeType,typename keyType>
void AVL_Balanced_tree<NodeType,keyType>::displayTree()
{
    if(root==NULL) return;
    std::string str="";
    doDisPlay(str,root);
}

template<typename NodeType,typename keyType>
int AVL_Balanced_tree<NodeType,keyType>::AVL_Balanced_tree::size() const
{
    return count;
}

template<typename NodeType,typename keyType>
void AVL_Balanced_tree<NodeType,keyType>::doDisPlay(std::__cxx11::string str, NodeType *&toSearch)
{
    if(toSearch->Right!=NULL) doDisPlay(str+">> ",toSearch->Right);
    if(toSearch->Left!=NULL) doDisPlay(str+"<< ",toSearch->Left);
    std::cout<<str<<toSearch->key<<std::endl;
}

template<typename NodeType,typename keyType>
int AVL_Balanced_tree<NodeType,keyType>::AVLReplaceAndFix(NodeType *&toSearch, NodeType *&toReplace)
{
    if(toSearch->Right==NULL){
        NodeType* tmp=toSearch;
        toSearch=toSearch->Left;
        tmp->Right=toReplace->Right;
        tmp->Left=toReplace->Left;
        tmp->bf=toReplace->bf;
        delete toReplace;
        --count;
        toReplace=tmp;
        return -1;
    }
    int delate=AVLReplaceAndFix(toSearch->Right,toReplace);
    if(delate==0) return 0;
    switch(toSearch->bf){
    case 0: toSearch->bf=-1; return 0;
    case 1: toSearch->bf=0; return -1;
    case -1: fixLeftBalanced(toSearch); return 0;
    }
    return 0;
}

template<typename NodeType,typename keyType>
int AVL_Balanced_tree<NodeType,keyType>::doEraserWork(NodeType *&toSearch, const keyType &key)
{
    if(toSearch==NULL){
        std::cerr<<"eraserNode: Key not found!"<<std::endl; return 0;
    }
    int delta=1;
    if(toSearch->key==key){
        if(toSearch->Left==NULL){
            NodeType *tmp=toSearch;
            toSearch=toSearch->Right;
            delete tmp;
            --count;
            return -1;
        }
        delta=AVLReplaceAndFix(toSearch->Left,toSearch);
    } else if(key<toSearch->key){
        delta=doEraserWork(toSearch->Left,key);
    }
    if(delta!=1){
        if(delta==0) return 0;
        switch(toSearch->bf){
        case -1: toSearch->bf=0; return -1;
        case 0:  toSearch->bf=1; return 0;
        case 1:  fixDleteRightBalance(toSearch); return 0;
        }
    }
    delta=doEraserWork(toSearch->Right,key);
    if(delta==0) return 0;
    switch(toSearch->bf){
    case -1: fixDleteLeftBalance(toSearch); return 0;
    case 0:  toSearch->bf=-1; return 0;
    case 1:  toSearch->bf=0; return -1;
    }
    return 0;
}

template<typename NodeType,typename keyType>
int AVL_Balanced_tree<NodeType,keyType>::AVLInsertNode(NodeType *&toSerach, NodeType *&toAdd)
{
    int delta=0;
    if(toSerach == NULL){
        toSerach=toAdd;
        toSerach->Right=toSerach->Left=NULL;
        toSerach->bf=0;
        count++;
        return 1;
    }
    if(toAdd->key==toSerach->key){
        NodeType* tmp=toSerach;
        toAdd->Left=toSerach->Left;
        toAdd->Right=toSerach->Right;
        toAdd->bf=toSerach->bf;
        toSerach=toAdd;
        delete tmp;
        return delta;
    }
    if(toAdd->key>toSerach->key){
        delta=AVLInsertNode(toSerach->Right,toAdd);
        if(delta!=0)
        switch(toSerach->bf){
        case 0: toSerach->bf=1; return 1;
        case -1: toSerach->bf=0; return 0;
        case 1: fixRightBalance(toSerach); return 0;
        }
    } else {
        delta=AVLInsertNode(toSerach->Left,toAdd);
        if(delta!=0)
        switch(toSerach->bf){
        case 0: toSerach->bf=-1; return 1;
        case 1: toSerach->bf=0; return 0;
        case -1: fixLeftBalanced(toSerach); return 0;
        }
    }
    return 0;
}

template<typename NodeType,typename keyType>
void AVL_Balanced_tree<NodeType, keyType>::rotateLeft(NodeType *&node)
{
    NodeType* rightNode=node->Right;
    node->Right=rightNode->Left;
    rightNode->Left=node;
    node=rightNode;
}

template<typename NodeType,typename keyType>
void AVL_Balanced_tree<NodeType, keyType>::rotateRight(NodeType *&node)
{
    NodeType* leftNode=node->Left;
    node->Left=leftNode->Right;
    leftNode->Right=node;
    node=leftNode;
}

// Do understood this codes.
template<typename NodeType,typename keyType>
void AVL_Balanced_tree<NodeType, keyType>::fixLeftBalanced(NodeType *&node)
{
    NodeType* leftNode=node->Left;
    if(node->bf!=leftNode->bf){
        int oldBF=leftNode->Right->bf;
        rotateLeft(leftNode);
        rotateRight(node);
        node->bf=0;
        switch(oldBF){
        case 0: node->Left=node->Right=0; break;
        case 1: node->Left->bf=-1; node->Right->bf=0; break;
        case -1:node->Left->bf=0;node->Right->bf=1; break;
        }
    } else{
        rotateRight(node);
        node->bf=node->Right->bf=0;
    }
}

template<typename NodeType,typename keyType>
void AVL_Balanced_tree<NodeType, keyType>::fixRightBalance(NodeType *&node)
{
    NodeType* rightNode=node->Right;
    if(rightNode->bf!=node->bf){
        int oldBF=rightNode->Left->bf;
        rotateRight(rightNode);
        rotateLeft(node);
        node->bf=0;
        switch(oldBF){
        case 0: node->Left->bf=node->Right->bf=0; break;
        case 1: node->Left->bf=-1; node->Right->bf=0; break;
        case -1: node->Left->bf=0; node->Right->bf=1; break;
        }
    }   else {
            rotateLeft(node);
            node->Left->bf=node->bf=0;
    }
}

template<typename NodeType,typename keyType>
void AVL_Balanced_tree<NodeType, keyType>::fixDleteRightBalance(NodeType *&node)
{
    auto rightNode=node->Right;
    if(rightNode->bf==-1){
        int oldBF=rightNode->Left->bf;
        rotateRight(rightNode);
        rotateLeft(node);
        node->bf=0;
        switch(oldBF){
        case 0: node->Left->bf=node->Right->bf=0; break;
        case 1: node->Left->bf=-1; node->Right->bf=0; break;
        case -1: node->Left->bf=0; node->Right->bf=1; break;
        }
    }   else {

            rotateLeft(node);
            node->Left->bf=node->bf=0;
    }
}
template<typename NodeType,typename keyType>
void AVL_Balanced_tree<NodeType, keyType>::fixDleteLeftBalance(NodeType *&node)
{
    NodeType* leftNode=node->Left;
    if(leftNode->bf==1){
        int oldBF=leftNode->Right->bf;
        rotateLeft(leftNode);
        rotateRight(node);
        node->bf=0;
        switch(oldBF){
        case 0: node->Left=node->Right=0; break;
        case 1: node->Left->bf=-1; node->Right->bf=0; break;
        case -1:node->Left->bf=0;node->Right->bf=1; break;
        }
    } else{
        rotateRight(node);
        node->bf=node->Right->bf=0;
    }
}


template<typename NodeType,typename keyType>
NodeType *AVL_Balanced_tree<NodeType,keyType>::BSTsearch(NodeType *toSearch, const keyType &key)
{
    if(toSearch==NULL) return NULL;
    if(toSearch->key==key) return toSearch;
    if(toSearch->key<key) return BSTsearch(toSearch->Right,key);
    return BSTsearch(toSearch->Left,key);
}

template<typename NodeType,typename keyType>
void AVL_Balanced_tree<NodeType,keyType>::releaseNode(NodeType* node){
    if(node==NULL) return;
    releaseNode(node->Right);
    releaseNode(node->Left);
    delete node;
    --count;
}

#endif // AVL_BALANCED_TREE_H
