#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n, f = 1;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i > 0) {
            if (arr[i] == arr[i - 1]) {
                f++;
            }
        }
    }
    sort(arr, arr + n);
    if (f == n)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        int y = 0, x = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (i % 2 == 0) {
                cout << arr[x] << " ";
                x--;
            }
            else {
                cout << arr[y] << " ";
                y++;
            }
        }
        cout << endl;
    }
}
int32_t main() {
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}