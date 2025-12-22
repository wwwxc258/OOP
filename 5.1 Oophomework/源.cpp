#include <iostream>
#include <cmath>
#include <limits>

class Point2D {
private:
	double x_;
	double y_;
public:
	Point2D(double x = 0, double y = 0)
		: x_(x), y_(y)
	{
		std::cout << "Point2D 构造\n";
	}
	virtual ~Point2D()
	{
		std::cout << "Point2D 析构\n";
	}
	Point2D& move(double dx, double dy)
	{
		x_ += dx;
		y_ += dy;
		return *this;
	}
	virtual void show() const
	{
		std::cout << "Point2D (" << x_ << "," << y_ << ")\n";
	}
	double getX() const { return x_; }
	double getY() const { return y_; }
	friend double distance(const Point2D& lhs, const Point2D& rhs)
	{
		double dx = lhs.x_ - rhs.x_;
		double dy = lhs.y_ - rhs.y_;
		return std::sqrt(dx * dx + dy * dy);
	}
};

class Point3D : public Point2D {
private:
	double z_;
public:
	Point3D(double x = 0, double y = 0, double z = 0)
		: Point2D(x, y), z_(z)
	{
		std::cout << "Point3D 构造\n";
	}
	~Point3D() override
	{
		std::cout << "Point3D 析构\n";
	}
	Point3D& move(double dx, double dy, double dz)
	{
		Point2D::move(dx, dy);
		z_ += dz;
		return *this;
	}
	void show() const override
	{
		std::cout << "Point3D (" << getX() << "," << getY() << "," << z_ << ")\n";
	}
	double getZ() const { return z_; }
};

class Base {
public:
	int a;
protected:
	int b;
private:
	int c;
	static int count;
public:
	Base(int av = 0, int bv = 0, int cv = 0)
		: a(av), b(bv), c(cv)
	{
		++count;
		std::cout << "Base 构造\n";
	}
	virtual ~Base()
	{
		std::cout << "Base 析构\n";
		--count;
	}
	void print() const
	{
		std::cout << "Base 输出 a=" << a << " b=" << b << " c=" << c << "\n";
	}
	static int Manage()
	{
		return count;
	}
protected:
	void setC(int value)
	{
		c = value;
	}
	int getC() const
	{
		return c;
	}
};

int Base::count = 0;

class Derived1 : public Base {
public:
	Derived1(int av = 5, int bv = 6, int cv = 7)
		: Base(av, bv, cv)
	{
		setC(cv);
		std::cout << "Derived1 构造\n";
	}
	~Derived1()
	{
		std::cout << "Derived1 析构\n";
	}
	void reveal() const
	{
		std::cout << "Derived1 a=" << a << " b=" << b << " c=" << getC() << "\n";
	}
};

class Derived2 : protected Base {
public:
	Derived2(int av = 8, int bv = 9, int cv = 10)
		: Base(av, bv, cv)
	{
		setC(cv);
		std::cout << "Derived2 构造\n";
	}
	~Derived2()
	{
		std::cout << "Derived2 析构\n";
	}
	void reveal() const
	{
		std::cout << "Derived2 a=" << a << " b=" << b << " c=" << getC() << "\n";
	}
	void showInherited() const
	{
		std::cout << "Derived2 调用 Base::print\n";
		Base::print();
	}
};

class Derived3 : private Base {
public:
	Derived3(int av = 11, int bv = 12, int cv = 13)
		: Base(av, bv, cv)
	{
		setC(cv);
		std::cout << "Derived3 构造\n";
	}
	~Derived3()
	{
		std::cout << "Derived3 析构\n";
	}
	void reveal() const
	{
		std::cout << "Derived3 a=" << a << " b=" << b << " c=" << getC() << "\n";
	}
	void showInherited() const
	{
		std::cout << "Derived3 调用 Base::print\n";
		Base::print();
	}
};

namespace {

	void discardInput()
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	bool readDoublePair(const char* prompt, double& outX, double& outY)
	{
		std::cout << prompt;
		if (!(std::cin >> outX >> outY)) {
			std::cout << "输入错误\n";
			discardInput();
			return false;
		}
		return true;
	}

	bool readDoubleTriple(const char* prompt, double& x, double& y, double& z)
	{
		std::cout << prompt;
		if (!(std::cin >> x >> y >> z)) {
			std::cout << "输入错误\n";
			discardInput();
			return false;
		}
		return true;
	}

	bool readIntTriple(const char* prompt, int& a, int& b, int& c)
	{
		std::cout << prompt;
		if (!(std::cin >> a >> b >> c)) {
			std::cout << "输入错误\n";
			discardInput();
			return false;
		}
		return true;
	}

	void runPoints()
	{
		double x1, y1;
		if (!readDoublePair("输入点1 x y：", x1, y1)) {
			return;
		}
		double x2, y2;
		if (!readDoublePair("输入点2 x y：", x2, y2)) {
			return;
		}
		Point2D p1(x1, y1);
		Point2D p2(x2, y2);
		p1.show();
		p2.show();

		double dx, dy;
		if (!readDoublePair("点1移动 dx dy：", dx, dy)) {
			return;
		}
		p1.move(dx, dy);
		p1.show();
		std::cout << "两点距离：" << distance(p1, p2) << "\n";

		double px, py, pz;
		if (!readDoubleTriple("输入三维 x y z：", px, py, pz)) {
			return;
		}
		Point3D p3(px, py, pz);
		p3.show();

		double mdx, mdy, mdz;
		if (!readDoubleTriple("三维移动 dx dy dz：", mdx, mdy, mdz)) {
			return;
		}
		p3.move(mdx, mdy, mdz);
		p3.show();
		Point2D projection(p3.getX(), p3.getY());
		std::cout << "投影距离：" << distance(p1, projection) << "\n";
		std::cout << "任务完成\n";
	}

	void runInheritanceDemo()
	{
		int a1, b1, c1;
		if (!readIntTriple("Derived1 a b c：", a1, b1, c1)) {
			return;
		}
		std::cout << "Base计数：" << Base::Manage() << "\n";
		Derived1 d1(a1, b1, c1);
		d1.reveal();
		d1.print();

		int a2, b2, c2;
		if (!readIntTriple("Derived2 a b c：", a2, b2, c2)) {
			return;
		}
		Derived2 d2(a2, b2, c2);
		d2.reveal();
		d2.showInherited();

		int a3, b3, c3;
		if (!readIntTriple("Derived3 a b c：", a3, b3, c3)) {
			return;
		}
		Derived3 d3(a3, b3, c3);
		d3.reveal();
		d3.showInherited();

		std::cout << "构造中 Base：" << Base::Manage() << "\n";
		{
			Derived1 block1;
			Derived2 block2;
			std::cout << "块内 Base：" << Base::Manage() << "\n";
		}
		std::cout << "块外 Base：" << Base::Manage() << "\n";
		std::cout << "任务完成\n";
	}

} // namespace

int main()
{
	while (true) {
		std::cout << "\n任务号（1 点，2 继承，0 退）：";
		int choice = -1;
		if (!(std::cin >> choice)) {
			std::cout << "输入错误\n";
			discardInput();
			continue;
		}
		switch (choice) {
		case 0:
			std::cout << "退出\n";
			return 0;
		case 1:
			runPoints();
			break;
		case 2:
			runInheritanceDemo();
			break;
		default:
			std::cout << "重新输入\n";
			break;
		}
	}
}
