#include "AdaptiveCruiseControl.h"
#include <iostream>
#include <sstream>
#include "assert.h"

using std::cout;
using std::endl;

enum IndexEnum {
   STATE_NAME,
   COLOR,
   MAX_INDEX
};

std::string AdaptiveCruiseControl::E_StateNames[E_STATE_MAX][MAX_INDEX] = {
      {"Off", "Black"},
      {"Armed", "Black"},
      {"Canceled", "Red"},
      {"Override", "Red"},
      {"Speed", "Green"},
      {"Gap", "Green"}
};
   
AdaptiveCruiseControl::AdaptiveCruiseControl() :
   StateMachine(E_STATE_MAX),
   m_currentSpeed(0)
{
}

AdaptiveCruiseControl::~AdaptiveCruiseControl()
{
}

std::string AdaptiveCruiseControl::getStatus() const
{
   std::stringstream strStream;
   int currentState = GetCurrentState();
   strStream << E_StateNames[currentState][STATE_NAME]<< "\t" 
             << m_currentSpeed << "\t"
             << E_StateNames[currentState][COLOR]
             << std::endl;
   return (strStream.str());
}

void AdaptiveCruiseControl::handleAction(AccActionEnum action, MotorData* pData)
{
   switch (action)
   {
      case E_ACTION_PRESS_ACC_BUTTON:
         pressAccButton(pData);
         break;

      case E_ACTION_PRESS_SET_BUTTON:
         pressSetButton(pData);
         break;
         
      case E_ACTION_PRESS_RESUME_BUTTON:
         pressResumeButton(pData);
         break;
      
      case E_ACTION_PUSH_CANCEL_BUTTON:
      case E_ACTION_PUSH_BRAKE_PEDAL:
         pressCancelAndPushBrakePedal(pData);
         break;

      case E_ACTION_PUSH_GAS_PEDAL:
         PushGasPedal(pData);
         break;

      case E_ACTION_DECTECT_VEHICLE:
         detectVehicle(pData);
         break;

      case E_ACTION_NOT_DECTECT_VEHICLE:
         notDetectVehicle(pData);
         break;

      case E_ACTION_ACC_INVALID:
      default:
         //Debug log: Invalid action
         assert(false);
         break;
   }
}

void AdaptiveCruiseControl::pressAccButton(MotorData* pData)
{
   BEGIN_TRANSITION_MAP                      // - Current State -
     TRANSITION_MAP_ENTRY (E_STATE_ARM)      // E_STATE_OFF
     TRANSITION_MAP_ENTRY (E_STATE_OFF)      // E_STATE_ARM
     TRANSITION_MAP_ENTRY (E_STATE_OFF)      // E_STATE_CAN
     TRANSITION_MAP_ENTRY (E_STATE_OFF)      // E_STATE_OVR       
     TRANSITION_MAP_ENTRY (E_STATE_OFF)      // E_STATE_SPD      
     TRANSITION_MAP_ENTRY (E_STATE_OFF)      // E_STATE_GAP
   END_TRANSITION_MAP(pData)
}

void AdaptiveCruiseControl::pressSetButton(MotorData* pData)
{
   BEGIN_TRANSITION_MAP                      // - Current State -
     TRANSITION_MAP_ENTRY (EVENT_IGNORED)      // E_STATE_OFF
     TRANSITION_MAP_ENTRY (E_STATE_SPD)      // E_STATE_ARM
     TRANSITION_MAP_ENTRY (EVENT_IGNORED)      // E_STATE_CAN
     TRANSITION_MAP_ENTRY (EVENT_IGNORED)      // E_STATE_OVR       
     TRANSITION_MAP_ENTRY (EVENT_IGNORED)      // E_STATE_SPD      
     TRANSITION_MAP_ENTRY (EVENT_IGNORED)      // E_STATE_GAP
   END_TRANSITION_MAP(pData)
}

void AdaptiveCruiseControl::pressResumeButton(MotorData* pData)
{
   BEGIN_TRANSITION_MAP                      // - Current State -
     TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_OFF
     TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_ARM
     TRANSITION_MAP_ENTRY (E_STATE_SPD)      // E_STATE_CAN
     TRANSITION_MAP_ENTRY (E_STATE_SPD)      // E_STATE_OVR       
     TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_SPD      
     TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_GAP
   END_TRANSITION_MAP(pData)
}

void AdaptiveCruiseControl::pressCancelAndPushBrakePedal(MotorData* pData)
{
   BEGIN_TRANSITION_MAP                      // - Current State -
     TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_OFF
     TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_ARM
     TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_CAN
     TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_OVR       
     TRANSITION_MAP_ENTRY (E_STATE_CAN)      // E_STATE_SPD      
     TRANSITION_MAP_ENTRY (E_STATE_CAN)      // E_STATE_GAP
   END_TRANSITION_MAP(pData)
}

void AdaptiveCruiseControl::PushGasPedal(MotorData* pData)
{
   BEGIN_TRANSITION_MAP                      // - Current State -
     TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_OFF
     TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_ARM
     TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_CAN
     TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_OVR       
     TRANSITION_MAP_ENTRY (E_STATE_OVR)      // E_STATE_SPD      
     TRANSITION_MAP_ENTRY (E_STATE_OVR)      // E_STATE_GAP
   END_TRANSITION_MAP(pData)
}

void AdaptiveCruiseControl::detectVehicle(MotorData* pData)
{
    BEGIN_TRANSITION_MAP                        // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_OFF
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_ARM
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_CAN
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_OVR       
        TRANSITION_MAP_ENTRY (E_STATE_GAP)      // E_STATE_SPD      
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_GAP
    END_TRANSITION_MAP(pData)
}

void AdaptiveCruiseControl::notDetectVehicle(MotorData* pData)
{
    BEGIN_TRANSITION_MAP                        // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_OFF
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_ARM
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_CAN
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_OVR       
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)    // E_STATE_SPD      
        TRANSITION_MAP_ENTRY (E_STATE_SPD)      // E_STATE_GAP
    END_TRANSITION_MAP(pData)
}

STATE_DEFINE(AdaptiveCruiseControl, OffState, MotorData)
{
	cout << "Current State is OffState"<< endl;
   m_currentSpeed = 0;
}

STATE_DEFINE(AdaptiveCruiseControl, ArmedState, MotorData)
{
	cout << "Current State is ArmedState"<< endl;

}

STATE_DEFINE(AdaptiveCruiseControl, CancelState, MotorData)
{
	cout << "Current State is CancelState"<< endl;
}

STATE_DEFINE(AdaptiveCruiseControl, OverrideState, MotorData)
{
	cout << "Current State is OverrideState"<< endl;
}

STATE_DEFINE(AdaptiveCruiseControl, SpeedState, MotorData)
{
	cout << "Current State is SpeedState"<< endl;
   if (GetCurrentState() == E_STATE_ARM)
   {
      m_currentSpeed = data->speed;
   }
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