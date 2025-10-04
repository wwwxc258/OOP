#pragma once
#include<iostream>
#include<string>
using namespace std;
class fridge
{
public:
	void OpenDoor();
	
	void CloseDoor();

	void PutInside(string n);

	bool CheckIsOpen();

	string CheckInside();

private:
	string inside = "";
	bool DoorIsOpen = 0;
};

