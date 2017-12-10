#include<iostream>
#include<string>
using namespace std;

int romanToDecimal(const string & str);

class LUT{
public:
    LUT(){
        A='A';
        table['I'-A]=1;
        table['V'-A]=5;
        table['X'-A]=10;
        table['L'-A]=50;
        table['C'-A]=100;
        table['D'-A]=500;
        table['M'-A]=1000;
    }

    int findCharValue(char ch){
        return table[ch-A];
    }

private:
    int A;
    int table[1+'Z'-'A'];

} lut;

int main(){

    cout<<romanToDecimal("MCMLXIXXX")<<endl;

    return 0;
}


int romanToDecimal(const string & str){
    int sum=0;
    for(int i=0;i<str.length();i++){
        int tmp=lut.findCharValue(str[i]);
        if(i+1<str.length()&&tmp<lut.findCharValue(str[i+1]))
            tmp=(-1)*tmp;
        sum+=tmp;
    }
    return sum;
}
