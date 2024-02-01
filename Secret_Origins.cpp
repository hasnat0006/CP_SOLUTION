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

void solve() {
    int n, one = 0;
    cin >> n;
    string s = bitset<32>(n).to_string();
    for (int i = 32; i >= 0; i--) {
        if (s[i] == '1')
            one = i;
        else if (s[i] == '0' and one) {
            swap(s[i], s[one]);
            break;
        }
    }
    int remove = 0;
    for(int i = one + 1; i < 32; i++) {
        if(s[i] == '1') 
            s[i] = '0', remove++;
    }
    while(remove--)
        s[31 - remove] = '1';
    cout << bitset<32>(s).to_ulong() << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";	
        solve();
    }
    return 0;
}