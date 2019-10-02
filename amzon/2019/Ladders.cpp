#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> solve (vector<int> query, vector<int> length) {
    vector<int> ans;
    ans.push_back(0);
    int n=length.size();
    int flor=length[0], floorNo=1;
    ans.push_back(flor);
    while(flor<n)
    {
        int temp=flor;
        while(floorNo<=temp&&flor<=n)
        {
            flor=max(flor, floorNo+length[floorNo]);
            floorNo++;
        }
        ans.push_back(flor);
    }
    vector<int> result(query.size(), 0);
    for(int i=0;i<query.size();i++)
    {
        int x=query[i];
        int ladderRequired=lower_bound(ans.begin(), ans.end(), x)-ans.begin();
        result[i]=ladderRequired;
    }
    return result;
   
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        int N;
        cin >> N;
        vector<int> length(N);
        for(int i_length=0; i_length<N; i_length++)
        {
        	cin >> length[i_length];
        }
        int Q;
        cin >> Q;
        vector<int> query(Q);
        for(int i_query=0; i_query<Q; i_query++)
        {
        	cin >> query[i_query];
        }

        vector<int> out_;
        out_ = solve(query, length);
        cout << out_[0];
        for(int i_out_=1; i_out_<out_.size(); i_out_++)
        {
        	cout << "\n" << out_[i_out_];
        }
        cout << "\n";
    }
}
