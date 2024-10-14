//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|10|2024 12:43:22            !//
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

string num = "0123456789ACDEFHJKLMNPRTVWX";
int mToTen(string n, int m) {
    int multi = 1;
    int result = 0;
    for (int i = n.size() - 1; i >= 0; i--) {
        result += num.find(n[i]) * multi;
        multi *= m;
    }
    return result;
}

int calculation(string s){
    int sum = 0;
    map<char,int> charValue;
    for(int i = 0; i < num.size(); i++){
        charValue[num[i]] = i;
    }
    vector<int> value = {2, 4, 5, 7, 8, 10, 11, 13};
    for(int i = 0; i < 8; i++){
        sum += (value[i] * charValue[s[i]]);
    }
    return sum % 27;
}

void solve() {
    map<char,char> mp;
    mp['B'] = '8', mp['G'] = 'C', mp['I'] = '1', mp['O'] = '0', mp['S'] = '5', mp['U'] = 'V', mp['Y'] = 'V', mp['Z'] = '2';
    string print, s;
    cin >> print >> s;
    for(int i = 0; i < s.size(); i++){
        if(mp[s[i]])
            s[i] = mp[s[i]];
    }
    cout << print << " ";
    if(calculation(s) == 10){
        s.pop_back();
        cout << mToTen(s, 27) << endl;
    }
    else
        cout << "Invalid" << endl;
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