#ifndef MONEY_H
#define MONEY_H
#endif

#include <iostream>
#include <math.h>


class Money
{
public:

#pragma region OPERATIONS

	// ��������
	static void add(Money& ourCurrency, Money anotherCurrency);

	// ���������
	static void diff(Money& ourCurrency, Money anotherCurrency);

	// ���������
	static void mul(Money& ourCurrency, Money anotherCurrency);

	// �������
	static void div(Money& ourCurrency, Money anotherCurrency);

	// ���������
	static int compare(Money& ourCurrency, Money anotherCurrency);


#pragma endregion OPERATIONS

	// ��������� ����� � ������� �����, ��������� double
	double getAbs();

	// ������������
	void convert(Money anotherCurrency);

	// ������� � ������� ���������� � ������� �������
	void printInfo();


#pragma region SETGET

	double getCourse();

	double getInteger();

	double getDecimal();

	void setCourse(double course);

	void setInteger(double integer);

	void setDecimal(double decimal);

#pragma endregion SETGET

#pragma region CONSTRUCT

	Money(double course);

	Money(double integer, double decimal);

	Money(double course, double integer, double decimal);

#pragma endregion CONSTRUCT

private:

	double course; // ����
	
	double integer; // ����� �����

	double decimal; // ������� �����

};

