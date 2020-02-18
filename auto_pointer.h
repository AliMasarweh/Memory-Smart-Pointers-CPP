//
// Created by ali-masa on 2/18/20.
//

#ifndef SMARTPOINTEREXERCISE_SMARTPOITNER_H
#define SMARTPOINTEREXERCISE_SMARTPOITNER_H

template <class T>
class AutoPointer
{
private:
    T* pntr;
    explicit AutoPointer(AutoPointer& AutoPointer): pntr(AutoPointer->pntr){}

public:
    explicit AutoPointer(T* pntr = NULL): pntr(pntr){}

    AutoPointer& operator=(AutoPointer& AutoPointer)
    {
        this->pntr = new T(pntr);

        return *this;
    }

    ~AutoPointer()
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

#endif //SMARTPOINTEREXERCISE_SMARTPOITNER_H
