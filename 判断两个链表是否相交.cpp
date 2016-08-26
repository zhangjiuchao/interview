/*---------------------------------
    判断两个链表是否相交
-----------------------------------
***给出两个单向链表的头指针，比如h1,h2，判断这两个链表是否相交
*/

#include<iostream>

using namespace std;
struct Node{
    int data;
    Node *next;
};

/*--------------------------
    情况一：两个链表均不带环
  --------------------------
*/
bool isJoinedSimple(Node *h1,Node *h2)
{
    if(h1 == NULL || h1 == NULL)
        return false;
    Node *temp1 = h1;
    for(;temp1->next != NULL; temp1 = temp1->next);

    Node *temp2 = h2;
    for(;temp2->next != NULL; temp2 = temp2->next);

    return temp1 == temp2;
}

//test


/*----------------------
    情况二：链表可能有环
  ----------------------
*/

//判断链表是否有环
Node* testCycle(Node *hPtr)
{
    Node *h1 = hPtr;
    Node *h2 = hPtr;

    while(h2 !=NULL && h2->next != NULL)   //h2每次走两步，h1每次走一步，若没环，h2最先到链尾，若有环，h2会转回来追上h1
    {
        h1 = h1->next;
        h2 = h2->next->next;

        if(h1 == h2)
            return h1;
    }
    return NULL;
}

bool isJoined(Node *h1,Node *h2)
{
    Node *cylic1 = testCycle(h1);
    Node *cylic2 = testCycle(h2);

    if(cylic1 == NULL && cylic2 == NULL)   //两个都没环
        return isJoinedSimple(h1,h2);
    if(cylic1 != NULL && cylic2 != NULL)    //两个都有环
    {
        Node *p = cylic1;
        while(1)
        {
            if(p == cylic2 || p->next == cylic2)    return true;
            p = p->next->next;
            cylic1 = cylic1->next;
            if(p == cylic1)    return false;
        }
    }
    else       //一个有环一个没环，必不相交
        return false;
}

