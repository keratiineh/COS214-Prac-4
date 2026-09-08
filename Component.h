#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <vector>

class Iterator;
using namespace std;


class Component{
    friend class FullTraversalIterator;
    friend class SelectiveTraversalIterator;
    protected:

        string id;
        string name;
        virtual vector<Component*> getChildrenForTraversal() const {return{};}
    public:

        Component(const string& id, const string& name);
        string getId() const;
        string getName() const;
        virtual string getStatus() const = 0;
        virtual Iterator* createIterator()  = 0;
        virtual ~Component();





};

#endif