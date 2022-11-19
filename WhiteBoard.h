#pragma once
#include"Window.h"

class WhiteBoard
{
private:
	std::string fname;
	int m_x;
	int m_y;
	int left = 110;
	int top = 230;
	int right = 538;
	int bottom = 730;
	int text_size = 20;
	int line_gap = text_size + 10;
	const char* text_font = "¿¬Ìå";
public:
	WhiteBoard(const std::string& fn);
	void show();

};

