#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string result = "0", temp;
unsigned long long x;

inline string plus2(string &str1,string &str2) //高精度加法
{
    string str;
    int len1=str1.length();
    int len2=str2.length();
    //前面补0，弄成长度相同
    if(len1<len2)
    {
        for(int i=1;i<=len2-len1;i++)
           str1="0"+str1;
    }
    else
    {
        for(int i=1;i<=len1-len2;i++)
           str2="0"+str2;
    }
    len1=str1.length();
    int cf=0;
    int temp;
    for(int i=len1-1;i>=0;i--)
    {
        temp=str1[i]-'0'+str2[i]-'0'+cf;
        cf=temp/10;
        temp%=10;
        str=char(temp+'0')+str;
    }
    if(cf!=0)  str=char(cf+'0')+str;
    return str;
}

int main() {
    freopen("secret/sample/U17650/1.in","r",stdin);
    ios::sync_with_stdio(false);
    while(cin >> x) {
        temp = to_string(x);
        result = plus2(result, temp);
    }
    cout << result << endl;
}