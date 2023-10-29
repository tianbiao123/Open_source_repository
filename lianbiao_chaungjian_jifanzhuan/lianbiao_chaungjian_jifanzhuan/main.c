#include <stdio.h>
#include <stdlib.h>

/*head->1->2->3->4->5->NULL*/
/*链表节点反转*/
typedef struct FZ
{
    int data;
    struct FZ *next;
}fz;
//函数声名
fz* set_list();
void head_insertion(fz* head, int data);
void Reversal_list(fz* head);
void print(fz* head);
//1、创建一个空的单链表
fz* set_list()
{
    //创建链表头节点
    fz* head = (fz*)malloc(sizeof(fz));
    if (head == NULL)
    {
        printf("malloc faile\n");
        return NULL;
    }
    //赋初值
    head->next = NULL;
    return head;
}
//2、头插法插入链表  data要传入的数据
void head_insertion(fz* head,int data)
{
    fz* temp = (fz*)malloc(sizeof(fz));
    if (temp == NULL)
    {
        printf("malloc failen\n");
        return;
    }
    //赋初值
    temp->data = data;
    temp->next = NULL;
    //头插法插入节点
    //先传递尾部的NULL
    temp->next = head->next;
    //head重新指向新的节点
    head->next = temp;
    return;
}
//3、链表反转
void Reversal_list(fz * head)
{
    //p用于指向下一个链表节点
    fz* p = head->next;
    //先断开头节点的连接
    head->next = NULL;
    //q用于每次的链表重新插入
    fz* q = p;
    while (q != NULL)
    {
        //每次p都指向下一个节点
        p = p->next;
        //使用q进行头插
        //先传递尾部的NULL
        q->next = head->next;
        //让head重新指向新的节点
        head->next = q;
        //更新q的指向和p一致
        q = p;
    }
}
//4、链表循环输出
void print(fz* head)
{
    //入参判断
    if (head == NULL)
    {
        printf("单链表不存在\n");
        return;
    }
    //循环打印输出链表数据
    while ((head->next) != NULL)
    {
        head = head->next;
        printf("%d ", head->data);
    }
    putchar('\n');
}
int main(void)
{
    //指向头节点的指针
    fz* head = NULL;
    //函数返回一个指向头节点的指针接收
    head = set_list();
    int i;
    //调用10次插入10个节点
    for (i = 0; i < 10; i++)
    {
        head_insertion(head,i+1);
    }
    print(head);
    Reversal_list(head);
    print(head);
    return 0;
}