#include<bits/stdc++.h>
using namespace std;
long long factorial(long long n){
	if(n<=1)
	{
		return 1;
	}
	else return n*factorial(n-1);
}
long long toHop(long long n,long long k)
{
	long long th=factorial(n)/(factorial(k)*factorial(n-k));
	return th;
}
int main(){
	int n,k;
	cin>>n>>k;
	long long tohop=toHop(n,k);
	cout<<tohop;
}