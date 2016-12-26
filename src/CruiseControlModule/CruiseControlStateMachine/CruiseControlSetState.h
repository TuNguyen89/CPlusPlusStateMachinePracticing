
#ifndef CRUISECONTROLSETSTATE_H_
#define CRUISECONTROLSETSTATE_H_

#include "CruiseControlActiveState.h"

class CruiseControlSetState : public CruiseControlActiveState {
public:
	CruiseControlSetState();
	virtual ~CruiseControlSetState();

   CruiseControlState<CruiseControlStateMachine>* transitionAccPressed(CruiseControlStateMachine * aMachine, EventDataType arg);
   CruiseControlState<CruiseControlStateMachine>* transitionBrake(CruiseControlStateMachine * aMachine, EventDataType arg);
   CruiseControlState<CruiseControlStateMachine>* transitionSet(CruiseControlStateMachine * aMachine, EventDataType arg);
};

#endif /* CRUISECONTROLSETSTATE_H_ */
