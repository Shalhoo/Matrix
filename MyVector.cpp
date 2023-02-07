#pragma once

template <typename T> class myVector {
public:

    myVector() {
        length = 0;
        allocated = 1;
        data = new T[allocated];
    };
    myVector(int leng) :
        length{ leng }
    {
        if (length > 0)
        {
            data = new T[leng];
            allocated = data;
        }
    }

    T& operator[](int index)
    {
        return data[index];
    }

    T* begin() {
        return data;
    }

    T* end() {
        return data + length;
    }


    int getLength() const { return length; }

    void reserve() {
        if (allocated > length)
            return;
        T* newArr = new T[2 * allocated];
        for (size_t i = 0; i < length; i++)
        {
            newArr[i] = data[i];
        }
        delete[] data;
        data = newArr;
        allocated *= 2;
    }

    void pushBack(const T& value) {
        insert(end(), value);
    }

    void pushFront(const T& value) {
        insert(begin(), value);
    }
    void insert(T* ptr, const T& value) {
        size_t n = ptr - begin();
        reserve();
        for (size_t i = length; i >= n + 1; i--)
        {
            data[i] = data[i - 1];
        }
        data[n] = value;
        length++;
    }

    void clear()
    {
        delete[] data;
        data = nullptr;
        length = 0;
    }

    void erase(T* ptr) {
        size_t n = ptr - begin();
        for (size_t i = n; i < length; i++)
        {
            data[i] = data[i + 1];
        }
        length--;
    }


private:
    int length, allocated;
    T* data;
};