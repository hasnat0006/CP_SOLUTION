//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
#define endl "\n"
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    int n = a + b;
    string s;
    cin >> s;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == s[n - i - 1] and (s[i] == '0' or s[i] == '1'))
            continue;
        else if (s[i] != s[n - i - 1]) {
            if (s[n - i - 1] == '?')
                s[n - i - 1] = s[i];
            else if (s[i] == '?')
                s[i] = s[n - i - 1];
        }
    }
    int one = 0, zero = 0, ques = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            zero++;
        else if (s[i] == '1')
            one++;
        else
            ques++;
    }
    int baki_zero = a - zero;
    int baki_one = b - one;
    // cout << baki_zero << "  " << baki_one << endl;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == '?') {
            if (baki_zero > 1)
                s[i] = '0', s[n - i - 1] = '0', baki_zero -= 2;
            else if (baki_one > 1)
                s[i] = '1', s[n - i - 1] = '1', baki_one -= 2;
        }
    }
    // cout << baki_zero << "  " << baki_one << endl;
    if (n % 2 == 1) {
        if (baki_one > 0)
            s[n / 2] = '1', baki_one--;
        else if (baki_zero > 0)
            s[n / 2] = '0', baki_zero--;
    }
    if (baki_one != 0 or baki_zero != 0) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1] or s[i] == '?' or s[n - i - 1] == '?') {
            cout << -1 << endl;
            return;
        }
    }
    cout << s << endl;
}

int32_t main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}