#ifndef ITERATOR_H
#define ITERATOR_H
class Component;

#include "Component.h"
class Iterator{
    public:
        virtual ~Iterator();
        virtual bool hasNext() const = 0;
        virtual Component* next() = 0;
};
#endif