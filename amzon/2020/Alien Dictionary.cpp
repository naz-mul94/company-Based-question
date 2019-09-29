#include<iostream>
#include<vector>
#include<string>
#include <map> 
#include <stack> 
#include <cstring> 
using namespace std; 

class graph
{
	int verticex;
	map<int, vector<int>> adj;
	void topologicalsorttill(int i, map<int, int> &visited, stack<int> &st);
	public:
		graph(int v)
		{
			verticex=v;
		}
		void addEdge(int u, int v);
		void topologicalsort();

};

void graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}

void graph::topologicalsorttill(int i, map<int, int> &visited, stack<int> &st)
{
	visited[i]=1;
	vector<int>::iterator j;
	for(j=adj[i].begin();j!=adj[i].end();j++)
		if(!visited[(*j)])
			topologicalsorttill(*j, visited, st);	
	st.push(i);	
}

void graph::topologicalsort()
{
	stack<int> st;
	map<int, int> visited;
	for(map<int, vector<int>>::iterator i=adj.begin();i!=adj.end();i++)
		visited[i->first]=0;

	for(map<int, vector<int>>::iterator i=adj.begin();i!=adj.end();i++)
		if(!visited[i->first])
			topologicalsorttill(i->first, visited, st);
	string temp="";	
	while(!st.empty())
	{
		temp+=char(st.top());
		st.pop();
	}	
	cout<<temp<<endl;
}

void printOrder(vector<string> words, int noChar)
{
	graph g(noChar);
	for (int i = 0; i < words.size()-1; ++i)
	{
		string word1=words[i], word2=words[i+1];
		for(int j=0;j<min(word1.size(), word2.size());j++)
		{
			if(word1[j]!=word2[j])
			{
				g.addEdge(word1[j], word2[j]);break;
			}
		}
	}
	g.topologicalsort();
}
  
int main()
{
	int noInput;
	cin>>noInput;
	for(int i=0;i<noInput;i++)
	{
		int n, k, vertexNo=1;
		cin>>n>>k;
		vector<string> words(n);
		for (int i = 0; i < n; ++i)cin>>words[i];
		printOrder(words, k);	
	}
}
