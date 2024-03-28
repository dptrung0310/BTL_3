#include<iostream>
using namespace std;

int ucln(int a, int b)
{
	if(b==0)
	{
		return a;
	}
	else{
		return ucln(b,a%b);
	}
}
int main(){
	int a,b; cin>>a>>b;
	int x=ucln(a,b);
	cout<<x;
}