#ifndef CRUISECONTROLREADYSTATE_H_
#define CRUISECONTROLREADYSTATE_H_

#include "CruiseControlState.h"
#include "CruiseControlActiveState.h"

class CruiseControl;

class CruiseControlReadyState: public CruiseControlActiveState {
public:
   CruiseControlReadyState();
   virtual ~CruiseControlReadyState();
   virtual void transitionSet(CruiseControl* control, unsigned int a_cruiseSpeed);
};

#endif /* CRUISECONTROLREADYSTATE_H_ */
