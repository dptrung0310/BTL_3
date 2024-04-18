Bai 8,9
using namespace std;
struct Point{
    int x,y;
};
void passByValue(Point p) {
    cout << &p << endl;
    p.x = 10;
    p.y = 20;
}

void passByReference(Point &p) {
    cout << &p << endl;
    p.x = 30;
    p.y = 40;
}
int main(){
    Point p;
    p.x=1;
    p.y=1;
    cout<<&(p.x)<<" "<<&(p.y)<<endl;
    passByValue(p);
    cout<<p.x<<" "<<p.y<<" "<<&(p.x)<<" "<<&(p.y)<<endl;//in ra 1 1 chung to ham da tac dong len 1 ban sao nao do chu khong phai p.x va p.y goc
    passByReference(p);// in ra dung dia chi cua p before
    cout<<p.x<<" "<<p.y<<" "<<&(p.x)<<" "<<&(p.y)<<endl;//In ra 30 40 va dia chi cua p.x va p.y goc

    return 0;

}