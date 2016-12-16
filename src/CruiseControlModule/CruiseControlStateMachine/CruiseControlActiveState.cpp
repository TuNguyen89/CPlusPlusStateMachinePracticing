

#include "CruiseControlActiveState.h"
#include "CruiseControlOffState.h"
#include "CruiseControl.h"

CruiseControlActiveState::CruiseControlActiveState() {
	// TODO Auto-generated constructor stub

}

CruiseControlActiveState::~CruiseControlActiveState() {
	// TODO Auto-generated destructor stub
}

void CruiseControlActiveState::transitionOn(CruiseControl* a_cruiseControl) {
   
    a_cruiseControl->setNewState(new CruiseControlOffState());
   delete this;
}