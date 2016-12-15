
#ifndef CRUISECONTROLSETSTATE_H_
#define CRUISECONTROLSETSTATE_H_

class CruiseControlSetState {
public:
	CruiseControlSetState();
	virtual ~CruiseControlSetState();
    void transitionAccPressed();
    void transitionBrake();
};

#endif /* CRUISECONTROLSETSTATE_H_ */
