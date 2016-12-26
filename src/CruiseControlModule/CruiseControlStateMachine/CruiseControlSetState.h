
#ifndef CRUISECONTROLSETSTATE_H_
#define CRUISECONTROLSETSTATE_H_

#include "CruiseControlActiveState.h"

class CruiseControlSetState : public CruiseControlActiveState {
public:
	CruiseControlSetState();
	virtual ~CruiseControlSetState();

   CruiseControlState<CruiseControlStateMachine>* transitionAccPressed(CruiseControlStateMachine * aMachine, EventDataType eventData);
   CruiseControlState<CruiseControlStateMachine>* transitionBrake(CruiseControlStateMachine * aMachine, EventDataType eventData);
   CruiseControlState<CruiseControlStateMachine>* transitionSet(CruiseControlStateMachine * aMachine, EventDataType eventData);
   
};

#endif /* CRUISECONTROLSETSTATE_H_ */
