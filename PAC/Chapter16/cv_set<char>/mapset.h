#ifndef MAPSET_H
#define MAPSET_H
#include"map.h"
#include<iostream>
#include<sstream>
#include<string>


const int RANGE_SIZE=256;
const int BITS_PER_BYTE=8;
const int BITS_PER_LONG=BITS_PER_BYTE*sizeof(unsigned long);
const int CVEC_WORDS=(BITS_PER_LONG+RANGE_SIZE-1)/BITS_PER_LONG;

template<typename ValueType>
class MapSet
{
public:

    MapSet();
    ~MapSet();
    int size() const;
    bool isEmpty();
    void add(const ValueType & value);
    void remove(const ValueType & value);

    bool contains(const ValueType & value) const;
    void clear();

    bool isSubsetOf(const MapSet<ValueType> & set) const;

    bool operator!=(const MapSet<ValueType> & set) const;
    bool operator==(const MapSet<ValueType> & set) const;



    MapSet<ValueType> operator+(const MapSet<ValueType> & set2) const;
    MapSet<ValueType> operator+(const ValueType & value) const;
    MapSet<ValueType> operator*(const MapSet<ValueType> & set2) const;
    MapSet<ValueType> operator-(const MapSet<ValueType> & set2) const;
    MapSet<ValueType> operator-(const ValueType & value) const;

    MapSet<ValueType> & operator=(const MapSet<ValueType> & set2);

    MapSet<ValueType> & operator+=(const MapSet<ValueType> & set2);
    MapSet<ValueType> & operator+=(const ValueType & value);
    MapSet<ValueType> & operator*=(const MapSet<ValueType> & set2);
    MapSet<ValueType> & operator-=(const MapSet<ValueType> & set2);
    MapSet<ValueType> & operator-=(const ValueType & value);





    template<class T>
    friend std::ostream & operator<< (std::ostream & os, const MapSet<T> & set);
    template<class T>
    friend std::istream & operator>> (std::istream & is,  MapSet<T> & set);

    friend MapSet<int> & doCreatePrimeSet(MapSet<int> & set,int max);

private:

    Map<ValueType,bool> map;

};



template<typename ValueType>
inline MapSet<ValueType>::MapSet()
{

}

template<typename ValueType>
inline MapSet<ValueType>::~MapSet()
{

}

template<typename ValueType>
inline int MapSet<ValueType>::size() const
{
    return map.size();
}
template<typename ValueType>
inline bool MapSet<ValueType>::isEmpty()
{
    return map.size()==0;
}
template<typename ValueType>
inline void MapSet<ValueType>::add(const ValueType &value)
{
    map.add(value,true);

}
template<typename ValueType>
inline void MapSet<ValueType>::remove(const ValueType &value)
{
    map[value]=false;
    map.remove(value);
}
template<typename ValueType>
inline bool MapSet<ValueType>::contains(const ValueType &value) const
{
    return map.containsKey(value);
}
template<typename ValueType>
inline void MapSet<ValueType>::clear()
{
    map.clear();
}

template<typename ValueType>
inline bool MapSet<ValueType>::isSubsetOf(const MapSet<ValueType> &set) const
{
    for(ValueType value : set){
        if(!map.containsKey(value))
            return false;
    }
    return true;
}

template<typename ValueType>
inline bool MapSet<ValueType>::operator!=(const MapSet<ValueType> &set) const
{
    if(map.size()!=set.size()) return false;
    for(ValueType value : map)
        if(!set.contains(value)) return false;
    return true;
}

template<typename ValueType>
inline bool MapSet<ValueType>::operator==(const MapSet<ValueType> &set) const
{
    return !((*this)!=set);
}

template<typename ValueType>
inline MapSet<ValueType> MapSet<ValueType>::operator+(const MapSet<ValueType> &set2) const
{
    MapSet<ValueType> targetSet=*this;
    for(ValueType value : set2.map)
        targetSet.add(value);
    return targetSet;
}

template<typename ValueType>
inline MapSet<ValueType> MapSet<ValueType>::operator+(const ValueType &value) const
{
    MapSet<ValueType> targetSet=*this;
    targetSet.add(value);
    return targetSet;
}

template<typename ValueType>
inline MapSet<ValueType> MapSet<ValueType>::operator*(const MapSet<ValueType> &set2) const
{
    MapSet<ValueType> targetSet;
    for(ValueType value : map){
        if(set2.map.containsKey(value))
            targetSet.add(value);
    }
    return targetSet;
}

template<typename ValueType>
inline MapSet<ValueType> MapSet<ValueType>::operator-(const MapSet<ValueType> &set2) const
{
    MapSet<ValueType> targetSet=*this;
    for(ValueType value : set2.map)
        targetSet.remove(value);
    return targetSet;
}


