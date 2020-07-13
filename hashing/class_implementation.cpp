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
	price_menu.insert("mango", 100);
	price_menu.insert("apple", 200);
	price_menu.insert("pear", 300);
	price_menu.insert("kiwi", 400);
	price_menu.insert("grapes", 900);
	price_menu.insert("guava", 500);


	price_menu.print();

	int *price = price_menu.search("mango");
	if (price == NULL) {
		cout << "not found! ";
	}
	else {
		cout << "found and the price is " << *price;
	}

	cout << endl << endl;

	price_menu.erase("kiwi");

	price_menu.print();

	price_menu["mango"] = 700;

	cout << "price of mango after update :- " << price_menu["mango"] << endl;


	return 0;
}
