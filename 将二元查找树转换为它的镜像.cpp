/*----------------------------
    将二元查找树转换为它的镜像
  ----------------------------
  即在转换后的二元查找树中，左子树的节点都大于右子树的节点
  用递归和循环两种方法完成数的镜像转换。
*/
#include<iostream>
#include<stack>
using namespace std;

struct BSTNode{
    int data;
    BSTNode *left;
    BSTNode *right;
};

/*---------------------------
    递归方式实现
  ---------------------------
*/
BSTNode* mirrorRecursion(BSTNode *root)
{
    if(root == NULL)
        return NULL;

    Node *lptr = mirrorRecursion(root->left);
    Node *rptr = mirrorRecursion(root->right);

    root->left = rptr;
    root->right = lptr;

    return root;
}

/*---------------------------------
    循环方式实现
  ---------------------------------
*/
void swap(BSTNode **l,BSTNode **r)
{
    BSTNode *temp = *l;
    *l = *r;
    *r = temp;
}

BSTNode* mirrorNoRecursion(BSTNode *root)
{
    stack<BSTNode*> S;
    S.push(root);
    while(!S.empty())
    {
        BSTNode *top = S.top();
        S.pop();
        if(top != NULL)
        {
            swap(&(top->left),&(top->right));
            S.push(top->left);
            S.push(top->right);
        }
    }

    return root;
}
