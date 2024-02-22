//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
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
    int n;
    cin >> n;
    int arr[n];
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
        freq[x]++;
    }
    sort(arr, arr + n);
    map<int, int> cal;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (cal[arr[i]] == 1)
            continue;
        bitset<31> b = (arr[i]);
        b.flip();
        int s = b.to_ullong();
        if (freq[s]) 
            cal[s] = 1;
        ans += max(freq[arr[i]], freq[s]);
        cal[arr[i]] = 1;
    }
    cout << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}