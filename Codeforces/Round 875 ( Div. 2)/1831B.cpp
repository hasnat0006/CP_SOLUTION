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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int, int> mpa, mpb, mp;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++) {
        int temp = a[i];
        int c = 0;
        while (a[i] == temp && i < n) {
            i++;
            c++;
        }
        i--;
        mpa[a[i]] = max(mpa[a[i]], c);
    }
    for (int i = 0; i < n; i++) {
        int temp = b[i];
        int c = 0;
        while (b[i] == temp && i < n) {
            i++;
            c++;
        }
        i--;
        mpb[b[i]] = max(mpb[b[i]], c);
    }
    for (auto i : mpa)
        mp[i.first] = i.second;
    for (auto i : mpb)
        mp[i.first] += i.second;
    int c = 0;
    for (auto i : mp)
        c = max(c, i.second);
    cout << c << "\n";
}

int32_t main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}