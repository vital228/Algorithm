#pragma once
template<class T>
class Node
{
public:
	T key;
	Node<T>* prev;
	Node<T>* next;
	Node(const T& k = T(), Node<T>* p = nullptr, Node<T>* n = nullptr) : key(k), prev(p), next(n) {}
	~Node() {};
};