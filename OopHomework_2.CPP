#include<iostream>
#include<string>
using namespace std;
bool test3 = 0;
class Student
{
public:
	string name;
	double c_score=0;
	double m_score=0;
	double e_score=0;
	double avg = 0;
	void GetAverage()
	{
		this->avg= (this->c_score + this->e_score + this->m_score) / 3.0;
	}
};
int countVowels(const char* p)
{
	
	if (*p == 'a' ||
		*p == 'e' || *p == 'i' ||
		*p == 'o' ||
		*p == 'u'||
		*p=='A'||
		*p=='E'||
		*p=='I'||
		*p=='O'||
		*p=='U') return 1;
	else return 0;
}
inline double square(double x)
{
	return x * x;
}
double power(double x, int exponent = 2)
{
	double ans = 1;
	bool flag = 1;
	if (exponent < 0)
	{
		flag = 0;
		exponent = -exponent;
	}
	
	for (int i = 1; i <= exponent; i++)
	{
		ans *= x;
	}
	return flag == 1 ? ans : 1.0 / ans;
}
double calc(double a, double b, char op)
{
	if (op == '+') return a + b;
	if (op = '-') return a - b;
	if (op == '*') return a * b;
	if (op == '/')
	{
		if (b == 0)
		{
			//test3 = 1;
			return 0;
		}
		else
			return a / b;
	}
}
double calc(int a, int b, char op)
{
	if (op == '+') return a + b;
	if (op = '-') return a - b;
	if (op == '*') return a * b;
	if (op == '/')
	{
		if (b == 0)
		{
			//test3 = 1;
			return 0;
		}
		else
			return a / b;
	}
}
void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}
void swap(double& x, double y)
{
	double t = x;
	x = y;
	y = t;
}
int main(void)
{
	int choose = -1;
	while (choose)
	{
		
		cout << "0.退出" << endl;
		cout << "1.完成任务1：" << endl;
		cout << "2.完成任务2：" << endl;
		cout << "3.完成任务3：" << endl;
		cout << "4.完成任务4：" << endl;
		cout << "请选择操作：";
		cin >> choose;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (choose)
		{
		case 1:
		{
			int n;
			cout << "请输入学生的数量：";
			cin >> n;
			cout << endl;
			Student nums[10010];
			for (int i= 1; i <= n; i++)
			{
				cin >> nums[i].name >> nums[i].c_score >> nums[i].m_score >> nums[i].e_score;
				//scanf("%s %d %d %d", &nums[i].name, &nums[i].c_score, &nums[i].m_score, &nums[i].e_score);
				nums[i].GetAverage();
			}
			for (int i = 1; i <= n; i++)
			{
				//cout << nums[i].name << " " << nums[i].c_score << " " << nums[i].m_score << " " << nums[i].e_score << " " << nums[i].avg << " ";
				cout << nums[i].name << " ";
				printf(" % .2f % .2f % .2f, % .2f", nums[i].c_score, nums[i].m_score, nums[i].e_score,nums[i].avg);
				if (nums[i].avg >= 90) cout << "Excellent";
				cout << endl;
			}
			break;
		}
		case 2:
		{
			cout << "输入：" << endl;
			string s;
			//cin >> s;
			getline(cin,s);
			
			int ans = 0;
			for (int i = 0; i < s.size(); i++)
			{
				const char* p = &s[i];
				ans+=countVowels(p);
			}
			cout << s << endl;
			cout << "输出：" << endl << "Number of vowels:" << ans << endl;
			break;
		}
		case 3:
		{
			cout << "输入：" << endl;
			int a, b;
			char ch;
			cin >> a >> b >> ch;
			printf("square(%d) = %.2f\n", a, square(a));
			printf("power(%d,3) = %.2f\n", a,power(a, 3));
			
			if (b != 0)
				printf("%d %c %d = %.2f\n", a,ch,b, calc(a, b, ch));
			else cout << "Error: divide by zero" << endl;
		}
		case 4:
		{
			cout << "输入：" << endl;
			int x, y;
			cin >> x >> y;
			printf("Before swap: x=%d, y=%d\n", x, y);
			swap(x, y);
			printf("After  swap: x=%d, y=%d\n", x, y);
		}
		}
	}
	return 0;
}