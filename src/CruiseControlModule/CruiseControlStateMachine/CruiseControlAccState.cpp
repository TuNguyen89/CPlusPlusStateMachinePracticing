

#include "CruiseControlAccState.h"
#include "CruiseControl.h"
#include "CruiseControlSetState.h"

CruiseControlAccState::CruiseControlAccState() 
{
   stateName = "Acc";
}

CruiseControlAccState::~CruiseControlAccState() 
{
	// TODO Auto-generated destructor stub
}

void CruiseControlAccState::transitionAccReleased(CruiseControl* a_cruiseControl)
{
   //Action: accR
   //Transition: Acc -> Set
   a_cruiseControl->state = new CruiseControlSetState();
}