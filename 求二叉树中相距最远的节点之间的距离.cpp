#include<iostream>

using namespace std;

struct Node{
    Node *left;
    Node *right
};

int maxDistance(Node *root)
{
    int depth;
    return helper(root,depth);
}

int helper(Node *root,int &depth)
{
    if(root == NULL)
    {
        depth = 0;
        return 0;
    }
    int ld,rd;
    int maxleft = helper(root->left,ld);
    int maxright = helper(root->right,rd);

    depth = max(ld,rd) + 1;
    return max(maxleft, max(maxright, ld+rd));
}
