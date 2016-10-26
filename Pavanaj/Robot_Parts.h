#ifndef __ROBOT_PARTS_H
#define __ROBOT_PARTS_H
#include <std_lib_facilities.h>

class Robot_Parts
{
public:
	string type;
	string name;
	double weight;
	string part_no;
	double cost;
	double input();
};
#endif