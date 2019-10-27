#include<iostream>
#include<vector>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;

bool isValid(vector<int> arr, int n)
{
    stack<int> s;
    int root=INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        if(arr[i]<root)return false;
        else
        {
            while(!s.empty() && s.top()<arr[i])
            {
                root=s.top();
                s.pop();
            }
        }
        s.push(arr[i]);
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    if(isValid(arr,n))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;    

}
