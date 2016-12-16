#ifndef CRUISECONTROL_H_
#define CRUISECONTROL_H_

#include <string>
#include "CruiseControlState.h"

enum ActionEnum 
{
    SetAction,
    OnAction,
    ResumAction,
    BreakAction,
    AccPressedAction,
    AccReleasedAction,
    InvalidAction
};

const unsigned int MIN_CAR_SPEED_TO_ACTIVE = 40; //Minimum car speed to active is 40

class CruiseControlOffState;
class CruiseControlReadyState;
class CruiseControlSetState;
class CruiseControlWaitState;
class CruiseControlAccState;
class CruiseControlActiveState;

class CruiseControl {
public:

    CruiseControl();
    virtual ~CruiseControl();

    void handleAction(ActionEnum action, unsigned int a_currentCarSpeed);
    std::string getStatus();

private:

    CruiseControlState *state;
    int cruiseSpeed;

    void actionOn();
    void actionSet(unsigned int a_currentCarSpeed);
    void actionResume();
    void actionBrake();
    void actionAccPressed();
    void actionReleased();

    //Friend class delcelation
    friend class CruiseControlOffState;
    friend class CruiseControlReadyState;
    friend class CruiseControlSetState;
    friend class CruiseControlWaitState;
    friend class CruiseControlAccState;
    friend class CruiseControlActiveState;

};

#endif /* CRUISECONTROL_H_ */
