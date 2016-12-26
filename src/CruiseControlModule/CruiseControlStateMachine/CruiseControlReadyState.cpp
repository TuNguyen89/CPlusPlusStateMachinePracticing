
#include "CruiseControlReadyState.h"
#include "CruiseControlSetState.h"
#include "CruiseControl.h"

CruiseControlReadyState::CruiseControlReadyState()
{
   stateName = "Ready";
}

CruiseControlReadyState::~CruiseControlReadyState() 
{
	
}

CruiseControlState<CruiseControlStateMachine>* CruiseControlReadyState::transitionSet(CruiseControlStateMachine * aMachine, const MyNameSpace::f_any &)
{
   //TODO Check guard condition here
   //if (a_cruiseSpeed < MIN_CAR_SPEED_TO_ACTIVE)
   return &(aMachine->mSetState);
}