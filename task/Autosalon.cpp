#include "Autosalon.h"

#include <iostream>

#include "Volvo.h"
#include "Zaporozhets.h"
#include "Car.h"

// Добавление автомобиля.
void Autosalon::AddAuto()
{
	int autoCount{ 0 };
	do
	{
		cout << "\nВведите количество автомобилей для добавления в список: ";
		cin >> autoCount;
		cin.get();
	} while (autoCount <= 0);

	int inputNumOfAuto{ 1 };
	vector<Car*>::iterator it;
	for (it = m_v.begin(); it != m_v.end(); it++)
	{
		cout << "\nВыберите " << inputNumOfAuto << " автомобиль: ";
		inputNumOfAuto++;

		cout << "\n(1 - Volvo, 2 - Zaporozhets): ";
		int type;
		cin >> type;
		cin.get();
		switch (type)
		{
		case 1:
			Volvo * vlv = new Volvo;
			m_v.push_back(vlv);
			break;
		case 2:
			Zaporozhets * zap = new Zaporozhets;
			m_v.push_back(zap);
			break;
		default:
			break;
		}

		cout << endl
			<< "Название автомобиля: ";
		string title;
		getline(cin, title);
		it->set_title(title);

		cout << "Год выпуска: ";
		int yearOfIssue{ 0 };
		cin >> yearOfIssue;
		it->set_yearOfIssue(yearOfIssue);

		cout << "Объем двигателя: ";
		double engineVolume{ 0.0 };
		cin >> engineVolume;
		it->set_engineVolume(engineVolume);

		cout << "Цена: ";
		double price{ 0.0 };
		cin >> price;
		it->set_price(price);
	}
}

// Печать всего списка автомобилей.
void Autosalon::PrintAll() const
{
	vector<Car*>::const_iterator it = m_v.begin();
	int count{ 1 };
	for (; it != m_v.end(); it++)
	{
		cout << endl << "Устройство № " << count++ << endl;
		it->;
		cout << "-------------------------------------------------------" << endl;
	}
}
