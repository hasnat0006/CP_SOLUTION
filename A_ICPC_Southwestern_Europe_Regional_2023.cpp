//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 02|03|2024 23:24:29            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

int lengthOfLIS(vector<int>& nums) {
    vector<int> dp;
    for (int i = 0; i < nums.size(); i++) {
        auto it = lower_bound(vf(dp), nums[i]);
        if (it == dp.end())
            dp.push_back(nums[i]);
        else
            *it = nums[i];
    }
    return dp.size();
}

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<char> cards = {'E', 'R', 'S', 'W'};
    int ans = inf;
    do {
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            string s = v[i];
            s.erase(s.begin());
            int num = stoi(s);
            if (v[i][0] == cards[0])
                temp.push_back((int)2e6 + num);
            else if (v[i][0] == cards[1])
                temp.push_back(num + (int)3e6);
            else if (v[i][0] == cards[2])
                temp.push_back((int)4e6 + num);
            else if (v[i][0] == cards[3])
                temp.push_back((int)5e6 + num);
            else
                temp.push_back((int)6e6 + num);
        }
        ans = min(ans, n - lengthOfLIS(temp));
    } while (next_permutation(vf(cards)));
    cout << ans << endl;
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