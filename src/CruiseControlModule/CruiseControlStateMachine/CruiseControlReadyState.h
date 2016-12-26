#ifndef CRUISECONTROLREADYSTATE_H_
#define CRUISECONTROLREADYSTATE_H_

#include "CruiseControlState.h"
#include "CruiseControlActiveState.h"

class CruiseControl;

class CruiseControlReadyState: public CruiseControlActiveState {
public:
   CruiseControlReadyState();
   virtual ~CruiseControlReadyState();
   
   CruiseControlState<CruiseControlStateMachine>*  transitionSet(CruiseControlStateMachine* aMachine, EventDataType aVehicelSpeed);
};

#endif /* CRUISECONTROLREADYSTATE_H_ */
