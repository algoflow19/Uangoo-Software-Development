/*
 * File: stringmap.h
 * -----------------
 * This interface exports a simplified version of the Map class in which
 * the keys and values are always strings.
 */

#ifndef _stringmap_h
#define _stringmap_h

#include <string>
#include<vector>
#include<iostream>
#include "error.h"
#include"hashcode.h"
/*
 * Iterator Implement Notes:
 * -------------------------
 * Using a string list(iteratorNameList) to get the Cell more effective!
 *
 */



/*
 * Free function: hashCode
 * Usage: int code = hashCode(key);
 * --------------------------------
 * Returns the hash code for key.
 */

//int hashCode(const std::string & key);

class StringMap {

public:

/*
 * Constructor: StringMap
 * Usage: StringMap map;
 * ---------------------
 * Initializes a new empty map that uses strings as both keys and values.
 */

   StringMap();

/*
 * Destructor: ~StringMap
 * ----------------------
 * Frees any heap storage associated with this map.
 */

   ~StringMap();

/*
 * Method: get
 * Usage: string value = map.get(key);
 * -----------------------------------
 * Returns the value for key or the empty string, if key is unbound.
 */

   std::string get(const std::string & key) const;

/*
 * Method: put
 * Usage: map.put(key, value);
 * ---------------------------
 * Associates key with value in this map.
 */

   void put(const std::string & key, const std::string & value);

   int size(){
       return iteratorNameList.size();
   }




/* Private section */

/*
    * Notes on the representation
    * ---------------------------
    * This version of the StringMap class uses a hash table that keeps the
    * key-value pairs in an array of buckets, each of which is a linked list
    * of keys that hash to that bucket.
*/

private:

/* Type definition for cells in the bucket chain */

   struct Cell {
      std::string key;
      std::string value;
      Cell *link;
   };

/* Constant definitions */

   static const int INITIAL_BUCKET_COUNT = 13;

/* Instance variables */

   std::vector<std::string> iteratorNameList;
   Cell **buckets;              /* Dynamic array of pointers to cells */
   int nBuckets;                /* The number of buckets in the array */

/* Private methods */

   Cell *findCell(int bucket, const std::string & key) const;

/* Make copying illegal */

   StringMap(const StringMap & src) { }
   StringMap & operator=(const StringMap & src) { return *this; }

public:
   class iterator{
   public:
       iterator(){
           sp=NULL;
       }
       std::string& operator*(){
           if(sp==NULL) error("Uninited iterator being using!");
           if(index<0&&index>=sp->iteratorNameList.size()) error("Iterator out of range");
           std::string key=sp->iteratorNameList[index];
           int bucket = hashCode(key) % sp->nBuckets;
           Cell *cp = sp->findCell(bucket, key);
           return cp->value;
       }
       iterator& operator++(){
           if(sp==NULL) error("Uninited iterator being using!");
           index++;
           return *this;
       }
       iterator operator++(int){  // with (int), the ++ is on the right of the iterator
           iterator copy(*this);
           ++(*this);
           return copy;
       }
       bool operator==(const iterator& rhs) const{
           if(sp==NULL) error("Uninited iterator being using!");
           if(sp!=rhs.sp) error("Iterator from different ");
           return index==rhs.index;
       }
       bool operator!=(const iterator& rhs)const{
           return !(*this==rhs);
       }
       std::string* operator->(){
           if(sp==NULL) error("Uninited iterator being using!");
           if(index<0&&index>=sp->iteratorNameList.size()) error("Iterator out of range");
           std::string key=sp->iteratorNameList[index];
           int bucket = hashCode(key) % sp->nBuckets;
           Cell *cp = sp->findCell(bucket, key);
           return &cp->value;
       }


   private:
       iterator(StringMap* sp,int index){
           this->sp=sp;
           this->index=index;
       }

       StringMap* sp;
       int index;
       friend class StringMap;
   };

   iterator begin(){
       return iterator(this,0);
   }
   iterator end(){
       return iterator(this,iteratorNameList.size());
   }


};



#endif
