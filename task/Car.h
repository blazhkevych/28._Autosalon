#pragma once

#include <string>

using namespace std;

class Car abstract // ����������� ������� ����� �Car�.
{
protected:
	string m_title;			// �������� ����������.
	int m_yearOfIssue;		// ��� �������.
	double m_engineVolume;	// ����� ���������.
	double m_price;			// ����.
public:
	// ����������� ��� ����������.
	Car();

	// ����������� c� ����� �����������.
	Car(string title, int yearOfIssue, double engineVolume, double price);

	// ����������.
	virtual ~Car();

	// ���������� �������� ���� "��� �������������".
	void set_title(string title);

	// ���������� �������� ���� "��� �������".
	void set_yearOfIssue(int yearOfIssue);

	// ���������� �������� ���� "����� ���������".
	void set_engineVolume(double engineVolume);

	// ���������� �������� ���� "����".
	void set_price(double price);

	// �������� �������� ���� "�������� ����������".
	string get_title();

	// �������� �������� ���� "��� �������".
	int get_yearOfIssue();

	// �������� �������� ���� "����� ���������".
	double get_engineVolume();

	// �������� �������� ���� "����".
	double get_price();

	// ������ ������� "Car".
	virtual void Print();

	// ������ ������� "Car" � ��������� ����.
	virtual void Write(ofstream& out);

	// ������ ������� "Car" �� ���������� �����.
	virtual void Read(ifstream& in);
};