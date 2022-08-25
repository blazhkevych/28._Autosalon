#include "Autosalon.h"

#include <iostream>

#include "Volvo.h"
#include "Zaporozhets.h"
#include "Car.h"

// ���������� ����������.
void Autosalon::AddDevice()
{
	int autoCount{ 0 };
	do
	{
		cout << "\n������� ���������� ����������� ��� ���������� � ������: ";
		cin >> autoCount;
		cin.get();
	} while (autoCount <= 0);

	int inputNumOfAuto{ 1 };
	vector<Car>::iterator it;
	for (it = m_v.begin(); it != m_v.end(); it++)
	{
		cout << "\n�������� " << inputNumOfAuto << " ����������: ";
		inputNumOfAuto++;

		cout << "\n(1 - Volvo, 2 - Zaporozhets): ";
		int type;
		cin >> type;
		cin.get();
		switch (type)
		{
		case 1:
			Volvo * vlv = new Volvo;
			m_v.push_back(**&vlv);
			break;
		case 2:
			Zaporozhets * zap = new Zaporozhets;
			m_v.push_back(**&zap);
			break;
		default:
			break;
		}

		cout << endl
			<< "�������� ����������: ";
		string title;
		getline(cin, title);
		it->set_title(title);

		cout << "��� �������: ";
		int yearOfIssue{ 0 };
		cin >> yearOfIssue;
		it->set_yearOfIssue(yearOfIssue);

		cout << "����� ���������: ";
		double engineVolume{ 0.0 };
		cin >> engineVolume;
		it->set_engineVolume(engineVolume);

		cout << "����: ";
		double price{ 0.0 };
		cin >> price;
		it->set_price(price);
	}
}

// ������ ����� ������ �����������.
void Autosalon::PrintAll() const
{
	for (int i = 0; i < m_v.size(); i++)
	{
		cout << endl << "���������� � " << i + 1 << endl;
		m_v[i].Print();
		cout << "-------------------------------------------------------" << endl;
	}
}
