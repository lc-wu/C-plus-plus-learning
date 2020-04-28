// test.cpp 
#include <iostream>
using namespace std;
int main()
{
    const int num = 0;
    int * const ptr = &num;
    cout << *ptr << endl;
}