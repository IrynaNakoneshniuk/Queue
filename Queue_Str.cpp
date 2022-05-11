#include <iostream>
#include "Queue.h"
#include "Array.h"

int main()
{
	Queue<int>* q1 = new  Queue<int>();
	Queue<int>* q2 = new  Queue<int>();
	Queue<int>* q3 = new  Queue<int>();
	Queue<int>* q4 = new  Queue<int>();
	q1->Push(1);
	q1->Push(2);
	q1->Push(5);
	q1->Push(5);
	q2->Push(2);
	q2->Push(5);
	q2->Push(5);
	q2 = q1;
	cout << "\nq1:";
	q1->Print();
	cout << "\nq2(q2 = q1):";
	q2->Print();
	q3 = q1->operator+(q2);
	q4 = q2->operator*(q1);
	cout << "\nq3(q1+q2):";
	q3->Print();
	cout << "\nq4(q2*q1):";
	q4->Print();

	Array<int>* a = new Array<int>(6);
	Node_A<int>* n = new Node_A<int>();
	Array<Queue<int>>* a3 = new Array<Queue<int>>(11);
	a3->Create(4);
	cout << a3->getSize() << endl;
	a3->Add(q3);
	a3->Add(q1);
	a3->Add(q3);
	a3->InsertAt(4,q2);
	a3->Print();
	cout << a3->getSize() << endl;
	a3->RemoveAt(3);
	a3->Print();
	a3->FreeExtra();
	a3->RemoveAll();
	a3->SetAt(1, q4);
	cout << a3->getSize() << endl;
	return 0;


}