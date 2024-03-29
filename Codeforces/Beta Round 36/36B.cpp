//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

int binaryExponentiation(int base, int power)  ////O(log2(power))
{
    if (power == 0)
        return 1;
    int ans = binaryExponentiation(base, power / 2);
    if (power % 2 == 1)
        return (((ans * ans) % mod) * base) % mod;
    return (ans * ans) % mod;
}

int n;
string pattern[3];
string ans[250];
string copyy[250];

int magic(int k) {
    if (!k) {
        ans[0] = '.';
        return 1;
    }
    int len = magic(k - 1);
    for (int i = 0; i < len * n; i++) {
        for (int j = 0; j < len * n; j++) {
            copyy[i] += '*';
        }
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (ans[i][j] == '.') {
                for (int p = 0; p < n; p++) {
                    for (int q = 0; q < n; q++) {
                        copyy[i * n + p][j * n + q] = pattern[p][q];
                    }
                }
            }
        }
    }
    for (int i = 0; i < len * n; i++) {
        ans[i] = copyy[i];
        copyy[i] = "";
    }
    return len * n;
}

void solve() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> pattern[i];
    int len = magic(k);
    for (int i = 0; i < len; i++)
        cout << ans[i] << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}

/*

5 3 2 1 4
4 3 2 1 5
3 4 2 1 5
2 4 3 1 5
1 4 3 2 5
1 3 4 2 5
1 2 4 3 5
1 2 3 4 5

// 4 2 3 1 5
// 4 1 3 2 5
// 4 1 2 3 5


*/