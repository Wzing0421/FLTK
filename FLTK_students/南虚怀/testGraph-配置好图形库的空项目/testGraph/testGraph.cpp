#include "iostream"
#include "Simple_window.h"
#include "std_lib_facilities.h"
#include "Graph.h"
#include "GUI.h"
#include "Window.h"
#include "Point.h"
#include "random"
#include <time.h>
#include <iostream>
#include <sstream>
#include "Graph.h"         // get access to our graphics library facilities
#include "GUI.h"
#include "Window.h"
#include <FL/Fl_Button.H>
#include "Simple_window.h"
#include "FL/Fl_JPEG_Image.H"
#include <windows.h>
#include <thread>
#include <chrono>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_ask.H>
using namespace Graph_lib;
using namespace std;
void   Delay(int   time)//time*1000为秒数
{
	clock_t   now = clock();
	while (clock() - now   <   time);
}
int aaa = 0, bbb = 0;
class EnterButton : public Fl_Button
{
	int handle(int e)
	{
		switch (e)
		{
		case FL_PUSH:
			color(FL_GREEN);
			labelsize(18);

			aaa = 1;
			bbb = 0;
			redraw();

			return 1;
		case FL_RELEASE:
			color(FL_BLUE);
			aaa = 0;
			bbb = 1;
			labelsize(18);
			redraw();
			return 1;
		default: return Fl_Button::handle(e);
		}
	}
public:
	EnterButton(int x, int y, int w, int h, const char *l) : Fl_Button(x, y, w, h, l) {}
};





struct phone_window :Graph_lib::Window{
	phone_window(Point xy, int w, int h, const string& title);
	void start(); void start1();
	Image i1, i2, t1, t2, t3, t4, t5, t6, t7, t8, t9, p1, p2, p3;
	Image s1, s2, s3, s4, s5, s6, s7, s8;
	Image l1, l2, l3, l4, l5;
	Image m1;
	Image middle1, light, middle2, emergencym1, emergencym2, emergencym3, emergencym4, emergencym5;
	Image off1, off2, off3, off4, off5, off6, off7, off8, off9, off10, off11, off12, off13, off14, off15, off16, off17, off18, off19, off20, off21, off22, off23, off24, off25, off26, off27, off28, off29, off30;
	Image on1, on2, on3, on4, on5, on6, on7, on8, on9, on10, on11, on12, on13, on14, on15, on16, on17, on18, on19, on20, on21, on22, on23, on24, on25, on26, on27, on28, on29, on30, on31, on32, on33, on34, on35, on36, on37, on38;
	Image j0, j1, j2, j3, j4, j5, j6, j7, j8, j9, j10, j11, j12, j13, j14, j15, j16, j17, j18, j19, j20, j21, j22, j23;//渐变图片
	Image c0, c8;//通讯录图片
	Image c1, c2, c3, c4, c5, c6, c7, c14;//通讯录渐变图片
	Image c9, c10, c11, c12, c13;
	Image toALice1, toALice2, toALice3, toALice4, toALice5, toALice6, toALice7;
	Image toBob1, toBob2, toBob3, toBob4, toBob5, toBob6, toBob7;
	Image toCarol1, toCarol2, toCarol3, toCarol4, toCarol5, toCarol6, toCarol7;
	Image ar1, ar2, ar3, ar4, ar5, ar6;
	Image br1, br2, br4, br5, br6;
	Image cr1, cr2, cr3, cr4, cr5, cr6;
	Image gr1, gr2, gr3, gr4, gr5, gr6;
	Image hr1, hr2, hr3, hr4, hr5;
	Image toGrace1, toGrace2, toGrace3, toGrace4, toGrace5, toGrace6, toGrace7, toGrace8;
	Image toHans1, toHans2, toHans3, toHans4, toHans5, toHans6, toHans7, toHans8;
	Image lton1, lton2, lton3, lton4;
	Image ntol1, ntol2, ntol3, ntol4, ntol5, ntol6;
	Image ntom1, ntom2, ntom3, ntom4, ntom5, ntom6;
	Image ltom1, ltom2, ltom3, ltom4, ltom5, ltom6, ltom7;
	Image noResults;
	Image KEYBOARD1, KEYBOARD2, KEYBOARD3, KEYBOARD4, KEYBOARD5, keyboard;
	Image keyboardn, keyboardn1, keyboardn2, keyboardn3, keyboardn4, keyboardn5;
	Button b1, quit_button, b2, b3, b4, b5, b6, b7;
	Button n0, n1, n2, n3, n4, n5, n6, n7, n8, n9;
	Button alice1, bob1, carol1, grace1, hans1, carol2, grace2, hans3;
	Button shutdown2;
	Button bdelete;

	Button key_a, key_A;
	Button key_b, key_B;
	Button key_c, key_C;
	Button key_d, key_D;
	Button key_e, key_E;
	Button key_f, key_F;
	Button key_g, key_G;
	Button key_h, key_H;
	Button key_i, key_I;
	Button key_j, key_J;
	Button key_k, key_K;
	Button key_l, key_L;
	Button key_m, key_M;
	Button key_n, key_N;
	Button key_o, key_O;
	Button key_p, key_P;
	Button key_q, key_Q;
	Button key_r, key_R;
	Button key_s, key_S;
	Button key_t, key_T;
	Button key_u, key_U;
	Button key_v, key_V;
	Button key_w, key_W;
	Button key_x, key_X;
	Button key_y, key_Y;
	Button key_z, key_Z;
	Button search;
	Button tran;//大小写转换
	Button searchReturn, searchReturn2;
	int numberOfletters = 0;
	Text letter1, letter2, letter3, letter4, letter5, letter6;
	vector<char>name;
	Button searchName;
	int page = 0;
	Image pleaseInput, aftersearch;
	Text sname;
	string strname2 = "11", strname3 = "111", strname4 = "1111", strname5 = "11111";


	bool b_alice1 = 0, b_bob1 = 0, b_carol1 = 0, b_grace1 = 0, b_hans1 = 0, b_grace2 = 0, b_carol2 = 0, b_hans3 = 0;

	Button b8;//通讯录按钮
	Button b9;//回到主界面
	Button b10, b11;//下一页，上一页
	Button b12, b13, b14, b15, b16;//通讯录人员详细信息
	Button b17, b18;//回到通讯录界面

	int number = 0, ans = 0;
	bool wait_for_button();
	bool button_pushed;
	static void cb_alice1(Address, Address);
	static void cb_bob1(Address, Address);
	static void cb_carol1(Address, Address);
	static void cb_grace1(Address, Address);
	static void cb_hans1(Address, Address);
	static void cb_carol2(Address, Address);
	static void cb_grace2(Address, Address);
	static void cb_hans3(Address, Address);
	static void cb_bdelete(Address, Address);

	static void cb_start(Address, Address);
	static void cb_screen(Address, Address);
	static void cb_start1(Address, Address);
	static void cb_quit(Address, Address);
	static void cb_emergency(Address, Address);
	static void cb_shutdown(Address, Address);
	static void cb_return1(Address, Address);
	static void cb_return2(Address, Address);
	static void cb_n0(Address, Address);
	static void cb_n1(Address, Address); static void cb_n6(Address, Address);
	static void cb_n2(Address, Address);
	static void cb_n3(Address, Address); static void cb_n7(Address, Address);
	static void cb_n4(Address, Address);
	static void cb_n5(Address, Address); static void cb_n8(Address, Address);
	static void cb_shutdown2(Address, Address);
	static void cb_n9(Address, Address);
	static void cb_b8(Address, Address);
	static void cb_b9(Address, Address);
	static void cb_b10(Address, Address);
	static void cb_b11(Address, Address);
	static void cb_b12(Address, Address);
	static void cb_b13(Address, Address);
	static void cb_b14(Address, Address);
	static void cb_b15(Address, Address);
	static void cb_b16(Address, Address);
	static void cb_b17(Address, Address);
	static void cb_b18(Address, Address);
	static void cb_searchReturn2(Address, Address);
	static void cb_a(Address, Address);
	static void cb_b(Address, Address);
	static void cb_c(Address, Address);
	static void cb_d(Address, Address);
	static void cb_e(Address, Address);
	static void cb_f(Address, Address);
	static void cb_g(Address, Address);
	static void cb_h(Address, Address);
	static void cb_i(Address, Address);
	static void cb_j(Address, Address);
	static void cb_k(Address, Address);
	static void cb_l(Address, Address);
	static void cb_m(Address, Address);
	static void cb_n(Address, Address);
	static void cb_o(Address, Address);
	static void cb_p(Address, Address);
	static void cb_q(Address, Address);
	static void cb_r(Address, Address);
	static void cb_s(Address, Address);
	static void cb_t(Address, Address);
	static void cb_u(Address, Address);
	static void cb_v(Address, Address);
	static void cb_w(Address, Address);
	static void cb_x(Address, Address);
	static void cb_y(Address, Address);
	static void cb_z(Address, Address);
	static void cb_A(Address, Address);
	static void cb_B(Address, Address);
	static void cb_C(Address, Address);
	static void cb_D(Address, Address);
	static void cb_E(Address, Address);
	static void cb_F(Address, Address);
	static void cb_G(Address, Address);
	static void cb_H(Address, Address);
	static void cb_I(Address, Address);
	static void cb_J(Address, Address);
	static void cb_K(Address, Address);
	static void cb_L(Address, Address);
	static void cb_M(Address, Address);
	static void cb_N(Address, Address);
	static void cb_O(Address, Address);
	static void cb_P(Address, Address);
	static void cb_Q(Address, Address);
	static void cb_R(Address, Address);
	static void cb_S(Address, Address);
	static void cb_T(Address, Address);
	static void cb_U(Address, Address);
	static void cb_V(Address, Address);
	static void cb_W(Address, Address);
	static void cb_X(Address, Address);
	static void cb_Y(Address, Address);
	static void cb_Z(Address, Address);
	static void cb_search(Address, Address);
	static void cb_tran(Address, Address);
	static void cb_searchReturn(Address, Address);
	static void cb_searchName(Address, Address);
	void searchReturn2u();
	void searchNameu();
	void tranu();
	void searchu();
	void searchReturnu();
	void shutdown2u();
	void alice1u();
	void bob1u();
	void carol1u();
	void grace1u();
	void hans1u();
	void carol2u();
	void grace2u();
	void hans3u();
	void bdeleteu();




	void au();
	void bu();
	void cu();
	void du();
	void eu();
	void fu();
	void gu();
	void hu();
	void iu();
	void ju();
	void ku();
	void lu();
	void mu();
	void nu();
	void ou();
	void pu();
	void qu();
	void ru();
	void su();
	void tu();
	void uu();
	void vu();
	void wu();
	void xu();
	void yu();
	void zu();
	void Au();
	void Bu();
	void Cu();
	void Du();
	void Eu();
	void Fu();
	void Gu();
	void Hu();
	void Iu();
	void Ju();
	void Ku();
	void Lu();
	void Mu();
	void Nu();
	void Ou();
	void Pu();
	void Qu();
	void Ru();
	void Su();
	void Tu();
	void Uu();
	void Vu();
	void Wu();
	void Xu();
	void Yu();
	void Zu();

