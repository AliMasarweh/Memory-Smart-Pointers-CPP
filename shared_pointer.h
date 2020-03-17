//
// Created by ali-masa on 2/18/20.
//

#ifndef SMARTPOINTEREXERCISE_SHARED_POINTER_H
#define SMARTPOINTEREXERCISE_SHARED_POINTER_H

#include <stddef.h>
#include <malloc.h>

template <class T>
class SharedPointer
{
private:
    T* pntr;
    size_t* count;

    template <class V>
    friend class SharedPointer;

public:
    explicit SharedPointer(T* pntr = NULL): pntr(pntr)
    {
        this->count = new size_t(1);
    }

    template <class V>
    explicit SharedPointer(SharedPointer<V> & sharedPointer)
    : pntr(sharedPointer.pntr), count(count)
    {
        this->count = sharedPointer.count;
        size_t& x = *(this->count);
        ++ *(this->count);
    }

    template <class V>
    SharedPointer& operator=(SharedPointer<V> & sharedPointer)
    {
        release();

        this->pntr = sharedPointer.pntr;
        this->count = sharedPointer.count;
        size_t& x = *(this->count);
        ++ *(this->count);

        return *this;
    }

    void release()
    {
        size_t& x = *(this->count);
        -- *(this->count);
        if(*(this->count) == 0) {
            if(pntr != NULL)
                delete pntr;
            delete count;
        }
    }

    ~SharedPointer()
    {
        release();
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
};

#endif //SMARTPOINTEREXERCISE_SHARED_POINTER_H
