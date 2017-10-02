#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
//using innovative names for various cost components
//will make your program easy to read for you and
//other programming team members.
const double KID_CONE = 1.00;
const double SMALL_CONE{ 2.00 };
const double MEDIUM_CONE{ 3.00 };
const double LARGE_CONE{ 4.00 };
const double EXTRA_LARGE_CONE{ 5.00 };
const double ORG_COW{ 0.20 };//percent of base cost
const double ORG_GOAT{ 0.30 };//percent of base cost
const double EXTRA_LYCHEES{ 0.50 };//dollars
const double EXTRA_LYCHEES_PCT_BASE{ 0.01 };//percent of base cost
const double EXTRA_GUM_BEARS{ 0.25 };//dollars
const double EXTRA_GUM_BEARS_PCT_BASE{ 0.011 };//percent of base cost
const double EXTRA_STRAWBERRY{ 0.60 };//dollars
const double EXTRA_STRAWBERRY_PCT_BASE{ 0.02 };//percent of base cost
const double EXTRA_KIWI{ 0.75 };//dollars
const double EXTRA_KIWI_PCT_BASE{ 0.015 };//percent of base cost
const double EXTRA_MANGO{ 0.80 };//dollars
const double EXTRA_MANGO_PCT_BASE{ 0.025 };//percent of base cost
const double SALES_TAX{ 0.10 };//percent of total cost
const double SENIOR_DISCOUNT{ 0.15 };//discount % after adding tax

