#ifndef CRUISECONTROLOFFSTATE_H_
#define CRUISECONTROLOFFSTATE_H_

#include "CruiseControlState.h"
class CruiseControl;

class CruiseControlOffState: public CruiseControlState {
public:
	CruiseControlOffState();
	virtual ~CruiseControlOffState();
    
   virtual void transitionOn(CruiseControl* a_cruiseControl);
    
};

#endif /* CRUISECONTROLOFFSTATE_H_ */
