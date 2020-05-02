### STL list类
## 一、概述
list 是双向链表实现而成， 元素放在堆中，每个元素放在一块内存中，内存空间可以是不连续的，通过指针来进行元素的访问。
+ 缺点：因此它的随机存取没有效率，并且没有提供[]操作符的重载。
+ 优点：方便任意地点的插入和删除操作。

## 二、头文件及定义
+ #include < list >
+ 定义
```
list<int> a;
list<int> a(10);
list<int> a(10, 1); //大小为10，且所有值初始化1
list<int> b(a); // 用a初始化b
deque<int> b(a.begin(), ++a.end()); // deque() 通用函数  访问链接[]
```
+ list 初始化
```
int n[] = {1, 2, 3};
list<int> a(n, n+5);    // 数组n前5个元素作为列表a的初值
```
### 三、基本操作
```
list< int >  list1
```
1. 容量函数方法
```
list1.size(); 返回元素个数
list1.max_size();
list1.resize();  改变容器大小
list1.empty();
```
2. 列表中添加元素
```
list1.push_front(const T& x); // 头部插入 x
list1.push_back(const T& x);    // 尾部插入 x
list1.insert(iterator it, const T& x); // 在it这个位置前面 插入x
list1.insert(iterator it, int n, const T& x);    // 在it位置前面插入 n个 x
list1.insert(iterator it, iterator a_first, iterator a_end);    // 在it位置上插入 a列表[a_first, a_end]位置的元素 列表a的元素不会变动
```
3. 删除元素
```
list1.pop_front();      // int a = list1.pop_front() 是错误的，函数没有返回删除的那个值
list1.pop_back();
list1.erase(iterator it);
list1.erase(iterator first, iterator last);     // 删除[first, last]之间的元素
list1.clear();  //清空
```
4. 访问函数
```
list1.front();  // 返回第一元素的值
list1.back();   // 返回最后一个元素
```
5. 其他函数
```
list1.assign(int nSize, const T& x);
// 将list1 清空， 赋值 nSize个 x到列表中

list1.swap(list &list2) 
swap(list &list1 , list &list2)
交换两个同类型容器的元素

list1.merge(list2);     
// 合并两个列表元素，默认升序
// 合并后 list2 为空

void list1.splice(iterator it, list &list2);
// 从一个 list 转移元素给 另一个
// 在 it 元素之前， 插入列表 list2， 之后 list2为空

void list1.unique();
// 删除容器中 相邻 的重复元素
```
### 四、迭代器和算法
1. 迭代器
```
list1.begin();

list1.end();

list1.cbegin(); // 不能通过这个指针来修改所指向的内容，其他方式可以，指针可移动

list1.cend();    // 指向 常量 的末尾迭代器指针

llist1.rbegin();    // 反向迭代器指针，指向最后一个元素

list1.rend();       // 反向迭代器指针，指向第一个元素的前一个
```
2. 算法
+ 遍历算法
```
list<int>::iterator it;
for (it = list1.begin(); it != list1.end(); it++)
    cout << *it << endl;
```
+ 元素翻转
```
#include <algorithm>
reverse(list1.begin(), list1.end())
```
+ 元素排序
```
#include <algorithm>
sort(list1.begin(), list1.end());   // 默认从小到大排序

sort(list1.begin(), list1.end(), Comp); // 自定义排序规则
bool Comp(const int &a, const int &b)
{
    return a > b;
}

// 可以先进行从小到大排序，之后进行翻转
```

参考
+ [ [C++ STL] list使用详解 ](https://www.cnblogs.com/linuxAndMcu/p/10260627.html)
+ [cppreference.com](https://zh.cppreference.com/) 