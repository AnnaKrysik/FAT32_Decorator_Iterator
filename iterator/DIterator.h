#pragma once
#include "Iterator.h"
#include "Cluster.h"

template<class Type>
class DIterator :
    public Iterator<Type>
{
protected:
    Iterator<Type>* It;
public:
    DIterator(Iterator<Type>* it) {
        It = it;
    }
    virtual void First() { It->First(); }
    virtual void Next() { It->Next(); }
    virtual bool IsDone() const { return It->IsDone(); }
    virtual Type GetCurrent() { return It->GetCurrent(); }
    ~DIterator() { delete It; }
};

