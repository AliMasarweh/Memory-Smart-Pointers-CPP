//
// Created by ali-masa on 2/18/20.
//

#ifndef SMARTPOINTEREXERCISE_SHARED_POINTER_H
#define SMARTPOINTEREXERCISE_SHARED_POINTER_H

#include <stddef.h>

template <class T>
class SharedPointer
{
private:
    T* pntr;
    size_t* count;
    SharedPointer<T>* m_ownerBefore;

public:
    explicit SharedPointer(T* pntr = NULL): pntr(pntr)
    {
        this->count = new size_t(1);
        m_ownerBefore = NULL;
    }

    explicit SharedPointer(SharedPointer& sharedPointer)
    : pntr(sharedPointer.pntr), count(count)
    {
        this->count = sharedPointer.count;
        ++ *(this->count);
        m_ownerBefore = &sharedPointer;
    }

    SharedPointer& operator=(SharedPointer& sharedPointer)
    {
        this->pntr = pntr;
        this->count = sharedPointer.count;
        ++ *(this->count);
        m_ownerBefore = &sharedPointer;

        return *this;
    }

    ~SharedPointer()
    {
        -- *(this->count);
        if(*(this->count) == 0)
            delete pntr;
    }

    T* operator ->()
    {
        return pntr;
    }

    T& operator *()
    {
        return *pntr;
    }

    T* getRowPointer()
    {
        return pntr;
    }

    operator bool()
    {
        return *(this->count);
    }

    size_t use_count()
    {
        return *(this->count);
    }

    T* get()
    {
        return this->pntr;
    }

    SharedPointer<T>& owner_before()
    {
        return *(this->m_ownerBefore);
    }
};

#endif //SMARTPOINTEREXERCISE_SHARED_POINTER_H
