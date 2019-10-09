#include <iostream>
#include "node.h"

using namespace std;

int main() {
    int n = 100;
    int* a = new int[n];

    for(int i=0; i<n; i++)
    {
        a[i]=i;
    }

    Node *np = new Node(1, n, a);

    int data = np->getDataById(8);
    cout << data << endl;

    delete np;

    return 0;
}