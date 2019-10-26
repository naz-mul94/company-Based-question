#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main()
{
    int num, start=0;
    cin>>num;
    vector<int> ans;
    ans.push_back(0);
    int addMask, noSetBit=0, pos=1;
    for(int i=31;i>=0;i--)
    {
        addMask=1<<i;
        if((addMask & num) !=0)
        {
            if(!start)
            {
                start=1;
                ans.push_back(pos);
                noSetBit++;
            }
            else
            {
                ans.push_back(pos);
                noSetBit++;
            }
        }
        if(start)pos++;
    }
    ans[0]=noSetBit;
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i] );
    cout<<endl;

}
