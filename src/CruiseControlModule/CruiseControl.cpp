#include "CruiseControl.h"
#include "CruiseControlOffState.h"

CruiseControl::CruiseControl() {
    state = new CruiseControlOffState();
    cruiseSpeed = 0;
}

CruiseControl::~CruiseControl() {
    // TODO Auto-generated destructor stub
}

void CruiseControl::handleAction(ActionEnum action) {
   
   //state.nextState(this, action);
   switch (action)
   {
      case OnAction:
         actionOn();
         break;
      default:
         break;
   }

}

std::string CruiseControl::getStatus() {
    std::string speed = std::to_string((long double)cruiseSpeed);
   return state->getStateName() + speed;
}

void CruiseControl::setNewState(CruiseControlState* newState) {
    state = newState;
}


void CruiseControl::actionOn() {
   state->transitionOn(this);
}

void CruiseControl::actionSet() {

}

void CruiseControl::actionResume() {

}

void CruiseControl::actionBrake() {

}

void CruiseControl::actionAccPressed() {

}

void CruiseControl::actionReleased() {

}

