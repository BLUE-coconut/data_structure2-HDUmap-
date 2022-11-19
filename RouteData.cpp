#include"RouteData.h"
void AllRoute::add_line(int from, int to, int dis)
{
	add(from, to, dis);
	add(to, from, dis);
	all_line.push_back(new RouteLine(from,to,p[from].x, p[from].y, p[to].x, p[to].y, dis));
}
AllRoute::AllRoute()
{
	p[0] = { 298, 525 };
	p[1] = { 298, 430 };
	p[2] = { 298, 735 };
	p[3] = { 365, 716 };
	p[4] = { 454, 655 };
	p[5] = { 82, 709 };
	p[6] = { 98, 386 };
	p[7] = { 463, 420 };
	p[8] = { 498, 524 };
	p[9] = { 292, 221 };

	add_line(0, 1, 30);
	add_line(0, 2, 50);
	add_line(5, 0, 60);
	add_line(7, 1, 70);
	add_line(2, 3, 80);
	add_line(3, 4, 20);
	add_line(1, 6, 60);
	add_line(2, 5, 90);
	add_line(6, 5, 10);
	add_line(9, 6, 60);
	add_line(7, 8, 20);
	add_line(9, 7, 30);
	add_line(8, 0, 90);
	add_line(4, 8, 30);

}
void AllRoute:: dij(int s, int end)
{
	int pre[N];
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	q.push({ -1, s, 0 });//(dis , s)
	while (!q.empty())
	{
		combine cur = q.top();
		q.pop();
		int x = cur.from;
		int y = cur.to;
		if (vis[y])continue;
		vis[y] = 1;
		pre[y] = x;

		for (int i = hd[y]; i; i = e[i].nx)
		{
			int z = e[i].to;
			if (dis[y] + e[i].w < dis[z])
			{
				dis[z] = dis[y] + e[i].w;
				q.push({ y, z, dis[z] });
			}
		}
	}
	int cur = end, cnt = 0;
	
	while (cur >= 0)
	{

		pick_path[++cnt] = cur;
		//printf("%d->%d\n", cur, pre[cur]);
		cur = pre[cur];

	}
	pick_path[0] = cnt;
	pick_dis = dis[end];
	//printf("%d\n", dis[end]);

}

bool AllRoute::show(int from, int to)
{
	
	for (auto cur : all_line)
	{
		if (cur->pick(from, to))
		{
			setlinecolor((202, 211, 195));
			setlinestyle(PS_DASH, 5);
			cur->show();
			setlinecolor(WHITE);
			setlinestyle(PS_SOLID, 0);
			return true;
		}
	}
	printf("Path Not exist\n");
	return false;
}

void AllRoute::show_all()
{
	setlinecolor((202,211,195));
	setlinestyle(PS_DASH, 5);
	for (auto cur : all_line)
	{
		cur->show();
	}
	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 0);
}


bool AllRoute::findRoute(int s, int e)
{
	if (s == e)
	{
		printf("起点和终点不可选同一个\n");
		return false;
	}
	dij(s,e);
	for (int i = 1; i <= pick_path[0]-1; i++)
	{
		printf("%d->%d\n", pick_path[i], pick_path[i+1]);
		show(pick_path[i], pick_path[i + 1]);
	}
	return true;
}