//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 10|10|2024 22:09:31            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int a, b, l;
    cin >> a >> b >> l;
    vector<int> divs;
    for (int i = 1; i * i <= l; i++) {
        if (l % i == 0) {
            divs.push_back(i);
            if (i * i != l)
                divs.push_back(l / i);
        }
    }
    sort(vf(divs));
    for(int i = 0; i < divs.size(); i++){
        int lcm1 = (a * b) / __gcd(a, b);
        int lcm2 = (lcm1 * divs[i]) / __gcd(lcm1, divs[i]);
        if(lcm2 == l){
            cout << divs[i] << endl;
            return;
        }
    }
    cout << "impossible" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve(); 
    }
    return 0;
}