#ifndef CRUISECONTROLSTATE_H_
#define CRUISECONTROLSTATE_H_

#include <string>

class CruiseControl;

class CruiseControlState {
public:
   CruiseControlState();
   virtual ~CruiseControlState();

   virtual void transitionOn(CruiseControl* cruiseControl) {};
   virtual void transitionSet(CruiseControl* cruiseControl, unsigned int a_cruiseSpeed) {};
   virtual void transitionResume(CruiseControl* cruiseControl) {};
   virtual void transitionBrake(CruiseControl* cruiseControl) {};
   virtual void transitionAccPressed(CruiseControl* cruiseControl) {};
   virtual void transitionAccReleased(CruiseControl* cruiseControl) {};
   std::string getStateName() { return stateName; }

protected:
   std::string stateName;
};

#endif /* CRUISECONTROLSTATE_H_ */
