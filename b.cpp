#include <bits/stdc++.h>
#define int long long
using namespace std;

int sumPairs(int arr[], int n) {
    sort(arr, arr + n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += i * arr[i] - (n - 1 - i) * arr[i];
    }
    return sum;
}

int32_t main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << sumPairs(arr, n);
    return 0;
}