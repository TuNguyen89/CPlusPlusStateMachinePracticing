/**
* @ingroup Cruise Control Module
* Cruise control module, handle cruise control feature
*/

/*! Cruise Control module
   The Cruise Control module receive the user input and change it state to active.
   Be noted that, the minimum speed to active cruise control is 40 Km/h
   There are number of user input: on, set, resume, brake, accP, accR
   There are number of state: Off, Ready, Set, Acc, Wait

   Example Usage:
    @code
       CruiseControl control = new CruiseControl();
       control.handleAction(OnAction);
       control.handleAction(SetAction);
       control.getStatus();
    @endcode
*/

#ifndef CRUISECONTROL_H_
#define CRUISECONTROL_H_

#include "CruiseControlState.h"


/**
* Action Enum
* The avaiable action that cruise control could handle
*/
enum ActionEnum 
{
    SetAction,
    OnAction,
    ResumAction,
    BreakAction,
    AccPressedAction,
    AccReleasedAction,
    InvalidAction
};

const unsigned int MIN_CAR_SPEED_TO_ACTIVE = 40; //Minimum car speed to active is 40

class CruiseControlOffState;
class CruiseControlReadyState;
class CruiseControlSetState;
class CruiseControlWaitState;
class CruiseControlAccState;
class CruiseControlActiveState;

class CruiseControl {
public:

   /**
   * CruiseControl constructor.
   * Construct Cruise Control module
   */
    CruiseControl();

    /**
    * CruiseControl destructor.
    * Destruct Cruise Control module
    */
    virtual ~CruiseControl();

    /**
    * Hanlde action from outside world
    * @param action action type
    * @param a_currentCarSpeed current car speed
    * @return void
    */
    void handleAction(ActionEnum action, unsigned int a_currentCarSpeed);

    /**
    * Hanlde action from outside world
    * @return current cruise control state and cruise speed
    */
    std::string getStatus();

private:

    CruiseControlState *state; ///Current state of Cruise Control system
    int cruiseSpeed;           ///Current set speed of Cruise Control system

    void actionOn();
    void actionSet(unsigned int a_currentCarSpeed);
    void actionResume();
    void actionBrake();
    void actionAccPressed();
    void actionReleased();

    //Friend class delcelation
    friend class CruiseControlOffState;
    friend class CruiseControlReadyState;
    friend class CruiseControlSetState;
    friend class CruiseControlWaitState;
    friend class CruiseControlAccState;
    friend class CruiseControlActiveState;

};

#endif /* CRUISECONTROL_H_ */