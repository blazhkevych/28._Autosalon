#pragma once

#include "Car.h"

class Zaporozhets :	public Car
{
	int m_numberOfOwners; // ���������� ����������.
public:
	// ����������� ��� ����������.
	Zaporozhets();

	// ����������� �� ����� �����������.
	Zaporozhets(string title, int yearOfIssue, double engineVolume, double price, int m_numberOfOwners);

	// ����������.
	~Zaporozhets() override;

	// ���������� �������� ���� "���������� ����������".
	void set_numberOfOwners(int speed);

	// �������� �������� ���� "���������� ����������".
	int get_numberOfOwners();

	// ������ ������� "Zaporozhets".
	void Print() override;

	// ������ ������� "Zaporozhets" � ��������� ����.
	void Write(ofstream& out) override;

	// ������ ������� "Zaporozhets" �� ���������� �����.
	void Read(ifstream& in) override;
};