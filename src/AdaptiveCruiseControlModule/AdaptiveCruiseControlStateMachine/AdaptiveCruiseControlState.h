#pragma once
class AdaptiveCruiseControlState
{
public:
   AdaptiveCruiseControlState();
   virtual ~AdaptiveCruiseControlState();
   // Handle Acc button press event
   virtual void onAccButton();
   // Handle Cancel button press event
   virtual void onCancelButton();
   // Hanlde Resume button press
   virtual void onResumeButton();
   // Handle Brake Pushed event
   virtual void onBrakePushed();
   // Handle Gas pdl pushed
   virtual void onGasPushed();
   // Handle Target Vehicel Disappear event
   void onTargetVehicelDisappear();
   // Hanlde Target Vehicel detected
   virtual void onTargetVehicelDetected();
};

