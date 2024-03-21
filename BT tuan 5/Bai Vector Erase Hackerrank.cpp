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
    int k; cin>>k;
    arr.erase(arr.begin()+k);
    int a,b; cin>>a>>b;
    arr.erase(arr.begin()+a-1,arr.begin()+b-1);
    cout<<arr.size()<<endl;
    for (auto& element : arr) {
        cout << element << " ";
    }
    return 0;
}
