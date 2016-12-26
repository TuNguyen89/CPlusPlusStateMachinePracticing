#ifndef CRUISECONTROLOFFSTATE_H_
#define CRUISECONTROLOFFSTATE_H_

#include "CruiseControlState.h"


class CruiseControl;
class CruiseControlStateMachine;

class CruiseControlOffState : public CruiseControlState <CruiseControlStateMachine> 
{
public:
	CruiseControlOffState();
	virtual ~CruiseControlOffState();

   CruiseControlState<CruiseControlStateMachine>* transitionOn(CruiseControlStateMachine * aMachine, const unsigned int & arg);
   
};

#endif /* CRUISECONTROLOFFSTATE_H_ */
