#pragma once

#include <string>
#include <vector>
#include "Car.h"

using namespace std;

class Autosalon 	
{
	vector<Car*> m_v;
public:
	// �������� ������ �������.
	int get_size();

	// ���������� ����������.
	void AddAuto();

	// ������ ����� ������ �����������.
	void PrintAll() const;

	// ������ ������� �� ������ �����������.
	void PrintSelective(int choice) const;

	// �������� ���������� �� ������.
	void Delete(int number);

	// ��������� �� ������ ���������� ����������.
	void Change(int number);

	// ����� �� ��������� ��������.
	void Search();

	// ���������� � ����.
	void Save();

	// �������� �� �����.
	void Load();

	// ���������� �� ��������� ��������.
	void Sort();
};