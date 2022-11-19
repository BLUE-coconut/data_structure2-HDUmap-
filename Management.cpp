#pragma once
#include "Management.h"
#include <conio.h>
#include <ctime> 

const int titley = 30;


bool Delay(int time)//time*1000为秒数 
{
    clock_t   now = clock();

    while (clock() - now < time);
    return true;
}



Management::Management()
{
	::loadimage(&m_bk, "./image/bg1.png", Window::width(), Window::height());//背景图

    //返回按钮：
    m_EscBtn.setFixedSize(80, 30);
    m_EscBtn.setText("返回");
    m_EscBtn.move(Window::width() - 100, Window::height() - 50);

    //主界面按钮
    menu_btns.push_back(new PushButton("查看景点信息"));
    menu_btns.push_back(new PushButton("查询&规划路径"));
    menu_btns.push_back(new PushButton("帮助&关于"));
    menu_btns.push_back(new PushButton("退出系统"));
    for (int i = 0; i < menu_btns.size(); i++)
    {
        menu_btns[i]->setFixedSize(300, 50);
        int bx = (Window::width() - menu_btns[i]->width()) / 2;
        int vspace = Window::height() - menu_btns.size() * menu_btns[i]->height();
        int by = vspace / 2 + i * menu_btns[i]->height();

        menu_btns[i]->move(bx, by);
    }

    //景点信息查询——十大景点按钮
    sites_inf.push_back(new Site("1", "三鼎问天", 298, 525));//三鼎问天
    sites_inf.push_back(new Site("2", "书海风荷", 298, 430));//书海风荷
    sites_inf.push_back(new Site("3", "长虹揽月", 298, 735));//长虹揽月
    sites_inf.push_back(new Site("4", "月雅云影", 365, 716));//月雅云影
    sites_inf.push_back(new Site("5", "兰亭春晓", 454, 655));//兰亭春晓
    sites_inf.push_back(new Site("6", "秘密花园", 82, 709));//秘密花园
    sites_inf.push_back(new Site("7", "巨碟邀星", 98, 386));//巨碟邀星
    sites_inf.push_back(new Site("8", "五四广场", 463, 420));//五四广场
    sites_inf.push_back(new Site("9", "丛鱼听学", 498, 524));//丛鱼听学
    sites_inf.push_back(new Site("10", "藤廊寄梦", 292, 221));//藤廊寄梦

    sites_board.push_back(new WhiteBoard("sanding.txt"));
    sites_board.push_back(new WhiteBoard("shuhai.txt"));
    sites_board.push_back(new WhiteBoard("changhong.txt"));
    sites_board.push_back(new WhiteBoard("yueya.txt"));
    sites_board.push_back(new WhiteBoard("lanting.txt"));
    sites_board.push_back(new WhiteBoard("huayuan.txt"));
    sites_board.push_back(new WhiteBoard("judie.txt"));
    sites_board.push_back(new WhiteBoard("wusi.txt"));
    sites_board.push_back(new WhiteBoard("congyu.txt"));
    sites_board.push_back(new WhiteBoard("tenglang.txt"));


    //路径规划——十大景点按钮
    sites_rot.push_back(new Site("1", "三鼎问天", 298, 525));//三鼎问天
    sites_rot.push_back(new Site("2", "书海风荷", 298, 430));//书海风荷
    sites_rot.push_back(new Site("3", "长虹揽月", 298, 735));//长虹揽月
    sites_rot.push_back(new Site("4", "月雅云影", 365, 716));//月雅云影
    sites_rot.push_back(new Site("5", "兰亭春晓", 454, 655));//兰亭春晓
    sites_rot.push_back(new Site("6", "秘密花园", 82, 709));//秘密花园
    sites_rot.push_back(new Site("7", "巨碟邀星", 98, 386));//巨碟邀星
    sites_rot.push_back(new Site("8", "五四广场", 463, 420));//五四广场
    sites_rot.push_back(new Site("9", "丛鱼听学", 498, 524));//丛鱼听学
    sites_rot.push_back(new Site("10", "藤廊寄梦", 292, 221));//藤廊寄梦

    
    
}
void Management::init_op()
{
    inf_op = 0;
    rot_op = 0;
    
}

void Management::draw_Background()
{
    ::putimage(0, 0, &m_bk);
}

void Management::run()
{
    int op = Menu;
    Window::benginDraw();
    
    //循环运行接收输入消息：
    while (true)
    {
        Window::clear();
        draw_Background();
        
        if (Window::hasMsg())
        {
            m_msg = Window::getMsg();
            switch (m_msg.message)
            {
            case WM_KEYDOWN:    // 按键按下ESC返回主界面
                switch (m_msg.vkcode)
                {
                case VK_ESCAPE:		//ESC
                    op = Menu;
                    break;
                }
                break;
            default://鼠标操作
                //this->EventLoop();//问询一遍各操作
                break;
            }
        }

        switch (op)
        {
        case Menu:
            //Init_op();
            //printf("menu!\n");
            op = mainMenu(m_msg);
            break;
        case Information:
            //printf("information!\n");
            op = get_inf();
            break;
        case Route:
            //printf("route!\n");
            op = get_rot();
            break;
        case Help:
            //printf("help!\n");
            op = help();
            break;
        default:
            exit(0);
            break;
        }

        Window::flushDraw();
    }
    Window::endDraw();


}

