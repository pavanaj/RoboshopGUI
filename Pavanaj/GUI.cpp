// standard io headers
#include <iostream>
#include <fstream>
#include "std_lib_facilities.h"
#include <string>
#include <sstream>
using namespace std;

#include "View.h"

// GUI Widgets
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <Fl/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <Fl/Fl_Widget.H>
#include <FL/Fl_Text_Display.H>
#include <Fl/fl_ask.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <cctype>

Fl_Window *win;
Fl_Menu_Bar *menubar;
View *view;

struct Robot
{
	string r_name;
	string r_no;
	string description;
	double r_cost;
	double r_price;
	double r_profit;
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
}R;

vector <Robot> Robots;

struct Order
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

vector <Order> Orders;

struct Customer
{
	string cust_no;
	string cust_name;
}C;

vector <Customer> Customers;

struct SalesAssociate
{
	string sa_no;
	string sa_name;
}SA;

vector <SalesAssociate> SalesAssociates;

string double_to_str(double d)
{
	char *c;
	itoa(d,c,10);
	string s(c);
	return s;
}

double str_to_double(string s)
{
	const char *c = s.c_str();
	double d = atoi(c);
	return d;
}

void EnterRoboPartsCB(Fl_Widget* w, void* p)
{
	Fl_Button* b = (Fl_Button*)w;
	Fl_Input* temp;
	string s;
	temp = (Fl_Input*)b->parent()->child(0);
	R.r_no = temp->value();
	temp = (Fl_Input*)b->parent()->child(1);
	R.r_name = temp->value();
	temp = (Fl_Input*)b->parent()->child(2);
	R.description = temp->value();
	temp = (Fl_Input*)b->parent()->child(3);
	R.head_partno = temp->value();
	temp = (Fl_Input*)b->parent()->child(4);
	R.head_name = temp->value();
	temp = (Fl_Input*)b->parent()->child(5);
	R.head_type = temp->value();
	temp = (Fl_Input*)b->parent()->child(6);
	s = temp->value();
	R.head_cost = str_to_double(s);
	temp = (Fl_Input*)b->parent()->child(7);
	s = temp->value();
	R.head_weight = str_to_double(s);
	temp = (Fl_Input*)b->parent()->child(8);
	R.torso_partno = temp->value();
	temp = (Fl_Input*)b->parent()->child(9);
	R.torso_name = temp->value();
	temp = (Fl_Input*)b->parent()->child(10);
	R.torso_type = temp->value();
	temp = (Fl_Input*)b->parent()->child(11);
	s = temp->value();
	R.torso_cost = str_to_double(s);
	temp = (Fl_Input*)b->parent()->child(12);
	s = temp->value();
	R.torso_weight = str_to_double(s);
	temp = (Fl_Input*)b->parent()->child(13);
	s = temp->value();
	R.compartments = str_to_double(s);
	temp = (Fl_Input*)b->parent()->child(14);
	R.locomoter_partno = temp->value();
	temp = (Fl_Input*)b->parent()->child(15);
	R.locomoter_name = temp->value();
	temp = (Fl_Input*)b->parent()->child(16);
	R.locomoter_type = temp->value();
	temp = (Fl_Input*)b->parent()->child(17);
	s = temp->value();
	R.locomoter_cost = str_to_double(s);
	temp = (Fl_Input*)b->parent()->child(18);
	s = temp->value();
	R.locomoter_weight = str_to_double(s);
	temp = (Fl_Input*)b->parent()->child(19);
	s = temp->value();
	R.max_speed = str_to_double(s);
	temp = (Fl_Input*)b->parent()->child(20);
	s = temp->value();
	R.power_consumed = str_to_double(s);
	temp = (Fl_Input*)b->parent()->child(21);
	R.battery_partno = temp->value();
	temp = (Fl_Input*)b->parent()->child(22);
	R.battery_name = temp->value();
	temp = (Fl_Input*)b->parent()->child(23);
	R.battery_type = temp->value();
	temp = (Fl_Input*)b->parent()->child(24);
	s = temp->value();
	R.battery_cost = str_to_double(s);
	temp = (Fl_Input*)b->parent()->child(25);
	s = temp->value();
	R.battery_weight = str_to_double(s);
	temp = (Fl_Input*)b->parent()->child(26);
	s = temp->value();
	R.max_power = str_to_double(s);
	temp = (Fl_Input*)b->parent()->child(27);
	s = temp->value();
	R.energy = str_to_double(s);
	temp = (Fl_Input*)b->parent()->child(28);
	R.arms_partno = temp->value();
	temp = (Fl_Input*)b->parent()->child(29);
	R.arms_name = temp->value();
	temp = (Fl_Input*)b->parent()->child(30);
	R.arms_type = temp->value();
	temp = (Fl_Input*)b->parent()->child(31);
	s = temp->value();
	R.arms_cost = str_to_double(s);
	temp = (Fl_Input*)b->parent()->child(32);
	s = temp->value();
	R.arms_weight = str_to_double(s);
	temp = (Fl_Input*)b->parent()->child(33);
	s = temp->value();
	R.arms_power = str_to_double(s);
	temp = (Fl_Input*)b->parent()->child(34);
	s = temp->value();
	R.no_of_arms = str_to_double(s);
	Robots.push_back(R);
}

