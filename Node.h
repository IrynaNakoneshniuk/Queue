#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Node
{
  public:
	  T value;
	  Node* prev;
	  Node* next;
	  Node();
	  Node(T value);
	  T getValue() { return this->value; }
 };

template<typename T>
inline Node<T>::Node()
{
	this->prev = nullptr;
	this->next = nullptr;
	this->value = 0;
}

template<typename T>
inline Node<T>::Node(T value)
{
	this->prev = nullptr;
	this->next = nullptr;
	this->value = value;
}
