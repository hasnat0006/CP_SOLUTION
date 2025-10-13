#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    // cin >> n;
    auto is_valid = [](ll num, ll n) {
        bitset<32> b(num);
        string a = "";
        ll f = 0;
        for (int i = 31; i >= 0; i--) {
            if (b[i])
                f = 1;
            if (f) {
                a.push_back((char)(b[i] + '0'));
            }
        }
        string rev = a;
        reverse(vf(rev));
        bitset<32> A(a), B(rev);
        if ((A ^ B) == n) {
            return true;
        }
        return false;
    };
    for (int k = 0; k <= 500; k++) {
        bitset<10> b(k);
        // dbg(b);
        ll c = 0, f1 = 0, f2 = 0;
        for (int i = 1; i <= 5000; i++) {
            f1 += is_valid(i, k);
            if (f1)
                break;
        }
        // if (!f1) {
        //     dbg(k, b);
        // }
        // continue;
        ll one = 0, zero = 0, con_one = 0, temp = 0, con_zero = 0, t2 = 0;
        for (int i = 31; i >= 0; i--) {
            if (b[i]) {
                one++;
                c++;
                t2 = 0;
                temp++;
            }
            else if (c > 0) {
                t2++;
                zero++;
                if (temp > 1 or c == 1)
                    con_one += temp;
                temp = 0;
                c++;
            }
            // con_one = max(con_one, temp);
            con_zero = max(con_zero, t2);
        }
        con_one += temp;
        f2 = (one % 2 == 0);
        if (f2) {
            if (one == con_one) {
                if (con_one > zero * 4)
                    f2 = 0;
            }
            else if ((one != con_one) and
                (one - con_one > zero or con_one >= (c + 1) / 2))
                f2 = 0;
        }
        if (f1 != f2) {
            dbg(k, f1, f2);
            dbg(one, zero, c, con_one, con_zero);
            dbg(b);
        }
        dbg("--------------------");
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
        dbg("------------");
    }
    return 0;
}