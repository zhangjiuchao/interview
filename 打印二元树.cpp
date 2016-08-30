/*
    输入一颗二元树，从上往下按层打印树的每个节点，同一层按照从左往右的顺序打印
*/

#include<iostream>
#include<queue>

using namespace std;

struct BTNode{
    int data;
    BTNode *left;
    BTNode *right;
};

void printBylayer(BTNode *root)
{
    queue<BTNode*> q;
    if(root != NULL)
    {
        q.push(root);
        while(!q.empty())
        {
            BTNode *temp = q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left != NULL)  q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
    }
}
