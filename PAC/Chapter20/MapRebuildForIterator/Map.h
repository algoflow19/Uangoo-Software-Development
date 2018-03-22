#ifndef map_h
#define map_h
#include"avl_balanced_tree.h"
#include "stack.h"
#include"error.h"
/* Using Balanced-tree to impelement the ordered map.*/


template<typename keyType,typename valueType>
struct mapNode
{
    keyType key;
    valueType value;
    int bf;
    mapNode* Left;
    mapNode* Right;
};


template<typename typeKey,typename typeValue>
class MyMap
{
public:


    MyMap();
    ~MyMap();

    typeValue get(const typeKey & key) ;
    void put(const typeKey & key, const typeValue & value);
    bool containsKey(const typeKey & key);
    unsigned int size() const;
    bool isEmpty() const;
    void remove(const typeKey & key);
    void clear();

    // This iterator implement stagey

    class iterator{
    public:
        iterator();
        bool operator==(const iterator& theOther)const{
            if(mp!=theOther.mp) error("Compare iterator from different container.");
            return index==theOther.index;
        }
        bool operator !=(const iterator& theOther) const{
            return !(*this==theOther);
        }
        typeKey& operator*(){
            if(index==-1) error("Can't reference the end iterator");
            return StoreStack.peek()->key;
        }
        typeKey* operator->(){  // pay attention to the return type.
            return &StoreStack.peek()->key;
        }

        iterator& operator++(){
            if(index==-1) error("Try to add the end iterator");
            if(StoreStack.size()==1&&StoreStack.peek()->Right==NULL){
                StoreStack.pop();
                this->index=-1;
                return *this;
            }
            auto tmp=StoreStack.pop();
            if(tmp->Right!=NULL)
                fillStack(tmp->Right);

            ++index;
            return *this;
        }

        iterator operator++(int){
            auto tmp=copy(*this);
            (*this)++;
            return tmp;
        }


    private:
        iterator(int index,MyMap<typeValue,typeKey> *mp){
            if(index==-1){
                this->index=-1;
                this->mp=mp;
            } else{
                this->mp=mp;
                this->index=0;
                fillStack(mp->tree.getRoot());
            }
        }

        MyMap<typeValue,typeKey>* mp;
        int index;
        Stack<mapNode<typeKey,typeValue>* > StoreStack;
        void fillStack( mapNode<typeKey,typeValue>* node){
            if(node==NULL) return;
            StoreStack.push(node);
            while(node->Left!=NULL){
                StoreStack.push(node->Left);
                node=node->Left;
            }
        }

        friend class MyMap;
    };
    iterator begin(){
        return iterator(0,this);
    }
    iterator end(){
        return iterator(-1,this);
    }

private:

    AVL_Balanced_tree< mapNode<typeKey,typeValue> ,typeKey> tree;

};


template<typename typeKey,typename typeValue>
MyMap<typeKey,typeValue>::MyMap()
{

}

template<typename typeKey,typename typeValue>
MyMap<typeKey,typeValue>::~MyMap()
{

}

template<typename typeKey,typename typeValue>
typeValue MyMap<typeKey,typeValue>::get(const typeKey &key)
{
    auto tmp=tree.getNode(key);
    if(tmp!=NULL)
    return tmp->value;
    return typeValue();
}

template<typename typeKey,typename typeValue>
void MyMap<typeKey,typeValue>::put(const typeKey &key, const typeValue &value)
{

    mapNode<typeKey,typeValue>* node= new mapNode<typeKey,typeValue>;
    node->value=value;
    node->key=key;
    tree.insertNode(node);
}

template<typename typeKey,typename typeValue>
bool MyMap<typeKey,typeValue>::containsKey(const typeKey &key)
{
    return tree.getNode(key)!=NULL;
}

template<typename typeKey,typename typeValue>
unsigned int MyMap<typeKey,typeValue>::size() const{
    return tree.size();
}
template<typename typeKey,typename typeValue>
bool MyMap<typeKey,typeValue>::isEmpty() const
{
    return size()==0;
}
template<typename typeKey,typename typeValue>
void MyMap<typeKey,typeValue>::remove(const typeKey &key)
{
    tree.eraserNode(key);
}
template<typename typeKey,typename typeValue>
void MyMap<typeKey,typeValue>::clear()
{
    tree.clear();
}

#endif
