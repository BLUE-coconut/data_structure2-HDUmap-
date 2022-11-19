#pragma once
#include<math.h>
#include"Window.h"
class RouteLine
{
private:
	int from;
	int to;
	int start_x;
	int start_y;
	int end_x;
	int end_y;
	int distance;
	int pointR = 25;
	int m_w;
	int m_h;
	double dis_compute()
	{
		return sqrt(pow((start_x - end_x), 2) + pow((start_y - end_y), 2));
	}
public:
	RouteLine(int f,int t,int sx,int sy,int ex,int ey,int d);

	void show();

	bool pick(int from,int to);
	//void show_point(int op);
};

