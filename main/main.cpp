//Изделие задано с помощью дерева.
//В листьях указаны значения массы соответствующих деталей.
//Требуется: 
//    • рассчитать массу всего изделия; 
//    • организовать обход листьев, 
//        запрашивая новые значения массы и сообщая,
//        как при этом меняется масса изделия.
#include "Tree.h"
#include <fstream>
#include <functional>

void from_file(Tree& t)
{
	fstream f;
	int priority = 0;
	Detail pr;
	f.open("file.txt");
	if (!f.is_open()) return;
	while (!f.eof())
	{
		f >> pr;
		t.push(pr);
	}
	f.close();
}

void from_hand(Tree& t)
{
	int mass = 1;
	string name = "Std_name";

	function<int(string)> f = [](string a)
	{
		int n = 1;
		do
		{
			if (n <= 0) cout << "Введите значение больше 0";
			cout << "\n" << a << "\n";
			cin >> n;
		} while (n <= 0);
		return n;
	};

	int n = f("Введите число деталей");

	for (int i = 0; i < n; i++)
	{
		cout << "Введите название детали\n";
		cin >> name;
		mass = f("Введите время массу этой детали");
		t.push(Detail(name, mass));
	}
}

int main()
{
    setlocale(LC_ALL, "rus");

    Tree t;

    t.push(Detail("A", 10));
    t.push(Detail("B", 19));
    t.push(Detail("C", 20));
    t.push(Detail("D", 23));
    t.push(Detail("E", 1));
    t.push(Detail("F", 2));
    t.push(Detail("G", 11));
    t.push(Detail("H", 12));

	/*from_hand(t);*/

	from_file(t);
   
	int choose = 0;

	while (1)
	{
		system("cls");

		do
		{
			if (choose < 0 || choose > 2)
			{
				system("cls");
				cout << "Введите корректное значение";
			}
			cout << "\n\nВыберите действие\n\n";
			cout << "0 - выйти\n";
			cout << "1 - вывести все детали и вес изделия\n";
			cout << "2 - добавить деталей\n";
			cin >> choose;
		} while (choose < 0 || choose > 2);

		switch (choose)
		{
		case 0:
			return 0;
			break;
		case 1:
			t.print();
			cout << "\nМасса изделия " << t.sum() << endl;
			break;
		case 2:
			cout << "\nИзначальная масса изделия " << t.sum() << endl << endl;
			from_hand(t);
			t.print();
			cout << "\nМасса изделия " << t.sum() << endl;
			break;
		}
		system("pause");
	}

    return 0;
}