
#ifndef CRUISECONTROLSETSTATE_H_
#define CRUISECONTROLSETSTATE_H_

#include "CruiseControlActiveState.h"

class CruiseControlSetState : public CruiseControlActiveState {
public:
	CruiseControlSetState();
	virtual ~CruiseControlSetState();
   virtual void transitionAccPressed(CruiseControl* a_cruiseControl);
   virtual void transitionBrake(CruiseControl* a_cruiseControl);
};

#endif /* CRUISECONTROLSETSTATE_H_ */
