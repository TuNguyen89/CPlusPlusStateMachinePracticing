#ifndef CRUISECONTROLSTATE_H_
#define CRUISECONTROLSTATE_H_

#include <string>
#include "FSM_TBaseState.h"

namespace MyNameSpace { struct f_any; }

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
   virtual CruiseControlState<FSM>*  transitionOn(FSM*, const MyNameSpace::f_any&) { return this; }
   virtual CruiseControlState<FSM>*  transitionSet(FSM*, const MyNameSpace::f_any&) { return this; }
   virtual CruiseControlState<FSM>*  transitionResume(FSM*, const MyNameSpace::f_any&) { return this; }
   virtual CruiseControlState<FSM>*  transitionBrake(FSM*, const MyNameSpace::f_any&) { return this; }
   virtual CruiseControlState<FSM>*  transitionAccPressed(FSM*, const MyNameSpace::f_any&) { return this; }
   virtual CruiseControlState<FSM>*  transitionAccReleased(FSM*, const MyNameSpace::f_any&) { return this; }

protected:
   std::string stateName;
};

#endif /* CRUISECONTROLSTATE_H_ */
