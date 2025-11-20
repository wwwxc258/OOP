#include "Operations.h"
#include<iomanip>
#include<stdexcept>
#include<cstdlib>
#include<fstream>
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
using namespace std;
const double FEE_RATE = 0.02;
const double WARNING_BALANCE = 10.0;
Card* createCards(int n)
{
	try
	{return new Card[n];}
	catch (const bad_alloc& e)
	{
		cerr << "分配内存失败：" << e.what() << endl;
		exit(EXIT_FAILURE);
	}
}
void destoryCards(Card* p)
{
	if(p!=nullptr)
	{delete[] p;}
}
void inputCards(Card* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "请输入学号、姓名和初始余额：";
		try
		{
			cin >> arr[i].id >> arr[i].name >> arr[i].balance;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				throw runtime_error("输入格式错误，请输入正确的数据类型。");
			}

			if (arr[i].balance < 0)
			{
				throw invalid_argument("初始余额不能为负数！");
			}

			arr[i].transactions = 0;
		}
		catch (const exception& e)
		{
			cout << "输入异常：" << e.what() << endl;
			i--;  // 重新输入当前账户
		}
	}
}
void  inputCards(Card* arr, int n, const string& filename)
{

	ifstream fin(filename);
	if (!fin.is_open())
	{
		throw runtime_error("无法打开文件：" + filename);
	}


	int count = 0;
	while (count < n && fin >> arr[count].id >> arr[count].name >> arr[count].balance)
	{
		if (arr[count].balance < 0)
		{
			throw invalid_argument("文件中存在非法余额（负数）数据！");
		}
		arr[count].transactions = 0;
		count++;
	}

	
	if (count < n)
	{
		throw invalid_argument("文件数据不足，无法完成账户录入。");
	}

	fin.close();
	cout << "已成功从文件读取 " << count << " 条校园卡信息。" << endl;
}
int countLines(const string& filename)
{
	ifstream fin(filename);
	if (!fin.is_open())
	{
		throw runtime_error("无法打开文件：" + filename);
	}

	int count = 0;
	string line;

	// 逐行读取
	while (getline(fin, line))
	{
		// 去除空白行判断
		if (!line.empty() && line.find_first_not_of(" \t\r\n") != string::npos)
		{
			count++;
		}
	}

	fin.close();
	return count;
}
void deposit(Card& c, double amount, double fee )
{
	if (amount < 0)
	{
		throw invalid_argument("充值金额不能为负数！");
	}
	if (fee < 0 || fee >= 1)
	{
		throw invalid_argument("手续费率必须在0~1之间！");
	}

	c.balance += amount * (1.0 - fee);
	c.transactions++;
}
bool spend(Card& c, double cost, const string& item)
{
	cout << "消费项目：" << item << endl;

	try
	{
		if (cost < 0)
		{
			throw invalid_argument("消费金额不能为负数！");
		}

		if (c.balance < cost)
		{
			throw runtime_error("余额不足，消费失败！");
		}
		c.balance -= cost;
		c.transactions++;

		return true;
	}
	catch (const exception& e)
	{
		cout << "异常提示：" << e.what() << endl;
		return false;
	}
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