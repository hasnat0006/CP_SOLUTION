//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 25|02|2024 23:40:58            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n, m, x;
    cin >> n >> m;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < m; i++) {
        cin >> x;
        cnt[x]++;
    }

    auto isPossible = [&](int time) {
        int done = 0, freeTime = 0;
        for (int i = 1; i <= n; i++) {
            done += min(cnt[i], time);
            int temp = time > cnt[i] ? time - cnt[i] : 0;
            freeTime += temp % 2 ? temp - 1 : temp;
        }
        done += freeTime / 2;
        return done >= m;
    };

    int time = 2 * m, low = 1, high = 2 * m;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(mid)) {
            time = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << time << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}