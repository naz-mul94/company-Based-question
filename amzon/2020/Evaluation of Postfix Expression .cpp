/*
It supports only 4 binary operators ‘+’, ‘*’, ‘-‘ and ‘/’. 
allowed operands are only single digit operands.
*/
#include<iostream>
#include<stack>
using namespace std;

int evaluatePost(string ex)
{
	stack<char> operand;
	int x, y;
	for (int i = 0; i < ex.size(); ++i)
	{
		if(ex[i]=='+'||ex[i]=='-'||ex[i]=='*'||ex[i]=='/')
		{
			switch(ex[i])
			{
				case '+': x= operand.top();
						  operand.pop();
						  y=operand.top();
						  operand.pop();
						  operand.push(x+y);break;
				case '-': x= operand.top();
						  operand.pop();
						  y=operand.top();
						  operand.pop();
						  operand.push(y-x);break;		
				case '*': x= operand.top();
						  operand.pop();
						  y=operand.top();
						  operand.pop();
						  operand.push(y*x);break;
				case '/': x= operand.top();
						  operand.pop();
						  y=operand.top();
						  operand.pop();
						  operand.push(y/x);break;	

			}
		}
		else operand.push(ex[i]-'0');
	}
	return operand.top();
}

int main()
 {
	int noInput;
	cin>>noInput;
	string input;
	for(int i=0;i<noInput;i++)
	{
		cin>>input;
		cout<<evaluatePost(input)<<endl;
	}
	return 0;
}
######################### alleviating the limitaion of single digit #####################################
#include<iostream>
#include<stack>
using namespace std;

int evaluatePost(string ex)
{
	stack<int> operand;
	int x, y;
	for (int i = 0; i < ex.size(); ++i)
	{//cout<<i<<endl;
		if(ex[i]=='+'||ex[i]=='-'||ex[i]=='*'||ex[i]=='/')
		{
			switch(ex[i])
			{
				case '+': x=operand.top();
						  operand.pop();
						  y=operand.top();
						  operand.pop();
						  operand.push(x+y);break;
				case '-': x= operand.top();
						  operand.pop();
						  y=operand.top();
						  operand.pop();//cout<<x<<" "<<y<<endl;cout<<y-x<<endl;
						  operand.push(y-x);break;		
				case '*': x= operand.top();
						  operand.pop();
						  y=operand.top();
						  operand.pop();//cout<<x<<" "<<y<<endl;cout<<x*y<<endl;
						  operand.push(y*x);break;
				case '/': x= operand.top();
						  operand.pop();
						  y=operand.top();
						  operand.pop();//cout<<x<<" "<<y<<endl;cout<<y/x<<endl;
						  operand.push(y/x);break;	

			}
		}
		else if(ex[i]==' ')continue;
		else if(ex[i]>='0'&&ex[i]<='9')
		{
			int num=0;
			while(ex[i]>='0'&&ex[i]<='9')
			{
				num=num*10+(ex[i]-'0');
				i++;
			}
			
			operand.push(num);//cout<<operand.top()<<endl;
			
		}
	}
	return operand.top();
}

int main()
 {
	string noInput;
	getline(cin, noInput);
	string input;
	for(int i=0;i<stoi(noInput);i++)
	{
		getline(cin, input);
		cout<<evaluatePost(input)<<endl;
	}
	return 0;
}
