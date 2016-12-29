#ifndef FSM_TSTATEMACHINE_H_
#define FSM_TSTATEMACHINE_H_

typedef const unsigned int&  EventDataType;

template <class DERIVED_FSM,class STATE>
class FSM_TStateMachine{
public:
   
   //for stack allocated states
   //note that constructors/destructors should not be used in this case, 
   //instead rely on on_enter/on_exit
   typedef STATE* (STATE::*Event)(DERIVED_FSM*, EventDataType);
   
   STATE* dispatch(Event e, EventDataType eventData)
   {
       if(curr_state && e)
       {
           STATE* next_state=(curr_state->*e)(that(), eventData);
           if (next_state != curr_state)
           {
              transition(next_state);
           }
       }
       return curr_state;
   }

protected:
   FSM_TStateMachine():curr_state(0){}
   virtual ~FSM_TStateMachine(){}

   void transition(STATE* next_state)
   {
      if (curr_state == next_state)
      {
         return;
      }

      if (curr_state)
      {
         curr_state->onExit(that(), next_state);
      }
      if (next_state)
      {
         next_state->onEnter(that(), curr_state);
      }

      curr_state = next_state;
   }

   const STATE* const getCurrentState() const
   {
      return curr_state;
   }

private:
   STATE* curr_state;
   inline DERIVED_FSM* that()
   {
      return static_cast<DERIVED_FSM*>(this);
   }
};

#endif