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
		cout << "Part Type : ";
		cin.ignore();
		getline(cin, type);
		cout << "Part No : ";
		cin.ignore();
		getline(cin, part_no);
		cout << "Part Name : ";
		cin.ignore();
		getline(cin, name);
		cout << "Weight : ";
		cin >> weight;
		cout << "Cost : ";
		cin >> cost;
		return cost;
	}

	void Torso::t_input()
	{
		cout << "No of Compartments : ";
		cin >> compartments;
		DC.compartments = compartments;
	}

	void Arms::a_input()
	{
		cout << "No of arms : ";
		cin >> no_of_arms;
		DC.no_of_arms = no_of_arms;
		cout << "Power Consumed : ";
		cin >> power_consumed;
		DC.arms_power = power_consumed;
	}

	void Battery::b_input()
	{
		cout << "Max Power : ";
		cin >> max_power;
		DC.max_power = max_power;
		cout << "Energy : ";
		cin >> energy;
		DC.energy = energy;
	}

	void Locomoter::l_input()
	{
		cout << "Max Speed : ";
		cin >> max_speed;
		DC.max_speed = max_speed;
		cout << "Power Consumed : ";
		cin >> power_consumed;
		DC.power_consumed;
	}

	void Product_Manager::pm_input()
	{
		cout << "Model Name : ";
		cin.ignore();
		getline(cin, model_name);
		R.r_name = model_name;
		cout << "Model No : ";
		cin.ignore();
		getline(cin, model_no);
		R.r_no = model_no;
		cout << "Description : ";
		cin.ignore();
		getline(cin, description);
		R.description = description;
	}

	void Product_Manager::Create_Robo_Part()
	{
		cout << "Head specs\n";
		Head h;
		R.h_cost = h.input();
		DC.head_name = h.name;
		DC.head_type = h.type;
		DC.head_cost = h.cost;
		DC.head_weight = h.weight;
		DC.head_partno = h.part_no;
		cout << "Torso specs\n";
		Torso t;
		R.t_cost = t.input();
		t.t_input();
		DC.torso_name = t.name;
		DC.torso_type = t.type;
		DC.torso_cost = t.cost;
		DC.torso_weight = t.weight;
		DC.torso_partno = t.part_no;
		cout << "Arms specs\n";
		Arms a;
		R.a_cost = a.input();
		a.a_input();
		DC.arms_name = a.name;
		DC.arms_type = a.type;
		DC.arms_cost = a.cost;
		DC.arms_weight = a.weight;
		DC.arms_partno = a.part_no;
		cout << "Battery specs\n";
		Battery b;
		R.b_cost = b.input();
		b.b_input();
		DC.battery_name = b.name;
		DC.battery_type = b.type;
		DC.battery_cost = b.cost;
		DC.battery_weight = b.weight;
		DC.battery_partno = b.part_no;
		cout << "Locomoter specs\n";
		Locomoter l;
		R.l_cost = l.input();
		l.l_input();
		DC.locomoter_name = l.name;
		DC.locomoter_type = l.type;
		DC.locomoter_cost = l.cost;
		DC.locomoter_weight = l.weight;
		DC.locomoter_partno = l.part_no;
	}

	double Product_Manager::Calc_Cost()
	{
		cost = R.h_cost + R.t_cost + R.a_cost + R.b_cost + R.l_cost;
		return cost;
	}

	double Product_Manager::Calc_Profit()
	{
		cout << "Price : ";
		cin >> price;
		R.r_price = price;
		profit = price - cost;
		return profit;
	}

	void Sales_Associate::Place_Order()
	{
		cout << "Enter Order No : ";
		cin.ignore();
		getline(cin, O.order_no);

		cout << "Enter Sales Associate name : ";
		cin.ignore();
		getline(cin, O.sa_name);

		cout << "Enter Customer No : ";
		cin.ignore();
		getline(cin, O.cust_no);

		cout << "Enter Customer Name : ";
		cin.ignore();
		getline(cin, O.cust_name);

		cout << "Enter Order's date : ";
		cin.ignore();
		getline(cin, O.sales_date);

		cout << "Enter Model Name : ";
		cin.ignore();
		getline(cin, O.model_name);

		cout << "Enter No. of Robots : ";
		cin >> O.robots_ordered;

		for (int i = 0; i < Robot_Parts.size(); i++)
		{
			if (O.model_name == Robot_Parts[i].r_name)
			{
				O.sub_total = Robot_Parts[i].r_price*O.robots_ordered;
			}
		}
		O.shipping = O.sub_total*0.10;
		O.tax = O.sub_total*.0825;
		O.net_total = O.sub_total + O.shipping + O.tax;

	}

	void Sales_Associate::Print()
	{
		cout << "Order number: " << O.order_no << endl;
		cout << "Customer number: " << O.cust_no << endl;
		cout << "Your sales associate: " << O.sa_name << endl;
		cout << "Sale date: " << O.sales_date << endl;
		cout << endl;
		cout << "Number of robots ordered: " << O.robots_ordered << endl;
		cout << "Model ordered: " << O.model_name << endl;
		cout << endl;
		cout << "Subtotal: $ " << O.sub_total << endl;
		cout << "Shipping: $ " << O.shipping << endl;
		cout << "Tax:      $ " << O.tax << endl;
		cout << endl;
		cout << "Total:    $ " << O.net_total;

	}

	void Sales_Associate::Report()
	{
		string sa_search_name;
		double sales_total = 0;

		cout << "Enter your name for your sales report." << endl;
		cin.ignore();
		getline(cin, sa_search_name);

		for (int i = 0; i < Order_Details.size(); i++)
		{
			if (sa_search_name == Order_Details[i].sa_name)
			{
				cout << " Order number : " << Order_Details[i].order_no << endl;
				cout << "Customer : " << Order_Details[i].cust_name << endl;
				cout << "Total : $" << Order_Details[i].net_total << endl;
				cout << endl;

				sales_total = sales_total + Order_Details[i].net_total;
			}
		}

		cout << "Total sales done by " << sa_search_name << ": $" << sales_total;
	}

	void Customer::Catalog()
	{
		int i;
		char c;
		int flag = 0;
		int model;

		cout << "Sr. No.\tName\tPrice\tDescription" << endl;
		for (i = 0; i < Robot_Parts.size(); i++)
		{
			cout << i+1 << "\t" << Robot_Parts[i].r_name << "\t" << Robot_Parts[i].r_price << "\t" << Robot_Parts[i].description << endl;
		}

		while (flag == 0)
		{
			cout << "More details about a Robot? (Y/N)" << endl;
			cin >> c;
			if (c == 'y' || c == 'Y')
			{
				cout << "Serial Number of Robot: " << endl;
				cin >> model;
				model--;
				cout << "Name of Head: " << Details[model].head_name << endl;
				cout << "Type of Head: " << Details[model].head_type << endl;
				cout << "Weight of Head: " << Details[model].head_weight << endl;
				cout << "Part No. of Head: " << Details[model].head_partno << endl;

				cout << "Name of Torso: " << Details[model].torso_name << endl;
				cout << "Type of Torso: " << Details[model].torso_type << endl;
				cout << "Weight of Torso: " << Details[model].torso_weight << endl;
				cout << "Part No. of Torso: " << Details[model].torso_partno << endl;
				cout << "No of Compartments in Torso : " << Details[model].compartments << endl;

				cout << "Name of Locomoter: " << Details[model].locomoter_name << endl;
				cout << "Type of Locomoter: " << Details[model].locomoter_type << endl;
				cout << "Weight of Locomoter: " << Details[model].locomoter_weight << endl;
				cout << "Part No. of Locomoter: " << Details[model].locomoter_partno << endl;
				cout << "Max Speed of Locomoter: " << Details[model].max_speed << endl;
				cout << "Power Consumed by Locomoter : " << Details[model].power_consumed << endl;

				cout << "Name of Battery: " << Details[model].battery_name << endl;
				cout << "Type of Battery: " << Details[model].battery_type << endl;
				cout << "Weight of Battery: " << Details[model].battery_weight << endl;
				cout << "Part No. of Battery: " << Details[model].battery_partno << endl;
				cout << "Max Power of Battery : " << Details[model].max_power << endl;
				cout << "Energy of Battery : " << Details[model].energy << endl;

				cout << "Name of Arms: " << Details[model].arms_name << endl;
				cout << "Type of Arms: " << Details[model].arms_type << endl;
				cout << "Weight of Arms: " << Details[model].arms_weight << endl;
				cout << "Part No. of Arms: " << Details[model].arms_partno << endl;
				cout << "No of arms : " << Details[model].no_of_arms << endl;
				cout << "Power Consumed by Arm : " << Details[model].arms_power << endl;
			}
			else
			{
				flag = 1;
			}
		}
	}

	void Customer::Orders()
	{
		int i;
		string cust_no;
		string cust_name = "";
		double order_total = 0;

		cout << "Please enter your Customer Number : " << endl;
		cin.ignore();
		getline(cin, cust_no);

		for (i = 0; i < Order_Details.size(); i++)
		{
			if (cust_no == Order_Details[i].cust_no)
			{
				cout << "Order No.\tDate of Order\tSA Name\tModel Name\tRobots Ordered\tSub Total\tShipping\tTax\tTotal" << endl;
				cout << Order_Details[i].order_no << "\t" << Order_Details[i].sales_date << "\t" << Order_Details[i].sa_name << "\t" << Order_Details[i].model_name
					<< "\t" << Order_Details[i].robots_ordered << "\t$" << Order_Details[i].sub_total << "\t$ " << Order_Details[i].shipping
					<< "\t$ " << Order_Details[i].tax << "\t$ " << Order_Details[i].net_total << endl;

				cust_name = Order_Details[i].cust_name;
				order_total += Order_Details[i].net_total;
			}
		}

		cout << "Total Order Amount for " << cust_name << " is $" << order_total << endl;
	}

	void Customer::Bill()
	{
		int i;
		string cust_no;
		string cust_name = "";
		string bill_date = "";
		double order_total = 0;
		int bill_no = 1;

		cout << "Please enter your Customer Number : " << endl;
		cin.ignore();
		getline(cin, cust_no);

		for (i = 0; i < Order_Details.size(); i++)
		{
			if (cust_no == Order_Details[i].cust_no)
			{
				cout << "Bill " << bill_no << ":" << endl;
				cout << "Order No.\tCustomer Name\tModel Name\tRobots Ordered\tSub Total\tShipping\tTax\tTotal" << endl;
				cout << Order_Details[i].order_no << "\t" << Order_Details[i].cust_name << "\t" << Order_Details[i].model_name << "\t" << Order_Details[i].robots_ordered
					<< "\t$" << Order_Details[i].sub_total << "\t$ " << Order_Details[i].shipping << "\t$ " << Order_Details[i].tax << "\t$ " << Order_Details[i].net_total << endl;

				bill_no++;
				bill_date = Order_Details[i].sales_date;
				cust_name = Order_Details[i].cust_name;
				order_total += Order_Details[i].net_total;
			}
		}

		cout << "Total Bill Amount for " << cust_name << " till " << bill_date << "is $" << order_total << endl;
	}

	void Boss::Sales_Report()
	{
		double total_sales;
		string ans;
		double max;
		vector<double> ts;
		int index_no;
		int k;
		for (int i = 0; i < Order_Details.size(); i++)
		{
			for (int j = 1; j < Order_Details.size(); j++)
			{
				if (Order_Details[i].sa_name == Order_Details[j].sa_name)
				{
					total_sales = total_sales + Order_Details[j].net_total;
				}
				else
				{
					total_sales = Order_Details[i].net_total;
				}
			}
			ts.push_back(total_sales);
			cout << i << ". Name of Sales Associate : " << Order_Details[i].sa_name << " Total Sales : $" << ts[i] << endl;
		}
		cout << "Do you want to view a detailed report. Y/N" << endl;
		cin >> ans;
		if (ans == "y"||ans=="Y")
		{
			cout << "Enter the SA_NO for detailed report" << endl;
			cin >> index_no;
			cout << Order_Details[index_no].sa_name << "\t" << ts[index_no] << endl;
			cout << Order_Details[index_no].order_no << "\n" << Order_Details[index_no].cust_name << "\n" << Order_Details[index_no].robots_ordered << "\n" << Order_Details[index_no].sales_date << "\n" << Order_Details[index_no].model_name << "\n" << Order_Details[index_no].net_total << endl;
		}

		max = ts[0];
		for (int i = 1; i < ts.size(); i++)
		{
			if (ts[i] > max)
			{
				max = ts[i];
				k = i;
			}
		}
		cout << "The highest sale was $ " << max << endl;
	}

	void Boss::Print_Orders()
	{
		cout << "The following is the list of Orders for Robo shop:" << endl;
		for (int i = 0; i < Order_Details.size(); i++)
		{
			cout << Order_Details[i].order_no << "\t" << Order_Details[i].cust_name << "\t" <<
				Order_Details[i].robots_ordered << "\t" << Order_Details[i].sa_name << "\t" << Order_Details[i].sales_date << "\t" <<
				Order_Details[i].model_name << "\t" << Order_Details[i].net_total << endl;
		}
	}

	void Boss::Profit()
	{
		int pft;
		vector<double> rp;
		for (int i = 0; i < Robot_Parts.size(); i++)
		{
			for (int j = 1; j < Robot_Parts.size(); j++)
			{
				if (Robot_Parts[i].r_name == Robot_Parts[j].r_name)
				{
					pft = pft + Robot_Parts[j].r_profit;
				}
				else
				{
					pft = Robot_Parts[i].r_profit;
				}
			}
			rp.push_back(pft);
			cout << i << ". Robot Name : " << Robot_Parts[i].r_name << " Total Profit : " << rp[i] << endl;
		}

	}

	void Boss::Models_Sold()
	{

		int r_sold;
		vector<int> rs;
		for (int i = 0; i < Order_Details.size(); i++)
		{
			for (int j = 1; j < Order_Details.size(); j++)
			{
				if (Order_Details[i].model_name == Order_Details[j].model_name)
				{
					r_sold = r_sold + Order_Details[j].robots_ordered;
				}
				else
				{
					r_sold = Order_Details[i].robots_ordered;
				}
			}
			rs.push_back(r_sold);
			cout << i << ". Model Name : " << Order_Details[i].model_name << " Robots sold : " << rs[i] << endl;
		}

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
			cout << "Welcome to Robo Shop System :\n";
			int flag = 0;
			int ch, choice;
			do
			{
				main_menu:
				cout << "MAIN MENU :- \n";
				cout << "Are you a : \n";
				cout << "1. Product Manager \n";
				cout << "2. Customer\n";
				cout << "3. Sales Associate\n";
				cout << "4. Boss\n";
				cout << "5. Help Me\n";
				cout << "0. To exit \n";
				cout << "9. TEST CASE \n";
				cin >> ch;
				switch (ch)
				{
				case 1:
					cout << "1. Create Robot Parts \n";
					cout << "0. To Exit \n";
					cin >> choice;
					if (ch == 1)
					{
						pm.pm_input();
						pm.Create_Robo_Part();
						R.r_cost = pm.Calc_Cost();
						R.r_profit = pm.Calc_Profit();
						Robot_Parts.push_back(R);
						Details.push_back(DC);
					}
					else
					{
						goto main_menu;
					}
					break;
				case 2:
					cout << "1. View Catalog \n";
					cout << "2. View Customer Order Details \n";
					cout << "3. View Bill \n";
					cout << "0. To Exit \n";
					cin >> choice;
					if (choice == 1)
					{
						c.Catalog();
					}
					else if (choice == 2)
					{
						c.Orders();
					}
					else if (choice == 3)
					{
						c.Bill();
					}
					else
					{
						goto main_menu;
					}
					break;
				case 3:
					cout << "1. Create Order and Generate Bill \n";
					cout << "2. View My Sales Report \n";
					cout << "3. Create Bill for Customer \n";
					cout << "0. To Exit \n";
					cin >> choice;
					if (choice == 1)
					{
						sa.Place_Order();
						sa.Print();
						Order_Details.push_back(O);
					}
					else if (choice == 2)
					{
						sa.Report();
					}
					else if (choice == 3)
					{
						c.Bill();
					}
					else
					{
						goto main_menu;
					}
					break;
				case 4:
					cout << "1. View Sales Report for all Sales Associates\n";
					cout << "2. View Order Details for Shop \n";
					cout << "3. View No of models sold \n";
					cout << "4. View profit for each model \n";
					cout << "0. To Exit \n";
					cin >> choice;
					if (choice == 1)
					{
						b.Sales_Report();
					}
					else if (choice == 2)
					{
						b.Print_Orders();
					}
					else if (choice == 3)
					{
						b.Models_Sold();
					}
					else if (choice == 4)
					{
						b.Profit();
					}
					else
					{
						goto main_menu;
					}
					break;
				case 5:
					help_me();
					break;
				case 0:
					cout << "Thank you for using the system \n";
					flag = 1;
					break;
				case 9:
					test_case();
					break;
				default:
					cout << "Please enter a valid choice or select Help for deatailed explanation\n";
					goto main_menu;
				}
			} while (flag == 0);
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
				//ignore
				getline(read_Orders, O.sa_name);
				getline(read_Orders, O.sales_date);
				getline(read_Orders, O.model_name);
				read_Orders >> O.sub_total;
				read_Orders >> O.shipping;
				read_Orders >> O.tax;
				read_Orders >> O.net_total;
				Order_Details.push_back(O);
			}
			while (!read_RobotParts.eof())// good() 
			{
				// read contents of Robot Parts
				getline(read_RobotParts, R.r_name);
				getline(read_RobotParts, R.r_no);
				read_RobotParts >> R.r_cost;
				read_RobotParts >> R.r_price;
				read_RobotParts >> R.r_profit;
				read_RobotParts >> R.l_cost;
				read_RobotParts >> R.t_cost;
				read_RobotParts >> R.a_cost;
				read_RobotParts >> R.b_cost;
				read_RobotParts >> R.h_cost;
				getline(read_RobotParts, R.description);
				Robot_Parts.push_back(R);

			}
			while (!read_Catalog.eof())// good() 
			{
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
	//co.read_data();
	co.menu();
	co.write_data();
	return 0;
}