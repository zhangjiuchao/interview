/*输入一个已经按升序排序过得数组和一个数字
  在数组中查找两个数，使得它们的和正好是输入的那个数字
  要求时间复杂度是O(n)
  如果有多对数字的和等于输入的数字，输出任意一对即可
*/

#include<iostream>
using namespace std;

bool find2Number(int a[],int len,int dest)
{
    int s = 0;
    int e = len - 1;
    while(s != e)
    {
        if(a[s] + a[e] == dest)
        {
            cout<<a[s]<<"+"<<a[e]<<"="<<dest<<endl;
            return true;
        }
        else if(a[s] + a[e] < dest)
            ++s;
        else
            --e;

    }
    return false;
}

int main()
{
    int nums[] = {1,5,8,9,10,25,36,45,52,64,78};
    bool flag = find2Number(nums,11,61);
    if(!flag)
        cout<<"not exist"<<endl;
    return 0;
}
