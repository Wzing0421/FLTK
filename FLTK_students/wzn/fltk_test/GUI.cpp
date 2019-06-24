
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include "GUI.h"

extern Graph_lib::namebutton *usrlist[8];
extern Graph_lib::ReturnButton *returnButton;

namespace Graph_lib {

//------------------------------------------------------------------------------

void Button::attach(Window& win)
{
    pw = new Fl_Button(loc.x, loc.y, width, height, label.c_str());
    pw->callback(reinterpret_cast<Fl_Callback*>(do_it), &win); // pass the window
    own = &win;
}

//------------------------------------------------------------------------------

int In_box::get_int()
{
    Fl_Input& pi = reference_to<Fl_Input>(pw);
    // return atoi(pi.value());
    const char* p = pi.value();
    if (!isdigit(p[0])) return -999999;
    return atoi(p);
}

//------------------------------------------------------------------------------

void In_box::attach(Window& win)
{
    pw = new Fl_Input(loc.x, loc.y, width, height, label.c_str());
    own = &win;
}

//------------------------------------------------------------------------------

void Out_box::put(const string& s)
{
    reference_to<Fl_Output>(pw).value(s.c_str());
}

//------------------------------------------------------------------------------

void Out_box::attach(Window& win)
{
    pw = new Fl_Output(loc.x, loc.y, width, height, label.c_str());
    own = &win;
}

//------------------------------------------------------------------------------

int Menu::attach(Button& b)
{
    b.width = width;
    b.height = height;

    switch(k) {
    case horizontal:
        b.loc = Point(loc.x+offset,loc.y);
        offset+=b.width;
        break;
    case vertical:
        b.loc = Point(loc.x,loc.y+offset);
        offset+=b.height;
        break;
    }
    selection.push_back(b); // b is NOT OWNED: pass by reference
    return int(selection.size()-1);
}

//------------------------------------------------------------------------------

int Menu::attach(Button* p)
{
    Button& b = *p;
    b.width = width;
    b.height = height;

    switch(k) {
    case horizontal:
        b.loc = Point(loc.x+offset,loc.y);
        offset+=b.width;
        break;
    case vertical:
        b.loc = Point(loc.x,loc.y+offset);
        offset+=b.height;
        break;
    }
    selection.push_back(&b); // b is OWNED: pass by pointer
    return int(selection.size()-1);
}
MyButton::MyButton(int x, int y, int w, int h, Fl_Box *box, namebutton* usrlist[]) :Fl_Box{ x, y, w, h }{
	
	im = box;
	for (int i = 0; i < 8; i++){
		list[i] = usrlist[i];
	}
}


void MyButton::change(){
	//点击事件
	
	this->hide();
	im->hide();

	for (int i = 0; i < 8; i++){//将8个namebutton显示出来
		list[i]->show();
	}
	
	printf("Buton is clicked!\n");

	//W7 w{323,699,"move"};
	//return gui_main();
	
	
}

string namebutton::getTelnum(string name){//通过用户名寻找电话号码
	return usrdata[name];
}
string namebutton::getUsrname(string telnum){//通过电话号码寻找用户名
	for (std::map<string, string>::iterator it = usrdata.begin(); it != usrdata.end(); it++){
		if (it->second == telnum) return it->first;
	}
}
void namebutton::hideusrlist(){
	for (int i = 0; i < 8; i++){
		usrlist[i]->hide();
	}
	returnButton->label("");//把returnButton隐藏
}

W7::W7(int w, int h, const string &t) :Window{ w, h ,t}
{
	p1 = new Button{ Point{ 0, 100 }, 323, 50, "User1", cb_sh };
	p2 = new Button{ Point{ 0, 150 }, 323, 50, "User2", cb_sh };
	p3 = new Button{ Point{ 0, 200 }, 323, 50, "User3", cb_sh };
	p4 = new Button{ Point{ 0, 250 }, 323, 50, "User4", cb_sh };
	p5 = new Button{ Point{ 0, 300 }, 323, 50, "User5", cb_sh };
	p6 = new Button{ Point{ 0, 350 }, 323, 50, "User6", cb_sh };
	p7 = new Button{ Point{ 0, 400 }, 323, 50, "User7", cb_sh };
	p8 = new Button{ Point{ 0, 450 }, 323, 50, "User8", cb_sh };

	attach(*p1);
	attach(*p2);
	attach(*p3);
	attach(*p4);
	attach(*p5);
	attach(*p6);
	attach(*p7);
	attach(*p8);

}
void W7::sh(){
	/*detach(*p1);
	delete p1;
	p1 = new Button{ Point{ 0, 100 }, 323, 50, "User10", cb_sh };
	attach(*p1);*/
	p1->label = "user10";
}

ReturnButton::ReturnButton(int x, int y, int w, int h, Fl_Box *box, Fl_Box *box2, Fl_Box *box3, Fl_Box *box4, Fl_Box *box5, namebutton* usrlist[]) :Fl_Box{ x, y, w, h }{

	im = box;
	btn = box2;
	spe = box3;
	name = box4;
	telnum = box5;
	for (int i = 0; i < 8; i++){
		list[i] = usrlist[i];
	}
}

//------------------------------------------------------------------------------

}; // of namespace Graph_lib
