#pragma once

#include <string>
#include <vector>
#include "Car.h"

using namespace std;

class Autosalon abstract	
{
	vector<Car*> m_v;
public:
	// ���������� ����������.
	void AddAuto();

	// ������ ����� ������ �����������.
	void PrintAll() const;


};