	void bu8();
	void bu9();
	void bu10();
	void bu11(); void bu12();
	void bu13();
	void bu14();
	void bu15();
	void bu16(); void bu17();
	void bu18();
	void quit();
	void return1();
	void return2();
	void num0();
	void num1(); void num3(); void num5(); void num7(); void num8(); void num9(); void num2(); void num4(); void num6();
	void shutdown();
	void emergency();
	void screen();
	Text tx1, tx2, tx3, tx4;
	int q = 1;
	int k = 1, k2 = 0, k3 = 0, k4 = 0;
	int j = 0;//锁屏界面切换
	int z = 0;//回到主界面
	int  zz = 0;//回到y通讯录第一页
};
phone_window::phone_window(Point xy, int w, int h, const string& title)
	:Window(xy, w, h, title), b1(Point(450, 200), 25, 75, "", cb_start), i1({ 100, 100 }, "poweroff.jpg"), i2({ 100, 100 }, "open.jpg"),
	middle1({ 100, 100 }, "mainInterface button.jpg"),
	middle2({ 100, 100 }, "middle2.jpg"),
	light({ 100, 100 }, "mainInterfacelight.jpg"),
	emergencym1({ 100, 100 }, "emergencym1.jpg"),
	emergencym2({ 100, 100 }, "emergencym2.jpg"),
	emergencym3({ 100, 100 }, "emergencym3.jpg"),
	emergencym4({ 100, 100 }, "emergencym4.jpg"),
	emergencym5({ 100, 100 }, "emergencym5.jpg"),
	t1({ 100, 100 }, "t1.jpg"),
	t2({ 100, 100 }, "t2.jpg"),
	t3({ 100, 100 }, "t3.jpg"),
	t4({ 100, 100 }, "t4.jpg"),
	t5({ 100, 100 }, "t5.jpg"),
	t6({ 100, 100 }, "t6.jpg"),
	t7({ 100, 100 }, "t7.jpg"),
	KEYBOARD1({ 100, 100 }, "KEYBOARD1.jpg"),
	KEYBOARD2({ 100, 100 }, "KEYBOARD2.jpg"),
	KEYBOARD3({ 100, 100 }, "KEYBOARD3.jpg"),
	KEYBOARD4({ 100, 100 }, "KEYBOARD4.jpg"),
	KEYBOARD5({ 100, 100 }, "KEYBOARD5.jpg"),
	keyboard({ 100, 100 }, "keyboard.jpg"),
	pleaseInput({ 100, 100 }, "pleaseInput.jpg"),
	c1({ 100, 100 }, "通讯录渐变1.jpg"),
	c2({ 100, 100 }, "通讯录渐变2.jpg"),
	c3({ 100, 100 }, "通讯录渐变3.jpg"),
	c4({ 100, 100 }, "通讯录渐变4.jpg"),
	c5({ 100, 100 }, "通讯录渐变5.jpg"),
	c6({ 100, 100 }, "通讯录渐变6.jpg"),
	c7({ 100, 100 }, "通讯录渐变7.jpg"),
	ar1({ 100, 100 }, "AliceReturn1.jpg"),
	ar2({ 100, 100 }, "AliceReturn2.jpg"),
	ar3({ 100, 100 }, "AliceReturn3.jpg"),
	ar4({ 100, 100 }, "AliceReturn4.jpg"),
	ar5({ 100, 100 }, "AliceReturn5.jpg"),
	ar6({ 100, 100 }, "AliceReturn6.jpg"),
	br1({ 100, 100 }, "br1.jpg"),
	br2({ 100, 100 }, "br2.jpg"),
	noResults({ 100, 100 }, "noResults.jpg"),
	br4({ 100, 100 }, "br4.jpg"),
	br5({ 100, 100 }, "br5.jpg"),
	br6({ 100, 100 }, "br6.jpg"),
	cr1({ 100, 100 }, "cr1.jpg"),
	cr2({ 100, 100 }, "cr2.jpg"),
	cr3({ 100, 100 }, "cr3.jpg"),
	cr4({ 100, 100 }, "cr4.jpg"),
	cr5({ 100, 100 }, "cr5.jpg"),
	cr6({ 100, 100 }, "cr6.jpg"),
	gr1({ 100, 100 }, "gr1.jpg"),
	gr2({ 100, 100 }, "gr2.jpg"),
	gr3({ 100, 100 }, "gr3.jpg"),
	gr4({ 100, 100 }, "gr4.jpg"),
	gr5({ 100, 100 }, "gr5.jpg"),
	gr6({ 100, 100 }, "gr6.jpg"),
	hr1({ 100, 100 }, "hr1.jpg"),
	hr2({ 100, 100 }, "hr2.jpg"),
	hr3({ 100, 100 }, "hr3.jpg"),
	hr4({ 100, 100 }, "hr4.jpg"),
	hr5({ 100, 100 }, "hr5.jpg"),
	toALice1({ 100, 100 }, "toALice1.jpg"),
	toALice2({ 100, 100 }, "toALice2.jpg"),
	toALice3({ 100, 100 }, "toALice3.jpg"),
	toALice4({ 100, 100 }, "toALice4.jpg"),
	toALice5({ 100, 100 }, "toALice5.jpg"),
	toALice6({ 100, 100 }, "toALice6.jpg"),
	toALice7({ 100, 100 }, "toALice7.jpg"),
	toCarol1({ 100, 100 }, "toCarol1.jpg"),
	toCarol2({ 100, 100 }, "toCarol2.jpg"),
	toCarol3({ 100, 100 }, "toCarol3.jpg"),
	toCarol4({ 100, 100 }, "toCarol4.jpg"),
	toCarol5({ 100, 100 }, "toCarol5.jpg"),
	toCarol6({ 100, 100 }, "toCarol6.jpg"),
	toCarol7({ 100, 100 }, "toCarol7.jpg"),
	toGrace1({ 100, 100 }, "toGrace1.jpg"),
	toGrace2({ 100, 100 }, "toGrace2.jpg"),
	toGrace3({ 100, 100 }, "toGrace3.jpg"),
	toGrace4({ 100, 100 }, "toGrace4.jpg"),
	toGrace5({ 100, 100 }, "toGrace5.jpg"),
	toGrace6({ 100, 100 }, "toGrace6.jpg"),
	toGrace7({ 100, 100 }, "toGrace7.jpg"),
	toGrace8({ 100, 100 }, "toGrace8.jpg"),
	toHans1({ 100, 100 }, "toHans1.jpg"),
	toHans2({ 100, 100 }, "toHans2.jpg"),
	toHans3({ 100, 100 }, "toHans3.jpg"),
	toHans4({ 100, 100 }, "toHans4.jpg"),
	toHans5({ 100, 100 }, "toHans5.jpg"),
	toHans6({ 100, 100 }, "toHans6.jpg"),
	toHans7({ 100, 100 }, "toHans7.jpg"),
	toHans8({ 100, 100 }, "toHans8.jpg"),
	toBob1({ 100, 100 }, "toBob1.jpg"),
	toBob2({ 100, 100 }, "toBob2.jpg"),
	toBob3({ 100, 100 }, "toBob3.jpg"),
	toBob4({ 100, 100 }, "toBob4.jpg"),
	toBob5({ 100, 100 }, "toBob5.jpg"),
	toBob6({ 100, 100 }, "toBob6.jpg"),
	toBob7({ 100, 100 }, "toBob7.jpg"),
	ltom1({ 100, 100 }, "ltom1.jpg"),
	ltom2({ 100, 100 }, "ltom2.jpg"),
	ltom3({ 100, 100 }, "ltom3.jpg"),
	ltom4({ 100, 100 }, "ltom4.jpg"),
	ltom5({ 100, 100 }, "ltom5.jpg"),
	ltom6({ 100, 100 }, "ltom6.jpg"),
	ltom7({ 100, 100 }, "ltom7.jpg"),
	ntom1({ 100, 100 }, "ntom1.jpg"),
	ntom2({ 100, 100 }, "ntom2.jpg"),
	ntom3({ 100, 100 }, "ntom3.jpg"),
	ntom4({ 100, 100 }, "ntom4.jpg"),
	ntom5({ 100, 100 }, "ntom5.jpg"),
	ntom6({ 100, 100 }, "ntom6.jpg"),
	lton1({ 100, 100 }, "lton1.jpg"),
	lton2({ 100, 100 }, "lton2.jpg"),
	lton3({ 100, 100 }, "lton3.jpg"),
	lton4({ 100, 100 }, "lton4.jpg"),
	ntol1({ 100, 100 }, "ntol1.jpg"),
	ntol2({ 100, 100 }, "ntol2.jpg"),
	ntol3({ 100, 100 }, "ntol3.jpg"),
	ntol4({ 100, 100 }, "ntol4.jpg"),
	ntol5({ 100, 100 }, "ntol5.jpg"),
	ntol6({ 100, 100 }, "ntol6.jpg"),
	keyboardn({ 100, 100 }, "keyboardn.jpg"),
	keyboardn1({ 100, 100 }, "keyboardn1.jpg"),
	keyboardn2({ 100, 100 }, "keyboardn2.jpg"),
	keyboardn3({ 100, 100 }, "keyboardn3.jpg"),
	keyboardn4({ 100, 100 }, "keyboardn4.jpg"),
	keyboardn5({ 100, 100 }, "keyboardn5.jpg"),
	sname({ 265, 200 }, " "),
	aftersearch({ 100, 100 }, "aftersearch.jpg"),
	shutdown2({ 360, 250 }, 50, 50, "shutdown2", cb_shutdown2),
	bdelete({ 415, 449 }, 35, 35, "shutdown2", cb_bdelete),
	off1({ 100, 100 }, "关机前.jpg"),
	off2({ 100, 100 }, "off2.jpg"),
	off3({ 100, 100 }, "off3.jpg"),
	off4({ 100, 100 }, "off4.jpg"),
	off5({ 100, 100 }, "off5.jpg"),
	off6({ 100, 100 }, "off6.jpg"),
	off7({ 100, 100 }, "off7.jpg"),
	off8({ 100, 100 }, "off8.jpg"),
	off9({ 100, 100 }, "off9.jpg"),
	off10({ 100, 100 }, "off10.jpg"),
	off11({ 100, 100 }, "off11.jpg"),
	off12({ 100, 100 }, "off12.jpg"),
	off13({ 100, 100 }, "off13.jpg"),
	off14({ 100, 100 }, "off14.jpg"),
	off15({ 100, 100 }, "off15.jpg"),
	off16({ 100, 100 }, "off16.jpg"),
	off17({ 100, 100 }, "off17.jpg"),
	off18({ 100, 100 }, "off18.jpg"),
	off19({ 100, 100 }, "off19.jpg"),
	off20({ 100, 100 }, "off20.jpg"),
	off21({ 100, 100 }, "off21.jpg"),
	off22({ 100, 100 }, "off22.jpg"),
	off23({ 100, 100 }, "off23.jpg"),
	off24({ 100, 100 }, "off24.jpg"),
	off25({ 100, 100 }, "off25.jpg"),
	off26({ 100, 100 }, "off26.jpg"),
	off27({ 100, 100 }, "off27.jpg"),
	off28({ 100, 100 }, "off28.jpg"),
	off29({ 100, 100 }, "off29.jpg"),
	off30({ 100, 100 }, "off30.jpg"),


	on1({ 100, 100 }, "/on1.jpg"),
	on2({ 100, 100 }, "/on2.jpg"),
	on3({ 100, 100 }, "on3.jpg"),
	on4({ 100, 100 }, "on4.jpg"),
	on5({ 100, 100 }, "on5.jpg"),
	on6({ 100, 100 }, "on6.jpg"),
	on7({ 100, 100 }, "on7.jpg"),
	on8({ 100, 100 }, "on8.jpg"),
	on9({ 100, 100 }, "on9.jpg"),
	on10({ 100, 100 }, "on10.jpg"),
	on11({ 100, 100 }, "on11.jpg"),
	on12({ 100, 100 }, "on12.jpg"),
	on13({ 100, 100 }, "on13.jpg"),
	on14({ 100, 100 }, "on14.jpg"),
	on15({ 100, 100 }, "on15.jpg"),
	on16({ 100, 100 }, "on16.jpg"),
	on17({ 100, 100 }, "on17.jpg"),
	on18({ 100, 100 }, "on18.jpg"),
	on19({ 100, 100 }, "on19.jpg"),
	on20({ 100, 100 }, "on20.jpg"),
	on21({ 100, 100 }, "on21.jpg"),
	on22({ 100, 100 }, "on22.jpg"),
	on23({ 100, 100 }, "on23.jpg"),
	on24({ 100, 100 }, "on24.jpg"),
	on25({ 100, 100 }, "on25.jpg"),
	on26({ 100, 100 }, "on26.jpg"),
	on27({ 100, 100 }, "on27.jpg"),
	on28({ 100, 100 }, "on28.jpg"),
	on29({ 100, 100 }, "on29.jpg"),
	on30({ 100, 100 }, "on30.jpg"),
	on31({ 100, 100 }, "on31.jpg"),
	on32({ 100, 100 }, "on32.jpg"),
	on33({ 100, 100 }, "on33.jpg"),
	on34({ 100, 100 }, "on34.jpg"),
	on35({ 100, 100 }, "on35.jpg"),
	on36({ 100, 100 }, "on36.jpg"),
	on37({ 100, 100 }, "on37.jpg"),
	on38({ 100, 100 }, "on38.jpg"),


	c14({ 100, 100 }, "通讯录渐变-.jpg"),
	c9({ 100, 100 }, "Alice.jpg"),
	c10({ 100, 100 }, "Bob.jpg"),
	c11({ 100, 100 }, "Carol.jpg"),
	c12({ 100, 100 }, "Grace.jpg"),
	c13({ 100, 100 }, "Hans.jpg"),
	t8({ 100, 100 }, "t8.jpg"),
	t9({ 100, 100 }, "t9.jpg"),
	p1({ 100, 100 }, "p1.jpg"),
	p2({ 100, 100 }, "p2.jpg"),
	p3({ 100, 100 }, "p3.jpg"),
	c0({ 100, 100 }, "contacts.jpg"),
	c8({ 100, 100 }, "contacts2.jpg"),
	j0({ 100, 100 }, "渐变0.jpg"),
	j1({ 100, 100 }, "渐变1.jpg"),
	j2({ 100, 100 }, "渐变2.jpg"),
	j3({ 100, 100 }, "渐变3.jpg"),
	j4({ 100, 100 }, "渐变4.jpg"),
	j5({ 100, 100 }, "渐变5.jpg"),
	j6({ 100, 100 }, "渐变6.jpg"),
	j7({ 100, 100 }, "渐变7.jpg"),
	j8({ 100, 100 }, "渐变8.jpg"),
	j9({ 100, 100 }, "渐变9.jpg"),
	j10({ 100, 100 }, "变暗1.jpg"),
	j11({ 100, 100 }, "变暗2.jpg"),
	j12({ 100, 100 }, "变暗3.jpg"),
	j13({ 100, 100 }, "变暗4.jpg"),
	j14({ 100, 100 }, "变暗5.jpg"),
	j15({ 100, 100 }, "变1.jpg"),
	j16({ 100, 100 }, "变2.jpg"),
	j17({ 100, 100 }, "变3.jpg"),
	j18({ 100, 100 }, "变4.jpg"),
	j19({ 100, 100 }, "变5.jpg"),
	j20({ 100, 100 }, "变6.jpg"),
	j21({ 100, 100 }, "变7.jpg"),
	j22({ 100, 100 }, "变8.jpg"),
	j23({ 100, 100 }, "变9.jpg"),
	s1({ 100, 100 }, "shutdown1.jpg"),
	s2({ 100, 100 }, "shutdown2.jpg"),
	s3({ 100, 100 }, "shutdown3.jpg"),
	s4({ 100, 100 }, "shutdown4.jpg"),
	s5({ 100, 100 }, "shutdown5.jpg"),
	s6({ 100, 100 }, "shutdown6.jpg"),
	s7({ 100, 100 }, "shutdown7.jpg"),
	s8({ 100, 100 }, "shutdown8.jpg"),
	l1({ 100, 100 }, "lock1.jpg"),
	l2({ 100, 100 }, "lock2.jpg"),
	l3({ 100, 100 }, "lock3.jpg"),
	l4({ 100, 100 }, "lock4.jpg"),
	l5({ 100, 100 }, "error.jpg"),
	m1({ 100, 100 }, "mainInterface.jpg"),
	tx1({ 290, 300 }, ""), tx2({ 260, 150 }, ""), tx3({ 260, 180 }, ""), tx4({ 380, 123 }, ""),

	key_a({ 270, 433 }, 20, 20, "a", cb_a), key_A({ 270, 433 }, 20, 20, "A", cb_A),
	key_b({ 368, 464 }, 20, 20, "b", cb_b), key_B({ 368, 464 }, 20, 20, "B", cb_B),
	key_c({ 324, 464 }, 20, 20, "c", cb_c), key_C({ 324, 464 }, 20, 20, "C", cb_C),
	key_d({ 314, 433 }, 20, 20, "d", cb_d), key_D({ 314, 433 }, 20, 20, "D", cb_D),
	key_e({ 304, 402 }, 20, 20, "e", cb_e), key_E({ 304, 402 }, 20, 20, "E", cb_E),
	key_f({ 336, 433 }, 20, 20, "f", cb_f), key_F({ 336, 433 }, 20, 20, "F", cb_F),
	key_g({ 348, 433 }, 20, 20, "g", cb_g), key_G({ 348, 433 }, 20, 20, "G", cb_G),
	key_h({ 370, 433 }, 20, 20, "h", cb_h), key_H({ 370, 433 }, 20, 20, "H", cb_H),
	key_i({ 395, 402 }, 20, 20, "i", cb_i), key_I({ 395, 402 }, 20, 20, "I", cb_I),
	key_j({ 389, 433 }, 20, 20, "j", cb_j), key_J({ 389, 433 }, 20, 20, "J", cb_J),
	key_k({ 406, 433 }, 20, 20, "k", cb_k), key_K({ 406, 433 }, 20, 20, "K", cb_K),
	key_l({ 423, 433 }, 20, 20, "l", cb_l), key_L({ 423, 433 }, 20, 20, "L", cb_L),
	key_m({ 407, 464 }, 20, 20, "m", cb_m), key_M({ 407, 464 }, 20, 20, "M", cb_M),
	key_n({ 385, 464 }, 20, 20, "n", cb_n), key_N({ 385, 464 }, 20, 20, "N", cb_N),
	key_o({ 415, 402 }, 20, 20, "o", cb_o), key_O({ 415, 402 }, 20, 20, "O", cb_O),
	key_p({ 438, 402 }, 20, 20, "p", cb_p), key_P({ 438, 402 }, 20, 20, "P", cb_P),
	key_q({ 260, 402 }, 20, 20, "q", cb_q), key_Q({ 260, 402 }, 20, 20, "Q", cb_Q),
	key_r({ 326, 402 }, 20, 20, "r", cb_r), key_R({ 326, 402 }, 20, 20, "R", cb_R),
	key_s({ 292, 433 }, 20, 20, "s", cb_s), key_S({ 292, 433 }, 20, 20, "S", cb_S),
	key_t({ 338, 402 }, 20, 20, "t", cb_t), key_T({ 338, 402 }, 20, 20, "T", cb_T),
	key_u({ 377, 402 }, 20, 20, "u", cb_u), key_U({ 377, 402 }, 20, 20, "U", cb_U),
	key_v({ 346, 464 }, 20, 20, "v", cb_v), key_V({ 346, 464 }, 20, 20, "V", cb_V),
	key_w({ 282, 402 }, 20, 20, "w", cb_w), key_W({ 282, 402 }, 20, 20, "W", cb_W),
	key_x({ 307, 464 }, 20, 20, "x", cb_x), key_X({ 307, 464 }, 20, 20, "X", cb_X),
	key_y({ 360, 402 }, 20, 20, "y", cb_y), key_Y({ 360, 402 }, 20, 20, "Y", cb_Y),
	key_z({ 285, 464 }, 20, 20, "z", cb_z), key_Z({ 285, 464 }, 20, 20, "Z", cb_Z),
	search({ 250, 150 }, 200, 30, "search", cb_search),
	tran({ 256, 465 }, 30, 30, "tran", cb_tran),
	letter1({ 276, 171 }, " "),
	letter2({ 285, 171 }, " "),
	letter3({ 294, 171 }, " "),
	letter4({ 303, 171 }, " "),
	letter5({ 312, 171 }, " "),
	letter6({ 321, 171 }, " "),
	searchReturn({ 380, 484 }, 35, 35, "re", cb_searchReturn),
	searchName(Point(415, 484), 35, 35, "search", cb_searchName),





	b2(Point(330, 525), 50, 30, "", cb_start1),
	b3(Point(380, 480), 50, 20, "", cb_return1),
	b4(Point(280, 480), 50, 20, "", cb_emergency),
	b5(Point(280, 480), 50, 20, "", cb_return2), b6(Point(450, 200), 20, 70, "", cb_shutdown),
	b7(Point(250, 155), 10, 50, "", cb_screen),
	n0(Point(330, 410), 40, 40, "0", cb_n0),
	n1(Point(280, 260), 40, 40, "1", cb_n1),
	n2(Point(330, 260), 40, 40, "2", cb_n2),
	n3(Point(380, 260), 40, 40, "3", cb_n3),
	n4(Point(280, 310), 40, 40, "4", cb_n4),
	n5(Point(330, 310), 40, 40, "5", cb_n5),
	n6(Point(380, 310), 40, 40, "6", cb_n6),
	n7(Point(500, 360), 40, 40, "7", cb_n7),
	n8(Point(330, 360), 40, 40, "8", cb_n8),
	n9(Point(380, 360), 40, 40, "9", cb_n9),
	b8(Point(270, 480), 40, 40, "b8", cb_b8),
	b9(Point(330, 525), 50, 30, "b9", cb_b9),
	b10(Point(380, 115), 70, 35, "下一页", cb_b10),
	b11(Point(380, 115), 70, 35, "上一页", cb_b11),
	searchReturn2(Point(380, 115), 70, 35, "return", cb_searchReturn2),
	b12(Point(250, 195), 200, 50, "ALice", cb_b12),
	b13(Point(250, 255), 200, 50, "Bob", cb_b13),
	b14(Point(250, 315), 200, 50, "Carol", cb_b14),
	b15(Point(250, 175), 200, 50, "Grace", cb_b15),
	b16(Point(250, 250), 200, 50, "Hans", cb_b16),
	b17(Point(250, 130), 35, 35, "b17", cb_b17),
	b18(Point(250, 130), 35, 35, "b18", cb_b18),

	alice1(Point(265, 196), 30, 15, "ALice", cb_alice1),
	bob1(Point(265, 196), 30, 15, "Bob", cb_bob1),
	carol1(Point(265, 196), 30, 15, "Carol", cb_carol1),
	grace1(Point(265, 196), 30, 15, "Grace", cb_grace1),
	hans1(Point(265, 196), 30, 15, "Hans", cb_hans1),
	carol2(Point(295, 196), 30, 15, "Carol", cb_carol1),
	grace2(Point(295, 196), 30, 15, "Grace", cb_grace1),
	hans3(Point(325, 196), 30, 15, "Hans", cb_hans1),



	quit_button(Point(x_max() - 70, 0), 70, 20, "quit", cb_quit), button_pushed(false)
{
	tx2.set_font_size(15);
	tx2.set_font(2);
	tx2.set_color(FL_WHITE);
	tx4.set_font_size(8);
	tx4.set_font(1);
	tx4.set_color(FL_BLACK);
	tx3.set_font_size(15);
	tx3.set_font(1);
	tx3.set_color(FL_WHITE);
	tx1.set_font(3);
	tx1.set_color(FL_WHITE);
	tx1.set_font_size(30);
	attach(i1);
	attach(b1);
	attach(quit_button);


}
bool phone_window::wait_for_button()

