#pragma once
#include"Configure.h"
#include<conio.h>
class Window
{
public:
	Window(int w, int h, int flag);
	void set_window_title(const std::string& title);
	int exec();
	//���ڲ���
	static int width();
	static int height();
	static void clear();
	//����BeginBatchDraw�����еĻ�ͼ��������ʾ����Ļ�ϣ��������ڴ��н���;ֱ������EndBatchDraw��֮ǰ�������ڴ��л�ͼ�ĳ�Ʒ��һ��չʾ����Ļ��;�Ӷ�����������
	static void benginDraw();
	static void flushDraw();
	static void endDraw();

	//������������
	inline static bool hasMsg() { return peekmessage(&m_msg, EM_MOUSE | EM_KEY); }
	inline static const ExMessage& getMsg() { return m_msg; }


private:
	HWND m_handle;//
	static ExMessage m_msg;
	//inline static ExMessage m_msg;// ��Ϣ(Ҫ���óɾ�̬����)
//��̬������������������������뻹Ҫ���壬���ܵ��ã�C++17֮ǰ��Ҫ��cpp�ļ�����������һ��ExMessage Window::m_msg;�˴�VS2019��c++20�����¹�����inline���Խ������
};