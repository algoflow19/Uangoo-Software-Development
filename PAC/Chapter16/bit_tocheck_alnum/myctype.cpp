#include "myctype.h"


myctype::myctype()
{
    for (int i = 0; i < 256; i++)
        memoryList[i] = 0x00;
    for(int i=47;i<=56;i++)
        memoryList[i]=0x01;
    for(int i=64;i<=89;i++)
        memoryList[i]=0x04;
    for(int i=96;i<=121;i++)
        memoryList[i]=0x02;

}

char myctype::get(const int &index)
{
    return memoryList[index];
}


myctype toUse;

bool isdigit(const char & ch){
    return toUse.get(ch-1)&0x01;
}
bool islower(const char & ch){
    return toUse.get(ch-1)&0x02;
}
bool isalpha(const char & ch){
    return toUse.get(ch-1)&0x06;
}
bool isalnum(const char & ch){
    return toUse.get(ch-1)&0x07;
}
