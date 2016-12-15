
#ifndef CRUISECONTROLWAITSTATE_H_
#define CRUISECONTROLWAITSTATE_H_

class CruiseControlWaitState {
public:
	CruiseControlWaitState();
	virtual ~CruiseControlWaitState();
    void transitionResume();
};

#endif /* CRUISECONTROLWAITSTATE_H_ */
