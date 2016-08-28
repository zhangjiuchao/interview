/* 通用字符串匹配
模式串包含'*'和'?' 通用字符串
其中'*'匹配任意长度的字符串
'?'匹配任意一个字符
*/
#include<iostream>

const int MAX_SIZE = 100;
using namespace std;


bool match(char * str, char * ptn)
{
    if(*ptn == '\0') return true;
    if(*ptn == '*')           //匹配'*'
    {
        do
        {
            if(match(str++,ptn + 1))
                return true;
        }while(*str != '\0');
    }
    if(*str == '\0') return false;
    if(*str == *ptn || *ptn == '?')
        return match(str+1,ptn+1);
    return false;
}

int main()
{
    char str[MAX_SIZE];
    char ptn[MAX_SIZE];

    cin>>str;
    cin>>ptn;

    bool ismatch = match(str,ptn);
    if(ismatch)
        cout<<"match"<<endl;
    else
        cout<<"not match"<<endl;
    return 0;
}
