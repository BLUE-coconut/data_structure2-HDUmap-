#pragma once
class BasicWidget
{
public:
	BasicWidget(int x, int y, int w, int h);
	int width();
	int height();
	void setFixedSize(int w, int h);//设置图形元件大小
	int x();
	int y();
	void move(int x, int y);//图形元件坐标
	virtual void show() = 0;//虚函数


protected:
	int m_x;
	int m_y;
	int m_w;
	int m_h;

};