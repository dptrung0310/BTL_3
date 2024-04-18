#include <bits/stdc++.h>
using namespace std;

bool b_s(int *a, int l, int r, int x) {
    if (l <= r) {
        int mid = (l + r)/2;
        if (a[mid] == x) return true;
        else {
            if (a[mid] > x) return b_s(a, l, mid - 1, x);
            else return b_s(a, mid + 1, r, x);
        }
    }
    return false;
}
int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key; cin >> key;
    if (b_s(arr, 0, n - 1, key)) cout << "key co trong day!";
    else cout << "key khong co trong day!";
    return 0;
}