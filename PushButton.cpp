#include "PushButton.h"
PushButton::PushButton(const std::string& text, int x, int y, int w, int h)
	:BasicWidget(x, y, w, h), m_text(text)//调用父类
{
	memset(&m_msg, 0, sizeof(ExMessage));//初始化
}
void PushButton::show()
{
	setfillcolor(cur_c);//设置颜色
	::fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, 10, 10);

	//文字居中并显示
	settextcolor(BLACK);
	int tx = m_x + (m_w - textwidth(m_text.c_str())) / 2;
	int ty = m_y + (m_h - textheight(m_text.c_str())) / 2;
	::outtextxy(tx, ty, m_text.c_str());
}

bool PushButton::is_in()
{
	if (m_msg.x >= m_x && m_msg.x <= m_x + m_w && m_msg.y <= m_y + m_h && m_msg.y >= m_y)
		return true;
	return false;
}

bool PushButton::is_clicked()
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

void PushButton::eventloop(const ExMessage& msg)
{
	m_msg = msg;
	if (!is_in())//鼠标在按钮上
	{
		cur_c = normal_c;

	}
	else
	{
		cur_c = hover_c;
	}
}

void PushButton::setBackgroundColor(COLORREF c)
{
	normal_c = c;
}

void PushButton::setHoverColor(COLORREF c)
{
	hover_c = c;
}

void PushButton::setText(std::string text)
{
	this->m_text = text;
}