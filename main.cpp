#include <iostream>
#include "list.h"
using namespace std;
int main()
{
    
    list<int>v;
    v.insertFront(5);
    v.insertFront(4);
    v.insertFront(3);
    v.insertFront(2);
    v.insertFront(1);

    cout<<v<<endl;

    v.reverse();
    cout<<v<<endl;

    return 0;
}