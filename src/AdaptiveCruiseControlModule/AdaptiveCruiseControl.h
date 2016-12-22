#pragma once

#include "AdaptiveCruiseControlState.h"


/**
* Action Enum
* The avaiable action that cruise control could handle
*/
enum ActionEnum
{
   AccButtonAction,
   ResumeButtonAction,
   BrakePushedAction,
   GasPushedAction,
   CancelButtonAction,
   TargetVehicelDetected,
   TargetVehicelDisappear,

   InvalidAction
};

class AdaptiveCruiseControl
{
public:
   AdaptiveCruiseControl();
   virtual ~AdaptiveCruiseControl();

   ///
   /// Public member functions
   ///
   void receiveExternalEvent(char aEventType);

private:
   AdaptiveCruiseControlState mSpeedControlState;
   AdaptiveCruiseControlState mGapControlState;
   AdaptiveCruiseControlState mOffState;
   AdaptiveCruiseControlState mStandbyState;

   AdaptiveCruiseControlState* pCurrentState;


   void nextState(const AdaptiveCruiseControlState& aNextState);
   void handleCruiseSwitchRequest(ActionEnum aActionType);
   void handleBrakeSwitchRequest();
   void handleGasPushRequest();
   void handleVehicelSpeedChanged();

};

