#include<iostream>
using namespace std;

int main(){
	int n; cin>>n;
	int ktrang=n-1;
	int dausao=1;
	int q=n;
	while(q>0)
	{
		for(int i=1;i<=ktrang;i++)
		{
			cout<<" ";
		}
		for(int i=1;i<=dausao*2-1;i++)
		{
			cout<<"*";
		}
		ktrang--;
		dausao++;
		cout<<endl;
		q--;
	}	
}