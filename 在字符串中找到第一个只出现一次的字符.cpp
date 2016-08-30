#include<iostream>
#include<string>
using namespace std;

char findOne(string str)
{
    int len = str.length();
    int flag[255] = {0};
    for(int i=0;i<len;++i)
        flag[str[i]]++;
    for(int i=0;i<len;++i)
    {
        if(flag[str[i]] == 1)
            return str[i];
    }
    return '\0';
}

int main()
{
    string str;
    cin>>str;
    cout<<findOne(str)<<endl;
    return 0;
}
