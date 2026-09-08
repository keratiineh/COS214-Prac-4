#include "VFXDecorator.h"
#include <utility>

VFXDecorator::VFXDecorator(Component* item, std::string house)
    : ComponentDecorator(item), vfxHouse(std::move(house)) {}

std::string VFXDecorator::getStatus() const {
    return wrapped->getStatus() + " | VFX review queued at " + vfxHouse;
}