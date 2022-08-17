#pragma once
#include <string>

using namespace std;

// ������ ������ ��� �������� � �����
class Person
{
public:

	// �������� � 1 ����
	char group;

	// �������� � 4 ����� (��� 8 � 64 ������ �������)
	int age;

	// ������ �������� �������� � 1 ����
	bool isMale;

	// �������� � 4 ����� � ��������� �������
	float height;

	// ������ �������� ������������ �����
	const char* name;


	Person()
	{
		this->name = "";
		this->age = 0;
		this->height = 0.0f;
		this->group = '\0';
		this->isMale = false;
	}


	Person(const char* name, int age, float height, char group, bool isMale)
	{
		this->name = name;
		this->age = age;
		this->height = height;
		this->group = group;
		this->isMale = isMale;
	}

};