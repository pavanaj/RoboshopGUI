// standard headers
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
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Scroll.H>

Fl_Window *win;
Fl_Menu_Bar *menubar;
View *view;

struct Robot
{
	string r_name;
	string r_no;
	string description;
	string image;
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
	string password;
}C;

vector <Customer> Customers;

struct SalesAssociate
{
	string sa_no;
	string sa_name;
	string password;
}SA;

vector <SalesAssociate> SalesAssociates;

struct Product_Manager
{
	string pm_no;
	string pm_name;
	string password;
}PM;

vector <Product_Manager> Managers;

string double_to_str(double value)
{
	stringstream ss;
	ss << value;
	string str = ss.str();
	return str;
}

double str_to_double(string s)
{
	const char *c = s.c_str();
	double d = atoi(c);
	return d;
}

string DTS(double value)
{
	stringstream ss;
	ss << value;
	string str = ss.str();
	return str;
}

string ITS(int value)
{
	stringstream ss;
	ss << value;
	string str = ss.str();
	return str;
}

double STD(string s)
{
	const char *c = s.c_str();
	double d = atoi(c);
	return d;
}

void Delete_RP_CB(Fl_Widget* w, void* p)
{
	string rp_no;
	Fl_Button* b = (Fl_Button*)w;
	Fl_Input* temp;
	temp = (Fl_Input*)b->parent()->child(0);
	rp_no = temp->value();

	for (int i = 0; i < Robots.size(); i++)
	{
		if (Robots[i].r_no == rp_no)
		{
			Robots.erase((Robots.begin() + i));
			break;
		}
	}
	win->show();
	view->redraw();
}

void DeleteRPCB(Fl_Widget* w, void* p)
{
	Fl_Window *win = new Fl_Window(250, 250, "Delete Robot Parts ");
	Fl_Input *rp_no = new Fl_Input(100, 50, 100, 30, "Model No : "); //Child 0
	Fl_Button *Delete = new Fl_Button(100, 120, 80, 50, "DELETE");
	Delete->callback(Delete_RP_CB);

	win->show();
	view->redraw();
}

void ImageCB(Fl_Widget* w, void* p)
{
	Fl_Button* b = (Fl_Button*)w;
	Fl_Input* temp;
	temp = (Fl_Input*)b->parent()->child(1);
	int no = STD(temp->value());
	fl_register_images();
	Fl_Window *win = new Fl_Window(600, 600);
	Fl_JPEG_Image *jpg = new Fl_JPEG_Image((Robots[(no - 1)].image).c_str());
	Fl_Box *box = new Fl_Box(0, 0, 600, 600);
	box->image(*jpg);
	win->show();
	view->redraw();
}

void ViewRPCB(Fl_Widget* w, void* p)
{
	Fl_Window *CW = new Fl_Window(600, 500, "Robot Parts");
	Fl_Multiline_Output *BR = new Fl_Multiline_Output(0, 0, 600, 300); // Child 0

	BR->type(FL_MULTILINE_OUTPUT);
	BR->textfont(FL_COURIER);

	string result = "No.\tModel No.\tName\t\t\tPrice\tDescription\t\n";
	string s;

	for (int i = 0; i < Robots.size(); i++)
	{
		s = ITS(i + 1);
		result += s + "\t" + Robots[i].r_no + "\t\t" + Robots[i].r_name + "\t\t" + DTS(Robots[i].r_price) + "\t" + Robots[i].description + "\n";
	}

	BR->value(result.c_str());

	Fl_Input *detcat = new Fl_Input(250, 350, 100, 30, "Serial No : "); // Child 1
	Fl_Button *img = new Fl_Button(250, 400, 100, 50, "IMAGE");
	img->callback(ImageCB);

	CW->resizable(BR);
	CW->end();
	CW->show();
	view->redraw();
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
	temp = (Fl_Input*)b->parent()->child(35);
	R.image = temp->value();
	Robots.push_back(R);
}

void RoboPartsCB(Fl_Widget* w, void* p)
{
	Fl_Window *CRP = new Fl_Window(1280, 720);

	Fl_Input *modelno = new Fl_Input(150, 50, 100, 30, "Model Number : "); //Child 0
	Fl_Input *modelname = new Fl_Input(450, 50, 100, 30, "Model Name : "); //Child 1
	Fl_Input *description = new Fl_Input(750, 50, 200, 30, "Description : ");//Child 2

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

	Fl_Input *image = new Fl_Input(450, 600, 100, 30, "Image : "); //Child 35
	Fl_Button *Enter = new Fl_Button(625, 625, 100, 50, "ENTER");
	Enter->callback(EnterRoboPartsCB);

	CRP->show();
	view->redraw();
}

void Create_PM_CB(Fl_Widget* w, void* p)
{
	Fl_Button* b = (Fl_Button*)w;
	Fl_Input* temp;
	temp = (Fl_Input*)b->parent()->child(0);
	PM.pm_no = temp->value();
	temp = (Fl_Input*)b->parent()->child(1);
	PM.pm_name = temp->value();
	temp = (Fl_Input*)b->parent()->child(2);
	PM.password = temp->value();

	Managers.push_back(PM);
}

