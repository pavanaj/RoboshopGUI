#include "iostream"
#include "fstream"
#include "istream"
#include "ostream"
#include "std_lib_facilities.h"

#include "Robot_Parts.h"
#include "Arms.h"
#include "Battery.h"
#include "Boss.h"
#include "Customer.h"
#include "Head.h"
#include "Locomoter.h"
#include "Product_Manager.h"
#include "Sales_Associate.h"
#include "Torso.h"

struct Robots
{
  string r_name;
  string r_no;
  double r_cost;
  double r_price;
  double r_profit;
  double l_cost;
  double t_cost;
  double a_cost;
  double b_cost;
  double h_cost;
  string description;
}R;

vector <Robots> Robot_Parts;

struct Detailed_Catalog
{
	string head_name;
	string head_type;
	double head_cost;
	double head_weight;
	string head_partno;
	string torso_name;
	string torso_type;
	double torso_cost;
	double torso_weight;
	string torso_partno;
	int compartments;
	string locomoter_name;
	string locomoter_type;
	double locomoter_cost;
	double locomoter_weight;
	string locomoter_partno;
	double max_speed;
	double power_consumed;
	string battery_name;
	string battery_type;
	double battery_cost;
	double battery_weight;
	string battery_partno;
	double max_power;
	double energy;
	string arms_name;
	string arms_type;
	double arms_cost;
	double arms_weight;
	string arms_partno;
	int no_of_arms;
	double arms_power;
}DC;

vector <Detailed_Catalog> Details;

struct Orders
{
    string order_no;
    string cust_no;
	string cust_name;
    int robots_ordered;
    string sa_name;
    string sales_date;
    string model_name;
    double sub_total;
    double shipping;
    double tax;
    double net_total;

}O;

vector <Orders> Order_Details;

	double Robot_Parts::input()
	{
		
		return cost;
	}

	void Torso::t_input()
	{

	}

	void Arms::a_input()
	{
		
	}

	void Battery::b_input()
	{
		
	}

	void Locomoter::l_input()
	{
		
	}

	void Product_Manager::pm_input()
	{
		
	}

	void Product_Manager::Create_Robo_Part()
	{
		
	}

	double Product_Manager::Calc_Cost()
	{
		cost = R.h_cost + R.t_cost + R.a_cost + R.b_cost + R.l_cost;
		return cost;
	}

	double Product_Manager::Calc_Profit()
	{
	
	}

	void Sales_Associate::Place_Order()
	{
		O.shipping = O.sub_total*0.10;
		O.tax = O.sub_total*.0825;
		O.net_total = O.sub_total + O.shipping + O.tax;
	}

	void Sales_Associate::Print()
	{

	}

	void Sales_Associate::Report()
	{
	
	}

	void Customer::Catalog()
	{
		int flag = 0;
			}
			else
			{
				flag = 1;
			}
		}
	}

	void Customer::Orders()
	{
	}

	void Customer::Bill()
	{
	}

	void Boss::Sales_Report()
	{

	}

	void Boss::Print_Orders()
	{

	}

	void Boss::Profit()
	{

	}

	void Boss::Models_Sold()
	{

	}

class Controller
{
	Product_Manager pm;
	Customer c;
	Sales_Associate sa;
	Boss b;
	public:
		void menu()
		{

		}

		void help_me()
		{
			cout << "Boss:\n1. The Boss can view the sales record of all the Sales Associates in the system.\nHe can then decide who should be given a raise.";
			cout << "\n2. The Boss can view the profit over each robot.";
			cout << "\n3. The Boss can view the models sold of each robot.";
			cout << "\n4. The Boss can view the details of all the orders taken by the shop.";
			cout << endl;
			cout << "\nProduct Manager :";
			cout << "\n1. The Product Manager defines the parts of a Robot.Each Robot Part has its own attributes, like energy, power, cost, etc.";
			cout << "\nWhen all the parts are defined, a Robot is assembled to be sold to a Customer.";
			cout << "\n2. After all the Robot Parts are defined with their accessories, their costs are added up to find the total cost of the assembled Robot.";
			cout << "\nThe Product Manager knows the cost of the Robot which helps to decide the price of the Robot.";
			cout << "\n3. When the Robot is assembled and ready for selling to the Customers, the Product Manager decides the price of the Robot, thereby calculating the profit for each Robot.";
			cout << endl;
			cout << "\nSales Associate :";
			cout << "\n1. The Sales Associate can create an order for a customer by selecting the Create Order and Generate Bill menu option.";
			cout << "\nThe Sales Associate will be prompted to enter his / her information and information for the Customer and order.";
			cout << "\n2. The Create Order and Generate Bill option will also print the bill of sale created by the Sales Associate.";
			cout << "\n3. The Sales Associate may also generate a report of all of his / her itemized sales and sales totals by selecting the View my Sales Report option.";
			cout << endl;
			cout << "\nCustomer:";
			cout << "\n1. The Customer can view the full Robot Catalog of the Robot Shop.";
			cout << "\nThe Customer can then view details of a particular Robot if the Customer wishes to.";
			cout << "\n2. The Customer can view the Order that has been placed by them.";
			cout << "\nThe Order gives details about the quantity of the robot choses,	its price and amount to pay for the purchase.";
			cout << "\n3. The Customer can print their Bill of all the orders that they placed.";
			cout << "\nThe Bill will give details about the date of purchase, Order Number, Robot Name, Quantity of the Robot, and all the monetary distributions for the clarity of the Customer.";
			
			cout << endl;
		}

