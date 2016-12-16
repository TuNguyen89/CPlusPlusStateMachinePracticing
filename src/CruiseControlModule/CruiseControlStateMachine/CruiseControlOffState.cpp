
#include "CruiseControlOffState.h"
#include "CruiseControl.h"
#include "CruiseControlReadyState.h"

CruiseControlOffState::CruiseControlOffState() 
{
   stateName = "Off";
}

CruiseControlOffState::~CruiseControlOffState() {
	
}

void CruiseControlOffState::transitionOn(CruiseControl* a_cruiseControl) {
   
   a_cruiseControl->state =  new CruiseControlReadyState();
   delete this;
}