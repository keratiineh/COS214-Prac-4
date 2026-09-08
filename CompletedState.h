#ifndef COMPLETEDSTATE_H
#define COMPLETEDSTATE_H

#include "ShotState.h"

class CompletedState : public ShotState {
public:
    ShotState* checkTransition(Shot* shot) override;
    std::string getName() const override;
};

#endif //COMPLETEDSTATE_H