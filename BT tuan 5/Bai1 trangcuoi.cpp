#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> dayso;
	int n;
	int dem=0;
	double sum=0;
	do{
		cin>>n;
		if(n==0)
		{
			break;
		}
		sum+=n;
		dayso.push_back(n);
		dem++;
	}while(true);
	double tb=sum/dem;
	double psai=0;
	for(int i=0;i<dem;i++)
	{
		psai+=(pow(dayso[i]-tb,2)/(dem));
	}
	cout<<setprecision(2)<<fixed<<tb<<" "<<psai;
}