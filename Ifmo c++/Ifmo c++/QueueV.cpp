#include "QueueV.h"


template<typename T>
QueueV<T>::QueueV(int maxN)
{
	size = maxN;
	arr = new T[maxN];
	count = 0;
}
template<typename T>
void QueueV<T>::push(T n) {
	if (count == size) throw overflow{ "overflow queue" };
	count++;
	arr[last] = n;
	last++;
	lasr %= size;
}
template<typename T>
T QueueV<T>::pop() {
	
	if (first == last) throw isempty{ "queue is empty" };
	count--;
	T k = arr[first];
	first--;
	first %= size;
}


