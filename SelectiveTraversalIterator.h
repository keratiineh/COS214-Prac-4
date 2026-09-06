#ifndef SELECTIVETRAVERSALITERATOR_H
#define SELECTIVETRAVERSALITERATOR_H

#include "Iterator.h"
#include "Component.h"
#include <vector>
#include <string>
#include <cstddef>
using namespace std;

class SelectiveTraversalIterator : public Iterator{
        vector<Component*> items;
        size_t position;
        string criteria;
        void collect(Component* node);
    public:
        SelectiveTraversalIterator(Component* root, string& criteria);
        bool hasNext() const override;
        Component* next() override;


};

#endif