#include "Money.h"



#pragma region OPERATIONS

/// <summary>
/// ��������
/// </summary>
void Money::add(Money& ourCurrency, Money anotherCurrency)
{
	if (ourCurrency.course != anotherCurrency.course) anotherCurrency.convert(ourCurrency);
	double temp = ourCurrency.getAbs() + anotherCurrency.getAbs();
	ourCurrency.decimal = modf(temp, &ourCurrency.integer);	//	�������� ����� ����� �� ������� <math.h>	https://www.cplusplus.com/reference/cmath/modf/
}

/// <summary>
/// ���������
/// </summary>
void Money::diff(Money& ourCurrency, Money anotherCurrency)
{
	if (ourCurrency.course != anotherCurrency.course) anotherCurrency.convert(ourCurrency);
	if (ourCurrency.getAbs() > anotherCurrency.getAbs())
	{
		if (ourCurrency.course != anotherCurrency.course) anotherCurrency.convert(ourCurrency);
		double temp = ourCurrency.getAbs() - anotherCurrency.getAbs();
		ourCurrency.decimal = modf(temp, &ourCurrency.integer);	//	�������� ����� ����� �� ������� <math.h>	https://www.cplusplus.com/reference/cmath/modf/
	}
	else
	{
		ourCurrency.integer = 0;
		ourCurrency.decimal = 0;
	}
}

/// <summary>
/// ���������
/// </summary>
void Money::mul(Money& ourCurrency, Money anotherCurrency)
{
	if (ourCurrency.course != anotherCurrency.course) anotherCurrency.convert(ourCurrency);
	double temp = ourCurrency.getAbs() * anotherCurrency.getAbs();
	ourCurrency.decimal = modf(temp, &ourCurrency.integer);	//	�������� ����� ����� �� ������� <math.h>	https://www.cplusplus.com/reference/cmath/modf/
}

/// <summary>
/// �������
/// </summary>
void Money::div(Money& ourCurrency, Money anotherCurrency)
{
	if (ourCurrency.course != anotherCurrency.course) anotherCurrency.convert(ourCurrency);
	if (anotherCurrency.integer != 0 && anotherCurrency.decimal != 0)
	{
		if (ourCurrency.course != anotherCurrency.course) anotherCurrency.convert(ourCurrency);
		double temp = ourCurrency.getAbs() / anotherCurrency.getAbs();
		ourCurrency.decimal = modf(temp, &ourCurrency.integer);	//	�������� ����� ����� �� ������� <math.h>	https://www.cplusplus.com/reference/cmath/modf/
	}
	else return;
}

/// <summary>
/// ��������� [!] �����, ����� ������ ������ �� ������������ �� ������, ����� � ������� �������������� ������� 
/// </summary>
int Money::compare(Money& ourCurrency, Money anotherCurrency)
{
	if (ourCurrency.course != anotherCurrency.course) anotherCurrency.convert(ourCurrency);
	
	if (ourCurrency.getAbs() > anotherCurrency.getAbs()) return 1;
	else if (ourCurrency.getAbs() < anotherCurrency.getAbs()) return 2;
	else if (ourCurrency.getAbs() == anotherCurrency.getAbs()) return 0;
	else return -1;

}

#pragma endregion OPERATIONS


/// <summary>
/// ������ �����: ����� ����� + ������� �����, ���������� � ���� double
/// </summary>
double Money::getAbs()
{
	return double(getInteger()) + getDecimal();
}

/// <summary>
/// �������� ������� ������ � �.�.
/// </summary>
void Money::convert(Money anotherCurrency)
{
	double abs = getAbs();							// ������� ��� ����� ��� ������� 
	abs = abs / course * anotherCurrency.course;	// ������������
	course = anotherCurrency.course;				//
	decimal = modf(abs, &integer);					//	�������� ����� ����� �� ������� <math.h>	https://www.cplusplus.com/reference/cmath/modf/
}

/// <summary>
/// �������� � ������� ���������� �� �������
/// </summary>
void Money::printInfo()
{
	std::cout << "\t" << course << "\t\t" << integer << "\t\t" << decimal << "\n";
}


#pragma region CONSTRUCT

Money::Money(double course)
{
	this->course = course;
	this->integer = 0;
	this->decimal = 0;
}

Money::Money(double integer, double decimal)
{
	this->course = 1;
	this->integer = integer;
	this->decimal = decimal;
}

Money::Money(double course, double integer, double decimal) : Money(integer, decimal)
{
	this->course = course;
}

#pragma endregion CONSTRUCT

#pragma region SETGET

double Money::getCourse() 
{
	return course;
}

double Money::getInteger()
{
	return integer;
}

double Money::getDecimal()
{
	return decimal;
}

void Money::setCourse(double course)
{
	this->course = course;
}

void Money::setInteger(double integer)
{
	this->integer = integer;
}

void Money::setDecimal(double decimal)
{
	this->decimal = decimal;
}

#pragma endregion SETGET

