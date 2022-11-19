#include "RouteLine.h"
RouteLine::RouteLine(int f, int t, int sx, int sy, int ex, int ey,int d)
{
	from = f;
	to = t;
	start_x = sx;
	start_y = sy;
	end_x = ex;
	end_y = ey;
	distance = d;
	m_w = end_x - start_x;
	m_h = end_y - start_y;
}

void RouteLine::show()
{
	int detax = (int)pointR * m_w / dis_compute();
	int detay = (int)pointR * m_h / dis_compute();
	line(start_x + detax , start_y + detay, end_x - detax, end_y - detay);
}

bool RouteLine::pick(int f,int t)
{
	if (from == f && to == t)return true;
	else if(from == t && to == f)return true;//无向图不区分起终点
	else return false;
}