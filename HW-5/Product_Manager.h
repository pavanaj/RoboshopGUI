#ifndef PRODUCT_MANAGER_H
#define PRODUCT_MANAGER_H


class Product_Manager
{
protected:
	string model_name;
	string model_no;
	double profit;

private:
	double price;
	double cost;
	string description;
public:
  //  void RoboPartsCB(Fl_Widget* w, void* p);
};

#endif // PRODUCT_MANAGER_H
