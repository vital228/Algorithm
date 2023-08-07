#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
#include "Marsh.h"
#include  <windows.h>
using namespace std;
void addname(List<Toy>& W, Toy temp) {
	int cnt = 0;
	// �� ��������� �� ������ �� ����� ������� ���� ���������
	for (auto itr = W.begin(); itr != W.end(); itr++)
	{
		Toy temp2 = *itr;
		// ���� ����� ���������, ��� ��� ������ ������, ��������� ����� ��� � ������� �� �������
		if (temp2.CompareToyname(temp))
		{
			W.insert(itr, temp);
			return;
		}
	}
	// ���� ���-� �����
	W.insert(W.end(), temp);
}
void addcost(List<Toy>& W, Toy temp) {
	int cnt = 0;
	// �� ��������� �� ������ �� ����� ������� ���� ���������
	for (auto itr = W.begin(); itr != W.end(); itr++)
	{
		Toy temp2 = *itr;
		// ���� ����� ���������, ��� ��� ������ ������, ��������� ����� ��� � ������� �� �������
		if (temp2.CompareToycost(temp))
		{
			W.insert(itr, temp);
			return;
		}
	}
	// ���� ���-� �����
	W.insert(W.end(), temp);
}
void addcategory(List<Toy>& W, Toy temp) {
	int cnt = 0;
	// �� ��������� �� ������ �� ����� ������� ���� ���������
	for (auto itr = W.begin(); itr != W.end(); itr++)
	{
		Toy temp2 = *itr;
		// ���� ����� ���������, ��� ��� ������ ������, ��������� ����� ��� � ������� �� �������
		if (temp2.CompareToycategory(temp))
		{
			W.insert(itr, temp);
			return;
		}
	}
	// ���� ���-� �����
	W.insert(W.end(), temp);
}
void addlimitation(List<Toy>& W, Toy temp) {
	int cnt = 0;
	// �� ��������� �� ������ �� ����� ������� ���� ���������
	for (auto itr = W.begin(); itr != W.end(); itr++)
	{
		Toy temp2 = *itr;
		// ���� ����� ���������, ��� ��� ������ ������, ��������� ����� ��� � ������� �� �������
		if (temp2.CompareToylimitation(temp))
		{
			W.insert(itr, temp);
			return;
		}
	}
	// ���� ���-� �����
	W.insert(W.end(), temp);
}

int main()
{
	SetConsoleCP(1251);
	
	SetConsoleOutputCP(1251);
	cout << "1. ���� � ����������.\n";
	cout << "2. ���� � �����.\n";
	cout << "3. ����������� ������� ����� �������� ����������� �� ����������.\n";
	cout << "4. ����� ������ � �������.\n";
	cout << "5. ����� ������ � ����.\n";
	cout << "0. �����.\n";
	int enter = 1;
	
	List<Toy> list;
	List<Toy> listsort;
	while (enter)
	{
		cout << "������� �����: ";
		cin >> enter;
		switch (enter)
		{
		case(0):
		{
			cout << "�����.";
			return 0;
		}
		case(1):
		{
			cout << "1.������������� �� ��������.\n";
			cout << "2.������������� �� ���������.\n";
			cout << "3.������������� �� ���������.\n";
			cout << "4.������������� �� �����������.\n";
			int n;
			cin >> n;
			if (n == 1) {
				int k;
				cin >> k;
				for (int i = 0; i < k; i++)
				{
					Toy toy;
					cin >> toy;
					int cnt = 0;
					//  ��������� ��������� � ������
					if (list.size() == 0)
						list.insert(list.begin(), toy);
					else
						addname(list, toy);
				}
				break;
			}
			if (n == 2) {
				int k;
				cin >> k;
				for (int i = 0; i < k; i++)
				{
					Toy toy;
					cin >> toy;
					//  ��������� ��������� � ������
					if (list.size() == 0)
						list.insert(list.begin(), toy);
					else
						addcost(list, toy);
				}
				break;
			}
			if (n == 3) {
				int k;
				cin >> k;
				for (int i = 0; i < k; i++)
				{
					Toy toy;
					cin >> toy;
					int cnt = 0;
					//  ��������� ��������� � ������
					if (list.size() == 0)
						list.insert(list.begin(), toy);
					else
						addcategory(list, toy);
				}
				break;
			}
			if (n == 4) {
				int k;
				cin >> k;
				for (int i = 0; i < k; i++)
				{
					Toy toy;
					cin >> toy;
					int cnt = 0;
					//  ��������� ��������� � ������
					if (list.size() == 0)
						list.insert(list.begin(), toy);
					else
						addlimitation(list, toy);
				}
				break;
			}
			
		}
		case(2):
		{
			cout << "1.������������� �� ��������.\n";
			cout << "2.������������� �� ���������.\n";
			cout << "3.������������� �� ���������.\n";
			cout << "4.������������� �� �����������.\n";
			int n;
			cin >> n;
			if (n == 1) {
				int k; Toy toy;
				ifstream file("input.txt");
				file >> k;
				for (int i = 0; i < k; i++)
				{
					file >> toy;
					if (list.size() == 0)
						list.insert(list.begin(), toy);
					else
						addname(list, toy);
				}
				file.close();
				break;
			}
			if (n == 2) {
				int k; Toy toy;
				ifstream file("input.txt");
				file >> k;
				for (int i = 0; i < k; i++)
				{
					file >> toy;
					if (list.size() == 0)
						list.insert(list.begin(), toy);
					else
						addcost(list, toy);
				}
				file.close();
				break;
			}
			if (n == 3) {
				int k; Toy toy;
				ifstream file("input.txt");
				file >> k;
				for (int i = 0; i < k; i++)
				{
					file >> toy;
					if (list.size() == 0)
						list.insert(list.begin(), toy);
					else
						addcategory(list, toy);
				}
				file.close();
				break;
			}
			if (n == 4) {
				int k; Toy toy;
				ifstream file("input.txt");
				file >> k;
				for (int i = 0; i < k; i++)
				{
					file >> toy;
					if (list.size() == 0)
						list.insert(list.begin(), toy);
					else
						addlimitation(list, toy);
				}
				file.close();
				break;
			}
		}
		case(3):
		{
			cout << "�������� ��������� � ���������� �����������(�� ������� ���)\n";
			string cat;
			int ogr;
			int i = 0;
			cin >> cat >> ogr;
			while(i<list.size()) {
				if ((list[i].getE() == cat) and (list[i].getT() >= ogr)) {
					cout << list[i] << endl;
				}
				i++;
			}
			break;

		}
		case(4):
		{
			list.print();
			break;
		}
		case(5):
		{
			ofstream fout("output.txt");
			List<Toy>::Iterator i = list.begin();
			for (; i != list.end(); i++)
			{
				fout << *i << "\n";
			}
			fout.close();
			break;
		}
		default:
		{
			cout << "�������� ����.\n";
			break;
		}
		}
	}
	return 0;
}