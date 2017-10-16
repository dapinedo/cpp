#include "Vehicle.h"
#include "Airpalne.h"
int main()
{
	Airplane AP1(600.1, 4);
	Vehicle & VEH = AP1;// This works because inheritance imparts this property
	VEH.describe();

	Vehicle * VPtr = new Airplane(700.2, 6);
	(*VPtr).describe();

	system("pause");
	return 0;
}
int main1()
{
	{
	Vehicle VH1(45.1);
	cout << "Speed: " << VH1.getSpeed() << endl;
	VH1.describe();
	
		Airplane AP1(600.1, 4);
		cout << "Speed: " << AP1.getSpeed() << endl;
		AP1.describe();
	}
	system("pause");
	return 0;
}