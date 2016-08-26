#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* reverse(Node *head)
{
    if(head == NULL)    return head;
    Node *pre;
    Node *cur = head->next;
    head->next = NULL;

    while(cur != NULL)
    {
        pre = head;
        head = cur;
        cur = cur->next;
        head->next = pre;
    }

    return head;
}

int main ()
{
    Node *head = new Node;
    head->data = 1;
    head->next = NULL;
    Node *temp = head;

    for(int i=2;i<10;++i)
    {
        Node *p = new Node;
        p->data = i;
        p->next = NULL;
        temp->next = p;
        temp = p;
    }

    Node *newHead = reverse(head);
    while(newHead != NULL)
    {
        cout<<newHead->data<<" ";
        newHead = newHead->next;
    }
    cout<<endl;
    return 0;
}
