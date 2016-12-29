/**
* @ingroup Adaptive Cruise Control Module
* Adaptive Cruise control module, handle cruise control feature
* Adaptive Cruise control use the implementation of table driven state machine
* more information could be found at: http://codeproject.com/Articles/1087619/State-Machine-Design-in-Cplusplus
*/

/*! Adaptive Cruise Control module
   The Cruise Control module receive the user input and change it state to active.
   Be noted that, the minimum speed to active cruise control is 70 Km/h
   There are number of user input: on, resume, brake, cancel, gas, vehicledectect, vehicledisappear
   There are number of state: Off, Standby, Speed, Gap.

   Example Usage:
    @code
       AdaptiveCruiseControl control;
       control.handleAction(E_ACTION_PRESS_ACC_BUTTON, MotorData*);
       control.handleAction(E_ACTION_PRESS_RESUME_BUTTON, MotorData* );
       control.getStatus();
    @endcode
*/
#ifndef ADAPTIVECRUISECONTROL_H_
#define ADAPTIVECRUISECONTROL_H_

#include "StateMachine.h"
#include <string>

const unsigned int MIN_ACC_CAR_SPEED_TO_ACTIVE = 40; //Minimum car speed to 40kms

/**
* Data Structure 
* structure to hold motor data, such as speed.
*/
struct MotorData : public EventData
{
   unsigned int speed;
};

/**
* Action Enum
* The avaiable action that adaptive cruise control could handle.
*/
enum AccActionEnum 
{
   E_ACTION_PRESS_ACC_BUTTON,
   E_ACTION_PRESS_SET_BUTTON,
   E_ACTION_PRESS_RESUME_BUTTON,
   E_ACTION_PUSH_BRAKE_PEDAL,
   E_ACTION_PUSH_GAS_PEDAL,
   E_ACTION_PUSH_CANCEL_BUTTON,
   E_ACTION_DECTECT_VEHICLE,
   E_ACTION_NOT_DECTECT_VEHICLE,
   E_ACTION_ACC_INVALID
};

class AdaptiveCruiseControl : public StateMachine
{
public:
   /**
   * AdaptiveCruiseControl constructor.
   * Construct Adaptive Cruise Control module
   */
   AdaptiveCruiseControl();

   /**
   * AdaptiveCruiseControl destructor.
   * Destruct Adaptive Cruise Control module
   */
   virtual ~AdaptiveCruiseControl();

   /**
   * Hanlde action from outside world
   * @return current adaptive cruise control state and cruise speed.
   */
   std::string getStatus() const;
   
   /**
   * Hanlde action from outside world
   * @param action action type
   * @param motor data structure.
   * @return void
   */
   void handleAction(AccActionEnum action, MotorData* pData);

private:

   AdaptiveCruiseControl(const AdaptiveCruiseControl&);
   AdaptiveCruiseControl& operator=(const AdaptiveCruiseControl&);

   //internal action funtion.
   void pressAccButton(MotorData*);
   void pressSetButton(MotorData*);
   void pressResumeButton(MotorData* pData);
   void pressCancelAndPushBrakePedal(MotorData* pData);
   void PushGasPedal(MotorData* pData);
   void detectVehicle(MotorData* pData);
   void notDetectVehicle(MotorData* pData);

   unsigned int m_currentSpeed;  // current speed of adaptive cruise system.
   
   // state enumeration
   enum E_States { 
      E_STATE_OFF = 0,
      E_STATE_ARM,
      E_STATE_CAN,
      E_STATE_OVR,
      E_STATE_SPD,
      E_STATE_GAP,
      E_STATE_MAX
   };
   
   // state names enumeration
   static std::string E_StateNames[E_STATE_MAX][2];

   // off state functions
   STATE_DECLARE(AdaptiveCruiseControl, OffState, MotorData)
   // armed state functions
   STATE_DECLARE(AdaptiveCruiseControl, ArmedState, MotorData)
   // cancel state functions
   STATE_DECLARE(AdaptiveCruiseControl, CancelState, MotorData)
   // override state functions
   STATE_DECLARE(AdaptiveCruiseControl, OverrideState, MotorData)
   // speed state functions
   STATE_DECLARE(AdaptiveCruiseControl, SpeedState, MotorData)
   // gap state functions
   STATE_DECLARE(AdaptiveCruiseControl, GapState, MotorData)
   
   // speed guard functions
   GUARD_DECLARE(AdaptiveCruiseControl, GuardSpeedState, MotorData)

   // state map to define state function order
   BEGIN_STATE_MAP_EX
      STATE_MAP_ENTRY_EX(&OffState)
      STATE_MAP_ENTRY_EX(&ArmedState)
      STATE_MAP_ENTRY_EX(&CancelState)
      STATE_MAP_ENTRY_EX(&OverrideState)
      STATE_MAP_ENTRY_ALL_EX(&SpeedState, &GuardSpeedState, 0, 0)
      STATE_MAP_ENTRY_EX(&GapState)
   END_STATE_MAP_EX

};

#endif /* ADAPTIVECRUISECONTROL_H_ */
