#include <bits/stdc++.h>
using namespace std;

//Phan A
//Bai 1
/*int arr1[4];
int arr3[6]={1,2,3,4};
int arr5[]={1,2,3,4};
int main()
{
    int arr2[4];
    //int arr4[3]={1,2,3,4};
    int arr6[]={1,2,3,4};
    for(auto &i:arr1)
    {
        cout<<i;
    }
    cout<<endl;
    for(auto &i:arr2)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto &i:arr3)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    //for(auto &i:arr4)
    //{
    //  cout<<i<<" ";
    //}
    for(auto &i:arr5)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto &i:arr6)
    {
        cout<<i<<" ";
    }
    return 0;
}*/
//Bai 2
/*char arr1[4];
char arr6[6]={'a','b','c','d','\0'};
char arr8[]={'a','b','c','d','\0'};
char arr4[6]={"abcd"};
char arr10[]={"abcd"};
// bi loi : char arr3[3]={"abcd"};
int main()
{
    char arr2[4];
    for(auto &i:arr1)
    {
        cout<<i<<" "; // Ket qua la khong co ki tu
    }
    cout<<endl;
    for(auto &i:arr2)
    {

        cout<<i<<" ";// Ket qua la khong co ki tu
    }
    cout<<endl;
    char arr3[6]={"abcd"};
    cout<<arr3<<endl;// in ra abcd
    cout<<arr4<<endl;// in ra abcd

    char arr5[6]={'a','b','c','d','\0'};
    cout<<arr5<<endl;// in ra abcd
    cout<<arr6<<endl;// in ra abcd

    char arr7[]={'a','b','c','d'};
    cout<<arr7<<endl;// in ra abcd
    cout<<arr8<<endl;// in ra abcd

    char arr9[]={"abcd"};
    cout<<arr9<<endl;
    cout<<arr10<<endl;

    cout<<sizeof(arr9)<<" "<<sizeof(arr10);// ra 5 5 chung to con 1 ki tu \0 nua o cac mang arr9 va arr10


}*/
//Bai 3
/*int main(){
    //cau a
    char daytab1[2][12] = {{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
    char daytab2[2][12] = {31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
    // hien thi ra cac ki tu trong bang ma asccii
    // cau b
    // Cách khai báo đúng là
    char daytab3[2][12] = {{'1','2','3','4','5','6','7','8','9'},{'1','2','3','4','5','6','7','8','9'}};
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<12;j++)
		{
			cout<<daytab3[i][j]<<" "; // ham se in ra tu 1 den 9 thoi
		}
		cout<<endl;
	}
	char daytab4[2][12] = {'1','2','3','4','5','6','7','8','9','1','2','3','4','5','6','7','8','9','a','a','a','a','a','a','a','a','a','a','a'};

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<12;j++)
		{
			cout<<daytab4[i][j]<<" ";// Loi co qua nhieu phan tu, cu the la co lon hon 24 phan tu
		}
		cout<<endl;
	}
	//cau c
	char daytab5[2][12] = {{'1','2','3','4','5','6','7','8','9'},{'1','2','3','4','5','6','7','8','9'}};
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<12;j++)
		{
			cout<<daytab5[i][j]<<" ";
		}
		cout<<endl;
	}
	// neu khai bao daytab5[][12] thi ham se chay binh thuong con cac truong hop khac thi xay ra loi
	char daytab6[2][12] = {'1','2','3','4','5','6','7','8','9','1','2','3','4','5','6','7','8','9'};

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<12;j++)
		{
			cout<<daytab6[i][j]<<" ";// neu khai bao daytab6[][12] thi ham se chay binh thuong con cac truong hop khac thi xay ra loi
		}
		cout<<endl;
	}
}*/
//Bai 4
/*int main(){
    //cau a
    char arr[5]={"abcd"};
    cout<<arr[-1]<<" "<<arr[0]<<" "<<arr[3]<<" "<<arr[4]<<" "<<arr[5]<<" "<<arr[6];
    // tai cac phan tu -1,5 deu cho khoang trang con tai 6 thi no ra 1 ki tu nao do bat ky, khong bi loi.

    //cau b
    char arr1[5]={"abcd"};
    arr1[-1]='a';
    arr1[5]='k';
    arr1[6]='k';
    cout<<arr1[-1]<<" "<<arr1[0]<<" "<<arr1[1]<<" "<<arr1[2]<<" "<<arr1[3]<<" "<<arr1[4]<<" "<<arr1[5]<<" "<<arr1[6];
    // ket qua la van chay binh thuong cac gia tri tran mang duoc gan va van in ra binh thuong

    //cau c
    char arr3[3][4]={{'1','2','3','4'},{'5','6','7','8'},{'9','a','b','c'}};
    cout<<arr3[0][4]<<" "<<arr3[0][0]<<" "<<arr3[0][3];
    // khi ghi tran dong thi no tu dong nhay xuong dong tiep theo
    //nghia la khi in arr3[0][4] la tràn 1 đơn vị nên giá trị arr3[0][4] sẽ là 5
    //vay nếu ta in ra arr3[0][11] thi kết quả sẽ là c, còn arr[0][12 trở đi] sẽ không in ra giá trị gì cả
}*/

