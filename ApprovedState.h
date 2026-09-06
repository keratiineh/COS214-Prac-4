#ifndef APPROVEDSTATE_H
#define APPROVEDSTATE_H

#include "ShotState.h"

/*ApprovedState is terminal: it does NOT override checkTransition(),
so calling transition() on a Shot in this state falls back to
ShotState's default (prints "invalid transition" and returns nullptr) */
class ApprovedState : public ShotState {
public:
    std::string getName() const override;
};

#endif //APPROVEDSTATE_H