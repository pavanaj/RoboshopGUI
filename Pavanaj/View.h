#ifndef __VIEW_H
#define __VIEW_H

#include <C:\msys\1.0\local\include\FL\Fl_Box.H>
class View : public Fl_Box
{
public:
	bool dirty;
	View(int x, int y, int w, int h) : Fl_Box(x, y, w, h) {
		dirty = false;
	};
	void draw();
	bool saved();
};

#endif
