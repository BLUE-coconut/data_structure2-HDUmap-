#pragma once
#include"Window.h"
#include"Management.h"

int main()
{
	Window w(648, 853, EW_SHOWCONSOLE | EW_NOCLOSE);//创建窗口
	w.set_window_title("");
	Management m;
	m.run();//界面运行
	return w.exec();
}