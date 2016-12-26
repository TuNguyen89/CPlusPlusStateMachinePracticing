#include "CruiseControlStateMachine.h"

CruiseControlStateMachine::CruiseControlStateMachine()
         : cruiseSpeed(0)
{
   //Default state is OFF
   transition(&mOffState);
}

CruiseControlStateMachine::~CruiseControlStateMachine()
{
}

void CruiseControlStateMachine::run(Event aReceivedEvent, EventDataType aInputData)
{
   if(aReceivedEvent)
   {
      dispatch(aReceivedEvent, aInputData);
   }
}

std::string CruiseControlStateMachine::getCurrentStateName() const
{
   const CruiseControlState<CruiseControlStateMachine>* const state = getCurrentState();
   return state->getStateName();
}
