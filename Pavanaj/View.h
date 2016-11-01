#ifndef __VIEW_H
#define __VIEW_H
#include <FL/Fl.H>
#include <Fl/Fl_Box.H>

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
