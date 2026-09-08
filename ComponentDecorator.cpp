#include "ComponentDecorator.h"

ComponentDecorator::ComponentDecorator(Component* item) 
    : Component(item->getId(), item->getName()), wrapped(item) {}

ComponentDecorator::~ComponentDecorator () {
    delete wrapped;
}

std::string ComponentDecorator::getStatus() const {
    return wrapped->getStatus();
}

Iterator* ComponentDecorator::createIterator() {
    return wrapped->createIterator();
}