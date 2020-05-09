### 1-a: 链表逆序-a
已知链表头结点指针head，将链表逆序，不可申请额外空间

### 1-b: 链表逆序-b 
已知链表头结点指针head，将链表从位置m到n逆序，不申请额外空间 
### 2: 求两个链表的交点 160
已知链表A的头节点指针headA， 链表B的头节点指针headB， 两个链表相交， 求两链表交点对应的节点。
>思路1
1遍历链表A，将A中节点对应指针地址，插入set. node_set.insert(headA)
2遍历链表B，依次查找B中节点的指针地址是否在set中，node_set.find(headB) != node_set.end() 发现第一个在set中的节点地址，就是交点

>思路2
1.计算headA 链表长度，计算headBand 链表长度，较长链表读出长度k 
2将交长链表指针移动到和较短链表指针对齐的位置
3headA和headB同时移动，当两指针指向同一个节点时就找到了

### 3: 链表求环 141 142
已知链表中可能存在环，若有环返回环起始节点，否则返回NULL
> 思路1
1遍历链表，将链表中节点对应的指针（地址），插入set中
2在遍历时插入节点前，在set中查找，第一个在set中发现的节点地址，即是链表环的起点

> 思路2
快慢指针赛跑
slow指针每次跑一步
fast指针每次跑两步
slow和fast重合证明存在环，重合位置为meet
从meet和head指针出发，两个指针重合位置为环的起点

### 4: 链表划分 86
已知链表头指针head与数值x，将所有小于x的节点放在大于等于x的节点前，且保存这些节点原来相对位置不变
> 思路
构建 less_head more_head 头结点， less_ptr more_ptr指针
less_head节点保存小于x的节点
more_head节点保存大于等于x的节点
合并less_head和more_head链表

### 5: 复杂的链表的深度拷贝 138
已知一个复杂的链表，节点中有一个指向本链表任意某个节点的随机指针（也可以为空），求这个链表的深度拷贝
> 思路
节点地址与原节点序号对应（难度在于节点中的随机指针）
node_map： 原链表节点地址->节点位置（第几个节点）
map2： 节点位置（第几个节点）-> 新链表节点地址

~~~
RandomListNode *copyRandomList(RandomListNode * head){
    std::map<RandomListNode *, int> node_map; // 地址到节点位置的map
    std::vector<RandomListNode *> node_vec; // 使用vector根据存储节点位置访问地址
    RandomListNode * ptr = head;
    int i = 0;
    while(ptr)  
    {
        // 新链表节点push到node_vec
        node_vec.push_back(new RandomListNode(ptr->label));
        // 生成新链表节点位置 i 到地址的map
        node_map[ptr] = i;
        ptr = ptr->next;
        i++;
    }
    node_vec.push_back(0);
    // 链表指针和vector数组全部置放到开头
    ptr = head;
    i = 0;
    // 此时链表已经拷贝到 node_vec中，缺少随机指针、next指针
    while(ptr)
    {
        // 建立原来链表的next指针
        node_vec[i]->next = node_vec[i+1];
        if (ptr->random)
        {   
            // 建立原来链表的random指针
            int id = node_map[ptr->random];
            node_vec[i]->random = node_vec[id];
        }
        ptr = ptr->next;
        i++;
    }
    return node_vec[0];
}
~~~

### 6-a: 排序链表的合并（两个链表） 21
已知两个已排序链表头结点指针l1和l2，将两个链表合并，合并后仍然有序，返回合并后头结点。
> 设置一个临时头结点temp_head,pre指针指向临时头结点。
 比较l1和l2指向的结点，将较小的结点插入到pre指针后，并且向前移动较小结点的指针。最后返回 temp_head.next

### 6-b: 排序链表的合并（多个） 23
已知 k 个已排序链表头结点指针，将 K 个链表合并，合并后仍然有序，返回合并后头结点。

> 思路1
链表头结点指针保存在 vector<ListNode *> & lists
将 k*n 个节点放到vector中， 再将vector排序， 再将节点顺序相连。设有k个链表，平均每个链表有n个节点
利用 STL排序算法 sort
~~~
bool cmp(const ListNode * a, const ListNode *b)
{
    return a->val < b->val;
}
sort(node_vec.begin(), node_vec.end(), cmp); //链表所有节点存入vector<ListNode *> node_vec;
~~~
> 思路2
对 k 个链表进行分治，两两进行合并