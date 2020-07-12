#include<iostream>
#include "hashmap.h"
using namespace std;

int main(int argc, char const *argv[])
{

	Hashtable<int> price_menu;

	price_menu.insert("Burger", 120);
	price_menu.insert("Pepsi", 20);
	price_menu.insert("BurgerPizza", 150);
	price_menu.insert("Noodles", 25);
	price_menu.insert("Coke", 12000);

	price_menu.print();



	return 0;
}
