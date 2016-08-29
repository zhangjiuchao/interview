//输入一个单项链表，输出该链表中倒数第k个节点。链表的倒数第0个节点为链表的尾指针

#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};
/*---------------------
    第一种方法：递归
  ---------------------
*/
Node* helper(Node *p,int k,int &pos)
{
    if(p == NULL)
    {
        pos = -1;
        return NULL;
    }
    int dep;
    Node *ptr = helper(p->next,k,dep);
    if(ptr == NULL)
    {
        pos = dep + 1;
        if(pos == k)
            return p;
        return NULL;
    }

    return ptr;
}

Node* findLastKth(Node *head, int k)
{
    int pos;
    return helper(head,k,pos);
}
/*-----------------------
    第二种方法：记录两个指针，先让其中一个指针从头指针开始向后移动k步，然后两个指针同时向后移动，
    当第一个指针到达尾指针时，第二个指针刚好在倒数第k个节点处
*/

Node* lastKth(Node *head,int k)
{
    Node *p1 = head,*p2 = head;
    for(;k>0;--k)
    {
        if(p1->next != NULL)
            p1 = p1->next;
        else
            return NULL;
    }

    while(p1->next != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}

int main()
{
    Node *head = new Node;
    head->data = 0;
    head->next = NULL;
    Node *cur = head;
    for(int i=1;i<10;++i)
    {
        Node *ptr = new Node;
        ptr->data = i;
        ptr->next = NULL;
        cur->next = ptr;
        cur = ptr;
    }

    Node *result = findLastKth(head,3);
    if(result != NULL)
        cout<<result->data<<endl;
    else
        cout<<"not find"<<endl;
    return 0;
}
