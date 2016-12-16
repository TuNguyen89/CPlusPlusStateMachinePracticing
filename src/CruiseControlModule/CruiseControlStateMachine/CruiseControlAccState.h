
#ifndef CRUISECONTROLACCSTATE_H_
#define CRUISECONTROLACCSTATE_H_

#include "CruiseControlActiveState.h"

class CruiseControlAccState : public CruiseControlActiveState {
public:
	CruiseControlAccState();
	virtual ~CruiseControlAccState();
   virtual void transitionAccReleased(CruiseControl* a_cruiseControl);
};

#endif /* CRUISECONTROLACCSTATE_H_ */
