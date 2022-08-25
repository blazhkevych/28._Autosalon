#pragma once

#include "Car.h"

class Volvo : public Car
{
	double m_speed; // ��������.
public:
	// ����������� ��� ����������.
	Volvo();

	// ����������� �� ����� �����������.
	Volvo(string title, int yearOfIssue, double engineVolume, double price, double speed);

	// ����������.
	~Volvo() override;

	// ���������� �������� ���� "��������".
	void set_speed(double speed);

	// �������� �������� ���� "��������".
	double get_speed();

	// ������ ������� "Volvo".
	void Print() override;

	// ������ ������� "Volvo" � ��������� ����.
	void Write(ofstream& out) override;

	// ������ ������� "Volvo" �� ���������� �����.
	void Read(ifstream& in) override;
};