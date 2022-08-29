#include "Autosalon.h"

#include <algorithm>
#include <fstream>
#include <iostream>

#include "Volvo.h"
#include "Zaporozhets.h"
#include "Car.h"

using std::cout;
using std::cin;
using std::endl;

// �������� ������ �������.
int Autosalon::get_size() { return m_v.size(); }

// ���������� ����������.
void Autosalon::AddAuto()
{
	int autoCount{ 0 }; // ����������� ���-��.
	do
	{
		cout << "\n������� ���������� ����������� ��� ���������� � ������: ";
		cin >> autoCount;
		cin.get();
	} while (autoCount <= 0);

	int inputNumOfAuto{ 1 }; // ���������� ����� ��������� ����.

	for (int i = 0; i < autoCount; i++)
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
		{
			Volvo* volvo = new Volvo;

			cout << "��� �������: ";
			int yearOfIssue{ 0 };
			cin >> yearOfIssue;
			volvo->set_yearOfIssue(yearOfIssue);

			cout << "����� ���������: ";
			double engineVolume{ 0.0 };
			cin >> engineVolume;
			volvo->set_engineVolume(engineVolume);

			cout << "����: ";
			double price{ 0.0 };
			cin >> price;
			volvo->set_price(price);

			cout << "��������: ";
			double speed{ 0.0 };
			cin >> speed;
			volvo->set_speed(speed);

			m_v.push_back(volvo);
			break;
		}
		case 2:
		{
			Zaporozhets* zap = new Zaporozhets;

			cout << "��� �������: ";
			int yearOfIssue{ 0 };
			cin >> yearOfIssue;
			zap->set_yearOfIssue(yearOfIssue);

			cout << "����� ���������: ";
			double engineVolume{ 0.0 };
			cin >> engineVolume;
			zap->set_engineVolume(engineVolume);

			cout << "����: ";
			double price{ 0.0 };
			cin >> price;
			zap->set_price(price);

			cout << "���������� ����������: ";
			int numberOfOwners{ 0 };
			cin >> numberOfOwners;
			cin.get();
			zap->set_numberOfOwners(numberOfOwners);

			m_v.push_back(zap);
			break;
		}
		default:
			break;
		}
	}
}

// ������ ����� ������ �����������.
void Autosalon::PrintAll() const
{
	vector<Car*>::const_iterator it = m_v.begin();
	int count{ 1 };
	for (; it != m_v.end(); it++)
	{
		cout << endl << "���������� � " << count++ << endl;
		(*it)->Print();
		cout << "-------------------------------------------------------" << endl;
	}
}

// ������ ������� �� ������ �����������.
void Autosalon::PrintSelective(int choice) const
{
	int autoPrinted{ 0 };
	vector<Car*>::const_iterator it = m_v.begin();
	int i{ 1 };
	for (; it != m_v.end(); it++)
	{
		if (typeid(**it) == typeid(Volvo) && choice == 2) // ������ ������ Volvo.			
		{
			autoPrinted++;
			cout << endl << "���������� ����� � ������: " << i << endl << endl
				<< "-------------------------------------------------------";
			(*it)->Print();
			cout << "-------------------------------------------------------" << endl;
		}

		if (typeid(**it) == typeid(Zaporozhets) && choice == 3) // ������ ������ Zaporozhets.			
		{
			autoPrinted++;
			cout << endl << "���������� ����� � ������: " << i << endl << endl
				<< "-------------------------------------------------------";
			(*it)->Print();
			cout << "-------------------------------------------------------" << endl;
		}

		i++;
		/* ��� �����, �� ���� ���� ������ ��������.
		 *if (dynamic_cast<DVD*>(m_mediaList[i])->get_speed() == temp)
			m_mediaList[i]->PrintAll();*/
	}
	cout << endl << "����� ����������� " << autoPrinted << " �����������." << endl;
}

// �������� ���������� �� ������.
void Autosalon::Delete(int number)
{
	number = number - 1;
	vector<Car*>::iterator it = m_v.begin();
	it += number;
	m_v.erase(it);
	m_v;
}

