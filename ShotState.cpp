#include "ShotState.h"
#include <iostream>

//Default behaviour: this state has no valid outgoing transition
//(e.g. ApprovedState is terminal). Print a message and signal "no
//change" by returning nullptr. Shot::transition() checks for nullptr
//and simply does nothing in that case.

ShotState* ShotState::checkTransition(Shot* shot) {
    (void)shot; //unused in the default case
    std::cout << "Invalid transition: cannot advance from " << getName() << ".\n";
    return nullptr;
}