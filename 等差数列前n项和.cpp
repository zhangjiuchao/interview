/*--------------------
    求1+2+3+...+n
  --------------------
    不能使用乘除法、for、while、if、else、switch、case等关键字以及条件判断语句（A?B:C）。
*/

#include<iostream>

using namespace std;

template<int N>
struct CalCls
{
    enum {sum = CalCls<N-1>::sum + N};
};

template<>
struct CalCls<0>
{
    enum {sum = 0};
};


int main()
{
    const int n=10;
    cout<<CalCls<n>::sum<<endl;
    return 0;
}

