#ifndef _POTATOS_FRAMEWORK_COLLECTION_COLLECTION_H_
#define _POTATOS_FRAMEWORK_COLLECTION_COLLECTION_H_

#include "Arduino.h"

template <class TObject>
class Collection
{
public:

    Collection(TObject collectionData[], int collectionSize);

    TObject pickRandom(void);

private:
    TObject *collection;

    int size;
};

#endif
