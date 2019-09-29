#include<iostream>
#include<vector>
using namespace std;


long long int diceThrow(int face, int noDice, int sum)
{
	vector<vector<long long int>> dp(noDice+1, vector<long long int>(sum+1, 0));
	for(int i=1;i<=sum&&i<=face;i++)
		dp[1][i]=1;
	for(int i=1;i<=noDice;i++)
		for(int j=1;j<=sum;j++)
			for(int k=1;k<=face&&k<j;k++)
				dp[i][j]+=dp[i-1][j-k];
	return dp[noDice][sum];		
}

int main()
 {
	int noInput;
	cin>>noInput;
	int face, noDice, sum;
	for (int i = 0; i < noInput; ++i)
	{
		cin>>face>>noDice>>sum;
		cout<<diceThrow(face, noDice, sum)<<endl;

	}
}
