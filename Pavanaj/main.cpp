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
				O.sub_total = Robot_Parts[i].r_price * O.robots_ordered;
			}
		}
		O.shipping = O.sub_total*0.10;
		O.tax = O.sub_total*.08;
		O.net_total = O.sub_total + O.shipping + O.tax;
		Order_Details.push_back(O);
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
		cout << endl;
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

		cout << endl;
	}

	void Customer::Catalog()
	{
		int i;
		char c;
		int flag = 0;
		int model;

		cout << "Sr. No.\tName\t\tPrice\tDescription" << endl;
		for (i = 0; i < Robot_Parts.size(); i++)
		{
			cout << i+1 << "\t" << Robot_Parts[i].r_name << "\t\t" << Robot_Parts[i].r_price << "\t" << Robot_Parts[i].description << endl;
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
		cout << "Order # Order-Date SA-Name Model-Name Robots-Ordered Sub-Total Shipping Tax\tTotal" << endl;

		for (i = 0; i < Order_Details.size(); i++)
		{
			if (cust_no == Order_Details[i].cust_no)
			{
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
		double total_sales = 0;
		string ans;
		double max;
		int index_no;
		int k;
		for (int i = 0; i < Order_Details.size(); i++)
		{
			total_sales = 0;
			for (int j = 0; j < Order_Details.size(); j++)
			{
				if (Order_Details[i].sa_name == Order_Details[j].sa_name)
				{
					total_sales = total_sales + Order_Details[j].net_total;
				}			
			}
			cout << i << ". Name of Sales Associate : " << Order_Details[i].sa_name << " Total Sales : $" << total_sales << endl;
		}
	}

	void Boss::Print_Orders()
	{
		cout << "The following is the list of Orders for Robo shop:" << endl;
		cout << "Order No\tCust-Name\tRobots-Ordered\tSA-Name\tSales-Date\tModel-Name\tNet-Total\n";
		for (int i = 0; i < Order_Details.size(); i++)
		{
			cout << Order_Details[i].order_no << "\t" << Order_Details[i].cust_name << "\t" <<
				Order_Details[i].robots_ordered << "\t" << Order_Details[i].sa_name << "\t" << Order_Details[i].sales_date << "\t" <<
				Order_Details[i].model_name << "\t" << Order_Details[i].net_total << endl;
		}
	}

	void Boss::Profit()
	{
		double p=0;
		for (int i = 0; i < Robot_Parts.size(); i++)
		{
			p = Robot_Parts[i].r_profit;
			cout << (i+1) << ". Robot Name : " << Robot_Parts[i].r_name << " Profit : " << p << endl;
		}
	}

	void Boss::Models_Sold()
	{
		int r_sold=0;
		for (int i = 0; i < Order_Details.size(); i++)
		{
			r_sold = 0;
			for (int j = 0; j < Order_Details.size(); j++)
			{
				if (Order_Details[i].model_name == Order_Details[j].model_name)
				{
					r_sold = r_sold + Order_Details[j].robots_ordered;
				}
			}
			cout << i << ". Model Name : " << Order_Details[i].model_name << " Robots sold : " << r_sold << endl;
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

		double str_to_double(string s)
		{
			const char *c = s.c_str();
			double d = atoi(c);
			return d;
		}

		void read_data()
		{
			ifstream read_Orders;
			read_Orders.open("Orders_data.txt");

			ifstream read_RobotParts;
			read_RobotParts.open("RobotParts_data.txt");

			ifstream read_Catalog;
			read_Catalog.open("Catalog_data.txt");

			string word;
			double number;

			if (read_Orders.fail() || read_RobotParts.fail() || read_Catalog.fail())
			{
				cerr << "Error opening File";
			}

			while (getline(read_Orders, word, '@'))
			{
				O.order_no = word;

				getline(read_Orders, word, '@');
				O.cust_no = word;

				getline(read_Orders, word, '@');
				O.cust_name = word;

				getline(read_Orders, word, '@');
				number = str_to_double(word);
				O.robots_ordered = number;

				getline(read_Orders, word, '@');
				O.sa_name = word;

				getline(read_Orders, word, '@');
				O.sales_date = word;

				getline(read_Orders, word, '@');
				O.model_name = word;

				getline(read_Orders, word, '@');
				number = str_to_double(word);
				O.sub_total = number;

				getline(read_Orders, word, '@');
				number = str_to_double(word);
				O.shipping = number;

				getline(read_Orders, word, '@');
				number = str_to_double(word);
				O.tax = number;

				getline(read_Orders, word, '\n');
				number = str_to_double(word);
				O.net_total = number;

				Order_Details.push_back(O);
			}

			while (getline(read_RobotParts, word, '@'))
			{
				R.r_name = word;

				getline(read_RobotParts, word, '@');
				R.r_no = word;

				getline(read_RobotParts, word, '@');
				number = str_to_double(word);
				R.r_cost = number;

				getline(read_RobotParts, word, '@');
				number = str_to_double(word);
				R.r_price = number;

				getline(read_RobotParts, word, '@');
				number = str_to_double(word);
				R.r_price = number;

				getline(read_RobotParts, word, '@');
				number = str_to_double(word);
				R.l_cost = number;

				getline(read_RobotParts, word, '@');
				number = str_to_double(word);
				R.t_cost = number;

				getline(read_RobotParts, word, '@');
				number = str_to_double(word);
				R.a_cost = number;

				getline(read_RobotParts, word, '@');
				number = str_to_double(word);
				R.b_cost = number;

				getline(read_RobotParts, word, '@');
				number = str_to_double(word);
				R.h_cost = number;

				getline(read_RobotParts, word, '\n');
				R.description = word;

				Robot_Parts.push_back(R);
			}

			while (getline(read_Catalog, word, '@'))
			{
				// Head Specs
				DC.head_name = word;

				getline(read_Catalog, word, '@');
				DC.head_type = word;

				getline(read_Catalog, word, '@');
				number = str_to_double(word);
				DC.head_cost = number;

				getline(read_Catalog, word, '@');
				number = str_to_double(word);
				DC.head_weight = number;

				getline(read_Catalog, word, '@');
				DC.head_partno = word;

				// Torso Specs
				getline(read_Catalog, word, '@');
				DC.torso_name = word;

				getline(read_Catalog, word, '@');
				DC.torso_type = word;

				getline(read_Catalog, word, '@');
				number = str_to_double(word);
				DC.torso_cost = number;

				getline(read_Catalog, word, '@');
				number = str_to_double(word);
				DC.torso_weight = number;

				getline(read_Catalog, word, '@');
				DC.torso_partno = word;

				getline(read_Catalog, word, '@');
				number = str_to_double(word);
				DC.compartments = number;

				// Locomoter Specs
				getline(read_Catalog, word, '@');
				DC.locomoter_name = word;

				getline(read_Catalog, word, '@');
				DC.locomoter_type = word;

				getline(read_Catalog, word, '@');
				number = str_to_double(word);
				DC.locomoter_cost = number;

				getline(read_Catalog, word, '@');
				number = str_to_double(word);
				DC.locomoter_weight = number;

				getline(read_Catalog, word, '@');
				DC.locomoter_partno = word;

				getline(read_Catalog, word, '@');
				number = str_to_double(word);
				DC.max_speed = number;

				getline(read_Catalog, word, '@');
				number = str_to_double(word);
				DC.power_consumed = number;

				// Battery Specs
				getline(read_Catalog, word, '@');
				DC.battery_name = word;

				getline(read_Catalog, word, '@');
				DC.battery_type = word;

				getline(read_Catalog, word, '@');
				number = str_to_double(word);
				DC.battery_cost = number;

				getline(read_Catalog, word, '@');
				number = str_to_double(word);
				DC.battery_weight = number;

				getline(read_Catalog, word, '@');
				DC.battery_partno = word;

				getline(read_Catalog, word, '@');
				number = str_to_double(word);
				DC.max_power = number;

				getline(read_Catalog, word, '@');
				number = str_to_double(word);
				DC.energy = number;

				// Arms Specs
				getline(read_Catalog, word, '@');
				DC.arms_name = word;

				getline(read_Catalog, word, '@');
				DC.arms_type = word;

				getline(read_Catalog, word, '@');
				number = str_to_double(word);
				DC.arms_cost = number;

				getline(read_Catalog, word, '@');
				number = str_to_double(word);
				DC.arms_weight = number;

				getline(read_Catalog, word, '@');
				DC.arms_partno = word;

				getline(read_Catalog, word, '@');
				number = str_to_double(word);
				DC.no_of_arms = number;

				getline(read_Catalog, word, '\n');
				number = str_to_double(word);
				DC.arms_power = number;

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

			for (int i = 0; i < Order_Details.size(); i++)
			{
				write_Orders << Order_Details[i].order_no << "@"
					<< Order_Details[i].cust_no << "@"
					<< Order_Details[i].cust_name << "@"
					<< Order_Details[i].robots_ordered << "@"
					<< Order_Details[i].sa_name << "@"
					<< Order_Details[i].sales_date << "@"
					<< Order_Details[i].model_name << "@"
					<< Order_Details[i].sub_total << "@"
					<< Order_Details[i].shipping << "@"
					<< Order_Details[i].tax << "@"
					<< Order_Details[i].net_total << endl;
			}

			for (int i = 0; i < Robot_Parts.size(); i++)
			{
				write_RobotParts << Robot_Parts[i].r_name << "@"
					<< Robot_Parts[i].r_no << "@"
					<< Robot_Parts[i].r_cost << "@"
					<< Robot_Parts[i].r_price << "@"
					<< Robot_Parts[i].r_profit << "@"
					<< Robot_Parts[i].l_cost << "@"
					<< Robot_Parts[i].t_cost << "@"
					<< Robot_Parts[i].a_cost << "@"
					<< Robot_Parts[i].b_cost << "@"
					<< Robot_Parts[i].h_cost << "@"
					<< Robot_Parts[i].description << endl;
			}

			for (int i = 0; i < Details.size(); i++)
			{
				write_Catalog << Details[i].head_name << "@"
					<< Details[i].head_type << "@"
					<< Details[i].head_cost << "@"
					<< Details[i].head_weight << "@"
					<< Details[i].head_partno << "@"
					<< Details[i].torso_name << "@"
					<< Details[i].torso_type << "@"
					<< Details[i].torso_cost << "@"
					<< Details[i].torso_weight << "@"
					<< Details[i].torso_partno << "@"
					<< Details[i].compartments << "@"
					<< Details[i].locomoter_name << "@"
					<< Details[i].locomoter_type << "@"
					<< Details[i].locomoter_cost << "@"
					<< Details[i].locomoter_weight << "@"
					<< Details[i].locomoter_partno << "@"
					<< Details[i].max_speed << "@"
					<< Details[i].power_consumed << "@"
					<< Details[i].battery_name << "@"
					<< Details[i].battery_type << "@"
					<< Details[i].battery_cost << "@"
					<< Details[i].battery_weight << "@"
					<< Details[i].battery_partno << "@"
					<< Details[i].max_power << "@"
					<< Details[i].energy << "@"
					<< Details[i].arms_name << "@"
					<< Details[i].arms_type << "@"
					<< Details[i].arms_cost << "@"
					<< Details[i].arms_weight << "@"
					<< Details[i].arms_partno << "@"
					<< Details[i].no_of_arms << "@"
					<< Details[i].arms_power << endl;
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
			R.r_cost = 500;
			R.r_price = 800;
			R.r_profit = 300;
			R.description = "autobot boss";
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

			O.order_no="1";
			O.cust_no="1";
			O.cust_name="Customer";
			O.robots_ordered=1;
			O.sa_name="SA";
			O.sales_date="01/01/01";
			O.model_name="optimus";
			O.sub_total = 800;
			O.shipping = 80;
			O.tax = 64;
			O.net_total = 944;
			Order_Details.push_back(O);

			R.r_name = "bumblebee";
			R.r_no = "102";
			R.l_cost = 50;
			R.t_cost = 50;
			R.a_cost = 50;
			R.b_cost = 50;
			R.h_cost = 50;
			R.r_cost = 250;
			R.r_price = 750;
			R.r_profit = 500;
			R.description = "autobot";
			Robot_Parts.push_back(R);
			DC.head_name = "bb_head";
			DC.head_type = "head";
			DC.head_cost = 50;
			DC.head_weight = 50;
			DC.head_partno = "1";
			DC.torso_name = "bb_torso";
			DC.torso_type = "torso";
			DC.torso_cost = 50;
			DC.torso_weight = 50;
			DC.torso_partno = "1";
			DC.compartments = 2;
			DC.locomoter_name = "bb_loco";
			DC.locomoter_type = "loco";
			DC.locomoter_cost = 50;
			DC.locomoter_weight = 50;
			DC.locomoter_partno = "1";
			DC.max_speed = 50;
			DC.power_consumed = 50;
			DC.arms_name = "bb_arms";
			DC.arms_type = "arms";
			DC.arms_cost = 50;
			DC.arms_weight = 50;
			DC.arms_partno = "1";
			DC.no_of_arms = 1;
			DC.arms_power = 50;
			DC.battery_name = "bb_battery";
			DC.battery_type = "battery";
			DC.battery_cost = 50;
			DC.battery_weight = 50;
			DC.battery_partno = "1";
			DC.max_power = 50;
			DC.energy = 50;
			Details.push_back(DC);

			O.order_no = "2";
			O.cust_no = "2";
			O.cust_name = "Customer-2";
			O.robots_ordered = 2;
			O.sa_name = "SA-2";
			O.sales_date = "02/02/02";
			O.model_name = "bumblebee";
			O.sub_total = 250;
			O.shipping = 25;
			O.tax = 25;
			O.net_total = 300;
			Order_Details.push_back(O);
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