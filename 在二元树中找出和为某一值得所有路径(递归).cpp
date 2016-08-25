#include<iostream>

using namespace std;

const int MAX_SIZE = 20;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

void printPath(int P[],int top)
{
    for(int i = 0;i<top;++i)
        cout<<P[i]<<" ";
    cout<<endl;
}

void helper(BinaryTreeNode *root,int sum,int path[],int top)
{
    if(root)
    {
       path[top++] = root->m_nValue;
       sum -= root->m_nValue;

       if(!root->m_pLeft && !root->m_pRight)
       {
            if(sum == 0)
                printPath(path,top);
       }
       else
       {
            if(root->m_pLeft) helper(root->m_pLeft,sum,path,top);
            if(root->m_pRight) helper(root->m_pRight,sum,path,top);
       }

       --top;
       sum += root->m_nValue;
    }
}

void printPaths(BinaryTreeNode *root, int sum)
{
    int Path[MAX_SIZE];
    helper(root,sum,Path,0);
}

int main()
{
    BinaryTreeNode *root = new BinaryTreeNode;
    root->m_nValue = 10;
    BinaryTreeNode *left = new BinaryTreeNode;
    left->m_nValue = 5;
    left->m_pLeft = NULL;
    left->m_pRight = NULL;
    BinaryTreeNode *right = new BinaryTreeNode;
    right->m_nValue = 12;
    right->m_pLeft = NULL;
    right->m_pRight = NULL;

    root->m_pLeft = left;
    root->m_pRight = right;

    BinaryTreeNode *left1 = new BinaryTreeNode;
    left1->m_nValue = 4;
    left1->m_pLeft = NULL;
    left1->m_pRight = NULL;
    left->m_pLeft = left1;

    BinaryTreeNode *right1 = new BinaryTreeNode;
    right1->m_nValue = 7;
    right1->m_pLeft = NULL;
    right1->m_pRight = NULL;

    right->m_pRight = right1;

    printPaths(root,29);
    return 0;
}
