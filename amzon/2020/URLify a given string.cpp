#include<iostream>
#include<vector>
using namespace std;
string urlfy(string str)
{
	int space=0, trail=0;
	int len=str.size();
	for (int i = 0; i < str.size(); ++i)
	{
		if(str[i]==' ')
			space++;
	}
	for (int i = str.size()-1; i >= 0; --i)
	{
		if(str[i]!=' ')
		break;
		trail++;
	}
	str.resize(len-trail);
	len=str.size();
	str.resize(str.size()+space*3);
	for(int i=str.size()-1, j=len-1;i>=0;i--)
	{
		if(str[j]==' ')
		{
			str[i]='0';
			i--;
			str[i]='2';
			i--;
			str[i]='%';
			j--;
		}
		else
		{
			str[i]=str[j];
			j--;
		}
		
	}
	return str;
}

int main()
 {
	int noInput;
	cin>>noInput;
	cin.ignore();
	int len;
	string str;
	for (int i = 0; i < noInput; ++i)
	{
		getline(cin, str);
		cin>>len;
		cin.ignore();
		cout<<urlfy(str)<<endl;

	}
}
