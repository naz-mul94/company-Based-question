#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int X[]={2, 2, -2, -2, 1, -1, 1, -1};
int Y[]={1, -1, 1, -1, 2, 2, -2, -2};
int minStep(int xK,  int yK, int xT, int yT, int N)
{
    int ans=2147483647;
    queue<pair<pair<int, int>, int>> coOrd;
    bool visited[N+1][N+1];
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)visited[i][j]=false;
    coOrd.push({{xK, yK}, 0});
    visited[xK][yK]=true;
    while(!coOrd.empty())
    {
        pair<pair<int, int>, int> temp=coOrd.front();
        coOrd.pop();
        int x=temp.first.first;
        int y=temp.first.second;
        int step=temp.second;
        if(x==xT&&y==yT)
            if(step<ans)ans=step;
        for (int i = 0; i < 8; ++i)
        {
            int newX=x+X[i];
            int newY=y+Y[i];
            if(newX>0 && newX<=N && newY>0 && newY<=N && !visited[newX][newY])
            {
                coOrd.push({{newX, newY}, step+1});
                visited[newX][newY]=true;
            }
        }
    }  
    return ans;      
}

int main()
{
    int noInput, xK, yK, xT, yT, N;
    cin>>noInput;
    while(noInput--)
    {
        cin>>N>>xK>>yK>>xT>>yT;
        cout<<minStep(xK, yK, xT, yT, N)<<endl;
    }
    

}
