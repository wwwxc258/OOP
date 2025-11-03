#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include"Operations.h"
const double FEE_RATE = 0.02;
const double WARNING_BALANCE = 10.0;
using namespace std;
int main(void)
{
	using card::title;
	using card::printLine;

	title("Campus Card System");
	int n;
	cout << "请输入学生数量：";
	cin >> n;
	Card* users = createCards(n);
    inputsCards(users, n);

	deposit(users[0], 100.0);
	spend(users[0], 8.5, "食堂午餐");
	 
	showBalance(users[0]);
	viewStudentID(&users[0]);

	cout << "换算分为：" << toCent(users[0].balance) << endl;
	printReport(users, n);
	destoryCards(users);
	system("pause");
	return 0;




}