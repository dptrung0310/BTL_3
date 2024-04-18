#include <bits/stdc++.h>

using namespace std;
void printArraySize(int* arr, int size) {
    cout << "Kich thuoc cua mang trong ham: " << sizeof(arr) << " bytes" << endl;
    cout << "So phan tu cua mang trong ham: " << size << endl;
}
template <size_t N>
void f(int (&arr)[N]) {
    cout << "Kich thuoc cua mang trong ham f: " << sizeof(arr) << " bytes" << endl;
    cout << "So phan tu cua mang trong ham f: " << N << endl;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    cout << "Kich thuoc cua mang tu ben ngoai ham: " << sizeof(A) << " bytes" << endl;
    cout << "So phan tu cua mang tu ben ngoai ham: " << sizeof(A) / sizeof(A[0]) << endl;  
    f(A);
    printArraySize(A, sizeof(A) / sizeof(A[0]));
    return 0;
}