// ��������� �� ������ ���������� ����������.
void Autosalon::Change(int number)
{
	number = number - 1;
	cout << endl << "��� ����� �������� ?"
		<< "\n1 - ��� �������."
		<< "\n2 - ����� ���������."
		<< "\n3 - ����."
		<< "\n4 - �������� / ���������� ����������."
		<< "\n������� ����� ���� ��� ���������, ����� ��� �������� >>> : ";
	int var;
	cin >> var;
	cin.get();

	vector<Car*>::iterator it = m_v.begin();
	it += number;

	switch (var)
	{
	case 1: // ��� �������.
	{
		int temp;
		cin >> temp;
		(*it)->set_yearOfIssue(temp);
		break;
	}
	case 2: // ����� ���������.
	{
		double temp;
		cin >> temp;
		(*it)->set_engineVolume(temp);
		break;
	}
	case 3: // ����.
	{
		double temp;
		cin >> temp;
		(*it)->set_price(temp);
		break;
	}
	case 4: // �������� / ���������� ����������.
	{
		if (typeid(**it) == typeid(Volvo))
		{
			double temp;
			cin >> temp;
			dynamic_cast<Volvo*>(*it)->set_speed(temp);
		}

		if (typeid(**it) == typeid(Zaporozhets))
		{
			int temp;
			cin >> temp;
			dynamic_cast<Zaporozhets*>(*it)->set_numberOfOwners(temp);
		}

		break;
	}
	default:
		cout << "������!" << endl;
		break;
	}
}

// ����� �� ��������� ��������.
void Autosalon::Search()
{
	int autoFound{ 0 }; // ����� ��������� ���������� �����������.
	cout << endl << "��� ����� ������ ?"
		<< "\n1 - �������� ����������."
		<< "\n2 - ��� �������."
		<< "\n3 - ����� ���������."
		<< "\n4 - ����."
		<< "\n5 - ��������."
		<< "\n6 - ���������� ����������."
		<< "\n������� ����� �������� ��� ������, ����� ��� �������� >>> : ";
	int var;
	cin >> var;
	cin.get();

	vector<Car*>::const_iterator it = m_v.begin();
	int i{ 0 };

	switch (var)
	{
	case 1:
	{
		string temp;
		getline(cin, temp);
		for (; it != m_v.end(); it++)
		{
			i++;
			if ((*it)->get_title() == temp) // �������� ����������
			{
				autoFound++;
				cout << endl << "���������� ����� � ������: " << i + 1 << endl << endl
					<< "-------------------------------------------------------";
				(*it)->Print();
				cout << "-------------------------------------------------------" << endl;
			}
		}
		break;
	}
	case 2:
	{
		int temp;
		cin >> temp;
		for (; it != m_v.end(); it++)
		{
			i++;
			if ((*it)->get_yearOfIssue() == temp) // ��� �������.
			{
				autoFound++;
				cout << endl << "���������� ����� � ������: " << i + 1 << endl << endl
					<< "-------------------------------------------------------";
				(*it)->Print();
				cout << "-------------------------------------------------------" << endl;
			}
		}
		break;
	}
	case 3:
	{
		double temp;
		cin >> temp;
		for (; it != m_v.end(); it++)
		{
			i++;
			if ((*it)->get_engineVolume() == temp) // ����� ���������.
			{
				autoFound++;
				cout << endl << "���������� ����� � ������: " << i + 1 << endl << endl
					<< "-------------------------------------------------------";
				(*it)->Print();
				cout << "-------------------------------------------------------" << endl;
			}
		}
		break;
	}
	case 4:
	{
		double temp;
		cin >> temp;
		for (; it != m_v.end(); it++)
		{
			i++;
			if ((*it)->get_price() == temp) // ����.
			{
				autoFound++;
				cout << endl << "���������� ����� � ������: " << i + 1 << endl << endl
					<< "-------------------------------------------------------";
				(*it)->Print();
				cout << "-------------------------------------------------------" << endl;
			}
		}
		break;
	}
	case 5:
	{
		double temp;
		cin >> temp;
		for (; it != m_v.end(); it++)
		{
			i++;
			if (typeid(**it) == typeid(Volvo) && dynamic_cast<Volvo*>(*it)->get_speed() == temp) // �������� Volvo.
			{
				autoFound++;
				cout << endl << "���������� ����� � ������: " << i + 1 << endl << endl
					<< "-------------------------------------------------------";
				(*it)->Print();
				cout << "-------------------------------------------------------" << endl;
			}
		}
		break;
	}
	case 6:
	{
		int temp;
		cin >> temp;
		for (; it != m_v.end(); it++)
		{
			i++;
			if (typeid(**it) == typeid(Zaporozhets) && dynamic_cast<Zaporozhets*>(*it)->get_numberOfOwners() == temp) // ���������� ���������� Zaporozhets.
			{
				autoFound++;
				cout << endl << "���������� ����� � ������: " << i + 1 << endl << endl
					<< "-------------------------------------------------------";
				(*it)->Print();
				cout << "-------------------------------------------------------" << endl;
			}
		}
		break;
	}
	default:
		cout << "������!" << endl;
		break;
	}
	cout << endl << "����� ������� " << autoFound << " �����������." << endl;
}

