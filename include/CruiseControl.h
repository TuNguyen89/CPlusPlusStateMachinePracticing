

#ifndef CRUISECONTROL_H_
#define CRUISECONTROL_H_

class CruiseControl {
public:
    CruiseControl();
    virtual ~CruiseControl();
    
    void handleAction();
    void getStatus();
private:

    int cruiseSpeed;
    
    void actionOn();
    void actionSet();
    void actionResume();
    void actionBrake();
    void actionAccPressed();
    void actionReleased();

};

#endif /* CRUISECONTROL_H_ */
