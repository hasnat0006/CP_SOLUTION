//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 02|03|2024 18:25:44            !//
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
    int n, t;
    cin >> n >> t;
    vector<int> ans;
    map<int, int> uniqueCnt;
    map<int, int> score;
    for (int i = 1; i <= n; i++) {
        score[i] = 0;
    }
    uniqueCnt[0] = n;
    for(int i = 1; i <= t; i++){
        int player, s;
        cin >> player >> s;
        int currentScore = score[player];
        uniqueCnt[currentScore]--;
        if(uniqueCnt[currentScore] == 0)
            uniqueCnt.erase(currentScore);
        score[player] += s;
        uniqueCnt[score[player]]++;
        cout << uniqueCnt.size() << endl;
    }
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