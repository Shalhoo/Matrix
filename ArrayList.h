#pragma once
#include <iterator>
#include "List.h"

template <typename T>

class Vector : public Pure<T> {
public:
	T* arr;
	size_t size = 0;
	size_t capacity = 1;

	Vector() {
		arr = new T[size];
		capacity = size;
	}

	T* begin() {
		return arr;
	}

	T* end() {
		return arr + size;
	}

	void reserve(size_t n) {
		if (n <= capacity) return;
		T* newArr = new T[n];
		for (size_t i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		capacity = n;
	}

	void push_back(T data) override {
		if (capacity <= size + 1) {
			reserve(2 * (size + 1));
		}
		arr[size] = data;
		size++;
	}

	void push_front(T value) {
		insert(0, value);
	}
	
	void insert(int index, T data) override {
		if (capacity <= size + 1) {
			reserve(2 * (size + 1));
		}
		if (index <= size) {
			for (int i = size + 1; i > index; i--) {
				arr[i] = arr[i - 1];
			}
			arr[index] = data;
			size++;
		}
	}

	void erase(int index) override {
		for (int i = index + 1; i < size; ++i) {
			arr[i - 1] = arr[i];
		}
		--size;
	}

	size_t list_size() {
		return size;
	}

	size_t array_capacity() {
		return capacity;
	}

	T& operator[](int index)
	{
		return arr[index];
	}
};	