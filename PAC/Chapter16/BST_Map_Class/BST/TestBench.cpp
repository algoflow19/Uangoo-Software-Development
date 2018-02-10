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
	assert(stringMap.containsKey("1"));
	assert(!stringMap.containsKey("0"));
	assert(!stringMap.containsKey("4"));
	assert(stringMap.size() == 3);
	stringMap.remove("1");
	assert(stringMap.size()==2);
	stringMap.remove("qq");
	assert(stringMap.size() == 2);
	assert(stringMap.get("2") == "3");
	assert(stringMap.get("3") == "4");
	stringMap.clear();
	assert(stringMap.size()==0);
	assert(stringMap.get("2") == "");
	stringMap.put("1", "2");
	stringMap.put("2", "3");
	stringMap.put("3", "4");
	assert(stringMap.containsKey("1"));
	assert(!stringMap.containsKey("0"));
	assert(!stringMap.containsKey("4"));
	stringMap.remove("3");
	assert(stringMap.size() == 2);
	stringMap.remove("1");
	assert(stringMap.size() == 1);
	assert(stringMap.containsKey("2"));
	assert(stringMap.get("2") == "3");

	return 0;
}

