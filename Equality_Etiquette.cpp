    //!-----------------------------------------------------!//
    //!                  YUSUF REZA HASNAT                  !//
    //!-----------------------------------------------------!//

    #pragma GCC optimize("O3")
    #include <bits/stdc++.h>
    #ifndef ONLINE_JUDGE
    #include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
    #else
    #define dbg(x...)
    #define dbgc(x...)
    #endif

    using namespace std;

    #define int long long
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
        int a, b;
        cin >> a >> b;
        int diff = abs(a - b);
        int low = 0, high = diff, ans = 0;
        auto SUM = [&](int x) { return ((x * (x + 1)) / 2); };
        while (low <= high) {
            int mid = (low + high) / 2;
            int possible_ans = SUM(mid);
            if (possible_ans > diff)
                high = mid - 1;
            else
                low = mid + 1, ans = mid;
        }
        if (SUM(ans) == diff) {
            cout << ans << endl;
            return;
        }
        ans++;
        if ((SUM(ans) - diff) % 2 == 0)
            cout << ans << endl;
        else
            cout << (((SUM(ans + 1) - diff) % 2 == 0) ? ans + 1 : ans + 2) << endl;
    }

    int32_t main() {
        YUSUF REZA HASNAT;
        int t = 1;
        cin >> t;
        for (int i = 1; i <= t; i++) {
            // dbg(i, "-----------");
            solve();
        }
        return 0;
    }