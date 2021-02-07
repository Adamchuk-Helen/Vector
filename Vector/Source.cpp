#include<iostream>
#include <vector>
#include<time.h>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	/*��������� ���� ������� vector<int> :
	v1 � �������, ������ �������� � ���������;*/
	int el, My_vec, My_v1, My_v5;
	cout << "How many elements for v1 do you want?" << endl;
	cin >> My_vec;
	cout << "Enter elements for v1" << endl;
	vector <int> v1;
	for (int i = 0; i < My_vec; i++)
	{
		cin >> My_v1;
		v1.push_back(My_v1);
	}
	//v2 � 10 �������� ��������;
	vector <int> v2(10);
	//v3 � ������� ������ � ���������, �������� ����������� ���������� �����;
	cout << "Enter, how many elements have v3" << endl;
	cin >> el;
	vector <int> v3(el);
	srand(time(NULL));
	for (int i = 0; i < el; i++)
	{
		v3[i] = rand() % 100;
	}
	//v4 � ��������� �� �������� v1;
	vector <int> v4(v1);

	//v5 � ��������� �� ������� �� ��������������� �������� v3.
	vector <int> v5;
	if (v3.size() > 2)
	{
		for (int i = 0; i < v3.size() - 2; i++)
		{
			My_v5 = v3[i + 1];
			v5.push_back(My_v5);
		}
	}
	else
	{
		cout << "v3 too small to create v5" << endl;
	}
	//������� �� �������� ������� v3 �� �����

	cout << "--------------V3--------------" << endl;

	for (int i = 0; i < el; i++)
	{
		cout << v3[i] << endl;
	}

	//�� �������� ������� v1 � ����������� ������� � ���� �Numbers.txt

	ofstream out;
	out.open("D:\\Numbers.txt");
	if (out.is_open())
	{
		reverse(v1.begin(), v1.end());
		for (int i = 0; i < My_vec; i++)
		{
			out << v1[i] << endl;
		}
	}
	else
	{
		cout << "File not found " << endl;
	}

	//��������� �������� ������� v2 ������� 1, 2, 3, ..., 10.

	for (int i = 0; i < 10; i++)
	{
		v2[i] = i + 1;
	}
	//������������ �������� ������� v2,

	for (int i = 0; i < 10; i++)
	{
		swap(v2[i], v2[rand() % 9]);
	}

	//�������� ������ �� ������� ��������,

	v2.erase(v2.begin() + 1);
	v2.pop_back();
	//������� �������� ������������� ������� �� �����.
	cout << "--------------V2--------------" << endl;

	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << endl;
	}
	/*������� ����� ������� ������� v4.���������, (12, 10, 35) �(12,
		12, 10, 10, 35, 35)*/

	vector <int> v2double;
	for (int i = 0; i < 8; i++)
	{
		v2double.push_back(v2[i]);
		v2double.push_back(v2[i]);
	}
	swap(v2, v2double);
	//�������� �� �������� ������� v5
	v5.clear();
	//c�������� � v5 ���� ���� �������� v4,
	for (int i = 0; i < v4.size(); i++)
	{
		if (v4[i] % 2 == 0)
		{
			v5.push_back(v4[i]);
		}
	}

	//�������� �������� ������� �������� v5 �����
	for (int i = 0; i < v5.size(); i++)
	{
		v5[i] /= 2;
	}

	//������� �� ����� ������������ ������.
	cout << "--------------V5--------------" << endl;

	for (int i = 0; i < v5.size(); i++)
	{
		cout << v5[i] << endl;
	}

	//������� �������� ������� v4 �� v5.
	swap(v4, v5);


	system("pause");
	return 0;
}