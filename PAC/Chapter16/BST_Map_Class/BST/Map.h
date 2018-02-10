#pragma once
#include<string>


template<typename typeKey,typename typeValue>
class Map
{
public:

	struct mapNode
	{
		typeKey key;
		typeValue value;
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

private:
	unsigned int number;
	mapNode* head;
	mapNode* & findMinNode(mapNode * &start) {
		if (start == NULL) return start;
		if (start->Left != NULL) return findMinNode(start->Left);
			return start;
	}

	typeValue Sear1chOrPut(const typeKey &Key, const typeValue &value);
	typeValue doSearchOrPut(const typeKey &Key, const typeValue &value, mapNode* &node);
	void doRemove(const typeKey &key, mapNode* &node);
	void doClear(mapNode* &node);
};

template<typename typeKey, typename typeValue>
inline Map<typeKey, typeValue>::Map()
{
	number = 0;
	head = NULL;
}

template<typename typeKey, typename typeValue>
inline Map<typeKey, typeValue>::~Map()
{
	clear();
}

template<typename typeKey, typename typeValue>
inline typeValue Map<typeKey, typeValue>::get(const typeKey & key)
{
	return Sear1chOrPut(key,typeValue());
}

template<typename typeKey, typename typeValue>
inline void Map<typeKey, typeValue>::put(const typeKey & key, const typeValue & value)
{
	Sear1chOrPut(key, value);
}

template<typename typeKey, typename typeValue>
inline bool Map<typeKey, typeValue>::containsKey(const typeKey & key) 
{
	return Sear1chOrPut(key, typeValue())!=typeValue();
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
	return;
}

template<typename typeKey, typename typeValue>
inline void Map<typeKey, typeValue>::clear()
{
	doClear(head);
	number = 0;
	head = NULL;
	return;
}







template<typename typeKey, typename typeValue>
inline typeValue Map<typeKey, typeValue>::Sear1chOrPut(const typeKey & Key, const typeValue & value)
{
	return doSearchOrPut(Key, value, head);
}

template<typename typeKey, typename typeValue>
inline typeValue Map<typeKey, typeValue>::doSearchOrPut(const typeKey & Key, const typeValue & value, mapNode *& node)
{
	if (node == NULL) {
		if (value == typeValue()) return typeValue();
		node = new mapNode;
		node->Right = NULL;
		node->Left = NULL;
		node->key = Key;
		node->value = value;
		number++;
		return value;
	}
	if (node->key == Key) {
		if (value == typeValue())
			return node->value;
		node->value = value;
		return value;
	}
	if (Key > node->key)
		return doSearchOrPut(Key, value, node->Right);
	return doSearchOrPut(Key, value, node->Left);
		
	return typeValue();
}


template<typename typeKey, typename typeValue>
inline void Map<typeKey, typeValue>::doRemove(const typeKey & key, mapNode * &node)
{
	if (node == NULL) return;
	if (key == node->key) {
		mapNode** result = &findMinNode(node->Right);

		if ((*result) == NULL) {
			mapNode* tmp = node;
			node = node->Left;
			delete tmp;
			number--;
			return;
		}
		else if ((*result) == node->Right) {
			node->key = (*result)->key;
			node->value = (*result)->value;
			mapNode* tmp = *result;
			(*result) = (*result)->Right;
			delete tmp;
			number--;
			return;
		}
		else {
			node->key = (*result)->key;
			node->value = (*result)->value;
			mapNode* tmp = *result;
			(*result) = (*result)->Right;
			delete tmp;
			number--;
			return;
		}
	}
	if (key > node->key) doRemove(key, node->Right);
	else doRemove(key, node->Left);
	return;
}

template<typename typeKey, typename typeValue>
inline void Map<typeKey, typeValue>::doClear(mapNode *& node)
{
	if (node == NULL) return;
	doClear(node->Right);
	doClear(node->Left);
	delete node;
}
