#ifndef __BATTERY_H
#define __BATTERY_H
#include <std_lib_facilities.h>
#include "Robot_Parts.h"

class Battery : public Robot_Parts
{
private:
	double max_power;
	double energy;
public:
	void b_input();
};
#endif
