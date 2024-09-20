//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 20|09|2024 21:07:25            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const int inf = 1e18;

int ask(string s) {
    cout << "? " << s << endl;
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        int x = ask("0");
        cout << "! " << (x == 1 ? "0" : "1") << endl;
        return;
    }
    string s = "0";
    int f = 0;
    map<string, int> mp;
    for (int i = 3; i <= 2 * n; i++) {
        if (f)
            s.insert(s.begin(), '0');
        else
            s += "0";
        int x = mp[s];
        int forZero;
        if (x == 0) {
            forZero = ask(s);
            mp[s] = forZero + 1;
        }
        else
            forZero = x - 1;
        if (forZero == 0) {
            if (f)
                s.erase(s.begin());
            else
                s.pop_back();
            if (f)
                s.insert(s.begin(), '1');
            else
                s += "1";
            x = mp[s];
            int forOne;
            if (x == 0) {
                forOne = ask(s);
                mp[s] = forOne + 1;
            }
            else
                forOne = x - 1;
            if (forOne == 0) {
                if (f)
                    s.erase(s.begin());
                else
                    s.pop_back();
                f = 1;
            }
        }
        if ((int)s.size() == n) {
            break;
        }
    }
    
    if(s.size() < n){
        s = "1";
        f = 0;
        for (int i = 3; i <= 2 * n; i++) {
            if (f)
                s.insert(s.begin(), '0');
            else
                s += "0";
            int x = mp[s];
            int forZero;
            if (x == 0) {
                forZero = ask(s);
                mp[s] = forZero + 1;
            }
            else
                forZero = x - 1;
            if (forZero == 0) {
                if (f)
                    s.erase(s.begin());
                else
                    s.pop_back();
                if (f)
                    s.insert(s.begin(), '1');
                else
                    s += "1";
                x = mp[s];
                int forOne;
                if (x == 0) {
                    forOne = ask(s);
                    mp[s] = forOne + 1;
                }
                else
                    forOne = x - 1;
                if (forOne == 0) {
                    if (f)
                        s.erase(s.begin());
                    else
                        s.pop_back();
                    f = 1;
                }
            }
            if ((int)s.size() == n) {
                break;
            }
        }
    }
    cout << "! " << s << endl;
}

int32_t main() {
    // ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}