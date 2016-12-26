#ifndef CRUISECONTROLSTATE_H_
#define CRUISECONTROLSTATE_H_

#include <string>
#include "FSM_TBaseState.h"


template<class FSM>
class CruiseControlState : public FSM_TIBaseState <FSM, CruiseControlState<FSM>>
{
public:
   CruiseControlState() {} ;
   virtual ~CruiseControlState() {} ;

   const std::string getStateName() const
   {
      return stateName; 
   }


   //New design
   virtual CruiseControlState<FSM>*  transitionOn(FSM*, EventDataType) { return this; }
   virtual CruiseControlState<FSM>*  transitionSet(FSM*, EventDataType) { return this; }
   virtual CruiseControlState<FSM>*  transitionResume(FSM*, EventDataType) { return this; }
   virtual CruiseControlState<FSM>*  transitionBrake(FSM*, EventDataType) { return this; }
   virtual CruiseControlState<FSM>*  transitionAccPressed(FSM*, EventDataType) { return this; }
   virtual CruiseControlState<FSM>*  transitionAccReleased(FSM*, EventDataType) { return this; }


protected:
   std::string stateName;
};

#endif /* CRUISECONTROLSTATE_H_ */
