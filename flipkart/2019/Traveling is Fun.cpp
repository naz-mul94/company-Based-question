#include <bits/stdc++.h>

using namespace std;
vector<int> par;
vector<int> rank1;

int gcd(int i, int j)
{
    if(i==0)return j;
    return gcd(j%i, i);
}

int findRoot(int i)
{
    int x = par[i];
    if(x!=i)
        par[i]=findRoot(x);
    return par[i];
}

void merge(int i, int j)
{
    int rootI=findRoot(i);
    int rootJ=findRoot(j);
    if(rank1[rootI]<rank1[rootJ])
    {
        par[rootI]=rootJ;
        rank1[rootJ]+=rank1[rootI];
    }
    else
    {
        par[rootJ]=rootI;
        rank1[rootI]+=rank1[rootJ];
    }
}

vector<int> connectedCities(int n, int g, vector<int> from, vector<int> to) {
    par.resize(n+1, -1);
    rank1.resize(n+1, 0);
    for(int i=1;i<=n;i++)par[i]=i;
    for (int i=g+1;i<=n;i++)
    for(int j=i+i;j<=n;j+=i)
    {
         
             merge(j, j-i);
    }

    int m = from.size();
    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        if(findRoot(from[i])==findRoot(to[i]))
            ans[i]=1;
        else ans[i]=0;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int g;
    cin >> g;
    int originCities_cnt;
    cin >> originCities_cnt;
    vector<int> originCities(originCities_cnt);
    for(int originCities_i = 0; originCities_i < originCities_cnt; originCities_i++){
    	cin >> originCities[originCities_i];
    }
    int destinationCities_cnt;
    cin >> destinationCities_cnt;
    vector<int> destinationCities(destinationCities_cnt);
    for(int destinationCities_i = 0; destinationCities_i < destinationCities_cnt; destinationCities_i++){
    	cin >> destinationCities[destinationCities_i];
    }
    vector <int> res = connectedCities(n, g, originCities, destinationCities);
    for (ssize_t i = 0; i < res.size(); i++) {
        cout << res[i] << (i != res.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
