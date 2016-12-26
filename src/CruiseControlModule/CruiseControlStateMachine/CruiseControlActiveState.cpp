

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
   //TODO
   //Transition from Active -> Off
   //Reset the cruise Speed
   return &(aMachine->mOffState);
}

//void CruiseControlActiveState::transitionOn(CruiseControl* a_cruiseControl) 
//{  
   //Transition from Active -> Off
   //Reset the cruise Speed

//}