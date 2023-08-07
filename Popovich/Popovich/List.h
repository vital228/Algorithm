#pragma once
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;
template<class T>
class List
{
	friend class Node<T>;
	Node<T>* Head;
	Node<T>* Tail;
	int count;
public:
	class Iterator
	{
		friend class List<T>;
		Node<T>* it;
		Iterator(Node<T>* ptr)
		{
			it = ptr;
		}
	public:
		Iterator()
		{
			it = nullptr;
		}
		T& operator*()
		{
			return it->key;
		}
		bool operator==(const Iterator& iter)
		{
			return it == iter.it;
		}
		bool operator!=(const Iterator& iter)
		{
			return it != iter.it;
		}

		Iterator& operator--()
		{
			if (it->prev == nullptr) throw "Out of range";
			it = it->prev;
			return *this;
		}
		Iterator& operator--(int notused)
		{
			if (it->prev == nullptr) throw "Out of range";
			Iterator tmp = *this;
			it = it->prev;
			return tmp;
		}
		Iterator& operator++()
		{
			if (it->next == nullptr) throw "Out of range";
			it = it->next;
			return *this;
		}
		Iterator& operator+(int n)
		{
			for (int i = 0; i < n; i++)
			{
				this->operator++();
			}
			return *this;
		}
		Iterator& operator-(int n)
		{
			for (int i = 0; i < n; i++)
			{
				this->operator--();
			}
			return *this;
		}
		Iterator& operator++(int notused)
		{
			if (it->next == nullptr) throw "Out of range";
			Iterator tmp = *this;
			it = it->next;
			return tmp;
		}
	};

	friend class Iterator;
	List();
	~List();
	void insert(Iterator i, const T& value);
	void pop_back();
	void del(Iterator i);
	void push_back(const T& value);
	void add(const T& value);
	bool find(const T& value);
	void redactor(Iterator i, const T& value);
	void print();
	void printEl(Iterator i, bool con);
	int size()
	{
		return count;
	}
	Iterator begin() const
	{
		return Iterator(Head);
	}
	Iterator end() const
	{
		return Iterator(Tail);
	}
	T& operator[](int index)
	{
		Iterator it = begin() + index;
		return *it;
	}
};

template<class T>
List<T>::List()
{
	Head = new Node<T>();
	Tail = Head;
	count = 0;
}

template<class T>
List<T>::~List()
{
	while (Head != Tail)
	{
		pop_back();
	}
	delete Head;
	Head = Tail = nullptr;
}

template<class T>
void List<T>::pop_back()
{
	if (Head == Tail)
	{
		throw "List is empty";
	}
	Node<T>* tmp = Tail->prev;
	if (tmp->prev == nullptr)
	{
		Head = Tail;
		count--;
	}
	else
	{
		tmp->prev->next = Tail;
		Tail->prev = tmp->prev;
		count--;
	}
	delete tmp;
};

template<class T>
void List<T>::del(Iterator i)
{
	if (Head == Tail)
	{
		throw "List is empty";
	}
	Node<T>* tmp = Head;
	while (tmp != Tail)
	{
		if (i == Iterator(tmp))
		{
			if (tmp == Head)
			{
				tmp->next->prev = nullptr;
				Head = tmp->next;
				delete tmp;
				count--;
				return;
			}
			else
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				delete tmp;
				count--;
				return;
			}
		}
		tmp = tmp->next;
	}
}

template<class T>
void List<T>::push_back(const T& value)
{
	Node<T>* tmp = new Node<T>(value, nullptr, Tail);
	if (Head == Tail)
	{
		Tail->prev = tmp;
		Head = tmp;
		count++;
	}
	else
	{
		tmp->prev = Tail->prev;
		Tail->prev->next = tmp;
		Tail->prev = tmp;
		count++;
	}
}

template<class T>
void List<T>::insert(Iterator i, const T& value)
{
	if (Head == Tail)
	{
		Node<T>* tmp = new Node<T>(value, nullptr, Tail);
		Tail->prev = tmp;
		Head = tmp;
		count++;
		return;
	}
	if (i == Iterator(Head))
	{
		Node<T>* tmp = new Node<T>(value);
		Head->prev = tmp;
		tmp->next = Head;
		Head = tmp;
		count++;
		return;
	}
	else if (i == Iterator(Tail))
	{
		push_back(value);
		//тут удалил count++
		return;
	}
	else if (i == Iterator(Tail->prev))
	{
		Node<T>* tmp = new Node<T>(value, Tail->prev->prev, Tail->prev);
		Tail->prev->prev->next = tmp;
		Tail->prev->prev = tmp; // тут исправил
		count++;
		return;
	}
	Node<T>* tp = Head;
	while (tp->next != Tail)
	{
		if (i == Iterator(tp))
		{
			Node<T>* tmp = new Node<T>(value, tp->prev, tp);
			tp->prev->next = tmp;
			tp->prev = tmp;
			count++;
			return;
		}
		tp = tp->next;
	}
}

template<class T>
inline void List<T>::add(const T& value)
{
	push_back(value);
	Node<T>* tmp = Head;
	for (tmp; tmp != Tail; tmp = tmp->next)
	{
		Node<T>* tmpn = tmp->next;
		for (tmpn; tmpn != Tail; tmpn = tmpn->next)
		{
			if (tmp->key > tmpn->key)
			{
				if (tmp->prev != nullptr)
				{
					tmp->prev->next = tmpn;
					tmpn->prev->next = tmpn->next;
					tmpn->next->prev = tmpn->prev;
					tmpn->prev = tmp->prev;
					tmp->prev = tmpn;
					tmpn->next = tmp;
				}
				else
				{
					Tail->prev = tmpn->prev;
					tmpn->prev->next = Tail;
					tmpn->next = tmp;
					tmp->prev = tmpn;
					tmp->prev = nullptr;
					Head = tmpn;
				}
			}
		}
	}
}

template<class T>
void List<T>::redactor(Iterator i, const T& value)
{
	Node<T>* tmp = Head;
	while (tmp != Tail)
	{
		if (i == Iterator(tmp))
		{
			tmp->key = value;
			return;
		}
		tmp = tmp->next;
	}
}

template<class T>
bool List<T>::find(const T& value)
{
	Node<T>* tmp = Head;
	for (tmp; tmp != Tail; tmp = tmp->next)
	{
		if (value == tmp->key)
		{
			return true;
		}
	}
	return false;
}

template<class T>
void List<T>::print()
{
	Iterator i = begin();
	for (; i != end(); ++i)
	{
		cout << *i << "\n";
	}
}

template<class T>
void List<T>::printEl(Iterator i, bool con)
{
	if (con)
	{
		cout << *i << "\n";
	}
}