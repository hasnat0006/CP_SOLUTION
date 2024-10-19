//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 19|10|2024 21:08:26            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

bool valid(vector<int> &mp, vector<int> &v, vector<int> &id, string &s) {
    int n = mp.size();
    for (int i = 1; i < n; i++) {
        if (mp[i] != 0) {
            if (mp[i] < 0) {
                while (mp[i] != 0) {
                    int idofI = id[i];
                    char charofI = s[idofI];
                    char agerIderChar = s[idofI - 1];
                    if ((charofI == 'L' or agerIderChar == 'R') and
                        v[idofI] < v[idofI - 1]) {
                        mp[i]++;
                        mp[v[idofI - 1]]--;
                        id[i]--;
                        id[v[idofI - 1]]++;
                        swap(v[idofI], v[idofI - 1]);
                    }
                    else
                        break;
                }
            }
            else if (mp[i] > 0) {
                while (mp[i] != 0) {
                    int idofI = id[i];
                    char charofI = s[idofI];
                    char porerIderChar = s[idofI + 1];
                    if ((charofI == 'R' or porerIderChar == 'L') and
                        v[idofI] > v[idofI + 1]) {
                        mp[i]--;
                        mp[v[idofI + 1]]++;
                        id[i]++;
                        id[v[idofI + 1]]--;
                        swap(v[idofI], v[idofI + 1]);
                    }
                    else
                        break;
                }
            }
        }
    }
    return (is_sorted(vf(v)));
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1), id(n + 1);
    // map<int, int> mp;
    vector<int> mp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        id[v[i]] = i;
        mp[v[i]] = v[i] - i;
    }
    string s;
    cin >> s;
    s.insert(s.begin(), 'X');
    while (q--) {
        int x;
        cin >> x;
        if (s[x] == 'L')
            s[x] = 'R';
        else
            s[x] = 'L';
        vector<int> temp1(n + 1), temp2(n + 1), temp3(n + 1);
        for(int i = 1; i <= n; i++){
            temp1[i] = mp[i];
            temp2[i] = v[i];
            temp3[i] = id[i];
        }
        if (valid(temp1, temp2, temp3, s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}