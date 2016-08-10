#ifndef _POTATOS_UTIL_COLLECTION_COLLECTION_H_
#define _POTATOS_UTIL_COLLECTION_COLLECTION_H_

#include "Arduino.h"

template <class TObject>
class Collection
{
public:

    Collection(TObject arrayData[]) {
        collection = arrayData;
    };

    TObject pickRandom(void) {

        srand(millis());
        const size_t n = sizeof(collection) / sizeof(collection[0]);

        return collection[rand() % n];
    };

private:
    TObject *collection;
};

#endif
