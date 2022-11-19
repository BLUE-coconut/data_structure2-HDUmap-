#pragma once
#include"Configure.h"
#include<conio.h>
class Window
{
public:
	Window(int w, int h, int flag);
	void set_window_title(const std::string& title);
	int exec();
	//窗口操作
	static int width();
	static int height();
	static void clear();
	//运行BeginBatchDraw后，所有的绘图都不再显示在屏幕上，而是在内存中进行;直到碰到EndBatchDraw，之前所有在内存中绘图的成品将一并展示在屏幕中;从而避免闪屏。
	static void benginDraw();
	static void flushDraw();
	static void endDraw();

	//按键和鼠标操作
	inline static bool hasMsg() { return peekmessage(&m_msg, EM_MOUSE | EM_KEY); }
	inline static const ExMessage& getMsg() { return m_msg; }


private:
	HWND m_handle;//
	static ExMessage m_msg;
	//inline static ExMessage m_msg;// 消息(要设置成静态变量)
//静态变量在这里仅仅是声明，必须还要定义，才能调用；C++17之前需要在cpp文件中这样定义一下ExMessage Window::m_msg;此处VS2019（c++20）的新功能用inline可以解决问题
};