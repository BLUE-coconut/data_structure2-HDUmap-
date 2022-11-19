#include "PushButton.h"
PushButton::PushButton(const std::string& text, int x, int y, int w, int h)
	:BasicWidget(x, y, w, h), m_text(text)//���ø���
{
	memset(&m_msg, 0, sizeof(ExMessage));//��ʼ��
}
void PushButton::show()
{
	setfillcolor(cur_c);//������ɫ
	::fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, 10, 10);

	//���־��в���ʾ
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
		if (m_msg.message == WM_LBUTTONDOWN)//��ȡ��������Ϣ��m_msg��ExMessage��ı���em_msg.message�����Ϣ
		{
			return true;
		}
	}
	return false;
}

void PushButton::eventloop(const ExMessage& msg)
{
	m_msg = msg;
	if (!is_in())//����ڰ�ť��
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