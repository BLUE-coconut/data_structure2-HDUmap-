#pragma once
#include "BasicWidget.h"
#include"Configure.h"
class PushButton :
    public BasicWidget
{
public:
    PushButton(const std::string& text = "Button", int x = 0, int y = 0, int w = 100, int h = 30);
    void show() override;
    bool is_in();//判断鼠标是否在按钮上
    bool is_clicked();//判断鼠标是否点击按钮

    void eventloop(const ExMessage& msg);
    void setBackgroundColor(COLORREF c);
    void setHoverColor(COLORREF c);
    void setText(std::string text);

private:
    std::string m_text;//按钮文字 
    ExMessage m_msg;
    COLORREF cur_c = RGB(186, 204, 217);//当前按钮颜色
    COLORREF normal_c = RGB(186, 204, 217);//正常状态按钮默认颜色
    COLORREF hover_c = RED;//鼠标悬停在按钮默认颜色
};