void CreatePMCB(Fl_Widget* w, void* p)
{
	Fl_Window *win = new Fl_Window(400, 400, "Create Manager");
	Fl_Input *sa_no = new Fl_Input(200, 50, 100, 30, "Prodcut Manager No : "); //Child 0
	Fl_Input *sa_name = new Fl_Input(200, 150, 100, 30, "Product Manager Name : "); //Child 1
	Fl_Input *sa_pass = new Fl_Input(200, 250, 100, 30, "Password : "); //Child 2
	Fl_Button *Create = new Fl_Button(200, 350, 80, 50, "CREATE");
	Create->callback(Create_PM_CB);

	win->show();
	view->redraw();
}

void ViewManagersCB(Fl_Widget* w, void* p)
{
	Fl_Window *PM = new Fl_Window(600, 300, "Product Managers");
	Fl_Multiline_Output *out = new Fl_Multiline_Output(10, 10, 500, 250);

	out->type(FL_MULTILINE_OUTPUT);
	out->textfont(FL_COURIER);

	string result = "No. \t Name \t Password\n";

	for (int i = 0; i < Managers.size(); i++)
	{
		result += Managers[i].pm_no + " \t " + Managers[i].pm_name + " \t " + Managers[i].password + "\n";
	}

	out->value(result.c_str());

	PM->resizable(out);
	PM->end();
	PM->show();
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
	temp = (Fl_Input*)b->parent()->child(2);
	C.password = temp->value();

	Customers.push_back(C);
}

void CreateCustomerCB(Fl_Widget* w, void* p)
{
	Fl_Window *win = new Fl_Window(400, 400, "Create Customer");
	Fl_Input *cust_no = new Fl_Input(150, 50, 100, 30, "Customer No : "); //Child 0
	Fl_Input *cust_name = new Fl_Input(150, 150, 100, 30, "Customer Name : "); //Child 1
	Fl_Input *cust_pass = new Fl_Input(150, 250, 100, 30, "Password : "); //Child 2
	Fl_Button *Create = new Fl_Button(150, 300, 80, 50, "CREATE");
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
	temp = (Fl_Input*)b->parent()->child(2);
	SA.password = temp->value();

	SalesAssociates.push_back(SA);
}

void CreateSACB(Fl_Widget* w, void* p)
{
	Fl_Window *win = new Fl_Window(400, 400, "Create SA");
	Fl_Input *sa_no = new Fl_Input(200, 50, 100, 30, "Sales Associate No : "); //Child 0
	Fl_Input *sa_name = new Fl_Input(200, 150, 100, 30, "Sales Associate Name : "); //Child 1
	Fl_Input *sa_pass = new Fl_Input(200, 250, 100, 30, "Password : "); //Child 2
	Fl_Button *Create = new Fl_Button(200, 350, 80, 50, "CREATE");
	Create->callback(Create_SA_CB);

	win->show();
	view->redraw();
}

void ViewCustomerCB(Fl_Widget* w, void* p)
{
	Fl_Window *VC = new Fl_Window(600, 300, "Customers");
	Fl_Multiline_Output *out = new Fl_Multiline_Output(10, 10, 500, 250);

	out->type(FL_MULTILINE_OUTPUT);
	out->textfont(FL_COURIER);

	string result = "No. \t Name \t Password\n";

	for (int i = 0; i < Customers.size(); i++)
	{
		result += Customers[i].cust_no + " \t " + Customers[i].cust_name + " \t " + Customers[i].password + "\n";
	}

	out->value(result.c_str());

	VC->resizable(out);
	VC->end();
	VC->show();
	view->redraw();
}

void ViewSACB(Fl_Widget* w, void* p)
{
	Fl_Window *VSA = new Fl_Window(600, 300, "Sales Associates");
	Fl_Multiline_Output *out = new Fl_Multiline_Output(10, 10, 500, 250);

	out->type(FL_MULTILINE_OUTPUT);
	out->textfont(FL_COURIER);

	string result = "No. \t Name \t   Password\n";

	for (int i = 0; i < SalesAssociates.size(); i++)
	{
		result += SalesAssociates[i].sa_no + " \t " + SalesAssociates[i].sa_name + "   " + SalesAssociates[i].password + "\n";
	}

	out->value(result.c_str());

	VSA->resizable(out);
	VSA->end();
	VSA->show();
	view->redraw();
}

void ProfitCB(Fl_Widget* w, void* p)
{
	Fl_Window  *win = new Fl_Window(600, 400, "Profit");
	Fl_Multiline_Output *BR = new Fl_Multiline_Output(10, 10, win->w() - 20, win->h() - 20);

	BR->type(FL_MULTILINE_OUTPUT);
	BR->textfont(FL_COURIER);
	string result = "Robot Name \t Profit ($)\n";

	for (int i = 0; i < Robots.size(); i++)
	{
		result += Robots[i].r_name + " \t " + DTS(Robots[i].r_profit) + "\n";
	}
	BR->value(result.c_str());
	win->resizable(BR);
	win->end();
	win->show();
	view->redraw();
}

