#include "CompletedState.h"
#include "InPostState.h"

ShotState* CompletedState::checkTransition(Shot* shot) {
    (void)shot;
    return new InPostState();
}

std::string CompletedState::getName() const {
    return "Completed";
}