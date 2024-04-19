//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 19|04|2024 11:48:43            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
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

const int mod = 1e9 + 7;
const int inf = 1e18;

struct Node {
    int take, nottake, index;
};

inline bool operator<(const Node &a, const Node &b) {
    if (a.take == b.take)
        return a.nottake > b.nottake;
    return a.take > b.take;
}

void print(Node a) {
    cerr << "NODE: " << a.take << ' ' << a.nottake << ' ' << a.index << endl;
}

void solve() {
    int n, adult, kid;
    cin >> n >> adult >> kid;
    vector<pair<int, int>> v(n);
    multiset<Node> A, K;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        A.insert({v[i].first, v[i].second, i});
        K.insert({v[i].second, v[i].first, i});
    }
    int ans = 0;
    while ((adult or kid) and (!A.empty() or !K.empty())) {
        Node a = *A.begin();
        Node k = *K.begin();
        A.erase(A.begin());
        K.erase(K.begin());
        print(a);
        print(k);
        if (!adult and kid) {
            ans += k.take, kid--;
            // continue;
        }
        else if (adult and !kid) {
            ans += a.take, adult--;
            // continue;
        }
        else if (a.index != k.index and adult and kid) {
            if (a.take >= k.take)
                ans += a.take, adult--;
            else
                ans += k.take, kid--;
        }
        else if (adult and kid) {
            Node aa = *A.begin();
            Node kk = *K.begin();
            int ans1 = a.take + kk.take;
            int ans2 = k.take + aa.take;
            if (ans1 >= ans2) {
                ans += ans1;
                adult--;
                kid--;
                K.erase(K.begin());
                Node temp = {kk.nottake, kk.take, kk.index};
                A.erase(A.find(temp));
            }
            else {
                ans += ans2;
                adult--;
                kid--;
                A.erase(A.begin());
                Node temp = {aa.nottake, aa.take, aa.index};
                K.erase(K.find(temp));
            }
            print(aa);
            print(kk);
        }
        for(auto i : A)
            cerr << i.index << " ";
        cerr << endl;
        for(auto i : K)
            cerr << i.index << " ";
        cerr << endl;
        cerr << adult << ' ' << kid << ' ' << ans << endl;
        cerr << "--------------------------\n";
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}