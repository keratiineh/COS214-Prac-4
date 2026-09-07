#include "SecurityDecorator.h"
#include <utility>

SecurityDecorator::SecurityDecorator(Component* item, std::string clearance)
    : ComponentDecorator(item), clearanceLevel(std::move(clearance)) {}

std::string SecurityDecorator::getStatus() const {
    return wrapped->getStatus() + " | closed set, clearance: " + clearanceLevel;
}