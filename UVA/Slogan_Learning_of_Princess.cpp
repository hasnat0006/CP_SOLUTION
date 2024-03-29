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
    cin >> n;
    vector<pair<string, string>> v(n);
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string t1, t2;
        getline(cin, t1);
        getline(cin, t2);
        v[i] = {t1, t2};
    }
    sort(v.begin(), v.end());
    int q;
    cin >> q;
    cin.ignore();
    while (q--) {
        string p;
        getline(cin, p);
        for (int i = 0; i < n; i++) {
            if (v[i].first == p) {
                cout << v[i].second << endl;
                break;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        unsolve();
    return 0;
}