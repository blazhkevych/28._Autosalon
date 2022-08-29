#include "Car.h"

#include <fstream>
#include <iostream>

using namespace std;

// ����������� ��� ����������.
Car::Car() :m_title("unknown"), m_yearOfIssue(0), m_engineVolume(0.0), m_price(0.0) {}

// ����������� c� ����� �����������.
Car::Car(string title, int yearOfIssue, double engineVolume, double price) :
	m_title(title), m_yearOfIssue(yearOfIssue), m_engineVolume(engineVolume), m_price(price) {}

// ����������.
Car::~Car() = default;

// ���������� �������� ���� "��� �������������".
void Car::set_title(string title) { m_title = title; }

// ���������� �������� ���� "��� �������".
void Car::set_yearOfIssue(int yearOfIssue) { m_yearOfIssue = yearOfIssue; }

// ���������� �������� ���� "����� ���������".
void Car::set_engineVolume(double engineVolume) { m_engineVolume = engineVolume; }

// ���������� �������� ���� "����".
void Car::set_price(double price) { m_price = price; }

// �������� �������� ���� "�������� ����������".
string Car::get_title() { return m_title; }

// �������� �������� ���� "��� �������".
int Car::get_yearOfIssue() { return m_yearOfIssue; }

// �������� �������� ���� "����� ���������".
double Car::get_engineVolume() { return m_engineVolume; }

// �������� �������� ���� "����".
double Car::get_price() { return m_price; }

// ������ ������� "Car".
void Car::Print()
{
	cout << "�������� ����������: " << m_title << endl
		<< "��� �������: " << m_yearOfIssue << endl
		<< "����� ���������: " << m_engineVolume << endl
		<< "����: " << m_price << endl;
}

// ������ ������� "Car" � ��������� ����.
void Car::Write(ofstream& out)
{
	out << m_title << "\n" // ����� ������, ��� ��������� ��� �� ����� ���������� �� �����.
		<< m_yearOfIssue << "\n"
		<< m_engineVolume << "\n"
		<< m_price << "\n";
}

// ������ ������� "Car" �� ���������� �����.
void Car::Read(ifstream& in)
{
	in.get(); // ������� "\n", ������� ������� ����� ���������� ������������ � ���� ��������.
	in >> m_yearOfIssue;
	in >> m_engineVolume;
	in >> m_price;
}