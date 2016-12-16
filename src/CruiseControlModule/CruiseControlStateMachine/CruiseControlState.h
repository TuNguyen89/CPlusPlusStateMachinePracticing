#ifndef CRUISECONTROLSTATE_H_
#define CRUISECONTROLSTATE_H_

#include <string>
/*
#include "CruiseControlActiveState.h"
#include "CruiseControlOffState.h"
#include "CruiseControlAccState.h"
#include "CruiseControlReadyState.h"
#include "CruiseControlSetState.h"
#include "CruiseControlWaitState.h"
*/
class CruiseControl;

class CruiseControlState {
public:
   CruiseControlState();
   virtual ~CruiseControlState();

   virtual void transitionOn(CruiseControl* cruiseControl) {};
   void transitionSet();
   void transitionResume();
   void transitionBrake();
   void transitionAccPressed();
   void transitionAccReleased();
   std::string getStateName() { return stateName; }
   virtual void setStateName(std::string name) { stateName = name; }
   std::string stateName;
};

#endif /* CRUISECONTROLSTATE_H_ */
