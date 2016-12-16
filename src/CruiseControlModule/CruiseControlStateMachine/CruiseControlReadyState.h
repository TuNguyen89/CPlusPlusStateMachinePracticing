#ifndef CRUISECONTROLREADYSTATE_H_
#define CRUISECONTROLREADYSTATE_H_

#include "CruiseControlState.h"
#include "CruiseControlActiveState.h"

class CruiseControl;

class CruiseControlReadyState: public CruiseControlActiveState {
public:
   CruiseControlReadyState();
   virtual ~CruiseControlReadyState();
   void transitionSet();
};

#endif /* CRUISECONTROLREADYSTATE_H_ */
