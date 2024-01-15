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
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

const int N = 100005;
int ans[N];

void merge(pair<int, int> a[], int start, int mid, int end) {
    pair<int, int> f[mid - start + 1], s[end - mid];
    int n = mid - start + 1;
    int m = end - mid;
    for (int i = start; i <= mid; i++)
        f[i - start] = a[i];
    for (int i = mid + 1; i <= end; i++)
        s[i - mid - 1] = a[i];
    int i = 0, j = 0, k = start;
    int cnt = 0;
    while (i < n && j < m) {
        if (f[i].second <= s[j].second) {
            ans[f[i].first] += cnt;
            a[k++] = f[i++];
        }
        else {
            cnt++;
            a[k++] = s[j++];
        }
    }
    while (i < n) {
        ans[f[i].first] += cnt;
        a[k++] = f[i++];
    }
    while (j < m) {
        a[k++] = s[j++];
    }
}

void mergesort(pair<int, int> item[], int low, int high) {
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergesort(item, low, mid);
    mergesort(item, mid + 1, high);
    merge(item, low, mid, high);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    pair<int, int> a[n];
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; i++) {
        a[i].second = v[i];
        a[i].first = i;
    }
    mergesort(a, 0, n - 1);
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt = max(cnt, ans[i]);
    cout << cnt << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}