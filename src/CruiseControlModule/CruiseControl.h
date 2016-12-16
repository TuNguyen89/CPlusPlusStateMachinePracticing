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
    AccReleasedAction
};

class CruiseControl {
public:

    CruiseControl();
    virtual ~CruiseControl();

    void handleAction(ActionEnum action);
    std::string getStatus();
    void setNewState(CruiseControlState*  newState);

private:

    CruiseControlState *state;
    int cruiseSpeed;

    void actionOn();
    void actionSet();
    void actionResume();
    void actionBrake();
    void actionAccPressed();
    void actionReleased();

};

#endif /* CRUISECONTROL_H_ */
