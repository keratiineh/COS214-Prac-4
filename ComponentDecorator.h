#ifndef COMPONENTDECORATOR_H
#define COMPONENTDECORATOR_H

#include "Component.h"

//Abstract Decorator 

class ComponentDecorator : public Component {
    protected:
        Component* wrapped;
    
    public:
        explicit ComponentDecorator(Component* item);
        ~ComponentDecorator() override;
        std::string getStatus() const override;
        Iterator* createIterator() const override;
};

#endif