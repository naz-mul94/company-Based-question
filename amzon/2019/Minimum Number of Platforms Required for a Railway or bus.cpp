#include<iostream>
#include<vector>
#include<string>
#include <algorithm> 
#include <stack> 
#include <cstring> 
using namespace std; 

int minPlat(vector<int> &arr, vector<int> &dep)
{
	sort(arr.begin(), arr.end());
	sort(dep.begin(), dep.end());
	int arrTrainNo=1, deptTrainNo=0;
	int maxPlat=1, ans=1;
	while(arrTrainNo<arr.size()&&deptTrainNo<arr.size())
	{
		if(dep[deptTrainNo]>=arr[arrTrainNo])
		{
			maxPlat++;
			arrTrainNo++;
			if(maxPlat>ans)ans=maxPlat;
		}
		else
		{
			deptTrainNo++;
			maxPlat--;
		}
	}
	return ans;
}

int main()
{
	int noInput;
	cin>>noInput;
	while(noInput--)
	{
		int noTrain;
		cin>>noTrain;
		vector<int> arr(noTrain, 0), dep(noTrain, 0);
		for(int i=0;i<noTrain;i++)cin>>arr[i];
		for(int i=0;i<noTrain;i++)cin>>dep[i];
		cout<<minPlat(arr, dep)<<endl;	
	}
}
