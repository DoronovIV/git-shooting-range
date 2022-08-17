#ifndef APP_H
#define APP_H
#endif

#include "StringEx.h"

/// <summary>
/// �����-����������
/// ��������� ����������� � ������ Run()
/// </summary>
class App
{


public:

	/// <summary>
	/// ����������� �� ���������
	/// </summary>
	App();

	/// <summary>
	/// �������� �����, ����������� ����������
	/// </summary>
	void run();


#pragma region MENU_DRAWING


	/// <summary>
	/// ������ ���� ��������
	/// </summary>
	void drawMenuStart();

	/// <summary>
	/// ��������� ���� � ���������� ����� ��������, ���������� �������������
	/// </summary>
	/// <param name="nOptionsQuantity">���-�� ��������, ��� ��������</param>
	/// <returns>��������� ����� ����</returns>
	int selector(int nOptionsQuantity);

	/// <summary>
	/// ���������� ���������� ���������� ���������
	/// </summary>
	void showContinue();

	/// <summary>
	/// ������������� ������������
	/// </summary>
	/// <param name="demo_one">������ ������</param>
	/// <param name="demo_two">������ ������</param>
	/// <param name="demo_three">������ ������</param>
	void drawConcatenation(StringEx& demo_one, StringEx& demo_two, StringEx& demo_three);

	/// <summary>
	/// ������������� ����� Split
	/// </summary>
	/// <param name="demo_one">������ ������</param>
	/// <param name="demo_two">������ ������</param>
	/// <param name="demo_three">������ ������</param>
	void drawSplit(StringEx& demo_one, StringEx& demo_two, StringEx& demo_three);

	/// <summary>
	/// ������������� ����� Insert
	/// </summary>
	/// <param name="demo_one">������ ������</param>
	void drawInsert(StringEx& demo_one);


	/// <summary>
	/// ������������� ����� Contains
	/// </summary>
	/// <param name="demo_one">������ ������</param>
	/// <param name="demo_two">������ ������</param>
	void drawContains(StringEx& demo_one, StringEx& demo_two);

	
#pragma endregion MENU_DRAWING


};

