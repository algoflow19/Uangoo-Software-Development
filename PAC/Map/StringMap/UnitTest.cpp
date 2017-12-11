#include "stdafx.h"
#include<iostream>
#include<string>
#include"StringMap.h"
#include<assert.h>
using namespace std;

int main() {
	
	StringMap map;
	assert(map.isEmpty());
	map.put("key", "value");
	assert( map.get("key") == "value");
	assert(map.containsKey("key"));
	assert(!map.isEmpty());
	assert(map.size() == 1);
	map.clear();
	assert(map.isEmpty());
	assert(!map.containsKey("key"));
	assert(map.get("key") == "");
	map.put("key", "value");
	map.add("key", "replace_value");
	map.add("key", "replace_value2");
	assert(map.get("key") == "replace_value2");
	map.remove("key");
	assert(map.get("key") == "replace_value");
	map.remove("key");
	assert(map.get("key") == "value");
	// cause the rehash
	map.put("0", "0");
	map.put("1", "1");
	map.put("2", "2");
	map.put("3", "3");
	map.put("4", "4");
	map.put("5", "5");
	map.put("6", "6");
	map.put("7", "7");
	map.put("8", "8");
	map.put("9", "9");
	map.put("10", "10");
	map.put("11", "11");
	assert(map.get("1") == "1");
	assert(map.get("2") == "2");
	assert(map.get("3") == "3");
	assert(map.get("4") == "4");
	assert(map.get("5") == "5");
	assert(map.get("6") == "6");
	assert(map.get("7") == "7");
	assert(map.get("8") == "8");
	assert(map.get("9") == "9");
	assert(map.get("10") == "10");
	assert(map.get("11") == "11");
	assert(map.get("0") == "0");
}
