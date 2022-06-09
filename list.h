#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
};

template <typename T>
class list
{
public:
    Node<T> *head;
    Node<T> *tail;
    int length;

    list<T>() : head(NULL), tail(NULL), length(0) {}

    void insertFront(T data)
    {
        Node<T> *newNode = new Node<T>();
        newNode->data = data;
        if (head == NULL && tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void insertBack(T data)
    {
        Node<T> *newNode = new Node<T>();
        newNode->data = data;
        if (tail == NULL && head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    T front() const
    {
        return head ? head->val : NULL;
    }

    T back() const
    {
        return tail ? tail->val : NULL;
    }

    void deleteFront()
    {
        if (head != NULL)
        {
            Node<T> *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            if (head == NULL)
                tail = NULL;
            length--;
        }
    }

    void deleteBack()
    {
        if (tail != NULL)
        {
            Node<T> *temp = head;
            if (temp->next == NULL)
            {
                delete temp;
                head = NULL;
                temp = NULL;
            }
            else
            {
                while (temp->next->next != NULL)
                    temp = temp->next;
                tail = temp;
                temp = temp->next;
                tail->next = NULL;
                delete temp;
            }
            length--;
        }
    }

    void reverse()
    {
        if (head == NULL || head->next == NULL)
            return;
        if (head->next->next == NULL)
        {
            tail->next = head;
            head->next = NULL;
            Node<T> *temp = head;
            head = tail;
            tail = temp;
        }
        else
        {
            Node<T> *h = head;
            Node<T> *p1 = head;
            Node<T> *p2 = p1->next;
            Node<T> *p3 = p2->next;

            head->next = NULL;
            while (p3 != NULL)
            {
                p2->next = p1;
                p1 = p2;
                p2 = p3;
                p3 = p3->next;
            }
            p2->next = p1;
            tail = h;
            head = p2;
        }
    }

    int size() const
    {
        return length;
    }

    friend std::ostream &operator<<(std::ostream &stream, const list &l)
    {
        stream << "[ ";
        Node<T> *temp = l.head;
        while (temp != NULL && temp->next != NULL)
        {
            stream << std::to_string(temp->data) << ", ";
            temp = temp->next;
        }
        if (temp != NULL)
            stream << std::to_string(temp->data);
        stream << " ]";
        return stream;
    }
};