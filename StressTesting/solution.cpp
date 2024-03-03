
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define in cin.tie(NULL)
#define out cout.tie(NULL)
// #include <ext/pb_ds/assoc_container.hpp>

int mod = 1000000007;
int inf = 1e18;

int32_t main() {
    fastio;
    in;
    out;
    int t = 1;
    cin >> t;
    int cs = 1;    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int i = 0, j = 0;
        int cnt1 = 0, cnt2 = 0;
        while (i < n and j < n) {
            if (b[i] == a[j]) {
                i++;
                j++;
                cnt1++;
            }
            else {
                j++;
            }
        }
        i = n - 1, j = n - 1;
        while (i >= 0 and j >= 0) {
            if (b[i] == a[j]) {
                i--;
                j--;
                cnt2++;
            }
            else {
                j--;
            }
        }
        i = 0, j = 0;
        int k = n - 1, l = n - 1;
        int cnt3 = 0;
        if (cnt1 == n and cnt2 == n) {
            cout << "Case " << cs << ": "
                 << "0" << endl;
            cs++;
            continue;
        }
        while (i < n and j < n and l >= 0 and k >= 0) {
            if (b[i] == a[j] and b[k] == a[l]) {
                if (j != l) {
                    cnt3 += 2;
                    i++;
                    j++;
                    k--;
                    l--;
                }
                else
                    break;
            }
            else if (b[i] == a[j] and b[k] != a[l]) {
                l--;
            }
            else if (b[i] != a[j] and b[k] == a[l]) {
                j++;
            }
            else
                break;
        }

        int ans = max(cnt1, cnt3);
        ans = max(cnt2, ans);
        ans = (n - ans);
        cout << "Case " << cs << ": " << ans << endl;
        cs++;
    }
    return 0;
}