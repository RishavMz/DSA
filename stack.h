#ifndef INCLUDED_IOSTREAM
#define INCLUDED_IOSTREAM "Included Iosteam"
#include <iostream>
#endif

#ifndef INCLUDED_LIST
#define INCLUDED_LIST "Included list.h"
#include "list.h"
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

    friend std::ostream &operator << (std::ostream &stream, stack &s)
    {
        stack<T> st;
        stream<<"Top => [ ";
        while(s.length>1)
        {
            stream<<s.top()<<" | ";
            st.push(s.top());
            s.pop();
        }
        if(s.length)
        {
            stream<<s.top();
            st.push(s.top());
            s.pop();
        }
        while(st.length)
        {
            s.push(st.top());
            st.pop();
        }
        stream<<" ]";
        return stream;
    }
};