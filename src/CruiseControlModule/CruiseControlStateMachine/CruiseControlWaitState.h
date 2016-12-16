
#ifndef CRUISECONTROLWAITSTATE_H_
#define CRUISECONTROLWAITSTATE_H_

#include "CruiseControlActiveState.h"

class CruiseControlWaitState : public CruiseControlActiveState {
public:
	CruiseControlWaitState();
	virtual ~CruiseControlWaitState();
    void transitionResume();
};

#endif /* CRUISECONTROLWAITSTATE_H_ */
