

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
                                                                                           EventDataType arg)
{
   //Action: accP
   //Transition: Set -> Wait
   return &(aMachine->mAccState);
}

CruiseControlState<CruiseControlStateMachine>* CruiseControlSetState::transitionBrake(CruiseControlStateMachine * aMachine,
                                                                                      EventDataType arg)
{
   //Action: Brake
   //Transition: Set -> Wait
   return &(aMachine->mWait);
}

CruiseControlState<CruiseControlStateMachine>* CruiseControlSetState::transitionSet(CruiseControlStateMachine * aMachine, EventDataType arg)
{
   //TODO: Check the current speed and set the new one if appropriate
   return this;
}
