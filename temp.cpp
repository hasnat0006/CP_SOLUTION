//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|05|2024 00:18:39            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

int maxVal = 1005;
vector<int> countDivisor(maxVal, 0);
vector<pair<int,int>> ans;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first < b.first)
        return true;
    if(a.first == b.first){
        if(a.second > b.second)
            return true;
        return false;
    }
    return false;
}

void countingDivisor(){
    for (int i = 1; i < maxVal; i++)
        for(int j= i; j<maxVal;j+= i)
            countDivisor[j]++;
    for(int i = 1; i <= 1000; i++)
        ans.push_back({countDivisor[i], i});
    sort(vf(ans),cmp);
}


void solve() {
    int n;
    cin >> n;
    cout << ans[n - 1].second << endl;
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    countingDivisor();
    // for(auto i : ans){
    //     cout << i.second << " -> " << i.first << endl;
    // }
    cin >> t;
    for (int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
