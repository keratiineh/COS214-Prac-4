#ifndef SHOTSTATE_H
#define SHOTSTATE_H

#include <string>

class Shot;

/*
 * ShotState
 *
 * checkTransition() is the ONLY action method. Each concrete state
 * overrides it to return a freshly-allocated instance of the next state
 * in the lifecycle if a transition is legal, or nullptr if it is not.
 * Shot itself owns the swap: it deletes the old state and installs the
 * one returned here. This keeps all allocation/deletion of states in
 * one place (Shot::transition()), which matters for the memory/Valgrind
 * requirements.
 *
 * The default implementation below (used by any state that has nothing
 * further to transition to, e.g. ApprovedState) prints a message and
 * returns nullptr, meaning "stay in the current state".
 *
 * Lifecycle order: ScheduleState -> ShootingState -> CompletedState -> InPostState -> ApprovedState
 */
class ShotState {
public:
    virtual ShotState* checkTransition(Shot* shot);

    //used by Shot::getStatus() to report the current lifecycle stage
    virtual std::string getName() const = 0;

    virtual ~ShotState() {}
};

#endif //SHOTSTATE_H