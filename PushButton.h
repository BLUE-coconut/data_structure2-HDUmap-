#pragma once
#include "BasicWidget.h"
#include"Configure.h"
class PushButton :
    public BasicWidget
{
public:
    PushButton(const std::string& text = "Button", int x = 0, int y = 0, int w = 100, int h = 30);
    void show() override;
    bool is_in();//�ж�����Ƿ��ڰ�ť��
    bool is_clicked();//�ж�����Ƿ�����ť

    void eventloop(const ExMessage& msg);
    void setBackgroundColor(COLORREF c);
    void setHoverColor(COLORREF c);
    void setText(std::string text);

private:
    std::string m_text;//��ť���� 
    ExMessage m_msg;
    COLORREF cur_c = RGB(186, 204, 217);//��ǰ��ť��ɫ
    COLORREF normal_c = RGB(186, 204, 217);//����״̬��ťĬ����ɫ
    COLORREF hover_c = RED;//�����ͣ�ڰ�ťĬ����ɫ
};