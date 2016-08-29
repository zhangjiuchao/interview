#include<iostream>

using namespace std;

const int MAX_SIZE = 100;

bool helper(int a[],int s,int e)
{
    if(s == e)  return true;

    int root = a[e];
    int i = e - 1;
    while(i >= s && a[i] > root) --i;

    if(i < e-1 && !helper(a,i+1,e-1))
        return false;

    int k = i;
    while(i >= s)
    {
        if(a[i--] > root)
            return false;
    }

    return helper(a,s,k);
}

bool isPostorderList(int a[],int len)
{
    return helper(a,0,len-1);
}

int main()
{
    int len = 0;
    int nums[MAX_SIZE];
    int integer;
    while(cin>>integer)
        nums[len++] = integer;
    cout<<isPostorderList(nums,len)<<endl;
    return 0;
}
