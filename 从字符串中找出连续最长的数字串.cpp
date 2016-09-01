#include<iostream>
#include<cstdio>
using namespace std;

const int MAX_SIZE = 100;

int continumax(char *outputstr,char *inputstr)
{
    int maxLen = 0;
    int len = 0;
    char *pstart;
    while(*inputstr != '\0')
    {
        if(*inputstr >=48 && *inputstr <= 57)
            len ++;
        else
        {
            if(len > maxLen)
            {
                maxLen = len;
                pstart = inputstr - len;

            }
            len = 0;
        }
        ++inputstr;
    }
    for(int i=0;i<maxLen;++i)
        outputstr[i] = pstart[i];
    outputstr[maxLen] = '\0';
    return maxLen;
}

int main()
{
    char inputstr[] = "sd3214321654ds65464213fsd6545";
    char outputstr[MAX_SIZE];
    int maxSubLen = continumax(outputstr,inputstr);
    if(maxSubLen > 0)
        cout<<outputstr<<endl;
    else
        cout<<"该字符串中没有数字串."<<endl;
    return 0;
}
