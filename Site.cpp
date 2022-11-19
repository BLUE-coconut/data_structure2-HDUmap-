#include "Site.h"
#include<math.h>
Site::Site(const std::string& text, const std::string& tname, int x, int y, int w, int h)
	:BasicWidget(x, y, w, h), m_text(text), name(tname)//���ø���
{
	memset(&m_msg, 0, sizeof(ExMessage));//��ʼ��
}

double com_distance(int sx,int sy,int cx,int cy)
{
	return sqrt(pow((sx - cx),2) + pow((sy - cy), 2));
}

void Site::show()
{
	setfillcolor(cur_c);//������ɫ
	::fillcircle(m_x, m_y, m_h);

	//���־��в���ʾ
	settextstyle(30, 0, "����");
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
		if (m_msg.message == WM_LBUTTONDOWN)//��ȡ��������Ϣ��m_msg��ExMessage��ı���em_msg.message�����Ϣ
		{
			return true;
		}
	}
	return false;
}

void Site::eventloop(const ExMessage& msg)
{
	m_msg = msg;
	if (!is_in())//��겻�ڰ�ť��
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
		settextstyle(20, 0, "����");
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