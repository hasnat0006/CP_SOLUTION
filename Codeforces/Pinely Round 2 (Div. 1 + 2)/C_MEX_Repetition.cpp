//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

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
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

vector<int> shifting(vector<int> &v, int k) {
    int n = v.size();
    k = k % n;
    vector<int> shift;
    for (int i = 0; i < n; i++) {
        if (i < k) {
            shift.pb(v[n + i - k]);
        }
        else {
            shift.pb(v[i - k]);
        }
    }
    return shift;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int c = 0;
    vector<int> v(n), par;
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        par.pb(i);
        st.insert(v[i]);
    }
    par.pb(n);
    // vector<int> shift = shifting(v, k);
    // dbg(shift);
    vector<int> temp = v, cpy = v;
    sort(vf(cpy));
    for (int i = 0; i < n; i++) {
        if (cpy[i] == c) {
            c += 1;
        }
    }
    // int c = C(v, n);
    temp.pb(c);
    vector<int> shifted_array = shifting(temp, k);
    shifted_array.pop_back();
    // dbg(shifted_array);
    for (auto i : shifted_array)
        cout << i << " ";
    cout << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        // case(i)
        solve();
    return 0;
}