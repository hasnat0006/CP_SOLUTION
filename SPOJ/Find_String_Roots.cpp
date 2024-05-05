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

// #define int long long
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

vector<int> createLPS(string pattern) {
    vector<int> lps(pattern.length());
    int index = 0;
    for (int i = 1; i < pattern.length();) {
        if (pattern[index] == pattern[i]) {
            lps[i] = index + 1;
            index++, i++;
        }
        else {
            if (index != 0)
                index = lps[index - 1];
            else
                lps[i] = index, i++;
        }
    }
    return lps;
}
int kmp(string text, string pattern) {
    int cnt_of_match = 0;
    vector<int> lps = createLPS(pattern);
    // dbg(lps);
    int i = 0, j = 0;
    // i -> text, j -> pattern
    while (i < text.length()) {
        if (text[i] == pattern[j])
            i++, j++;
        else {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
        if (j == pattern.length()) {
            cnt_of_match++;
            // the index where match found -> (i - pattern.length());
            j = lps[j - 1];
        }
    }
    return cnt_of_match;
}

void solve() {
    string s;
    cin >> s;
    if(s == "*") exit(0);
    int n = s.size();
    int mn = n;
    vector<int> divisor;
    for(int i=1;i*i<=n;i++){
        if(n % i == 0){
            divisor.push_back(i);
            if(i != n/i) divisor.push_back(n/i);
        }
    }
    sort(divisor.begin(), divisor.end());
   // dbg(divisor);
    for(int i:divisor){
        i = i - 1;
        int j = i + 1;
        int flag = 0;
        while(j < n){
            // dbg(j, (j % (i + 1)));
            if(s[j] != s[j % (i + 1)]){
                flag = 1;
                break;
            }
            j++;
        }
        if(flag == 0 && n % (i+1) == 0){
            mn = n / (i + 1);
            break;
        }
    }
    cout<<mn<<"\n";
}

int32_t main() {
    YUSUF REZA HASNAT;
    while(true) {
        solve();
    }
    return 0;
}