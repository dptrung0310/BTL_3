Bai 10
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
}