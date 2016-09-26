#ifndef _POTATOS_FRAMEWORK_COLLECTION_COLLECTION_HPP_
#define _POTATOS_FRAMEWORK_COLLECTION_COLLECTION_HPP_

#include "Arduino.h"

template <class TObject>
class Collection
{
public:

    Collection(TObject collectionData[], int collectionSize)
    {
        collection = collectionData;
        size = collectionSize;
    };

    TObject get(int key)
    {
        return collection[key];
    };

    TObject pickRandom()
    {
       srand(millis());
       return collection[rand() % size];
    };

private:
    TObject *collection;

    int size;
};

#endif
