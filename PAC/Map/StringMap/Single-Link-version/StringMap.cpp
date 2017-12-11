#include "StringMap.h"



StringMap::StringMap()
{
	Nbuckets = INIT_NUM;
	bucket = new Cell*[Nbuckets];
	for (int i = 0; i < Nbuckets; i++)
		bucket[i] = NULL;
	pairNum = 0;
}


StringMap::~StringMap()
{
	clear();
	delete[] bucket;
}

std::string StringMap::get(const std::string & key) const
{
	Cell* tmp = findCell(hashCode(key) % Nbuckets, key);
	if (tmp != NULL)
		return tmp->value;
	return "";
}

void StringMap::put(const std::string & key, const std::string & value)
{
	int hashNum = hashCode(key) % Nbuckets;
	Cell* tmp = findCell(hashNum, key);
	if (tmp != NULL)
		tmp->value = value;
	else {
		Cell* oldCell = bucket[hashNum];
		bucket[hashNum] = new Cell;
		bucket[hashNum]->key = key;
		bucket[hashNum]->value = value;
		bucket[hashNum]->nextCell = oldCell;
		pairNum++;
		if (double(pairNum) / Nbuckets > REHASH_THRESHOLD)
			rehash();
	}

}

void StringMap::clear()
{
	for (int i = 0; i < Nbuckets; i++) {
		while (bucket[i]!=NULL)
		{
			Cell* tmp = bucket[i];
			bucket[i] = tmp->nextCell;
			delete tmp;
		}
	}
	pairNum = 0;
}

/*
* Implementation notes: hashCode
* ------------------------------
* This function takes a string key and uses it to derive a hash code,
* which is nonnegative integer related to the key by a deterministic
* function that distributes keys well across the space of integers.
* The specific algorithm used here is called djb2 after the initials
* of its inventor, Daniel J. Bernstein, Professor of Mathematics at
* the University of Illinois at Chicago.
*/

const int HASH_SEED = 5381;               /* Starting point for first cycle */
const int HASH_MULTIPLIER = 33;           /* Multiplier for each cycle      */
const int HASH_MASK = unsigned(-1) >> 1;  /* The largest positive integer   */

int StringMap::hashCode(const std::string & key) const
{
	unsigned hash = HASH_SEED;
	int n = key.length();
	for (int i = 0; i < n; i++) {
		hash = HASH_MULTIPLIER * hash + key[i];
	}
	return int(hash & HASH_MASK);
}

StringMap::Cell * StringMap::findCell(int index,const std::string & key) const
{
	Cell* target = bucket[index];
	while (target != NULL&&target->key != key)  
		target = target->nextCell;
	return target;
}

void StringMap::rehash()
{
	pairNum = 0;
	Cell** oldBuckets = bucket;
	int oldNbuckets = Nbuckets;
	Nbuckets *= 2;
	bucket = new Cell*[Nbuckets];
	for (int i = 0; i < Nbuckets; i++)
		bucket[i] = NULL;
	for (int i = 0; i < oldNbuckets; i++) {
		Cell* tmp = oldBuckets[i];
		while (tmp!=NULL)
		{
			put(tmp->key, tmp->value);
			Cell* readyToRemove = tmp;
			tmp = tmp->nextCell;
			delete readyToRemove;
		}
	}
	delete[] oldBuckets;
}

bool StringMap::containsKey(const std::string & key) const
{
	Cell* tmp = findCell(hashCode(key) % Nbuckets, key);
	return tmp != NULL;
}

int StringMap::size() const
{
	return pairNum;
}

bool StringMap::isEmpty() const
{
	return pairNum==0;
}

void StringMap::add(const std::string & key, const std::string & value)
{
	Cell* tmp = findCell(hashCode(key) % Nbuckets, key);
	if (tmp == NULL)
		put(key, value);
	else {
		Cell *follingCell=tmp->nextCell;
		tmp->nextCell = new Cell;
		tmp->nextCell->value = tmp->value;
		tmp->nextCell->key = tmp->key;
		tmp->nextCell->nextCell = follingCell;
		tmp->value = value;
		pairNum++;
	}
}

void StringMap::remove(const std::string & key)
{
	Cell* tmp = findCell(hashCode(key) % Nbuckets, key);
	if (tmp != NULL) {
		if (tmp->nextCell == NULL) {
			delete tmp;
		}
		else
		{
			Cell* cellToBeRemove = tmp->nextCell;
			tmp->key = cellToBeRemove->key;
			tmp->value = cellToBeRemove->value;
			tmp->nextCell = cellToBeRemove->nextCell;
			delete cellToBeRemove;
		}
		pairNum--;
	}
}