		void read_data()
		{
			ifstream read_Orders;
			read_Orders.open("Orders_data.txt");
			ifstream read_RobotParts;
			read_RobotParts.open("RobotParts_data.txt");
			ifstream read_Catalog;
			read_Catalog.open("Catalog_data.txt");
			
			if (read_Orders.fail() || read_RobotParts.fail() || read_Catalog.fail())
			{
				cerr << "Error opening File";
			}

			while (!read_Orders.eof())
			{
				// read data from Orders_data
				getline(read_Orders, O.order_no);
				getline(read_Orders, O.cust_no);
				getline(read_Orders, O.cust_name);
				read_Orders >> O.robots_ordered;
				getline(read_Orders, O.sa_name);
				getline(read_Orders, O.sales_date);
				getline(read_Orders, O.model_name);
				read_Orders >> O.sub_total;
				read_Orders >> O.shipping;
				read_Orders >> O.tax;
				read_Orders >> O.net_total;
				Order_Details.push_back(O);
			}
			while (!read_RobotParts.eof())
			{
				// read contents of Robot Parts
				getline(read_RobotParts, R.r_name);
				getline(read_RobotParts, R.r_no);
				read_RobotParts>>R.r_cost;
				read_RobotParts >> R.r_price;
				read_RobotParts >> R.r_profit;
				read_RobotParts >> R.l_cost;
				read_RobotParts >> R.t_cost;
				read_RobotParts >> R.a_cost;
				read_RobotParts >> R.b_cost;
				read_RobotParts >> R.h_cost;
				getline(read_RobotParts, R.description);
				Robot_Parts.push_back(R);

				// read contents of detailed catalog
				getline(read_Catalog, DC.head_name);
				getline(read_Catalog, DC.torso_name);
				read_Catalog >> DC.compartments;
				getline(read_Catalog, DC.locomoter_name);
				read_Catalog >> DC.max_speed;
				read_Catalog >> DC.power_consumed;
				getline(read_Catalog, DC.battery_name);
				read_Catalog >> DC.max_power;
				read_Catalog >> DC.energy;
				getline(read_Catalog, DC.arms_name);
				read_Catalog >> DC.no_of_arms; 
				read_Catalog >> DC.arms_power;
				Details.push_back(DC);
			}
		}

