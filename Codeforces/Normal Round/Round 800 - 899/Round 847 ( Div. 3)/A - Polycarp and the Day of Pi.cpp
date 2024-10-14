#include <bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve() {
    string s = "3141592653589793238462643383279502884197";
    int c = 0;
    string st;
    cin >> st;
    for (int i = 0; i < st.length(); i++) {
        if (st[i] == s[i])
            c++;
        else
            break;
    }
    cout << c << endl;
}
int32_t main() {
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}