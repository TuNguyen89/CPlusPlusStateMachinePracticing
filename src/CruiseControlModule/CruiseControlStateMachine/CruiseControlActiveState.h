
#ifndef CRUISECONTROLACTIVESTATE_H_
#define CRUISECONTROLACTIVESTATE_H_

#include "CruiseControlState.h"

class CruiseControl;

class CruiseControlActiveState: public CruiseControlState {
public:
    CruiseControlActiveState();
    virtual ~CruiseControlActiveState();
    void transitionOn(CruiseControl* a_cruiseControl);
};

#endif /* CRUISECONTROLACTIVESTATE_H_ */
