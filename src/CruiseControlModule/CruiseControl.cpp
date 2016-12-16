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
    
}

void CruiseControl::handleAction(ActionEnum action, unsigned int a_currentCarSpeed)
{
   
   switch (action)
   {
      case OnAction:

         actionOn();
         break;
      
      case SetAction:

         actionSet(a_currentCarSpeed);
         break;
      
      case BreakAction:

         actionBrake();
         break;

      case AccPressedAction:

         actionAccPressed();
         break;

      case AccReleasedAction:
         
         actionReleased();
         break;

      case ResumAction:

         actionResume();
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

void CruiseControl::actionOn()
{
   state->transitionOn(this);
}

void CruiseControl::actionSet(unsigned int a_currentCarSpeed)
{
   if (a_currentCarSpeed >= MIN_CAR_SPEED_TO_ACTIVE)
   {
      state->transitionSet(this, a_currentCarSpeed);
   }
}

void CruiseControl::actionBrake()
{
   state->transitionBrake(this);
}

void CruiseControl::actionAccPressed()
{
   state->transitionAccPressed(this);
}

void CruiseControl::actionReleased()
{
   state->transitionAccReleased(this);
}

void CruiseControl::actionResume()
{
   state->transitionResume(this);
}