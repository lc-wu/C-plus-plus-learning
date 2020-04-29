// static_1.cpp
#include <iostream>
using namespace std;

class Apple
{
public:
    static void printMsg()
    {
        cout << "welcome to apple";
    }
};

int main()
{
    Apple::printMsg();
}