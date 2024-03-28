#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin>>n;
	int a[n];
	int k=0;
	srand(time(NULL));
	while(n>0)
	{
		int x;
		x = rand() % 49 + 0;
		a[k]=x;
		k++;
		n--;
	}
	for(int i=0;i<k;i++)
	{
		cout<<a[i]<<" "<<endl;
	}
	for(int i=0;i<k;i++)
	{
		for(int j=i+1;j<k;j++)
		{
			for(int m=j+1;m<k;m++)
			{
				int h=a[i]+a[j]+a[m];
				if(h%3==0)
				{
					cout<<a[i]<<" "<<a[j]<<" "<<a[m]<<endl;
				}
			}
		}
	}
}
