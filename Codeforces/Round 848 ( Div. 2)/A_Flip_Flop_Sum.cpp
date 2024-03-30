#include <bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve() {
    int n, total_ans = 0, cnt_one = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 1)
            cnt_one++;
    }
    if (cnt_one == n) {
        for (int i = 0; i < n; i++)
            total_ans += arr[i];
        total_ans += -4;
        cout << total_ans << endl;
        return;
    }
    int cnt = 1;
    int mx = -9;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == -1 and arr[i + 1] == -1)
            cnt++;
        else {
            if (cnt > mx)
                mx = cnt;
            cnt = 1;
        }
    }
    if (cnt > mx)
        mx = cnt;
    if (mx >= 2) {
        for (int i = 0; i < n; i++)
            total_ans += arr[i];
        total_ans += 4;
        cout << total_ans << endl;
    }
    else if (mx == 1) {
        for (int i = 0; i < n; i++)
            total_ans += arr[i];
        cout << total_ans << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}