////////////////////////////////////////////////////////
//输入一个整数n，求从1到n这n个整数的十进制中1出现的次数
////////////////////////////////////////////////////////

//分析：
//设n = ABCDE
//当E = 0时，个位上是1的整数个数是ABCD(0~ABCD-1),当E>=1时，个位上是1的整数个数ABCD+1（0~ABCD）；
//当D = 0时，十位上是1的整数个数是ABC*10,当D = 1时，十位上是1的整数个数ABC*10+E+1,当D>1时，十位上是1的整数个数(ABC+1)*10
//。。。。。。
#include<iostream>

using namespace std;
int timesof1(int n)
{
    int prefix[10];
    int suffix[10];
    int digit[10];
    int i = 0;
    int base = 1;
    while(base < n)
    {
        suffix[i] = n % base;
        digit[i] = (n%(base*10))/base;
        prefix[i] = n/(base*10);
        ++i;
        base*=10;
    }

    base = 1;
    int count = 0;
    for(int j=0;j<i;++j,base*=10)
    {
        if(digit[j]<1)  count += prefix[j]*base;
        else if(digit[j] == 1)  count += prefix[j]*base + suffix[j] + 1;
        else    count += prefix[j]*base + base;
    }
    return count;
}

int main()
{
    cout<<timesof1(12)<<endl;
    return 0;
}
