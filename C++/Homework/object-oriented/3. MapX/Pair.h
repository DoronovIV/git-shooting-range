#ifndef PAIR_H
#define PAIR_H


/// <summary>
/// ����� "����", ��� ��������. 
/// ��������� ���� � ������������� ��������� ����� ������� �� �������, � ����� �������� ������
/// </summary>
/// <typeparam name="T">������ ��������</typeparam>
/// <typeparam name="D">������ ��������</typeparam>
template<typename T, typename D>
class Pair
{


public:


#pragma	region CONSTRUCT


	/// <summary>
	/// ����������� �� ���������
	/// </summary>
	Pair()
	{
		firstValue = 0;
		secondValue = 0;
	}


	/// <summary>
	/// ����������� � ����� ��������
	/// </summary>
	/// <param name="firstValue">������ ��������</param>
	/// <param name="secondValue">������ ��������</param>
	Pair(T firstValue, D secondValue)
	{
		this->firstValue = firstValue;
		this->secondValue = secondValue;
	}


#pragma	endregion CONSTRUCT




#pragma region ACCESS


	/// <summary>
	/// ������ �������
	/// </summary>
	/// <param name="first">����� ��������</param>
	void setFirst(T first)
	{
		this->firstValue = first;
	}


	/// <summary>
	/// ������ �������
	/// </summary>
	/// <param name="second">����� ��������</param>
	void setSecond(D second)
	{
		this->secondValue = second;
	}


	/// <summary>
	/// ����������� �������� ��������������� ���� ���������
	/// </summary>
	/// <param name="first">������ ��������</param>
	/// <param name="second">������ ��������</param>
	void set(T first, D second)
	{
		this->firstValue = first;
		this->secondValue = second;
	}


	/// <summary>
	/// ������ ������� �������� ���� T
	/// </summary>
	/// <returns>������ ��������</returns>
	T& getFirst()
	{
		return this->firstValue;
	}


	/// <summary>
	/// ������ ������� �������� ���� D
	/// </summary>
	/// <returns>������ ��������</returns>
	D& getSecond()
	{
		return this->secondValue;
	}


#pragma endregion ACCESS


private:


	/// <summary>
	/// ������ ��������
	/// </summary>
	T firstValue;

	/// <summary>
	/// ������ ��������
	/// </summary>
	D secondValue;


};


#endif