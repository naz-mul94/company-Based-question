#include<iostream>
#include<vector>
using namespace std;


int lis(vector<int> &num)
{
	vector<int> dp(num.size(), 1);
	for(int i=1;i<num.size();i++)
	{
		for(int j=0;j<i;j++)
		if(num[i]>num[j]&&dp[i]<dp[j]+1)
		{
			dp[i]=1+dp[j];
		}	
	}
	int maxi=-1;
	for (int i = 0; i < num.size(); ++i)
	{
		if(maxi<dp[i])
		{
			maxi=dp[i];
		}
	}
	return maxi;
}


int main()
 {
	int noInput;
	cin>>noInput;
	int len;
	for (int i = 0; i < noInput; ++i)
	{
		cin>>len;
		if(len==0)return 0;
		if(len==1)return 1;
		vector<int> num(len, 0);
		for(int i=0;i<len;i++)
			cin>>num[i];
		cout<<lis(num)<<endl;

	}
}
