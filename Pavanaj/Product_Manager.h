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
	void pm_input();
    void Create_Robo_Part();
    double Calc_Cost();
    double Calc_Profit();
};

#endif // PRODUCT_MANAGER_H
