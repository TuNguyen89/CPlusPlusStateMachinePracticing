

#include "CruiseControlSetState.h"
#include "CruiseControl.h"
#include "CruiseControlAccState.h"
#include "CruiseControlWaitState.h"

CruiseControlSetState::CruiseControlSetState() 
{
   stateName = "Set"; 
}

CruiseControlSetState::~CruiseControlSetState() 
{
	// TODO Auto-generated destructor stub
}


CruiseControlState<CruiseControlStateMachine>* CruiseControlSetState::transitionAccPressed(CruiseControlStateMachine * aMachine, 
                                                                                           const MyNameSpace::f_any & arg)
{
   //Action: accP
   //Transition: Set -> Wait
   return &(aMachine->mAccState);
}

CruiseControlState<CruiseControlStateMachine>* CruiseControlSetState::transitionBrake(CruiseControlStateMachine * aMachine,
                                                                                      const MyNameSpace::f_any & arg)
{
   //Action: Brake
   //Transition: Set -> Wait
   return &(aMachine->mWait);
}

CruiseControlState<CruiseControlStateMachine>* CruiseControlSetState::transitionSet(CruiseControlStateMachine * aMachine, const MyNameSpace::f_any & arg)
{
   //TODO: Check the current speed and set the new one if appropriate
   return this;
}
