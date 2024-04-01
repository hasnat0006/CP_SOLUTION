//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;

void unsolve() {
    int n;
    string s, temp, copy;
    cin >> s >> n;
    int sum = 0;
    copy = s;
    sort(s.begin(), s.end());
    int c = 0;
    for (int i = 0; s[i]; i++) {
        c += s[i] - 96;
        temp.pb(s[i]);
        if (c == n)
            break;
        else if (c > n) {
            c -= (s[i] - 96);
            temp.pop_back();
            break;
        }
    }
    string ans;
    for (int i = 0; i < copy.size(); i++) {
        if (temp.find(copy[i]) != string ::npos) {
            ans.pb(copy[i]);
            temp.erase(temp.begin() + temp.find(copy[i]));
        }
        if (temp.size() == 0)
            break;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        unsolve();
    return 0;
}
