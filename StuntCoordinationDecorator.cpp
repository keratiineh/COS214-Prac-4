#include "StuntCoordinationDecorator.h"
#include <utility>

StuntCoordinationDecorator::StuntCoordinationDecorator(Component* item, std::string coordinator)
    : ComponentDecorator(item), coordinatorName(std::move(coordinator)) {}

std::string StuntCoordinationDecorator::getStatus() const {
    return wrapped->getStatus() + " | stunt coordination by " + coordinatorName;
}