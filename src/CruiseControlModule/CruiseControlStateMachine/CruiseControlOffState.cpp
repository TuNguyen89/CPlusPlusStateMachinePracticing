
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
                                                                                   const MyNameSpace::f_any& arg)
{
   return &(aMachine->mReadyState);
}