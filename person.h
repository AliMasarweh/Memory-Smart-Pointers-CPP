//
// Created by ali-masa on 2/18/20.
//

#ifndef SMARTPOINTEREXERCISE_PERSON_H
#define SMARTPOINTEREXERCISE_PERSON_H

class Person
{
public:
    Person(char *fullname, unsigned int id, unsigned int age);

    void doSomthing();

private:
    char fullname[32];
    unsigned int id;
    unsigned int age;
};

#endif //SMARTPOINTEREXERCISE_PERSON_H