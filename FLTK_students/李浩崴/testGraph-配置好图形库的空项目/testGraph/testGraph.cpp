#pragma warning( disable : 4996 )
#include <iostream>
#include "Simple_window.h"
#include "Graph.h"
#include "time.h"
#include "stdio.h"
#include <sstream>
#include "pch.h"
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include<Windows.h>
#pragma comment(lib,"winmm.lib")
using namespace Graph_lib;

struct Phone_startpage : Window
{
	Phone_startpage(Point xy, int w, int h, const string& title);
private:
	//declare...................................................................................................................
	//startpage--------------------------------------------------------------------------------------------------------------------------
	int pointer;
	Image frame; Image lockscreen;
	Image b0; Image b00; Image b1; Image b2; Image b3; Image b4; Image b5; Image b6; Image b7; Image b8; Image b9; Image b10;
	Image b11; Image b12; Image b13; Image b14; Image b15; Image b16; Image b17; Image b18; Image b19; Image b20; Image b21; Image b22;
	Image b23; Image b24; Image b25; Image b26; Image b27; Image b28; Image b29; Image b30; Image b31; Image b32; Image b33;
	static void callback0(void*); static void callback1(void*); static void callback2(void*); static void callback3(void*);
	static void callback4(void*); static void callback5(void*); static void callback6(void*); static void callback7(void*);
	static void callback8(void*); static void callback9(void*); static void callback10(void*); static void callback11(void*);
	static void callback12(void*); static void callback13(void*); static void callback14(void*); static void callback15(void*);
	static void callback16(void*); static void callback17(void*); static void callback18(void*); static void callback19(void*);
	static void callback20(void*); static void callback21(void*); static void callback22(void*); static void callback23(void*);
	static void callback24(void*); static void callback25(void*); static void callback26(void*); static void callback27(void*);
	static void callback28(void*); static void callback29(void*); static void callback30(void*); static void callback31(void*);
	static void callback32(void*); static void callback33(void*); static void callback34(void*);
	//lockscreen--------------------------------------------------------------------------------------------------------------------------
	Image lockscreen1; Text times; Text date; Text pw; Text hint; string code; string code2; Button get_pw; Button back_pw;
	Button bb1; Button bb2; Button bb3; Button bb4; Button bb5; Button bb6; Button bb7; Button bb8; Button bb9; Button bb0;
	Button deleter; Button viewpw; Button enter; int type; int localmin1; int localmin2; int localmin3;
	void getpw();
	void backpw();
	void num1(); void num2(); void num3(); void num4(); void num5(); void num6(); void num7(); void num8(); void num9(); void num0();
	void del();	void vpw(); void Enter();
	static void callbackt(void*); static void callbackblack(void*);
	static void cb_getpw(Address, Address window); static void cb_backpw(Address, Address window);
	static void cb_Enter(Address, Address window);
	static void cb_num1(Address, Address window); static void cb_num2(Address, Address window); static void cb_num3(Address, Address window);
	static void cb_num4(Address, Address window); static void cb_num5(Address, Address window); static void cb_num6(Address, Address window);
	static void cb_num7(Address, Address window); static void cb_num8(Address, Address window); static void cb_num9(Address, Address window);
	static void cb_num0(Address, Address window);	static void cb_del(Address, Address window); static void cb_vpw(Address, Address window);
	//mainpage-----------------------------------------------------------------------------------------------------------------------
	Image mainpage;
	Button lock; Button black; Button to_contact;
	static void cb_tocontact(Address, Address window); static void cb_tolock(Address, Address window);
	static void cb_blacktolock(Address, Address window);
	void tolock(); void tocontact(); void blacktolock();
	Text mtimes; Text timeup; Text mdate; Text location;
	static void callbackmt(void*); static void callbackup(void*);
	//contact------------------------------------------------------------------------------------------------------------------------
	Image contact1;	Image contact2; Image contact3; Image detail; string contrast;
	Button home; Button nextpg; Button previouspg; Button nextpg1; Button previouspg1; Button searcher; Button details;
	In_box search; Text showsearch; Button re_detail; Button song;
	static void cb_homer(Address, Address window);	void homer();
	static void cb_next(Address, Address window);	void next();
	static void cb_previous(Address, Address window);	void previous();
	static void cb_next1(Address, Address window);	void next1();
	static void cb_previous1(Address, Address window);	void previous1();
	static void cb_srch(Address, Address window);	void srch();
	static void cb_detailer(Address, Address window);	void detailer();
	static void cb_retail(Address, Address window);	void retail();
	static void cb_sing(Address, Address window);	void sing();
	static void callbackshow(void*);
};
Phone_startpage::Phone_startpage(Point xy, int w, int h, const string& title)
	:Window(xy, w, h, title),
	//defination...................................................................................................................
	//startpage--------------------------------------------------------------------------------------------------------------------
	frame(Point(100, 50), "frame.jpg"), b0(Point(153, 130), "blackout.jpg"), b00(Point(153, 130), "logo.jpg"), b1(Point(153, 130), "b1.jpg"),
	b2(Point(153, 130), "b2.jpg"), b3(Point(153, 130), "b3.jpg"), b4(Point(153, 130), "b4.jpg"), b5(Point(153, 130), "b5.jpg"),
	b6(Point(153, 130), "b6.jpg"), b7(Point(153, 130), "b7.jpg"), b8(Point(153, 130), "b8.jpg"), b9(Point(153, 130), "b9.jpg"),
	b10(Point(153, 130), "b10.jpg"), b11(Point(153, 130), "b11.jpg"), b12(Point(153, 130), "b12.jpg"), b13(Point(153, 130), "b13.jpg"),
	b14(Point(153, 130), "b14.jpg"), b15(Point(153, 130), "b15.jpg"), b16(Point(153, 130), "b16.jpg"), b17(Point(153, 130), "b17.jpg"),
	b18(Point(153, 130), "b18.jpg"), b19(Point(153, 130), "b19.jpg"), b20(Point(153, 130), "b20.jpg"), b21(Point(153, 130), "b21.jpg"),
	b22(Point(153, 130), "b22.jpg"), b23(Point(153, 130), "b23.jpg"), b24(Point(153, 130), "b24.jpg"), b25(Point(153, 130), "b25.jpg"),
	b26(Point(153, 130), "b26.jpg"), b27(Point(153, 130), "b27.jpg"), b28(Point(153, 130), "b28.jpg"), b29(Point(153, 130), "b29.jpg"),
	b30(Point(153, 130), "b30.jpg"), b31(Point(153, 130), "b31.jpg"), b32(Point(153, 130), "b32.jpg"), b33(Point(153, 130), "b33.jpg"),
	//lockscreen---------------------------------------------------------------------------------------------------------------------
	lockscreen(Point(153, 130), "lockscreen.jpg"), lockscreen1(Point(153, 130), "lockscreen1.jpg"),
	times(Point(245, 210), " "), date(Point(263, 245), " "), pw(Point(260, 315), " "), hint(Point(225, 235), "Incorrect PIN"),
	get_pw(Point(253, 320), 107, 200, " ", cb_getpw),
	back_pw(Point(153, 145), 309, 110, " ", cb_backpw),
	bb1(Point(153, 395), 103, 62, " ", cb_num1), bb2(Point(256, 395), 103, 62, " ", cb_num2), bb3(Point(359, 395), 103, 62, " ", cb_num3),
	bb4(Point(153, 457), 103, 62, " ", cb_num4), bb5(Point(256, 457), 103, 62, " ", cb_num5), bb6(Point(359, 457), 103, 62, " ", cb_num6),
	bb7(Point(153, 519), 103, 62, " ", cb_num7), bb8(Point(256, 519), 103, 62, " ", cb_num8), bb9(Point(359, 519), 103, 62, " ", cb_num9),
	bb0(Point(256, 581), 103, 62, " ", cb_num0), deleter(Point(359, 581), 103, 62, " ", cb_del), viewpw(Point(400, 300), 30, 28, " ", cb_vpw),
	enter(Point(153, 581), 103, 62, " ", cb_Enter),
	//mainpage-----------------------------------------------------------------------------------------------------------------------
	mainpage(Point(153, 130), "mainpage1.jpg"),
	to_contact(Point(260, 606), 27, 27, " ", cb_tocontact), lock(Point(470, 330), 10, 33, " ", cb_tolock),
	black(Point(470, 330), 10, 33, " ", cb_blacktolock),
	mtimes(Point(173, 190), " "), mdate(Point(173, 212), " "), location(Point(314, 190), "Beijing"), timeup(Point(410, 144), " "),
	//contact------------------------------------------------------------------------------------------------------------------------
	contact1(Point(153, 130), "contactlist3.jpg"), contact2(Point(153, 130), "contactlist4.jpg"), contact3(Point(153, 130), "contactlist5.jpg"),
	home(Point(270, 700), 70, 33, " ", cb_homer),
	nextpg(Point(383, 583), 42, 42, " ", cb_next), previouspg(Point(383, 230), 42, 42, " ", cb_previous),
	nextpg1(Point(383, 583), 42, 42, " ", cb_next1), previouspg1(Point(383, 230), 42, 42, " ", cb_previous1),
	search(Point(200, 188), 260, 26, " "), searcher(Point(178, 188), 22, 26, " ", cb_srch), showsearch(Point(208, 210), " "),
	detail(Point(153, 130), "detail1.jpg"), details(Point(180, 420), 249, 40, " ", cb_detailer),
	re_detail(Point(183, 159), 15, 15, " ", cb_retail), song(Point(180, 440), 249, 58, " ", cb_sing)
{
	//initialize...................................................................................................................
	//startpage----------------------------------------------------------------------------------------------------------------------
	attach(frame);
	attach(b0);
	Fl::add_timeout(2, callback0, (void*)this);
	Fl::add_timeout(5, callback1, (void*)this);
	Fl::add_timeout(5.1, callback2, (void*)this);
	Fl::add_timeout(5.2, callback3, (void*)this);
	Fl::add_timeout(5.3, callback4, (void*)this);
	Fl::add_timeout(5.4, callback5, (void*)this);
	Fl::add_timeout(5.5, callback6, (void*)this);
	Fl::add_timeout(5.6, callback7, (void*)this);
	Fl::add_timeout(5.7, callback8, (void*)this);
	Fl::add_timeout(5.8, callback9, (void*)this);
	Fl::add_timeout(5.9, callback10, (void*)this);
	Fl::add_timeout(6.0, callback11, (void*)this);
	Fl::add_timeout(6.1, callback12, (void*)this);
	Fl::add_timeout(6.2, callback13, (void*)this);
	Fl::add_timeout(6.3, callback14, (void*)this);
	Fl::add_timeout(6.4, callback15, (void*)this);
	Fl::add_timeout(6.5, callback16, (void*)this);
	Fl::add_timeout(6.6, callback17, (void*)this);
	Fl::add_timeout(6.8, callback18, (void*)this);
	Fl::add_timeout(6.9, callback19, (void*)this);
	Fl::add_timeout(7.0, callback20, (void*)this);
	Fl::add_timeout(7.2, callback21, (void*)this);
	Fl::add_timeout(7.5, callback22, (void*)this);
	Fl::add_timeout(7.7, callback23, (void*)this);
	Fl::add_timeout(7.9, callback24, (void*)this);
	Fl::add_timeout(8.1, callback25, (void*)this);
	Fl::add_timeout(8.3, callback26, (void*)this);
	Fl::add_timeout(8.5, callback27, (void*)this);
	Fl::add_timeout(8.7, callback28, (void*)this);
	Fl::add_timeout(8.9, callback29, (void*)this);
	Fl::add_timeout(9.7, callback30, (void*)this);
	Fl::add_timeout(9.8, callback31, (void*)this);
	Fl::add_timeout(9.9, callback32, (void*)this);
	Fl::add_timeout(10.0, callback33, (void*)this);
	Fl::add_timeout(10.3, callback30, (void*)this);
	Fl::add_timeout(10.4, callback31, (void*)this);
	Fl::add_timeout(10.5, callback32, (void*)this);
	Fl::add_timeout(10.6, callback33, (void*)this);
	Fl::add_timeout(10.9, callback30, (void*)this);
	Fl::add_timeout(11.0, callback31, (void*)this);
	Fl::add_timeout(11.1, callback32, (void*)this);
	Fl::add_timeout(11.2, callback33, (void*)this);
	Fl::add_timeout(11.5, callback34, (void*)this);
	Fl::add_timeout(11.5, callbackt, (void*)this);
	Fl::add_timeout(20, callbackblack, (void*)this);
	pointer = 0; type = 0;
	//lockscreen-----------------------------------------------------------------------------------------------
	localmin1 = 0; localmin2 = 0; localmin3 = 0;
	times.set_font_size(50); times.set_color(Color::red); times.set_font(Font::helvetica_bold);
	date.set_font_size(18); date.set_color(Color::blue); date.set_font(Font::helvetica);
	pw.set_font_size(20); pw.set_color(Color::white); pw.set_font(Font::helvetica);
	hint.set_font_size(30); hint.set_color(Color::white); hint.set_font(Font::helvetica);
	timeup.set_font_size(10); timeup.set_color(Color::white); timeup.set_font(Font::times);
	//mainpage-------------------------------------------------------------------------------------------------
	mtimes.set_font_size(45); mtimes.set_color(Color::white); mtimes.set_font(Font::courier);
	mdate.set_font_size(15); mdate.set_color(Color::white); mdate.set_font(Font::courier);
	location.set_font_size(10); location.set_color(Color::white); location.set_font(Font::courier);
	//contact--------------------------------------------------------------------------------------------------
	showsearch.set_font_size(18); showsearch.set_color(Color::white); showsearch.set_font(Font::courier);
}
//timeout event&&button reference....................................................................................................................
//startpage-------------------------------------------------------------------------------------------------------------------------
void Phone_startpage::callback0(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b00); x->redraw(); x->detach(x->b0); }
void Phone_startpage::callback1(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b1); x->redraw(); x->detach(x->b00); }
void Phone_startpage::callback2(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b2); x->redraw(); x->detach(x->b1); }
void Phone_startpage::callback3(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b3); x->redraw(); x->detach(x->b2); }
void Phone_startpage::callback4(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b4); x->redraw(); x->detach(x->b3); }
void Phone_startpage::callback5(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b5); x->redraw(); x->detach(x->b4); }
void Phone_startpage::callback6(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b6); x->redraw(); x->detach(x->b5); }
void Phone_startpage::callback7(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b7); x->redraw(); x->detach(x->b6); }
void Phone_startpage::callback8(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b8); x->redraw(); x->detach(x->b7); }
void Phone_startpage::callback9(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b9); x->redraw(); x->detach(x->b8); }
void Phone_startpage::callback10(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b10); x->redraw(); x->detach(x->b9); }
void Phone_startpage::callback11(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b11); x->redraw(); x->detach(x->b10); }
void Phone_startpage::callback12(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b12); x->redraw(); x->detach(x->b11); }
void Phone_startpage::callback13(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b13); x->redraw(); x->detach(x->b12); }
void Phone_startpage::callback14(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b14); x->redraw(); x->detach(x->b13); }
void Phone_startpage::callback15(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b15); x->redraw(); x->detach(x->b14); }
void Phone_startpage::callback16(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b16); x->redraw(); x->detach(x->b15); }
void Phone_startpage::callback17(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b17); x->redraw(); x->detach(x->b16); }
void Phone_startpage::callback18(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b18); x->redraw(); x->detach(x->b17); }
void Phone_startpage::callback19(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b19); x->redraw(); x->detach(x->b18); }
void Phone_startpage::callback20(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b20); x->redraw(); x->detach(x->b19); }
void Phone_startpage::callback21(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b21); x->redraw(); x->detach(x->b20); }
void Phone_startpage::callback22(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b22); x->redraw(); x->detach(x->b21); }
void Phone_startpage::callback23(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b23); x->redraw(); x->detach(x->b22); }
void Phone_startpage::callback24(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b24); x->redraw(); x->detach(x->b23); }
void Phone_startpage::callback25(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b25); x->redraw(); x->detach(x->b24); }
void Phone_startpage::callback26(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b26); x->redraw(); x->detach(x->b25); }
void Phone_startpage::callback27(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b27); x->redraw(); x->detach(x->b26); }
void Phone_startpage::callback28(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b28); x->redraw(); x->detach(x->b27); }
void Phone_startpage::callback29(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b29); x->redraw(); x->detach(x->b28); }
void Phone_startpage::callback30(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b30); x->redraw(); x->detach(x->b29); }
void Phone_startpage::callback31(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b31); x->redraw(); x->detach(x->b30); }
void Phone_startpage::callback32(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b32); x->redraw(); x->detach(x->b31); }
void Phone_startpage::callback33(void*xx) { Phone_startpage *x = (Phone_startpage*)xx; x->attach(x->b33); x->redraw(); x->detach(x->b32); }
void Phone_startpage::callback34(void*xx)
{
	Phone_startpage *x = (Phone_startpage*)xx;
	x->attach(x->lockscreen); x->attach(x->get_pw); x->attach(x->lock); x->redraw(); x->detach(x->b33);
	mciSendString(TEXT("open start.wav alias mysong"), NULL, 0, NULL);//开机音乐
	mciSendString(TEXT("play mysong wait"), NULL, 0, NULL);
	mciSendString(TEXT("close mysong"), NULL, 0, NULL);
}
//lockscreen--------------------------------------------------------------------------------------------------------------------------
void Phone_startpage::callbackt(void*xx)//锁屏展示时间日期的timeout
{
	Phone_startpage *x = (Phone_startpage*)xx; struct tm *local; time_t t; t = time(NULL); local = localtime(&t);
	stringstream read_time;
	if (local->tm_hour < 10)
	{
		if (local->tm_min < 10)
			read_time << '0' << local->tm_hour << ":0" << local->tm_min;
		else
			read_time << '0' << local->tm_hour << ':' << local->tm_min;
	}
	else
	{
		if (local->tm_min < 10)
			read_time << local->tm_hour << ":0" << local->tm_min;
		else
			read_time << local->tm_hour << ':' << local->tm_min;
	}
	x->times.set_label(read_time.str()); read_time.str(""); x->attach(x->times);
	struct tm *ptr; time_t lt; char str[80] = { '\0' }; lt = time(NULL); ptr = localtime(&lt);
	strftime(str, 100, "%a, %b %d", ptr);
	x->date.set_label(str); x->attach(x->date);
	if (x->localmin1 != local->tm_min)//减少闪烁
	{
		x->redraw();
	}
	x->localmin1 = local->tm_min;
	Fl::repeat_timeout(1.0, callbackt, xx);
}
void Phone_startpage::cb_getpw(Address, Address pw) { reference_to<Phone_startpage>(pw).getpw(); }
void Phone_startpage::cb_backpw(Address, Address pw) { reference_to<Phone_startpage>(pw).backpw(); }
void Phone_startpage::cb_num1(Address, Address pw) { reference_to<Phone_startpage>(pw).num1(); }
void Phone_startpage::cb_num2(Address, Address pw) { reference_to<Phone_startpage>(pw).num2(); }
void Phone_startpage::cb_num3(Address, Address pw) { reference_to<Phone_startpage>(pw).num3(); }
void Phone_startpage::cb_num4(Address, Address pw) { reference_to<Phone_startpage>(pw).num4(); }
void Phone_startpage::cb_num5(Address, Address pw) { reference_to<Phone_startpage>(pw).num5(); }
void Phone_startpage::cb_num6(Address, Address pw) { reference_to<Phone_startpage>(pw).num6(); }
void Phone_startpage::cb_num7(Address, Address pw) { reference_to<Phone_startpage>(pw).num7(); }
void Phone_startpage::cb_num8(Address, Address pw) { reference_to<Phone_startpage>(pw).num8(); }
void Phone_startpage::cb_num9(Address, Address pw) { reference_to<Phone_startpage>(pw).num9(); }
void Phone_startpage::cb_num0(Address, Address pw) { reference_to<Phone_startpage>(pw).num0(); }
void Phone_startpage::cb_del(Address, Address pw) { reference_to<Phone_startpage>(pw).del(); }
void Phone_startpage::cb_vpw(Address, Address pw) { reference_to<Phone_startpage>(pw).vpw(); }
void Phone_startpage::cb_Enter(Address, Address pw) { reference_to<Phone_startpage>(pw).Enter(); }
//mainpage------------------------------------------------------------------------------------------------------------
void Phone_startpage::callbackmt(void*xx)//主屏展示时间日期的timeout
{
	Phone_startpage *x = (Phone_startpage*)xx; struct tm *local; time_t t; t = time(NULL); local = localtime(&t);
	stringstream read_time;
	if (local->tm_hour < 10)
	{
		if (local->tm_min < 10)
			read_time << '0' << local->tm_hour << ":0" << local->tm_min;
		else
			read_time << '0' << local->tm_hour << ':' << local->tm_min;
	}
	else
	{
		if (local->tm_min < 10)
			read_time << local->tm_hour << ":0" << local->tm_min;
		else
			read_time << local->tm_hour << ':' << local->tm_min;
	}
	x->mtimes.set_label(read_time.str()); read_time.str(""); x->attach(x->mtimes);

	struct tm *ptr; time_t lt; char str[80] = { '\0' }; lt = time(NULL); ptr = localtime(&lt);
	strftime(str, 100, "%A, %B %d", ptr);
	x->mdate.set_label(str); x->attach(x->mdate);
	if (x->localmin2 != local->tm_min)//减少闪烁
	{
		x->redraw();
	}
	x->localmin2 = local->tm_min;
	Fl::repeat_timeout(1.0, callbackmt, xx);
}
void Phone_startpage::callbackup(void*xx)//状态栏时间显示
{
	Phone_startpage *x = (Phone_startpage*)xx; struct tm *local; time_t t; t = time(NULL); local = localtime(&t);
	stringstream read_time;
	if (local->tm_hour < 10)
	{
		if (local->tm_min < 10)
			read_time << '0' << local->tm_hour << ":0" << local->tm_min;
		else
			read_time << '0' << local->tm_hour << ':' << local->tm_min;
	}
	else
	{
		if (local->tm_min < 10)
			read_time << local->tm_hour << ":0" << local->tm_min;
		else
			read_time << local->tm_hour << ':' << local->tm_min;
	}
	x->timeup.set_label(read_time.str()); read_time.str(""); x->attach(x->timeup);
	if (x->localmin3 != local->tm_min)//减少闪烁
	{
		x->redraw();
	}
	x->localmin3 = local->tm_min;
	Fl::repeat_timeout(0.4, callbackup, xx);
}
void Phone_startpage::callbackblack(void*xx)//自动黑屏
{
	Phone_startpage *x = (Phone_startpage*)xx;
	Fl::remove_timeout(callbackt, 0);
	x->detach(x->get_pw); x->detach(x->lockscreen); x->detach(x->times); x->detach(x->date);
	x->localmin1 = 0; x->localmin2 = 0; x->localmin3 = 0; x->pointer = 7;
	x->detach(x->lock); x->attach(x->black); x->attach(x->b0);
	x->redraw();
}
void Phone_startpage::cb_tocontact(Address, Address pw) { reference_to<Phone_startpage>(pw).tocontact(); }
void Phone_startpage::cb_tolock(Address, Address pw) { reference_to<Phone_startpage>(pw).tolock(); }
void Phone_startpage::cb_blacktolock(Address, Address pw) { reference_to<Phone_startpage>(pw).blacktolock(); }
//contact--------------------------------------------------------------------------------------------------------------
void Phone_startpage::cb_homer(Address, Address pw) { reference_to<Phone_startpage>(pw).homer(); }
void Phone_startpage::cb_next(Address, Address pw) { reference_to<Phone_startpage>(pw).next(); }
void Phone_startpage::cb_previous(Address, Address pw) { reference_to<Phone_startpage>(pw).previous(); }
void Phone_startpage::cb_next1(Address, Address pw) { reference_to<Phone_startpage>(pw).next1(); }
void Phone_startpage::cb_previous1(Address, Address pw) { reference_to<Phone_startpage>(pw).previous1(); }
void Phone_startpage::cb_srch(Address, Address pw) { reference_to<Phone_startpage>(pw).srch(); }
void Phone_startpage::cb_detailer(Address, Address pw) { reference_to<Phone_startpage>(pw).detailer(); }
void Phone_startpage::cb_retail(Address, Address pw) { reference_to<Phone_startpage>(pw).retail(); }
void Phone_startpage::cb_sing(Address, Address pw) { reference_to<Phone_startpage>(pw).sing(); }
void Phone_startpage::callbackshow(void*xx)//显示查找字符
{
	Phone_startpage *x = (Phone_startpage*)xx;
	string temp = x->search.get_string();
	if (temp.size() < 20)
	{
		x->showsearch.set_label(temp);
	}
	if (x->contrast != temp)
	{
		x->attach(x->showsearch);
		x->redraw();
	}
	x->contrast = temp;
	Fl::repeat_timeout(0.1, callbackshow, xx);
}
//button event..........................................................................................................................
//lockscreen----------------------------------------------------------------------------------------------------------------------------
void Phone_startpage::getpw()//锁屏界面去密码界面
{
	Fl::remove_timeout(callbackblack, 0);
	Fl::remove_timeout(callbackt, 0);
	pointer = 1;
	attach(lock); attach(lockscreen1); attach(back_pw); attach(bb1); attach(bb2); attach(bb3);
	attach(bb4); attach(bb5); attach(bb6); attach(bb7); attach(bb8); attach(bb9);
	attach(bb0); attach(deleter); attach(viewpw); attach(enter);
	detach(get_pw); detach(lockscreen); detach(times); detach(date);
	attach(timeup);
	Fl::add_timeout(0.01, callbackup, (void*)this);
	redraw();
}
void Phone_startpage::backpw()//密码界面返回锁屏界面
{
	pointer = 0;
	localmin1 = 0; localmin2 = 0; localmin3 = 0;
	attach(lockscreen); attach(get_pw);
	detach(lockscreen1); detach(back_pw); code.clear(); code2.clear(); detach(pw);
	detach(bb1); detach(bb2); detach(bb3); detach(bb4); detach(bb5);
	detach(bb6); detach(bb7); detach(bb8); detach(bb9); detach(bb0);
	detach(deleter); detach(hint); detach(viewpw); detach(enter);
	detach(timeup);
	Fl::remove_timeout(callbackup, 0);
	Fl::add_timeout(5, callbackblack, (void*)this);
	Fl::add_timeout(0.01, callbackt, (void*)this);
}
void Phone_startpage::num1()//密码界面按键
{
	detach(hint);
	code = code + '1';
	code2 = code2 + '*';
	if (type == 0)
		pw.set_label(code2);
	else if (type == 1)
		pw.set_label(code);
	attach(pw);
	if (code.size() == 8) { attach(hint);	code.clear(); code2.clear(); }
	redraw();
}
void Phone_startpage::num2()
{
	detach(hint);
	code = code + '2';
	code2 = code2 + '*';
	if (type == 0)
		pw.set_label(code2);
	else if (type == 1)
		pw.set_label(code);
	attach(pw);
	if (code.size() == 8) {
		attach(hint);	code.clear(); code2.clear();
	}
	redraw();
}
void Phone_startpage::num3()
{
	detach(hint);
	code = code + '3';
	code2 = code2 + '*';
	if (type == 0)
		pw.set_label(code2);
	else if (type == 1)
		pw.set_label(code);
	attach(pw);
	if (code.size() == 8) { attach(hint);	code.clear(); code2.clear(); }
	redraw();
}
void Phone_startpage::num4()
{
	detach(hint);
	code = code + '4';
	code2 = code2 + '*';
	if (type == 0)
		pw.set_label(code2);
	else if (type == 1)
		pw.set_label(code);
	attach(pw);
	if (code.size() == 8) { attach(hint);	code.clear(); code2.clear(); }
	redraw();
}
void Phone_startpage::num5()
{
	detach(hint);
	code = code + '5';
	code2 = code2 + '*';
	if (type == 0)
		pw.set_label(code2);
	else if (type == 1)
		pw.set_label(code);
	attach(pw);
	if (code.size() == 8) { attach(hint);	code.clear(); code2.clear(); }
	redraw();
}
void Phone_startpage::num6()
{
	detach(hint);
	code = code + '6';
	code2 = code2 + '*';
	if (type == 0)
		pw.set_label(code2);
	else if (type == 1)
		pw.set_label(code);
	attach(pw);
	if (code.size() == 8) { attach(hint);	code.clear(); code2.clear(); }
	redraw();
}
void Phone_startpage::num7()
{
	detach(hint);
	code = code + '7';
	code2 = code2 + '*';
	if (type == 0)
		pw.set_label(code2);
	else if (type == 1)
		pw.set_label(code);
	attach(pw);
	if (code.size() == 8) { attach(hint);	code.clear(); code2.clear(); }
	redraw();
}
void Phone_startpage::num8()
{
	detach(hint);
	code = code + '8';
	code2 = code2 + '*';
	if (type == 0)
		pw.set_label(code2);
	else if (type == 1)
		pw.set_label(code);
	attach(pw);
	if (code.size() == 8) { attach(hint);	code.clear(); code2.clear(); }
	redraw();
}
void Phone_startpage::num9()
{
	detach(hint);
	code = code + '9';
	code2 = code2 + '*';
	if (type == 0)
		pw.set_label(code2);
	else if (type == 1)
		pw.set_label(code);
	attach(pw);
	if (code.size() == 8) { attach(hint);	code.clear(); code2.clear(); }
	redraw();
}
void Phone_startpage::num0()
{
	detach(hint);
	code = code + '0';
	code2 = code2 + '*';
	if (type == 0)
		pw.set_label(code2);
	else if (type == 1)
		pw.set_label(code);
	attach(pw);
	if (code.size() == 8) { attach(hint);	code.clear(); code2.clear(); }
	redraw();
}
void Phone_startpage::Enter()//回车键，若密码正确进去主屏
{
	if (code == "1314520")
	{
		pointer = 2;
		localmin1 = 0; localmin2 = 0; localmin3 = 0;
		attach(mainpage); attach(to_contact); attach(location);
		detach(lockscreen1); detach(back_pw); code.clear(); code2.clear(); detach(get_pw);
		detach(pw); detach(bb1); detach(bb2);  detach(bb3); detach(bb4);
		detach(bb5); detach(bb6); detach(bb7); detach(bb8); detach(bb9); detach(bb0);
		detach(deleter); detach(hint); detach(viewpw); detach(enter);
		redraw();
		Fl::add_timeout(0.01, callbackmt, (void*)this);
		mciSendString(TEXT("open unlock.wav alias mysong"), NULL, 0, NULL);
		mciSendString(TEXT("play mysong wait"), NULL, 0, NULL);
		mciSendString(TEXT("close mysong"), NULL, 0, NULL);
	}
	else
		attach(hint); redraw();

}
void Phone_startpage::del()//删除键
{
	if (code.size() > 0)
	{
		code.pop_back();
		code2.pop_back();
	}
	if (type == 0)
		pw.set_label(code2);
	else if (type == 1)
		pw.set_label(code);
	attach(pw);
	redraw();
}
void Phone_startpage::vpw()//“眼睛”，转换密码显示状态
{
	if (type == 0)
		type = 1;
	else
		type = 0;
	if (type == 0)
		pw.set_label(code2);
	else if (type == 1)
		pw.set_label(code);
	attach(pw);
	redraw();
}
//mainpage--------------------------------------------------------------------------------------------------------------------------
void Phone_startpage::tocontact()//主页去通讯录
{
	pointer = 3;
	localmin1 = 0; localmin2 = 0; localmin3 = 0;
	attach(contact1); attach(home); attach(nextpg); attach(search); attach(searcher);
	Fl::remove_timeout(callbackmt, 0);
	detach(mainpage); detach(to_contact); detach(mtimes); detach(mdate); detach(location);
	redraw();
	Fl::add_timeout(0.01, callbackshow, (void*)this);
}
void Phone_startpage::blacktolock()//黑屏去锁屏
{
	pointer = 0;
	localmin1 = 0; localmin2 = 0; localmin3 = 0;
	attach(lockscreen); attach(get_pw);
	detach(b0); detach(black); attach(lock);
	Fl::add_timeout(5, callbackblack, (void*)this);
	Fl::add_timeout(0.01, callbackt, (void*)this);
}
void Phone_startpage::tolock()//任意界面去黑屏
{
	if (pointer == 7)//黑屏
		return;
	else
	{
		if (pointer == 0)//锁屏
		{
			Fl::remove_timeout(callbackt, 0);
			detach(get_pw); detach(lockscreen); detach(times); detach(date);
		}
		if (pointer == 1)//密码界面
		{
			detach(back_pw); detach(lockscreen1); code.clear(); code2.clear();
			detach(pw); detach(hint); detach(viewpw);
			detach(bb1); detach(bb2); detach(bb3); detach(bb4); detach(bb5); detach(bb6);
			detach(bb7); detach(bb8); detach(bb9); detach(bb0); detach(deleter); detach(enter);
		}
		else if (pointer == 2)//主屏
		{
			Fl::remove_timeout(callbackmt, 0);	detach(mainpage); detach(to_contact);
			detach(mtimes); detach(mdate); detach(location);
		}
		else if (pointer == 3)//通讯录1
		{
			Fl::remove_timeout(callbackshow, 0); detach(contact1); detach(search);
			detach(searcher); detach(showsearch); detach(nextpg); detach(home);
		}
		else if (pointer == 4)//通讯录2
		{
			Fl::remove_timeout(callbackshow, 0); detach(contact2); detach(search);
			detach(searcher); detach(showsearch); detach(nextpg1); detach(previouspg); detach(home);
		}
		else if (pointer == 5)//通讯录3
		{
			Fl::remove_timeout(callbackshow, 0); detach(contact3); detach(search);
			detach(searcher); detach(showsearch); detach(previouspg1); detach(home);
		}
		else if (pointer == 6)//详情
		{
			detach(detail); detach(home); detach(re_detail); detach(song);
		}
		localmin1 = 0; localmin2 = 0; localmin3 = 0; pointer = 7;
		if (pointer != 0)
		{
			detach(timeup);
			Fl::remove_timeout(callbackup, 0);
		}
		detach(lock); attach(black); attach(b0);
		redraw();
	}
}
void Phone_startpage::homer()//返回主页
{
	if (pointer == 2)
	{
		return;
	}
	else if (pointer == 3)
	{
		Fl::remove_timeout(callbackshow, 0); detach(contact1); detach(search);
		detach(searcher); detach(showsearch); detach(nextpg); detach(home);
	}
	else if (pointer == 4)
	{
		Fl::remove_timeout(callbackshow, 0); detach(contact2); detach(search);
		detach(searcher); detach(showsearch); detach(nextpg1); detach(previouspg); detach(home);
	}
	else if (pointer == 5)
	{
		Fl::remove_timeout(callbackshow, 0); detach(contact3); detach(search);
		detach(searcher); detach(showsearch); detach(previouspg1); detach(home);
	}
	else if (pointer == 6)
	{
		detach(detail); detach(home); detach(re_detail); detach(song);
	}
	pointer = 2;
	localmin1 = 0; localmin2 = 0; localmin3 = 0;
	attach(mainpage); attach(to_contact);  attach(location);
	Fl::add_timeout(0.01, callbackmt, (void*)this);
}
//contact---------------------------------------------------------------------------------------------------------------------------
void Phone_startpage::next()//通讯录1去2
{
	pointer = 4;
	localmin1 = 0; localmin2 = 0; localmin3 = 0;
	attach(contact2); attach(previouspg); attach(nextpg1); attach(details);
	detach(contact1); detach(nextpg);	attach(showsearch);
	redraw();
}
void Phone_startpage::previous()//通讯录2去1
{
	pointer = 3;
	localmin1 = 0; localmin2 = 0; localmin3 = 0;
	attach(contact1); attach(nextpg);
	detach(contact2);  detach(previouspg); detach(nextpg1); detach(details);	attach(showsearch);
	redraw();
}
void Phone_startpage::next1()//通讯录2去3
{
	pointer = 5;
	localmin1 = 0; localmin2 = 0; localmin3 = 0;
	attach(contact3); attach(previouspg1);
	detach(contact2);  detach(nextpg1); detach(previouspg); detach(details);	attach(showsearch);
	redraw();
}
void Phone_startpage::previous1()//通讯录3去2
{
	pointer = 4;
	localmin1 = 0; localmin2 = 0; localmin3 = 0;
	attach(contact2); attach(nextpg1); attach(previouspg); attach(details);	attach(showsearch);
	detach(contact3); detach(previouspg1);
	redraw();
}
void Phone_startpage::srch()//查找按钮，点击进行查找，跳转去该界面
{
	string name; char c;
	localmin1 = 0; localmin2 = 0; localmin3 = 0;
	name = search.get_string();
	c = name.at(0);
	//showsearch.set_label(" ");
	if (c >= 'c'&&c <= 'r' || c >= 'C'&&c <= 'R')
	{
		if (pointer == 3)
			next();
		else if (pointer == 4)
		{
			return;
		}
		else if (pointer == 5)
		{
			pointer = 4;
			detach(contact3);  detach(previouspg1); attach(contact2); attach(previouspg);
			attach(nextpg1); attach(details);	attach(showsearch);//贴回去
			redraw();
		}
	}
	else if (c >= 's'&&c <= 'z' || c >= 'S'&&c <= 'Z')
	{
		if (pointer == 3)
		{
			pointer = 5;
			detach(contact1); detach(nextpg);	attach(contact3); attach(previouspg1);	attach(showsearch);
			redraw();
		}
		else if (pointer == 4)
		{
			next1();
		}
		else if (pointer == 5)
		{
			return;
		}
	}
	else
	{
		if (pointer == 3)
			return;
		else if (pointer == 4)
		{
			previous();
		}
		else if (pointer == 5)
		{
			pointer = 3;
			detach(contact3);  detach(previouspg1);	attach(contact1); attach(nextpg); attach(showsearch);
			redraw();
		}
	}
}
void Phone_startpage::detailer()//跳转进入详情界面
{
	pointer = 6;
	localmin1 = 0; localmin2 = 0; localmin3 = 0;
	Fl::remove_timeout(callbackshow, 0);
	attach(detail); attach(re_detail); attach(song);
	detach(details); detach(contact2);  detach(nextpg1); detach(previouspg);
	detach(search); detach(searcher); detach(showsearch);
	redraw();
}
void Phone_startpage::retail()//详情界面跳转回初始通讯录面
{
	pointer = 4;
	localmin1 = 0; localmin2 = 0; localmin3 = 0;
	detach(detail); detach(re_detail); detach(song);
	attach(contact2); attach(previouspg); attach(nextpg1); attach(details);
	attach(search); attach(searcher); attach(showsearch);
	Fl::add_timeout(0.01, callbackshow, (void*)this);
}
void Phone_startpage::sing()//ringtone钮
{
	mciSendString(TEXT("open song2.wav alias mysong"), NULL, 0, NULL);
	mciSendString(TEXT("play mysong wait"), NULL, 0, NULL);
	mciSendString(TEXT("close mysong"), NULL, 0, NULL);
}

int main()
{
	try
	{
		Phone_startpage win1(Point(100, 100), 620, 800, "Phone");
		return gui_main();
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Some exception\n";
		return 2;
	}
}