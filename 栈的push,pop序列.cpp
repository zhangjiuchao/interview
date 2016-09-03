/////////////////////////////////////////////////
//输入两个整数序列。其中一个序列表示栈的push顺序，
//判断另一个序列有没有可能是对应的pop顺序
/////////////////////////////////////////////////

#include<iostream>
#include<stack>

using namespace std;

bool isPopSeries(int push[],int pop[],int len)
{
    int poppos = 0;
    int pushpos = 0;
    stack<int> S;
    while(pushpos < len || !S.empty())
    {
        if(pushpos < len)
        {
            if(push[pushpos] == pop[poppos])
                ++poppos;
            else
            {
                if(!S.empty() && S.top() == pop[poppos])
                {
                    ++poppos;
                    S.pop();
                }
                S.push(push[pushpos]);
            }
            ++pushpos;
        }
        else
        {
            if(!S.empty() && S.top() != pop[poppos])
                return false;
            S.pop();
            ++poppos;
        }
    }
    return true;
}

int main()
{
    int push[] = {1,2,3,4,5};
    int pop[]  = {2,1,4,5,3};
    cout<<isPopSeries(push,pop,5)<<endl;
    return 0;
}
