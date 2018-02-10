#pragma once
#include<string>
#include<iostream>
#define DEBUG


// This is the Map Class Implemented by black-red tree!
enum nodeColor { red,black };


template<typename typeKey,typename typeValue>
class Map
{
public:

	struct mapNode
	{
		typeKey key;
		typeValue value;
		nodeColor color;
		mapNode* Left;
		mapNode* Right;
	};

	Map();
	~Map();
	
	typeValue get(const typeKey & key) ;
	void put(const typeKey & key, const typeValue & value);
	bool containsKey(const typeKey & key);
	unsigned int size() const;
	bool isEmpty() const;
	void remove(const typeKey & key);
	void clear();

#ifdef DEBUG
	void displayTree() {
		doDisplay(head, "");
	}

#endif

private:
	unsigned int number;
	mapNode* head;
	typeValue doSearch(const typeKey & key, mapNode* & node) const;
	int doInsert(const typeKey & key, const typeValue & value,mapNode* & node);

	bool doRemove(const typeKey &key, mapNode* &node);
	void doClear(mapNode* &node);
	void rotateLeft(mapNode* & node);
	void rotateRight(mapNode*& node);

	void fixLLBalance(mapNode*& node);
	void fixRRBalance(mapNode*& node);
	void fixLRBalance(mapNode*& node);
	void fixRLBalance(mapNode*& node);
	void fixDuelRed(mapNode*& node);

	void doDisplay(mapNode*& node, std::string pos);
};

template<typename typeKey, typename typeValue>
inline Map<typeKey, typeValue>::Map()
{
	head = NULL;
	number = 0;
}

template<typename typeKey, typename typeValue>
inline Map<typeKey, typeValue>::~Map()
{
	doClear(head);
}

template<typename typeKey, typename typeValue>
inline typeValue Map<typeKey, typeValue>::get(const typeKey & key) 
{
	return doSearch(key,head);
}

template<typename typeKey, typename typeValue>
inline void Map<typeKey, typeValue>::put(const typeKey & key, const typeValue & value)
{
	doInsert(key, value, head);
	head->color = black;
}


template<typename typeKey, typename typeValue>
inline bool Map<typeKey, typeValue>::containsKey(const typeKey & key)
{
	return doSearch(key, head) != typeValue();
}

template<typename typeKey, typename typeValue>
inline unsigned int Map<typeKey, typeValue>::size() const
{
	return number;
}

template<typename typeKey, typename typeValue>
inline bool Map<typeKey, typeValue>::isEmpty() const
{
	return number==0;
}

template<typename typeKey, typename typeValue>
inline void Map<typeKey, typeValue>::remove(const typeKey & key)
{
	doRemove(key, head);
}

template<typename typeKey, typename typeValue>
inline void Map<typeKey, typeValue>::clear()
{
	doClear(head);
	number = 0;
	head = NULL;
}

template<typename typeKey, typename typeValue>
inline typeValue Map<typeKey, typeValue>::doSearch(const typeKey & key,  mapNode* & node) const
{
	if (node == NULL) return typeValue();
	if (key == node->key) return node->value;
	if (key > node->key) return doSearch(key, node->Right);
	else return doSearch(key, node->Left);

}

template<typename typeKey, typename typeValue>
inline int Map<typeKey, typeValue>::doInsert(const typeKey & key, const typeValue & value, mapNode *& node)
{
	if (node == NULL) {
		node = new mapNode;
		node->color = red;
		node->Left = node->Right = NULL;
		node->key = key;
		node->value = value;
		number++;
		return 0;
	}
	if (node->key == key) {
		node->value = value;
		return 0;
	}

	if (key > node->key) {
		int status = doInsert(key, value, node->Right);
		if (node->Right->color == red)
			if (node->Left==NULL||node->Left->color == black)
				switch (status)
				{
				case 1:
					fixRRBalance(node);
					return 1;
				case 0:
					return 1;
				case -1:
					fixRLBalance(node);
					return 1;
				default:
					return 0;
				}
			else
			{
				fixDuelRed(node);
			}
		return 0;
		}

	if (key < node->key) {
		int status = doInsert(key, value, node->Left);
		if (node->Left->color == red)
			if (node->Right == NULL || node->Right->color == black)
				switch (status)
				{
				case 1:
					fixLRBalance(node);
					return 1;
				case 0:
					return -1;
				case -1:
					fixLLBalance(node);
					return 1;
				default:
					return 0;
				}
			else
			{
				fixDuelRed(node);
			}
		return 0;
	}

	}

/*
template<typename typeKey, typename typeValue>
inline bool Map<typeKey, typeValue>::doRemove(const typeKey & key, mapNode *& node)
{
	if (node == NULL) return false;
	if (node->key == key) {
		if (node->Right != NULL) {
			mapNode** tmp = &node->Right;
			while ((*tmp)->Left!=NULL)
				tmp = &tmp->Left;
			if((*tmp)->Right!=NULL)
			mapNode* tmpNode = (*tmp)->Right;
				
		}
	}
}

*/


template<typename typeKey, typename typeValue>
inline bool Map<typeKey, typeValue>::doRemove(const typeKey & key, mapNode *& node)
{
	return false;
}

template<typename typeKey, typename typeValue>
inline void Map<typeKey, typeValue>::doClear(mapNode *& node)
{
	if (node == NULL) return;
	doClear(node->Right);
	doClear(node->Left);
	delete node;
	node = NULL;
}

template<typename typeKey, typename typeValue>
	inline void Map<typeKey, typeValue>::rotateLeft(mapNode *& node)
	{
		mapNode* toRotate = node->Right;
		node->Right = toRotate->Left;
		toRotate->Left = node;
		node = toRotate;
	}
	template<typename typeKey, typename typeValue>
	inline void Map<typeKey, typeValue>::rotateRight(mapNode *& node)
	{
		mapNode* toRotate = node->Left;
		node->Left = toRotate->Right;
		toRotate->Right = node;
		node = toRotate;
	}

	template<typename typeKey, typename typeValue>
	inline void Map<typeKey, typeValue>::fixLLBalance(mapNode *& node)
	{
		rotateRight(node);
		node->color = black;
		node->Right->color = red;
	}

	template<typename typeKey, typename typeValue>
	inline void Map<typeKey, typeValue>::fixRRBalance(mapNode *& node)
	{
		rotateLeft(node);
		node->color = black;
		node->Left->color = red;
	}

	template<typename typeKey, typename typeValue>
	inline void Map<typeKey, typeValue>::fixLRBalance(mapNode *& node)
	{
		rotateLeft(node->Left);
		rotateRight(node);
		node->color = black;
		node->Right->color = red;
	}

	template<typename typeKey, typename typeValue>
	inline void Map<typeKey, typeValue>::fixRLBalance(mapNode *& node)
	{
		rotateRight(node->Right);
		rotateLeft(node);
		node->color = black;
		node->Left->color = red;
	}

	template<typename typeKey, typename typeValue>
	inline void Map<typeKey, typeValue>::fixDuelRed(mapNode *& node)
	{
		node->Right->color = node->Left->color = black;
		node->color = red;
	}


template<typename typeKey, typename typeValue>
inline void Map<typeKey, typeValue>::doDisplay(mapNode *& node, std::string pos)
{
	if (node == NULL) return;
	doDisplay(node->Right, pos + ">");
	std::cout << "The pos is" << pos << "|| " << ((node->color == red) ? "RED" : "BLACK") <<"     "<<node->key<< std::endl;
	doDisplay(node->Left, pos + "<");
}
