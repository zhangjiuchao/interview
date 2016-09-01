//////////////////////////////
//input n and m,select several integers from list(1,2,3,...,n)
//and the sum of them equals to m
//list all the combinations
////////////////////////////////////////////


//similar to 0-1 bag
#include<iostream>
#include<cstring>
using namespace std;

void print(int aux[],int n)
{
    for(int i = 0;i<n;++i)
    {
        if(aux[i] == 1)
            cout<<i+1<<" ";
    }
    cout<<endl;
}

void helper(int dest,int a[],int index,int n)
{
    if(dest == 0)
        print(a,n);
    if(dest > 0 && index < n)
    {
        helper(dest,a,index + 1,n);
        a[index] = 1;
        helper(dest - index - 1,a,index+1,n);
        a[index] = 0;
    }
}
void findCombination(int n, int m)
{
    if(n > m)
        findCombination(m,m);
    else
    {
        int aux[n];
        memset(aux,0,n*sizeof(int));
        helper(m,aux,0,n);
    }

}

int main()
{
    findCombination(10, 6);
    return 0;
}
