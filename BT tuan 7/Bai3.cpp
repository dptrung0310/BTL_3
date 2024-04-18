#include <iostream>

using namespace std;
int count_even(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int count_first = count_even(arr, 5);
    cout << "So so chan trong 5 ptu dau mang: " << count_first << endl;
    int count_last = count_even(arr + 5, 5);
    cout << "So so chan trong 5 ptu cuoi mang: " << count_last << endl;

    return 0;
}