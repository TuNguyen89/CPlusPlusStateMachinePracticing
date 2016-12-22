#include "AdaptiveCruiseControl.h"
#include "ActiveState.h"
#include "GapControlState.h"
#include "OffState.h"
#include "SpeedControlState.h"
#include "StandbyState.h"


AdaptiveCruiseControl::AdaptiveCruiseControl()
   :  mSpeedControlState(SpeedControlState()),
      mGapControlState(GapControlState()),
      mOffState(OffState()),
      mStandbyState(StandbyState()),
      pCurrentState (&mOffState)
{
   
}


AdaptiveCruiseControl::~AdaptiveCruiseControl()
{
}