{
	show();
	button_pushed = false;
#if 1
	// Simpler handler
	while (!button_pushed) Fl::wait();
	Fl::redraw();
#else
	// To handle the case where the user presses the X button in the window frame
	// to kill the application, change the condition to 0 to enable this branch.
	Fl::run();
#endif
	return button_pushed;
}
void phone_window::cb_a(Address, Address pw)     { reference_to<phone_window>(pw).au(); }
void phone_window::cb_b(Address, Address pw)     { reference_to<phone_window>(pw).bu(); }
void phone_window::cb_c(Address, Address pw)     { reference_to<phone_window>(pw).cu(); }
void phone_window::cb_d(Address, Address pw)     { reference_to<phone_window>(pw).du(); }
void phone_window::cb_e(Address, Address pw)     { reference_to<phone_window>(pw).eu(); }
void phone_window::cb_f(Address, Address pw)     { reference_to<phone_window>(pw).fu(); }
void phone_window::cb_g(Address, Address pw)     { reference_to<phone_window>(pw).gu(); }
void phone_window::cb_h(Address, Address pw)     { reference_to<phone_window>(pw).hu(); }
void phone_window::cb_i(Address, Address pw)     { reference_to<phone_window>(pw).iu(); }
void phone_window::cb_j(Address, Address pw)     { reference_to<phone_window>(pw).ju(); }
void phone_window::cb_k(Address, Address pw)     { reference_to<phone_window>(pw).ku(); }
void phone_window::cb_l(Address, Address pw)     { reference_to<phone_window>(pw).lu(); }
void phone_window::cb_m(Address, Address pw)     { reference_to<phone_window>(pw).mu(); }
void phone_window::cb_n(Address, Address pw)     { reference_to<phone_window>(pw).nu(); }
void phone_window::cb_o(Address, Address pw)     { reference_to<phone_window>(pw).ou(); }
void phone_window::cb_p(Address, Address pw)     { reference_to<phone_window>(pw).pu(); }
void phone_window::cb_q(Address, Address pw)     { reference_to<phone_window>(pw).qu(); }
void phone_window::cb_r(Address, Address pw)     { reference_to<phone_window>(pw).ru(); }
void phone_window::cb_s(Address, Address pw)     { reference_to<phone_window>(pw).su(); }
void phone_window::cb_t(Address, Address pw)     { reference_to<phone_window>(pw).tu(); }
void phone_window::cb_u(Address, Address pw)     { reference_to<phone_window>(pw).uu(); }
void phone_window::cb_v(Address, Address pw)     { reference_to<phone_window>(pw).vu(); }
void phone_window::cb_w(Address, Address pw)     { reference_to<phone_window>(pw).wu(); }
void phone_window::cb_x(Address, Address pw)     { reference_to<phone_window>(pw).xu(); }
void phone_window::cb_y(Address, Address pw)     { reference_to<phone_window>(pw).yu(); }
void phone_window::cb_z(Address, Address pw)     { reference_to<phone_window>(pw).zu(); }
void phone_window::cb_A(Address, Address pw)     { reference_to<phone_window>(pw).Au(); }
void phone_window::cb_B(Address, Address pw)     { reference_to<phone_window>(pw).Bu(); }
void phone_window::cb_C(Address, Address pw)     { reference_to<phone_window>(pw).Cu(); }
void phone_window::cb_D(Address, Address pw)     { reference_to<phone_window>(pw).Du(); }
void phone_window::cb_E(Address, Address pw)     { reference_to<phone_window>(pw).Eu(); }
void phone_window::cb_F(Address, Address pw)     { reference_to<phone_window>(pw).Fu(); }
void phone_window::cb_G(Address, Address pw)     { reference_to<phone_window>(pw).Gu(); }
void phone_window::cb_H(Address, Address pw)     { reference_to<phone_window>(pw).Hu(); }
void phone_window::cb_I(Address, Address pw)     { reference_to<phone_window>(pw).Iu(); }
void phone_window::cb_J(Address, Address pw)     { reference_to<phone_window>(pw).Ju(); }
void phone_window::cb_K(Address, Address pw)     { reference_to<phone_window>(pw).Ku(); }
void phone_window::cb_L(Address, Address pw)     { reference_to<phone_window>(pw).Lu(); }
void phone_window::cb_M(Address, Address pw)     { reference_to<phone_window>(pw).Mu(); }
void phone_window::cb_N(Address, Address pw)     { reference_to<phone_window>(pw).Nu(); }
void phone_window::cb_O(Address, Address pw)     { reference_to<phone_window>(pw).Ou(); }
void phone_window::cb_P(Address, Address pw)     { reference_to<phone_window>(pw).Pu(); }
void phone_window::cb_Q(Address, Address pw)     { reference_to<phone_window>(pw).Qu(); }
void phone_window::cb_R(Address, Address pw)     { reference_to<phone_window>(pw).Ru(); }
void phone_window::cb_S(Address, Address pw)     { reference_to<phone_window>(pw).Su(); }
void phone_window::cb_T(Address, Address pw)     { reference_to<phone_window>(pw).Tu(); }
void phone_window::cb_U(Address, Address pw)     { reference_to<phone_window>(pw).Uu(); }
void phone_window::cb_V(Address, Address pw)     { reference_to<phone_window>(pw).Vu(); }
void phone_window::cb_W(Address, Address pw)     { reference_to<phone_window>(pw).Wu(); }
void phone_window::cb_X(Address, Address pw)     { reference_to<phone_window>(pw).Xu(); }
void phone_window::cb_Y(Address, Address pw)     { reference_to<phone_window>(pw).Yu(); }
void phone_window::cb_Z(Address, Address pw)     { reference_to<phone_window>(pw).Zu(); }
void phone_window::cb_searchName(Address, Address pw)     { reference_to<phone_window>(pw).searchNameu(); }
void phone_window::cb_searchReturn(Address, Address pw)     { reference_to<phone_window>(pw).searchReturnu(); }
void phone_window::cb_searchReturn2(Address, Address pw)     { reference_to<phone_window>(pw).searchReturn2u(); }
void phone_window::cb_shutdown2(Address, Address pw)     { reference_to<phone_window>(pw).shutdown2u(); }


void phone_window::cb_alice1(Address, Address pw)     { reference_to<phone_window>(pw).alice1u(); }
void phone_window::cb_bob1(Address, Address pw)     { reference_to<phone_window>(pw).bob1u(); }
void phone_window::cb_carol1(Address, Address pw)     { reference_to<phone_window>(pw).carol1u(); }
void phone_window::cb_grace1(Address, Address pw)     { reference_to<phone_window>(pw).grace1u(); }
void phone_window::cb_hans1(Address, Address pw)     { reference_to<phone_window>(pw).hans1u(); }
void phone_window::cb_carol2(Address, Address pw)     { reference_to<phone_window>(pw).carol2u(); }
void phone_window::cb_grace2(Address, Address pw)     { reference_to<phone_window>(pw).grace2u(); }
void phone_window::cb_hans3(Address, Address pw)     { reference_to<phone_window>(pw).hans3u(); }
void phone_window::alice1u()
{
	zz = 1;
	if (b_alice1) {
		detach(alice1);
		b_alice1 = 0;
	}
	if (b_bob1) {
		detach(bob1);
		b_bob1 = 0;
	}
	if (b_carol1) {
		detach(carol1);
		b_carol1 = 0;
	}
	if (b_grace1) {
		detach(grace1);
		b_grace1 = 0;
	}
	if (b_hans1) {
		detach(hans1);
		b_hans1 = 0;
	}
	if (b_carol2) {
		detach(carol2);
		b_carol2 = 0;
	}
	if (b_grace2) {
		detach(grace2);
		b_grace2 = 0;
	}
	if (b_hans3) {
		detach(hans3);
		b_hans3 = 0;
	}
	if (b_alice1) {
		detach(alice1);
		b_alice1 = 0;
	}
	attach(toALice1); Sleep(500); wait();
	attach(toALice2); Sleep(500); wait();
	attach(toALice3); Sleep(500); wait();
	attach(toALice4); Sleep(500); wait();
	attach(toALice5); Sleep(500); wait();
	attach(toALice6); Sleep(500); wait();
	attach(toALice7); Sleep(500); wait();
	attach(c9); attach(b17); detach(b9);

	k4 = 1;
	while (k4 == 1) {
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;

		int m = t / 60 % 60;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string sss = "11111";
		sss.at(0) = h3;
		sss.at(1) = h4;
		sss.at(2) = ':';
		sss.at(3) = m3;
		sss.at(4) = m4;
		tx4.set_label(sss);
		tx4.set_color(FL_YELLOW);
		attach(tx4);

		wait();
		redraw();
	}
	redraw();
}
void phone_window::bob1u(){
	k2 = 0; k4 = 1;
	if (b_alice1) {
		detach(alice1);
		b_alice1 = 0;
	}
	if (b_bob1) {
		detach(bob1);
		b_bob1 = 0;
	}
	if (b_carol1) {
		detach(carol1);
		b_carol1 = 0;
	}
	if (b_grace1) {
		detach(grace1);
		b_grace1 = 0;
	}
	if (b_hans1) {
		detach(hans1);
		b_hans1 = 0;
	}
	if (b_carol2) {
		detach(carol2);
		b_carol2 = 0;
	}
	if (b_grace2) {
		detach(grace2);
		b_grace2 = 0;
	}
	if (b_hans3) {
		detach(hans3);
		b_hans3 = 0;
	}
	if (b_alice1) {
		detach(alice1);
		b_alice1 = 0;
	}
	zz = 2;
	attach(toBob1); Sleep(500); wait();
	attach(toBob2); Sleep(500); wait();
	attach(toBob3); Sleep(500); wait();
	attach(toBob4); Sleep(500); wait();
	attach(toBob5); Sleep(500); wait();
	attach(toBob6); Sleep(500); wait();
	attach(toBob7); Sleep(500); wait();
	attach(c10); attach(b17); detach(b9);
	redraw();

	while (k4 == 1) {
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;

		int m = t / 60 % 60;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string sss = "11111";
		sss.at(0) = h3;
		sss.at(1) = h4;
		sss.at(2) = ':';
		sss.at(3) = m3;
		sss.at(4) = m4;
		tx4.set_label(sss);
		tx4.set_color(FL_YELLOW);
		attach(tx4);

		wait();
		redraw();
	}
}



