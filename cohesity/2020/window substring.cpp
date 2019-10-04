#include<iostream>
#include<string>
using namespace std;

string windowSubstr(string str, string pattern)
{
    int lenStr=str.size();
    int lenPatt=pattern.size();
    int count=0, start=0, strIdx=-1, minLen=2147483647;
    int hashStr[26]={0}, hashPatt[26]={0};
    if(lenStr<lenPatt)return "-1";
    for(int i=0;i<lenPatt;i++)hashPatt[pattern[i]-'a']++;

    for (int i = 0; i < lenStr; ++i)
    {
        hashStr[str[i]-'a']++;
        if(hashStr[str[i]-'a']<=hashPatt[str[i] - 'a'])
            count++;
        if(count==lenPatt)
        {
            while(hashPatt[str[start] - 'a']==0 || hashStr[str[start] - 'a']> hashPatt[str[start] - 'a'])
            {
                hashStr[str[start] - 'a']--;
                start++;
            }

            int newLen = i - start +1;
            if(minLen>newLen)
            {
                strIdx= start;
                minLen = newLen;
            }
        }
    }

    if(strIdx==-1)return "-1";
    return str.substr(strIdx, minLen);

}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string str, pattern;
        cin>>str>>pattern;
        cout<<windowSubstr(str, pattern)<<endl;
    }
}
