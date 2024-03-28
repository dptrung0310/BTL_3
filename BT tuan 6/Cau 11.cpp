#include<bits/stdc++.h>
using namespace std;

string dectoBin(long long n)
{
	vector<char> vec;
	if(n<0)
	{
		n=abs(n);
	}
	while(n>0)
	{
	char c=char (n%2)+'0';
	vec.push_back(c);
	n/=2;
	}
	string s="";
	int k=vec.size();
	for(int i=k-1;i>=0;i--)
	{
		s+=vec[i];
	}
	return s;
}
long long Bintodec(long long n){
	long long sum=0;
	int k=0;
	while(n>0)
	{
		long long h=n%10;
		sum+=h*pow(2,k);
		k++;
		n/=10;
	}
	return sum;
}
int main(){
	long long n; cin>>n;
	string s=dectoBin(n);
	cout<<s;
	long long bin;
	cin>>bin;
	long long btd=Bintodec(bin);
	cout<<btd;
	
}