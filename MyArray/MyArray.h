#ifndef MYARRAY_H
#define MYARRAY_H

class MyArray {
public:
	MyArray();
	MyArray(int len, int val = 0);
	MyArray(const MyArray& other);
	~MyArray();

	MyArray merge(const MyArray& other) const;
	MyArray add(const MyArray& other) const;
	MyArray subtract(const MyArray& other) const;
	MyArray multiply(const MyArray& other) const;
	MyArray divide(const MyArray& other) const;

	void print() const;
	int length() const;

private:
	int* p;
	int N;
};

#endif#pragma once
