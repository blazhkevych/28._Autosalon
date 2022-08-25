#pragma once

#include <string>
#include <vector>
#include "Car.h"

using namespace std;

class Autosalon abstract	
{
	vector<Car*> m_v;
public:
	// Добавление автомобиля.
	void AddAuto();

	// Печать всего списка автомобилей.
	void PrintAll() const;


};

