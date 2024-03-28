#include<bits/stdc++.h>
using namespace std;
int kiemTra(int k,int n)
{
	if(k>=0&&k<=n&&n>=1&&n<=20)
	{
		return 1;
	}
	return 0;
}
int main(){
	int n,k;
	cin>>n>>k;
	int check=kiemTra(k,n);
	cout<<check;
}