#pragma once
#include "Management.h"
#include <conio.h>
#include <ctime> 

const int titley = 30;


bool Delay(int time)//time*1000Ϊ���� 
{
    clock_t   now = clock();

    while (clock() - now < time);
    return true;
}



Management::Management()
{
	::loadimage(&m_bk, "./image/bg1.png", Window::width(), Window::height());//����ͼ

    //���ذ�ť��
    m_EscBtn.setFixedSize(80, 30);
    m_EscBtn.setText("����");
    m_EscBtn.move(Window::width() - 100, Window::height() - 50);

    //�����水ť
    menu_btns.push_back(new PushButton("�鿴������Ϣ"));
    menu_btns.push_back(new PushButton("��ѯ&�滮·��"));
    menu_btns.push_back(new PushButton("����&����"));
    menu_btns.push_back(new PushButton("�˳�ϵͳ"));
    for (int i = 0; i < menu_btns.size(); i++)
    {
        menu_btns[i]->setFixedSize(300, 50);
        int bx = (Window::width() - menu_btns[i]->width()) / 2;
        int vspace = Window::height() - menu_btns.size() * menu_btns[i]->height();
        int by = vspace / 2 + i * menu_btns[i]->height();

        menu_btns[i]->move(bx, by);
    }

    //������Ϣ��ѯ����ʮ�󾰵㰴ť
    sites_inf.push_back(new Site("1", "��������", 298, 525));//��������
    sites_inf.push_back(new Site("2", "�麣���", 298, 430));//�麣���
    sites_inf.push_back(new Site("3", "��������", 298, 735));//��������
    sites_inf.push_back(new Site("4", "������Ӱ", 365, 716));//������Ӱ
    sites_inf.push_back(new Site("5", "��ͤ����", 454, 655));//��ͤ����
    sites_inf.push_back(new Site("6", "���ܻ�԰", 82, 709));//���ܻ�԰
    sites_inf.push_back(new Site("7", "�޵�����", 98, 386));//�޵�����
    sites_inf.push_back(new Site("8", "���Ĺ㳡", 463, 420));//���Ĺ㳡
    sites_inf.push_back(new Site("9", "������ѧ", 498, 524));//������ѧ
    sites_inf.push_back(new Site("10", "���ȼ���", 292, 221));//���ȼ���

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


    //·���滮����ʮ�󾰵㰴ť
    sites_rot.push_back(new Site("1", "��������", 298, 525));//��������
    sites_rot.push_back(new Site("2", "�麣���", 298, 430));//�麣���
    sites_rot.push_back(new Site("3", "��������", 298, 735));//��������
    sites_rot.push_back(new Site("4", "������Ӱ", 365, 716));//������Ӱ
    sites_rot.push_back(new Site("5", "��ͤ����", 454, 655));//��ͤ����
    sites_rot.push_back(new Site("6", "���ܻ�԰", 82, 709));//���ܻ�԰
    sites_rot.push_back(new Site("7", "�޵�����", 98, 386));//�޵�����
    sites_rot.push_back(new Site("8", "���Ĺ㳡", 463, 420));//���Ĺ㳡
    sites_rot.push_back(new Site("9", "������ѧ", 498, 524));//������ѧ
    sites_rot.push_back(new Site("10", "���ȼ���", 292, 221));//���ȼ���

    
    
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
    
    //ѭ�����н���������Ϣ��
    while (true)
    {
        Window::clear();
        draw_Background();
        
        if (Window::hasMsg())
        {
            m_msg = Window::getMsg();
            switch (m_msg.message)
            {
            case WM_KEYDOWN:    // ��������ESC����������
                switch (m_msg.vkcode)
                {
                case VK_ESCAPE:		//ESC
                    op = Menu;
                    break;
                }
                break;
            default://������
                //this->EventLoop();//��ѯһ�������
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
    settextstyle(60, 0, "����");
    char title[50] = "HDUУ԰����";
    outtextxy((Window::width() - textwidth(title)) / 2, titley, title);
    settextstyle(30, 0, "����");
    outtextxy(320, 600, "HDU students��hhl");

    for (auto btn : menu_btns)
    {
        btn->show();//��ʾ��ť
    }
    for (int i = 0; i < menu_btns.size(); i++)
    {
        menu_btns[i]->eventloop(msg);
        if (menu_btns[i]->is_clicked())//��ť�����Ϣ����
        {
            return i;
        }
    }
    return Menu;
}

int Management::isEsc()
{
    settextstyle(20, 0, "����");
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
        settextstyle(50, 0, "����");
        char title[50] = "����ʮ������";
        outtextxy((Window::width() - textwidth(title)) / 2, titley, title);
        for (auto btn : sites_inf)
        {
            btn->show();//��ʾ��ť
        }
        for (int i = 0; i < sites_inf.size(); i++)
        {
            sites_inf[i]->eventloop(m_msg);
            if (sites_inf[i]->is_clicked())//��ť�����Ϣ����
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
        settextstyle(40, 0, "����");
        char title[50] = "����·���滮(ѡ�����)";
        outtextxy((Window::width() - textwidth(title)) / 2, titley, title);
        if (isEsc())
        {
            return Menu;
        }
        for (auto btn : sites_rot)
        {
            btn->show();//��ʾ��ť
        }
        Routes.show_all();//��ʾ·��
        for (int i = 0; i < sites_rot.size(); i++)
        {
            sites_rot[i]->eventloop(m_msg);
            if (sites_rot[i]->is_clicked() && Delay(250))//��ť�����Ϣ����
            {
                pick_start = i;
                rot_op = 1;
                return Route;
            }
        }
    }
    else if (rot_op == 1)
    {
        settextstyle(40, 0, "����");
        char title[50] = "����·���滮(ѡ���յ�)";
        outtextxy((Window::width() - textwidth(title)) / 2, titley, title);
        if (isEsc())
        {
            return Menu;
        }
        for (auto btn : sites_rot)
        {
            btn->show();//��ʾ��ť
        }
        Routes.show_all();//��ʾ·��
        for (int i = 0; i < sites_rot.size(); i++)
        {
            sites_rot[i]->eventloop(m_msg);
            if (sites_rot[i]->is_clicked() && Delay(250))//��ť�����Ϣ����
            {
                pick_end = i;
                rot_op = 2;
                return Route;
            }
        }
    }
    else
    {
        settextstyle(40, 0, "����");
        char title[50] = "���·��";
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
    settextstyle(50, 0, "����");
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