void OrdersCB(Fl_Widget* w, void* p)
{
	Fl_Window  *win = new Fl_Window(1000, 500, "Orders");
	Fl_Multiline_Output *BR = new Fl_Multiline_Output(10, 10, win->w() - 20, win->h() - 20);
	BR->type(FL_MULTILINE_OUTPUT);
	BR->textfont(FL_COURIER);
	string result = "Order No \tCust-Name \tRobots Ordered \t  SA-Name \t   Sales-Date \t   Model-Name \t\tNet-Total\n";
	for (int i = 0; i < Orders.size(); i++)
	{
		result += Orders[i].order_no + "\t\t" + Orders[i].cust_name + "\t\t" + ITS(Orders[i].robots_ordered) + "\t\t" + Orders[i].sa_name + " \t\t" + Orders[i].sales_date + " \t" + Orders[i].model_name + " \t\t" + DTS(Orders[i].net_total) + "\n";
	}
	BR->value(result.c_str());
	win->resizable(BR);
	win->end();
	win->show();
	view->redraw();
}

void SalesReportCB(Fl_Widget* w, void* p)
{
	Fl_Window  *win = new Fl_Window(600, 400, "Sales Report");
	Fl_Multiline_Output *BR = new Fl_Multiline_Output(10, 10, win->w() - 20, win->h() - 20);
	BR->type(FL_MULTILINE_OUTPUT);
	BR->textfont(FL_COURIER);
	string result = "Name of Sales Associate \tTotal Sales\n";
	double total_sales = 0;
	string ans;
	double max;
	int index_no;
	int k;
	for (int i = 0; i < Orders.size(); i++)
	{
		total_sales = 0;
		for (int j = 0; j < Orders.size(); j++)
		{
			if (Orders[i].sa_name == Orders[j].sa_name)
			{
				total_sales = total_sales + Orders[j].net_total;
			}
		}
		result += Orders[i].sa_name + "  \t\t\t" + DTS(total_sales) + "\n";
	}
	BR->value(result.c_str());
	win->resizable(BR);
	win->end();
	win->show();
	view->redraw();
}

void ModelSalesCB(Fl_Widget* w, void* p)
{
	Fl_Window  *win = new Fl_Window(600, 400, "Model Sales");
	Fl_Multiline_Output *BR = new Fl_Multiline_Output(10, 10, win->w() - 20, win->h() - 20);

	BR->type(FL_MULTILINE_OUTPUT);
	BR->textfont(FL_COURIER);

	string result = "Model Name\tRobots Sold\n";

	int r_sold = 0;

	for (int i = 0; i < Orders.size(); i++)
	{
		r_sold = 0;
		for (int j = 0; j < Orders.size(); j++)
		{
			if (Orders[i].model_name == Orders[j].model_name)
			{
				r_sold = r_sold + Orders[j].robots_ordered;
			}
		}
		result += Orders[i].model_name + "  \t" + ITS(r_sold) + "\n";
	}
	BR->value(result.c_str());
	win->resizable(BR);
	win->end();
	win->show();
	view->redraw();
}

void StoreOrderCB(Fl_Widget* w, void* p)
{
	Fl_Button* b = (Fl_Button*)w;
	Fl_Input* temp;
	temp = (Fl_Input*)b->parent()->child(0);
	O.order_no = temp->value();

	temp = (Fl_Input*)b->parent()->child(1);
	O.cust_no = temp->value();

	temp = (Fl_Input*)b->parent()->child(2);
	O.cust_name = temp->value();

	temp = (Fl_Input*)b->parent()->child(3);
	O.robots_ordered = str_to_double(temp->value());

	temp = (Fl_Input*)b->parent()->child(4);
	O.sa_name = temp->value();

	temp = (Fl_Input*)b->parent()->child(5);
	O.sales_date = temp->value();

	temp = (Fl_Input*)b->parent()->child(6);
	O.model_name = temp->value();

	for (int i = 0; i < Robots.size(); i++)
	{
		if (O.model_name == Robots[i].r_name)
		{
			O.sub_total = Robots[i].r_price*O.robots_ordered;
		}
	}

	O.shipping = O.sub_total*0.10;
	O.tax = O.sub_total*.08;
	O.net_total = O.sub_total + O.shipping + O.tax;
	Orders.push_back(O);
}

void OrderCB(Fl_Widget* w, void* p)
{
	Fl_Window *order = new Fl_Window(300, 500, "New Order");
	Fl_Input *order_no = new Fl_Input(150, 50, 100, 30, "Order Number : "); //Child 0
	Fl_Input *cust_no = new Fl_Input(150, 100, 100, 30, "Customer Number : "); //Child 1
	Fl_Input *cust_name = new Fl_Input(150, 150, 100, 30, "Customer Name : "); //Child 2
	Fl_Input *robots_ordered = new Fl_Input(150, 200, 100, 30, "No.Robots Ordered : "); //Child 3
	Fl_Input *sa_name = new Fl_Input(150, 250, 100, 30, "Sales Assc. Name : "); //Child 4
	Fl_Input *sales_date = new Fl_Input(150, 300, 100, 30, "Sales Date : "); //Child 5
	Fl_Input *model_name = new Fl_Input(150, 350, 100, 30, "Model Name : "); //Child 6
	Fl_Button *create_order = new Fl_Button(150, 425, 100, 50, "Create Order");
	create_order->callback(StoreOrderCB);
	order->show();
	order->resizable(order);
	view->redraw();
}

