#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define inf 2147483647

int cost(int x1, int y1, int x2, int y2, vector<vector<char>> mat)
{
    if(x1==x2 && y1==y2)
    {
        if(mat[x1][y1]=='*')
            return 1;
        return 0;
    }
    int ans=0;
    if(mat[x1][y1]=='*')
        ans++;
    if(mat[x2][y2]=='*')
        ans++;
    return ans;
}

int solve(int n, vector<vector<char>> mat, vector<vector<vector<int>>> dp, int row1, int col1, int row2)
{
    int col2=row1+col1-row2;
    // if(row1>=n || row2 >= n || col1>=n || col2>=n)
    //     return -1*inf;
    if(row1==n-1 && row2 ==n-1 && col1==n-1 && col2==n-1)
        return 0;

    if(dp[row1][col1][row2] != -1)
        return dp[row1][col1][row2];
    int ch1=-1*inf, ch2=-1*inf, ch3=-1*inf, ch4=-1*inf;

    // path1 go to down and path2 go to right
    if(row1+1<n && col2+1<n && mat[row1+1][col1]!='#' && mat[row2][col2+1]!='#')
        ch1=cost(row1+1, col1, row2, col2+1, mat)+solve(n, mat, dp, row1+1, col1, row2);

    // path1 go to down and path2 go to down
    if(row1+1<n && row2+1<n && mat[row1+1][col1] != '#' && mat[row2+1][col1] != '#')
        ch2=cost(row1+1, col1, row2+1, col2, mat)+solve(n, mat, dp, row1+1, col1, row2+1);

    // path1 go to right and path2 go to down
    if(col1+1<n && row2+1<n && mat[row1][col1+1] != '#' && mat[row2+1][col2] != '#')
        ch3=cost(row1, col1+1, row2+1, col2, mat)+solve(n, mat, dp, row1, col1+1, row2+1);

    // path2 go to right and path2 go to right
    if(col1+1<n && col2+1<n && mat[row1][col1+1] != '#' && mat[row2][col2+1] != '#')
        ch4=cost(row1, col1+1, row2, col2+1, mat)+solve(n, mat, dp, row1, col1+1, row2);
    printf("dp[%d][%d][%d]= %d\n", row1, col1, row2, max({ch1, ch2, ch3, ch4}));
    return dp[row1][col1][row2]=max({ch1, ch2, ch3, ch4});
}

int maxNoDiamond(vector<vector<char>> mat, int n)
{
    int ans=0;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
    if(mat[0][0]=='#' || mat[n-1][n-1]=='#')
        return -1;
    if(mat[0][0]=='*')
        ans++;
    mat[0][0]='.';
    if(mat[n-1][n-1]=='*')
        ans++;
    mat[n-1][n-1]='.';
    ans+=solve(n, mat, dp, 0, 0, 0);
    return ans;
}

int main()
{
    int sizeOfMat;
    cin>>sizeOfMat;
    vector<vector<char>> mat(sizeOfMat, vector<char>(sizeOfMat));
    for(int i=0;i<sizeOfMat;i++)
        for(int j=0;j<sizeOfMat;j++)
            cin>>mat[i][j];

    cout<<maxNoDiamond(mat, sizeOfMat)<<endl;
}
