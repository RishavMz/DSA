#include <iostream>
#include "stack.h"
using namespace std;
int main()
{
    
    stack<string>s;
    s.push("ABC");
    cout<<s<<endl;
    s.push("DEF");
    cout<<s<<endl;

    return 0;
}