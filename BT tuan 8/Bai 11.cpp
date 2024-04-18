Bai 11
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

