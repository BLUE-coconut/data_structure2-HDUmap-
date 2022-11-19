#include "Site.h"
#include<math.h>
Site::Site(const std::string& text, const std::string& tname, int x, int y, int w, int h)
	:BasicWidget(x, y, w, h), m_text(text), name(tname)//调用父类
{
	memset(&m_msg, 0, sizeof(ExMessage));//初始化
}

double com_distance(int sx,int sy,int cx,int cy)
{
	return sqrt(pow((sx - cx),2) + pow((sy - cy), 2));
}

void Site::show()
{
	setfillcolor(cur_c);//设置颜色
	::fillcircle(m_x, m_y, m_h);

	//文字居中并显示
	settextstyle(30, 0, "楷体");
	settextcolor(BLACK);
	int tx = m_x - textwidth(m_text.c_str())/ 2;
	int ty = m_y - textheight(m_text.c_str())/ 2;
	::outtextxy(tx, ty, m_text.c_str());
	show_name();
}

bool Site::is_in()
{
	if(com_distance(m_msg.x, m_msg.y, m_x, m_y)<=m_h)
		return true;
	return false;
}

bool Site::is_clicked()
{
	if (is_in())
	{
		if (m_msg.message == WM_LBUTTONDOWN)//获取鼠标左键消息。m_msg是ExMessage类的变量em_msg.message获得消息
		{
			return true;
		}
	}
	return false;
}

void Site::eventloop(const ExMessage& msg)
{
	m_msg = msg;
	if (!is_in())//鼠标不在按钮上
	{
		cur_c = normal_c;
	}
	else
	{
		cur_c = hover_c;
	}
}

void Site::show_name()
{
	if (cur_c == hover_c)
	{
		settextstyle(20, 0, "楷体");
		::outtextxy(m_x - textwidth(name.c_str()) / 2 , m_y - textheight(name.c_str()) / 2 - m_h, name.c_str());
	}
}

void Site::setBackgroundColor(COLORREF c)
{
	normal_c = c;
}

void Site::setHoverColor(COLORREF c)
{
	hover_c = c;
}

void Site::setText(std::string text)
{
	this->m_text = text;
}

void Site::setColorDefault()
{
	cur_c = normal_c;
}

void Site::setColorHover()
{
	cur_c = hover_c;
}