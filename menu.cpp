#include "menu.h"
using namespace std;
using namespace my;
//-------------------------------------------------
int main()
//
// 
//Киселев Андрей Евгеньевич поток 28 группа РРБО-02-19
//
//
{
	console_menu* main_menu = new console_menu("main_menu");

	main_menu->add_item("0. item0");
	main_menu->add_item("1. item1");
	main_menu->add_item("2. item2");
	main_menu->add_item("3. item3");

	main_menu->items[1]->add_item("0 sub item 1.1");

	main_menu->items[1]->items[0]->add_item("0 sub sub item 1.1.1");

	main_menu->items[1]->add_item("1 subitem 1.2");

	console_menu* current_menu;

	current_menu = main_menu;
	cout << "\/" << current_menu->path() << endl;
	current_menu->show();

	char key;
	unsigned index;
	string str;

	for (;;)
	{
		cin >> str;
		key = str[0];

		if (isdigit(key))
		{
			index = atoi(str.c_str());

			if (index < current_menu->items.size())
			{
				current_menu = current_menu->items[index];
				cout << "\/" << current_menu->path() << endl;
				current_menu->show();
			}
			else cerr << "error" << endl;
		}
		else
			if (str == "exit" || str == "quit")  break;
			else
				if (str == "back" && current_menu->parent)
				{
					current_menu = current_menu->parent;
					cout << current_menu->path() << endl;
					current_menu->show();
				}
	}
	delete  main_menu;
	system("pause");
}