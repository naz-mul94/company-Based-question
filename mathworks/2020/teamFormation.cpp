/*
** any suggestion highly appreciated
** feel free to modify.
*/

#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

long long int teamFromation(vector<int> score, int noMember, int m)
{
    long long int ans=0;
    int n=score.size();
    priority_queue<pair<int, int>> memberScore;
    for(int i=0;i<m;i++)memberScore.push({score[i], i});
    for(int i=n-m;i<n;i++)memberScore.push({score[i], i});    
    int low=m-1;
    int high=n-m;
    while(high>low && noMember)
    {
        pair<int, int> temp=memberScore.top();
        memberScore.pop();
        ans+=temp.first;
        noMember--;
        if(temp.second<=low)
        {
            low++;
            if(low < high)
                memberScore.push({score[low], low});
        }
        else if(temp.second>=high)
        {
            high--;
            if(high>low)memberScore.push({score[high], high});
        }
    } 
    while(!memberScore.empty() && noMember)
    {
        ans+=memberScore.top().first;
        memberScore.pop();
        noMember--;
    }   
    return ans;
}


int main()
{
    int testCase;
    cin>>testCase;
    while(testCase--)
    {
        int noSore,noMember, m;
        cin>>noSore>>noMember>>m;
        vector<int> score(noSore);
        for(int i=0;i<noSore;i++)
            cin>>score[i];
        cout<<teamFromation(score, noMember, m)<<endl;
    }
    return 0;
}
