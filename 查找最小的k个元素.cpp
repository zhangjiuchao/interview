/*找出数组中最小的k个元素
**可以有几种方法：
**1、先从小到大排序，给出前k个元素，时间复杂度为O(nlogn)
**2、插入排序，知道前k个数找出来，事件复杂度为O(kn)
**3、维护一个k个数的大顶堆，保存当前遍历到的最小的k个元素，时间复杂度为O(n+klogn)

**这里我采用维护大顶堆的方法
*/
#include<iostream>

using namespace std;

const int MAX_SIZE = 100;

//将堆N调整为大顶堆
void HeapAdjust(int N[],int start,int end)
{
    int rc = N[start];

    for(int j = 2*start;j <= end;j*=2)      //沿值较大的孩子向下筛选
    {
        if(j < end && N[j] < N[j+1])    ++j;       //j为值较大的孩子下标
        if(!(rc < N[j]))    break;              //rc应插在位置start处
        N[start] = N[j];
        start = j;
    }
    N[start] = rc;                       //插入
}

int main()
{
    int len = 0;
    cout<<"Enter the number of integers:"<<endl;
    cin>>len;

    int nums[MAX_SIZE + 1];
    cout<<"Enter the integers:"<<endl;
    for(int i = 1;i <= len;++i)
        cin>>nums[i];

    int k;
    cout<<"Enter the k:"<<endl;
    cin>>k;
    if(len <= k)
    {
        for(int i = 1;i <= len;++i)
            cout<<nums[i]<<" ";
        cout<<endl;
    }
    else
    {
        for(int i = k/2;i > 0;--i)
            HeapAdjust(nums,i,k);
        for(int i = k+1;i<=len;++i)
        {
            if(nums[i] < nums[1])
            {
                nums[1] = nums[i];
                HeapAdjust(nums,1,k);
            }
        }

        for(int i = 1;i <= k;++i)
            cout<<nums[i]<<" ";
        cout<<endl;
    }

    return 0;
}


