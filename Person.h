#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "ecs36b_Common.h"
using namespace std;

class Person {
    private:   
        string name;

    public:

        Person(string n);

        Person();

        void setName(string n);

        string getName();

        Json::Value dump2JSON();

        bool JSON2Object(Json::Value);
};
#endif