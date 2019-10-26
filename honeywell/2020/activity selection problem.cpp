#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void maxNo(vector<vector<int>> jobTime, int n)
{
    sort(jobTime.begin(), jobTime.end());
    vector<int> ans;
    ans.push_back(jobTime[0][2]+1);
    int j=0;
    for(int i=1;i<n;i++)
    {
        if(jobTime[i][1]>=jobTime[j][0])
        {
            ans.push_back(jobTime[i][2]+1);
            j=i;
        }
    }
    for(int i=0;i<ans.size();i++)
        printf("%d ", ans[i]);
}

int main()
{
    int testCase;
    cin>>testCase;
    while(testCase--)
    {
        int noInput;
        cin>>noInput;
        vector<vector<int>> jobTime(noInput, vector<int>(3));

        for(int i=0;i<noInput;i++)
            cin>>jobTime[i][1];
        for(int j=0;j<noInput;j++)
        {
            cin>>jobTime[j][0];
            jobTime[j][2]=j;
        }
        maxNo(jobTime, noInput);
        cout<<endl;
    }
    

}
