#include <iostream>
#include "queue.h"
using namespace std;
int main()
{

    queue<string> q;
    q.push("ABC");
    cout << q << " " << q.hash() << endl;
    q.push("DEF");
    cout << q << " " << q.hash() << endl;
    q.pop();
    cout << q << " " << q.hash() << endl;
    q.pop();
    cout << q << " " << q.hash() << endl;

    return 0;
}