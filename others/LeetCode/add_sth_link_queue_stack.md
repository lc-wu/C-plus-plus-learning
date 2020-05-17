### 1：链表逆序拆解详解
已知链表头结点指针head，将链表逆序。（不申请额外空间）
> 思路
额外申请两个指针，next,new_head = NULL
~~~
ListNode * next_head = NULL;
while(head)
{
    next = head->next;      // 保存 原链表头结点的next
    head->next = new_head;  // 头结点next指向new_head
    new_head = head;        // new_head保持到链表的头部
    head = next;            // head指向原来链表的头部
}
~~~

### 2:链表逆序-头插法
同上，可以辅助一个节点
> 思路
设置一个临时头结点 temp_head ,利用head指针遍历链表，每遍历一个节点即将该节点插入到 temp_head 后。同时还是需要一个 next指针
~~~
ListNode * reverseList(ListNode * head)
{
    ListNode temp_head(0);
    while(head)
    {
        ListNode * next = head->next;
        head->next = temp_head.next;
        temp_head.next = head;          // 头插法
        head = next;
    }
}
~~~
### 4:使用栈实现队列（方法2-双栈法） 232 原方法辅助n2
设计一个队列，支持基本的队列操作，这个队列的内部存储数据的结构为栈，栈的方法只能包括push  top  pop  size  empty等标准的栈方法
> 思路1 复杂度n2
在 队列 push元素时，利用临时 栈 调换元素次序
1 将原数据栈 data_stack 内容 push 进入临时栈 temp_stack
2 将新数据 push 进入 临时栈 temp_stack
3 将临时栈 temp_stack 中的元素 push 进入 数据栈 data_stack

>思路2 复杂度n
1.push操作时，即直接将元素push到input_stack
2.pop和peek（front）操作时，需要进行调整
完成调整后，直接返回output.top()
调整算法：adjust
如果output不空，则不需要调整，直接弹出栈顶；
否则，将input_stack中的元素push进入output_stack,
每push一个元素，input_stack弹出一个元素
3.empty操作，input与output均为空时，返回true，否则返回false


