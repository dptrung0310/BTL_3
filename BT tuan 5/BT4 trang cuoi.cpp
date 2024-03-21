#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	int passcal[n][n]={0};
	
	passcal[0][0]=1;
	passcal[1][0]=1;
	passcal[1][1]=1;
	
	int socot=2;
	for(int i=2;i<n;i++)
	{
		for(int j=0;j<=socot;j++)
		{
			if(socot>=n)
			{
				break;
			}
			else{
			if(j==0){
				passcal[i][j]=1;
			}
			else{
				passcal[i][j]=passcal[i-1][j-1]+passcal[i-1][j];
			}
			}
		}
		socot++;
	}
	/* Cach khac de hon
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0||j==i){
				passcal[i][j]=1;
				continue;
			}	
			passcal[i][j]=passcal[i-1][j-1]+passcal[i-1][j];
		}
	}*/
		
	int socot2=0;
	for(int i=0;i<n;i++)
	{
		if(socot2<n)
		{
			for(int j=0;j<=socot2;j++)
			{
				cout<<passcal[i][j]<<" ";
			}
		}
		cout<<endl;
		socot2++;
	}
	
}