void GenerateBill(Fl_Widget* w, void* p)
{
	Fl_Button* b = (Fl_Button*)w;
	Fl_Input* temp;
	temp = (Fl_Input*)b->parent()->child(0);
	string order_no = temp->value();

	Fl_Window *Bill = new Fl_Window(700, 300, "Bill of Sale");
	Fl_Multiline_Output *out = new Fl_Multiline_Output(10, 10, 600, 250);

	out->type(FL_MULTILINE_OUTPUT);

	string result = "";
	for (int i = 0; i < Orders.size(); i++)
	{
		if (order_no == Orders[i].order_no)
		{
			result += "Order No.: " + Orders[i].order_no + "\n";
			result += "Customer Name: " + Orders[i].cust_name + "\n";
			result += "Model Name: " + Orders[i].model_name + "\n";
			result += "Robots Ordered: " + DTS(Orders[i].robots_ordered) + "\n";
			result += "Sub-Total: $" + DTS(Orders[i].sub_total) + "\n";
			result += "Shipping: $" + DTS(Orders[i].shipping) + "\n";
			result += "Tax: $" + DTS(Orders[i].tax) + "\n";
			result += "Total: $" + DTS(Orders[i].net_total) + "\n\n";
		}
	}

	out->value(result.c_str());
	Bill->resizable(out);
	Bill->end();
	Bill->show();
	view->redraw();
}

void BillCB(Fl_Widget* w, void* p)
{
	Fl_Window *win = new Fl_Window(300, 200, "Search Orders");
	Fl_Input *order_no = new Fl_Input(150, 50, 100, 30, "Enter order No. : "); //Child 0
	Fl_Button *Generate = new Fl_Button(150, 100, 80, 50, "Generate");
	Generate->callback(GenerateBill);
	win->show();
	view->redraw();
}

void CustBCB(Fl_Widget* w, void* p)
{
	Fl_Window *CW = new Fl_Window(500, 500, "Customer Bill");
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *display = new Fl_Text_Display(10, 10, 500, 500);
	display->buffer(buff);
	CW->resizable(*display);
	CW->show();

	Fl_Button* b = (Fl_Button*)w;
	Fl_Input* temp;
	temp = (Fl_Input*)b->parent()->child(0);
	string input = temp->value();
	int n = (int)STD(input);

	string result = "";
	string d = "";
	double order_total = 0;
	for (int i = 0; i < Orders.size(); i++)
	{
		if (i == (n - 1))
		{
			order_total += Orders[i].net_total;
			result += "Order No.: " + Orders[i].order_no + "\n";
			result += "Customer Name: " + Orders[i].cust_name + "\n";
			result += "Model Name: " + Orders[i].model_name + "\n";
			result += "Robots Ordered: " + DTS(Orders[i].robots_ordered) + "\n";
			result += "Sub-Total: $" + DTS(Orders[i].sub_total) + "\n";
			result += "Shipping: $" + DTS(Orders[i].shipping) + "\n";
			result += "Tax: $" + DTS(Orders[i].tax) + "\n";
			result += "Total: $" + DTS(Orders[i].net_total) + "\n\n";
		}
	}
	result += "Total Bill Amount: $" + DTS(order_total);
	buff->text(result.c_str());
	CW->end();
	view->redraw();
}

void CustBillCB(Fl_Widget* w, void* p)
{
	Fl_Window *CW = new Fl_Window(300, 150, "Bill");
	Fl_Input *cno = new Fl_Input(150, 50, 100, 30, "Customer Number :");
	Fl_Button *Enter = new Fl_Button(150, 100, 80, 30, "Enter");
	Enter->callback(CustBCB);
	CW->end();
	CW->show();
	view->redraw();
}

void CustOCB(Fl_Widget* w, void* p)
{
	Fl_Window *CW = new Fl_Window(500, 500, "Customer Order");
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *display = new Fl_Text_Display(10, 10, 500, 500);
	display->buffer(buff);
	CW->resizable(*display);
	CW->show();

	Fl_Button* b = (Fl_Button*)w;
	Fl_Input* temp;
	temp = (Fl_Input*)b->parent()->child(0);
	string input = temp->value();
	int n = (int)STD(input);

	string result = "";
	string d = "";

	double order_total = 0;
	for (int i = 0; i < Orders.size(); i++)
	{
		if (i == (n - 1))
		{
			order_total += Orders[i].net_total;
			result += "Order No.: " + Orders[i].order_no + "\n";
			result += "Order Date: " + Orders[i].sales_date + "\n";
			result += "SA Name: " + Orders[i].sa_name + "\n";
			result += "Model Name: " + Orders[i].model_name + "\n";
			result += "Robots Ordered: " + DTS(Orders[i].robots_ordered) + "\n";
			result += "Sub-Total: $" + DTS(Orders[i].sub_total) + "\n";
			result += "Shipping: $" + DTS(Orders[i].shipping) + "\n";
			result += "Tax: $" + DTS(Orders[i].tax) + "\n";
			result += "Total: $" + DTS(Orders[i].net_total) + "\n\n";
		}
	}
	result += "Total Order Amount: $" + DTS(order_total);
	buff->text(result.c_str());
	CW->end();
	view->redraw();
}

