
#include "CruiseControlOffState.h"
#include "CruiseControl.h"

CruiseControlOffState::CruiseControlOffState() 
{
   stateName = "Off";
}

CruiseControlOffState::~CruiseControlOffState() 
{
	
}

CruiseControlState<CruiseControlStateMachine>* CruiseControlOffState::transitionOn(CruiseControlStateMachine* aMachine,
                                                                                   EventDataType arg)
{
   return &(aMachine->mReadyState);
}