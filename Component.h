#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Iterator;
using namespace std;


class Component{
    protected:

        string id;
        string name;
    public:

        Component(const string& id, const string& name);
        string getId() const;
        string getName() const;
        virtual string getStatus() const = 0;
        virtual Iterator* createIterator() const = 0;
        virtual ~Component();





};

#endif