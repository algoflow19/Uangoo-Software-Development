#ifndef MYCTYPE_H
#define MYCTYPE_H



class myctype
{
public:
    myctype();
    char get(const int & index);
private:
    char memoryList[256];


};

bool isdigit(const char & ch);
bool islower(const char & ch);
bool isalpha(const char & ch);
bool isalnum(const char & ch);
#endif // MYCTYPE_H
