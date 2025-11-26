#include "MyArray.h"
#include <iostream>
using namespace std;

MyArray::MyArray() : p(nullptr), N(0) {}

MyArray::MyArray(int len, int val) : N(len) {
	p = new int[N];
	for (int i = 0; i < N; ++i) p[i] = val;
}

MyArray::MyArray(const MyArray& other) : N(other.N) {
	p = new int[N];
	for (int i = 0; i < N; ++i) p[i] = other.p[i];
}

MyArray::~MyArray() {
	delete[] p;
}

MyArray MyArray::merge(const MyArray& other) const {
	MyArray res(N + other.N);
	for (int i = 0; i < N; ++i) res.p[i] = p[i];
	for (int i = 0; i < other.N; ++i) res.p[N + i] = other.p[i];
	return res;
}

MyArray MyArray::add(const MyArray& other) const {
	int len = N > other.N ? N : other.N;
	MyArray res(len);
	for (int i = 0; i < len; ++i) {
		int a = i < N ? p[i] : 0;
		int b = i < other.N ? other.p[i] : 0;
		res.p[i] = a + b;
	}
	return res;
}

MyArray MyArray::subtract(const MyArray& other) const {
	int len = N > other.N ? N : other.N;
	MyArray res(len);
	for (int i = 0; i < len; ++i) {
		int a = i < N ? p[i] : 0;
		int b = i < other.N ? other.p[i] : 0;
		res.p[i] = a - b;
	}
	return res;
}

MyArray MyArray::multiply(const MyArray& other) const {
	int len = N > other.N ? N : other.N;
	MyArray res(len);
	for (int i = 0; i < len; ++i) {
		int a = i < N ? p[i] : 0;
		int b = i < other.N ? other.p[i] : 0;
		res.p[i] = a * b;
	}
	return res;
}

MyArray MyArray::divide(const MyArray& other) const {
	int len = N > other.N ? N : other.N;
	MyArray res(len);
	for (int i = 0; i < len; ++i) {
		int a = i < N ? p[i] : 0;
		int b = i < other.N ? other.p[i] : 0;
		res.p[i] = b == 0 ? 0 : a / b;
	}
	return res;
}

void MyArray::print() const {
	for (int i = 0; i < N; ++i) cout << p[i] << " ";
	cout << endl;
}

int MyArray::length() const { return N; }