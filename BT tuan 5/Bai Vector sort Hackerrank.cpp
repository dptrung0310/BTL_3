#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin>>n;
    vector<int> arr;
    int dem=n;
    while(dem>0)
    {
        int a; cin>>a;
        arr.push_back(a);
        dem--;
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}