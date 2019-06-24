
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities
#include "GUI.h"

#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include "Window.h"

#include<fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <map>
#include "json.h"

#define HEIGHT 699
#define WIDTH 323
#define MARGIN 4

using namespace std;

int posInusrinfo = 0;
map<string, string>usrdata;
int imagelayer = 1;//表示的是当前位于第几层，第一层表示主界面，第二层（在第一层下面）表示通讯录和各类图标，第三层表示详细的通讯录信息
//现在改成自定义的按钮了
namebutton *usrlist[8];
ReturnButton *returnButton;

//设置本机的开机密码
string pinNumber = "1122";
string tempNumber = "";
void cb() {}
void but_cb(Fl_Widget* o, void*) {
	Fl_Button* b = (Fl_Button*)o;
	b->label("Good job"); //redraw not necessary

	b->resize(10, 150, 140, 30); //redraw needed
	b->redraw();
}
void callback(void *){
	puts("TICK");
	Fl::repeat_timeout(1.0, callback);
}
int withFltk()
{
	
	Fl_Window     win(WIDTH, HEIGHT);//在Fl_Window的声明和win.show之间就是所有的控件的逻辑

	//Background tel(0, 0, WIDTH, HEIGHT);
	//Fl_PNG_Image  tel_png("C:\\Users\\Wzing\\Desktop\\Files\\courses\\ProgramingAndAlgorithm\\fltk_test\\img\\tel.png");
	//tel.image(tel_png);

	/*Fl_Box *usrlist[10];
	for (int i = 0; i < 10; i++){
		
		usrlist[i] = new Fl_Box(1, 50+50*i, 322, 50, "");
		usrlist[i]->box(FL_UP_BOX);
		//usrlist[i]->labelsize(36);
		usrlist[i]->labelfont(FL_BOLD + FL_ITALIC);
		//usrlist[i]->labeltype(FL_SHADOW_LABEL);
		//usrlist[i]->label(s[i].data());
	}
	map<string, string> ::iterator it = usrdata.begin();
	int cnt = 0;
	while (cnt <= 9 && it != usrdata.end()){
		usrlist[cnt]->label(it->first.data());
		cnt++;
		it++;
	}*/

	
	Fl_Box tongxinlu(0,0,323,50);
	Fl_PNG_Image  tong_png("..\img\tong.png");
	tongxinlu.image(tong_png);


	//表示的是自定义名字
	namebutton *usrlist[10];
	/*for (int i = 0; i < 10; i++){

		usrlist[i] = new namebutton(1, 50 + 50 * i, 322, 50);
		usrlist[i]->box(FL_UP_BOX);
		//usrlist[i]->labelsize(36);
		usrlist[i]->labelfont(FL_BOLD + FL_ITALIC);
		//usrlist[i]->labeltype(FL_SHADOW_LABEL);
		//usrlist[i]->label(s[i].data());
	}*/
	map<string, string> ::iterator it = usrdata.begin();
	int cnt = 0;
	while (cnt <= 9 && it != usrdata.end()){
		usrlist[cnt]->label(it->first.data());
		cnt++;
		it++;
	}



	upbutton upbtn(60, 600, 80, 40, usrlist);
	upbtn.box(FL_UP_BOX);
	upbtn.label("Last page");

	downbutton dwnbtn(180, 600, 80, 40, usrlist);
	dwnbtn.box(FL_UP_BOX);
	dwnbtn.label("Next page");


	Background bg(0, 0, WIDTH, HEIGHT);
	Fl_PNG_Image  bg_png("..\img\bg.png");
	bg.image(bg_png);

	ImageButton        btn(MARGIN, HEIGHT - 64 - MARGIN, 64, 64, &bg);
	Fl_PNG_Image  btn_png("..\img\button\i1.png");
	btn.image(btn_png);

	win.show();
	return(Fl::run());

}

