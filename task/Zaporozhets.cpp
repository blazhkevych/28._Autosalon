#include "Zaporozhets.h"

#include <iostream>
#include <fstream>

// ����������� ��� ����������.
Zaporozhets::Zaporozhets() :Car(), m_numberOfOwners(0) { m_title = "Zaporozhets"; }

Zaporozhets::Zaporozhets(string title, int yearOfIssue, double engineVolume, double price, int m_numberOfOwners)
	:Car(title, yearOfIssue, engineVolume, price), m_numberOfOwners(m_numberOfOwners) {
	m_title = "Zaporozhets";
}

// ����������.
Zaporozhets::~Zaporozhets() = default;

// ���������� �������� ���� "��������".
void Zaporozhets::set_numberOfOwners(int numberOfOwners) { m_numberOfOwners = numberOfOwners; }

// �������� �������� ���� "��������".
int Zaporozhets::get_numberOfOwners() { return m_numberOfOwners; }

// ������ ������� "Zaporozhets".
void Zaporozhets::Print()
{
	cout << endl;
	Car::Print();
	cout << "���������� ����������: " << m_numberOfOwners << endl;
}

// ������ ������� "Zaporozhets" � ��������� ����.
void Zaporozhets::Write(ofstream& out)
{
	Car::Write(out);
	out << m_numberOfOwners << "\n";
}

// ������ ������� "Zaporozhets" �� ���������� �����.
void Zaporozhets::Read(ifstream& in)
{
	Car::Read(in);
	in >> m_numberOfOwners;
}