void CustOrderCB(Fl_Widget* w, void* p)
{
	Fl_Window *CW = new Fl_Window(300, 150, "Order");
	Fl_Input *cno = new Fl_Input(150, 50, 100, 30, "Customer Number :");
	Fl_Button *Enter = new Fl_Button(150, 100, 80, 30, "Enter");
	Enter->callback(CustOCB);
	CW->end();
	CW->show();
	view->redraw();
}

void DetailedCatalogCB(Fl_Widget* w, void* p)
{
	Fl_Window *CW = new Fl_Window(600, 600, "Detailed Catalog");
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *display = new Fl_Text_Display(10, 10, 600, 600);
	display->buffer(buff);
	CW->resizable(*display);

	Fl_Button* b = (Fl_Button*)w;
	Fl_Input* temp;
	temp = (Fl_Input*)b->parent()->child(1);
	string input = temp->value();
	int n = (int)STD(input);

	string result = "";
	string d = "";
	for (int i = 0; i < Robots.size(); i++)
	{
		if (i == (n - 1))
		{
			result += "Model No.: " + Robots[i].r_no + "\n";
			result += "Name: " + Robots[i].r_name + "\n";
			result += "Price: " + DTS(Robots[i].r_price) + "\n";
			result += "Description: " + Robots[i].description + "\n\n";

			result += d + "Specifications:" + "\n";
			result += "Name: " + Robots[i].arms_name + "\n";
			result += "Type: " + Robots[i].arms_type + "\n";
			result += "Weight: " + DTS(Robots[i].arms_weight) + "\n";
			result += "Part No.: " + Robots[i].arms_partno + "\n\n";

			result += d + "Torso Specifications:" + "\n";
			result += "Name: " + Robots[i].torso_name + "\n";
			result += "Type: " + Robots[i].torso_type + "\n";
			result += "Weight: " + DTS(Robots[i].torso_weight) + "\n";
			result += "Part No.: " + Robots[i].torso_partno + "\n";
			result += "Compartments: " + DTS(Robots[i].compartments) + "\n\n";

			result += d + "Locomoter Specifications:" + "\n";
			result += "Name: " + Robots[i].locomoter_name + "\n";
			result += "Type: " + Robots[i].locomoter_type + "\n";
			result += "Weight: " + DTS(Robots[i].locomoter_weight) + "\n";
			result += "Part No.: " + Robots[i].locomoter_partno + "\n";
			result += "Max. Speed: " + Robots[i].locomoter_partno + "\n";
			result += "Power Consumed: " + Robots[i].locomoter_partno + "\n\n";

			result += d + "Battery Specifications:" + "\n";
			result += "Name: " + Robots[i].battery_name + "\n";
			result += "Type: " + Robots[i].battery_type + "\n";
			result += "Weight: " + DTS(Robots[i].battery_weight) + "\n";
			result += "Part No.: " + Robots[i].battery_partno + "\n";
			result += "Max. Power: " + DTS(Robots[i].max_power) + "\n";
			result += "Energy: " + DTS(Robots[i].energy) + "\n\n";

			result += d + "Arm Specifications:" + "\n";
			result += "Name: " + Robots[i].arms_name + "\n";
			result += "Type: " + Robots[i].arms_type + "\n";
			result += "Weight: " + DTS(Robots[i].arms_weight) + "\n";
			result += "Part No.: " + Robots[i].arms_partno + "\n";
			result += "No.: " + DTS(Robots[i].no_of_arms) + "\n";
			result += "Power Consumed: " + DTS(Robots[i].arms_power);
		}
	}

	buff->text(result.c_str());

	CW->end();
	CW->show();
	view->redraw();
}

void CatalogCB(Fl_Widget* w, void* p)
{
	Fl_Window *CW = new Fl_Window(600, 500, "Catalog");
	Fl_Multiline_Output *BR = new Fl_Multiline_Output(0, 0, 600, 300); // Child 0

	BR->type(FL_MULTILINE_OUTPUT);
	BR->textfont(FL_COURIER);

	string result = "No.\tModel No.\tName\t\t\tPrice\tDescription\t\n";
	string s;

	for (int i = 0; i < Robots.size(); i++)
	{
		s = ITS(i + 1);
		result += s + "\t" + Robots[i].r_no + "\t\t" + Robots[i].r_name + "\t\t" + DTS(Robots[i].r_price) + "\t" + Robots[i].description + "\n";
	}

	BR->value(result.c_str());

	Fl_Input *detcat = new Fl_Input(250, 350, 100, 30, "Serial No : "); // Child 1
	Fl_Button *Enter = new Fl_Button(200, 400, 100, 50, "DETAILS");
	Fl_Button *img = new Fl_Button(400, 400, 100, 50, "IMAGE");
	Enter->callback(DetailedCatalogCB);
	img->callback(ImageCB);

	CW->resizable(BR);
	CW->end();
	CW->show();
	view->redraw();
}

