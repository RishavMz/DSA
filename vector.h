#include <iostream>

template <typename T>
class vector
{
public:
    int size;
    int capacity;
    T *arr;

    vector<T>() : size(0), capacity(1)
    {
        arr = new T[capacity];
    }

    void push_back(T data)
    {
        if (size == capacity)
        {
            capacity *= 2;
            T *temp = new T[capacity];
            for (int i = 0; i < size; i++)
                temp[i] = arr[i];
            delete[] arr;
            arr = temp;
        }
        arr[size++] = data;
    }

    void pop_back()
    {
        if (size > 0)
            size--;
        else
        {
            std::cout<<"ERROR : Cannot delete from an empty vector"<<std::endl;
            exit(0);
        }
    }

    T at(int index)
    {
        if (index < size)
            return arr[index];
        else{
            std::cout<<"ERROR : Given inex exceeds current size of vector"<<std::endl;
            exit(0);
        }
    }

    void eraseAt(int index)
    {
        if (index < size)
        {
            for (int i = index; i < size - 1; i++)
                arr[i] = arr[i + 1];
            size--;
        }
        else
            std::cout<<"ERROR : Given index exceeds current size of vector"<<std::endl;
    }

    void reverse()
    {
        for (int i = 0; i <= size / 2; i++)
        {
            T temp = arr[i];
            arr[i] = arr[size - 1 - i];
            arr[size - 1 - i] = temp;
        }
    }

    void mergesort(int l, int r)
    {
        if (l < r)
        {
            int mid = l + (r - l) / 2;
            mergesort(l, mid);
            mergesort(mid + 1, r);
            int l1 = (mid - l + 1), l2 = (r - mid);
            int temp1[l1], temp2[l2];
            for (int i = 0; i < l1; i++)
                temp1[i] = arr[l + i];
            for (int i = 0; i < l2; i++)
                temp2[i] = arr[mid + 1 + i];
            int p1 = 0, p2 = 0, p3 = l;
            while (p1 < l1 && p2 < l2)
            {
                if (temp1[p1] <= temp2[p2])
                    arr[p3++] = temp1[p1++];
                else
                    arr[p3++] = temp2[p2++];
            }
            while (p1 < l1)
                arr[p3++] = temp1[p1++];
            while (p2 < l2)
                arr[p3++] = temp2[p2++];
        }
    }

    void sort()
    {
        mergesort(0, size - 1);
    }

    void unique()
    {
        this->sort();
        int p1 = 0, p2 = 1, s = 0;
        while (p1 < size)
        {
            if (arr[p2] == arr[p1])
            {
                p2++;
                s++;
            }
            else
            {
                arr[++p1] = arr[p2++];
            }
        }
        size -= s;
    }

    int length()
    {
        return size;
    }

    friend std::ostream &operator<<(std::ostream &stream, const vector &v)
    {
        stream << "[ ";
        for (int i = 0; i < v.size - 1; i++)
            stream << v.arr[i] << ", ";
        stream << v.arr[v.size - 1];
        stream << " ]\n";
        return stream;
    }
};
