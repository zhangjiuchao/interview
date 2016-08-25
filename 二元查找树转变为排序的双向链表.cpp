#include<iostream>
using namespace std;

struct BSTreeNode
{
    int m_nValue;
    BSTreeNode *m_pLeft;
    BSTreeNode *m_pRight;
};

typedef pair<BSTreeNode*, BSTreeNode*> HeadandTail;

HeadandTail BSTreeToDlist(BSTreeNode *root)
{
    if(root == NULL)
        return HeadandTail(NULL,NULL);

    BSTreeNode *headPtr = root;
    BSTreeNode *endPtr = root;

    if(root->m_pLeft != NULL)
    {
        HeadandTail lResult = BSTreeToDlist(root->m_pLeft);
        headPtr = lResult.first;
        lResult.second->m_pRight = root;
        root->m_pLeft = lResult.second;
    }

    if(root->m_pRight != NULL)
    {
        HeadandTail rResult = BSTreeToDlist(root->m_pRight);
        endPtr = rResult.second;
        rResult.first->m_pLeft = root;
        root->m_pRight = rResult.first;
    }

    return HeadandTail(headPtr, endPtr);
}

int main()
{
    /* ²âÊÔµÄ¶þÔªÊ÷£º    10
                         /\
                        /  \
                       6   14
    */
    BSTreeNode *root = new BSTreeNode;
    root->m_nValue = 10;
    BSTreeNode *left = new BSTreeNode;
    left->m_nValue = 6;
    left->m_pLeft = NULL;
    left->m_pRight = NULL;
    BSTreeNode *right = new BSTreeNode;
    right->m_nValue = 14;
    right->m_pLeft = NULL;
    right->m_pRight = NULL;

    root->m_pLeft = left;
    root->m_pRight = right;
    HeadandTail result = BSTreeToDlist(root);

    BSTreeNode *head = result.first;
    BSTreeNode *tail = result.second;

    while(head != NULL)
    {
        cout<<head->m_nValue<<" ";
        head = head->m_pRight;
    }
    cout<<endl;

    while(tail != NULL)
    {
        cout<<tail->m_nValue<<" ";
        tail = tail->m_pLeft;
    }
    cout<<endl;
    return 0;
}