int main() {
	cout << fixed << showpoint << setprecision(2);
	cout << "Welcome to WorldWide Ice Cream store." << endl;
	string first, last;
	cout << "Please enter your first name: ";
	cin >> first;
	cout << "Please enter your last name: ";
	cin >> last;
	cout << "We need to ask your age to process a discount." << endl;
	cout << "Enter your age on last birthday: ";
	unsigned int age{ 0 };
	cin >> age;
	cout << "Hello " << first << ' ' << last << endl;
	bool age_flag{ false };

	if (age >= 55)
	{
		cout << "Congratulations. You qualify for 15% discount." << endl;
		age_flag = true;
	}

	cout << "Enter ice cream size: [K]idde cone, [S]mall, [M]edium, [L]arge, e[X]tra large." << endl;
	char size{ ' ' };
	cin >> size;
	bool flag_size = (size == 'K' || size == 'S' || size == 'M' || size == 'L' || size == 'X');

	cout << "Enter 1 for regular cow milk cream, 2 for organic cow, 3 for goat organic." << endl;
	int milkType{ 0 };
	cin >> milkType;
	bool flag_milk = (milkType == 1 || milkType == 2 || milkType == 3);

	cout << "Enter 1 for no toppings, 2 for Lychees, 3 for Gummy bears, 4 for strawberry, 5 for kiwi fruit, 6 for mango, 7 for all." << endl;
	int toppingType{ 0 };
	cin >> toppingType;
	bool flag_topping = (toppingType == 1 || toppingType == 2 || toppingType == 3
		|| toppingType == 4 || toppingType == 5 || toppingType == 6
		|| toppingType == 7);

	if (flag_size && flag_milk && flag_topping)
	{
		double BaseCost{ 0.0 };
		double TotalCost{ 0.0 };
		//compute cost and discounts if any

		//set the base cost relative to size
		if (size == 'K'){
			BaseCost = KID_CONE;
			cout << "You bought Kiddi cone." << endl;
		}
		else if (size == 'S'){
			BaseCost = SMALL_CONE;
			cout << "You bought small cone." << endl;
		}
		else if (size == 'M'){
			BaseCost = MEDIUM_CONE;
			cout << "You bought medium cone." << endl;
		}
		else if (size == 'L'){
			BaseCost = LARGE_CONE;
			cout << "You bought large cone." << endl;
		}
		else{
			BaseCost = EXTRA_LARGE_CONE;
			cout << "You bought extra large cone." << endl;
		}
		TotalCost = BaseCost;// This is to be done if they do not want any extras

		//add extra due to milk type
		//no extra for milkType = 1
		if (milkType == 1){
			cout << "Your ice cream will be made of regular cow milk." << endl;
		}
		else if (milkType == 2){
			TotalCost = BaseCost + BaseCost*ORG_COW;
			cout << "Your ice cream will be made of organic cow milk." << endl;
		}
		else if (milkType == 3){
			TotalCost = BaseCost + BaseCost*ORG_GOAT;
			cout << "Your ice cream will be made of organic goat milk." << endl;
		}

		//Add extra cost due to toppings. No extra if they do not want any topping
		if (toppingType == 1){
			cout << "You ordered no toppings." << endl;
		}
		else if (toppingType == 2)//Lychees
		{
			TotalCost = TotalCost + EXTRA_LYCHEES
				+ BaseCost*EXTRA_LYCHEES_PCT_BASE;
			cout << "You ordered Lychee topping." << endl;
		}
		else if (toppingType == 3)//Gummy Bears
		{
			TotalCost = TotalCost + EXTRA_GUM_BEARS +
				BaseCost*EXTRA_GUM_BEARS_PCT_BASE;
			cout << "You ordered gummy bears topping." << endl;
		}
		else if (toppingType == 4)//strawberry
		{
			TotalCost = TotalCost + EXTRA_STRAWBERRY +
				BaseCost*EXTRA_STRAWBERRY_PCT_BASE;
			cout << "You ordered strawberry topping." << endl;
		}
		else if (toppingType == 5)//kIWI
		{
			TotalCost = TotalCost + EXTRA_KIWI +
				BaseCost*EXTRA_KIWI_PCT_BASE;
			cout << "You ordered Kiwi fruit topping." << endl;
		}
		else if (toppingType == 6)//MANGO
		{
			TotalCost = TotalCost + EXTRA_MANGO +
				BaseCost*EXTRA_MANGO_PCT_BASE;
			cout << "You ordered mango topping." << endl;
		}
		else if (toppingType == 7)//all toppings
		{
			TotalCost = TotalCost + EXTRA_LYCHEES
				+ BaseCost*EXTRA_LYCHEES_PCT_BASE
				+ EXTRA_GUM_BEARS +
				BaseCost*EXTRA_GUM_BEARS_PCT_BASE
				+ EXTRA_STRAWBERRY +
				BaseCost*EXTRA_STRAWBERRY_PCT_BASE + EXTRA_KIWI +
				BaseCost*EXTRA_KIWI_PCT_BASE
				+ EXTRA_MANGO +
				BaseCost*EXTRA_MANGO_PCT_BASE;
			cout << "You ordered all toppings we offer." << endl;
		}
		//Add tax
		TotalCost = TotalCost*(1 + SALES_TAX);
		//Process senior discount if any
		if (age_flag)
		{
			double originalCostPennies = TotalCost * 100;
			double discountPennies = originalCostPennies*SENIOR_DISCOUNT;
			double FinalCostPennies = round(originalCostPennies - discountPennies);
			TotalCost = FinalCostPennies / 100.00;
			cout << "Total cost of your order including tax: $" << TotalCost << endl;
			cout << "You saved approximately: $" << round(discountPennies) / 100.0 << endl;
		}
		else
		{
			cout << "Total cost of your order is: $" << TotalCost << endl;
			double originalCostPennies = TotalCost * 100;
			int roundedPennies = static_cast<int>(round(originalCostPennies));
			cout << "Cost of your order: " << roundedPennies / 100 << " dollars and "
				<< roundedPennies % 100 << " cents." << endl;
		}
	}
	else
	{
		if (!flag_size)
		{
			cout << "We are unable to process your order because invalid size was entered." << endl;
		}
		if (!flag_milk)
		{
			cout << "We are unable to process your order because invalid code for milk type." << endl;
		}
		if (!flag_topping)
		{
			cout << "We are unable to process your order because invalid code for topping(s)." << endl;
		}
	}
	return 0;
}
/*
Welcome to WorldWide Ice Cream store.
Please enter your first name: s
Please enter your last name: p
We need to ask your age to process a discount.
Enter your age on last birthday: 45
Hello s p
Enter ice cream size: [K]idde cone, [S]mall, [M]edium, [L]arge, e[X]tra large.
X
Enter 1 for regular cow milk cream, 2 for organic cow, 3 for goat organic.
3
Enter 1 for no toppings, 2 for Lychees, 3 for Gummy bears, 4 for strawberry, 5 f
or kiwi fruit, 6 for mango, 7 for all.
7
You bought extra large cone.
Your ice cream will be made of organic goat milk.
You ordered all toppings we offer.
Total cost of your order is: $10.79
Cost of your order: 10 dollars and 79 cents.

Welcome to WorldWide Ice Cream store.
Please enter your first name: s
Please enter your last name: p
We need to ask your age to process a discount.
Enter your age on last birthday: 65
Hello s p
Congratulations. You qualify for 15% discount.
Enter ice cream size: [K]idde cone, [S]mall, [M]edium, [L]arge, e[X]tra large.
X
Enter 1 for regular cow milk cream, 2 for organic cow, 3 for goat organic.
3
Enter 1 for no toppings, 2 for Lychees, 3 for Gummy bears, 4 for strawberry, 5 f
or kiwi fruit, 6 for mango, 7 for all.
7
You bought extra large cone.
Your ice cream will be made of organic goat milk.
You ordered all toppings we offer.
Total cost of your order including tax: $9.17
You saved approximately: $1.62
*/