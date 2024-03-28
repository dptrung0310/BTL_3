#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n; cin>>n;
	int x;
	srand(time(NULL));
	x = rand() % n-1 + 1;
	cout<<x;
}