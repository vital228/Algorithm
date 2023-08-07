#pragma once
class My_vector
{
private:
	int *arr;
	int size;
	int f, l;
public:
	
	My_vector(int size);
	My_vector(const My_vector &obj);
	void push(int k);
	int pop();
	int count();
	bool empty();
	int first();
	void const out();

};