int Management::mainMenu(const ExMessage& msg)
{
    settextstyle(60, 0, "黑体");
    char title[50] = "HDU校园导航";
    outtextxy((Window::width() - textwidth(title)) / 2, titley, title);
    settextstyle(30, 0, "楷体");
    outtextxy(320, 600, "HDU students：hhl");

    for (auto btn : menu_btns)
    {
        btn->show();//显示按钮
    }
    for (int i = 0; i < menu_btns.size(); i++)
    {
        menu_btns[i]->eventloop(msg);
        if (menu_btns[i]->is_clicked())//按钮点击消息接收
        {
            return i;
        }
    }
    return Menu;
}

int Management::isEsc()
{
    settextstyle(20, 0, "楷体");
    m_EscBtn.show();
    m_EscBtn.eventloop(m_msg);

    if (m_EscBtn.is_clicked()&&Delay(250))
    {
        init_op();
        return 1;
    }
    else return 0;
}


int Management::get_inf()
{
    if (inf_op == 0)
    {
        if (isEsc())
        {
            return Menu;
        }
        settextstyle(50, 0, "黑体");
        char title[50] = "杭电十景介绍";
        outtextxy((Window::width() - textwidth(title)) / 2, titley, title);
        for (auto btn : sites_inf)
        {
            btn->show();//显示按钮
        }
        for (int i = 0; i < sites_inf.size(); i++)
        {
            sites_inf[i]->eventloop(m_msg);
            if (sites_inf[i]->is_clicked())//按钮点击消息接收
            {
                inf_op = i + 1;
                return Information;
            }
        }
    }
    else
    {
        if (isEsc())
        {
            return Information;
        }
        sites_board[inf_op - 1]->show();
    }
    return Information;
}

int Management::get_rot()
{
    if (rot_op == 0)
    {
        settextstyle(40, 0, "黑体");
        char title[50] = "景点路径规划(选择起点)";
        outtextxy((Window::width() - textwidth(title)) / 2, titley, title);
        if (isEsc())
        {
            return Menu;
        }
        for (auto btn : sites_rot)
        {
            btn->show();//显示按钮
        }
        Routes.show_all();//显示路线
        for (int i = 0; i < sites_rot.size(); i++)
        {
            sites_rot[i]->eventloop(m_msg);
            if (sites_rot[i]->is_clicked() && Delay(250))//按钮点击消息接收
            {
                pick_start = i;
                rot_op = 1;
                return Route;
            }
        }
    }
    else if (rot_op == 1)
    {
        settextstyle(40, 0, "黑体");
        char title[50] = "景点路径规划(选择终点)";
        outtextxy((Window::width() - textwidth(title)) / 2, titley, title);
        if (isEsc())
        {
            return Menu;
        }
        for (auto btn : sites_rot)
        {
            btn->show();//显示按钮
        }
        Routes.show_all();//显示路线
        for (int i = 0; i < sites_rot.size(); i++)
        {
            sites_rot[i]->eventloop(m_msg);
            if (sites_rot[i]->is_clicked() && Delay(250))//按钮点击消息接收
            {
                pick_end = i;
                rot_op = 2;
                return Route;
            }
        }
    }
    else
    {
        settextstyle(40, 0, "黑体");
        char title[50] = "最短路线";
        outtextxy((Window::width() - textwidth(title)) / 2, titley, title);
        if (isEsc())
        {
            return Route;
        }
        if (Routes.findRoute(pick_start, pick_end))
        {
            for (int i = 1; i <= Routes.pick_path[0]; i++)
            {
                if (i == Routes.pick_path[0])
                {
                    sites_rot[Routes.pick_path[i]]->setColorHover();
                    sites_rot[Routes.pick_path[i]]->show();
                    sites_rot[Routes.pick_path[i]]->setColorDefault();
                }
                sites_rot[Routes.pick_path[i]]->show();
            }
        }
    }
    return Route;
}

int Management::help()
{
    settextstyle(50, 0, "黑体");
    char title[50] = "About & Help";
    outtextxy((Window::width() - textwidth(title)) / 2, titley, title);

    helper->show();

    if (isEsc())
    {
        return Menu;
    }
    else return Help;
}

void Management::EventLoop()
{
    if (op == Help)
    {
        m_EscBtn.eventloop(m_msg);
    }
    else if (op == Information)
    {
        m_EscBtn.eventloop(m_msg);
    }
    else if (op == Route)
    {
        m_EscBtn.eventloop(m_msg);
    }
}
