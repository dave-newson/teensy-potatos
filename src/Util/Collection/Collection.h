#ifndef _POTATOS_UTIL_COLLECTION_COLLECTION_H_
#define _POTATOS_UTIL_COLLECTION_COLLECTION_H_

#include "Arduino.h"

template <class TObject>
class Collection
{
public:

    Collection(TObject collectionData[], int collectionSize) {
        collection = collectionData;
        size = collectionSize;
    };

    TObject pickRandom(TObject collection[]) {

        srand(millis());
        return collection[rand() % size];
    };

private:
    TObject *collection;

    int size = 0;
};

#endif
