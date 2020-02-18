//
// Created by ali-masa on 2/18/20.
//

#ifndef SMARTPOINTEREXERCISE_PERSON_H
#define SMARTPOINTEREXERCISE_PERSON_H

class Person
{
public:
    Person();
    Person(char *fullname, unsigned int id, unsigned int age);

    void doSomthing();

    char fullname[32];
    unsigned int id;
    unsigned int age;
};

#endif //SMARTPOINTEREXERCISE_PERSON_H
