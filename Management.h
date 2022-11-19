#pragma once
#include"Window.h"
#include<vector>
#include"PushButton.h"
#include"Site.h"
#include"WhiteBoard.h"
#include"RouteData.h"
class Management
{
	enum Operator
	{
		Information,
		Route,
		Help,
		Menu = 66
	};
public:
	Management();
	int op = Menu;//��ǰѡ��ҳ��Menu=66��
	int inf_op = 0;
	int rot_op = 0;
	int pick_start = 0;
	int pick_end = 0;
	void init_op();

	IMAGE m_bk;//����ͼƬ
	ExMessage m_msg;//������Ϣ
	std::vector<PushButton*	>menu_btns;//���˵���ť
	PushButton	m_EscBtn;//��ҳ�淵�ذ�ť


	void draw_Background();
	int mainMenu(const ExMessage& msg);
	void EventLoop();
	int isEsc();
	int get_inf();
	int get_rot();
	int help();
	void run();


	//ten sites for information
	std::vector<Site* >sites_inf;
	std::vector<WhiteBoard* >sites_board;

	//ten sites for route
	std::vector<Site* >sites_rot;
	AllRoute Routes;

	//help
	WhiteBoard* helper = new WhiteBoard("help.txt");

};

