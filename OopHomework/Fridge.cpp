#include"Fridge.h"
	void fridge::OpenDoor()
	{
		this->DoorIsOpen = 1;
		cout << "-----冰箱门已打开-----" << endl;
	}
	void fridge::CloseDoor()
	{
		this->DoorIsOpen = 0;
		cout << "-----冰箱门已关闭-----" << endl;
	}
	void fridge::PutInside(string n)
	{
		cout << "正在把" << n << "塞进冰箱：";
		this->inside = n;
	}
	bool fridge::CheckIsOpen()
	{
		return this->DoorIsOpen;
	}
	string fridge::CheckInside()
	{
		return this->inside;
	}
	


