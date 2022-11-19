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
    bool is_in();//判断鼠标是否在按钮上
    bool is_clicked();//判断鼠标是否点击按钮

    void eventloop(const ExMessage& msg);
    void setBackgroundColor(COLORREF c);
    void setHoverColor(COLORREF c);
    void setText(std::string text);
    void setColorDefault();
    void setColorHover();

private:
    std::string m_text;//按钮文字 
    std::string name;//景点名称 
    ExMessage m_msg;
    COLORREF cur_c = RGB(39, 117, 182);//当前按钮颜色
    COLORREF normal_c = RGB(39, 117, 182);//正常状态按钮默认颜色
    COLORREF hover_c = RED;//鼠标悬停在按钮默认颜色
};

