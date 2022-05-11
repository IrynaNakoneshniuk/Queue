#pragma once
#include <iostream>
#include <cassert>
#include <initializer_list>
template <class T>
class  Node_A {
    public:
    Node_A<T>* next;
    Node_A<T>* prev;
	T* elem;
	Node_A(T* elemP) {
		next = nullptr;
		prev = nullptr;
		this->elem = elemP;
	}
	Node_A() = default;
	~Node_A() = default;
	T* getElem() { return this->elem; }
	friend ostream& operator <<(ostream& stream, Node_A<T>& obj) {
		obj.Print();
		return stream;
	}
	void setElem(T *elem) { this->elem = elem; }
};
template <class T>
class Array
{
   public:
	uint32_t length;
	Node_A <T>* head;
	Node_A <T>* tail;
	uint32_t count_el;
		Array(uint32_t length){
			this->length = length;
			this->head = nullptr;
			this->tail = nullptr;
		}
		Array():Array(0) {};
		~Array() {
			RemoveAll();
		}
		
		Node_A <T> *operator[](int idx)const
		{
			int i = 1;
			assert(idx >= 0 and idx < length and "Index is out"
				"of range!");
			Node_A<T>* node_elem = new Node_A <T>();
			node_elem = this->head;
			while (i<idx) {
				node_elem = node_elem->next;
				i++;
			}
			return *node_elem;
		}
		uint32_t getSize() { return this->count_el; }
		void Add(T* elem);
		void setSize(uint32_t size, uint32_t grow);
		void Print();
		uint32_t  GetUpperBound() { return count_el; }
		bool IsEmpty() { return (this->count_el == 0) ? true : false; }
		void FreeExtra();
		T* GetAt(int index);
		void SetAt(int index,T*elem);
		void Append(Array<T>* obj);
		Array<T>* operator =(const Array<T>* obj);
		Array<T>* GetData() { return this; }
		void  InsertAt(int index, T* elem);
		void RemoveAt(int index);
		void Create(uint32_t length);
		void RemoveAll();
};
template<typename T>
inline void Array<T>::Create(uint32_t lengthP) {
	T* elem = new T();
	for (int i = 1; i <=lengthP; i++) {
		this->Add(elem);
	}
}

template <typename T>
inline void Array<T>::setSize(uint32_t  size, uint32_t grow)
{
	if (size>= grow) {
		Create(grow);
	}
}
template<typename T>
inline void Array<T>::RemoveAll()
{
	Node_A<T>* node_elem = new Node_A <T>();
	node_elem = this->head;
	while (node_elem != nullptr) {
		if (node_elem == nullptr)
		{
			this->tail = this->head = nullptr;
		}
		else {
			this->head = node_elem->next;
			node_elem->prev = nullptr;
		}
		this->length--;
		this->count_el--;
		delete node_elem;
		node_elem = this->head;
	}
}
	
template<typename T>
inline void Array<T>::Add(T* elem) {
	Node_A <T>* node_elem = new Node_A <T>(elem);
	node_elem->next = 0;
	node_elem->prev = tail;
	if (tail != 0) {
		tail->next = node_elem;
	}
	if (count_el == 0) {
		head = tail = node_elem;
	}
	else
	{
		tail = node_elem;
	}
	count_el++;
	if (count_el >= this->length) {
		this->setSize(count_el, this->length);
	}
}
template<typename T>
inline void Array<T>::Print() {
	Node_A <T>* node_elem = new Node_A <T>();
	node_elem = this->head;
	if (node_elem != nullptr) {
		cout << "{";
		while (node_elem != nullptr) {
			cout << node_elem->getElem()<< ",";
			node_elem = node_elem->next;
		}
		cout << "}" << endl;
	}
}
template<typename T>
inline void Array<T>::FreeExtra() {
	int i =count_el;
	Node_A <T>* node_elem = new Node_A <T>();
	while (i <=length) {
		node_elem = this->tail;
		this->tail = this->tail->prev;
		node_elem->prev = nullptr;
		delete node_elem;
		i++;
	}
}
template<typename T>
inline T *Array<T>::GetAt(int index) {
	assert(index >= 0 and index < length and "Index is out"
		"of range!");
	int i = 0;
	Node_A <T>* node_el = new Node_A<T>();
	node_el = this->head;
	while (i < index) {
		node_el = node_el->next;
	}
	return node_el->getElem();
}
template<typename T>
inline void Array <T>::SetAt(int index,T* element) {
	this->RemoveAt(index);
	InsertAt(index, element);
}

template<typename T>
inline void Array<T>::Append(Array<T>* obj){
	this->setSize(this->length, obj->count_el);
	Node_A <T>* node_el = new Node_A <T>();
	node_el = obj->head;
	while (node_el != nullptr) {
		this->tail->next = node_el;
		node_el->prev = this->tail;
		this->tail = node_el;
		node_el = node_el->next;
	}
}
template<typename T>
inline Array<T>* Array<T>:: operator =(const Array<T>* obj) {
	Node_A<T>*node_el = new Node_A <T>();
	node_el= obj->head();
	if (!this->IsEmpty()) {
		this->RemoveAll();
	}
	this->length = obj->length;
	while (node_el!=nullptr)
	{
		this->Add(node_el->getValue());
		node_el = node_el->next;
	}
}
template<typename T>
inline void Array<T>::InsertAt(int index, T* elem){
	int i=1;
	Node_A <T>* InsertPos =this->head;
	Node_A <T>* PrevPos = new Node_A<T>();
	Node_A <T>* Insert = new Node_A <T>(elem);
	count_el++;
	if (count_el >= this->length) {
		this->setSize(count_el, this->length);
	}
	assert(index >= 0 and index < length and "Index is out"
		"of range!");
	if (index == count_el) {
		Add(Insert->getElem());
	}
	else {
		while (i < index)
		{
			InsertPos = InsertPos->next;
			i++;
		}
		if (InsertPos->prev!= nullptr) {
			PrevPos = InsertPos->prev;
		}
		if (index == 1) {
			Insert->prev = 0;
			Insert->next = InsertPos;
			InsertPos->prev = Insert;
		}
		else {
			PrevPos->next = Insert;
			Insert->next = InsertPos;
			Insert->prev = PrevPos;
			InsertPos->prev = Insert;
		}
	}
}
template<typename T>
inline void Array<T>::RemoveAt(int index) {
	uint32_t i = 1;
	Node_A <T>* Del = this->head;
	Node_A <T>* PrevDel = new Node_A<T>();
	Node_A <T>* DelNext = new Node_A <T>();
	assert(index >= 0 and index < length and "Index is out"
		"of range!");
	while (i <index && Del != nullptr)
	{
		Del = Del->next;
		i++;
	}
	if (i > 1) {
		PrevDel = Del->prev;
	}
	if (i < length) {
		DelNext = Del->next;
	}
	if (count_el== 1) {
		this->RemoveAll();
	}
	if (i==length) {
		Del->prev = nullptr;
		this->tail=PrevDel;
		delete Del;
	}
   else if(i==1){
		Del->next = nullptr;
		this->head=DelNext;
		DelNext->prev = nullptr;
		count_el--;
		delete Del;
   }
	else if (PrevDel!=nullptr&&DelNext!=nullptr){
		Del->next = nullptr;
		Del->prev = nullptr;
		PrevDel->next = DelNext;
		DelNext->prev = PrevDel;
		count_el--;
		delete Del;
	}
}