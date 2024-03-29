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

void solve() {
    int nnnn, mmmm;
    cin >> nnnn >> mmmm;
    char s[nnnn][mmmm];
    bool f = false;
    for (int it1 = 0; it1 < nnnn; it1++) {
        for (int it2 = 0; it2 < mmmm; it2++) {
            cin >> s[it1][it2];
        }
    }
    if (nnnn < 4 && mmmm < 4) {
        cout << "NO\n";
        return;
    }
    int ami = 0, kiso = 0, pari = 0, na = 0;
    for (int it1 = 0; it1 < mmmm; it1++) {
        for (int it2 = 0; it2 < nnnn; it2++) {
            if (s[it2][it1] == 'v' && ami == 0) {
                ami++;
                break;
            }
            if (s[it2][it1] == 'i' && ami == 1 && kiso == 0) {
                kiso++;
                break;
            }
            else if (s[it2][it1] == 'k' && kiso == 1 && pari == 0) {
                pari++;
                break;
            }
            else if (s[it2][it1] == 'a' && pari == 1 && na == 0) {
                na++;
                break;
            }
        }
        dbg(ami, kiso, pari, na);
        if (ami && kiso && pari && na) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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