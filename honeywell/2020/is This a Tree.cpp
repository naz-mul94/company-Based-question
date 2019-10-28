#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
using namespace std;

string makeString(char root, unordered_map<char, vector<char>> parToChild)
{
    string ans="", left="", right="";
    ans+=string(1, root);
    if(parToChild.find(root)==parToChild.end())
        return "("+ans+")";
    if(parToChild[root].size()>0)
    left=makeString(parToChild[root][0], parToChild);
    if(parToChild[root].size()>1)
    right=makeString(parToChild[root][1], parToChild);
    return "("+ans+left+right+")";
}

string formTree(vector<vector<char>> tree, unordered_set<char>s)
{
    int n=tree.size();
    set<int> error;
    string ans;
    unordered_map<char, char>par;
    unordered_map<char, vector<char>> parToChild;
    for(int i=0;i<n;i++)
    {//cout<<tree[i][0]<<" "<<tree[i][1]<<endl;
        if(parToChild.find(tree[i][0])==parToChild.end())
        {
            parToChild[tree[i][0]].push_back(tree[i][1]);
            if(par.find(tree[i][1])!=par.end())
                error.insert(3);
            else
                par[tree[i][1]]=tree[i][0];
        }
        else if( parToChild[tree[i][0]].size()==1)
        {
            if(parToChild[tree[i][0]][0] <= tree[i][1])
            {
                parToChild[tree[i][0]].push_back(tree[i][1]);
            }
            else
            {
                parToChild[tree[i][0]].push_back(parToChild[tree[i][0]][0]);
                parToChild[tree[i][0]][0]=tree[i][1];
            }
            if(par.find(tree[i][1])!=par.end())
            error.insert(3);
            else
            par[tree[i][1]]=tree[i][0];
        }
        else
        {
            //cout<<(char)tree[i][0]<<" "<<(char)tree[i][1]<<endl;
            if(tree[i][1]==parToChild[tree[i][0]][0] || tree[i][1]==parToChild[tree[i][0]][1])
                error.insert(2);
            else error.insert(1);

            if(par.find(tree[i][1])!=par.end())
            error.insert(3);
            else
            par[tree[i][1]]=tree[i][0];
        }
        s.erase(tree[i][1]);
    }

    if(s.size()==1)
    {
        if(error.empty())
        ans=makeString(*(s.begin()), parToChild);
    }
    else
    {
        error.insert(4);
    }
    if(!error.empty())
        return "E"+to_string(*(error.begin()));     
    return ans;
}

int main()
{
    int noInput;
    cin>>noInput;
    vector<vector<char>> tree(noInput, vector<char>(2));
    unordered_set<char> s;
    for(int i=0;i<noInput;i++)
    {
        cin>>tree[i][0]>>tree[i][1];
        s.insert(tree[i][0]);
        s.insert(tree[i][1]);
    }
    cout<<formTree(tree, s)<<endl;    
}
#######################################################################################################
string printString(int root, unordered_map<char, vector<int>> parToChild)
{
    string ans=string(1,root),c1="", c2="";
    if(parToChild.find(root)==parToChild.end())
        return "("+ans+")";
    if(parToChild[root].size()>0)
    {
        c1=printString(parToChild[root][0], parToChild);
    }

    if(parToChild[root].size()>1)
    {
        c2=printString(parToChild[root][1], parToChild);
    }
    return "("+ans+c1+c2+")";
}

string preOrder(vector<vector<char>> pre, unordered_set<char> nodes, int n)
{
    string ans=""; 
    set<int> error;
    unordered_map<char, vector<int>> parToChild;
    unordered_map<char, char> par;
    for(int i=0;i<n;i++)
    {
        if(parToChild.find(pre[i][0])==parToChild.end())
        {
            parToChild[pre[i][0]].push_back(pre[i][1]);
            if(par.find(pre[i][1]) == par.end())
                par[pre[i][1]]=pre[i][0];
            else
            {
                error.insert(3);
            }
        }
        else if(parToChild[pre[i][0]].size()==1)
        {
            if(pre[i][1]==parToChild[pre[i][0]][0])
            {
                //printf("pre[%d][1]=%c , %c\n",i,  pre[i][1], parToChild[pre[i][0]][0]);
                error.insert(2);
                continue;
            }
            if(parToChild[pre[i][0]][0]<pre[i][1])
            {
                parToChild[pre[i][0]].push_back(pre[i][1]);
            }
            else
            {
                parToChild[pre[i][0]].push_back(parToChild[pre[i][0]][0]);
                parToChild[pre[i][0]][0]=pre[i][1];
            }

            if(par.find(pre[i][1]) == par.end())
                par[pre[i][1]]=pre[i][0];
            else
            {
                error.insert(3);
            }


        }
        else
        {
            if(pre[i][1]==parToChild[pre[i][0]][0] || pre[i][1]==parToChild[pre[i][0]][1])
                error.insert(2);
            else
                error.insert(1);

            if(par.find(pre[i][1]) == par.end())
                par[pre[i][1]]=pre[i][0];
            else
            {
                error.insert(3);
            }
        }

        nodes.erase(pre[i][1]);
    }

    if(nodes.size()==1)
    {
        if(error.empty())
            return ans=printString(*(nodes.begin()), parToChild);
    }
    return "E"+to_string(*(error.begin()));
}
