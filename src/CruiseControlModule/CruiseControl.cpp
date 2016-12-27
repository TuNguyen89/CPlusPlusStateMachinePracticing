/**
* @ingroup Cruise Control Module
* Cruise control module, handle cruise control feature
*/


#include "CruiseControl.h"

#include <assert.h>
#include <sstream>

CruiseControl::CruiseControl()
{
}

CruiseControl::~CruiseControl() 
{
}

void CruiseControl::handleAction(ActionEnum action, EventDataType a_currentCarSpeed)
{

   CruiseControlStateMachine::Event eventToHandle = 0;
   switch (action)
   {
      case E_ACTION_ON:
         eventToHandle = &CruiseControlState<CruiseControlStateMachine>::transitionOn;
         break;
      
      case E_ACTION_SET:
         eventToHandle = &CruiseControlState<CruiseControlStateMachine>::transitionSet;
         break;
      
      case E_ACTION_BRAKE:
         eventToHandle = &CruiseControlState<CruiseControlStateMachine>::transitionBrake;
         break;

      case E_ACTION_ACC_PRESSED:
         eventToHandle = &CruiseControlState<CruiseControlStateMachine>::transitionAccPressed;
         break;

      case E_ACTION_ACC_RELEASED:
         eventToHandle = &CruiseControlState<CruiseControlStateMachine>::transitionAccReleased;
         break;

      case E_ACTION_RESUME:
         eventToHandle = &CruiseControlState<CruiseControlStateMachine>::transitionResume;
         break;

      case E_ACTION_INVALID:
      default:
         //Debug log: Invalid action
         assert(false);
         break;
   }

   mStateMachine.run(eventToHandle, a_currentCarSpeed);
}

std::string CruiseControl::getStatus() const
{

   std::stringstream strStream;
   strStream << mStateMachine.getCurrentStateName() << "\t" << mStateMachine.getCruiseSpeed() << std::endl;
   
   return (strStream.str());
}