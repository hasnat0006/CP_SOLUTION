//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 07|10|2024 11:38:09            !//
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


set<string> Allans;
string a, b;
void func(int i, int j, string ans = ""){
    if(ans.size() == a.size() + b.size()){
        Allans.insert(ans);
        return;
    }
    if(i < a.size())
        func(i + 1, j, ans + a[i]);
    if(j < b.size())
        func(i, j + 1, ans + b[j]);
}

void solve() {
    Allans.clear();
    cin >> a >> b;
    func(0, 0);
    for(auto x: Allans)
        cout << x << endl;
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}