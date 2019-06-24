
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


	class namebutton :public Fl_Box{//�û���Ϣ��ť����Ҫ���ص��������ʵ���û����ֺ͵绰������л�
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

			case FL_PUSH://���֮���ѯmap��key����value,���߲�ѯvalue����key
				cout << posx << " " << posy << endl;
				if (sw == true){//��������֣����л��ɵ绰����

						//�л���ͨѶ¼��ϸ����
						imagelayer = 3;
						thisname = this->label();
						thisnum = this->getTelnum(thisname);
						cout << "namebuttonclicked1: " << thisnum << endl;
						boxname->label(thisname.data());
						boxnum->label(thisnum.data());

						tong_spe->show();//ͨѶ¼������ʧ��¶��ͨѶ¼��ϸ��Ϣҳ
						boxname->show();
						boxnum->show();


						hideusrlist();

						//label(this->getTelnum(thisname).c_str());
						//label(thisnum.data());
						//sw = false;
					}
					else{//����ǵ绰���룬���л�������

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
		//namebutton�������þ���һ��Fl_Box,��ʼ��sw=1��ʾ��ʾ���֣�sw=0��ʾ��ʾ�绰����
		string getTelnum(string name);
		string getUsrname(string telnum);
		void hideusrlist();
	};

	class upbutton :public Fl_Box{//���¼���ť
	public:
		namebutton *list[8];
		map<string, string> ::iterator it;
		int handle(int event){
			switch (event)
			{
			case FL_PUSH:
				//your logic
				if (posInusrinfo >= 1){//������ǵ�һҳ
					it = usrdata.begin();
					for (int i = 0; i < 8 * (posInusrinfo - 1); i++) it++;//��λ����һҳ�ĵ�һ��λ��

					int cnt = 0;
					while (cnt <= 7 && it != usrdata.end()){
						list[cnt]->label(it->first.data());//������
						list[cnt]->sw = true;
						it++;
						cnt++;
					}
					//for (int last = 9; last > cnt; last--) list[last]->label("");//���ﲻ��Ҫ��仰��Ϊ��һҳ�϶�������
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
				if (8 * (posInusrinfo + 1) < usrdata.size()){//�����һҳ�����û�
					it = usrdata.begin();
					for (int i = 0; i < 8 * (posInusrinfo + 1); i++) it++;//��λ����һҳ�ĵ�һ��λ��

					int cnt = 0;
					while (cnt <= 7 && it != usrdata.end()){
						list[cnt]->label(it->first.data());//������
						list[cnt]->sw = true;
						it++;
						cnt++;
					}
					for (int last = 7; last > cnt; last--){
						list[last]->label("");//�ѿ��ಿ������Ϊ��
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
	��׼����Mybutton��w7������������ʵ����Ҫ�Ĺ��ܣ�
	MyButton��ʵ�ֵ��Ǽ���ͼƬ��Ȼ����ͨѶ¼��ť��ת����ͨѶ¼���棻
	window��ťʵ�ֵĹ����ǣ�ͨѶ¼�������ʾ���Լ�����İ�ť���֮�����Ӧ
	*/
	class MyButton : public Fl_Box{
	public:
		Fl_Box *im;
		namebutton *list[8];
		W7 *usr;
		int getkeyborad;
		//MyButton(int x, int y, int w, int h, Fl_Box *box):Fl_Box(x, y, w, h), im(box) {  }//���캯��
		MyButton(int x, int y, int w, int h, Fl_Box *box, namebutton* usrlist[]);//���캯��
		int handle(int event){//�����˵���¼�
			switch (event){
			case FL_PUSH:
				imagelayer = 2;//��ʾ���ڽ�����ͨѶ¼��ͼ�����
				change();
				break;
			case FL_MOUSEWHEEL:
				
				if (Fl::event_dy() > 0){//���»���
					cout << "fuckdown" << endl;
				}
				else//���ϻ���
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

	class ReturnButton : public Fl_Box{//����ͨѶ¼���ذ�ť
	public:
		Fl_Box *im;//���Ǹ�������main��
		Fl_Box *btn;//���Ǹ�ͨѶ¼ͼ�갴ť��
		Fl_Box *spe;

		Fl_Box *name;
		Fl_Box *telnum;
		namebutton *list[8];
		map<string, string> ::iterator it;
		int nowPos = 0;

		//MyButton(int x, int y, int w, int h, Fl_Box *box):Fl_Box(x, y, w, h), im(box) {  }//���캯��
		ReturnButton(int x, int y, int w, int h, Fl_Box *box, Fl_Box *box2, Fl_Box *box3, Fl_Box *box4, Fl_Box *box5, namebutton* usrlist[]);//���캯��

		int handle(int event){//�����˵���¼�
			int posx = Fl::event_x();
			switch (event){
			
			case FL_PUSH:
				if (posx <= 180){
					

					if (imagelayer == 3){
						//����ϸͨѶ¼���棬��ôӦ�ûص�����ͨѶ¼����
						imagelayer--;
						for (int i = 0; i < 8; i++){//��ʾ������ť
							list[i]->show();
						}
						//��ϸͨѶ¼������ʧ
						spe->hide();
						//�������͵绰�����box��ʧ
						name->hide();
						telnum->hide();
						this->label("<--");

					}
					else if (imagelayer == 2){
						//��ͨѶ¼����,��ôӦ�ûص�������
						//���Ӧ�������ǽ�main�����ͨѶ¼��ť��ʾ
						imagelayer--;
						im->show();
						btn->show();
						cout << "return btn clicked!" << endl;
					}
					break;
				
				}
			case FL_DRAG:
				
					if (nowPos + 9 <= usrdata.size()){//����Ϊʲô��9����8����Ϊ��ʱ�����һ���ӻ�������λ�����׳���
						nowPos++;
						//��ʾ8����Ϣ
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
				if (Fl::event_dy() > 0){//���»���
					if (nowPos + 9 <= usrdata.size()){//����Ϊʲô��9����8����Ϊ��ʱ�����һ���ӻ�������λ�����׳���
						nowPos++;
						//��ʾ8����Ϣ
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
				else//���ϻ���
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

	//�������
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
				
				//��ť1
				if (PosX >= 58 && PosX <= 58 + bias && PosY >= 257 && PosY <= 257 + bias){
					tempNumber += '1';
					judge(tempNumber);
				}//��ť2
				else if (PosX >= 135 && PosX <= 135 + bias && PosY >= 257 && PosY <= 257 + bias){
					tempNumber += '2';
					judge(tempNumber);
				}//��ť3
				else if (PosX >= 216 && PosX <= 216 + bias && PosY >= 257 && PosY <= 257 + bias){
					tempNumber += '3';
					judge(tempNumber);
				}//��ť4
				else if (PosX >= 58 && PosX <= 58 + bias && PosY >= 322 && PosY <= 322 + bias){
					tempNumber += '4';
					judge(tempNumber);
				}//��ť5
				else if (PosX >= 135 && PosX <= 135 + bias && PosY >= 322 && PosY <= 322 + bias){
					tempNumber += '5';
					judge(tempNumber);
				}//��ť6
				else if (PosX >= 216 && PosX <= 216 + bias && PosY >= 322 && PosY <= 322 + bias){
					tempNumber += '6';
					judge(tempNumber);
				}//��ť7
				else if (PosX >= 58 && PosX <= 58 + bias && PosY >= 387 && PosY <= 387 + bias){
					tempNumber += '7';
					judge(tempNumber);
				}//��ť8
				else if (PosX >= 135 && PosX <= 135 + bias && PosY >= 387 && PosY <= 387 + bias){
					tempNumber += '8';
					judge(tempNumber);
				}//��ť9
				else if (PosX >= 216 && PosX <= 216 + bias && PosY >= 387 && PosY <= 387 + bias){
					tempNumber += '9';
					judge(tempNumber);
				}//��ť0
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
			if (num.length() <= 3) return;//С��3�Ͳ�����
			else{
				if (num == pinNumber){//������ȷ
					num = "";
					this->hide();
					im->hide(); //�Ѵ����Ҳɾ��
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
		StartButton(int x, int y, int w, int h, Fl_Box *box1, Fl_Box *box2) :Fl_Box(x, y, w, h), im1(box1),im2(box2) {  }//���캯��
		//StartButton(int x, int y, int w, int h, Fl_Box *box);//���캯��
		int handle(int event){//�����˵���¼�
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
