#include<iostream>
#include<vector>
#include<string>
#include <map> 
#include <stack> 
#include <cstring> 
using namespace std; 

class point
{public:
	int x;
	int y;

	point(int a, int b):x(a), y(b){}
};
int gcd(int a, int b)
{
	if(b==0)return a;
	return gcd(b, a%b);
}
int pointLine( point p1, point p2)
{
	if(p1.x==p2.x)
		return abs(p1.y-p2.y)-1;
	else if(p1.y==p2.y)
		return abs(p1.x-p2.x)-1;
	return gcd(abs(p1.x-p2.x), abs(p1.y-p2.y))-1;
}

int integralPoint(point p1, point p2, point p3)
{
	int doubleArea;
	int pointBoundary;
	doubleArea=abs(p1.x*(p2.y-p3.y)+p2.x*(p3.y-p1.y)+p3.x*(p1.y-p2.y));
	pointBoundary=pointLine(p1, p2)+pointLine(p2, p3)+pointLine(p3, p1)+3;
	return (doubleArea - pointBoundary +2)/2;
}

int main()
{
	int noInput;
	cin>>noInput;
	while(noInput--)
	{
		
		int x, y;
		cin>>x>>y;
		point p1(x, y);
		cin>>x>>y;
		point p2(x, y);
		cin>>x>>y;
		point p3(x, y);
		cout<<integralPoint(p1, p2, p3)<<endl;	
	}
}
