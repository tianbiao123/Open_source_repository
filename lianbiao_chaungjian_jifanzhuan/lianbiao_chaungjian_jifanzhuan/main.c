#include <stdio.h>
#include <stdlib.h>

/*head->1->2->3->4->5->NULL*/
/*����ڵ㷴ת*/
typedef struct FZ
{
    int data;
    struct FZ *next;
}fz;
//��������
fz* set_list();
void head_insertion(fz* head, int data);
void Reversal_list(fz* head);
void print(fz* head);
//1������һ���յĵ�����
fz* set_list()
{
    //��������ͷ�ڵ�
    fz* head = (fz*)malloc(sizeof(fz));
    if (head == NULL)
    {
        printf("malloc faile\n");
        return NULL;
    }
    //����ֵ
    head->next = NULL;
    return head;
}
//2��ͷ�巨��������  dataҪ���������
void head_insertion(fz* head,int data)
{
    fz* temp = (fz*)malloc(sizeof(fz));
    if (temp == NULL)
    {
        printf("malloc failen\n");
        return;
    }
    //����ֵ
    temp->data = data;
    temp->next = NULL;
    //ͷ�巨����ڵ�
    //�ȴ���β����NULL
    temp->next = head->next;
    //head����ָ���µĽڵ�
    head->next = temp;
    return;
}
//3������ת
void Reversal_list(fz * head)
{
    //p����ָ����һ������ڵ�
    fz* p = head->next;
    //�ȶϿ�ͷ�ڵ������
    head->next = NULL;
    //q����ÿ�ε��������²���
    fz* q = p;
    while (q != NULL)
    {
        //ÿ��p��ָ����һ���ڵ�
        p = p->next;
        //ʹ��q����ͷ��
        //�ȴ���β����NULL
        q->next = head->next;
        //��head����ָ���µĽڵ�
        head->next = q;
        //����q��ָ���pһ��
        q = p;
    }
}
//4������ѭ�����
void print(fz* head)
{
    //����ж�
    if (head == NULL)
    {
        printf("����������\n");
        return;
    }
    //ѭ����ӡ�����������
    while ((head->next) != NULL)
    {
        head = head->next;
        printf("%d ", head->data);
    }
    putchar('\n');
}
int main(void)
{
    //ָ��ͷ�ڵ��ָ��
    fz* head = NULL;
    //��������һ��ָ��ͷ�ڵ��ָ�����
    head = set_list();
    int i;
    //����10�β���10���ڵ�
    for (i = 0; i < 10; i++)
    {
        head_insertion(head,i+1);
    }
    print(head);
    Reversal_list(head);
    print(head);
    return 0;
}