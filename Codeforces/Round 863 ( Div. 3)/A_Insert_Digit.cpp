//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    char m;
    cin >> m;
    cin >> s;
    if (m == '0') {
        cout << s << "0" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if ((s[i] < m)) {
            s.insert(s.begin() + i, m);
            cout << s << endl;
            return;
        }
    }
    cout << s;
    cout << m << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}