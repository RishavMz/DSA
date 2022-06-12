#ifndef INCLUDED_IOSTREAM
#define INCLUDED_IOSTREAM "Included Iosteam"
#include <iostream>
#endif

#ifndef INCLUDED_LIST
#define INCLUDED_LIST "Included list.h"
#include "list.h"
#endif

#ifndef HASHER
#define A 54059 /* a prime */
#define B 76963 /* another prime */
#define C 86969 /* yet another prime */
#define HASHER 37
#endif

template <typename T>
class queue
{
public:
    dlist<T> list;
    int length;
    queue<T>() : length(0) {}

    void push(T data)
    {
        list.insertBack(data);
        length++;
    }

    T front()
    {
        if (length > 0)
            return list.front();
        else
        {
            std::cout << "ERROR : Queue empty" << std ::endl;
            exit(0);
        }
    }

    void pop()
    {
        if (length > 0)
        {
            length--;
            return list.deleteFront();
        }
        else
        {
            std::cout << "ERROR : Cannot delete from an empty queue" << std ::endl;
            exit(0);
        }
    }

    int size()
    {
        return length;
    }

    unsigned int hash()
    {
        std::string s;
        queue<T> qq;
        s += "[ ";
        while (length > 1)
        {
            qq.push(front());
            s += front() + ", ";
            pop();
        }
        if (length > 0)
        {
            qq.push(front());
            s += front();
            pop();
        }
        s += " ]";
        while (qq.length > 0)
        {
            push(qq.front());
            qq.pop();
        }
        unsigned int hashed = HASHER;
        for (int i = 0; i < s.size(); i++)
        {
            hashed = (hashed * A) ^ (s[0] * B);
        }
        return hashed;
    }

    friend std::ostream &operator<<(std::ostream &stream, queue &q)
    {
        queue<T> qq;
        stream << "Front => [ ";
        while (q.length > 1)
        {
            qq.push(q.front());
            stream << q.front() << ", ";
            q.pop();
        }
        if (q.length > 0)
        {
            qq.push(q.front());
            stream << q.front();
            q.pop();
        }
        stream << " ]";
        while (qq.length > 0)
        {
            q.push(qq.front());
            qq.pop();
        }
        return stream;
    }
};