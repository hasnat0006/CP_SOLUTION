//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 23|04|2024 21:39:51            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

map<int, char> input() {
    map<int, char> A;
    while (1) {
        char c;
        cin >> c;
        if (c == 'E')
            break;
        if (c == 'D') {
            int id;
            cin >> id;
            A.erase(id);
        }
        else if (c == 'I') {
            int id;
            char x;
            cin >> id >> x;

            vector<pair<int, char>> v;
            for (auto i : A) {
                if (i.first >= id)
                    v.push_back({i.first, i.second});
            }
            A[id] = x;
            for (auto i : v) {
                A[i.first + 1] = i.second;
            }
        }
    }
    for (auto i : A) {
        cerr << i.second << " " << i.first << endl;
    }
    return A;
}

void solve() {
    string a = "";
    map<int, char> A = input();
    map<int, char> B = input();
    cout << (A == B ? 0 : 1) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}