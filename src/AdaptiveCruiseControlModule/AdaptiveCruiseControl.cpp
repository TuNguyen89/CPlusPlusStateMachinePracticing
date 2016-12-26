#include "AdaptiveCruiseControl.h"
#include <iostream>
#include <sstream>
#include "assert.h"

using namespace std;

std::string AdaptiveCruiseControl::E_StateNames[E_STATE_MAX] = {
      "Off",
      "Standby",
      "Speed",
      "Gap"
   };
   
AdaptiveCruiseControl::AdaptiveCruiseControl() :
   StateMachine(E_STATE_MAX),
   m_currentSpeed(0)
{
}

AdaptiveCruiseControl::~AdaptiveCruiseControl()
{
}

std::string AdaptiveCruiseControl::getStatus()
{
   std::stringstream strStream;
   strStream << E_StateNames[GetCurrentState()] << "\t" << m_currentSpeed << std::endl;
   return (strStream.str());
}

void AdaptiveCruiseControl::handleAction(AccActionEnum action, MotorData* pData)
{
   switch (action)
   {
      case AccButtonAction:
         setAccButton(pData);
         break;
      
      case ResumeButtonAction:
         setResumeButton(pData);
         break;
      
      case CancelButtonAction:
      case BrakePushedAction:
      case GasPushedAction:
         setBrakeCancelGas(pData);
         break;

      case TargetVehicelDetected:
         setVehicleDetected(pData);
         break;

      case TargetVehicelDisappear:
         setNotVehicleDetected(pData);
         break;

      case AccInvalidAction:
      default:
         //Debug log: Invalid action
         assert(false);
         break;
   }
}

void AdaptiveCruiseControl::setAccButton(MotorData* pData)
{
    BEGIN_TRANSITION_MAP                      // - Current State -
        TRANSITION_MAP_ENTRY (E_STATE_SPD)    // E_STATE_OFF       
        TRANSITION_MAP_ENTRY (E_STATE_OFF)    // E_STATE_STANDBY       
        TRANSITION_MAP_ENTRY (E_STATE_OFF)    // E_STATE_SPD      
        TRANSITION_MAP_ENTRY (E_STATE_OFF)    // E_STATE_GAP
    END_TRANSITION_MAP(pData)
}

void AdaptiveCruiseControl::setResumeButton(MotorData* pData)
{
    BEGIN_TRANSITION_MAP                      // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // E_STATE_OFF       
        TRANSITION_MAP_ENTRY (E_STATE_SPD)    // E_STATE_STANDBY       
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // E_STATE_SPD      
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // E_STATE_GAP
    END_TRANSITION_MAP(pData)
}

void AdaptiveCruiseControl::setBrakeCancelGas(MotorData* pData)
{
    BEGIN_TRANSITION_MAP                        // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_OFF       
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_STANDBY       
        TRANSITION_MAP_ENTRY (E_STATE_STANDBY)  // E_STATE_SPD      
        TRANSITION_MAP_ENTRY (E_STATE_STANDBY)  // E_STATE_GAP
    END_TRANSITION_MAP(pData)
}

void AdaptiveCruiseControl::setVehicleDetected(MotorData* pData)
{
    BEGIN_TRANSITION_MAP                        // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_OFF       
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_STANDBY       
        TRANSITION_MAP_ENTRY (E_STATE_GAP)      // E_STATE_SPD      
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_GAP
    END_TRANSITION_MAP(pData)
}

void AdaptiveCruiseControl::setNotVehicleDetected(MotorData* pData)
{
    BEGIN_TRANSITION_MAP                        // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_OFF       
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_STANDBY       
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_SPD      
        TRANSITION_MAP_ENTRY (E_STATE_SPD)      // E_STATE_GAP
    END_TRANSITION_MAP(pData)
}

STATE_DEFINE(AdaptiveCruiseControl, OffState, MotorData)
{
	cout << "Current State is OffState"<< endl;
   m_currentSpeed = 0;
}

STATE_DEFINE(AdaptiveCruiseControl, StandbyState, MotorData)
{
	cout << "Current State is StandbyState"<< endl;
}

STATE_DEFINE(AdaptiveCruiseControl, SpeedState, MotorData)
{
	cout << "Current State is SpeedState"<< endl;
   m_currentSpeed = data->speed;
}

STATE_DEFINE(AdaptiveCruiseControl, GapState, MotorData)
{
	cout << "Current State is GapState"<< endl;
}

// Guard condition to detemine whether SpeedState state is executed.
GUARD_DEFINE(AdaptiveCruiseControl, GuardSpeedState, MotorData)
{
	cout << "Checking GuardSpeedState" << endl;
	if (data->speed > MIN_ACC_CAR_SPEED_TO_ACTIVE)
   {
		return TRUE;
   }
	else
   {
		return FALSE;
   }
}