//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|03|2024 00:58:38            !//
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

struct Node{
    int gcd, a, b;
};

void solve() {
    int n;
    cin >> n;
    set<int> div;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.insert(i);
            div.insert(n / i);
        }
    }
    div.erase(div.find(n));
    vector<Node> v;
    for(auto i : div){
        int a = i;
        int b = n - i;
        int gcd = __gcd(a, b);
        v.push_back({gcd, a, b});
    }
    sort(vf(v), [](Node a, Node b){
        return a.gcd > b.gcd;
    });
    cout << v[0].a << " " << v[0].b << endl;
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