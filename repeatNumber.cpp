/*一个用1001个整数组成的数组，这些整数是任意排列的，所有的整数都在1到1000（包括1000）之间。
此外，除一个数字出现两次之外，其他所有数字都只出现一次，找出这个重复的数字
*/

#include<iostream>

using namespace std;

const int MAX_SIZE = 1005;

//第一种方法：通过交换数组中整数的位置，使得整数i在数组中的位置i上,如果找到整数i,且整数i不在对应的位置上，且对应的位置上以及存在一个整数i，则i是重复的那个数
int repeatNumber(int nums[],int len)        //数组下标从1开始
{
    int pos = 1;
    while(pos <= len)
    {
        if(nums[pos] == pos)
            ++pos;
        else
        {
            if(nums[pos] == nums[nums[pos]])
                return nums[pos];
            int temp = nums[nums[pos]];
            nums[nums[pos]] = nums[pos];
            nums[pos] = temp;
        }
    }
}

//第二种方法，利用异或,因为A XOR A XOR B = B
int findX(int nums[],int len) //数组下标从0开始
{
    int k = nums[0];
    for(int i = 1;i < len;++i)          //k=1^2^..^1000^1^2..^1000^num,其中num是重复的那个数
        k ^= nums[i]^i;
    return k;
}

