#pragma once
#include"RouteLine.h"
#include<vector>
#include<queue>
const int N = 15;
const int L = 20;
class AllRoute
{
private:
//´æÍ¼
	struct point
	{
		int x, y;
	}p[N];
	struct edge
	{
		int to, w, nx;
	}e[2*N*N];

	int hd[N], tot, ided;
	int dis[N], vis[N];
	struct combine
	{
		int from, to, cw;
		friend bool operator < (const combine& a, const combine& b)
		{
			return a.cw > b.cw;
		}
	};
	std:: priority_queue <combine> q;
	void add(int x, int y, int w)
	{

		e[++tot] = { y,w,hd[x] };
		hd[x] = tot;
	}
	
	
public:
	AllRoute();

	int pick_path[N];
	int pick_dis = 0;

	std::vector <RouteLine*> all_line;
	void dij(int s,int e);
	bool findRoute(int s,int e);
	bool show(int from,int to);
	void show_all();
	void add_line(int from, int to, int dis);
};
