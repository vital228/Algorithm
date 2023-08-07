#pragma once
#include <vector>
using namespace std;

template<typename T>
T max(vector<T> arr) {
	T max = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}
