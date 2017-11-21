#ifndef INTARRAY_H
#define INTARRAY_H


class IntArray
{
public:
    IntArray(int n);
    IntArray(const IntArray& array);  // Stand Way to const & paramenter

    ~IntArray();
    int size() const;
    int get(int k) const;
    void put(int k,int value) ;
    IntArray& operator=(const IntArray& array);
    int &operator[](int k);


private:
    void isError(int k) const;
    void deepCopy(const IntArray& src);
    int arraySize;
    int *ip;

};

#endif // INTARRAY_H
