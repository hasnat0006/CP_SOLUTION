#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n + 1];
    int pre[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    map<int, int> m;
    m[0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (m[pre[i]]) {
            ans++;
            m.clear();
        }
        m[pre[i]]++;
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    int tc = 1;
    while (t--) {
        // cout << "Case " << tc++ << ": ";
        solve();
    }
    return 0;
}