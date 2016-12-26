#include "CruiseControlStateMachine.h"

CruiseControlStateMachine::CruiseControlStateMachine()
{
   //Default state is OFF
   transition(&mOffState);
}

CruiseControlStateMachine::~CruiseControlStateMachine()
{
}

void CruiseControlStateMachine::run(Event aReceivedEvent, unsigned int aInputData)
{
   if(aReceivedEvent)
   {
      dispatch(aReceivedEvent, aInputData);
   }
}

std::string CruiseControlStateMachine::getCurrentStateName()
{
   const CruiseControlState<CruiseControlStateMachine>* const state = getCurrentState();
   return state->getStateName();
}
