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
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

string decToBinary(int n) { return bitset<8>(n).to_string(); }

vector<int> convertNumber(string a) {
    vector<int> real;
    string temp = "";
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '.') {
            real.push_back(stoi(temp));
            temp = "";
        }
        else
            temp.push_back(a[i]);
    }
    real.push_back(stoi(temp));
    return real;
}

void solve() {
    string a, b;
    cin >> a >> b;
    vector<int> real = convertNumber(a);
    dbg(real);
    vector<string> fake;
    string temp = "";
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == '.') {
            fake.push_back((temp));
            temp = "";
        }
        else {
            temp.push_back(b[i]);
        }
    }
    fake.push_back((temp));
    for (int i = 0; i < real.size(); i++) {
        string binary = decToBinary(real[i]);
        dbg(binary);
        for (int j = fake[i].size() - 1; j >= 0; j--) {
            if (binary[j] != fake[i][j]) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}