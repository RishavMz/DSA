#include <iostream>
#include "list.h"
using namespace std;
int main()
{
    
    dlist<int>v;
    v.insertFront(5);
    v.insertFront(4);
    v.insertFront(3);
    v.insertFront(2);
    v.insertFront(1);


    while(v.head != NULL)
    {
        v.deleteBack();
        cout<<v<<endl;
    }

    return 0;
}