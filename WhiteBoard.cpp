#include "WhiteBoard.h"

WhiteBoard::WhiteBoard(const std::string& fn)
{
	fname = fn;
}

int readline(FILE* fp, int tx, int ty)//read help.txt
{
    char szTest[100];
    int len = 0;

    if (!feof(fp))
    {
        memset(szTest, 0, sizeof(szTest));
        fgets(szTest, sizeof(szTest) - 1, fp);
        outtextxy(tx, ty, szTest);
        //printf("%s", szTest);
    }
    else
    {
        return 0;
    }
    return 1;
}

void WhiteBoard::show()
{
    setfillcolor(WHITE);//设置填充颜色
    
    int m_w = right - left;
    int m_h = bottom - top;
    ::fillroundrect(left, top, right, bottom, 10, 10);

    //char text1[50] = "HDU 数据结构作业7:校园向导";
    //文字居中并显示
    settextcolor(BLACK);
    settextstyle(text_size, 0, text_font);
    int tx = left + 20;
    int ty = top + 30;

    FILE* fp;
    fopen_s(&fp, fname.c_str(), "r");
    while (readline(fp, tx, ty))
    {
        ty += line_gap;
    }
    fclose(fp);
}
