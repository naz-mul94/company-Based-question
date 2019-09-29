#include<iostream>
#include<vector>
#include<string>
#include <map> 
#include <stack> 
#include <cstring> 
using namespace std; 

int noDecode(string encodeing)
{
	if(encodeing.size()==0||encodeing.size()==1)return 1;
	int ans=0;
	vector<int> dp(encodeing.size()+1, 0);
	dp[0]=1;dp[1]=1;
	for(int i=2;i<=encodeing.size();i++)
	{
		if(encodeing[i-1]-'0'!=0)
			dp[i]+=dp[i-1];
		if((encodeing[i-2]-'0'!=0&&encodeing[i-2]-'0'<2)||(encodeing[i-2]-'0'==2&&encodeing[i-1]-'0'<7))
		dp[i]+=dp[i-2];
		if(dp[i]==0)return 0;
	}
	return dp[encodeing.size()];
}
  
int main()
{
	int noInput;
	cin>>noInput;
	for(int i=0;i<noInput;i++)
	{
		int len;
		string encodeing;
		cin>>len>>encodeing;
		if(encodeing[0]=='0')
		{
		    cout<<"0"<<endl;
		    continue;
		}
		cout<<noDecode(encodeing)<<endl;	
	}
}