void RoboPartsCB(Fl_Widget* w, void* p)
{
	Fl_Window *CRP = new Fl_Window(1280,720);

	Fl_Input *modelno = new Fl_Input(150,50,100,30,"Model Number : "); //Child 0
	Fl_Input *modelname = new Fl_Input(450,50,100,30, "Model Name : "); //Child 1
	Fl_Input *description = new Fl_Input(750,50,200,30, "Description : ");//Child 2

	Fl_Input *headpartno = new Fl_Input(150, 100, 100, 30, "Head PartNo : ");//Child 3
	Fl_Input *headname = new Fl_Input(450, 100, 100, 30, "Head Name : ");//Child 4
	Fl_Input *headtype = new Fl_Input(150, 150, 100, 30, "Head Type : ");//Child 5
	Fl_Input *headcost = new Fl_Input(450, 150, 100, 30, "Head Cost : ");//Child 6
	Fl_Input *headweight = new Fl_Input(150, 200, 100, 30, "Head Weight : ");//Child 7

	Fl_Input *torsopartno = new Fl_Input(750, 100, 100, 30, "Torso PartNo : ");//Child 8
	Fl_Input *torsoname = new Fl_Input(1050, 100, 100, 30, "Torso Name : ");//Child 9
	Fl_Input *torsotype = new Fl_Input(750, 150, 100, 30, "Torso Type : ");//Child 10
	Fl_Input *torsocost = new Fl_Input(1050, 150, 100, 30, "Torso Cost : "); //Child 11
	Fl_Input *torsoweight = new Fl_Input(750, 200, 100, 30, "Torso Weight : ");//Child 12
	Fl_Input *compartments = new Fl_Input(1050, 200, 100, 30, "Torso Compartments : ");//Child 13

	Fl_Input *locomoterpartno = new Fl_Input(150, 250, 100, 30, "Locomoter PartNo : ");//Child 14
	Fl_Input *locomotername = new Fl_Input(450, 250, 100, 30, "Locomoter Name : ");//Child 15
	Fl_Input *locomotertype = new Fl_Input(150, 300, 100, 30, "Locomoter Type : ");//Child 16
	Fl_Input *locomotercost = new Fl_Input(450, 300, 100, 30, "Locomoter Cost : ");//Child 17
	Fl_Input *locomoterweight = new Fl_Input(150, 350, 100, 30, "Locomoter Weight : ");//Child 18
	Fl_Input *maxspeed = new Fl_Input(450, 350, 100, 30, "Locomoter MaxSpeed : ");//Child 19
	Fl_Input *power_consumed = new Fl_Input(450, 400, 100, 30, "Locomoter PowerConsumed : ");//Child 20

	Fl_Input *batterypartno = new Fl_Input(750, 250, 100, 30, "Battery PartNo : ");//Child 21
	Fl_Input *batteryname = new Fl_Input(1050, 250, 100, 30, "Battery Name : ");//Child 22
	Fl_Input *batterytype = new Fl_Input(750, 300, 100, 30, "Battery Type : ");//Child 23
	Fl_Input *batterycost = new Fl_Input(1050, 300, 100, 30, "Battery Cost : ");//Child 24
	Fl_Input *batteryweight = new Fl_Input(750, 350, 100, 30, "Battery Weight : ");//Child 25
	Fl_Input *maxpower = new Fl_Input(1050, 350, 100, 30, "Battery MaxPower : ");//Child 26
	Fl_Input *energy = new Fl_Input(750, 400, 100, 30, "Battery Energy : ");//Child 27

	Fl_Input *armspartno = new Fl_Input(150, 450, 100, 30, "Arms PartNo : ");//Child 28
	Fl_Input *armsname = new Fl_Input(450, 450, 100, 30, "Arms Name : ");//Child 29
	Fl_Input *armstype = new Fl_Input(150, 500, 100, 30, "Arms Type : ");//Child 30
	Fl_Input *armscost = new Fl_Input(450, 500, 100, 30, "Arms Cost : ");//Child 31
	Fl_Input *armsweight = new Fl_Input(150, 550, 100, 30, "Arms Weight : "); //Child 32
	Fl_Input *armspower = new Fl_Input(450, 550, 100, 30, "Arms Power : ");//Child 33
	Fl_Input *noofarms = new Fl_Input(150, 600, 100, 30, "Arms Number : ");//Child 34

	Fl_Button *Enter = new Fl_Button(525, 625, 80, 50, "ENTER");
	Enter->callback(EnterRoboPartsCB);
	
	CRP->show();
	view->redraw();
}

