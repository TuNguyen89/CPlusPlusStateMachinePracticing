
#ifndef VEHICLE_H_
#define VEHICLE_H_

class Vehicle {
public:
	Vehicle();
	virtual ~Vehicle();

private:
	int currentSpeed;
	void handleUserInput();
};

#endif /* VEHICLE_H_ */
