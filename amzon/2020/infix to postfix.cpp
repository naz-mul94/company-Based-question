//https://practice.geeksforgeeks.org/problems/infix-to-postfix/0
#include<iostream>
using namespace std;
#include<stack>
int prec(char oper)
{
    if(oper=='^')
    return 3;
    else if(oper=='*'||oper=='/')
    return 2;
    else if(oper=='+'||oper=='-')
    return 1;
    else return -1;
}
string conversion(string ex)
{stack<char> inToPo;
    string temp="";
    for(int i=0;i<ex.size();i++)
    {
        if((ex[i]>='a'&&ex[i]<='z')||(ex[i])>='A'&&ex[i]<='Z')
        temp+=ex[i];
        else if(ex[i]=='(')
        inToPo.push(ex[i]);
        else if(ex[i]==')')
        {
            while(!inToPo.empty()&&inToPo.top()!='(')
            {
                temp+=inToPo.top();
                inToPo.pop();
            }
            if(inToPo.top()=='(')
            inToPo.pop();
        }
        else
        {
            if(inToPo.empty()||prec(ex[i])>prec(inToPo.top()))
            inToPo.push(ex[i]);
            else
            {
                while(!inToPo.empty()&&prec(ex[i])<=prec(inToPo.top()))
                {
                    temp+=inToPo.top();
                    inToPo.pop();
                }
                inToPo.push(ex[i]);
            }
        }
        //cout<<temp<<endl;
    }
    while(!inToPo.empty())
    {
    	temp+=inToPo.top();
        inToPo.pop();
    }
    return temp;
}

int main()
 {
	int noInput;
	cin>>noInput;
	string input;
	for(int i=0;i<noInput;i++)
	{
	    cin>>input;
	    cout<<conversion(input)<<endl;
	}
	return 0;
}
