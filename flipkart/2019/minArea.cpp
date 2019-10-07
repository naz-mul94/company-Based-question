#include<iostream>
#include<stack>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
#define ll long long int
ll minArea(vector<int> x, vector<int> y)
{
    map<pair<int, int>, set<int>> mp;
    for (int i = 1; i < x.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if(x[i]==x[j])
            {
                mp[{min(y[i], y[j]), max(y[i], y[j])}].insert(x[i]);
            }

        }
    }

    int ans=2147483647;
    for (auto i=mp.begin(); i!=mp.end();i++)
    {
        int a=i->first.second-i->first.first;
        vector<int> xs(i->second.begin(), i->second.end());
        int n=xs.size();
        for (int j=1;j<n;j++)
        {
            int x=xs[j]-xs[j-1];
            if(a*x<ans)ans=a*x;
        }
    }
    return ans;
}
