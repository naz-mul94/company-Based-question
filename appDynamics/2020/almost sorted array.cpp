/**Almost sorted array*/---------------IIT KGP

int Solution::lis(const vector<int> &A) 
{
   vector<int> ans;
   int len=-1;
   if(A.size()==0)return 0;
   if(A.size()==1)return 1;
   ans.push_back(A[0]);
   len++;
   for(int i=1;i<A.size();i++)
   {
       if(A[i]<ans[0])ans[0]=A[i];
       else if(ans[len]<A[i])
       {
           ans.push_back(A[i]);
           len++;
       }
       else
       {
           auto x=lower_bound(ans.begin(), ans.end(), A[i]);
           ans[x-ans.begin()]=A[i];
       }
   }
   len++;
   if(len==0||len==1)return 0;
   return len-1;
}
