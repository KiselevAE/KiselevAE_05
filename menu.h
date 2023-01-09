#include <string>
#include <vector>
#include <iostream>
//-----------------------------------------------------------------------------
namespace my
{
	struct console_menu
	{
		console_menu* parent;
		std::string name;
		std::vector<console_menu*> items;
		//---------------------------------
		console_menu(std::string name, console_menu* parent = NULL)
		{
			this->name = name;
			this->parent = parent;
		}
		//---------------------------------
		~console_menu()
		{
			std::cout << "destroy  " << name << std::endl;
			for (unsigned i = 0; i < items.size(); i++)
				if (items[i]) delete items[i];
		}
		//---------------------------------
		console_menu* add_item(std::string item_name)
		{
			console_menu* new_item = new console_menu(item_name, this);
			items.push_back(new_item);
			return  new_item;
		}
		//---------------------------------
		void show()
		{
			for (unsigned i = 0; i < items.size(); i++)   std::cout << items[i]->name << std::endl;
		}
		//---------------------------------
		std::string path()
		{
			std::string s = name;
			console_menu* pos = parent;
			for (; pos;) { s.insert(0, pos->name + "\/"); pos = pos->parent; }
			return s;
		}
	};
};