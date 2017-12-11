#include "StringMap.h"



StringMap::StringMap()
{
	Nbuckets = INIT_NUM;
	bucket = new Cell[Nbuckets];
	pairNum = 0;
	for (int i = 0; i < Nbuckets; i++)
		bucket[i].isUsing = false;
}


StringMap::~StringMap()
{
	delete[] bucket;
}

std::string StringMap::get(const std::string & key) const
{
	int index = findCell(hashCode(key) % Nbuckets, key);
	if (index == -1)
		return "";
	return bucket[index].value;
}

void StringMap::put(const std::string & key, const std::string & value)
{
	int hashNum = hashCode(key) % Nbuckets;
	int index = findCell(hashNum, key);
	if (index != -1)
		bucket[index].value = value;
	else {
		for (int i = 0; i < Nbuckets; i++) {
			int tmpindex = (hashNum + i) % Nbuckets;
			if (bucket[tmpindex].isUsing == false) {  // "=" -> "==" , You made mistake by thinking when Coding!
				bucket[tmpindex].key = key;
				bucket[tmpindex].value = value;
				bucket[tmpindex].isUsing = true;
				pairNum++;
				if (double(pairNum) / Nbuckets > 0.7)
					rehash();
				return;
			}
		}
		std::cout << "program error!" << std::endl;
		return;
	}
}

void StringMap::clear()
{
	for (int i = 0; i < Nbuckets; i++) 
		bucket[i].isUsing = false;
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

int StringMap::findCell(int index,const std::string & key) const
{
	
	for (int i = 0; i < Nbuckets; i++) {
		if (bucket[(index + i) % Nbuckets].key == key&&bucket[(index + i) % Nbuckets].isUsing == true)
			return (index + i) % Nbuckets;
	}
	return -1;
}

void StringMap::rehash()
{
	pairNum = 0;
	Cell* oldBuckets = bucket;
	int oldNbuckets = Nbuckets;
	Nbuckets *= 2;
	bucket = new Cell[Nbuckets];
	
	for (int i = 0; i < Nbuckets; i++)
		bucket[i].isUsing = false;

	for (int i = 0; i < oldNbuckets; i++) {
		if (oldBuckets[i].isUsing) 
		{
			put(oldBuckets[i].key, oldBuckets[i].value);
			oldBuckets[i].isUsing = false;

			for (int index = 1;index < oldNbuckets; index++) 
			{
				int trueIndex = (i + index) % oldNbuckets;

				if (oldBuckets[trueIndex].key == oldBuckets[i].key&&
					oldBuckets[trueIndex].isUsing) 
				{
					put(oldBuckets[trueIndex].key,
						oldBuckets[trueIndex].value);
					oldBuckets[trueIndex].isUsing = false;
				}
			}

		}		
	}
	delete[] oldBuckets;
}

bool StringMap::containsKey(const std::string & key) const
{
	int index= findCell(hashCode(key) % Nbuckets, key);
	return index != -1;
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
	int index = findCell(hashCode(key) % Nbuckets, key);
	if (index==-1)
		put(key, value);
	else {
		for (int i = 1; i < Nbuckets; i++) {
			if (bucket[(i+index)%Nbuckets].isUsing == false) {
				bucket[(i + index) % Nbuckets].key = key;
				bucket[(i + index) % Nbuckets].value = bucket[index].value;
				bucket[(i + index) % Nbuckets].isUsing = true;
				bucket[index].value = value;
				pairNum++;
				if (double(pairNum) / Nbuckets > 0.7)
					rehash();
				bucket[0];
				bucket[1];
				bucket[2];
				bucket[3];
				bucket[4];
				bucket[5];
				bucket[6];
				bucket[7];
				bucket[8];
				bucket[9];
				bucket[10];
				bucket[11];
				bucket[12];
				return;
			}
		}
	}
}

void StringMap::remove(const std::string & key)
{
	int index = findCell(hashCode(key) % Nbuckets, key);
	if (index == -1)
		return;
	bucket[index].isUsing = false;
	/* Just added for the tmp value funtation */
	for (int i = 1; i < Nbuckets; i++) {
		int tmp = (index - i + Nbuckets) % Nbuckets;
		if (bucket[tmp].key == key&&bucket[tmp].isUsing == true) {
			bucket[index].value = bucket[tmp].value;
			bucket[index].isUsing = true;
			bucket[tmp].isUsing = false;
			break;
		}
	}
	pairNum--;
}
