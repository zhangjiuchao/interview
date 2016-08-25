#include<iostream>
#include<vector>

using namespace std;

int maxSubArr(vector<int> &vec)
{
    int len = vec.size();
    if(len <= 0)
    {
        cout<<"数组长度为0"<<endl;
        return - (1 << 31);
    }
    int sum = 0;
    int max = - (1 << 31);
    for(int cur = 0;cur <len; ++cur)
    {
        sum += vec[cur];
        if(sum > max)
            max = sum;
        else if(sum < 0)
            sum = 0;
    }

    return max;
}

int main()
{
    vector<int> nums;
    int integer;
    while(cin>>integer)
        nums.push_back(integer);

    int maxSum = maxSubArr(nums);
    cout<<maxSum<<endl;
    return 0;
}
