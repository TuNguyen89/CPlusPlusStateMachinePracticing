
#ifndef CruiseControlResumeState_H_
#define CruiseControlResumeState_H_

#include "CruiseControlActiveState.h"

class CruiseControlResumeState : public CruiseControlActiveState {
public:
	CruiseControlResumeState();
	virtual ~CruiseControlResumeState();
    void transitionAccPressed();
    void transitionBrake();
};

#endif /* CruiseControlResumeState_H_ */
