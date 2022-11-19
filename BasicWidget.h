#pragma once
class BasicWidget
{
public:
	BasicWidget(int x, int y, int w, int h);
	int width();
	int height();
	void setFixedSize(int w, int h);//����ͼ��Ԫ����С
	int x();
	int y();
	void move(int x, int y);//ͼ��Ԫ������
	virtual void show() = 0;//�麯��


protected:
	int m_x;
	int m_y;
	int m_w;
	int m_h;

};