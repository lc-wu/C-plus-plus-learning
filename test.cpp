#include<iostream>
#include<list>

using namespace std;

int main()
{
    list<int> a;
    list<int> b;
    a.push_back(5);
    a.push_back(4);
    b = a;
    list<int>::iterator it = a.begin();
    a.insert(it, b.begin(), b.end());
    int c;
    c = a.pop_front();
    cout << c << endl;
    for (it = b.begin(); it != b.end(); it++)
        cout << *it << endl;
    return 0;
}