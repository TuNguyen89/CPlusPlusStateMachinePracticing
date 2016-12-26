
#ifndef CRUISECONTROLSETSTATE_H_
#define CRUISECONTROLSETSTATE_H_

#include "CruiseControlActiveState.h"

class CruiseControlSetState : public CruiseControlActiveState {
public:
	CruiseControlSetState();
	virtual ~CruiseControlSetState();

   CruiseControlState<CruiseControlStateMachine>* transitionAccPressed(CruiseControlStateMachine * aMachine, const MyNameSpace::f_any & arg);
   CruiseControlState<CruiseControlStateMachine>* transitionBrake(CruiseControlStateMachine * aMachine, const MyNameSpace::f_any & arg);
   CruiseControlState<CruiseControlStateMachine>* transitionSet(CruiseControlStateMachine * aMachine, const MyNameSpace::f_any & arg);
};

#endif /* CRUISECONTROLSETSTATE_H_ */
