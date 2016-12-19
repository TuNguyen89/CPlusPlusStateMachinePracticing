/**
* @ingroup Cruise Control Module
* Cruise control module, handle cruise control feature
*/


#include "CruiseControl.h"
#include "CruiseControlOffState.h"

#include <assert.h>
#include <sstream>

CruiseControl::CruiseControl() {
    
   //Default state = OFF and cruise speed = 0
   state = new CruiseControlOffState();
   cruiseSpeed = 0;
}

CruiseControl::~CruiseControl() 
{
   delete state;
}

void CruiseControl::handleAction(ActionEnum action, unsigned int a_currentCarSpeed)
{
   switch (action)
   {
      case OnAction:

         state->transitionOn(this);
         break;
      
      case SetAction:
         state->transitionSet(this, a_currentCarSpeed);
         break;
      
      case BreakAction:

         state->transitionBrake(this);
         break;

      case AccPressedAction:

         state->transitionAccPressed(this);
         break;

      case AccReleasedAction:
         
         state->transitionAccReleased(this);
         break;

      case ResumAction:

         state->transitionResume(this);
         break;

      case InvalidAction:
      default:
         //Debug log: Invalid action
         assert(false);
         break;
   }
}

std::string CruiseControl::getStatus() {

   std::stringstream strStream;
   strStream << state->getStateName() << "\t" << cruiseSpeed << std::endl;
   
   return (strStream.str());
}