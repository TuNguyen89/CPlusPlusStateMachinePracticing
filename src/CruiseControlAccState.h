
#ifndef CRUISECONTROLACCSTATE_H_
#define CRUISECONTROLACCSTATE_H_

class CruiseControlAccState {
public:
	CruiseControlAccState();
	virtual ~CruiseControlAccState();
    void transitionAccReleased();
};

#endif /* CRUISECONTROLACCSTATE_H_ */
