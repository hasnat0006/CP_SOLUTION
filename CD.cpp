//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

vector<int> v;
int TIME, n;
map<int, vector<int>> mp;

void maximumSong(int i, int done, vector<int> song) {
    if (i == n) {
        dbg(song);
        int sum = 0;
        for (auto x : song)
            sum += x;
        if (mp[sum].size() > 0) {
            int sum2 = 0;
            for (auto x : mp[sum])
                sum2 += x;
            if (sum2 > sum)
                return;
            else if (mp[sum].size() < song.size())
                mp[sum] = song;
        }
        else
            mp[sum] = song;
        return;
    }
    if (done + v[i] <= TIME) {
        song.push_back(v[i]);
        maximumSong(i + 1, done + v[i], song);
        song.pop_back();
    }
    maximumSong(i + 1, done, song);
}

int32_t main() {
    YUSUF REZA HASNAT;
    while (cin >> TIME >> n) {
        mp.clear();
        v.resize(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        vector<int> song;
        maximumSong(0, 0, song);
        vector<pair<int, int>> vp;
        // dbg(mp);
        for (auto i : mp) {
            int sum = 0;
            for (auto j : i.second)
                sum += j;
            vp.push_back({sum, i.second.size()});
        }
        sort(vr(vp));
        dbg(vp);
        auto it = mp.lower_bound(vp[0].first);
        for (auto i : it->second)
            cout << i << " ";
        cout << "sum:" << it->first << endl;
    }
    return 0;
}