template<typename ValueType>
inline MapSet<ValueType> MapSet<ValueType>::operator-(const ValueType &value) const
{
    MapSet<ValueType> targetSet=*this;
    targetSet.remove(value);
    return targetSet;
}

template<typename ValueType>
inline MapSet<ValueType> &MapSet<ValueType>::operator=(const MapSet<ValueType> &set2)
{
    for(ValueType value1 : (*this - set2).map )
        remove(value1);

    for(ValueType value2 : (set2 - *this).map )
        add(value2);
    return *this;
}
template<typename ValueType>
inline MapSet<ValueType> &MapSet<ValueType>::operator+=(const MapSet<ValueType> &set2)
{
    *this=(*this)+set2;
}
template<typename ValueType>
inline MapSet<ValueType> &MapSet<ValueType>::operator+=(const ValueType &value)
{
    *this=(*this)+value;
}
template<typename ValueType>
inline MapSet<ValueType> &MapSet<ValueType>::operator*=(const MapSet<ValueType> &set2)
{
    *this=(*this)*set2;
}
template<typename ValueType>
inline MapSet<ValueType> &MapSet<ValueType>::operator-=(const MapSet<ValueType> &set2)
{
    *this=(*this)-set2;
}
template<typename ValueType>
inline MapSet<ValueType> &MapSet<ValueType>::operator-=(const ValueType &value)
{
    remove(value);
    return *this;
}

template<typename ValueType>
inline std::ostream &operator<<(std::ostream & os, const MapSet<ValueType> & set)
{
    int size=set.size();
    int i=1;
    std::cout<<"{";
    for(ValueType value : set.map ){
        os<<value;
        if(i==size)
            os<<"}";
        else{
            os<<",";
            i++;
        }
    }
    if(set.size()==0) os<<"}";
    return os;
}

template<typename ValueType>
inline std::istream &operator>>(std::istream &is,  MapSet<ValueType> &set)
{
    std::string str="";
    if(is.get()!='{') {

        error("Invaild format! example: {a,b,c}");
    }
    std::stringstream ss;
    while(true){
        char word=is.get();

        if(word!=','&&word!='}'){
            ss<<word;
        }
        else{
            ss>>str;
            set.add(str);
            ss.clear();
            if(word=='}')
                break;
        }
    }
    is.get(); //The input stream will read change-line symbol
    return is;
}

struct CharacteristicVector{
    unsigned long words[CVEC_WORDS];
};

template<>
class MapSet<char>{
public:
    MapSet();

    ~MapSet();
    int size() const;
    bool isEmpty();
    void add(const char & value);
    void remove(const char & value);

    bool contains(const char & value) const;
    void clear();

    bool isSubsetOf(const MapSet<char> & set) const;
private:

    unsigned long createMask(int k) const;
    int count;
    CharacteristicVector cv;

};

inline MapSet<char>::MapSet()
{
    for(int i=0;i<CVEC_WORDS;i++)
        cv.words[i]=(unsigned long)0;
    count=0;
}





inline int MapSet<char>::size() const
{
    return count;
}


inline bool MapSet<char>::isEmpty()
{
    return count==0;
}

inline void MapSet<char>::add(const char &value)
{
    if(!(cv.words[(value)/BITS_PER_LONG]&createMask(value))) {
    cv.words[(value)/BITS_PER_LONG]=cv.words[(value)/BITS_PER_LONG]|createMask(value);
    count++;
    }
}

inline unsigned long MapSet<char>::createMask(int k) const
{
    return (unsigned long)(1) << k % BITS_PER_LONG;
}

inline void MapSet<char>::remove(const char &value)
{
    if(cv.words[(value)/BITS_PER_LONG]&createMask(value)){
    cv.words[(value)/BITS_PER_LONG]=cv.words[(value)/BITS_PER_LONG] & ~createMask(value);
    count--;
    }
}

inline bool MapSet<char>::contains(const char &value) const
{
    return cv.words[(value)/BITS_PER_LONG]&createMask(value);
}

inline void MapSet<char>::clear()
{
    for(int i=0;i<CVEC_WORDS;i++)
        cv.words[i]=0;
    count=0;
}

inline bool MapSet<char>::isSubsetOf(const MapSet<char> &set) const
{
    for(int i=0;i<CVEC_WORDS;i++){
        if((cv.words[i]|set.cv.words[i]) != set.cv.words[i])
            return false;
    }
    return true;
}

inline MapSet<char>::~MapSet()
{

}







#endif // MAPSET_H
