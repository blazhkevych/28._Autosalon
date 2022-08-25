#include "Volvo.h"

#include <iostream>
#include <fstream>

// ����������� ��� ����������.
Volvo::Volvo() :Car(), m_speed(0) { m_title = "Volvo"; }

Volvo::Volvo(string title, int yearOfIssue, double engineVolume, double price, double speed)
	:Car(title, yearOfIssue, engineVolume, price), m_speed(speed) {
	m_title = "Volvo";
}

// ����������.
Volvo::~Volvo() = default;

// ���������� �������� ���� "��������".
void Volvo::set_speed(double speed) { m_speed = speed; }

// �������� �������� ���� "��������".
double Volvo::get_speed() { return m_speed; }

// ������ ������� "Volvo".
void Volvo::Print()
{
	cout << endl;
	Car::Print();
	cout << "��������: " << m_speed << endl;
}

// ������ ������� "Volvo" � ��������� ����.
void Volvo::Write(ofstream& out)
{
	Car::Write(out);
	out << m_speed << "\n";
}

// ������ ������� "Volvo" �� ���������� �����.
void Volvo::Read(ifstream& in)
{
	Car::Read(in);
	in >> m_speed;
}