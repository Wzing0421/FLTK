
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef GUI_GUARD
#define GUI_GUARD

#include "Window.h"
#include "Graph.h"
#include "json.h"

#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <Windows.h>

#include <FL/Fl_PNG_Image.H>
#include "FL/Fl_Input.H"
extern int posInusrinfo;	
extern map<string, string>usrdata;
extern int imagelayer;
extern string pinNumber;
extern string tempNumber;
namespace Graph_lib {

	

//------------------------------------------------------------------------------

    typedef void* Address;    // Address is a synonym for void*
    typedef void(*Callback)(Address, Address);    // FLTK's required function type for all callbacks

//------------------------------------------------------------------------------

    template<class W> W& reference_to(Address pw)
    // treat an address as a reference to a W
    {
        return *static_cast<W*>(pw);
    }

//------------------------------------------------------------------------------

    class Widget {
    // Widget is a handle to an Fl_widget - it is *not* an Fl_widget
    // We try to keep our interface classes at arm's length from FLTK
    public:
        Widget(Point xy, int w, int h, const string& s, Callback cb)
            : loc(xy), width(w), height(h), label(s), do_it(cb)
        {}

        virtual void move(int dx,int dy) { hide(); pw->position(loc.x+=dx, loc.y+=dy); show(); }
        virtual void hide() { pw->hide(); }
        virtual void show() { pw->show(); }
        virtual void attach(Window&) {};

        void image(Fl_Image *img) { pw->image(img); }

        Point loc;
        int width;
        int height;
        string label;
        Callback do_it;

        virtual ~Widget() { }

    protected:
        Window* own;    // every Widget belongs to a Window
        Fl_Widget* pw;  // connection to the FLTK Widget
    private:
        Widget& operator=(const Widget&); // don't copy Widgets
        Widget(const Widget&);
    };

//------------------------------------------------------------------------------

    struct Button : Widget {
        Button(Point xy, int w, int h, const string& label, Callback cb)
            : Widget(xy,w,h,label,cb)
        {  }

        void attach(Window&);
    };

//------------------------------------------------------------------------------

    struct In_box : Widget {
        In_box(Point xy, int w, int h, const string& s)
            :Widget(xy,w,h,s,0) { }
        int get_int();
        string get_string();

        void attach(Window& win);
    };

//------------------------------------------------------------------------------

    struct Out_box : Widget {
        Out_box(Point xy, int w, int h, const string& s)
            :Widget(xy,w,h,s,0) { }
        void put(int);
        void put(const string&);

        void attach(Window& win);
    };

//------------------------------------------------------------------------------

    struct Menu : Widget {
        enum Kind { horizontal, vertical };
        Menu(Point xy, int w, int h, Kind kk, const string& label)
            : Widget(xy,w,h,label,0), k(kk), offset(0)
        {}

        Vector_ref<Button> selection;
        Kind k;
        int offset;
        int attach(Button& b);      // Menu does not delete &b
        int attach(Button* p);      // Menu deletes p

        void show()                 // show all buttons
        {
            for (unsigned int i = 0; i<selection.size(); ++i)
                selection[i].show();
        }
        void hide()                 // hide all buttons
        {
            for (unsigned int i = 0; i<selection.size(); ++i) 
                selection[i].hide(); 
        }
        void move(int dx, int dy)   // move all buttons
        {
            for (unsigned int i = 0; i<selection.size(); ++i) 
                selection[i].move(dx,dy);
        }

        void attach(Window& win)    // attach all buttons
        {
            for (int i=0; i<selection.size(); ++i) win.attach(selection[i]);
            own = &win;
        }

    };

    class Background : public Fl_Box
    {
    public:
        Background(int x, int y, int w, int h) :
            Fl_Box(x, y, w, h) {  }
    };

    class ImageButton : public Fl_Box
    {
        Fl_Box *bg;
        int handle(int event) {
            switch (event)
            {
			case FL_PUSH: printf("Button clicked.\n");
				bg->hide();
				hide();
				break;
                // printf("Button clicked.\n");
            };
            return 0;
        }
    public:
        ImageButton(int x, int y, int w, int h, Fl_Box* box) :
            Fl_Box(x, y, w, h), bg(box) {  }
    };


