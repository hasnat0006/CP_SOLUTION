//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 24|11|2024 12:28:36            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll int
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

vector<string> Table = {
    "",   "H",  "He", "Li", "Be", "B",  "C",  "N",  "O",  "F",  "Ne", "Na",
    "Mg", "Al", "Si", "P",  "S",  "Cl", "Ar", "K",  "Ca", "Sc", "Ti", "V",
    "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br",
    "Kr", "Rb", "Sr", "Y",  "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag",
    "Cd", "In", "Sn", "Sb", "Te", "I",  "Xe", "Cs", "Ba", "La", "Ce", "Pr",
    "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu",
    "Hf", "Ta", "W",  "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi",
    "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U",  "Np", "Pu", "Am",
    "Cm", "Bk", "Cf", "Es", "Fm", "Md"};

struct Node {
    ll mask, prevI, prevJ;
    Node() {}
    Node(ll i, ll j, ll k) { mask = i, prevI = j, prevJ = k; }
};

int dp[1 << 17][105];
int a[17], b[17];
ll n, k;
set<ll> st;

ll findAllCombinations(ll mask, ll sum) {
    if (sum == 0) {
        st.insert(mask);
        return 1;
    }
    if (mask == (1 << n) - 1)
        return 0;
    if (dp[mask][sum] != -1)
        return dp[mask][sum];
    int res;
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i)) and (sum - a[i]) >= 0) {
            res = findAllCombinations(mask | (1 << i), (sum - a[i]));
        }
    }
    return dp[mask][sum] = res;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    auto findValue = [](string s) {
        for (int i = 0; i < Table.size(); i++) {
            if (Table[i] == s)
                return i;
        }
    };

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = findValue(s);
    }
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        b[i] = findValue(s);
    }
    sort(a, a + n);
    sort(b, b + k);

    ll TotalSum = accumulate(a, a + n, 0LL);
    ll Sum = accumulate(b, b + n, 0LL);
    int i = n - 1;
    while(i >= 0 and a[i] > b[k - 1])
        TotalSum -= a[i], i--;
    // cout << TotalSum << " " << Sum << endl;
    if(Sum > TotalSum) {
        cout << "NO" << '\n';
        return;
    }

    vector<vector<Node>> store(k);

    for (int i = 0; i < k; i++) {
        st.clear();
        if (i == 0) {
            ll x = findAllCombinations(0, b[i]);
            ll cnt = 0;
            for (auto m : st) {
                store[i].push_back(Node(m, i - 1, cnt++));
            }
        }
        else {
            ll cnt = 0;
            for (auto [mask, preI, preJ] : store[i - 1]) {
                st.clear();
                ll x = findAllCombinations(mask, b[i]);
                for (auto m : st) {
                    store[i].push_back(Node(m, i - 1, cnt));
                }
                cnt++;
            }
        }
    }

    Node temp;
    ll f = 0;
    for (auto [mask, i, j] : store[k - 1]) {
        if (mask == (1 << n) - 1) {
            temp = Node(mask, i, j);
            f = 1;
            break;
        }
    }

    if (f == 0) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';

    vector<ll> finalMask;
    while (temp.prevI != -1) {
        finalMask.push_back(temp.mask);
        temp = store[temp.prevI][temp.prevJ];
    }
    finalMask.push_back(temp.mask);
    reverse(vf(finalMask));
    ll mask = 0;
    for (int i = 0; i < (int)finalMask.size(); i++) {
        finalMask[i] = mask ^ finalMask[i];
        mask |= finalMask[i];
    }

    ll k = 0;
    for (auto mask : finalMask) {
        f = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                if (f)
                    cout << "+";
                cout << Table[a[i]];
                f = 1;
            }
        }
        cout << "->" << Table[b[k++]] << '\n';
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