void phone_window::carol1u(){
	k2 = 0; k4 = 1;
	zz = 3; if (b_alice1) {
		detach(alice1);
		b_alice1 = 0;
	}
	if (b_bob1) {
		detach(bob1);
		b_bob1 = 0;
	}
	if (b_carol1) {
		detach(carol1);
		b_carol1 = 0;
	}
	if (b_grace1) {
		detach(grace1);
		b_grace1 = 0;
	}
	if (b_hans1) {
		detach(hans1);
		b_hans1 = 0;
	}
	if (b_carol2) {
		detach(carol2);
		b_carol2 = 0;
	}
	if (b_grace2) {
		detach(grace2);
		b_grace2 = 0;
	}
	if (b_hans3) {
		detach(hans3);
		b_hans3 = 0;
	}
	if (b_alice1) {
		detach(alice1);
		b_alice1 = 0;
	}
	attach(toCarol1); Sleep(500); wait();
	attach(toCarol2); Sleep(500); wait();
	attach(toCarol3); Sleep(500); wait();
	attach(toCarol4); Sleep(500); wait();
	attach(toCarol5); Sleep(500); wait();
	attach(toCarol6); Sleep(500); wait();
	attach(toCarol7); Sleep(500); wait();
	attach(c11); attach(b17); detach(b9);
	while (k4 == 1) {
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;

		int m = t / 60 % 60;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string sss = "11111";
		sss.at(0) = h3;
		sss.at(1) = h4;
		sss.at(2) = ':';
		sss.at(3) = m3;
		sss.at(4) = m4;
		tx4.set_label(sss);
		tx4.set_color(FL_YELLOW);
		attach(tx4);

		wait();
		redraw();
	}
	redraw();
}
void phone_window::carol2u(){
	k2 = 0; k4 = 1;
	zz = 3; if (b_alice1) {
		detach(alice1);
		b_alice1 = 0;
	}
	if (b_bob1) {
		detach(bob1);
		b_bob1 = 0;
	}
	if (b_carol1) {
		detach(carol1);
		b_carol1 = 0;
	}
	if (b_grace1) {
		detach(grace1);
		b_grace1 = 0;
	}
	if (b_hans1) {
		detach(hans1);
		b_hans1 = 0;
	}
	if (b_carol2) {
		detach(carol2);
		b_carol2 = 0;
	}
	if (b_grace2) {
		detach(grace2);
		b_grace2 = 0;
	}
	if (b_hans3) {
		detach(hans3);
		b_hans3 = 0;
	}
	if (b_alice1) {
		detach(alice1);
		b_alice1 = 0;
	}
	attach(toCarol1); Sleep(500); wait();
	attach(toCarol2); Sleep(500); wait();
	attach(toCarol3); Sleep(500); wait();
	attach(toCarol4); Sleep(500); wait();
	attach(toCarol5); Sleep(500); wait();
	attach(toCarol6); Sleep(500); wait();
	attach(toCarol7); Sleep(500); wait();
	attach(c11); attach(b17); detach(b9);
	while (k4 == 1) {
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;

		int m = t / 60 % 60;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string sss = "11111";
		sss.at(0) = h3;
		sss.at(1) = h4;
		sss.at(2) = ':';
		sss.at(3) = m3;
		sss.at(4) = m4;
		tx4.set_label(sss);
		tx4.set_color(FL_YELLOW);
		attach(tx4);

		wait();
		redraw();
	}
	redraw();
}
void phone_window::grace1u(){
	k2 = 0; k4 = 1;
	if (b_alice1) {
		detach(alice1);
		b_alice1 = 0;
	}
	if (b_bob1) {
		detach(bob1);
		b_bob1 = 0;
	}
	if (b_carol1) {
		detach(carol1);
		b_carol1 = 0;
	}
	if (b_grace1) {
		detach(grace1);
		b_grace1 = 0;
	}
	if (b_hans1) {
		detach(hans1);
		b_hans1 = 0;
	}
	if (b_carol2) {
		detach(carol2);
		b_carol2 = 0;
	}
	if (b_grace2) {
		detach(grace2);
		b_grace2 = 0;
	}
	if (b_hans3) {
		detach(hans3);
		b_hans3 = 0;
	}
	if (b_alice1) {
		detach(alice1);
		b_alice1 = 0;
	}
	zz = 4;
	attach(toGrace1); Sleep(500); wait();
	attach(toGrace2); Sleep(500); wait();
	attach(toGrace3); Sleep(500); wait();
	attach(toGrace4); Sleep(500); wait();
	attach(toGrace5); Sleep(500); wait();
	attach(toGrace6); Sleep(500); wait();
	attach(toGrace7); Sleep(500); wait();
	attach(toGrace8); Sleep(500); wait();
	attach(c12); attach(b18); detach(b9);
	while (k4 == 1) {
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;

		int m = t / 60 % 60;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string sss = "11111";
		sss.at(0) = h3;
		sss.at(1) = h4;
		sss.at(2) = ':';
		sss.at(3) = m3;
		sss.at(4) = m4;
		tx4.set_label(sss);
		tx4.set_color(FL_YELLOW);
		attach(tx4);

		wait();
		redraw();
	}
	detach(b16); redraw();
}
void phone_window::grace2u(){
	k2 = 0; k4 = 1;
	if (b_alice1) {
		detach(alice1);
		b_alice1 = 0;
	}
	if (b_bob1) {
		detach(bob1);
		b_bob1 = 0;
	}
	if (b_carol1) {
		detach(carol1);
		b_carol1 = 0;
	}
	if (b_grace1) {
		detach(grace1);
		b_grace1 = 0;
	}
	if (b_hans1) {
		detach(hans1);
		b_hans1 = 0;
	}
	if (b_carol2) {
		detach(carol2);
		b_carol2 = 0;
	}
	if (b_grace2) {
		detach(grace2);
		b_grace2 = 0;
	}
	if (b_hans3) {
		detach(hans3);
		b_hans3 = 0;
	}
	if (b_alice1) {
		detach(alice1);
		b_alice1 = 0;
	}
	zz = 4;
	attach(toGrace1); Sleep(500); wait();
	attach(toGrace2); Sleep(500); wait();
	attach(toGrace3); Sleep(500); wait();
	attach(toGrace4); Sleep(500); wait();
	attach(toGrace5); Sleep(500); wait();
	attach(toGrace6); Sleep(500); wait();
	attach(toGrace7); Sleep(500); wait();
	attach(toGrace8); Sleep(500); wait();
	attach(c12); attach(b18); detach(b9);
	while (k4 == 1) {
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;

		int m = t / 60 % 60;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string sss = "11111";
		sss.at(0) = h3;
		sss.at(1) = h4;
		sss.at(2) = ':';
		sss.at(3) = m3;
		sss.at(4) = m4;
		tx4.set_label(sss);
		tx4.set_color(FL_YELLOW);
		attach(tx4);

		wait();
		redraw();
	}
	detach(b16); redraw();
}
void phone_window::hans1u(){
	k2 = 0; k4 = 1;
	if (b_alice1) {
		detach(alice1);
		b_alice1 = 0;
	}
	if (b_bob1) {
		detach(bob1);
		b_bob1 = 0;
	}
	if (b_carol1) {
		detach(carol1);
		b_carol1 = 0;
	}
	if (b_grace1) {
		detach(grace1);
		b_grace1 = 0;
	}
	if (b_hans1) {
		detach(hans1);
		b_hans1 = 0;
	}
	if (b_carol2) {
		detach(carol2);
		b_carol2 = 0;
	}
	if (b_grace2) {
		detach(grace2);
		b_grace2 = 0;
	}
	if (b_hans3) {
		detach(hans3);
		b_hans3 = 0;
	}
	if (b_alice1) {
		detach(alice1);
		b_alice1 = 0;
	}
	zz = 5;
	attach(toHans1); Sleep(500); wait();
	attach(toHans2); Sleep(500); wait();
	attach(toHans3); Sleep(500); wait();
	attach(toHans4); Sleep(500); wait();
	attach(toHans5); Sleep(500); wait();
	attach(toHans6); Sleep(500); wait();
	attach(toHans7); Sleep(500); wait();
	attach(toHans8); Sleep(500); wait();
	attach(c13); attach(b18); detach(b9);
	while (k4 == 1) {
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;

		int m = t / 60 % 60;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string sss = "11111";
		sss.at(0) = h3;
		sss.at(1) = h4;
		sss.at(2) = ':';
		sss.at(3) = m3;
		sss.at(4) = m4;
		tx4.set_label(sss);
		tx4.set_color(FL_YELLOW);
		attach(tx4);

		wait();
		redraw();
	}
	detach(b15); redraw();
}
void phone_window::hans3u(){
	k2 = 0; k4 = 1;
	if (b_alice1) {
		detach(alice1);
		b_alice1 = 0;
	}
	if (b_bob1) {
		detach(bob1);
		b_bob1 = 0;
	}
	if (b_carol1) {
		detach(carol1);
		b_carol1 = 0;
	}
	if (b_grace1) {
		detach(grace1);
		b_grace1 = 0;
	}
	if (b_hans1) {
		detach(hans1);
		b_hans1 = 0;
	}
	if (b_carol2) {
		detach(carol2);
		b_carol2 = 0;
	}
	if (b_grace2) {
		detach(grace2);
		b_grace2 = 0;
	}
	if (b_hans3) {
		detach(hans3);
		b_hans3 = 0;
	}
	if (b_alice1) {
		detach(alice1);
		b_alice1 = 0;
	};
	zz = 5;
	attach(toHans1); Sleep(500); wait();
	attach(toHans2); Sleep(500); wait();
	attach(toHans3); Sleep(500); wait();
	attach(toHans4); Sleep(500); wait();
	attach(toHans5); Sleep(500); wait();
	attach(toHans6); Sleep(500); wait();
	attach(toHans7); Sleep(500); wait();
	attach(toHans8); Sleep(500); wait();
	attach(c13); attach(b18); detach(b9);
	while (k4 == 1) {
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;

		int m = t / 60 % 60;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string sss = "11111";
		sss.at(0) = h3;
		sss.at(1) = h4;
		sss.at(2) = ':';
		sss.at(3) = m3;
		sss.at(4) = m4;
		tx4.set_label(sss);
		tx4.set_color(FL_YELLOW);
		attach(tx4);

		wait();
		redraw();
	}
	detach(b15); redraw();
}

void phone_window::shutdown2u()
{
	detach(shutdown2); k = k2 = k3 = k4 = 0;
	attach(off2); Sleep(300); wait();
	attach(off3); Sleep(300); wait();
	attach(off4); Sleep(300); wait();
	attach(off5); Sleep(300); wait();
	attach(off6); Sleep(300); wait();
	attach(off7); Sleep(300); wait();
	attach(off8); Sleep(300); wait();
	attach(off9); Sleep(300); wait();
	attach(off10); Sleep(300); wait();
	attach(off11); Sleep(300); wait();
	attach(off12); Sleep(300); wait();
	attach(off13); Sleep(300); wait();
	attach(off14); Sleep(300); wait();
	attach(off15); Sleep(300); wait();
	attach(off16); Sleep(300); wait();
	attach(off17); Sleep(300); wait();
	attach(off18); Sleep(300); wait();
	attach(off19); Sleep(300); wait();
	attach(off20); Sleep(300); wait();
	attach(off21); Sleep(300); wait();
	attach(off22); Sleep(300); wait();
	attach(off23); Sleep(300); wait();
	attach(off24); Sleep(300); wait();
	attach(off25); Sleep(300); wait();
	attach(off26); Sleep(300); wait();
	attach(off27); Sleep(300); wait();
	attach(off28); Sleep(300); wait();
	attach(off29); Sleep(300); wait();
	attach(off30); Sleep(300); wait();
	attach(i1);
	detach(b6);
	attach(b1);
	redraw();
}
void phone_window::searchReturn2u()
{
	detach(bdelete);
	if (page == 0) {
		attach(b10);
		attach(c0);
		attach(b12);
		attach(b13);
		attach(b14);
		redraw();
	}
	else if (page == 1)
	{
		attach(b11);
		attach(c8);
		attach(b15);
		attach(b16);
		redraw();
	}
}
void phone_window::searchNameu(){
	attach(searchReturn2); attach(aftersearch);
	detach(bdelete);
	long int size = name.size();
	if (page == 0) {
		detach(b12); detach(b13); detach(b14); detach(b10);
	}
	else if (page == 1)
	{
		detach(b15); detach(b16); detach(b11);
	}
	switch (size) {
	case 0:

		attach(pleaseInput);
		redraw();
		break;
	case 1:
		switch (name[0]) {
		case 'A':
			attach(aftersearch); attach(alice1); b_alice1 = 1;
			sname.set_label("Alice"); attach(sname);
			redraw();
			break;
		case 'B':
			attach(aftersearch); attach(bob1); b_bob1 = 1;
			sname.set_label("Bob"); attach(sname);
			redraw();
			break;
		case 'C':
			attach(aftersearch); attach(carol1); b_carol1 = 1;
			sname.set_label("Carol"); attach(sname);
			redraw();
			break;
		case 'G':
			attach(aftersearch); attach(grace1); b_grace1 = 1;
			sname.set_label("Grace"); attach(sname);
			redraw();
			break;
		case 'H':
			attach(aftersearch); attach(hans1); b_hans1 = 1;
			sname.set_label("Hans"); attach(sname);

			redraw();
			break;
		case 'a':
			attach(aftersearch); attach(carol1); attach(grace2); attach(hans3);
			b_carol1 = 1; b_grace2 = 1; b_hans3 = 1;
			sname.set_label("Carol  Grace  Hans"); attach(sname);
			redraw();

			break;
		case 'c':
			attach(aftersearch); attach(alice1); attach(grace2);
			b_alice1 = 1; b_grace2 = 1;
			sname.set_label("Alice  Grace"); attach(sname);
			redraw(); break;
		case 'e':
			attach(aftersearch); attach(alice1); attach(grace2);
			b_alice1 = 1; b_grace2 = 1;
			sname.set_label("Alice  Grace"); attach(sname);
			redraw(); break;
		case 'i':
			attach(aftersearch); attach(alice1); b_alice1 = 1;
			sname.set_label("Alice"); attach(sname);
			redraw(); break;
		case 'l':
			attach(aftersearch); attach(alice1); b_alice1 = 1;
			sname.set_label("Alice"); attach(sname);
			redraw(); break;
		case 'n':
			attach(aftersearch); attach(hans1); b_hans1 = 1;
			sname.set_label("Hans"); attach(sname);
			redraw(); break;
		case 'o':
			attach(aftersearch); attach(bob1); attach(carol2); b_bob1 = 1; b_carol2 = 1;
			sname.set_label("Bob  Carol"); attach(sname);
			redraw(); break;
		case 'r':
			attach(aftersearch); attach(carol1); attach(grace2); b_carol1 = 1; b_grace2 = 1;
			sname.set_label("Carol  Grace"); attach(sname);
			redraw(); break;
		case 's':
			attach(aftersearch); attach(hans1); b_hans1 = 1;
			sname.set_label("Hans"); attach(sname);
			redraw(); break;
		default:
			attach(noResults); redraw();
			break;
		}

		detach(searchName);
		break;
	case 2:
		strname2.at(0) = name[0];
		strname2.at(1) = name[1];
		if (strname2 == "Al" || strname2 == "Ai" || strname2 == "Ac" || strname2 == "Ae" || strname2 == "li" || strname2 == "lc" || strname2 == "le" || strname2 == "ic" || strname2 == "ie")
		{
			attach(alice1); b_alice1 = 1;
			sname.set_label("Alice"); attach(sname); redraw();
		}

		else
			if (strname2 == "Bo" || strname2 == "Bb" || strname2 == "ob")
			{
				attach(bob1); b_bob1 = 1;
				sname.set_label("Bob"); attach(sname); redraw();
			}
			else if (strname2 == "Ca" || strname2 == "Cr" || strname2 == "Co" || strname2 == "Cl" || strname2 == "ar" || strname2 == "ao" || strname2 == "al" || strname2 == "ro" || strname2 == "rl" || strname2 == "ol")
			{
				attach(carol1); b_carol1 = 1;
				sname.set_label("Carol"); attach(sname); redraw();
			}

			else if (strname2 == "Gr" || strname2 == "Ga" || strname2 == "Gc" || strname2 == "ra" || strname2 == "rc" || strname2 == "re" || strname2 == "ac" || strname2 == "ae" || strname2 == "Ge")
			{
				attach(grace1); b_grace1 = 1;
				sname.set_label("Grace"); attach(sname); redraw();
			}
			else if (strname2 == "Ha" || strname2 == "Hn" || strname2 == "Hs" || strname2 == "an" || strname2 == "as" || strname2 == "ns")
			{
				attach(hans1); b_hans1 = 1;
				sname.set_label("Hans"); attach(sname); redraw();
			}
			else if (strname2 == "ce")
			{
				attach(alice1); attach(grace2); b_alice1 = 1; b_grace2 = 1;
				sname.set_label("Alice  Grace"); attach(sname); redraw();
			}
			else
			{
				attach(noResults); redraw();
			}
			detach(searchName);
			break;
	case 3:
		strname3.at(0) = name[0];
		strname3.at(1) = name[1];
		strname3.at(2) = name[2];
		if (strname3 == "Ali" || strname3 == "Alc" || strname3 == "Ale" || strname3 == "Aic" || strname3 == "Aie" || strname3 == "lic" || strname3 == "lie" || strname3 == "lce" || strname3 == "ice" || strname3 == "Ace")
		{
			attach(alice1); b_alice1 = 1;
			sname.set_label("Alice"); attach(sname); redraw();
		}
		else   if (strname3 == "Bob")
		{
			attach(bob1); b_bob1 = 1;
			sname.set_label("Bob"); attach(sname); redraw();
		}
		else  if (strname3 == "Han" || strname3 == "Has" || strname3 == "Hns" || strname3 == "ans")
		{
			attach(hans1); b_hans1 = 1;
			sname.set_label("Hans"); attach(sname); redraw();
		}
		else   if (strname3 == "Car" || strname3 == "Cao" || strname3 == "Cal" || strname3 == "Cro" || strname3 == "Crl" || strname3 == "Col" || strname3 == "aro" || strname3 == "arl" || strname3 == "aol" || strname3 == "rol")
		{
			attach(carol1); b_carol1 = 1;
			sname.set_label("Carol"); attach(sname); redraw();
		}

		else    if (strname3 == "Gra" || strname3 == "Grc" || strname3 == "Gre" || strname3 == "Gac" || strname3 == "Gae" || strname3 == "Gce" || strname3 == "rac" || strname3 == "rae" || strname3 == "rce" || strname3 == "ace")
		{
			attach(grace1); b_grace1 = 1;
			sname.set_label("Grace"); attach(sname); redraw();
		}

		else {
			attach(noResults);
			redraw();
		}

		detach(searchName);
		break;
	case 4:
		strname4.at(0) = name[0];
		strname4.at(1) = name[1];
		strname4.at(2) = name[2];
		strname4.at(3) = name[3];
		if (strname4 == "Alic" || strname4 == "Alce" || strname4 == "lice" || strname4 == "Aice" || strname4 == "Alie")
		{
			attach(alice1); b_alice1 = 1;
			sname.set_label("Alice"); attach(sname); redraw();
		}
		else  if (strname4 == "Caro" || strname4 == "Carl" || strname4 == "Caol" || strname4 == "Crol" || strname4 == "arol")
		{
			attach(carol1); b_carol1 = 1;
			sname.set_label("Carol"); attach(sname); redraw();
		}
		else   if (strname4 == "Grac" || strname4 == "Grae" || strname4 == "Grce" || strname4 == "Gace" || strname4 == "race")
		{
			attach(grace1); b_grace1 = 1;
			sname.set_label("Grace"); attach(sname); redraw();
		}
		else  if (strname4 == "Hans")
		{
			attach(hans1); b_hans1 = 1;
			sname.set_label("Hans"); attach(sname); redraw();
		}
		else
		{
			attach(noResults);
			redraw();
		}

		detach(searchName);
		break;
	case 5:
		strname5.at(0) = name[0];
		strname5.at(1) = name[1];
		strname5.at(2) = name[2];
		strname5.at(3) = name[3];
		strname5.at(4) = name[4];
		if (strname5 == "Alice") {
			attach(alice1); b_alice1 = 1;
			sname.set_label("Alice"); attach(sname); redraw();
		}

		else   if (strname5 == "Carol") {
			attach(carol1); b_carol1 = 1;
			sname.set_label("Carol"); attach(sname); redraw();
		}
		else   if (strname5 == "Grace") {
			attach(grace1); b_grace1 = 1;
			sname.set_label("Grace"); attach(sname); redraw();
		}

		else
		{
			attach(noResults); redraw();
		}
		detach(searchName);
		break;
	case 6:

		detach(searchName);
		attach(noResults);
		redraw();
		break;
	default:
		break;
	}
}
void phone_window::searchReturnu(){
	detach(bdelete);
	if (b_alice1) {
		detach(alice1);
		b_alice1 = 0;
	}
	if (b_bob1) {
		detach(bob1);
		b_bob1 = 0;
	}
	if (b_carol1) {
		detach(carol1);
		b_carol1 = 0;
	}
	if (b_grace1) {
		detach(grace1);
		b_grace1 = 0;
	}
	if (b_hans1) {
		detach(hans1);
		b_hans1 = 0;
	}
	if (b_carol2) {
		detach(carol2);
		b_carol2 = 0;
	}
	if (b_grace2) {
		detach(grace2);
		b_grace2 = 0;
	}
	if (b_hans3) {
		detach(hans3);
		b_hans3 = 0;
	}
	if (b_alice1) {
		detach(alice1);
		b_alice1 = 0;
	}
	name.resize(0);
	letter1.set_label("");
	letter2.set_label("");
	letter3.set_label("");
	letter4.set_label("");
	letter5.set_label("");
	letter6.set_label("");
	detach(letter1); detach(letter2); detach(letter3); detach(letter4); detach(letter5); detach(letter6);
	if (page == 0) {
		detach(KEYBOARD1);
		detach(KEYBOARD2);
		detach(KEYBOARD3);
		detach(KEYBOARD4);
		detach(KEYBOARD5);
		attach(c0);
	}
	else if (page == 1){
		detach(keyboardn1);
		detach(keyboardn2);
		detach(keyboardn3);
		detach(keyboardn4);
		detach(keyboardn5);
		attach(c8);
	}
	detach(tran);
	detach(key_A);
	detach(key_B);
	detach(key_C);
	detach(key_D);
	detach(key_E);
	detach(key_F);
	detach(key_G);
	detach(key_H);
	detach(key_I);
	detach(key_J);
	detach(key_K);
	detach(key_L);
	detach(key_M);
	detach(key_N);
	detach(key_O);
	detach(key_P);
	detach(key_Q);
	detach(key_R);
	detach(key_S);
	detach(key_T);
	detach(key_U);
	detach(key_V);
	detach(key_W);
	detach(key_X);
	detach(key_Y);
	detach(key_Z);

	redraw();
}

