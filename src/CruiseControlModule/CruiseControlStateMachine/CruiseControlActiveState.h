
#ifndef CRUISECONTROLACTIVESTATE_H_
#define CRUISECONTROLACTIVESTATE_H_

#include "CruiseControlState.h"

class CruiseControl;
class CruiseControlStateMachine;

class CruiseControlActiveState: public CruiseControlState <CruiseControlStateMachine> 
{
public:
    CruiseControlActiveState();
    virtual ~CruiseControlActiveState();

    CruiseControlState<CruiseControlStateMachine>*  transitionOn(CruiseControlStateMachine* aMachine, EventDataType arg);
};

#endif /* CRUISECONTROLACTIVESTATE_H_ */
