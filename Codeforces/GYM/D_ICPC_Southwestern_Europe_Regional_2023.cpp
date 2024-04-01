//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 26|02|2024 20:16:03            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define PAIR pair<int, pair<string, int>>

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<PAIR> v(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int point;
        cin >> point;
        point *= 10;
        vector<int> temp(6);
        for (int j = 0; j < 6; j++)
            cin >> temp[j];
        point += accumulate(vf(temp), 0) - *min_element(vf(temp)) -
                 *max_element(vf(temp));
        v[i] = {point, {s, i}};
    }

    auto cmp = [](PAIR a, PAIR b) {
        if (a.first < b.first)
            return true;
        if (a.first == b.first) {
            if (a.second.second > b.second.second)
                return true;
        }
        return false;
    };

    sort(vr(v), cmp);
    int diff = 0, cnt = 1;
    cout << v[0].second.first << " " << v[0].first << endl;
    for (int i = 1; i < min(n, 1000ll); i++) {
        if (v[i].first != v[i - 1].first) {
            diff++;
            if (diff == 2 or cnt >= 3)
                break;
        }
        cout << v[i].second.first << " " << v[i].first << endl;
        cnt++;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}