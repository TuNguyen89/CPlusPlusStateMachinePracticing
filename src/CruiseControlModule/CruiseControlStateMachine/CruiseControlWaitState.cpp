

#include "CruiseControlWaitState.h"
#include "CruiseControl.h"
#include "CruiseControlSetState.h"
#include "CruiseControlOffState.h"

CruiseControlWaitState::CruiseControlWaitState() 
{
  
   stateName = "Wait";
}

CruiseControlWaitState::~CruiseControlWaitState() 
{
	// TODO Auto-generated destructor stub
}


void CruiseControlWaitState::transitionResume(CruiseControl* a_cruiseControl)
{
   //Action: Resume
   //Transition: Wait -> Set
   a_cruiseControl->state = new CruiseControlSetState();
   delete this;
}

void CruiseControlWaitState::transitionAccReleased(CruiseControl* a_cruiseControl)
{

   //Action: AccR
   //Transition: Wait -> OFF
   a_cruiseControl->state = new CruiseControlOffState();
   a_cruiseControl->cruiseSpeed = 0;
   delete this;
}