void phone_window::au()
{
	numberOfletters++;
	name.push_back('a');
	if (numberOfletters == 1) letter1.set_label("a");
	else if (numberOfletters == 2) letter2.set_label("a");
	else if (numberOfletters == 3) letter3.set_label("a");
	else if (numberOfletters == 4) letter4.set_label("a");
	else if (numberOfletters == 5) letter5.set_label("a");
	else if (numberOfletters == 6) letter6.set_label("a");
	else{};
	redraw();

}


void phone_window::bu()     {
	numberOfletters++; name.push_back('b');
	if (numberOfletters == 1) letter1.set_label("b");
	else if (numberOfletters == 2) letter2.set_label("b");
	else if (numberOfletters == 3) letter3.set_label("b");
	else if (numberOfletters == 4) letter4.set_label("b");
	else if (numberOfletters == 5) letter5.set_label("b");
	else if (numberOfletters == 6) letter6.set_label("b");
	else{};
	attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::cu()     {
	numberOfletters++; name.push_back('c'); if (numberOfletters == 1) letter1.set_label("c");
	else if (numberOfletters == 2) letter2.set_label("c");
	else if (numberOfletters == 3) letter3.set_label("c");
	else if (numberOfletters == 4) letter4.set_label("c");
	else if (numberOfletters == 5) letter5.set_label("c");
	else if (numberOfletters == 6) letter6.set_label("c");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::du()     {
	numberOfletters++; name.push_back('d'); if (numberOfletters == 1) letter1.set_label("d");
	else if (numberOfletters == 2) letter2.set_label("d");
	else if (numberOfletters == 3) letter3.set_label("d");
	else if (numberOfletters == 4) letter4.set_label("d");
	else if (numberOfletters == 5) letter5.set_label("d");
	else if (numberOfletters == 6) letter6.set_label("d");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::eu()     {
	numberOfletters++; name.push_back('e'); if (numberOfletters == 1) letter1.set_label("e");
	else if (numberOfletters == 2) letter2.set_label("e");
	else if (numberOfletters == 3) letter3.set_label("e");
	else if (numberOfletters == 4) letter4.set_label("e");
	else if (numberOfletters == 5) letter5.set_label("e");
	else if (numberOfletters == 6) letter6.set_label("e");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::fu()     {
	numberOfletters++; name.push_back('f'); if (numberOfletters == 1) letter1.set_label("e");
	else if (numberOfletters == 2) letter2.set_label("f");
	else if (numberOfletters == 3) letter3.set_label("f");
	else if (numberOfletters == 4) letter4.set_label("f");
	else if (numberOfletters == 5) letter5.set_label("f");
	else if (numberOfletters == 6) letter6.set_label("f");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::gu()     {
	numberOfletters++; name.push_back('g'); if (numberOfletters == 1) letter1.set_label("g");
	else if (numberOfletters == 2) letter2.set_label("g");
	else if (numberOfletters == 3) letter3.set_label("g");
	else if (numberOfletters == 4) letter4.set_label("g");
	else if (numberOfletters == 5) letter5.set_label("g");
	else if (numberOfletters == 6) letter6.set_label("g");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::hu()     {
	numberOfletters++; name.push_back('h'); if (numberOfletters == 1) letter1.set_label("h");
	else if (numberOfletters == 2) letter2.set_label("h");
	else if (numberOfletters == 3) letter3.set_label("h");
	else if (numberOfletters == 4) letter4.set_label("h");
	else if (numberOfletters == 5) letter5.set_label("h");
	else if (numberOfletters == 6) letter6.set_label("h");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::iu()     {
	numberOfletters++; name.push_back('i'); if (numberOfletters == 1) letter1.set_label("i");
	else if (numberOfletters == 2) letter2.set_label("i");
	else if (numberOfletters == 3) letter3.set_label("i");
	else if (numberOfletters == 4) letter4.set_label("i");
	else if (numberOfletters == 5) letter5.set_label("i");
	else if (numberOfletters == 6) letter6.set_label("i");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::ju()     {
	numberOfletters++; name.push_back('j'); if (numberOfletters == 1) letter1.set_label("j");
	else if (numberOfletters == 2) letter2.set_label("j");
	else if (numberOfletters == 3) letter3.set_label("j");
	else if (numberOfletters == 4) letter4.set_label("j");
	else if (numberOfletters == 5) letter5.set_label("j");
	else if (numberOfletters == 6) letter6.set_label("j");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::ku()     {
	numberOfletters++; name.push_back('k'); if (numberOfletters == 1) letter1.set_label("k");
	else if (numberOfletters == 2) letter2.set_label("k");
	else if (numberOfletters == 3) letter3.set_label("k");
	else if (numberOfletters == 4) letter4.set_label("k");
	else if (numberOfletters == 5) letter5.set_label("k");
	else if (numberOfletters == 6) letter6.set_label("k");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::lu()     {
	numberOfletters++; name.push_back('l'); if (numberOfletters == 1) letter1.set_label("l");
	else if (numberOfletters == 2) letter2.set_label("l");
	else if (numberOfletters == 3) letter3.set_label("l");
	else if (numberOfletters == 4) letter4.set_label("l");
	else if (numberOfletters == 5) letter5.set_label("l");
	else if (numberOfletters == 6) letter6.set_label("l");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::mu()     {
	numberOfletters++; name.push_back('m'); if (numberOfletters == 1) letter1.set_label("m");
	else if (numberOfletters == 2) letter2.set_label("m");
	else if (numberOfletters == 3) letter3.set_label("m");
	else if (numberOfletters == 4) letter4.set_label("m");
	else if (numberOfletters == 5) letter5.set_label("m");
	else if (numberOfletters == 6) letter6.set_label("m");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::nu()     {
	numberOfletters++; name.push_back('n'); if (numberOfletters == 1) letter1.set_label("n");
	else if (numberOfletters == 2) letter2.set_label("n");
	else if (numberOfletters == 3) letter3.set_label("n");
	else if (numberOfletters == 4) letter4.set_label("n");
	else if (numberOfletters == 5) letter5.set_label("n");
	else if (numberOfletters == 6) letter6.set_label("n");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::ou()     {
	numberOfletters++; name.push_back('o'); if (numberOfletters == 1) letter1.set_label("o");
	else if (numberOfletters == 2) letter2.set_label("o");
	else if (numberOfletters == 3) letter3.set_label("o");
	else if (numberOfletters == 4) letter4.set_label("o");
	else if (numberOfletters == 5) letter5.set_label("o");
	else if (numberOfletters == 6) letter6.set_label("o");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::pu()     {
	numberOfletters++; name.push_back('p'); if (numberOfletters == 1) letter1.set_label("p");
	else if (numberOfletters == 2) letter2.set_label("p");
	else if (numberOfletters == 3) letter3.set_label("p");
	else if (numberOfletters == 4) letter4.set_label("p");
	else if (numberOfletters == 5) letter5.set_label("p");
	else if (numberOfletters == 6) letter6.set_label("p");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::qu()     {
	numberOfletters++; name.push_back('q'); if (numberOfletters == 1) letter1.set_label("q");
	else if (numberOfletters == 2) letter2.set_label("q");
	else if (numberOfletters == 3) letter3.set_label("q");
	else if (numberOfletters == 4) letter4.set_label("q");
	else if (numberOfletters == 5) letter5.set_label("q");
	else if (numberOfletters == 6) letter6.set_label("q");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::ru()     {
	numberOfletters++; name.push_back('r'); if (numberOfletters == 1) letter1.set_label("r");
	else if (numberOfletters == 2) letter2.set_label("r");
	else if (numberOfletters == 3) letter3.set_label("r");
	else if (numberOfletters == 4) letter4.set_label("r");
	else if (numberOfletters == 5) letter5.set_label("r");
	else if (numberOfletters == 6) letter6.set_label("r");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::su()     {
	numberOfletters++; name.push_back('s'); if (numberOfletters == 1) letter1.set_label("s");
	else if (numberOfletters == 2) letter2.set_label("s");
	else if (numberOfletters == 3) letter3.set_label("s");
	else if (numberOfletters == 4) letter4.set_label("s");
	else if (numberOfletters == 5) letter5.set_label("s");
	else if (numberOfletters == 6) letter6.set_label("s");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::tu()     {
	numberOfletters++; name.push_back('t'); if (numberOfletters == 1) letter1.set_label("t");
	else if (numberOfletters == 2) letter2.set_label("t");
	else if (numberOfletters == 3) letter3.set_label("t");
	else if (numberOfletters == 4) letter4.set_label("t");
	else if (numberOfletters == 5) letter5.set_label("t");
	else if (numberOfletters == 6) letter6.set_label("t");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::uu()     {
	numberOfletters++; name.push_back('u'); if (numberOfletters == 1) letter1.set_label("u");
	else if (numberOfletters == 2) letter2.set_label("u");
	else if (numberOfletters == 3) letter3.set_label("u");
	else if (numberOfletters == 4) letter4.set_label("u");
	else if (numberOfletters == 5) letter5.set_label("u");
	else if (numberOfletters == 6) letter6.set_label("u");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::vu()     {
	numberOfletters++; name.push_back('v'); if (numberOfletters == 1) letter1.set_label("v");
	else if (numberOfletters == 2) letter2.set_label("v");
	else if (numberOfletters == 3) letter3.set_label("v");
	else if (numberOfletters == 4) letter4.set_label("v");
	else if (numberOfletters == 5) letter5.set_label("v");
	else if (numberOfletters == 6) letter6.set_label("v");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::wu()     {
	numberOfletters++; name.push_back('w'); if (numberOfletters == 1) letter1.set_label("w");
	else if (numberOfletters == 2) letter2.set_label("w");
	else if (numberOfletters == 3) letter3.set_label("w");
	else if (numberOfletters == 4) letter4.set_label("w");
	else if (numberOfletters == 5) letter5.set_label("w");
	else if (numberOfletters == 6) letter6.set_label("w");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::xu()     {
	numberOfletters++; name.push_back('x'); if (numberOfletters == 1) letter1.set_label("x");
	else if (numberOfletters == 2) letter2.set_label("x");
	else if (numberOfletters == 3) letter3.set_label("x");
	else if (numberOfletters == 4) letter4.set_label("x");
	else if (numberOfletters == 5) letter5.set_label("x");
	else if (numberOfletters == 6) letter6.set_label("x");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::yu()     {
	numberOfletters++; name.push_back('y'); if (numberOfletters == 1) letter1.set_label("y");
	else if (numberOfletters == 2) letter2.set_label("y");
	else if (numberOfletters == 3) letter3.set_label("y");
	else if (numberOfletters == 4) letter4.set_label("y");
	else if (numberOfletters == 5) letter5.set_label("y");
	else if (numberOfletters == 6) letter6.set_label("y");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::zu()     {
	numberOfletters++; name.push_back('z'); if (numberOfletters == 1) letter1.set_label("z");
	else if (numberOfletters == 2) letter2.set_label("z");
	else if (numberOfletters == 3) letter3.set_label("z");
	else if (numberOfletters == 4) letter4.set_label("z");
	else if (numberOfletters == 5) letter5.set_label("z");
	else if (numberOfletters == 6) letter6.set_label("z");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Au()     {
	numberOfletters++; name.push_back('A');
	if (numberOfletters == 1) letter1.set_label("A");
	else if (numberOfletters == 2) letter2.set_label("A");
	else if (numberOfletters == 3) letter3.set_label("A");
	else if (numberOfletters == 4) letter4.set_label("A");
	else if (numberOfletters == 5) letter5.set_label("A");
	else if (numberOfletters == 6) letter6.set_label("A");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Bu()     {
	numberOfletters++; name.push_back('B');
	if (numberOfletters == 1) letter1.set_label("B");
	else if (numberOfletters == 2) letter2.set_label("B");
	else if (numberOfletters == 3) letter3.set_label("B");
	else if (numberOfletters == 4) letter4.set_label("B");
	else if (numberOfletters == 5) letter5.set_label("B");
	else if (numberOfletters == 6) letter6.set_label("B");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Cu()     {
	numberOfletters++; name.push_back('C');
	if (numberOfletters == 1) letter1.set_label("C");
	else if (numberOfletters == 2) letter2.set_label("C");
	else if (numberOfletters == 3) letter3.set_label("C");
	else if (numberOfletters == 4) letter4.set_label("C");
	else if (numberOfletters == 5) letter5.set_label("C");
	else if (numberOfletters == 6) letter6.set_label("C");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Du()     {
	numberOfletters++; name.push_back('D');
	if (numberOfletters == 1) letter1.set_label("D");
	else if (numberOfletters == 2) letter2.set_label("D");
	else if (numberOfletters == 3) letter3.set_label("D");
	else if (numberOfletters == 4) letter4.set_label("D");
	else if (numberOfletters == 5) letter5.set_label("D");
	else if (numberOfletters == 6) letter6.set_label("D");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Eu()     {
	numberOfletters++; name.push_back('E');
	if (numberOfletters == 1) letter1.set_label("E");
	else if (numberOfletters == 2) letter2.set_label("E");
	else if (numberOfletters == 3) letter3.set_label("E");
	else if (numberOfletters == 4) letter4.set_label("E");
	else if (numberOfletters == 5) letter5.set_label("E");
	else if (numberOfletters == 6) letter6.set_label("E");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Fu()     {
	numberOfletters++; name.push_back('F');
	if (numberOfletters == 1) letter1.set_label("F");
	else if (numberOfletters == 2) letter2.set_label("F");
	else if (numberOfletters == 3) letter3.set_label("F");
	else if (numberOfletters == 4) letter4.set_label("F");
	else if (numberOfletters == 5) letter5.set_label("F");
	else if (numberOfletters == 6) letter6.set_label("F");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Gu()     {
	numberOfletters++; name.push_back('G');
	if (numberOfletters == 1) letter1.set_label("G");
	else if (numberOfletters == 2) letter2.set_label("G");
	else if (numberOfletters == 3) letter3.set_label("G");
	else if (numberOfletters == 4) letter4.set_label("G");
	else if (numberOfletters == 5) letter5.set_label("G");
	else if (numberOfletters == 6) letter6.set_label("G");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Hu()     {
	numberOfletters++; name.push_back('H');
	if (numberOfletters == 1) letter1.set_label("H");
	else if (numberOfletters == 2) letter2.set_label("H");
	else if (numberOfletters == 3) letter3.set_label("H");
	else if (numberOfletters == 4) letter4.set_label("H");
	else if (numberOfletters == 5) letter5.set_label("H");
	else if (numberOfletters == 6) letter6.set_label("H");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Iu()     {
	numberOfletters++; name.push_back('I');
	if (numberOfletters == 1) letter1.set_label("I");
	else if (numberOfletters == 2) letter2.set_label("I");
	else if (numberOfletters == 3) letter3.set_label("I");
	else if (numberOfletters == 4) letter4.set_label("I");
	else if (numberOfletters == 5) letter5.set_label("I");
	else if (numberOfletters == 6) letter6.set_label("I");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Ju()     {
	numberOfletters++; name.push_back('J');
	if (numberOfletters == 1) letter1.set_label("J");
	else if (numberOfletters == 2) letter2.set_label("J");
	else if (numberOfletters == 3) letter3.set_label("J");
	else if (numberOfletters == 4) letter4.set_label("J");
	else if (numberOfletters == 5) letter5.set_label("J");
	else if (numberOfletters == 6) letter6.set_label("J");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Ku()     {
	numberOfletters++; name.push_back('K');
	if (numberOfletters == 1) letter1.set_label("K");
	else if (numberOfletters == 2) letter2.set_label("K");
	else if (numberOfletters == 3) letter3.set_label("K");
	else if (numberOfletters == 4) letter4.set_label("K");
	else if (numberOfletters == 5) letter5.set_label("K");
	else if (numberOfletters == 6) letter6.set_label("K");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Lu()     {
	numberOfletters++; name.push_back('L');
	if (numberOfletters == 1) letter1.set_label("L");
	else if (numberOfletters == 2) letter2.set_label("L");
	else if (numberOfletters == 3) letter3.set_label("L");
	else if (numberOfletters == 4) letter4.set_label("L");
	else if (numberOfletters == 5) letter5.set_label("L");
	else if (numberOfletters == 6) letter6.set_label("L");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Mu()     {
	numberOfletters++; name.push_back('M');
	if (numberOfletters == 1) letter1.set_label("M");
	else if (numberOfletters == 2) letter2.set_label("M");
	else if (numberOfletters == 3) letter3.set_label("M");
	else if (numberOfletters == 4) letter4.set_label("M");
	else if (numberOfletters == 5) letter5.set_label("M");
	else if (numberOfletters == 6) letter6.set_label("M");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Nu()     {
	numberOfletters++; name.push_back('N');
	if (numberOfletters == 1) letter1.set_label("N");
	else if (numberOfletters == 2) letter2.set_label("N");
	else if (numberOfletters == 3) letter3.set_label("N");
	else if (numberOfletters == 4) letter4.set_label("N");
	else if (numberOfletters == 5) letter5.set_label("N");
	else if (numberOfletters == 6) letter6.set_label("N");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Ou()     {
	numberOfletters++; name.push_back('O');
	if (numberOfletters == 1) letter1.set_label("O");
	else if (numberOfletters == 2) letter2.set_label("O");
	else if (numberOfletters == 3) letter3.set_label("O");
	else if (numberOfletters == 4) letter4.set_label("O");
	else if (numberOfletters == 5) letter5.set_label("O");
	else if (numberOfletters == 6) letter6.set_label("O");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Pu()     {
	numberOfletters++; name.push_back('P');
	if (numberOfletters == 1) letter1.set_label("P");
	else if (numberOfletters == 2) letter2.set_label("P");
	else if (numberOfletters == 3) letter3.set_label("P");
	else if (numberOfletters == 4) letter4.set_label("P");
	else if (numberOfletters == 5) letter5.set_label("P");
	else if (numberOfletters == 6) letter6.set_label("P");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Qu()     {
	numberOfletters++; name.push_back('Q');
	if (numberOfletters == 1) letter1.set_label("Q");
	else if (numberOfletters == 2) letter2.set_label("Q");
	else if (numberOfletters == 3) letter3.set_label("Q");
	else if (numberOfletters == 4) letter4.set_label("Q");
	else if (numberOfletters == 5) letter5.set_label("Q");
	else if (numberOfletters == 6) letter6.set_label("Q");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Ru()     {
	numberOfletters++; name.push_back('R');
	if (numberOfletters == 1) letter1.set_label("R");
	else if (numberOfletters == 2) letter2.set_label("R");
	else if (numberOfletters == 3) letter3.set_label("R");
	else if (numberOfletters == 4) letter4.set_label("R");
	else if (numberOfletters == 5) letter5.set_label("R");
	else if (numberOfletters == 6) letter6.set_label("R");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Su()     {
	numberOfletters++; name.push_back('S');
	if (numberOfletters == 1) letter1.set_label("S");
	else if (numberOfletters == 2) letter2.set_label("S");
	else if (numberOfletters == 3) letter3.set_label("S");
	else if (numberOfletters == 4) letter4.set_label("S");
	else if (numberOfletters == 5) letter5.set_label("S");
	else if (numberOfletters == 6) letter6.set_label("S");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Tu()     {
	numberOfletters++; name.push_back('T');
	if (numberOfletters == 1) letter1.set_label("T");
	else if (numberOfletters == 2) letter2.set_label("T");
	else if (numberOfletters == 3) letter3.set_label("T");
	else if (numberOfletters == 4) letter4.set_label("T");
	else if (numberOfletters == 5) letter5.set_label("T");
	else if (numberOfletters == 6) letter6.set_label("T");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Uu()     {
	numberOfletters++; name.push_back('U');
	if (numberOfletters == 1) letter1.set_label("U");
	else if (numberOfletters == 2) letter2.set_label("U");
	else if (numberOfletters == 3) letter3.set_label("U");
	else if (numberOfletters == 4) letter4.set_label("U");
	else if (numberOfletters == 5) letter5.set_label("U");
	else if (numberOfletters == 6) letter6.set_label("U");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Vu()     {
	numberOfletters++; name.push_back('V');
	if (numberOfletters == 1) letter1.set_label("V");
	else if (numberOfletters == 2) letter2.set_label("V");
	else if (numberOfletters == 3) letter3.set_label("V");
	else if (numberOfletters == 4) letter4.set_label("V");
	else if (numberOfletters == 5) letter5.set_label("V");
	else if (numberOfletters == 6) letter6.set_label("V");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Wu()     {
	numberOfletters++; name.push_back('W');
	if (numberOfletters == 1) letter1.set_label("W");
	else if (numberOfletters == 2) letter2.set_label("W");
	else if (numberOfletters == 3) letter3.set_label("W");
	else if (numberOfletters == 4) letter4.set_label("W");
	else if (numberOfletters == 5) letter5.set_label("W");
	else if (numberOfletters == 6) letter6.set_label("W");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Xu()     {
	numberOfletters++; name.push_back('X');
	if (numberOfletters == 1) letter1.set_label("X");
	else if (numberOfletters == 2) letter2.set_label("X");
	else if (numberOfletters == 3) letter3.set_label("X");
	else if (numberOfletters == 4) letter4.set_label("X");
	else if (numberOfletters == 5) letter5.set_label("X");
	else if (numberOfletters == 6) letter6.set_label("X");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Yu()     {
	numberOfletters++; name.push_back('Y');
	if (numberOfletters == 1) letter1.set_label("Y");
	else if (numberOfletters == 2) letter2.set_label("Y");
	else if (numberOfletters == 3) letter3.set_label("Y");
	else if (numberOfletters == 4) letter4.set_label("Y");
	else if (numberOfletters == 5) letter5.set_label("Y");
	else if (numberOfletters == 6) letter6.set_label("Y");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}
void phone_window::Zu()     {
	numberOfletters++; name.push_back('Z');
	if (numberOfletters == 1) letter1.set_label("Z");
	else if (numberOfletters == 2) letter2.set_label("Z");
	else if (numberOfletters == 3) letter3.set_label("Z");
	else if (numberOfletters == 4) letter4.set_label("Z");
	else if (numberOfletters == 5) letter5.set_label("Z");
	else if (numberOfletters == 6) letter6.set_label("Z");
	else{}; attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	redraw();
}




void phone_window::cb_bdelete(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).bdeleteu();

}
void phone_window::bdeleteu(){

	if (numberOfletters >= 1){
		name.pop_back();
		switch (numberOfletters) {
		case 1:
			detach(letter1);
			break;
		case 2:
			detach(letter2);
			break;
		case 3:
			detach(letter3);
			break;
		case 4:
			detach(letter4);
			break;
		case 5:
			detach(letter5);
			break;
		case 6:
			detach(letter6);
			break;
		default:
			break;
		}
		numberOfletters--;
	}
	redraw();
}



void phone_window::cb_start(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).start();

}
void phone_window::cb_b10(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).bu10();

}
void phone_window::cb_b11(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).bu11();

}
void phone_window::cb_b9(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).bu9();

}
void phone_window::cb_shutdown(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).shutdown();

}
void phone_window::cb_screen(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).screen();
}

void phone_window::cb_start1(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).start1();

}
void phone_window::cb_quit(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).quit();

}
void phone_window::cb_return1(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).return1();

}
void phone_window::cb_return2(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).return2();

}
void phone_window::cb_emergency(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).emergency();

}
void phone_window::cb_n0(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).num0();

}

void phone_window::cb_search(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).searchu();

}
void phone_window::cb_tran(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).tranu();

}

void phone_window::searchu(){
	attach(bdelete);
	if (b_alice1) {
		detach(alice1);
		b_alice1 = 0;
	}
	if (b_bob1) {
		detach(bob1);
		b_bob1 = 0;
	}
	if (b_carol1) {
		detach(carol1);
		b_carol1 = 0;
	}
	if (b_grace1) {
		detach(grace1);
		b_grace1 = 0;
	}
	if (b_hans1) {
		detach(hans1);
		b_hans1 = 0;
	}
	if (b_carol2) {
		detach(carol2);
		b_carol2 = 0;
	}
	if (b_grace2) {
		detach(grace2);
		b_grace2 = 0;
	}
	if (b_hans3) {
		detach(hans3);
		b_hans3 = 0;
	}
	if (b_alice1) {
		detach(alice1);
		b_alice1 = 0;
	}
	numberOfletters = 0;
	name.resize(0);
	sname.set_label(" ");
	attach(searchName);
	letter1.set_label("");
	letter2.set_label("");
	letter3.set_label("");
	letter4.set_label("");
	letter5.set_label("");
	letter6.set_label("");
	attach(searchReturn);
	attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
	if (page == 0){

		attach(KEYBOARD1); Sleep(500); wait();
		attach(KEYBOARD2); Sleep(500); wait();
		attach(KEYBOARD3); Sleep(500); wait();
		attach(KEYBOARD4); Sleep(500); wait();
		attach(KEYBOARD5); Sleep(500); wait();
	}
	else if (page == 1)
	{

		attach(keyboardn1); Sleep(500); wait();
		attach(keyboardn2); Sleep(500); wait();
		attach(keyboardn3); Sleep(500); wait();
		attach(keyboardn4); Sleep(500); wait();
		attach(keyboardn5); Sleep(500); wait();
	}
	attach(tran);
	attach(key_A);
	attach(key_B);
	attach(key_C);
	attach(key_D);
	attach(key_E);
	attach(key_F);
	attach(key_G);
	attach(key_H);
	attach(key_I);
	attach(key_J);
	attach(key_K);
	attach(key_L);
	attach(key_M);
	attach(key_N);
	attach(key_O);
	attach(key_P);
	attach(key_Q);
	attach(key_R);
	attach(key_S);
	attach(key_T);
	attach(key_U);
	attach(key_V);
	attach(key_W);
	attach(key_X);
	attach(key_Y);
	attach(key_Z);
	redraw();
}

void phone_window::tranu(){
	static int tra = 0;
	if (tra == 0) {
		tra = 1;

		detach(key_A);
		detach(key_B);
		detach(key_C);
		detach(key_D);
		detach(key_E);
		detach(key_F);
		detach(key_G);
		detach(key_H);
		detach(key_I);
		detach(key_J);
		detach(key_K);
		detach(key_L);
		detach(key_M);
		detach(key_N);
		detach(key_O);
		detach(key_P);
		detach(key_Q);
		detach(key_R);
		detach(key_S);
		detach(key_T);
		detach(key_U);
		detach(key_V);
		detach(key_W);
		detach(key_X);
		detach(key_Y);
		detach(key_Z);
		attach(key_a);
		attach(key_b);
		attach(key_c);
		attach(key_d);
		attach(key_e);
		attach(key_f);
		attach(key_g);
		attach(key_h);
		attach(key_i);
		attach(key_j);
		attach(key_k);
		attach(key_l);
		attach(key_m);
		attach(key_n);
		attach(key_o);
		attach(key_p);
		attach(key_q);
		attach(key_r);
		attach(key_s);
		attach(key_t);
		attach(key_u);
		attach(key_v);
		attach(key_w);
		attach(key_x);
		attach(key_y);
		attach(key_z);
		if (page == 0) {
			detach(KEYBOARD1);
			detach(KEYBOARD2);
			detach(KEYBOARD3);
			detach(KEYBOARD4);
			detach(KEYBOARD5);
			attach(keyboard);
		}
		else if (page == 1)
		{
			detach(keyboardn1);
			detach(keyboardn2);
			detach(keyboardn3);
			detach(keyboardn4);
			detach(keyboardn5);
			attach(keyboardn);
		}
		attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
		redraw();
	}
	else
	{
		tra = 0;
		attach(key_A);
		attach(key_B);
		attach(key_C);
		attach(key_D);
		attach(key_E);
		attach(key_F);
		attach(key_G);
		attach(key_H);
		attach(key_I);
		attach(key_J);
		attach(key_K);
		attach(key_L);
		attach(key_M);
		attach(key_N);
		attach(key_O);
		attach(key_P);
		attach(key_Q);
		attach(key_R);
		attach(key_S);
		attach(key_T);
		attach(key_U);
		attach(key_V);
		attach(key_W);
		attach(key_X);
		attach(key_Y);
		attach(key_Z);
		detach(key_a);
		detach(key_b);
		detach(key_c);
		detach(key_d);
		detach(key_e);
		detach(key_f);
		detach(key_g);
		detach(key_h);
		detach(key_i);
		detach(key_j);
		detach(key_k);
		detach(key_l);
		detach(key_m);
		detach(key_n);
		detach(key_o);
		detach(key_p);
		detach(key_q);
		detach(key_r);
		detach(key_s);
		detach(key_t);
		detach(key_u);
		detach(key_v);
		detach(key_w);
		detach(key_x);
		detach(key_y);
		detach(key_z);

		attach(KEYBOARD5);
		detach(keyboard);
		attach(letter1); attach(letter2); attach(letter3); attach(letter4); attach(letter5); attach(letter6);
		redraw();
	}
}
void phone_window::cb_b8(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).bu8();

}
void phone_window::cb_b12(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).bu12();

}
void phone_window::bu12(){
	zz = 1;

	attach(toALice1); Sleep(500); wait();
	attach(toALice2); Sleep(500); wait();
	attach(toALice3); Sleep(500); wait();
	attach(toALice4); Sleep(500); wait();
	attach(toALice5); Sleep(500); wait();
	attach(toALice6); Sleep(500); wait();
	attach(toALice7); Sleep(500); wait();
	attach(c9); attach(b17); detach(b9);
	detach(b13); detach(b14); detach(b12);
	k4 = 1;
	while (k4 == 1) {
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;

		int m = t / 60 % 60;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string sss = "11111";
		sss.at(0) = h3;
		sss.at(1) = h4;
		sss.at(2) = ':';
		sss.at(3) = m3;
		sss.at(4) = m4;
		tx4.set_label(sss);
		tx4.set_color(FL_YELLOW);
		attach(tx4);

		wait();
		redraw();
	}
	redraw();
}
void phone_window::cb_b13(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).bu13();

}
void phone_window::bu13(){
	k2 = 0; k4 = 1;

	zz = 2;
	attach(toBob1); Sleep(500); wait();
	attach(toBob2); Sleep(500); wait();
	attach(toBob3); Sleep(500); wait();
	attach(toBob4); Sleep(500); wait();
	attach(toBob5); Sleep(500); wait();
	attach(toBob6); Sleep(500); wait();
	attach(toBob7); Sleep(500); wait();
	attach(c10); detach(b13); attach(b17); detach(b9);
	detach(b12); detach(b14); redraw();

	while (k4 == 1) {
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;

		int m = t / 60 % 60;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string sss = "11111";
		sss.at(0) = h3;
		sss.at(1) = h4;
		sss.at(2) = ':';
		sss.at(3) = m3;
		sss.at(4) = m4;
		tx4.set_label(sss);
		tx4.set_color(FL_YELLOW);
		attach(tx4);

		wait();
		redraw();
	}
}
void phone_window::cb_b14(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).bu14();

}
void phone_window::bu14(){
	k2 = 0; k4 = 1;
	zz = 3;
	attach(toCarol1); Sleep(500); wait();
	attach(toCarol2); Sleep(500); wait();
	attach(toCarol3); Sleep(500); wait();
	attach(toCarol4); Sleep(500); wait();
	attach(toCarol5); Sleep(500); wait();
	attach(toCarol6); Sleep(500); wait();
	attach(toCarol7); Sleep(500); wait();
	attach(c11); detach(b13); detach(b12); detach(b14); attach(b17); detach(b9);
	while (k4 == 1) {
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;

		int m = t / 60 % 60;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string sss = "11111";
		sss.at(0) = h3;
		sss.at(1) = h4;
		sss.at(2) = ':';
		sss.at(3) = m3;
		sss.at(4) = m4;
		tx4.set_label(sss);
		tx4.set_color(FL_YELLOW);
		attach(tx4);

		wait();
		redraw();
	}
	redraw();
}
void phone_window::cb_b15(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).bu15();

}
void phone_window::bu15(){
	k2 = 0; k4 = 1;
	zz = 4;
	attach(toGrace1); Sleep(500); wait();
	attach(toGrace2); Sleep(500); wait();
	attach(toGrace3); Sleep(500); wait();
	attach(toGrace4); Sleep(500); wait();
	attach(toGrace5); Sleep(500); wait();
	attach(toGrace6); Sleep(500); wait();
	attach(toGrace7); Sleep(500); wait();
	attach(toGrace8); Sleep(500); wait();
	attach(c12); detach(b15); attach(b18); detach(b9);
	while (k4 == 1) {
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;

		int m = t / 60 % 60;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string sss = "11111";
		sss.at(0) = h3;
		sss.at(1) = h4;
		sss.at(2) = ':';
		sss.at(3) = m3;
		sss.at(4) = m4;
		tx4.set_label(sss);
		tx4.set_color(FL_YELLOW);
		attach(tx4);

		wait();
		redraw();
	}
	detach(b16); redraw();
}
void phone_window::cb_b16(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).bu16();

}
void phone_window::bu16(){
	k2 = 0; k4 = 1;
	zz = 5;
	attach(toHans1); Sleep(500); wait();
	attach(toHans2); Sleep(500); wait();
	attach(toHans3); Sleep(500); wait();
	attach(toHans4); Sleep(500); wait();
	attach(toHans5); Sleep(500); wait();
	attach(toHans6); Sleep(500); wait();
	attach(toHans7); Sleep(500); wait();
	attach(toHans8); Sleep(500); wait();
	attach(c13); detach(b16); attach(b18); detach(b9);
	while (k4 == 1) {
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;

		int m = t / 60 % 60;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string sss = "11111";
		sss.at(0) = h3;
		sss.at(1) = h4;
		sss.at(2) = ':';
		sss.at(3) = m3;
		sss.at(4) = m4;
		tx4.set_label(sss);
		tx4.set_color(FL_YELLOW);
		attach(tx4);

		wait();
		redraw();
	}
	detach(b15); redraw();
}
void phone_window::cb_b17(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).bu17();

}
void phone_window::bu17(){
	k4 = 0;
	k3 = 1;

	if (zz == 1) {
		attach(ar1); Sleep(500); wait();
		attach(ar2); Sleep(500); wait();
		attach(ar3); Sleep(500); wait();
		attach(ar4); Sleep(500); wait();
		attach(ar5); Sleep(500); wait();
		attach(ar6); Sleep(500); wait();
		attach(c0);
		attach(b12);
		attach(b13);
		attach(b14);
		attach(b9);
		detach(b17);
		redraw();
	}
	else if (zz == 2)
	{
		attach(br1); Sleep(500); wait();
		attach(br2); Sleep(500); wait();

		attach(br4); Sleep(500); wait();
		attach(br5); Sleep(500); wait();
		attach(br6); Sleep(500); wait();
		attach(c0);
		attach(b12);
		attach(b13);
		attach(b14);
		attach(b9);
		detach(b17);
		redraw();
	}
	else if (zz == 3)
	{
		{
			attach(cr1); Sleep(500); wait();
			attach(cr2); Sleep(500); wait();
			attach(cr3); Sleep(500); wait();
			attach(cr4); Sleep(500); wait();
			attach(cr5); Sleep(500); wait();
			attach(cr6); Sleep(500); wait();
			attach(c0);
			attach(b12);
			attach(b13);
			attach(b14);
			attach(b9);
			detach(b17);
			redraw();
		}
	}
	else{
		attach(c0);
		attach(b12);
		attach(b13);
		attach(b14);
		attach(b9);
		detach(b17);
		redraw();

	}

	while (k3 == 1) {
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;

		int m = t / 60 % 60;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string sss = "11111";
		sss.at(0) = h3;
		sss.at(1) = h4;
		sss.at(2) = ':';
		sss.at(3) = m3;
		sss.at(4) = m4;
		tx4.set_label(sss);
		tx4.set_color(FL_BLUE);
		attach(tx4);

		wait();
		redraw();
	}


}
void phone_window::cb_b18(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).bu18();

}
void phone_window::bu18(){
	k4 = 0; k3 = 1;


	if (zz == 4)
	{
		attach(gr1); Sleep(500); wait();
		attach(gr2); Sleep(500); wait();
		attach(gr3); Sleep(500); wait();
		attach(gr4); Sleep(500); wait();
		attach(gr5); Sleep(500); wait();
		attach(gr6); Sleep(500); wait();
	}
	if (zz == 5)
	{
		attach(hr1); Sleep(500); wait();
		attach(hr2); Sleep(500); wait();
		attach(hr3); Sleep(500); wait();
		attach(hr4); Sleep(500); wait();
		attach(hr5); Sleep(500); wait();

	}

	attach(c8);
	attach(b15);
	detach(b18);
	attach(b9);
	attach(b16);

	while (k3 == 1) {
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;

		int m = t / 60 % 60;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string sss = "11111";
		sss.at(0) = h3;
		sss.at(1) = h4;
		sss.at(2) = ':';
		sss.at(3) = m3;
		sss.at(4) = m4;
		tx4.set_label(sss);
		tx4.set_color(FL_BLUE);
		attach(tx4);

		wait();
		redraw();
	}

	redraw();
}
void phone_window::bu8(){

	k = 0;
	z = 1;
	attach(search);
	attach(c14); Sleep(100); wait();
	attach(c1); Sleep(100); wait();
	attach(c2); Sleep(100); wait();
	attach(c3); Sleep(100); wait();
	attach(c4); Sleep(100); wait();
	attach(c5); Sleep(100); wait();
	attach(c6); Sleep(100); wait();
	attach(c7); Sleep(100); wait();
	attach(c0);
	attach(b12); attach(b13); attach(b14);
	j = 2;

	attach(b10);
	attach(b9);


	k2 = 1;
	while (k2 == 1) {
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;

		int m = t / 60 % 60;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string sss = "11111";
		sss.at(0) = h3;
		sss.at(1) = h4;
		sss.at(2) = ':';
		sss.at(3) = m3;
		sss.at(4) = m4;
		tx4.set_label(sss);
		tx4.set_color(FL_BLUE);
		attach(tx4);

		wait();
		redraw();
	}
	redraw();

}
void phone_window::bu9(){
	k2 = 0;
	k3 = 0; k4 = 0;
	if (z == 1){
		attach(ltom1); Sleep(500); wait();
		attach(ltom2); Sleep(500); wait();
		attach(ltom3); Sleep(500); wait();
		attach(ltom4); Sleep(500); wait();
		attach(ltom5); Sleep(500); wait();
		attach(ltom6); Sleep(500); wait();
		attach(ltom7); Sleep(500); wait();
		attach(light); Sleep(1500); wait();
		attach(m1);
		detach(c0);

		detach(b9);
		detach(b10);

		detach(b12);
		detach(b13);
		detach(b14);
	}
	if (z == 2){
		attach(ntom1); Sleep(500); wait();
		attach(ntom2); Sleep(500); wait();
		attach(ntom3); Sleep(500); wait();
		attach(ntom4); Sleep(500); wait();
		attach(ntom5); Sleep(500); wait();
		attach(ntom6); Sleep(500); wait();
		attach(light); Sleep(1500); wait();
		attach(m1);
		detach(c8);
		detach(b9);
		detach(b11);

		detach(b15);
		detach(b16);

	}
	j = 1;
	redraw();
	k = 1;
	bbb = 0; aaa = 0; k2 = 1;
	while (k == 1) {
		if (aaa == 1) {
			attach(middle1); redraw();
		}
		if (bbb == 1) {
			attach(m1); k = 0; redraw();
		}
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;

		int m = t / 60 % 60;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string sss = "11111";
		sss.at(0) = h3;
		sss.at(1) = h4;
		sss.at(2) = ':';
		sss.at(3) = m3;
		sss.at(4) = m4;
		tx4.set_label(sss);
		tx4.set_color(FL_BLACK);
		attach(tx4);

		wait();
		redraw();
	}
	detach(tx4);
	redraw();
	bbb = 0;
	z = 1;
	if (bbb == 1){
		attach(search);
		attach(c14); Sleep(100); wait();
		attach(c1); Sleep(100); wait();
		attach(c2); Sleep(100); wait();
		attach(c3); Sleep(100); wait();
		attach(c4); Sleep(100); wait();
		attach(c5); Sleep(100); wait();
		attach(c6); Sleep(100); wait();
		attach(c7); Sleep(100); wait();
		attach(c0);
		attach(b12); attach(b13); attach(b14);
		j = 2;

		attach(b10);
		attach(b9);
	}



	while (k2 == 1) {
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;

		int m = t / 60 % 60;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string sss = "11111";
		sss.at(0) = h3;
		sss.at(1) = h4;
		sss.at(2) = ':';
		sss.at(3) = m3;
		sss.at(4) = m4;
		tx4.set_label(sss);
		tx4.set_color(FL_BLUE);
		attach(tx4);

		wait();
		redraw();
	}
	redraw();
}
void phone_window::bu10(){
	page = 1;
	k2 = 0;
	attach(lton1); Sleep(700); wait();
	attach(lton2); Sleep(700); wait();
	attach(lton3); Sleep(700); wait();
	attach(lton4); Sleep(700); wait();

	attach(c8);
	z = 2;
	detach(b10);
	detach(b12);
	detach(b13);
	detach(b14);
	attach(b15);
	attach(b16);
	attach(b11);

	redraw();
	k2 = 1;
	k = 1;
	while (k2 == 1) {
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;

		int m = t / 60 % 60;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string sss = "11111";
		sss.at(0) = h3;
		sss.at(1) = h4;
		sss.at(2) = ':';
		sss.at(3) = m3;
		sss.at(4) = m4;
		tx4.set_label(sss);
		tx4.set_color(FL_BLUE);

		attach(tx4);

		wait();
		redraw();
	}
}
void phone_window::bu11(){
	page = 0;
	attach(ntol1); Sleep(700); wait();
	attach(ntol2); Sleep(700); wait();
	attach(ntol3); Sleep(700); wait();
	attach(ntol4); Sleep(700); wait();
	attach(ntol5); Sleep(700); wait();
	attach(ntol6); Sleep(700); wait();

	detach(b11);
	z = 1;
	attach(b10);
	attach(b12);
	attach(b13);
	attach(b14);
	detach(b15);
	detach(b16);
	attach(c0);

	redraw();
}
void phone_window::num0(){
	number++;
	if (number == 1) {
		attach(l1);
		redraw();
	}
	else if (number == 2)
	{
		attach(l2); redraw();
	}
	else if (number == 3)
	{
		attach(l3); redraw();
	}
	else if (number == 4)
	{
		attach(l4);
		redraw();
		wait();
		Sleep(1000000);
		attach(l5);
		redraw();
	}
	else{}
	if (number == 4) {
		number = 0; ans = 0;
	}
}
void phone_window::cb_n1(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).num1();

}
void phone_window::num1(){
	number++;

	if (number == 1) {
		attach(l1); redraw(); ans++;
	}
	else if (number == 2)
	{
		attach(l2); redraw();
	}
	else if (number == 3)
	{
		attach(l3); redraw();
	}
	else if (number == 4)
	{
		attach(l4);
		redraw();
		wait();
		Delay(1000000);
		attach(l5);
		redraw();
	}
	else{}
	if (number == 4) {
		number = 0; ans = 0;
	}
}
void phone_window::cb_n2(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).num2();

}
void phone_window::num2(){
	number++;
	if (number == 1) {
		attach(l1); redraw();
	}
	else if (number == 2)
	{
		attach(l2); redraw(); ans++;
	}
	else if (number == 3)
	{
		attach(l3); redraw();
	}
	else if (number == 4)
	{
		attach(l4);
		redraw();
		wait();
		Sleep(1000000);
		attach(l5);
		redraw();
	}
	else{}
	if (number == 4) {
		number = 0; ans = 0;
	}
}
void phone_window::cb_n3(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).num3();

}
void phone_window::num3(){
	number++;
	if (number == 1) {
		attach(l1); redraw();
	}
	else if (number == 2)
	{
		attach(l2); redraw();
	}
	else if (number == 3)
	{
		attach(l3); redraw(); ans++;
	}
	else if (number == 4)
	{
		attach(l4);
		redraw();
		wait();
		Sleep(1000000);
		attach(l5);
		redraw();
	}
	else{}
	if (number == 4) {
		number = 0; ans = 0;
	}
}
void phone_window::cb_n4(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).num4();

}
void phone_window::num4(){
	number++;
	if (number == 1) {
		attach(l1); redraw();
	}
	else if (number == 2)
	{
		attach(l2); redraw();
	}
	else if (number == 3)
	{
		attach(l3); redraw();
	}
	else if (number == 4 && ans == 3)
	{
		k3 = 0;
		detach(tx4);
		attach(l4);
		redraw();
		wait();
		Sleep(300000);
		redraw();
		attach(j0);
		Sleep(50); wait();

		attach(j1);
		Sleep(50);
		wait();
		attach(j2);
		Sleep(50);
		wait();
		attach(j3);
		Sleep(50);
		wait();
		attach(j4);
		Sleep(50);
		wait();
		attach(j5);
		Sleep(50);
		wait();
		attach(j6);
		Sleep(50);
		wait();
		attach(j7);
		Sleep(50);
		wait();
		attach(j8);

		Sleep(100); wait();
		attach(j9);

		Sleep(100); wait();
		attach(m1);

		j = 1;//锁屏
		detach(n1); detach(n2); detach(n3); detach(n4); detach(n5); detach(n6);
		detach(n0); detach(n7); detach(n8); detach(n9); detach(b3);
		q = 0; detach(b2);
		detach(tx1); detach(tx2); detach(tx3);
		k2 = 1;
		k3 = 0;
		k = 1;
		aaa = 0;
		bbb = 0;
		while (k == 1) {
			if (aaa == 1) {
				attach(middle1); redraw();
			}
			if (bbb == 1) {
				attach(m1); k = 0; redraw();
			}
			time_t t = time(&t);
			int h = (t / 3600 % 24 + 8) % 24;
			int m = t / 60 % 60;
			int h1 = h / 10;
			int h2 = h % 10;
			int m1 = m / 10;
			int m2 = m % 10;
			char h3 = '0' + h1;
			char h4 = '0' + h2;
			char m3 = '0' + m1;
			char m4 = '0' + m2;
			string sss = "11111";
			sss.at(0) = h3;
			sss.at(1) = h4;
			sss.at(2) = ':';
			sss.at(3) = m3;
			sss.at(4) = m4;
			tx4.set_label(sss);
			tx4.set_color(FL_BLACK);
			attach(tx4);

			wait(); Sleep(5000);
			redraw();
		}
		redraw();
		detach(tx4);

		z = 1;
		if (k == 0)
		{
			attach(search);
			attach(c14); Sleep(100); wait();
			attach(c1); Sleep(100); wait();
			attach(c2); Sleep(100); wait();
			attach(c3); Sleep(100); wait();
			attach(c4); Sleep(100); wait();
			attach(c5); Sleep(100); wait();
			attach(c6); Sleep(100); wait();
			attach(c7); Sleep(100); wait();
			attach(c0);
			attach(b12); attach(b13); attach(b14);
			j = 2;

			attach(b10);
			attach(b9);
		}



		while (k2 == 1) {
			time_t t = time(&t);
			int h = (t / 3600 % 24 + 8) % 24;

			int m = t / 60 % 60;
			int h1 = h / 10;
			int h2 = h % 10;
			int m1 = m / 10;
			int m2 = m % 10;
			char h3 = '0' + h1;
			char h4 = '0' + h2;
			char m3 = '0' + m1;
			char m4 = '0' + m2;
			string sss = "11111";
			sss.at(0) = h3;
			sss.at(1) = h4;
			sss.at(2) = ':';
			sss.at(3) = m3;
			sss.at(4) = m4;
			tx4.set_label(sss);
			tx4.set_color(FL_BLUE);
			attach(tx4);

			wait();
			redraw();
		}
		redraw();
	}
	else{}
	if (number == 4) {
		number = 0; ans = 0;
	}
}
void phone_window::cb_n5(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).num5();

}
void phone_window::num5(){
	number++;
	if (number == 1) {
		attach(l1); redraw();
	}
	else if (number == 2)
	{
		attach(l2); redraw();
	}
	else if (number == 3)
	{
		attach(l3); redraw();
	}
	else if (number == 4)
	{
		attach(l4);
		redraw();
		wait();
		Sleep(1000000);
		attach(l5);
		redraw();
	}
	else{}
	if (number == 4) {
		number = 0; ans = 0;
	}
}
void phone_window::cb_n6(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).num6();

}
void phone_window::num6(){
	number++;
	if (number == 1) {
		attach(l1); redraw();
	}
	else if (number == 2)
	{
		attach(l2); redraw();
	}
	else if (number == 3)
	{
		attach(l3); redraw();
	}
	else if (number == 4)
	{
		attach(l4);
		redraw();
		wait();
		Sleep(1000000);
		attach(l5);
		redraw();
	}
	else{}
	if (number == 4) {
		number = 0; ans = 0;
	}
}
void phone_window::cb_n7(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).num7();

}
void phone_window::num7(){
	number++;
	if (number == 1) {
		attach(l1); redraw();
	}
	else if (number == 2)
	{
		attach(l2); redraw();
	}
	else if (number == 3)
	{
		attach(l3); redraw();
	}
	else if (number == 4)
	{
		attach(l4);
		redraw();
		wait();
		Sleep(1000000);
		attach(l5);
		redraw();
	}
	else{}
	if (number == 4) {
		number = 0; ans = 0;
	}
}
void phone_window::cb_n8(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).num8();

}
void phone_window::num8(){
	number++;
	if (number == 1) {
		attach(l1); redraw();
	}
	else if (number == 2)
	{
		attach(l2); redraw();
	}
	else if (number == 3)
	{
		attach(l3); redraw();
	}
	else if (number == 4)
	{
		attach(l4);
		redraw();
		wait();
		Sleep(1000000);
		attach(l5);
		redraw();
	}
	else{}
	if (number == 4) {
		number = 0; ans = 0;
	}
}
void phone_window::cb_n9(Address, Address pw)     // "the usual"
{
	reference_to<phone_window>(pw).num9();

}
void phone_window::num9(){
	number++;
	if (number == 1) {
		attach(l1); redraw();
	}
	else if (number == 2)
	{
		attach(l2); redraw();
	}
	else if (number == 3)
	{
		attach(l3); redraw();
	}
	else if (number == 4)
	{
		attach(l4);
		redraw();
		wait();
		Sleep(1000000);
		attach(l5);
		redraw();
	}
	else{}
	if (number == 4) {
		number = 0; ans = 0;
	}
}

void phone_window::screen(){
	static int i = 1;
	if (i == 1) {
		if (j == 1){
			attach(j10); Sleep(10000); wait();
			attach(j11); Sleep(10000); wait();
			attach(j12); Sleep(10000); wait();
			attach(j13); Sleep(10000); wait();
			attach(j14); Sleep(10000); wait();
			attach(i1);

			q = 0;
			redraw();
			i = 0;
		}
		else{
			attach(i1);

			q = 0;
			redraw();
			i = 0;
		}
	}
	else  if (i == 0) {
		if (j == 1) {
			i = 1;
			detach(i1); Sleep(10000); wait();
			detach(j14); Sleep(10000); wait();
			detach(j13); Sleep(10000); wait();
			detach(j12); Sleep(10000); wait();
			detach(j11); Sleep(10000); wait();
			detach(j10); Sleep(10000); wait();

			redraw();
		}
		else
		{

			detach(i1);
			redraw();
			i = 1;
		}
	}
}
void phone_window::shutdown(){
	q = 0;
	detach(tx1);
	detach(tx2);
	detach(tx3);

	attach(off1);
	attach(shutdown2);
	redraw();
}
void phone_window::emergency(){


	attach(p3);
	detach(tx1);
	detach(tx2);
	detach(tx3);
	attach(b5);
	detach(b3);
	redraw();
}
void phone_window::return2(){
	attach(n0);
	attach(n1);
	attach(n2);
	attach(n3);
	attach(n4);
	attach(n5);
	attach(n6);
	attach(n7);
	attach(n8);
	attach(n9);
	detach(p3);
	attach(p2);
	attach(b3);
	detach(b5);
	redraw();
}
void phone_window::return1(){
	q = 1;
	detach(p3);
	attach(p1);
	while (q == 1) {
		detach(p2);
		time_t t = time(&t);

		int h = (t / 3600 % 24 + 8) % 24;
		int s = t % 60;
		int m = t / 60 % 60;
		int s1 = s / 10;
		int s2 = s % 10;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char s3 = '0' + s1;
		char s4 = '0' + s2;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string ss = "11111111";
		ss.at(0) = h3;
		ss.at(1) = h4;
		ss.at(2) = ':';
		ss.at(3) = m3;
		ss.at(4) = m4;
		ss.at(5) = ':';
		ss.at(6) = s3;
		ss.at(7) = s4;
		int day = t / (24 * 3600) % 7;
		string Dayy;
		switch (day) {
		case 0:
			Dayy = "Thursday";
			break;
		case 1:
			Dayy = "Friday";
			break;
		case 2:
			Dayy = "Saturday";
			break;
		case 3:
			Dayy = "Sunday";
			break;
		case 4:
			Dayy = "Monday";
			break;
		case 5:
			Dayy = "Tuesday";
			break;
		case 6:
			Dayy = "Wednesday";
			break;
		default:
			break;
		}



		struct tm timeinfo;
		time_t now = time(0);
		char timE[80];
		localtime_s(&timeinfo, &now);
		strftime(timE, 80, "%Y-%m-%d\n", &timeinfo);
		tx1.set_label(ss);
		tx2.set_label(Dayy);
		tx2.set_label(timE);
		attach(tx1);
		tx2.set_label(Dayy);
		attach(tx2);
		attach(tx3);
		wait();
		Sleep(30000);
		redraw();
	}
	redraw();
}
void phone_window::quit(){
	q = 0;
	k = 2; k2 = 0; k3 = 0; k4 = 0;
	aaa = 0; bbb = 0;
	button_pushed = true;
	hide();
}
void phone_window::start1(){
	attach(j15); Sleep(100); wait();
	attach(j16); Sleep(100); wait();
	attach(j17); Sleep(100); wait();
	attach(j18); Sleep(100); wait();
	attach(j19); Sleep(100); wait();
	attach(j20); Sleep(100); wait();
	attach(j21); Sleep(100); wait();
	attach(j22); Sleep(100); wait();
	attach(j23); Sleep(100); wait();

	attach(p2);
	q = 0;
	detach(tx1);
	detach(tx2);
	detach(tx3);

	attach(b3);


	attach(n0);
	attach(n1);
	attach(n2);
	attach(n3);
	attach(n4);
	attach(n5);
	attach(n6);
	attach(n7);
	attach(n8);
	attach(n9);
	k3 = 1;
	aaa = 0;
	bbb = 0;
	while (k3 == 1) {

		if (aaa == 1) {
			attach(middle2); redraw();
		}
		if (bbb == 1) {
			attach(emergencym1); Delay(1000); wait();
			attach(emergencym2); Delay(1000); wait();
			attach(emergencym3); Delay(1000); wait();
			attach(emergencym4); Delay(1000); wait();
			attach(emergencym5); Delay(1000); wait();
			detach(b3);

			detach(n0);
			detach(n1);
			detach(n2);
			detach(n3);
			detach(n4);
			detach(n5);
			detach(n6);
			detach(n7);
			detach(n8);
			detach(n9);

			k3 = 0; attach(p3);
			detach(tx1);
			detach(tx2);
			detach(tx3);
			attach(b5);
			detach(b3);
			redraw();
		}
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;

		int m = t / 60 % 60;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string sss = "11111";
		sss.at(0) = h3;
		sss.at(1) = h4;
		sss.at(2) = ':';
		sss.at(3) = m3;
		sss.at(4) = m4;
		tx4.set_label(sss);
		tx4.set_color(FL_RED);
		attach(tx4);

		wait();
		redraw();
	}
	redraw();
}
void phone_window::start(){

	wait(); q = 1;
	Sleep(1000000);
	attach(i2);
	detach(b1);

	attach(b6);
	redraw();
	wait();
	Sleep(2000000);
	detach(i2);
	attach(on1); Sleep(60000); wait();
	attach(on2); Sleep(60000); wait();
	attach(on3); Sleep(60000); wait();
	attach(on4); Sleep(60000); wait();
	attach(on5); Sleep(60000); wait();
	attach(on6); Sleep(60000); wait();
	attach(on7); Sleep(60000); wait();
	attach(on8); Sleep(60000); wait();
	attach(on9); Sleep(60000); wait();
	attach(on10); Sleep(60000); wait();
	attach(on11); Sleep(60000); wait();
	attach(on12); Sleep(60000); wait();
	attach(on13); Sleep(60000); wait();
	attach(on14); Sleep(60000); wait();
	attach(on15); Sleep(60000); wait();
	attach(on16); Sleep(60000); wait();
	attach(on17); Sleep(60000); wait();
	attach(on18); Sleep(60000); wait();
	attach(on19); Sleep(60000); wait();
	attach(on20); Sleep(60000); wait();
	attach(on21); Sleep(60000); wait();
	attach(on22); Sleep(60000); wait();
	attach(on23); Sleep(60000); wait();
	attach(on24); Sleep(60000); wait();
	attach(on25); Sleep(60000); wait();
	attach(on26); Sleep(60000); wait();
	attach(on27); Sleep(60000); wait();
	attach(on28); Sleep(60000); wait();
	attach(on29); Sleep(60000); wait();
	attach(on30); Sleep(60000); wait();
	attach(on31); Sleep(60000); wait();
	attach(on32); Sleep(60000); wait();
	attach(on33); Sleep(60000); wait();
	attach(on34); Sleep(60000); wait();
	attach(on35); Sleep(60000); wait();
	attach(on36); Sleep(60000); wait();
	attach(on37); Sleep(60000); wait();
	attach(on38); Sleep(60000); wait(); Sleep(200000); wait();
	attach(p1);
	attach(tx1);
	attach(tx2);
	attach(tx3);
	attach(b2);

	attach(b7);
	while (q == 1) {
		time_t t = time(&t);
		int h = (t / 3600 % 24 + 8) % 24;
		int s = t % 60;
		int m = t / 60 % 60;
		int s1 = s / 10;
		int s2 = s % 10;
		int h1 = h / 10;
		int h2 = h % 10;
		int m1 = m / 10;
		int m2 = m % 10;
		char s3 = '0' + s1;
		char s4 = '0' + s2;
		char h3 = '0' + h1;
		char h4 = '0' + h2;
		char m3 = '0' + m1;
		char m4 = '0' + m2;
		string ss = "11111111";
		ss.at(0) = h3;
		ss.at(1) = h4;
		ss.at(2) = ':';
		ss.at(3) = m3;
		ss.at(4) = m4;
		ss.at(5) = ':';
		ss.at(6) = s3;
		ss.at(7) = s4;
		int day = t / (24 * 3600) % 7;
		string Day;
		switch (day) {
		case 0:
			Day = "Thursday";
			break;
		case 1:
			Day = "Friday";
			break;
		case 2:
			Day = "Saturday";
			break;
		case 3:
			Day = "Sunday";
			break;
		case 4:
			Day = "Monday";
			break;
		case 5:
			Day = "Tuesday";
			break;
		case 6:
			Day = "Wednesday";
			break;
		default:
			break;
		}

		/*struct tm* timeinfo;
		char timE[80];
		timeinfo = localtime(&t);
		strftime(timE, 80, "%Y-%m-%d\n", timeinfo);
		*/
		struct tm timeinfo;
		time_t now = time(0);
		char timE[80];
		localtime_s(&timeinfo, &now);
		strftime(timE, 80, "%Y-%m-%d\n", &timeinfo);
		tx1.set_label(ss);
		tx2.set_label(Day);
		tx3.set_label(timE);
		attach(tx1);
		attach(tx2);
		attach(tx3);
		wait();
		Sleep(3000);
		redraw();
	}
	redraw();
}

int main() {


	phone_window *win = new phone_window({ 800, 100 }, 600, 700, "phone");
	win->begin();
	EnterButton *eBtn = new EnterButton(270, 600, 40, 40, "");


	win->end();
	win->show();

	return gui_main();
}