	class namebutton :public Fl_Box{//用户信息按钮，需要重载点击函数，实现用户名字和电话号码的切换
	public:

		bool sw;
		string thisname;
		string thisnum;
		Fl_Box *boxname, *boxnum;
		Fl_Box *tong_spe;


		int handle(int event){
			int posy = Fl::event_y();
			int posx = Fl::event_x();
			switch (event)
			{

			case FL_PUSH://点击之后查询map的key返回value,或者查询value返回key
				cout << posx << " " << posy << endl;
				if (sw == true){//如果是名字，则切换成电话号码

						//切换到通讯录详细界面
						imagelayer = 3;
						thisname = this->label();
						thisnum = this->getTelnum(thisname);
						cout << "namebuttonclicked1: " << thisnum << endl;
						boxname->label(thisname.data());
						boxnum->label(thisnum.data());

						tong_spe->show();//通讯录界面消失，露出通讯录详细信息页
						boxname->show();
						boxnum->show();


						hideusrlist();

						//label(this->getTelnum(thisname).c_str());
						//label(thisnum.data());
						//sw = false;
					}
					else{//如果是电话号码，则切换成名字

						thisnum = this->label();
						thisname = this->getUsrname(thisnum);
						cout << "namebuttonclicked2: " << thisname << endl;
						//label(this->getUsrname(thistelnum).c_str());
						label(thisname.data());
						sw = true;
					}

			default:
				break;
			}
			return 0;
		}
		namebutton(int x, int y, int w, int h, Fl_Box *namebox, Fl_Box *numbox, Fl_Box *bg ) :Fl_Box(x, y, w, h), sw{ true }{
			boxname = namebox;
			boxnum = numbox;
			tong_spe = bg;
		}
		//namebutton初定设置就是一个Fl_Box,初始化sw=1表示显示名字，sw=0表示显示电话号码
		string getTelnum(string name);
		string getUsrname(string telnum);
		void hideusrlist();
	};

	class upbutton :public Fl_Box{//上下键按钮
	public:
		namebutton *list[8];
		map<string, string> ::iterator it;
		int handle(int event){
			switch (event)
			{
			case FL_PUSH:
				//your logic
				if (posInusrinfo >= 1){//如果不是第一页
					it = usrdata.begin();
					for (int i = 0; i < 8 * (posInusrinfo - 1); i++) it++;//定位到上一页的第一个位置

					int cnt = 0;
					while (cnt <= 7 && it != usrdata.end()){
						list[cnt]->label(it->first.data());//改名字
						list[cnt]->sw = true;
						it++;
						cnt++;
					}
					//for (int last = 9; last > cnt; last--) list[last]->label("");//这里不需要这句话因为上一页肯定是满的
					posInusrinfo--;
				}
				cout << posInusrinfo << endl;
				break;
			default:
				break;
			}
			return 0;
		}

		upbutton(int x, int y, int w, int h, namebutton* usrlist[]) :Fl_Box(x, y, w, h) {
			for (int i = 0; i < 8; i++){
				list[i] = usrlist[i];
			}
			cout << "----------------" << endl;
			map<string, string> ::iterator it;
			for (it = usrdata.begin(); it != usrdata.end(); it++){
				cout << it->first << ' ' << it->second << endl;
			}
			cout << "----------------" << endl;
		}

	};

	class downbutton : public Fl_Box{
		
	public:
		namebutton *list[8];
		map<string, string> ::iterator it;
		int handle(int event){
			switch (event)
			{
			case FL_PUSH:
				//your logic
				if (8 * (posInusrinfo + 1) < usrdata.size()){//如果下一页还有用户
					it = usrdata.begin();
					for (int i = 0; i < 8 * (posInusrinfo + 1); i++) it++;//定位到下一页的第一个位置

					int cnt = 0;
					while (cnt <= 7 && it != usrdata.end()){
						list[cnt]->label(it->first.data());//改名字
						list[cnt]->sw = true;
						it++;
						cnt++;
					}
					for (int last = 7; last > cnt; last--){
						list[last]->label("");//把空余部分设置为空
						list[cnt]->sw = true;
					} 
					posInusrinfo++;
				}
				cout << posInusrinfo << endl;
				break;
			default:
				break;
			}
			return 0;
		}