void Create_Customer_CB(Fl_Widget* w, void* p)
{
	Fl_Button* b = (Fl_Button*)w;
	Fl_Input* temp;
	temp = (Fl_Input*)b->parent()->child(0);
	C.cust_no = temp->value();
	temp = (Fl_Input*)b->parent()->child(1);
	C.cust_name = temp->value();

	Customers.push_back(C);
}

void CreateCustomerCB(Fl_Widget* w, void* p)
{
	Fl_Window *win = new Fl_Window(350, 300);
	Fl_Input *cust_no = new Fl_Input(150, 50, 100, 30, "Customer No : "); //Child 0
	Fl_Input *cust_name = new Fl_Input(150, 150, 100, 30, "Customer Name : "); //Child 1
	Fl_Button *Create = new Fl_Button(100, 225 , 80, 50, "CREATE");
	Create->callback(Create_Customer_CB);

	win->show();
	view->redraw();
}

void Create_SA_CB(Fl_Widget* w, void* p)
{
	Fl_Button* b = (Fl_Button*)w;
	Fl_Input* temp;
	temp = (Fl_Input*)b->parent()->child(0);
	SA.sa_no = temp->value();
	temp = (Fl_Input*)b->parent()->child(1);
	SA.sa_name = temp->value();

	SalesAssociates.push_back(SA);
}

void CreateSACB(Fl_Widget* w, void* p)
{
	Fl_Window *win = new Fl_Window(350, 300);
	Fl_Input *cust_no = new Fl_Input(200, 50, 100, 30, "Sales Associate No : "); //Child 0
	Fl_Input *cust_name = new Fl_Input(200, 150, 100, 30, "Sales Associate Name : "); //Child 1
	Fl_Button *Create = new Fl_Button(100, 225, 80, 50, "CREATE");
	Create->callback(Create_SA_CB);

	win->show();
	view->redraw();
}

