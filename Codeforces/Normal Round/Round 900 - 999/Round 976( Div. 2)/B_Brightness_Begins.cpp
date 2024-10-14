
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

int Func(int n) {
    vector<int> temp(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            temp[j] = !temp[j];
        }
    }
    int oneCnt = 0;
    for (int j = 1; j <= n; j++) {
        oneCnt += temp[j];
    }
    return oneCnt;
}

__int128_t calN(int x, int a = 2, int d = 2) {
    // 2x = 2an + n(n-1)d
    // 2x = 2an + n^2d - nd
    // n^2d + (2a - d)n - 2x = 0
    // n = (-B + sqrt(B^2 - 4AC)) / 2A
    
    __int128_t A = d;
    __int128_t B = 2 * a - d;
    __int128_t C = -2 * x;

    __int128_t discriminant = B * B - 4 * A * C;
    __int128_t sqrtDiscriminant = sqrtl(discriminant);
    __int128_t n1 = (-B + sqrtDiscriminant) / (2 * A);
    __int128_t n2 = (-B - sqrtDiscriminant) / (2 * A);

    __int128_t n = (n1 >= 0) ? n1 : n2;
    return n;
}

__int128_t SumTillN(int n, int a = 2, int d = 2) {
    __int128_t A = a;
    __int128_t D = d;
    __int128_t N = n;
    __int128_t sum = (N * (2 * A + (N - 1) * D)) / 2;
    return sum;
}

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cout << i << " " << Func(i) << " " << i - Func(i) << endl;
        mp[Func(i)] = i;
    }
    for (auto i : mp) {
        cout << i.first << " " << i.second << " " << i.second - i.first <<
        endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}