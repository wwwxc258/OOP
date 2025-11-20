#include<iostream>
#include<string>
using namespace std;
namespace card
{
	//打印分割线
	void printLine(char c = '-', int len = 60);

	//打印标题
	void title(const string& s);
};
struct Card
{
	int id;
	std::string name;
	double balance;
	int transactions;
};

Card*createCards(int n);
void destoryCards(Card* p);
void inputCards(Card* arr, int n);
void  inputCards(Card* arr, int n, const string& filename);
void deposit(Card& c, double amount, double fee = 0.02);
int countLines(const string& filename);
bool spend(Card& c, double cost,  const string & item);
void showBalance(const Card& c);
void viewStudentID(const Card* p);
int  toCent(double amount);
void printReport(const Card* arr, int n);

