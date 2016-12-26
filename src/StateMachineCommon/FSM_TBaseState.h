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

    #if _MSC_VER < 1200 
     #error derives_from() will not compile in VC++ before version 7./ create this as stand-alone fn then.
    #endif

    template<class T>
    bool derives_from(T*){ 
        const char* derives= 0!=dynamic_cast<T*>(this)?"YES":"NO";
        printf("\n%s derives from %s ?-%s",
	    typeid(*this).name(),typeid(T).name(),derives);
        return 0!=dynamic_cast<T*>(this);
    }
};

#endif /*FSM_TBASESTATE_H_*/