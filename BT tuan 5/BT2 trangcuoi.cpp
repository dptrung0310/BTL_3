#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> dayso;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		dayso.push_back(a);
	}
	sort(dayso.begin(),dayso.end());
	cout<<dayso[0]<<" "<<dayso[n-1];
	cout<<endl;
	int demle=0;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(dayso[i]%2==0)
		{
			sum+=dayso[i];	
		}	
		else if(dayso[i]%2!=0)
		{
			demle++;
		}
	}
	cout<<sum<<" "<<demle;	
}