#ifndef __LOCOMOTER_H
#define __LOCOMOTER_H

#include "Robot_Parts.h"

class Locomoter : public Robot_Parts
{
private:
	double max_speed;
	double power_consumed;
public:
	void l_input();
};
#endif
