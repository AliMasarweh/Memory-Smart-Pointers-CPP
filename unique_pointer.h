//
// Created by ali-masa on 2/18/20.
//

#ifndef SMARTPOINTEREXERCISE_UNIQUEPOINTER_H
#define SMARTPOINTEREXERCISE_UNIQUEPOINTER_H

#include <stddef.h>

template <class T>
class UniquePointer;

template <class T>
class UnownedPointer
{
public:
    T* uniquePointer;
};

template <class T>
class UniquePointer
{

    friend UnownedPointer<T> move(UniquePointer<T>& uniquePointer)
    {
        UnownedPointer<T> unownedPointer;
        unownedPointer.uniquePointer = uniquePointer.pntr;
        uniquePointer.pntr = NULL;

        return unownedPointer;
    }

private:
    T* pntr;
    explicit UniquePointer(UniquePointer& AutoPointer): pntr(AutoPointer->pntr){}

public:
    explicit UniquePointer(T* pntr = NULL): pntr(pntr){}

    UniquePointer<T>& operator=(UnownedPointer<T> unownedPointer)
    {
        this->pntr = unownedPointer.uniquePointer;

        return *this;
    }

    UniquePointer<T>& operator=(UnownedPointer<T>& unownedPointer)
    {
        this->pntr = unownedPointer.uniquePointer;
        unownedPointer.uniquePointer = NULL;

        return *this;
    }

    UniquePointer<T>& operator=(UniquePointer<T>& uniquePointer)
    {
        this->pntr = uniquePointer.pntr;
        uniquePointer.pntr = NULL;

        return *this;
    }

    ~UniquePointer()
    {
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
};



#endif //SMARTPOINTEREXERCISE_UNIQUEPOINTER_H
