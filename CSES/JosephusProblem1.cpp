#include<iostream>
#include<vector>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
};

class List
{
    public:
    Node* head;
    Node* tail;
    void insert(int val)
    {
        Node* newNode = new Node();
        newNode->data = val;
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    void doggie()
    {
        tail->next = head;
        Node* temp = head;
        temp = temp->next;
        while(temp != NULL)
        {
            if(temp->next == temp)
            {
                cout<<temp->data<<" ";
                return;
            }
            else
            {
                cout<<temp->data<<" ";
                temp->data = temp->next->data;
                temp->next = temp->next->next;
                temp = temp->next;
            }
        }
    }
};
int main()
{
    List* ll = new List();
    int d;
    cin>>d;
    for(int i=0; i<d; i++)
        ll->insert(i+1);
    ll->doggie();
}