#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> arr;
    arr.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int q; cin>>q;
    while(q>0)
    {
        int a; cin>>a;
        auto it=lower_bound(arr.begin(),arr.end(),a);
        if(it!=arr.end()&&*it==a)
        {
            cout<<"YES"<<" "<<it-arr.begin()+1<<endl;	
        }
        else{
            cout<<"NO"<<" "<<it-arr.begin()+1<<endl;
        }
        q--;
    }
}