#include <iostream>
#include <string>

using namespace std;
string concat(const char* str1, const char* str2) {
    string result(str1); //Khoi tao result voi str1
    result += str2; // Noi str2 vao result
    return result; // Tra ve result
}
// ham tra ve result 
char* concat(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char* result = new char[len1 + len2 + 1]; // Cap phat bo nho du cho ca hai xau va ky ty ket thuc null
    strcpy(result, str1); // Sao chep str1 vao result
    strcat(result, str2); // Noi str2 vao result
    return result; // Tra ve con tro toi mang result
}
// ham tra ve con tro toi mang result



