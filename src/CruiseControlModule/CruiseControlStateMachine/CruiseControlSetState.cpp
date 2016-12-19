

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

void CruiseControlSetState::transitionAccPressed(CruiseControl* a_cruiseControl)
{

   //Action: accP
   //Transition: Set -> Wait
   a_cruiseControl->state = new CruiseControlAccState();
   delete this;
}

void CruiseControlSetState::transitionBrake(CruiseControl* a_cruiseControl)
{
   //Action: Brake
   //Transition: Set -> Wait
   a_cruiseControl->state = new CruiseControlWaitState();
   delete this;
}