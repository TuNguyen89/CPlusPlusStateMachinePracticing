

#include "CruiseControlActiveState.h"
#include "CruiseControlOffState.h"
#include "CruiseControl.h"

CruiseControlActiveState::CruiseControlActiveState()
{

}

CruiseControlActiveState::~CruiseControlActiveState() 
{
	
}

void CruiseControlActiveState::transitionOn(CruiseControl* a_cruiseControl) 
{  
   //Transition from Active -> Off
   a_cruiseControl->state = new CruiseControlOffState();
   //Reset the cruise Speed
   a_cruiseControl->cruiseSpeed = 0;
   delete this;
}