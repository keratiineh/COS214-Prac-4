#ifndef FULLTRAVERSALITERATOR_H
#define FULLTRAVERSALITERATOR_H
#include "Iterator.h"
#include "CompositeComponent.h"
#include "Component.h"
#include <cstddef>
using namespace std;
class FullTraversalIterator: public Iterator{
        std::vector<Component*> items;
        size_t position;
        void collect(Component* node);
    public:
        explicit FullTraversalIterator(Component* root);
        bool hasNext() const override;
        Component* next() override;

};
#endif