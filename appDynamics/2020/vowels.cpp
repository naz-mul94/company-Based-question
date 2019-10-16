#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<int> vowels(vector<string> words, vector<string> query)
{
    vector<int> temp(words.size(), -1);
    vector<int> ans;
    int l, r;
    for (int i = 0; i < query.size(); ++i)
    {
        string str="";
        int j=0, word=0;
        while(query[i][j]!='-')str+=query[i][j++];
        l=stoi(str);
        str="";
        j=query[i].size()-1;
        while(query[i][j]!='-')str+=query[i][j--];
        r=stoi(str);
        for (int j = l-1; j < r; ++j)
        {
            int n=words[j].size()-1;
            if((words[j][0]=='a' || words[j][0]=='i' || words[j][0]=='e' || words[j][0]=='o' || words[j][0]=='u') && (words[j][n]=='a' || words[j][n]=='i' || words[j][n]=='e' || words[j][n]=='o' || words[j][n]=='u'))
                word++;
        }
        ans.push_back(word);
        word=0;
    }
    return ans;
}


int main()
{
    int testCase;
    cin>>testCase;
    while(testCase--)
    {
        int noStr, noQuerry;
        cin>>noStr;
        vector<string> words(noStr);
        for(int i=0;i<noStr;i++)cin>>words[i];

        cin>>noQuerry;
        vector<string> query(noQuerry);
        for(int i=0;i<noQuerry;i++)cin>>query[i];

        vector<int> ans=vowels(words, query); 
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
    }
}
