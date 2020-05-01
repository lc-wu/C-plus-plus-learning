### STL list类
##一、概述
list 是双向链表实现而成， 元素放在堆中，每个元素放在一块内存中，内存空间可以是不连续的，通过指针来进行元素的访问。
+ 缺点：因此它的随机存取没有效率，并且没有提供[]操作符的重载。
+ 优点：方便任意地点的插入和删除操作。

##二、头文件及定义
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
###三、基本操作
```
list< int >  list1
```
1 容量函数方法
```
list1.size(); 返回元素个数
list1.max_size();
list1.resize();  改变容器大小
list1.empty();
```
2 列表中添加元素
```
list1.push_front(const T& x); // 头部插入 x
list1.push_back(const T& x);    // 尾部插入 x
list1.insert(iterator it, const T& x); // 在it这个位置前面 插入x
list1.insert(iterator it, int n, const T& x);    // 在it位置前面插入 n个 x
list1.insert(iterator it, iterator a_first, iterator a_end);    // 在it位置上插入 a列表[a_first, a_end]位置的元素 列表a的元素不会变动
```
3 删除元素
```
list1.pop_front();      // int a = list1.pop_front() 是错误的，函数没有返回删除的那个值
list1.pop_back();
list1.erase(iterator it);
list1.erase(iterator first, iterator last);     // 删除[first, last]之间的元素
list1.clear();  //清空
```



