#include "InPostState.h"
#include "ApprovedState.h"

ShotState* InPostState::checkTransition(Shot* shot) {
    (void)shot;
    return new ApprovedState();
}

std::string InPostState::getName() const {
    return "In Post-Production";
}