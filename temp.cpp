//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

const int N = 1e6 + 5;
int spf[N];
void smallestPrimeFactorUsingSeive() {
    for (int i = 2; i < N; i++) {
        if (spf[i] == 0) {
            for (int j = i; j < N; j += i) {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
}


void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	map<set<int>, int> mp;
	map<int, int> count;
	int one = 0;
	for(int i = 0; i < n; i++){
		int num; cin >> num;
		if(num == 1){
			one++;
			continue;
		}
		set<int> temp;
		dbg(num);
		while(num > 1) {
			int factor = spf[num];
			temp.insert(factor);
			num /= factor;
		}
		dbg(temp);
		for(auto it : temp)
			count[it]++;
		mp[temp]++;
	}
	int ans = one * (n - 1);
	// n = mp.size();
	dbg(n, ans);
	for(auto &i : mp){
		dbg(i.first, i.second);
		int cnt = 0;
		for(auto &it : i.first){
			cnt += count[it];
			dbg(count[it], i.second);
		}
		cnt -= i.first.size() - 1LL;
		ans += (n - cnt) * i.second;
		dbg(cnt, ans);
	}
	cout << ans / 2LL << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    smallestPrimeFactorUsingSeive();
    // cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}