#ifndef CRUISECONTROLSTATEMACHINE_H_
#define CRUISECONTROLSTATEMACHINE_H_

#include "FSM_TStateMachine.h"
#include "CruiseControlState.h"
#include "CruiseControlOffState.h"
#include "CruiseControlReadyState.h"
#include "CruiseControlSetState.h"
#include "CruiseControlWaitState.h"
#include "CruiseControlAccState.h"

class CruiseControlStateMachine : public FSM_TStateMachine<CruiseControlStateMachine, CruiseControlState<CruiseControlStateMachine>>
{
public:
   CruiseControlStateMachine();
   virtual ~CruiseControlStateMachine();

   //The state of machine
   CruiseControlAccState mAccState;
   CruiseControlOffState mOffState;
   CruiseControlReadyState mReadyState;
   CruiseControlSetState mSetState;
   CruiseControlWaitState mWait;

   void run(Event aReceivedEvent, EventDataType aInputData);

   std::string getCurrentStateName() const;

   unsigned int getCruiseSpeed() const
   {
      return cruiseSpeed; 
   } 
   void setCruiseSpeed(unsigned int aCruiseSpeed)
   {
      cruiseSpeed = aCruiseSpeed;
   }

private:

   CruiseControlStateMachine(const CruiseControlStateMachine& aCopy);
   unsigned int cruiseSpeed;

};

#endif /* CRUISECONTROLSTATEMACHINE_H_ */