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
class stack
{
public:
    int length;
    list<T> list;

    stack<T>() : length(0) {}

    void push(T data)
    {
        list.insertFront(data);
        length++;
    }

    void pop()
    {
        if (length > 0)
        {
            list.deleteFront();
            length--;
        }
        else
        {
            std::cout << "ERROR : Cannot pop from an empty stack" << std::endl;
            exit(0);
        }
    }

    T top()
    {
        if (list.length > 0)
            return list.front();
        else
        {
            std::cout << "ERROR : Empty list" << std::endl;
            exit(0);
        }
    }

    int size()
    {
        return length;
    }

    unsigned int hash()
    {
        std::string temp;
        stack<T> st;
        temp += "[ ";
        while (s.length > 1)
        {
            temp += s.top() + " | ";
            st.push(s.top());
            s.pop();
        }
        if (s.length)
        {
            temp += s.top();
            st.push(s.top());
            s.pop();
        }
        while (st.length)
        {
            s.push(st.top());
            st.pop();
        }
        temp += " ]";
        unsigned int hashed = HASHER;
        for (int i = 0; i < temp.size(); i++)
        {
            hashed = (hashed * A) ^ (temp[0] * B);
        }
        return hashed;
    }

    friend std::ostream &operator<<(std::ostream &stream, stack &s)
    {
        stack<T> st;
        stream << "Top => [ ";
        while (s.length > 1)
        {
            stream << s.top() << " | ";
            st.push(s.top());
            s.pop();
        }
        if (s.length)
        {
            stream << s.top();
            st.push(s.top());
            s.pop();
        }
        while (st.length)
        {
            s.push(st.top());
            st.pop();
        }
        stream << " ]";
        return stream;
    }
};