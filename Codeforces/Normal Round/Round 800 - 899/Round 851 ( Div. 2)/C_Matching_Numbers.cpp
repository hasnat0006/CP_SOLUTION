#include <bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve() {
    int n;
    cin >> n;
    int check = (n * (2 * n + 1) - ((n * (n - 1)) / 2));
    if (check % n != 0) {
        cout << "NO" << endl;
        return;
    }
    vector<pair<int, int>> v(2 * n);
    int highest = check + n;
    v[0].first = 1;
    v[0].second = 2 * n;
    for (int i = 2; i < n; i += 2) {
        v[i].first = i + 1;
        v[i].second = (v[i - 2].second) - 1;
    }
    v[1].first = 2;
    int x = v[n - 1].second - 1;
    v[1].second = x;
    for (int i = 3; i < n; i += 2) {
        x--;
        v[i].first = v[i - 2].first + 2;
        v[i].second = x;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
        cout << v[i].first << " " << v[i].second << endl;
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