void GenerateSAR(Fl_Widget* w, void* p)
{
	Fl_Button* b = (Fl_Button*)w;
	Fl_Input* temp;
	temp = (Fl_Input*)b->parent()->child(0);
	string sa_name = temp->value();

	Fl_Window *Report = new Fl_Window(600, 300, "My Report");
	Fl_Multiline_Output *out = new Fl_Multiline_Output(10, 10, 500, 250);

	out->type(FL_MULTILINE_OUTPUT);
	out->textfont(FL_COURIER);

	string result = sa_name + "\n";
	result += "Customer Name\t Date\t Amount\n";

	for (int i = 0; i < Orders.size(); i++)
	{
		if (sa_name == Orders[i].sa_name)
		{
			result += Orders[i].cust_name + "\t" + Orders[i].sales_date + "\t" + double_to_str(Orders[i].net_total) + "\n";
		}
	}

	out->value(result.c_str());

	Report->resizable(out);
	Report->end();
	Report->show();
	view->redraw();
}

void SAReportCB(Fl_Widget* w, void* p)
{
	Fl_Window *win = new Fl_Window(220, 220, "SA Report");
	Fl_Input *sa_no = new Fl_Input(100, 50, 100, 30, "SA Name : "); //Child 0
	Fl_Button *Generate = new Fl_Button(50, 125, 80, 50, "Generate");
	Generate->callback(GenerateSAR);
	win->show();
	view->redraw();
}

void View::draw()
{
	Fl_Box::draw();
}

bool View::saved()
{
	return dirty;
}

void OpenCB(Fl_Widget* w, void* p)
{
	ifstream read_Orders;
	read_Orders.open("Orders_data.txt");

	ifstream read_Robots;
	read_Robots.open("Robots_data.txt");

	ifstream read_Cust;
	read_Cust.open("Cust_data.txt");

	ifstream read_SA;
	read_SA.open("SA_data.txt");

	ifstream read_PM;
	read_PM.open("PM_data.txt");

	string word;
	double number;

	while (getline(read_Orders, word, '@'))
	{
		O.order_no = word;

		getline(read_Orders, word, '@');
		O.cust_no = word;

		getline(read_Orders, word, '@');
		O.cust_name = word;

		getline(read_Orders, word, '@');
		number = str_to_double(word);
		O.robots_ordered = (int)number;

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

		Orders.push_back(O);
	}

	while (getline(read_Robots, word, '@'))
	{
		//Robot Specs
		R.r_name = word;

		getline(read_Robots, word, '@');
		R.r_no = word;

		getline(read_Robots, word, '@');
		R.description = word;

		getline(read_Robots, word, '@');
		R.image = word;

		getline(read_Robots, word, '@');
		number = str_to_double(word);
		R.r_cost = number;

		getline(read_Robots, word, '@');
		number = str_to_double(word);
		R.r_price = number;

		getline(read_Robots, word, '@');
		number = str_to_double(word);
		R.r_profit = number;

		// Head Specs
		R.head_name = word;

		getline(read_Robots, word, '@');
		R.head_type = word;

		getline(read_Robots, word, '@');
		number = str_to_double(word);
		R.head_cost = number;

		getline(read_Robots, word, '@');
		number = str_to_double(word);
		R.head_weight = number;

		getline(read_Robots, word, '@');
		R.head_partno = word;

		// Torso Specs
		getline(read_Robots, word, '@');
		R.torso_name = word;

		getline(read_Robots, word, '@');
		R.torso_type = word;

		getline(read_Robots, word, '@');
		number = str_to_double(word);
		R.torso_cost = number;

		getline(read_Robots, word, '@');
		number = str_to_double(word);
		R.torso_weight = number;

		getline(read_Robots, word, '@');
		R.torso_partno = word;

		getline(read_Robots, word, '@');
		number = str_to_double(word);
		R.compartments = (int)number;

		// Locomoter Specs
		getline(read_Robots, word, '@');
		R.locomoter_name = word;

		getline(read_Robots, word, '@');
		R.locomoter_type = word;

		getline(read_Robots, word, '@');
		number = str_to_double(word);
		R.locomoter_cost = number;

		getline(read_Robots, word, '@');
		number = str_to_double(word);
		R.locomoter_weight = number;

		getline(read_Robots, word, '@');
		R.locomoter_partno = word;

		getline(read_Robots, word, '@');
		number = str_to_double(word);
		R.max_speed = number;

		getline(read_Robots, word, '@');
		number = str_to_double(word);
		R.power_consumed = number;

		// Battery Specs
		getline(read_Robots, word, '@');
		R.battery_name = word;

		getline(read_Robots, word, '@');
		R.battery_type = word;

		getline(read_Robots, word, '@');
		number = str_to_double(word);
		R.battery_cost = number;

		getline(read_Robots, word, '@');
		number = str_to_double(word);
		R.battery_weight = number;

		getline(read_Robots, word, '@');
		R.battery_partno = word;

		getline(read_Robots, word, '@');
		number = str_to_double(word);
		R.max_power = number;

		getline(read_Robots, word, '@');
		number = str_to_double(word);
		R.energy = number;

		// Arms Specs
		getline(read_Robots, word, '@');
		R.arms_name = word;

		getline(read_Robots, word, '@');
		R.arms_type = word;

		getline(read_Robots, word, '@');
		number = str_to_double(word);
		R.arms_cost = number;

		getline(read_Robots, word, '@');
		number = str_to_double(word);
		R.arms_weight = number;

		getline(read_Robots, word, '@');
		R.arms_partno = word;

		getline(read_Robots, word, '@');
		number = str_to_double(word);
		R.no_of_arms = (int)number;

		getline(read_Robots, word, '\n');
		number = str_to_double(word);
		R.arms_power = number;

		Robots.push_back(R);
	}

	while (getline(read_Cust, word, '@'))
	{
		C.cust_no = word;

		getline(read_Cust, word, '@');
		C.cust_name = word;

		getline(read_Cust, word, '\n');
		C.password = word;

		Customers.push_back(C);
	}

	while (getline(read_SA, word, '@'))
	{
		SA.sa_no = word;

		getline(read_SA, word, '@');
		SA.sa_name = word;

		getline(read_SA, word, '\n');
		SA.password = word;

		SalesAssociates.push_back(SA);
	}

	while (getline(read_PM, word, '@'))
	{
		PM.pm_no = word;

		getline(read_PM, word, '@');
		PM.pm_name = word;

		getline(read_PM, word, '\n');
		PM.password = word;

		Managers.push_back(PM);
	}
}

