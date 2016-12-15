
#ifndef CRUISECONTROLSTATE_H_
#define CRUISECONTROLSTATE_H_

class CruiseControlState {
public:
	CruiseControlState();
	virtual ~CruiseControlState();

    void transitionOn();
    void transitionSet();
    void transitionResume();
    void transitionBrake();
    void transitionAccPressed();
    void transitionAccReleased();
};

#endif /* CRUISECONTROLSTATE_H_ */
