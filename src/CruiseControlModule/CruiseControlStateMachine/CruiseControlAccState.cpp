

#include "CruiseControlAccState.h"
#include "CruiseControl.h"
#include "CruiseControlSetState.h"

CruiseControlAccState::CruiseControlAccState() 
{
   stateName = "Acc";
}

CruiseControlAccState::~CruiseControlAccState() 
{
	// TODO Auto-generated destructor stub
}

CruiseControlState<CruiseControlStateMachine>* CruiseControlAccState::transitionAccReleased(CruiseControlStateMachine * aMachine, EventDataType arg)
{
   //Action: accR
   //Transition: Acc -> Set
   return &(aMachine->mSetState);
}
