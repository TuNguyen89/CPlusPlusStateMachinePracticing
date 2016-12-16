
#ifndef CRUISECONTROLWAITSTATE_H_
#define CRUISECONTROLWAITSTATE_H_

#include "CruiseControlActiveState.h"

class CruiseControl;

class CruiseControlWaitState : public CruiseControlActiveState {
public:
	CruiseControlWaitState();
	virtual ~CruiseControlWaitState();
   virtual void transitionResume(CruiseControl* a_cruiseControl);
   virtual void transitionAccReleased(CruiseControl* a_cruiseControl);
};

#endif /* CRUISECONTROLWAITSTATE_H_ */
