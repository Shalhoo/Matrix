#pragma once
#include "List.h"

template <class T>
class Node { // класс, отвечающий за отдельные элементы двусвязного списка
public:
	T data;
	Node<T>* prev, * next; // указатели на пред и след элементы списка

	Node(double data) {
		this->data = data;
		this->prev = this->next = nullptr; // указатели прев и след принимают по умолча
	}
};

template <class T>
class LinkedList : public Pure<T> {
public:
	Node<T>* head, * tail; // указатели ссылаются на элементы двусвязного списка
	int count;

	LinkedList() {
		head = tail = nullptr; // по умолчанию нал
	}

	~LinkedList() {
		while (head != nullptr)
			pop_front();
	}

	Node<T>* push_front(double data) { // добавление элемента в начало списка
		Node<T>* ptr = new Node<T>(data); //создание объекта списка
		ptr->next = head; // если хед указывает н сущ объект, то некст тоже, если нал, то нал
		if (head != nullptr)
			head->prev = ptr; // если хед указывает на сущ обьект, то указатель прев должен вести на пред
		if (tail == nullptr)
			tail = ptr;
			head = ptr;
		// единственный, тогда нал
		return ptr;
	}

	Node<T>* push_back(double data) { // добавление элемента в конец списка
		Node<T>* ptr = new Node<T>(data);
		ptr->prev = tail;
		if (tail != nullptr)
			tail->next = ptr; // тейл теперь на след объект, 
		if (head == nullptr)
			head = ptr;
		tail = ptr;
		return ptr; 
	}

	T* pop_front() { // удаление с начала списка
		if (head == nullptr) return nullptr;

		Node<T>* ptr = head->next; // временный указатель, ведет на след элемент после первого
		if (ptr != nullptr) 
			ptr->prev = nullptr; // если второй существует, то нал
		else
			tail = nullptr;
		T value = head->data;
		delete head;
		head = ptr;
		return &value;
	}

	T* pop_back() { // удаление с конца списка
		if (tail == nullptr) return nullptr;

		Node<T>* ptr = tail->prev; // указатель на предпоследний объект списка
		if (ptr != nullptr)
			ptr->next = nullptr;
		else
			head = nullptr;
		T value = tail->data;
		delete tail;
		tail = ptr;
		return &value;
	}

	Node<T>* getAt(int index) { // метод произвольного доступа к элементу двусвязного списка с индексом получаемого элемента
		Node<T>* ptr = head;
		int n = 0;

		while (n != index) { // цикл пока не дойдем до нужног оиндекса
			if (ptr == nullptr) // если не существует объектов
				return ptr;
			ptr = ptr->next;
			n++;
		}

		return ptr;
	}

	Node<T>* operator [] (int index) { // возвращение элемента по опред индексу
		return getAt(index);
	}

	Node<T>* insert(int index, double data) override { //метод вставки нового элемента в произвольное место двусвязного списка (индекс куда вставляем и значение)
		Node<T>* right = getAt(index); // ссылается на элемент с индексом(элемент справа от нового всатвленного)
		if (right == nullptr)
			return push_back(data);

		Node<T>* left = right->prev;
		if (left == nullptr)
			return push_front(data);

		Node<T>* ptr = new Node<T>(data); // новый объект, со след связями
		ptr->prev = left; 
		ptr->next = right;
		left->next = ptr;
		right->next = ptr;

		return ptr;
	}

	void erase(int index) override { // удаление элемента
		Node<T>* ptr = getAt(index); // получение указателя на элемент кот хотим удалить  
		if (ptr == nullptr)
			return;

		if (ptr->prev == nullptr) {
			pop_front();
			return;
		}

		if (ptr->next == nullptr) {
			pop_back();
			return;
		}

		Node<T>* left = ptr->prev;
		Node<T>* right = ptr->next;
		left->next = right;
		right->prev = left;

		delete ptr;
	}
};