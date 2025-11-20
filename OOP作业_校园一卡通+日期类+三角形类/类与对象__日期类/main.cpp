#include<iostream>
#include<cmath>
using namespace std;
string weekday[] = { "日", "一", "二", "三", "四", "五", "六" };
class Date
{
private:
	int year=0;
	int month=0;
	int date=0;
public:
	void Init()
	{
		printf("调用初始化函数，全部初始化为0000-0-0");
		year = 0;
		month = 0;
		date = 0;
	}
	int getYear()
	{
		return year;
	}
	int getMonth()
	{
		return month;
	}
	int getDate()
	{
		return date;
	}
	void setYear(int a)
	{
		year = a;
	}
	void setMonth(int a)
	{
		month = a;
	}
	void setDate(int a)
	{
		date = a;
	}
	void display()
	{
		cout << "日期为：" << year << " 年 " << month << " 月 " << date << " 日 " << endl;
	}
	int calWeekday()
	{
		return (date + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;
	}
};
int main(void)
{
	Date d;
	d.Init();
	d.display();

	cout << "设置year：";
	int year;
	cin >> year;
	d.setYear(year);
	d.display();

	cout << "设置month：";
	int month;
	cin >> month;
	d.setMonth(month);
	d.display();

	cout << "设置date：";
	int date;
	cin >> date;
	d.setDate(date);
	d.display();

	cout << "日期是周" << weekday[d.calWeekday()] << endl;

	
}