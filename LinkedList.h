#pragma once
#include "List.h"

template <class T>
class Node { // �����, ���������� �� ��������� �������� ����������� ������
public:
	T data;
	Node<T>* prev, * next; // ��������� �� ���� � ���� �������� ������

	Node(double data) {
		this->data = data;
		this->prev = this->next = nullptr; // ��������� ���� � ���� ��������� �� ������
	}
};

template <class T>
class LinkedList : public Pure<T> {
public:
	Node<T>* head, * tail; // ��������� ��������� �� �������� ����������� ������
	int count;

	LinkedList() {
		head = tail = nullptr; // �� ��������� ���
	}

	~LinkedList() {
		while (head != nullptr)
			pop_front();
	}

	Node<T>* push_front(double data) { // ���������� �������� � ������ ������
		Node<T>* ptr = new Node<T>(data); //�������� ������� ������
		ptr->next = head; // ���� ��� ��������� � ��� ������, �� ����� ����, ���� ���, �� ���
		if (head != nullptr)
			head->prev = ptr; // ���� ��� ��������� �� ��� ������, �� ��������� ���� ������ ����� �� ����
		if (tail == nullptr)
			tail = ptr;
			head = ptr;
		// ������������, ����� ���
		return ptr;
	}

	Node<T>* push_back(double data) { // ���������� �������� � ����� ������
		Node<T>* ptr = new Node<T>(data);
		ptr->prev = tail;
		if (tail != nullptr)
			tail->next = ptr; // ���� ������ �� ���� ������, 
		if (head == nullptr)
			head = ptr;
		tail = ptr;
		return ptr; 
	}

	T* pop_front() { // �������� � ������ ������
		if (head == nullptr) return nullptr;

		Node<T>* ptr = head->next; // ��������� ���������, ����� �� ���� ������� ����� �������
		if (ptr != nullptr) 
			ptr->prev = nullptr; // ���� ������ ����������, �� ���
		else
			tail = nullptr;
		T value = head->data;
		delete head;
		head = ptr;
		return &value;
	}

	T* pop_back() { // �������� � ����� ������
		if (tail == nullptr) return nullptr;

		Node<T>* ptr = tail->prev; // ��������� �� ������������� ������ ������
		if (ptr != nullptr)
			ptr->next = nullptr;
		else
			head = nullptr;
		T value = tail->data;
		delete tail;
		tail = ptr;
		return &value;
	}

	Node<T>* getAt(int index) { // ����� ������������� ������� � �������� ����������� ������ � �������� ����������� ��������
		Node<T>* ptr = head;
		int n = 0;

		while (n != index) { // ���� ���� �� ������ �� ������ ��������
			if (ptr == nullptr) // ���� �� ���������� ��������
				return ptr;
			ptr = ptr->next;
			n++;
		}

		return ptr;
	}

	Node<T>* operator [] (int index) { // ����������� �������� �� ����� �������
		return getAt(index);
	}

	Node<T>* insert(int index, double data) override { //����� ������� ������ �������� � ������������ ����� ����������� ������ (������ ���� ��������� � ��������)
		Node<T>* right = getAt(index); // ��������� �� ������� � ��������(������� ������ �� ������ ������������)
		if (right == nullptr)
			return push_back(data);

		Node<T>* left = right->prev;
		if (left == nullptr)
			return push_front(data);

		Node<T>* ptr = new Node<T>(data); // ����� ������, �� ���� �������
		ptr->prev = left; 
		ptr->next = right;
		left->next = ptr;
		right->next = ptr;

		return ptr;
	}

	void erase(int index) override { // �������� ��������
		Node<T>* ptr = getAt(index); // ��������� ��������� �� ������� ��� ����� �������  
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