//Cau 5
/*int main(){
    char str[5];
    cin>>str;
    cout<<" "<<str<<" ";// no van in ra du cac ki tu dù cho có nhập tràn mảng
    char str2[5];
    cin>>str2;
    cout<<" "<<str2<<" ";// nó vẫn in ra đủ các kí tự dù cho có nhập ít hơn kích thước mảng
}*/

//Cau 6
/*int main(){
 	int arr[30];
 	srand(time(NULL));
	for(int i=0;i<30;i++)
	{
		arr[i]=	rand()%100+1;
	}
	for(int &i:arr)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	for (int i = 0; i < 30 - 1; ++i) {
        for (int j = 0; j < 30 - i - 1; ++j) {
            if (arr[j] >= arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
	for(int &i:arr)
	{
		cout<<i<<" ";
	}
}*/
//Phan C
//Bai 2 Xau tuong duong

/*bool doixung(string s,int n)
{
	int k=n-1;
	for(int i=0;i<=n/2;i++)
	{
		if(s[i]!=s[k])
		{
			 return false;
		}
		k--;
	}
	return true;
}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    if(doixung(s,n))
    {
    	cout<<"Yes";
    }
    else cout<<"No";
}*/

//Bai 3 So doi guong
/*int reverse(int n)
{
    int h=0;
    for(int i=n;i>0;i/=10)
    {
        h=h*10+i%10;
    }
    return h;
}
int main(){
    int T; cin>>T;
    while(T>0)
    {
        int a,b;
        cin>>a>>b;
        int dem=0;
        while(a<=b)
        {
            int h=reverse(a);
            if(h==a)
            {
                dem++;
            }
            a++;
        }
        cout<<dem<<endl;
        T--;
    }
}*/

//Bai 4 Do min
bool isValid(int i, int j, int m, int n) {
    return i >= 0 && i < m && j >= 0 && j < n;
}

void print(vector<vector<char>>& mineField) {
    int m = mineField.size();
    int n = mineField[0].size();

    vector<vector<int>> result(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mineField[i][j] == '*') {
                result[i][j] = -1;
            } else {
                int count = 0;
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        if (di == 0 && dj == 0) continue;
                        int ni = i + di;
                        int nj = j + dj;
                        if (isValid(ni, nj, m, n) && mineField[ni][nj] == '*') {
                            count++;
                        }
                    }
                }
                result[i][j] = count;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (result[i][j] == -1) {
                cout << "* ";
            } else {
                cout << result[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    if (m > 0 && n > 0 && m < 10 && n < 10) {
        vector<vector<char>> mineField(m, vector<char>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> mineField[i][j];
            }
        }

        print(mineField);
    }

    return 0;
}