void SaveCB(Fl_Widget* w, void* p)
{
	ofstream write_Orders;
	write_Orders.open("Orders_data.txt");

	ofstream write_Robots;
	write_Robots.open("Robots_data.txt");

	ofstream write_Cust;
	write_Cust.open("Cust_data.txt");

	ofstream write_SA;
	write_SA.open("SA_data.txt");

	ofstream write_PM;
	write_PM.open("PM_data.txt");

	for (int i = 0; i < Orders.size(); i++)
	{
		write_Orders << Orders[i].order_no << "@"
			<< Orders[i].cust_no << "@"
			<< Orders[i].cust_name << "@"
			<< Orders[i].robots_ordered << "@"
			<< Orders[i].sa_name << "@"
			<< Orders[i].sales_date << "@"
			<< Orders[i].model_name << "@"
			<< Orders[i].sub_total << "@"
			<< Orders[i].shipping << "@"
			<< Orders[i].tax << "@"
			<< Orders[i].net_total << endl;
	}

	for (int i = 0; i < Robots.size(); i++)
	{
		write_Robots << Robots[i].r_name << "@"
			<< Robots[i].r_no << "@"
			<< Robots[i].description << "@"
			<< Robots[i].image << "@"
			<< Robots[i].r_cost << "@"
			<< Robots[i].r_price << "@"
			<< Robots[i].r_profit << "@"
			<< Robots[i].head_name << "@"
			<< Robots[i].head_type << "@"
			<< Robots[i].head_cost << "@"
			<< Robots[i].head_weight << "@"
			<< Robots[i].head_partno << "@"
			<< Robots[i].torso_name << "@"
			<< Robots[i].torso_type << "@"
			<< Robots[i].torso_cost << "@"
			<< Robots[i].torso_weight << "@"
			<< Robots[i].torso_partno << "@"
			<< Robots[i].compartments << "@"
			<< Robots[i].locomoter_name << "@"
			<< Robots[i].locomoter_type << "@"
			<< Robots[i].locomoter_cost << "@"
			<< Robots[i].locomoter_weight << "@"
			<< Robots[i].locomoter_partno << "@"
			<< Robots[i].max_speed << "@"
			<< Robots[i].power_consumed << "@"
			<< Robots[i].battery_name << "@"
			<< Robots[i].battery_type << "@"
			<< Robots[i].battery_cost << "@"
			<< Robots[i].battery_weight << "@"
			<< Robots[i].battery_partno << "@"
			<< Robots[i].max_power << "@"
			<< Robots[i].energy << "@"
			<< Robots[i].arms_name << "@"
			<< Robots[i].arms_type << "@"
			<< Robots[i].arms_cost << "@"
			<< Robots[i].arms_weight << "@"
			<< Robots[i].arms_partno << "@"
			<< Robots[i].no_of_arms << "@"
			<< Robots[i].arms_power << endl;
	}

	for (int i = 0; i < Customers.size(); i++)
	{
		write_Cust << Customers[i].cust_no << "@"
			<< Customers[i].cust_name << "@"
			<< Customers[i].password << endl;
	}

	for (int i = 0; i < SalesAssociates.size(); i++)
	{
		write_SA << SalesAssociates[i].sa_no << "@"
			<< SalesAssociates[i].sa_name << "@"
			<< SalesAssociates[i].password << endl;
	}

	for (int i = 0; i < Managers.size(); i++)
	{
		write_PM << Managers[i].pm_no << "@"
			<< Managers[i].pm_name << "@"
			<< Managers[i].password << endl;
	}
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

void NewCB(Fl_Widget* w, void* p)
{
	R.r_name = "Optimus Prime";
	R.image = "Optimus.jpg";
	R.r_no = "101";
	R.r_cost = 500;
	R.r_price = 800;
	R.r_profit = 300;
	R.description = "Autobot Leader";
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
	Robots.push_back(R);

	R.r_name = "Bumblebee";
	R.image = "Bumblebee.jpg";
	R.r_no = "102";
	R.r_cost = 250;
	R.r_price = 750;
	R.r_profit = 500;
	R.description = "Autobot";
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
	Robots.push_back(R);

	O.order_no = "1";
	O.cust_no = "1";
	O.cust_name = "Sam";
	O.robots_ordered = 1;
	O.sa_name = "Simmons";
	O.sales_date = "01/01/01";
	O.model_name = "Optimus";
	O.sub_total = 800;
	O.shipping = 80;
	O.tax = 64;
	O.net_total = 944;
	Orders.push_back(O);

	O.order_no = "2";
	O.cust_no = "2";
	O.cust_name = "Mike";
	O.robots_ordered = 2;
	O.sa_name = "William";
	O.sales_date = "02/02/02";
	O.model_name = "Bumblebee";
	O.sub_total = 250;
	O.shipping = 25;
	O.tax = 25;
	O.net_total = 300;
	Orders.push_back(O);

	C.cust_no = "1";
	C.cust_name = "Sam";
	C.password = "Sam1";
	Customers.push_back(C);

	C.cust_no = "2";
	C.cust_name = "Mike";
	C.password = "Mike2";
	Customers.push_back(C);

	SA.sa_no = "1";
	SA.sa_name = "Simmons";
	SA.password = "Simmons1";
	SalesAssociates.push_back(SA);

	SA.sa_no = "2";
	SA.sa_name = "William";
	SA.password = "William2";
	SalesAssociates.push_back(SA);

	PM.pm_no = "1";
	PM.pm_name = "John";
	PM.password = "John1";
	Managers.push_back(PM);
}

int main()
{
	// CREATE WINDOW
	win = new Fl_Window(720, 480, "RoboShop");
	win->color(FL_WHITE);
	view = new View(0, 0, 720, 480);
	//MAIN MENU
	menubar = new Fl_Menu_Bar(0, 0, 720, 30);
	Fl_Menu_Item menuitems[] =
	{
		{ "&File",0,0,0, FL_SUBMENU },
		{ "New",0,(Fl_Callback*)NewCB,0,FL_MENU_DIVIDER },
		{ "Open",0,(Fl_Callback*)OpenCB },
		{ "Save",0,(Fl_Callback*)SaveCB,0,FL_MENU_DIVIDER },
		{ "Help",0,(Fl_Callback*)HelpCB },
		{ "Quit",0,(Fl_Callback*)QuitCB },
		{ 0 },
		{ "&Product Manager",0,0,0, FL_SUBMENU },
		{ "Create Robot Parts",0,(Fl_Callback*)RoboPartsCB },
		{ "Delete Robot Parts",0,(Fl_Callback*)DeleteRPCB },
		{ "View Robot Parts",0,(Fl_Callback*)ViewRPCB },
		{ 0 },
		{ "&Boss",0,0,0, FL_SUBMENU },
		{ "Sales Report",0,(Fl_Callback*)SalesReportCB },
		{ "View Orders",0,(Fl_Callback*)OrdersCB,0,FL_MENU_DIVIDER },
		{ "Model's Sales",0,(Fl_Callback*)ModelSalesCB },
		{ "Model's Profit",0,(Fl_Callback*)ProfitCB,0,FL_MENU_DIVIDER },
		{ "Create Product Manager",0,(Fl_Callback*)CreatePMCB },
		{ "Create Customer",0,(Fl_Callback*)CreateCustomerCB },
		{ "Create Sales Associate",0,(Fl_Callback*)CreateSACB,0,FL_MENU_DIVIDER },
		{ "View Product Managers",0,(Fl_Callback*)ViewManagersCB },
		{ "View Customers",0,(Fl_Callback*)ViewCustomerCB },
		{ "View Sales Associates",0,(Fl_Callback*)ViewSACB },
		{ 0 },
		{ "&Sales Associate",0,0,0, FL_SUBMENU },
		{ "Sales Report",0,(Fl_Callback*)SAReportCB },
		{ "Create Order",0,(Fl_Callback*)OrderCB },
		{ "Create Bill",0,(Fl_Callback*)BillCB },
		{ 0 },
		{ "&Customer",0,0,0, FL_SUBMENU },
		{ "View Catalog",0,(Fl_Callback*)CatalogCB },
		{ "View Bills",0,(Fl_Callback*)CustBillCB },
		{ "View Orders",0,(Fl_Callback*)CustOrderCB },
		{ 0 },
		{ 0 }
	};
	menubar->menu(menuitems);
	win->end();
	win->show();
	return (Fl::run());
}
