#ifndef __TORSO_H
#define __TORSO_H
#include <std_lib_facilities.h>
#include "Robot_Parts.h"

class Torso : public Robot_Parts
{
private:
	int compartments;
public:
	void t_input();
};
#endif