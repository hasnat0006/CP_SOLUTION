//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 19|10|2024 01:50:02            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

const int N = 1e5 + 5;
int prime[N];
vector<int> allPrime;
void sieveOfEratosthenes() {
    for (int i = 2; i < N; i++)
        prime[i] = 1;
    for (int i = 4; i < N; i += 2)
        prime[i] = 0;
    for (int i = 3; i * i < N; i++) {
        if (prime[i]) {
            for (int j = i * i; j < N; j += i * 2)
                prime[j] = 0;
        }
    }
    for (int i = 2; i < N; i++)
        if (prime[i])
            allPrime.push_back(i);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    int one = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        one += (v[i] == 1);
    }
    if (one) {
        cout << "YES" << endl;
        return;
    }
    int done = 0;
    for (int i = 0; i < n; i++) {
        int high = i + 2;
        int id = upper_bound(vf(allPrime), high) - allPrime.begin();
        // cerr << id << " " << allPrime[id - 1] << endl;
        for (int p = done; p < id; p++) {
            if (v[i] % allPrime[p] == 0) {
                cout << "NO" << endl;
                return;
            }
        }
        done++;
    }
    cout << "YES" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    sieveOfEratosthenes();
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}