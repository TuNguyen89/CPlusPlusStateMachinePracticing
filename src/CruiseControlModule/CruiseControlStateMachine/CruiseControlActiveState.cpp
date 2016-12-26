

#include "CruiseControlActiveState.h"
#include "CruiseControlOffState.h"
#include "CruiseControl.h"

CruiseControlActiveState::CruiseControlActiveState()
{

}

CruiseControlActiveState::~CruiseControlActiveState() 
{
	
}

CruiseControlState<CruiseControlStateMachine>* CruiseControlActiveState::transitionOn(CruiseControlStateMachine * aMachine, EventDataType arg)
{
   //Transition from Active -> Off
   //Reset the cruise Speed
   return &(aMachine->mOffState);
}