#ifndef PERSON_BINARY
#define PERSON_BINARY



#include "Person.h"
#include <fstream>
#include <filesystem>
#include <sstream>
#include <cstring>

#include "../FileBufferedReader/FileBufferedReader.h"




// ����� ������� ��������� (�����������) ������ ������ Person
class PersonBinary
{
public:

	// �����������
	// person - ������ ������ ������� �� ���������� �������� � ����
	PersonBinary(Person& person, string filePath);

	// ������ � ����
	void write() const;

	// ������ �� �����;
	Person read(string sPath);

private:

	// ������ �������� ������
	Person& person;

	// ���� � �����
	string filePath;
};


#endif