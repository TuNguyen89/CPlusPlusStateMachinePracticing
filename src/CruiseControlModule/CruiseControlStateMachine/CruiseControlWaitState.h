
#ifndef CRUISECONTROLWAITSTATE_H_
#define CRUISECONTROLWAITSTATE_H_

#include "CruiseControlActiveState.h"

class CruiseControl;

class CruiseControlWaitState : public CruiseControlActiveState {
public:
	CruiseControlWaitState();
	virtual ~CruiseControlWaitState();

   CruiseControlState<CruiseControlStateMachine>* transitionResume(CruiseControlStateMachine * aMachine, 
                                                                   EventDataType arg);
};

#endif /* CRUISECONTROLWAITSTATE_H_ */
