#pragma once
#include"Window.h"
#include"Management.h"

int main()
{
	Window w(648, 853, EW_SHOWCONSOLE | EW_NOCLOSE);//��������
	w.set_window_title("");
	Management m;
	m.run();//��������
	return w.exec();
}