		downbutton(int x, int y, int w, int h, namebutton* usrlist[]) :Fl_Box(x, y, w, h) {
			for (int i = 0; i < 8; i++){
				list[i] = usrlist[i];
			}
		}
	};

	class W7 : public Window{
	public:
		W7(int w, int h, const string &t);
		Button *p1;
		Button *p2;
		Button *p3;
		Button *p4;
		Button *p5;
		Button *p6;
		Button *p7;
		Button *p8;

		void sh();
		static void cb_sh(Address, Address addr){
			reference_to < W7 >(addr).sh();
		}
	};


	/*
	我准备在Mybutton和w7这两个类上面实现主要的功能：
	MyButton类实现的是加载图片，然后点击通讯录按钮就转换到通讯录界面；
	window按钮实现的功能是：通讯录界面的显示，以及上面的按钮点击之后的响应
	*/
	class MyButton : public Fl_Box{
	public:
		Fl_Box *im;
		namebutton *list[8];
		W7 *usr;
		int getkeyborad;
		//MyButton(int x, int y, int w, int h, Fl_Box *box):Fl_Box(x, y, w, h), im(box) {  }//构造函数
		MyButton(int x, int y, int w, int h, Fl_Box *box, namebutton* usrlist[]);//构造函数
		int handle(int event){//重载了点击事件
			switch (event){
			case FL_PUSH:
				imagelayer = 2;//表示现在进入了通讯录和图标界面
				change();
				break;
			case FL_MOUSEWHEEL:
				
				if (Fl::event_dy() > 0){//向下滑动
					cout << "fuckdown" << endl;
				}
				else//向上滑动
				{
					cout << "fuckup" << endl;
				}	

				break;
			default:
				break;
			}
			return 0;
		}
		void change();
		/*static void cb_change(Address, Address addr){
			reference_to <MyButton>(addr).change();
		}*/
	};

	class ReturnButton : public Fl_Box{//这是通讯录返回按钮
	public:
		Fl_Box *im;//这是给主界面main的
		Fl_Box *btn;//这是给通讯录图标按钮的
		Fl_Box *spe;

		Fl_Box *name;
		Fl_Box *telnum;
		namebutton *list[8];
		map<string, string> ::iterator it;
		int nowPos = 0;

		//MyButton(int x, int y, int w, int h, Fl_Box *box):Fl_Box(x, y, w, h), im(box) {  }//构造函数
		ReturnButton(int x, int y, int w, int h, Fl_Box *box, Fl_Box *box2, Fl_Box *box3, Fl_Box *box4, Fl_Box *box5, namebutton* usrlist[]);//构造函数

		int handle(int event){//重载了点击事件
			int posx = Fl::event_x();
			switch (event){
			
			case FL_PUSH:
				if (posx <= 180){
					

					if (imagelayer == 3){
						//是详细通讯录界面，那么应该回到的是通讯录界面
						imagelayer--;
						for (int i = 0; i < 8; i++){//显示姓名按钮
							list[i]->show();
						}
						//详细通讯录界面消失
						spe->hide();
						//把姓名和电话号码的box消失
						name->hide();
						telnum->hide();
						this->label("<--");

					}
					else if (imagelayer == 2){
						//是通讯录界面,那么应该回到主界面
						//这个应该做的是将main界面和通讯录按钮显示
						imagelayer--;
						im->show();
						btn->show();
						cout << "return btn clicked!" << endl;
					}
					break;
				
				}
			case FL_DRAG:
				
					if (nowPos + 9 <= usrdata.size()){//这里为什么是9不是8是因为有时候滚轮一下子滑下了两位就容易出错
						nowPos++;
						//显示8个信息
						it = usrdata.begin();
						for (int t = 0; t < nowPos; t++){
							it++;
							if (it == usrdata.end()) break;
						}
						cout << it->first << endl;
						for (int t = 0; t < 8; t++){
							list[t]->label(it->first.data());
							it++;
						}
					}
				
				break;
			case FL_MOUSEWHEEL:
				if (Fl::event_dy() > 0){//向下滑动
					if (nowPos + 9 <= usrdata.size()){//这里为什么是9不是8是因为有时候滚轮一下子滑下了两位就容易出错
						nowPos++;
						//显示8个信息
						it = usrdata.begin();
						for (int t = 0; t < nowPos; t++){
							it++;
							if (it == usrdata.end()) break;
						}
						cout << it->first << endl;
						for (int t = 0; t < 8; t++){
							list[t]->label(it->first.data());
							it++;
						}
					}
				}
				else//向上滑动
				{
					if (nowPos >= 1){
						nowPos--;
						it = usrdata.begin();
						for (int t = 0; t < nowPos; t++){
							it++;
						}
						
						for (int t = 0; t < 8; t++){
							list[t]->label(it->first.data());
							it++;
						}
					}
				}

				break;
			default:
				break;
			}
			return 0;
		}
	};

