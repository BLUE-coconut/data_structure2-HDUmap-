#include "Window.h"
#include<iostream>
#include<vector>
Window::Window(int w, int h, int flag)
{
	m_handle = ::initgraph(w, h, flag);
	::setbkmode(TRANSPARENT);
}
void Window::set_window_title(const std::string& title)
{
	::SetWindowText(m_handle, title.c_str());
}
int Window::exec()
{
	return getchar();

}

int Window::width()
{
	return ::getwidth();
}

int Window::height()
{
	return ::getheight();
}

void Window::clear()
{
	::cleardevice();
}

void Window::benginDraw()
{
	::BeginBatchDraw();
}

void Window::flushDraw()
{
	::FlushBatchDraw();
}

void Window::endDraw()
{
	::EndBatchDraw();
}

ExMessage Window::m_msg;