#include "Complex.h"
#include "ComplexNumberList.h"
int main()
{
	ComplexNumberList CL;
	cin >> CL;
	cout << CL;

	system("pause");
	return 0;
}
int main3()
{
	Complex C1(-1.1, -2.1);
	++C1;
	cout << C1;
	cout << C1++ << endl;
	cout << C1;
	system("pause");
	return 0;
}
int main1()
{
	Complex C1, C2;
	cin >> C1 >> C2;
	cout << C1 << C2;

	Complex Sum = C1 + C2;
	Complex Diff = C1 - C2;
	cout << "Sum: " << Sum << endl;
	cout << "Difference: " << Diff << endl;

	if (C1 == C1)
	{
		cout << "They are same." << endl;
	}
	else
	{
		cout << "They are different." << endl;
	}

	if (C1 != 1)
	{
		cout << "They are different." << endl;
	}
	else
	{
		cout << "They are same." << endl;
	}
	system("pause");
	return 0;
 }
int main2()
{
	Complex C1(-1.1, -2.1);
	Complex Sum1 = C1 + 1;
	cout << C1 << " + 1 = " << Sum1 << endl;

	Complex Sum2 = 1 + C1;
	cout << Sum2;
	cout.operator<<(5.5);
	cout.operator<<(endl);

	system("pause");
	return 0;
}