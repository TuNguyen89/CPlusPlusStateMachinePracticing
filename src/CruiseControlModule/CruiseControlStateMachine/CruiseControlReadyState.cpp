
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

void CruiseControlReadyState::transitionSet(CruiseControl* control, unsigned int a_cruiseSpeed)
{
   if (a_cruiseSpeed < MIN_CAR_SPEED_TO_ACTIVE)
   {
      return;
   }
   control->state = new CruiseControlSetState();
   control->cruiseSpeed = a_cruiseSpeed;
   delete this;
}