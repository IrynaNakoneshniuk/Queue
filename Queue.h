#pragma once
#include "Node.h"
#include <iostream>
using namespace std;
template <typename T>
class Queue
{
    public:
	Node<T>* head;
	Node<T>* tail;
	size_t length;
	 Queue();
     ~Queue();
     Node<T>* Top() { return this->head; }
	 size_t Size() { return this->length; }
	 void Push(T elem);
	 void Pop();
     void Del();
     Queue<T>* operator =(const Queue<T>* q);
     T Back();
     T Front();
     bool Chek(T elem);
     Queue<T>* operator+(const Queue<T>* q1);
     Queue<T>* operator*(const Queue<T>* q1);
     void Print()const ;
    friend ostream& operator <<(ostream& stream, const Queue<T>& obj) {
         obj.Print();
         return stream;
    }
};

template<typename T>
inline Queue<T>::Queue()
{
	head = nullptr;
	tail = nullptr;
	length = 0;
}

template<typename T>
inline Queue<T>::~Queue()
{ 
    Del();
}
template<typename T>
inline bool  Queue<T>::Chek(T elem) {
    Node <T>* node_el = this->tail;
    if (node_el!= nullptr) {
        while (node_el != nullptr) {
            if (node_el->getValue() == elem) {
                return true;
            }
            node_el = node_el->next;
        }
    }
    return false;
}
template<typename T>
inline void Queue<T>::Push(T elem)
{
	Node <T>* node_el = new Node  <T>(elem);
    if (length==0)
    {
        this->head = this->tail = node_el;
    }
    else {
        this->tail->prev = node_el;
        node_el->next = this->tail;
        this->tail = node_el;
    }
    length++;
}

template<typename T>
inline void Queue<T>::Pop()
{
    Node <T>* node_el = new Node  <T>();
    node_el = head;
    if (head->prev = nullptr) {
        tail=head = nullptr;
    }
    else {
        head = node_el->prev;
        head->next = nullptr;
    }
    length--;
    delete node_el;
}

template<typename T>
inline void Queue<T>::Del()
{
    int k = length;
    Node <T>* node_el = new Node  <T>();
    node_el = head;
    for (size_t i = 1; i <= k; i++) {
        if (head->prev = nullptr) {
            tail = head = nullptr;
        }
        else {
            head = node_el->prev;
            head->next = nullptr;
        }
        length--;
        delete node_el;
    }
}

template<typename T>
inline Queue<T>* Queue<T>::operator=(const Queue<T>* q)
{
    Node <T>* node_el = new Node  <T>();
    if (this == q) {
        return this;
    }
    if (this->length != q->length) {
        this->length == q->length;
    }
    if (length != 0) {
        Del();
    }
    node_el = q->tail;
    for (size_t i = 0; i < this->length; i++) {
        Push(node_el->getValue());
        node_el = node_el->next;
    }
    return this;
}

template<typename T>
inline T Queue<T>::Back()
{
    if (length == 0)
    {
        return (T)0;
    }
    else {
        return tail->getValue();
    }
}

template<typename T>
inline T Queue<T>::Front()
{
    if (length == 0)
    {
        return (T)0;
    }
    else {
        return head->getValue();
    }
}

template<typename T>
inline Queue<T>* Queue<T>::operator+(const Queue<T>* q1)
{
    Queue <T>* new_obj = new Queue<T>(*this);
    Node<T>* tmp = q1->head;
    for (size_t i = 0; i < q1->length; i++) {
        new_obj->Push(tmp->getValue());
        tmp = tmp->prev;
    }
    return new_obj;
}

template<typename T>
inline Queue<T>* Queue<T>::operator*( const Queue<T>* q1)
{
     Queue <T>* new_obj = new Queue<T>();
     Node<T>* tmp = q1->head;
        while (tmp != nullptr) {
            if (this->Chek(tmp->getValue())&&
                !new_obj->Chek(tmp->getValue())) {
                new_obj->Push(tmp->getValue());
            }
            tmp = tmp->prev;
        }
    return new_obj;
}

template<typename T>
inline void Queue<T>::Print()const 
{
    if (length != 0)
    {
        Node <T>* node_el = new Node  <T>();
        node_el = tail;
        cout << "( ";
        while (node_el->next != 0)
        {
            cout << node_el->getValue() << ", ";
            node_el = node_el->next;
        }
        cout << node_el->getValue() << " )\n";
    }
}