void ProfitCB(Fl_Widget* w, void* p)
{

}
void View::draw()
{
	Fl_Box::draw();
}

bool View::saved()
{
	return dirty;
}

void QuitCB(Fl_Widget* w, void* p)
{
	int selection = 1;
	if (!view->saved())
	{
		selection = fl_choice("Are You Sure ? ", fl_no, fl_yes, 0);
	}
	if (selection == 1)
	{
		win->hide();
	}
}

void HelpCB(Fl_Widget* w, void* p)
{
	Fl_Window *help = new Fl_Window(900, 550);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *display = new Fl_Text_Display(20, 20, 900, 550, "HELP ME");
	display->buffer(buff);
	help->resizable(*display);
	help->show();
	buff->text(
	"Boss:\n1. The Boss can view the sales record of all the Sales Associates in the system.\nHe can then decide who should be given a raise."
	"\n2. The Boss can view the profit over each robot."
	"\n3. The Boss can view the models sold of each robot."
	"\n4. The Boss can view the details of all the orders taken by the shop."
	"\n"
	"\nProduct Manager :"
	"\n1. The Product Manager defines the parts of a Robot.Each Robot Part has its own attributes, like energy, power, cost, etc."
	"\nWhen all the parts are defined, a Robot is assembled to be sold to a Customer."
	"\n2. After all the Robot Parts are defined with their accessories, their costs are added up to find the total cost of the assembled Robot."
	"\nThe Product Manager knows the cost of the Robot which helps to decide the price of the Robot."
	"\n3. When the Robot is assembled and ready for selling to the Customers, the Product Manager decides the price of the Robot," 
	"\n thereby calculating the profit for each Robot."
	"\n"
	"\nSales Associate :"
	"\n1. The Sales Associate can create an order for a customer by selecting the Create Order and Generate Bill menu option."
	"\nThe Sales Associate will be prompted to enter his / her information and information for the Customer and order."
	"\n2. The Create Order and Generate Bill option will also print the bill of sale created by the Sales Associate."
	"\n3. The Sales Associate may also generate a report of all of his / her itemized sales and sales totals by selecting the"
	"\nView my Sales Report option."
	"\n"
	"\nCustomer:"
	"\n1. The Customer can view the full Robot Catalog of the Robot Shop."
	"\nThe Customer can then view details of a particular Robot if the Customer wishes to."
	"\n2. The Customer can view the Order that has been placed by them."
	"\nThe Order gives details about the quantity of the robot choses,	its price and amount to pay for the purchase."
	"\n3. The Customer can print their Bill of all the orders that they placed."
	"\nThe Bill will give details about the date of purchase, Order Number, Robot Name, Quantity of the Robot,"
	"\nand all the monetary distributions for the clarity of the Customer."
	"\n"
	);
	view->redraw();
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
	R.head_name = "op_head";
	R.head_type = "head";
	R.head_cost = 100;
	R.head_weight = 100;
	R.head_partno = "1";
	R.torso_name = "op_torso";
	R.torso_type = "torso";
	R.torso_cost = 100;
	R.torso_weight = 100;
	R.torso_partno = "1";
	R.arms_name = "op_arms";
	R.arms_type = "arms";
	R.arms_cost = 100;
	R.arms_weight = 100;
	R.arms_partno = "1";
	R.battery_name = "op_battery";
	R.battery_type = "battery";
	R.battery_cost = 100;
	R.battery_weight = 100;
	R.battery_partno = "1";
	R.locomoter_name = "op_loco";
	R.locomoter_type = "loco";
	R.locomoter_cost = 100;
	R.locomoter_weight = 100;
	R.locomoter_partno = "1";
	R.compartments = 4;
	R.max_speed = 100;
	R.power_consumed = 100;
	R.max_power = 100;
	R.energy = 100;
	R.no_of_arms = 2;
	R.arms_power = 100;
	Robot_Parts.push_back(R);
	O.order_no = "1";
	O.cust_no = "1";
	O.cust_name = "Customer";
	O.robots_ordered = 1;
	O.sa_name = "SA";
	O.sales_date = "01/01/01";
	O.model_name = "optimus";
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
	R.head_name = "bb_head";
	R.head_type = "head";
	R.head_cost = 50;
	R.head_weight = 50;
	R.head_partno = "1";
	R.torso_name = "bb_torso";
	R.torso_type = "torso";
	R.torso_cost = 50;
	R.torso_weight = 50;
	R.torso_partno = "1";
	R.compartments = 2;
	R.locomoter_name = "bb_loco";
	R.locomoter_type = "loco";
	R.locomoter_cost = 50;
	R.locomoter_weight = 50;
	R.locomoter_partno = "1";
	R.max_speed = 50;
	R.power_consumed = 50;
	R.arms_name = "bb_arms";
	R.arms_type = "arms";
	R.arms_cost = 50;
	R.arms_weight = 50;
	R.arms_partno = "1";
	R.no_of_arms = 1;
	R.arms_power = 50;
	R.battery_name = "bb_battery";
	R.battery_type = "battery";
	R.battery_cost = 50;
	R.battery_weight = 50;
	R.battery_partno = "1";
	R.max_power = 50;
	R.energy = 50;
	Robot_Parts.push_back(R);
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

int main()
{
	// CREATE WINDOW
	win = new Fl_Window(720,480,"RoboShop");
	win->color(FL_WHITE);
	view = new View (0, 0, 720, 480);
	//MAIN MENU
	menubar = new Fl_Menu_Bar(0, 0, 720, 30);
	test_case();
	Fl_Menu_Item menuitems[] =
	{
		{ "&File",0,0,0, FL_SUBMENU },
		{ "New" },//(Fl_Callback*)NewCB },
		{ "Open" },//(Fl_Callback*)OpenCB },
		{ "Save" },//(Fl_Callback*)SaveCB },
		{ "Save As"},//(Fl_Callback*)SaveAsCB},
		{ "Help",0,(Fl_Callback*)HelpCB},
		{ "Quit",0,(Fl_Callback*)QuitCB},
		{ 0 },
		{ "&Product Manager",0,0,0, FL_SUBMENU },
		{ "Create RoboParts",0,(Fl_Callback*)RoboPartsCB },
		{ 0 },
		{ "&Boss",0,0,0, FL_SUBMENU },
		{ "Sales Report" },//(Fl_Callback*)SalesReportCB },
		{ "View Orders"},//(Fl_Callback*)OrdersCB },
		{ "Model Sales" },//(Fl_Callback*)ModelSalesCB },
		{ "Models Profit",0,(Fl_Callback*)ProfitCB,0,FL_MENU_DIVIDER },
		{ "Create Customer",0,(Fl_Callback*)CreateCustomerCB},
		{ "Create Sales Associate",0,(Fl_Callback*)CreateSACB },
		{ 0 },
		{ "&Sales Associate",0,0,0, FL_SUBMENU },
		{ "Sales Report" },//(Fl_Callback*)SAReportCB },
		{ "Create Order" },//(Fl_Callback*)OrderCB },
		{ "Create Bill" },//(Fl_Callback*)BillCB },
		{ 0 },
		{ "&Customer",0,0,0, FL_SUBMENU },
		{ "View Catalog" },//(Fl_Callback*)CatalogCB },
		{ "View Bills" },//(Fl_Callback*)CustBillCB },
		{ "View Orders" },//(Fl_Callback*)CustOrderCB },
		{ 0 },
		{ 0 }
	};

	menubar->menu(menuitems);
	//win->resizable(*win);
	win->end();
	win->show();
	return (Fl::run());
}