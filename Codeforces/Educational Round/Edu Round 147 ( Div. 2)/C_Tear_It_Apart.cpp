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
/*

! abacaba
! codeforces -> oeocs -> oos -> oo
! oooooooo
! abcdef
! mewheniseearulhiiarul

*/
int recursion(int n) {
    if (n == 1)
        return 1;
    return (1 + recursion(n / 2));
}

void solve() {
    string temp, s;
    cin >> s;
    char c;
    int mx = -1, cnt = 0;
    mx = INT_MAX;
    for (int i = 0; i < 26; i++) {
        int temp_mx = -1;
        c = i + 'a';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c)
                temp_mx = max(cnt, temp_mx), cnt = 0;
            else
                cnt++;
        }
        temp_mx = max(cnt, temp_mx), cnt = 0;
        mx = min(mx, temp_mx);
    }
    int ans = 0;
    while (mx)
        ans++, mx /= 2;
    cout << ans << endl;
}

int32_t main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}