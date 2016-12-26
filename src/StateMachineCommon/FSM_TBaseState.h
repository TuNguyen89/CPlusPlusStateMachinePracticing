#ifndef FSM_TBASESTATE_H_
#define FSM_TBASESTATE_H_

#include "FSM_TStateMachine.h"

template<class FSM, class STATE>
class FSM_TIBaseState{
protected:
   virtual ~FSM_TIBaseState(){}
public:
   virtual void onExit (FSM*,STATE* new_state){}
   virtual void onEnter(FSM*,STATE* old_state){}
};

#endif /*FSM_TBASESTATE_H_*/