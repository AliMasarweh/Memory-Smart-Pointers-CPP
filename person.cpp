//
// Created by ali-masa on 2/18/20.
//

#include <cstring>
#include "person.h"

Person::Person(char *fullname, unsigned int id, unsigned int age)
:id(id),age(age)
{
    strcpy(this->fullname, fullname);
}

void Person::doSomthing() {

}
