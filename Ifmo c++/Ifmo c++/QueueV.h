#pragma once
#include<string>



class QueueException {
	std::string error;
	public:
		QueueException(std::string err) :error(err) {
		}
		const char* getError() { return error.c_str(); }
};


template<class T>
class QueueV
{
	T* arr;
	int size,count;
	int first=0, last = 0;
public:
	QueueV(int maxN)
	{
		size = maxN;
		arr = new T[maxN];
		count = 0;
	}
	void push(T n) {
		try{
			if (count == size) 
				throw QueueException("queue is FULL");		
		}
		catch (QueueException &e) {
			cout << "ERROR: " << e.getError() << endl;
			return;
		}
		count++;
		arr[last] = n;
		last++;
		last = (last + size) % size;
	}
	T pop() {
		try {
			if (count==0) throw QueueException("queue is empty");
		}
		catch (QueueException &e) {
			cout << "ERROR: " << e.getError();
			return 1;
		}
		count--;
		T k = arr[first];
		first++;
		first = (first+size)%size;
		return k;
	}
};

