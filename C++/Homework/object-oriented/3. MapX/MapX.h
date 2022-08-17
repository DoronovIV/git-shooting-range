#ifndef MAPX_H
#define MAPX_H


#include <iostream>
#include "Pair.h"



#define COLLECTION_SIZE 10 // ������ ���������



/// <summary>
/// ������������� ������
/// ������ �������� - "����". ������ - "��������"
/// @see "Pair.h"
/// </summary>
template<typename T, typename D>
class MapX
{


public:


#pragma region CONSTRUCT


	/// <summary>
	/// �����������
	/// </summary>
	MapX()
	{
		currentSize = 0;

		for (size_t i = 0ULL; i < COLLECTION_SIZE; i++)
		{
			ptrPairs[i].set(0, 0);
		}
	}


	/// <summary>
	/// ����������� �����������
	/// </summary>
	/// <param name="copy"></param>
	MapX(MapX& copy)
	{
		this->currentSize = copy.currentSize;

		for (size_t i = 0ULL; i < COLLECTION_SIZE; i++)
		{
			put(copy.ptrPairs[i]);
		}
	}


#pragma endregion CONSTRUCT




#pragma region OPERATORS


	/// <summary>
	/// ���������� ��������� ������������
	/// </summary>
	/// <param name="right">������ �������</param>
	/// <returns>����� �������</returns>
	MapX& operator=(MapX& right)
	{
		this->currentSize = right.currentSize;

		for (size_t i = 0ULL; i < COLLECTION_SIZE; i++)
		{
			ptrPairs[i].set(right.ptrPairs[i].getFirst(), right.ptrPairs[i].getSecond());
		}

		return *this;
	}


	/// <summary>
	/// ���������� ��������� ����������
	/// </summary>
	/// <param name="index">���������� ����� ��������</param>
	/// <returns>���� �� ������</returns>
	T& operator[](const int& index)
	{	
		return ptrPairs[index].getFirst();
	}


#pragma endregion OPERATORS





#pragma region ACCESS


	/// <summary>
	/// ������ ���-�� ��������� ���������
	/// </summary>
	/// <returns>������� ������ ���������</returns>
	size_t getSize()
	{
		return this->currentSize;
	}


	/// <summary>
	/// ������ ��� ��������
	/// </summary>
	/// <param name="key">���� ��������</param>
	/// <returns>��������</returns>
	D& getValue(T key)
	{
		for (size_t i = 0; i < currentSize; i++)
		{
			if (key == ptrPairs[i].getFirst()) return ptrPairs[i].getSecond();
		}
		return -1;
	}


	/// <summary>
	/// ������ ��� �����
	/// </summary>
	/// <param name="key">�������� �����</param>
	/// <returns>����</returns>
	T& getKey(D value)
	{
		for (size_t i = 0; i < currentSize; i++)
		{
			if (value == ptrPairs[i].getSecond()) return ptrPairs[i].getFirst();
		}
		return -1;
	}


#pragma endregion ACCESS


	/// <summary>
	/// ���������� ���� � ���������
	/// </summary>
	/// <param name="couple">�� �� ��������, ��������� � ����</param>
	void put(Pair<T,D> couple)
	{
		if (currentSize < COLLECTION_SIZE)
		{
			ptrPairs[currentSize].set(couple.getFirst(), couple.getSecond());

			currentSize += 1;
		}
		else return;
	}


	/// <summary>
	/// ���������� ���� � ���������
	/// </summary>
	/// <param name="key">����</param>
	/// <param name="value">��������</param>
	void put(T key, D value)
	{
		if (currentSize < COLLECTION_SIZE)
		{
			Pair<T,D> couple(key, value);

			put(couple);
		}
		else return;
	}


	/// <summary>
	/// ����� ��������� ��������� � �������
	/// </summary>
	/// <param name="outstream">����� ������</param>
	void forEach(std::ostream& outstream)
	{
		for (size_t i = 0ULL; i < currentSize; i++)
		{
			outstream << "[" << ptrPairs[i].getFirst() << " - " << ptrPairs[i].getSecond() << "]\n";
		}
	}


	/// <summary>
	/// �������� ������� ����� � ���������
	/// </summary>
	/// <param name="key">����</param>
	/// <returns>1 -- true, 2 -- false</returns>
	int containsKey(const T& key) 
	{
		for (size_t i = 0ULL; i < currentSize; i++)
		{
			if (key == ptrPairs[i].getFirst()) return 1;
		}
		return 0;
	}


	/// <summary>
	/// ����� ����� ���������
	/// </summary>
	/// <param name="key">����</param>
	/// <returns>���������� �����</returns>
	int findKey(const T& key) 
	{
		int position = 0;
		for (size_t i = 0ULL; i < currentSize; i++) 
		{
			if (key == ptrPairs[i].getFirst()) position = i;
		}
		return position;
	}


	/// <summary>
	/// ��������� �������� �� �����
	/// </summary>
	/// <param name="key">����</param>
	/// <param name="newValue">����� �������� ��������</param>
	void renew(const T& key, const D& newValue) 
	{
		if (!containsKey(key)) return;
		else 
		{
			ptrPairs[findKey(key)].setSecond(newValue);
		}
	}


private:


	/// <summary>
	/// ������� ������ ��������� (���-�� ������� �����)
	/// </summary>
	size_t currentSize;


	/// <summary>
	/// ������ ��� "����-��������"
	/// </summary>
	Pair<T,D> ptrPairs[10];


};


#endif

