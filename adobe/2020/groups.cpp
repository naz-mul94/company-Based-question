/*
There are n people placed in straight line. each person is given an unique number from 1 to n in order. 
you are given m pairs(ai, bi) which implies that person a and person b are enemies. your task is to count the number of different 
groups that do not contain any pair such that they are enemies. A group is defined as an interval(x,y) such that all people in 
the range from x to y form a group.
intput format:
n:no of people
m: no of group
next m line contains first member of pair
again m:no of group
next m line contains second member of pair
*/

#include <bits/stdc++.h> 
using namespace std; 

int ans=0;

void findGroup(int n, unordered_map<int, vector<int>> enemy1, unordered_map<int, vector<int>> enemy2)
{
    int count=0, start=0, flag=0, temp=0;
    for(int i=1;i<=n;i++)
    {
        flag=0;
        if(enemy1.find(i)!=enemy1.end())
        {//printf("i1=%d\n", i);
            for(auto j = enemy1[i].begin();j!=enemy1[i].end();j++)
            if((*j)>=start && (*j)<i)
            {
                
                cout<<count<<endl;
                temp=(count*count-(count*(count-1)/2));
                start=(*j)+1;
                count=i-(*j);
                int x=count-1;
                temp-=(x*x-(x*(x-1)/2));
                flag=1;
                //break;
            }

        }
        if(enemy2.find(i)!=enemy2.end())
        {//printf("i2=%d start=%d\n", i, start);
            for(auto j = enemy2[i].begin();j!=enemy2[i].end();j++)
            if((*j)>=start && (*j)<i)
            {
                
                cout<<count<<endl;
                temp=(count*count-(count*(count-1)/2));
                start=(*j)+1;
                flag=1;
                count=i-(*j);
                int x=count-1;
                temp-=(x*x-(x*(x-1)/2));

            }
        }
        if(!flag)
        {
            count++;
            
        }
        if(flag)
            {//printf("temp=%d\n", temp);
            ans+=temp;//flag=0;
        }

    }
    //if(!flag)
        ans+=(count*count-(count*(count-1)/2));

}


int main() 
{ 

    int n, m;
    cin>>n>>m;
    vector<int> x(m), y(m);
    for(int i=0;i<m;i++)cin>>x[i];
    cin>>m;    
    for(int i=0;i<m;i++)cin>>y[i];
    unordered_map<int, vector<int>> enemy1, enemy2;  
    for(int i=0;i<m;i++)enemy1[x[i]].push_back(y[i]), enemy2[y[i]].push_back(x[i]);
    findGroup(n, enemy1, enemy2);    
    cout<<ans<<endl;
}  
