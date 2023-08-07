#include "My_vector.h"
#include <iostream>


My_vector::My_vector(int size){
	this->size = size;
	arr = new int[size];
	f = 0;
	l = 0;
}
My_vector::My_vector(const My_vector &obj) {
	size = obj.size;
	arr = new int[size];
	arr = obj.arr;
	l = obj.l;
}
void My_vector::push(int k) {
	arr[l] = k;
	l++;
	l %= size;
}
int My_vector::pop() {
	l--;
	l %= size;
	return arr[l];
}
int My_vector::count() {
	return l;
}
bool My_vector::empty() {
	if (f == l)
		return true;
	return false;
}
int My_vector::first() {

	return arr[l-1];
}
void const My_vector::out() {
	for (int i = f; i != l; i = (i + 1) % size) {
		std::cout << arr[i] << " ";
	}
}
