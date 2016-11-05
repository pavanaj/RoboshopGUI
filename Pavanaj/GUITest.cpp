#include <C:/msys/1.0/local/include/FL/Fl.H>
#include <C:/msys/1.0/local/include/FL/Fl_Window.H>
#include <C:/msys/1.0/local/include/FL/Fl_Button.H>
#include <C:/msys/1.0/local/include/FL/Fl_Input.H>
#include <C:/msys/1.0/local/include/FL/Fl_Output.H>
#include <string.h>
using namespace std;

void copy_cb(Fl_Widget* o, void* p) 
{
	Fl_Button* b = (Fl_Button*)o;
	Fl_Input* iw = (Fl_Input*)b->parent()->child(2);
	Fl_Output* ow = (Fl_Output*)b->parent()->child(3);
	ow->value(iw->value());
}

void close_cb(Fl_Widget* o, void* p) 
{
	//	exit(0);
}
void make_window() 
{
	Fl_Window* win = new Fl_Window(300, 200, "Testing 2");
	Fl_Button* copy = new Fl_Button(10, 150, 70, 30, "C&opy"); 
	Fl_Button* close = new Fl_Button(100, 150, 70, 30, "&Quit");
	Fl_Input* inp = new Fl_Input(50, 50, 140, 30, "In");        
	Fl_Output* out = new Fl_Output(50, 100, 140, 30, "Out");    	
	copy->callback(copy_cb);
	close->callback(close_cb);
	win->show();
}
int main() 
{
	make_window();
	return (Fl::run());
}