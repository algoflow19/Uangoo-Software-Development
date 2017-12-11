#pragma once
#include<iostream>

class StringMap
{
public:
	
	StringMap();
	~StringMap();
	std::string get(const std::string & key) const;
	void put(const std::string & key, const std::string & value);
	void clear();
	bool containsKey(const std::string & key) const;
	int size() const;
	bool isEmpty() const;
	void add(const std::string & key, const std::string & value);
	void remove(const std::string & key);


private:

	static const int INIT_NUM = 13;
	const double REHASH_THRESHOLD = 0.7;

	struct Cell
	{
		std::string key;
		std::string value;
		Cell* nextCell;
	};

	Cell ** bucket;
	int Nbuckets;
	int pairNum;
	int hashCode(const std::string & key)  const;
	Cell *findCell(int index,const std::string & key) const;
	void rehash();
};

