#include <cmath>
#include<iostream>
using namespace std;

int round1(double num) {
    
    int ceilNum = ceil(num);
    int floorNum = floor(num);

    double diffCeil = fabs(num - ceilNum);
    double diffFloor = fabs(num - floorNum);
    return (diffCeil <= diffFloor) ? ceilNum : floorNum;
}	
int round2(double num) {
    
    int intPart = (int)num;
 
    double decimalPart = num - (double)intPart;

    if (decimalPart >= 0.5)
        return intPart + 1;
    else
        return intPart;
}
int main(){
	double x; cin>>x;
	int a1=round1(x);
	int a2=round2(x);
	cout<<a1<<" "<<a2;
}