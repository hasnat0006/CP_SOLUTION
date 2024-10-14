//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

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

/*

Anna turns: the only thing he can do is to reverse the string
            which has maximum number of zeros at the end.
Sasha turns: the only thing he can do is to concreate two strings.

Now for example we have 4 input : 100, 1000, 10000, 100000
Turn1(anna): he can choose 100000 and reverse it to 1. arr = {100, 1000, 10000, 1}
Turn2(sasha): he can choose 10000 and 1 then concreate them. arr = {100, 1000, 100001}
Turn3(anna): he can choose 1000 and reverse it to 1. arr = {100, 1, 100001}
Turn4(sasha): he can choose 100 and 1 then concreate them. arr = {1001, 100001}

after this anna can't reduce the length of the string.
Now we just need to check if the length of the string is greater than m or not.

*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, string>> v(n);
    int totalDigit = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int zero = 0;
        totalDigit += s.size();
        for (int j = s.size() - 1; j >= 0; j--) {
            if (s[j] == '0')
                zero++;
            else
                break;
        }
        v[i] = {zero, s};
    }
    sort(vr(v));
    int removeDigit = 0;
    for(int i = 0; i < n; i++){
        if(v[i].first == 0)
            break;
        if(i % 2 == 0 and v[i].first > 0){
            while(v[i].second.back() == '0'){
                removeDigit++;
                v[i].second.pop_back();
            }
        }
    }
    totalDigit - removeDigit > m ? cout << "Sasha" << endl : cout << "Anna" << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}