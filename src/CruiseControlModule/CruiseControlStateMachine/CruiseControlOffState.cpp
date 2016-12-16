
#include "CruiseControlOffState.h"
#include "CruiseControl.h"

CruiseControlOffState::CruiseControlOffState() {
	// TODO Auto-generated constructor stub
   stateName = "Off";
}

CruiseControlOffState::~CruiseControlOffState() {
	// TODO Auto-generated destructor stub
}

void CruiseControlOffState::transitionOn(CruiseControl* a_cruiseControl) {
   
   //a_cruiseControl->setNewState(new CruiseControlReadyState());
   delete this;
}