// ���������� � ����.
void Autosalon::Save()
{
	// ������ �������� �������� ����� � ������������ � ���� ����, ������� ����������� �� ������ � ��������� ������.
	ofstream out("data.txt", ios_base::out | ios_base::trunc);
	if (!out.is_open()) // ���� �������� ����� ����������� �������� - �������.
	{
		cout << "Error!\n";
		return;
	}

	out << m_v.size() << "\n"; // ���������� ���������� ��������� � �������.

	vector<Car*>::const_iterator it = m_v.begin();

	for (; it != m_v.end(); it++)
		(*it)->Write(out);

	out.close(); // ��������� �������� �����.
}

// �������� �� �����.
void Autosalon::Load()
{
	// ������ ������� �������� ����� � ������������ � ���� ����, ������� ����������� �� ������ � ��������� ������.
	ifstream in("data.txt");
	if (!in.is_open()) // ���� �������� ����� ����������� �������� - �������.
	{
		cout << "Error!\n";
		return;
	}

	int size{ 0 };
	in >> size; // ��������� ���������� ���������� �������� � �����.

	m_v.reserve(size); // �������� ������ ��� ��� ���������� �������, ��� ���������� ������������ ����������.

	string title{}; // ������������.

	for (int i = 0; i < size; i++)
	{
		getline(in, title);
		in >> title;

		if (title == "Volvo")
		{
			m_v.insert(m_v.end(), new Volvo);
			m_v[i]->Read(in);
			continue;
		}
		if (title == "Zaporozhets")
		{
			m_v.insert(m_v.end(), new Zaporozhets);
			m_v[i]->Read(in);
		}
	}
	in.close();
}

// ���������� �� "1 - �������� ����������".
bool compare()
{

}

// ���������� �� ��������� ��������.
void Autosalon::Sort()
{
	cout << endl << "�� ������ �������� ����� ����������� ?"
		<< "\n1 - �������� ����������."
		<< "\n2 - ��� �������."
		<< "\n3 - ����� ���������."
		<< "\n4 - ����."
		<< "\n5 - ��������."
		<< "\n6 - ���������� ����������."
		<< "\n������� ����� �������� ��� ���������� >>> : ";
	int var;
	cin >> var;

	vector<Car*>::const_iterator it = m_v.begin();
	int i{ 0 };

	switch (var)
	{
	case 1: // 1 - �������� ����������.
	{
		for (; it != m_v.end(); it++)
		{


		}

		PrintAll();
		break;
	}
	case 2: // 2 - ��� �������.
	{

		break;
	}
	case 3: // 3 - ����� ���������.
	{

		break;
	}
	case 4: // 4 - ����.
	{

		break;
	}
	case 5: // 5 - ��������.
	{

		break;
	}
	case 6: // 6 - ���������� ����������.
	{

		break;
	}
	default:
		cout << "������!" << endl;
		break;
	}
}

// ��������� �����������.
//bool Autosalon::operator<(const Car& other) const
//{
//	return m_ < other.age;
//}