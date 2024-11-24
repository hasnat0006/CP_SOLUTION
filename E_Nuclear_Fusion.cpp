//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 24|11|2024 12:28:36            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

unordered_map<string, int> Table = {
    {"H", 1},    {"He", 2},   {"Li", 3},   {"Be", 4},   {"B", 5},
    {"C", 6},    {"N", 7},    {"O", 8},    {"F", 9},    {"Ne", 10},
    {"Na", 11},  {"Mg", 12},  {"Al", 13},  {"Si", 14},  {"P", 15},
    {"S", 16},   {"Cl", 17},  {"Ar", 18},  {"K", 19},   {"Ca", 20},
    {"Sc", 21},  {"Ti", 22},  {"V", 23},   {"Cr", 24},  {"Mn", 25},
    {"Fe", 26},  {"Co", 27},  {"Ni", 28},  {"Cu", 29},  {"Zn", 30},
    {"Ga", 31},  {"Ge", 32},  {"As", 33},  {"Se", 34},  {"Br", 35},
    {"Kr", 36},  {"Rb", 37},  {"Sr", 38},  {"Y", 39},   {"Zr", 40},
    {"Nb", 41},  {"Mo", 42},  {"Tc", 43},  {"Ru", 44},  {"Rh", 45},
    {"Pd", 46},  {"Ag", 47},  {"Cd", 48},  {"In", 49},  {"Sn", 50},
    {"Sb", 51},  {"Te", 52},  {"I", 53},   {"Xe", 54},  {"Cs", 55},
    {"Ba", 56},  {"La", 57},  {"Ce", 58},  {"Pr", 59},  {"Nd", 60},
    {"Pm", 61},  {"Sm", 62},  {"Eu", 63},  {"Gd", 64},  {"Tb", 65},
    {"Dy", 66},  {"Ho", 67},  {"Er", 68},  {"Tm", 69},  {"Yb", 70},
    {"Lu", 71},  {"Hf", 72},  {"Ta", 73},  {"W", 74},   {"Re", 75},
    {"Os", 76},  {"Ir", 77},  {"Pt", 78},  {"Au", 79},  {"Hg", 80},
    {"Tl", 81},  {"Pb", 82},  {"Bi", 83},  {"Po", 84},  {"At", 85},
    {"Rn", 86},  {"Fr", 87},  {"Ra", 88},  {"Ac", 89},  {"Th", 90},
    {"Pa", 91},  {"U", 92},   {"Np", 93},  {"Pu", 94},  {"Am", 95},
    {"Cm", 96},  {"Bk", 97},  {"Cf", 98},  {"Es", 99},  {"Fm", 100},
    {"Md", 101}, {"No", 102}, {"Lr", 103}, {"Rf", 104}, {"Db", 105},
    {"Sg", 106}, {"Bh", 107}, {"Hs", 108}, {"Mt", 109}, {"Ds", 110},
    {"Rg", 111}, {"Cn", 112}, {"Nh", 113}, {"Fl", 114}, {"Mc", 115},
    {"Lv", 116}, {"Ts", 117}, {"Og", 118}};

ll dp[17][1 << 17];
vector<string> v;
int n, k, cnt, ans = 0;
void findAns(ll i, ll mask) {
    if(i < 0)
        return;
    if(dp[i][mask] != -1)
        return;
    ll sum = 0;
    for (ll j = 0; j < n; j++) {
        if (mask & (1 << j))
            sum += Table[v[j]];
    }
    if(sum == cnt) {
        cout << cnt << " " << sum << '\n';
        ans = mask;
        cout << "MILSE" << endl;
        return;
    }
    // nibo na
    findAns(i - 1, mask);
    // avaiable thakle nibo
    for (ll j = 0; j < n; j++) {
        if(!(mask & (1 << j))) {
            findAns(i - 1, mask | (1 << j));
        }
    }
}

void solve() {
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    while (k--) {
        string s;
        cin >> s;
        memset(dp, -1, sizeof(dp));
        ans = 0, cnt = -1;
        findAns(n - 1, 0);
        cout << ans << endl;
        if(ans > 0) {
            for (ll j = 0; j < n; j++) {
                if (ans & (1 << j))
                    cout << v[j] << " ";
            }
            cout << '\n';
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}