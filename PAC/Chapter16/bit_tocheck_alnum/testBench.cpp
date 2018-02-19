#include <iostream>
#include <string>
#include"mapset.h"
#include<assert.h>
#include"myctype.h"

using namespace std;



int main() {
    assert(isalnum('x'));
        assert(isalnum('z'));
        assert(isalnum('A'));
        assert(!isalnum('/'));
        assert(!isalnum('!'));
        assert(isalnum('0'));
        assert(isdigit('1'));
        assert(isdigit('2'));
        assert(isdigit('0'));
        assert(isdigit('9'));
        assert(isalpha('z'));
        assert(isalpha('a'));
        assert(isalpha('A'));
        assert(isalpha('Z'));
        assert(isalpha('B'));
        assert(!islower('B'));
        assert(islower('a'));
        assert(islower('z'));
        assert(!islower('Z'));
        assert(!isalpha('`'));
        return 0;

}


