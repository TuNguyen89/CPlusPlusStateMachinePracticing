
#ifndef CRUISECONTROLSETSTATE_H_
#define CRUISECONTROLSETSTATE_H_

#include "CruiseControlActiveState.h"

class CruiseControlSetState : public CruiseControlActiveState {
public:
	CruiseControlSetState();
	virtual ~CruiseControlSetState();
    void transitionAccPressed();
    void transitionBrake();
};

#endif /* CRUISECONTROLSETSTATE_H_ */
