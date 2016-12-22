#pragma once
#include "AdaptiveCruiseControlState.h"
class StandbyState :
   public AdaptiveCruiseControlState
{
public:
   StandbyState();
   virtual ~StandbyState();
};

