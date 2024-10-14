//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 30|05|2024 21:38:13            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using o_set_g = tree<T, null_type, greater<T>, rb_tree_tag,
                     tree_order_statistics_node_update>;
template <typename T>
using o_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,
                        tree_order_statistics_node_update>;
template <typename T>
using o_multiset_g = tree<T, null_type, greater_equal<T>, rb_tree_tag,
                          tree_order_statistics_node_update>;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

struct info {
    int tester = 0, programer = 0;
    bool isProgrammer = false;
};

void solve() {
    int n, m;
    cin >> n >> m;
    int N = n + m + 1;
    vector<int> pro(N + 1), tes(N + 1);
    vector<info> v(N + 1);
    o_set<int> pID, tID;
    for (int i = 1; i <= N; i++)
        cin >> pro[i];
    for (int i = 1; i <= N; i++) {
        cin >> tes[i];
        if (pro[i] > tes[i]) {
            v[i].isProgrammer = true;
            v[i].programer = v[i - 1].programer + 1;
            v[i].tester = v[i - 1].tester;
            pID.insert(i);
        }
        else {
            v[i].tester = v[i - 1].tester + 1;
            v[i].programer = v[i - 1].programer;
            tID.insert(i);
        }
    }
    vector<int> proPre(N + 1), tesPre(N + 1);
    for (int i = 1; i <= N; i++) {
        if (v[i].isProgrammer) {
            proPre[i] = proPre[i - 1] + pro[i];
            tesPre[i] = tesPre[i - 1];
        }
        else {
            proPre[i] = proPre[i - 1];
            tesPre[i] = tesPre[i - 1] + tes[i];
        }
    }
    vector<int> proSuf(N + 1), tesSuf(N + 1);
    if(v[N].isProgrammer)
        proSuf[N] = tes[N], tesSuf[N] = 0;
    else
        proSuf[N] = 0, tesSuf[N] = pro[N];
    for (int i = N - 1; i >= 1; i--) {
        if (v[i].isProgrammer) {
            proSuf[i] = proSuf[i + 1] + tes[i];
            tesSuf[i] = tesSuf[i + 1];
        }
        else {
            proSuf[i] = proSuf[i + 1];
            tesSuf[i] = tesSuf[i + 1] + pro[i];
        }
    }
    dbg(proPre);
    dbg(tesPre);
    dbg(proSuf);
    dbg(tesSuf);
    vector<int> ans;
    for (int i = 1; i <= N; i++){
        bool isPro = false;
        if(pID.find(i) != pID.end())
            isPro = true;
        int remPro = pID.size() - isPro;
        int remTes = tID.size() - !isPro;
        dbg(remPro, remTes);
        if(remPro >= n){
            // int SearchId = (isPro ? n : n - 1);
            int sum = 0;
            int SearchId = n - 1;
            int temp = *pID.find_by_order(SearchId);
            if(temp >= i)
                SearchId++, sum -= pro[i];
            int id = *pID.find_by_order(SearchId);
            dbg(sum);
            sum += proPre[id];
            dbg(id, proPre[id], sum);
            sum += proSuf[id] - tes[id];
            dbg(sum);
            sum += tesPre.back() - (!isPro ? tes[i] : 0ll);
            ans.push_back(sum);
        }
        else if(remTes >= m) {
            int sum = 0;
            int SearchId = m - 1;
            int temp = *tID.find_by_order(SearchId);
            if(temp >= i)
                SearchId++, sum -= tes[i];

            // int SearchId = (!isPro ? m : m - 1);
            int id = *tID.find_by_order(SearchId);
            dbg(sum);
            sum += tesPre[id];
            dbg(id, tesPre[id], sum);
            id++;
            sum += (tesSuf[id] - pro[id]);
            dbg(tesSuf[id], pro[id]);
            dbg(sum);
            sum += proPre.back() - (isPro ? pro[i] : 0ll);
            ans.push_back(sum);
        }
        dbg("--");
    }
    for(auto x : ans)
        cout << x << " ";
    cout << endl;
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