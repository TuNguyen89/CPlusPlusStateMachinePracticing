/**
* @ingroup Cruise Control Module
* Cruise control module, handle cruise control feature
*/


#include "CruiseControl.h"

#include <assert.h>
#include <sstream>

CruiseControl::CruiseControl()
{
   cruiseSpeed = 0;
   mStateMachine.transition(&(mStateMachine.mOffState));
}

CruiseControl::~CruiseControl() 
{
   //delete state;
}

void CruiseControl::handleAction(ActionEnum action, unsigned int a_currentCarSpeed)
{

   CruiseControlStateMachine::Event eventToHandle = 0;
   switch (action)
   {
      case OnAction:
         eventToHandle = &CruiseControlState<CruiseControlStateMachine>::transitionOn;
         break;
      
      case SetAction:
         eventToHandle = &CruiseControlState<CruiseControlStateMachine>::transitionSet;
         break;
      
      case BreakAction:
         eventToHandle = &CruiseControlState<CruiseControlStateMachine>::transitionBrake;
         break;

      case AccPressedAction:
         eventToHandle = &CruiseControlState<CruiseControlStateMachine>::transitionAccPressed;
         break;

      case AccReleasedAction:
         eventToHandle = &CruiseControlState<CruiseControlStateMachine>::transitionAccReleased;
         break;

      case ResumAction:
         eventToHandle = &CruiseControlState<CruiseControlStateMachine>::transitionResume;
         break;

      case InvalidAction:
      default:
         //Debug log: Invalid action
         assert(false);
         break;
   }

   mStateMachine.run(eventToHandle, a_currentCarSpeed);
}

std::string CruiseControl::getStatus() {

   std::stringstream strStream;
   strStream << mStateMachine.getCurrentStateName() << "\t" << cruiseSpeed << std::endl;
   
   return (strStream.str());
}