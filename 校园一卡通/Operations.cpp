#include "Operations.h"
#include<iomanip>
//namespace card;
namespace card
{
	//打印分割线
	void printLine(char c , int len )
	{
		for (int i = 0; i < len; i++)
		{
			cout << c;
		}
		cout << endl;
	}
	//打印标题
	void title(const string& s)
	{
		cout << "\n====" << s << "====\n";
	}
}
//struct Card
//{
//	int id;
//	string name;
//	double balance;
//	int transactions;
//};
Card* createCards(int n)
{
	return new Card[n];
}
void destoryCards(Card* p)
{
	delete[] p;
}
void inputsCards(Card* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "请输入学号、姓名和初始余额：";
		cin >> arr[i].id >> arr[i].name >> arr[i].balance;
		arr[i].transactions = 0;
	}
}
void deposit(Card& c, double amount, double fee )
{
	c.balance += amount * (1.0 - fee);
	c.transactions++;
}
bool spend(Card& c, double cost)
{
	if (c.balance >= cost)
	{
		c.balance -= cost;
		c.transactions++;
		return true;
	}
	else return false;
}
bool spend(Card& c, double cost, const string& item)
{
	cout << "消费项目：" << item << endl;
	return spend(c, cost);
}
void showBalance(const Card& c)
{
	cout << c.name << "当前余额为： " << c.balance << endl;
}
void viewStudentID(const Card* p)
{
	cout << "账户ID为：" << p->id << endl;
}
int  toCent(double amount)
{
	return static_cast<int>(amount * 100);
}
void printReport(const Card* arr, int n)
{
	using card::printLine;
	printLine('=');
	cout << left << setw(8) << "ID"
		<< setw(12) << "Name"
		<< right << setw(14) << "Balance"
		<< setw(14) << "Transactions" << endl;
	printLine('-');
	cout.setf(ios::fixed);
	cout << setprecision(2);
	for (int i = 0; i < n; i++)
	{
		cout << left << setw(8) << arr[i].id
			<< setw(12) << arr[i].name
			<< right << setw(14) << arr[i].balance
			<< setw(14) << arr[i].transactions << endl;

	}
	printLine('=');
}