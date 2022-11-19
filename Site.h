#pragma once
#include "BasicWidget.h"
#include"Configure.h"
class Site :
    public BasicWidget
{
public:
    Site(const std::string& text = "Button", const std::string& tname = "name", int x = 0, int y = 0, int w = 25, int h = 25);
    void show() override;
    void show_name();
    bool is_in();//�ж�����Ƿ��ڰ�ť��
    bool is_clicked();//�ж�����Ƿ�����ť

    void eventloop(const ExMessage& msg);
    void setBackgroundColor(COLORREF c);
    void setHoverColor(COLORREF c);
    void setText(std::string text);
    void setColorDefault();
    void setColorHover();

private:
    std::string m_text;//��ť���� 
    std::string name;//�������� 
    ExMessage m_msg;
    COLORREF cur_c = RGB(39, 117, 182);//��ǰ��ť��ɫ
    COLORREF normal_c = RGB(39, 117, 182);//����״̬��ťĬ����ɫ
    COLORREF hover_c = RED;//�����ͣ�ڰ�ťĬ����ɫ
};

