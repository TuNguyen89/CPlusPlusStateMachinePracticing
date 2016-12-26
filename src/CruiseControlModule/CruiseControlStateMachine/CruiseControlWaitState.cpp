

#include "CruiseControlWaitState.h"
#include "CruiseControl.h"
#include "CruiseControlSetState.h"
#include "CruiseControlOffState.h"

CruiseControlWaitState::CruiseControlWaitState() 
{
  
   stateName = "Wait";
}

CruiseControlWaitState::~CruiseControlWaitState() 
{
	// TODO Auto-generated destructor stub
}


CruiseControlState<CruiseControlStateMachine>* CruiseControlWaitState::transitionResume(CruiseControlStateMachine * aMachine, EventDataType arg)
{
   //Action: Resume
   //Transition: Wait -> Set
   return &(aMachine->mSetState);
}
