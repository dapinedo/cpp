// ----------------
// assignment1_dpinedo.cpp
// Daniel Pinedo
//-----------------
//Grade: 17/17
#include <iostream>
#include <string>
using namespace std;

int main()
{
	
	// Input - defining variables
	float weight = 0.0;
	float height = 0.0;
	float ActivityLevel = 0.0;
	int age = 0;

	// Input - user input

	cout << "We will calculate how many calories you burned today." << '\n';
	cout << "We will need your weight, height, age and your average daily activity level." << '\n' << '\n';
	cout << "Please enter your weight in pounds[xx.xx] and then press enter key: ";
	cin >> weight;
	cout << "Your weight: " << weight << '\n' << '\n';
	cout << "Please enter your height in feet[xx.xx] and then press enter key: ";
	cin >> height;
	cout << "Your height: " << height << '\n' << '\n';
	cout << "Please enter your age in years[xx] and press enter key: ";
	cin >> age;
	cout << "Your age: " << age << '\n' << '\n';
	cout << "These are the activity numbers for your life style. Please enter just one of them." << '\n';
	cout << "If you have a desk job and do no exercises then enter 1.2" << '\n';
	cout << "If you do light exercise 1 to 3 days a week then enter 1.375" << '\n';
	cout << "If you do moderate exercises 3 to 5 times a week enter 1.55" << '\n';
	cout << "If you do hard exercises 6 to 7 days a week, enter 1.725" << '\n';
	cout << "If you train hard in sports twice a day enter 1.9" << '\n' << '\n';
	cout << "Enter one of the values above now and hit enter: ";
	cin >> ActivityLevel;
	cout << "Your activity level is: " << ActivityLevel << '\n' << '\n';

	// Analysis

	double BMR = 0.0;
	double CaloriesBurned = 0.0;

	BMR = 66 + 6.2*weight + 152.4*height - 6.8*age; // Basic Metabolic Rate
	CaloriesBurned = BMR*ActivityLevel; // Total Calories Burned

	// Output

	cout << string(50, '*') << '\n';
	cout << "You burn " << CaloriesBurned << " calories every day." << '\n';
	cout << "If your caloric intake is more than this number you may wish to exercise more." << '\n' << '\n';

	system("pause");

	return(0);
}