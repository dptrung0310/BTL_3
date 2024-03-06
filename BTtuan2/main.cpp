#include <iostream>
#include<cmath>
using namespace std;

//Bai1
/*int main()
{
    int x,dem=0;
    cin>>x;
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            cout<<"no";
            dem++;
            break;
        }
    }
    if(dem==0) cout<<"yes";
    return 0;
}*/

//Bai2
/*int main()
{
    int n;
    cin>>n;
    for(int i=n;i>=1;i--)
    {
        for(int j=i;j>=1;j--)
        {
            cout<<"*";
        }
        cout<<endl;
        for(int k=n-i;k>=0;k--)
        {
            cout<<" ";
        }
    }
}*/

//Bai3
/*int main()
{
    int n;
    cin>>n;
    for(int i=n;i>=1;i--)
    {
        int dem=0;
        for(int j=i-1;j>=1;j--)
        {
            cout<<" ";
            dem++;
        }
        for(int k=1;k<=2*(n-dem)-1;k++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}*/

//Bai4
/*int main()
{
    int n,dem=0;
    cin>>n;
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=dem;j++)
        {
            cout<<" ";
        }
        for(int k=1;k<=2*(n-dem)-1;k++)
        {
            cout<<"*";
        }
        dem++;

        cout<<endl;
    }
}*/

//Bai5
/*int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            cout<<j<<" ";
        }
        for(int k=1;k<=i-1;k++)
        {
            cout<<k<<" ";
        }
        cout<<endl;
    }
}*/
//Bai6
/*int main() {
    int num;
    int prevNum = -1;
    bool firstNegativeFound = false;

    while (std::cin >> num) {

        if (num < 0) {
            firstNegativeFound = true;
            break;
        }
        if (num != prevNum) {

            std::cout << num << " ";
            prevNum = num;
        }
    }

    if (!firstNegativeFound) {
        cout << "Không có số âm đầu tiên!" <<endl;
    }

    return 0;
}*/

//Bai7
int arr[10001][10001]={};
int main()
{
    int n; cin>>n;
    while(n>0)
    {
        int a,b;
        cin>>a>>b;
        if(a>=10001||b>=10001)
        {
            continue;
        }
        else{
            for(int i=0;i<a;i++)
            {
                for(int j=0;j<b;j++)
                {
                    arr[i][j]++;
                }
            }
        }
        n--;
    }
    cout<<arr[0][0]<<" "<<arr[1][0]<<endl;
    int dem=0;
    for(int i=0;i<10001;i++)
    {
        for(int j=0;j<10001;j++)
        {
            if(arr[j][i]==arr[0][0])
                {
                    dem++;
                }
        }
    }
    cout<<dem;
}
