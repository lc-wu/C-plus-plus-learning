//使用assign进行元素重置
#include <iostream>
#include <list>
using namespace std;
  
int main()
{
    list<double> list_One,list_Two,list_Three;
    for(int i=0;i<10;++i){
        list_One.push_front(i);
    }
    list_Two = list_One;
    //list_Two.assign(5,5.6);  //将list_Two的值设置为5个5.6
    list_Three.assign(list_One.begin(),list_One.end());
    for (list<double>::iterator it = list_Two.begin(); it != list_Two.end(); it++)
        cout << *it << endl;
    return 0;
}