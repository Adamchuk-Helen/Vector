#include<iostream>
#include <vector>
#include<time.h>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	/*ќголосити пТ€ть вектор≥в vector<int> :
	v1 Ц порожн≥й, ввести елементи з клав≥атури;*/
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
	//v2 Ц 10 нульових елемент≥в;
	vector <int> v2(10);
	//v3 Ц к≥льк≥сть ввести з клав≥атури, елементи згенерувати випадковим чином;
	cout << "Enter, how many elements have v3" << endl;
	cin >> el;
	vector <int> v3(el);
	srand(time(NULL));
	for (int i = 0; i < el; i++)
	{
		v3[i] = rand() % 100;
	}
	//v4 Ц скоп≥ювати вс≥ елементи v1;
	vector <int> v4(v1);

	//v5 Ц скоп≥ювати в≥д другого до передостаннього елементи v3.
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
	//¬ивести вс≥ елементи вектора v3 на екран

	cout << "--------------V3--------------" << endl;

	for (int i = 0; i < el; i++)
	{
		cout << v3[i] << endl;
	}

	//вс≥ елементи вектора v1 у зворотньому пор€дку у файл СNumbers.txt

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

	//«аповнити елементи вектора v2 числами 1, 2, 3, ..., 10.

	for (int i = 0; i < 10; i++)
	{
		v2[i] = i + 1;
	}
	//ѕеретасувати елементи вектора v2,

	for (int i = 0; i < 10; i++)
	{
		swap(v2[i], v2[rand() % 9]);
	}

	//видалити другий та останн≥й елементи,

	v2.erase(v2.begin() + 1);
	v2.pop_back();
	//вивести елементи результуючого вектора на екран.
	cout << "--------------V2--------------" << endl;

	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << endl;
	}
	/*ѕодвоњти кожен елемент вектора v4.Ќаприклад, (12, 10, 35) Ц(12,
		12, 10, 10, 35, 35)*/

	vector <int> v2double;
	for (int i = 0; i < 8; i++)
	{
		v2double.push_back(v2[i]);
		v2double.push_back(v2[i]);
	}
	swap(v2, v2double);
	//¬идалити вс≥ елементи вектора v5
	v5.clear();
	//cкоп≥ювати у v5 лише парн≥ елементи v4,
	for (int i = 0; i < v4.size(); i++)
	{
		if (v4[i] % 2 == 0)
		{
			v5.push_back(v4[i]);
		}
	}

	//зменшити значенн€ кожного елемента v5 удв≥ч≥
	for (int i = 0; i < v5.size(); i++)
	{
		v5[i] /= 2;
	}

	//вивести на екран результуючий вектор.
	cout << "--------------V5--------------" << endl;

	for (int i = 0; i < v5.size(); i++)
	{
		cout << v5[i] << endl;
	}

	//ќбм≥н€ти елементи вектор≥в v4 та v5.
	swap(v4, v5);


	system("pause");
	return 0;
}