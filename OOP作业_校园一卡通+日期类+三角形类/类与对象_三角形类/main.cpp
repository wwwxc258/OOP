#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a < b;
}
class Triangle
{
private:
	double a;
	double b;
	double c;
public:
	void Init()
	{
		cout << "初始化三角形，三个边长全为0" << endl;
		a = 0;
		b = 0;
		c = 0;
	}
	bool isTriangle()
	{
		if (a + b <= c || a + c <= b || b + c <= a)
		{
			return false;
		}
		else return true;
	}
	double getSideA()
	{
		return a;
	}
	double getSideB()
	{
		return b;
	}
	double getSideC()
	{
		return c;
	}
	void set_SideA(double x)
	{
		a = x;
	}
	void set_SideB(double x)
	{
		b = x;
	}
	void set_SideC(double x)
	{
		c = x;
	}
	double perimeter()
	{
		return a + b + c;
	}
	double area()
	{
		double p = perimeter() / 2.0;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	int typeTriangle()
	{
		double nums[5];
		nums[1] = a;
		nums[2] = b;
		nums[3] = c;
		sort(nums+1, nums + 4);
		if (nums[3]*nums[3] == nums[1] * nums[1] + nums[2] * nums[2])
		{
			return 1;
		}
		else if (nums[3]*nums[3]>nums[1] * nums[1] + nums[2] * nums[2])
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}
};
int main(void)
{
	Triangle t;
	t.Init();

	cout << "请输入边长a：";
	double x;
	cin >> x;
	t.set_SideA(x);
	cout << endl;

	cout << "请输入边长b：";
	
	cin >> x;
	t.set_SideB(x);
	cout << endl;

	cout << "请输入边长c：";
	
	cin >> x;
	t.set_SideC(x);
	cout << endl;

	if (t.isTriangle() == 1)
	{
		cout << "三角形创建成功！" << endl;
	}
	else
	{
		cout << "三角形创建失败！" << endl;
		return 0;
	}

	cout << "边长A的长度为：" << t.getSideA() << endl;
	cout << "边长B的长度为：" << t.getSideB() << endl;
	cout << "边长C的长度为：" << t.getSideC() << endl;

	cout << "三角形的周长：" << t.perimeter() << endl;
	cout << "三角形的面积：" << t.area() << endl;

	cout << "三角形类型：";
	if (t.typeTriangle() == 1) cout << "直角三角形";
	else if (t.typeTriangle() == 2) cout << "钝角三角形";
	else cout << "锐角三角形";
	cout << endl;




}