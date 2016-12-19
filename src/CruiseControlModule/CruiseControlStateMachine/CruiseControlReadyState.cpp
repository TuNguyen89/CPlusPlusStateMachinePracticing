
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
   control->state = new CruiseControlSetState();
   control->cruiseSpeed = a_cruiseSpeed;
   delete this;
}