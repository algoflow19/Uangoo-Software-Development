#pragma once
template<typename typeKey,typename typeValue>

class Map
{
public:

	Map();
	~Map();

	typeValue get(const typeKey & key) const;
	void put(const typeKey & key, const typeValue & value);
	bool containsKey(const typeKey & key) const;

	unsigned int size() const;
	bool isEmpty() const;
	void remove(const typeKey & key);
	void clear();

private:
	unsigned int number;
	struct mapNode
	{
		typeKey key;
		typeValue value;
		mapNode* Left;
		mapNode* Right;
	};
	mapNode* head;
	typeValue Sear1chOrPut(const typeKey &Key, const typeValue &value = typeValue());
	typeValue doSearchOrPut(const typeKey &Key, const typeValue &value = typeValue(),const mapNode* &node=NULL);
	void doRemove(const typeKey &key, mapNode* node);

};

template<typename typeKey, typename typeValue>
inline Map<typeKey, typeValue>::Map()
{

}

template<typename typeKey, typename typeValue>
inline Map<typeKey, typeValue>::~Map()
{
	clear();
}

template<typename typeKey, typename typeValue>
inline typeValue Map<typeKey, typeValue>::get(const typeKey & key) const
{
	return Sear1chOrPut(key);
}

template<typename typeKey, typename typeValue>
inline void Map<typeKey, typeValue>::put(const typeKey & key, const typeValue & value)
{
	Sear1chOrPut(key, value);
}

template<typename typeKey, typename typeValue>
inline bool Map<typeKey, typeValue>::containsKey(const typeKey & key) const
{
	return Sear1chOrPut(key)==typeValue();
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
inline typeValue Map<typeKey, typeValue>::Sear1chOrPut(const typeKey & Key, const typeValue & value)
{
	return doSearchOrPut(key, value, head);
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
inline void Map<typeKey, typeValue>::doRemove(const typeKey & key, mapNode * node)
{

}



