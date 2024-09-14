//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|09|2024 22:01:27            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;



void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        s += temp;
    }
    cout << s << endl;
    map<char, int> mp;
    for(int i = 0; i < n * m; i++){
        mp[s[i]]++;
    }
    int totalCnt = 0;
    string Final = "narek";
    for(int i = 0; i < 5; i++){
        if(mp[Final[i]]){
            totalCnt+=mp[Final[i]];
        }
    }
    int len = Final.size();
    int il = 0;
    int cnt = 0;
    for(int i = 0; i < n * m; i++){
        if(s[i] == Final[il]){
            il++;
        }
        if(il == len){
            cnt++;
            il = 0;
        }
    }
    int AMI = cnt * 5;
    int GPT = totalCnt - AMI;
    // cout<< totalCnt << " " << AMI << " " << GPT << endl;
    cout << max(0ll, AMI - GPT) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}