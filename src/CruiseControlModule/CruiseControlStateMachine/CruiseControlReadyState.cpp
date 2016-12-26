
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

CruiseControlState<CruiseControlStateMachine>* CruiseControlReadyState::transitionSet(CruiseControlStateMachine * aMachine, EventDataType aVehicelSpeed)
{
   //Check guard condition here
   if (aVehicelSpeed < MIN_CAR_SPEED_TO_ACTIVE)
   {
      return this;
   }
   else
   {
      aMachine->setCruiseSpeed(aVehicelSpeed);
      return &(aMachine->mSetState);
   }
   
}