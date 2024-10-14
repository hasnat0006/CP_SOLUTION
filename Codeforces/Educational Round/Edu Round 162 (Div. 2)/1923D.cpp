//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 25|02|2024 23:01:37            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

vector<int> v, pre, cnt, ans;

int sum(int l, int r){
    return pre[r] - pre[l - 1];
}

bool check(int l, int r){
    if(l == r)
        return true;
    return cnt[r] - cnt[l] > 0;
}

void solve() {
    v.clear(), pre.clear(), cnt.clear(), ans.clear();
    int n;
    cin >> n;
    v.resize(n + 1, 0), pre.resize(n + 1, 0), cnt.resize(n + 1, 0), ans.resize(n + 1 , inf);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pre[i] = pre[i - 1] + v[i];
        cnt[i] = (v[i] != v[i - 1]) + cnt[i - 1];
    }
    for(int i = 1; i <= n; i++){
        if(i > 1 and v[i - 1] > v[i])
            ans[i] = 1;
        if(i < n and v[i + 1] > v[i])
            ans[i] = 1;
        int l = 1, r = i - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(sum(mid, i - 1) > v[i] and check(mid, i - 1)){
                ans[i] = min(ans[i], i - mid);
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        l = i + 1, r = n;
        while(l <= r){
            int mid = (l + r) / 2;
            if(sum(i + 1, mid) > v[i] and check(i + 1, mid)){
                ans[i] = min(ans[i], mid - i);
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
    }
    for(int i = 1; i <= n; i++)
        ans[i] == inf ? cout << -1 << " " : cout << ans[i] << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}