		void write_data()
		{
			ofstream write_Orders;
			write_Orders.open("Orders_data.txt");
			ofstream write_RobotParts;
			write_RobotParts.open("RobotParts_data.txt");
			ofstream write_Catalog;
			write_Catalog.open("Catalog_data.txt");

			if (write_Orders.fail() || write_RobotParts.fail() || write_Catalog.fail())
			{
				cerr << "Error opening File";
			}

			for(int i=0;i<Order_Details.size();i++)
			{
				//write data to Orders_data
				write_Orders << Order_Details[i].order_no << endl;
				write_Orders << Order_Details[i].cust_no << endl;
				write_Orders << Order_Details[i].cust_name << endl;
				write_Orders << Order_Details[i].robots_ordered << endl;
				write_Orders << Order_Details[i].sa_name << endl;
				write_Orders << Order_Details[i].sales_date << endl;
				write_Orders << Order_Details[i].model_name << endl;
				write_Orders << Order_Details[i].sub_total << endl;
				write_Orders << Order_Details[i].shipping << endl;
				write_Orders << Order_Details[i].tax << endl;
				write_Orders << Order_Details[i].net_total << endl;
			}
			for (int i = 0; i<Robot_Parts.size(); i++)
			{
				// write data to RobotParts_data
				write_RobotParts << Robot_Parts[i].r_name << endl;
				write_RobotParts << Robot_Parts[i].r_no << endl;
				write_RobotParts << Robot_Parts[i].r_cost << endl;
				write_RobotParts << Robot_Parts[i].r_price << endl;
				write_RobotParts << Robot_Parts[i].r_profit << endl;
				write_RobotParts << Robot_Parts[i].l_cost << endl;
				write_RobotParts << Robot_Parts[i].t_cost << endl;
				write_RobotParts << Robot_Parts[i].a_cost << endl;
				write_RobotParts << Robot_Parts[i].b_cost << endl;
				write_RobotParts << Robot_Parts[i].h_cost << endl;
				write_RobotParts << Robot_Parts[i].description << endl;

				// write data to Catalog_data
				write_Catalog << Details[i].head_name << endl;
				write_Catalog << Details[i].head_type << endl;
				write_Catalog << Details[i].head_cost << endl;
				write_Catalog << Details[i].head_weight << endl;
				write_Catalog << Details[i].head_partno << endl;

				write_Catalog << Details[i].torso_name << endl;
				write_Catalog << Details[i].torso_type << endl;
				write_Catalog << Details[i].torso_cost << endl;
				write_Catalog << Details[i].torso_weight << endl;
				write_Catalog << Details[i].torso_partno << endl;
				write_Catalog << Details[i].compartments << endl;

				write_Catalog << Details[i].locomoter_name << endl;
				write_Catalog << Details[i].locomoter_type << endl;
				write_Catalog << Details[i].locomoter_cost << endl;
				write_Catalog << Details[i].locomoter_weight << endl;
				write_Catalog << Details[i].locomoter_partno << endl;
				write_Catalog << Details[i].max_speed << endl;
				write_Catalog << Details[i].power_consumed << endl;

				write_Catalog << Details[i].battery_name << endl;
				write_Catalog << Details[i].battery_type << endl;
				write_Catalog << Details[i].battery_cost << endl;
				write_Catalog << Details[i].battery_weight << endl;
				write_Catalog << Details[i].battery_partno << endl;
				write_Catalog << Details[i].max_power << endl;
				write_Catalog << Details[i].energy << endl;

				write_Catalog << Details[i].arms_name << endl;
				write_Catalog << Details[i].arms_type << endl;
				write_Catalog << Details[i].arms_cost << endl;
				write_Catalog << Details[i].arms_weight << endl;
				write_Catalog << Details[i].arms_partno << endl;
				write_Catalog << Details[i].no_of_arms << endl;
				write_Catalog << Details[i].arms_power << endl;

			}	
		}
void test_case()
		{
			R.r_name = "optimus";
			R.r_no = "101";
			R.l_cost = 100;
			R.t_cost = 100;
			R.a_cost = 100;
			R.b_cost = 100;
			R.h_cost = 100;
			R.r_cost = R.a_cost + R.l_cost + R.t_cost + R.h_cost + R.b_cost;
			R.r_price = 800;
			R.r_profit = R.r_price - R.r_cost;
			R.description = "autobot";
			DC.head_name = "op_head";
			DC.head_type = "head";
			DC.head_cost = 100;
			DC.head_weight = 100;
			DC.head_partno = "1";
			DC.torso_name = "op_torso";
			DC.torso_type = "torso";
			DC.torso_cost = 100;
			DC.torso_weight = 100;
			DC.torso_partno = "1";
			DC.arms_name = "op_arms";
			DC.arms_type = "arms";
			DC.arms_cost = 100;
			DC.arms_weight = 100;
			DC.arms_partno = "1";
			DC.battery_name = "op_battery";
			DC.battery_type = "battery";
			DC.battery_cost = 100;
			DC.battery_weight = 100;
			DC.battery_partno = "1";
			DC.locomoter_name = "op_loco";
			DC.locomoter_type = "loco";
			DC.locomoter_cost = 100;
			DC.locomoter_weight = 100;
			DC.locomoter_partno = "1";
			DC.compartments = 4;
			DC.max_speed = 100;
			DC.power_consumed = 100;
			DC.max_power = 100;
			DC.energy = 100;
			DC.no_of_arms = 2;
			DC.arms_power = 100;
			Robot_Parts.push_back(R);
			Details.push_back(DC);
		}
};

int main()
{
	Controller co;
	co.read_data();
	co.menu();
	co.write_data();
	return 0;
}