	//密码界面
	class pinButton : public Fl_Box{
	public:
		Fl_Box *im;
		pinButton(int x, int y, int w, int h, Fl_Box *wr) :Fl_Box(x, y, w, h){ im = wr; }
		int handle(int event){
			int bias = 50;
			int PosX, PosY;
			switch (event)
			{
			case FL_PUSH:
				
				PosX = Fl::event_x();
				PosY = Fl::event_y();
				
				//按钮1
				if (PosX >= 58 && PosX <= 58 + bias && PosY >= 257 && PosY <= 257 + bias){
					tempNumber += '1';
					judge(tempNumber);
				}//按钮2
				else if (PosX >= 135 && PosX <= 135 + bias && PosY >= 257 && PosY <= 257 + bias){
					tempNumber += '2';
					judge(tempNumber);
				}//按钮3
				else if (PosX >= 216 && PosX <= 216 + bias && PosY >= 257 && PosY <= 257 + bias){
					tempNumber += '3';
					judge(tempNumber);
				}//按钮4
				else if (PosX >= 58 && PosX <= 58 + bias && PosY >= 322 && PosY <= 322 + bias){
					tempNumber += '4';
					judge(tempNumber);
				}//按钮5
				else if (PosX >= 135 && PosX <= 135 + bias && PosY >= 322 && PosY <= 322 + bias){
					tempNumber += '5';
					judge(tempNumber);
				}//按钮6
				else if (PosX >= 216 && PosX <= 216 + bias && PosY >= 322 && PosY <= 322 + bias){
					tempNumber += '6';
					judge(tempNumber);
				}//按钮7
				else if (PosX >= 58 && PosX <= 58 + bias && PosY >= 387 && PosY <= 387 + bias){
					tempNumber += '7';
					judge(tempNumber);
				}//按钮8
				else if (PosX >= 135 && PosX <= 135 + bias && PosY >= 387 && PosY <= 387 + bias){
					tempNumber += '8';
					judge(tempNumber);
				}//按钮9
				else if (PosX >= 216 && PosX <= 216 + bias && PosY >= 387 && PosY <= 387 + bias){
					tempNumber += '9';
					judge(tempNumber);
				}//按钮0
				else if (PosX >= 135 && PosX <= 135 + bias && PosY >= 454 && PosY <= 454 + bias){
					tempNumber += '0';
					judge(tempNumber);
				}
				break;
			default:
				break;
			}
			return 0;
		}
		void judge(string &num){
			if (num.length() <= 3) return;//小于3就不管了
			else{
				if (num == pinNumber){//密码正确
					num = "";
					this->hide();
					im->hide(); //把错误的也删掉
				}
				else{
					num = "";
					this->hide();
					Fl::flush();
					Sleep(1500);
					this->show();
				}
			}
		}
	};
	class StartButton : public Fl_Box{
	public:
		Fl_Box *im1;
		Fl_Box *im2;
		int cntnum = 0;
		StartButton(int x, int y, int w, int h, Fl_Box *box1, Fl_Box *box2) :Fl_Box(x, y, w, h), im1(box1),im2(box2) {  }//构造函数
		//StartButton(int x, int y, int w, int h, Fl_Box *box);//构造函数
		int handle(int event){//重载了点击事件
			switch (event){
			case FL_PUSH:
				im1->hide();
				Fl::flush();
				Sleep(3000);
				im2->hide();
				break;
			default:
				break;
			}
			return 0;
		}
		
	};
	
//------------------------------------------------------------------------------

} // of namespace Graph_lib

#endif // GUI_GUARD
