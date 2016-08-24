#include "Collection.h"

template<class TObject> Collection<TObject>::Collection(TObject collectionData[], int collectionSize)
{
    collection = collectionData;
    size = collectionSize;
};

template<class TObject> TObject Collection<TObject>::pickRandom()
{
   srand(millis());
   return collection[rand() % size];
};
