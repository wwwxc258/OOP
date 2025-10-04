#include<iostream>
#include<windows.h>
#include"Fridge.h"
using namespace std;
fridge f1;
void dispaly()
{
	if (f1.CheckIsOpen() == 1)
	{
		cout << "////////////////" << endl;
		cout << "//" << "            " << "//" << endl;
		cout << "//" << "            " << "//" << endl;
		cout << "//" << "            " << "//" << endl;
		if (f1.CheckInside().length() != 0)
		{
			cout << "//" << "  "<<f1.CheckInside()<<"  " << "//" << endl;
		}
		else cout << "//" << "            " << "//" << endl;
		cout << "//" << "            " << "//" << endl;
		cout << "//" << "            " << "//" << endl;
		cout << "//" << "            " << "//" << endl;
		cout << "//" << "            " << "//" << endl;
		cout << "////////////////" << endl;
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			cout << "////////////////" << endl;
		}
	}
}
void OpenFridge()
{
	cout << "ÕýÔÚ´ò¿ª±ùÏäÃÅ£º ";
	int tmp = 5;
	while (tmp)
	{
		cout << "Ê£Óà" << tmp-- << "Ãë" << "  ";
		Sleep(1000);
	}
	cout << endl;
	cout << endl;
	f1.OpenDoor();
	dispaly();
	cout << endl;
	cout << endl;

}
void CloseFridge()
{
	cout << "ÕýÔÚ¹Ø±Õ±ùÏäÃÅ£º ";
	int tmp = 5;
	while (tmp)
	{
		cout << "Ê£Óà" << tmp-- << "Ãë" << "  ";
		Sleep(1000);
	}
	cout << endl;
	cout << endl;
	f1.CloseDoor();
	dispaly();
	cout << endl;
	cout << endl;
}
void Put()
{
	f1.PutInside("Elephant");
	int tmp = 5;
	while (tmp)
	{
		cout << "Ê£Óà" << tmp-- << "Ãë" << "  ";
		Sleep(1000);
	}
	cout << endl;
	cout << endl;
	
	dispaly();
	cout << endl;
	cout << endl;
}
int main(void)
{
	dispaly();
	OpenFridge();
	Put();
	CloseFridge();
	system("pause");

	return 0;
}