#include "Shot.h"
#include "ScheduleState.h"

//a new Shot always starts life as Scheduled
Shot::Shot(const std::string& id, const std::string& name)
    : Component(id, name), currentState(new ScheduleState()) {}

void Shot::transition() {
    ShotState* next = currentState->checkTransition(this);
    if (next != nullptr) {
        delete currentState;
        currentState = next;
    }
}

void Shot::setState(ShotState* state) {
    delete currentState;
    currentState = state;
}

std::string Shot::getStatus() const {
    return currentState->getName();
}

Iterator* Shot::createIterator() const {
    //a leaf has nothing to iterate over
    return nullptr;
}

Shot::~Shot() {
    delete currentState;
}