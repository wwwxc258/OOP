#include "MyArray.h"
using namespace std;

int main() {
	MyArray a(3, 5);
	MyArray b(4, 2);
	MyArray c = a.merge(b);
	c.print();

	MyArray d = a.add(b);
	d.print();

	MyArray e = a.subtract(b);
	e.print();

	MyArray f = a.multiply(b);
	f.print();

	MyArray g = a.divide(b);
	g.print();

	return 0;
}