void writeJson(const char *filename){//写json信息
	
	Json::Reader reader;
	Json::Value root;

	ifstream is;
	is.open(filename, std::ios::binary);
	if (reader.parse(is, root)){//现在root是根节点了
		Json::Value arrayobj;//这是二级节点
		arrayobj["id"] = "abm";
		arrayobj["telnum"] = "15650709503";
		root.append(arrayobj);

		arrayobj["id"] = "lyrt";
		arrayobj["telnum"] = "15620309003";
		root.append(arrayobj);

		arrayobj["id"] = "sshh";
		arrayobj["telnum"] = "15610307603";
		root.append(arrayobj);

		arrayobj["id"] = "awlh";
		arrayobj["telnum"] = "15645609680";
		root.append(arrayobj);

		arrayobj["id"] = "ehb";
		arrayobj["telnum"] = "15623709603";
		root.append(arrayobj);

		arrayobj["id"] = "cqqq";
		arrayobj["telnum"] = "15234709248";
		root.append(arrayobj);

		arrayobj["id"] = "rly";
		arrayobj["telnum"] = "15230409212";
		root.append(arrayobj);
	}
	is.close();//关闭读入文件流
	ofstream ofs;
	ofs.open(filename);

	ofs << root.toStyledString();
	ofs.close();

}
void readJson(const char *filename){//读入json信息

	//map<string, string> usr;
	ifstream is(filename, ios::binary);
	if (!is.is_open()){
		cout << "open json file failed" << endl;
		exit(1);
	}
	Json::Reader reader;
	Json::Value arrayobj;
	Json::Value Item;
	if (!reader.parse(is, arrayobj)){
		cout << "读取json格式错误" << endl;
		exit(1);
	}
	for (int i = 0; i < arrayobj.size(); i++){
		string id = arrayobj[i]["id"].asString();
		string telnum = arrayobj[i]["telnum"].asString();
		usrdata[id] = telnum;
	}
	is.close();

}
int main()
{
	
	/*withFltk();*/

	//writeJson("userinfo.json");
	
	
	readJson("userinfo.json");
	
	Simple_window win{ Point{0, 0}, 400, 750, "Mywin"};
	win.begin();

	Background tel(0, 0, WIDTH, HEIGHT);
	Fl_PNG_Image  tel_png("iphonecom.png");
	tel.image(tel_png);


	Fl_Box tongspe(0, 0, 323, 699);
	Fl_PNG_Image  tongspe_png("iphonespe.png");
	tongspe.image(tongspe_png);
	tongspe.hide();

	Fl_Box spe_name(115, 180, 100, 60);
	spe_name.label("NAME");
	spe_name.labelfont(Font::courier_bold);
	spe_name.labelsize(25);
	spe_name.hide();

	Fl_Box spe_num(115, 315, 100, 20);
	spe_num.label("111111111111");
	spe_num.hide();

	usrlist[0] = new namebutton(25, 310, 280, 20, &spe_name, &spe_num, &tongspe);
	usrlist[0]->labelfont(FL_COURIER_BOLD);
	
	usrlist[1] = new namebutton(25, 343, 280, 20, &spe_name, &spe_num, &tongspe);
	usrlist[1]->labelfont(FL_COURIER_BOLD);
	
	usrlist[2] = new namebutton(25, 395, 280, 20, &spe_name, &spe_num, &tongspe);
	usrlist[2]->labelfont(FL_COURIER_BOLD);
	
	usrlist[3] = new namebutton(25, 430, 280, 20, &spe_name, &spe_num, &tongspe);
	usrlist[3]->labelfont(FL_COURIER_BOLD);

	usrlist[4] = new namebutton(25, 460, 280, 20, &spe_name, &spe_num, &tongspe);
	usrlist[4]->labelfont(FL_COURIER_BOLD);

	usrlist[5] = new namebutton(25, 510, 280, 20, &spe_name, &spe_num, &tongspe);
	usrlist[5]->labelfont(FL_COURIER_BOLD);
	
	usrlist[6] = new namebutton(120, 540, 90, 20, &spe_name, &spe_num, &tongspe);
	usrlist[6]->labelfont(FL_COURIER_BOLD);
	usrlist[6]->hide();//之所以把usrlist[6]和usrlist[7]藏起来是因为防止点击通讯录按钮也点击了它们

	usrlist[7] = new namebutton(120, 570, 90, 20, &spe_name, &spe_num, &tongspe);
	usrlist[7]->labelfont(FL_COURIER_BOLD);
	usrlist[7]->hide();

	map<string, string> ::iterator it = usrdata.begin();
	int cnt = 0;
	while (cnt <= 7 && it != usrdata.end()){
		usrlist[cnt]->label(it->first.data());
		cnt++;
		it++;
	}


	Fl_Box bg(0, 0, 323, 699);
	//Fl_PNG_Image  bg_png("C:\\Users\\Wzing\\Desktop\\Files\\courses\\ProgramingAndAlgorithm\\fltk_test\\img\\iphonemain.png");
	Fl_PNG_Image  bg_png("iphonemain.png");
	bg.image(bg_png);

	MyButton        btn(MARGIN + 25, HEIGHT - 170 - MARGIN, 64, 64, &bg, usrlist);

	ReturnButton retBtn(40, 120, 280, 180, &bg, &btn, &tongspe, &spe_name, &spe_num, usrlist);
	//retBtn.label("<--");
	//retBtn.labelfont(FL_COURIER_BOLD);
	returnButton = &retBtn;

	Fl_Box wrong_box(20, 108, 283, 480);
	Fl_PNG_Image  wrong_png("wrong.png");
	wrong_box.image(wrong_png);

	pinButton block_box(20, 108, 283, 480, &wrong_box);
	Fl_PNG_Image  block_png("pinnum.png");
	block_box.image(block_png);
	

	Fl_Box start_box(20, 108, 283, 480);
	Fl_PNG_Image  start_png("start.png");
	start_box.image(start_png);

	Fl_Box blk_box(20, 108, 283, 480);
	Fl_PNG_Image  blk_png("black.png");
	blk_box.image(blk_png);
	
	StartButton startBtn(290, 165, 64, 32, &blk_box, &start_box);
	

	win.end();
	win.show();
	win.wait_for_button();
	

	
}

