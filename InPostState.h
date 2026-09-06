#ifndef INPOSTSTATE_H
#define INPOSTSTATE_H

#include "ShotState.h"

class InPostState : public ShotState {
public:
    ShotState* checkTransition(Shot* shot) override;
    std::string getName() const override;
};

#endif //INPOSTSTATE_H