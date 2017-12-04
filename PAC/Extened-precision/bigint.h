#ifndef BIGINT_H
#define BIGINT_H
#include<string>

class BigInt
{
public:
    // BigInt();
    BigInt(int n);
    BigInt(std::string str);

    std::string toString() const;
    BigInt operator+(const BigInt &src) const;
    BigInt operator*(const BigInt &src) const;

    ~BigInt();

private:
    int length;
    struct node{
      unsigned short num;
      node* nextNode;
    };
    node* tail;
    std::string power10(int n) const;
    std::string doSingleMul(short n) const;

};

#endif // BIGINT_H
