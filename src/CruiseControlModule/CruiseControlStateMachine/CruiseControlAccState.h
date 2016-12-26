
#ifndef CRUISECONTROLACCSTATE_H_
#define CRUISECONTROLACCSTATE_H_

#include "CruiseControlActiveState.h"

class CruiseControlAccState : public CruiseControlActiveState {
public:
	CruiseControlAccState();
	virtual ~CruiseControlAccState();

   CruiseControlState<CruiseControlStateMachine>* transitionAccReleased(CruiseControlStateMachine * aMachine,
      EventDataType arg);
};

#endif /* CRUISECONTROLACCSTATE_H_ */
