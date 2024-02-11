//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

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
    string s;
    int sum = 0, reverse = 0, rep = 0;
    stack<int> st;
    while (cin >> s) {
        int val;
        if (s == "PUSH") {
            if(reverse % 2 ){
                
            }
            cin >> val, sum += val, st.push(val);
        }
        else if (s == "POP" and st.size())
            sum -= st.top(), st.pop();
        else if (s == "PRINT") {
            if (st.size())
                cout << st.top() << endl;
        }
        else if (s == "SIZE")
            cout << st.size() << endl;
        else if (s == "SUM")
            cout << sum << endl;
        else if (s == "REPEAT") {
            rep++;
        }
        else if (s == "REVERSE") {
            reverse++;
        }
    }
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}