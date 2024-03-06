#include <bits/stdc++.h>

//Phan 1
/*
Bai 1,2,3
using namespace std;
struct Point{
    int x,y;
};

void changebyvalue(Point p)
{
    p.x=20;
    p.y=30;
}
void changebyReference(Point &p){
    p.x=40;
    p.y=50;
}
const Point trungdiem(Point p1, Point p2)
{
    Point td;
    td.x=0;
    td.y=0;
    td.x=(p1.x+p2.x)/2;
    td.y=(p1.y+p2.y)/2;
    return td;
}
int main()
{
    Point point;
    point.x=10;
    point.y=12;
    changebyvalue(point);
    cout<<point.x<<" "<<point.y<<endl;
    changebyReference(point);
    cout<<point.x<<" "<<point.y<<endl;
    Point p1={2,4};
    Point p2={4,6};
    Point td=trungdiem(p1,p2);
    cout<<td.x<<" "<<td.y;
    return 0;
}*/
//Phan 2
/*
Bai 5, 6, 7
using namespace std;
struct Point{
    int a,b;
};
struct Rect{
    int x,y,w,h;
     bool const contains(Point p){
        if(p.a<x||p.a>(x+w)){
            return false;
        }
        else if(p.b<y||p.b>(y+h))
        {
           return false;
        }
        return true;
    }
};
struct Ship{
    Rect myship;
    string id;
    int dx,dy;
    void move(){
        myship.x+=dx;
        myship.y+=dy;
    }
};
void display(const Ship &ship)
{
    cout<<ship.myship.x<<" "<<ship.myship.y<<endl;
    cout<<ship.id;
}
int main(){
    int x,y,w,h;
    cin>>x>>y>>w>>h;
    int a,b;
    cin>>a>>b;
    Point diem;
    diem.a=a;
    diem.b=b;
    Rect hinhchunhat;
    hinhchunhat.x=x;
    hinhchunhat.y=y;
    hinhchunhat.w=w;
    hinhchunhat.h=h;
    bool check=hinhchunhat.contains(diem);
    cout<<check<<endl;
    if(check)
    {
        cout<<"Yes"<<endl;
    }
    else cout<<"NO"<<endl;

    Ship contau;
    contau.myship.x=x;
    contau.myship.y=y;
    contau.id="Trung";
    contau.dx=5;
    contau.dy=5;
    display(contau);
    cout<<endl;
    contau.move();
    display(contau);
    return 0;
}*/
//Phan 3
/*
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

}*/
/*Bai 10
using namespace std;

struct Point{
    int x,y;
};
struct Rectangle{
    Point* point;
} ;
int main(){
    Rectangle rect1;
    rect1.point=new Point[2];
    rect1.point[0].x=0;
    rect1.point[0].y=0;
    rect1.point[1].x=20;
    rect1.point[1].y=20;
    Rectangle rect2=rect1;
    rect2.point[0].x=5;
    rect2.point[0].y=5;
    cout<<rect1.point[0].x<<" "<<rect1.point[0].y;
    delete[] rect1.point;
    delete[] rect2.point;
    return 0;
}*/
//Bai 11
using namespace std;
struct String {
    int n;   // do dai xau
    char* str;    // Con trỏ đến mảng char

    // Constructor nhận một xâu kí tự và khởi tạo String từ đó
    String(const char* s) {
        n = strlen(s);         // Tính độ dài của xâu
        str = new char[n + 1]; // Cấp phát bộ nhớ động cho mảng char
        strcpy(str, s);             // Sao chép nội dung của xâu vào str
    }

    // Destructor để giải phóng bộ nhớ động khi đối tượng bị hủy
    ~String() {
        delete[] str;
    }
    void print(){
        cout<<str<<endl;
    }
    void append(const char* s){
        int newlength=n+strlen(s);
        char* temp=new char[newlength+1];
        strcpy(temp,str);
        strcat(temp,s);
        delete[] temp;
        str=temp;
        n=newlength;


    }
};
int main(){
    String s("Chao moi nguoi");
    s.print();
    s.append("toi la trung day");
    s.print();
    return 0;
}

























