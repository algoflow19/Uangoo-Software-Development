#include <iostream>
#include <string>
#include"mapset.h"
#include<assert.h>
using namespace std;



int main() {

    MapSet<char> set;
    set.add('a');
    set.add('b');
    set.add('c');
    set.add('d');
    assert(set.contains('a'));
    assert(set.contains('b'));
    assert(set.contains('c'));
    assert(set.contains('d'));
    assert(!set.contains('1'));
    assert(set.size()==4);
    set.remove('d');
    assert(set.size()==3);
    assert(!set.contains('d'));
    set.clear();
    assert(set.isEmpty());
    MapSet<char> subset;
    subset.add('1');
    subset.add('2');
    subset.add('3');
    subset.add('a');
    assert(subset.size()==4);
    assert(subset.contains('1'));
    assert(subset.contains('a'));
    assert(subset.contains('3'));
    set.add('1');
    set.add('2');
    set.add('3');
    set.add('a');
    set.add('b');
    assert(!set.isSubsetOf(subset));
    assert(subset.isSubsetOf(set));
    set.remove('b');
    assert(set.isSubsetOf(subset));
    assert(subset.isSubsetOf(set));
    set.remove('1');
    assert(set.isSubsetOf(subset));
    assert(!subset.isSubsetOf(set));
    subset.clear();
    assert(subset.isEmpty());
    return 0;

}


