#include <iostream>
#include <string>

using namespace std;
string concat(const char* str1, const char* str2) {
    string result(str1); // Khởi tạo result với str1
    result += str2; // Nối str2 vào result
    return result; // Trả về result
}
// ham tra ve result 
char* concat(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char* result = new char[len1 + len2 + 1]; // Cấp phát bộ nhớ đủ cho cả hai xâu và ký tự kết thúc null
    strcpy(result, str1); // Sao chép str1 vào result
    strcat(result, str2); // Nối str2 vào result
    return result; // Trả về con trỏ tới mảng result
}
// ham tra ve con tro toi mang result



