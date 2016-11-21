#ifndef __ARMS_H
#define __ARMS_H
#include "Robot_Parts.h"

class Arms : public Robot_Parts
{
private:
	int no_of_arms;
	double power_consumed;
public:
	void a_input();
};
#endif