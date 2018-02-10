#include<iostream>
#include<string>
#include"bst.h"
#include"Map.h"
#include<assert.h>



using namespace std;


int main() {
	Map<string, string> stringMap;
	stringMap.put("1", "2");
	stringMap.put("2", "3");
	stringMap.put("3", "4");
	stringMap.put("4", "5");
	stringMap.put("5", "4");
	stringMap.put("6", "3");
	stringMap.put("7", "2");
	assert(stringMap.get("1") == "2");
	assert(stringMap.get("2") == "3");
	assert(stringMap.get("3") == "4");
	assert(stringMap.get("4") == "5");
	assert(stringMap.get("5") == "4");
	assert(stringMap.get("6") == "3");
	assert(stringMap.get("7") == "2");
	assert(stringMap.size() == 7);
	assert(stringMap.containsKey("1"));
	assert(stringMap.containsKey("7"));
	assert(!stringMap.containsKey("0"));
	stringMap.put("8", "1");
	assert(stringMap.size() == 8);
	assert(stringMap.get("8") == "1");
	assert(!stringMap.isEmpty());
	stringMap.clear();
	assert(stringMap.size() == 0);
	assert(!stringMap.containsKey("8"));
	assert(!stringMap.containsKey("7"));
	assert(!stringMap.containsKey("1"));
	stringMap.clear();
	stringMap.put("a","A");
	stringMap.put("d", "D");
	stringMap.put("s", "S");
	stringMap.put("q", "Q");
	stringMap.put("w", "W");
	stringMap.put("e", "E");
	stringMap.put("r", "R");

	stringMap.displayTree();
	

	return 0;
}

