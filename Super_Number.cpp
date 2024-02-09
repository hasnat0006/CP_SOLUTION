//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma comment(linker, "/stack:102400000, 102400000")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

int n, m;
vector<int> ans(40);
bool checker;

int isvalid(int cur) {
    int sum = 0;
    for (int i = 0; i < cur; i++)
        sum = (sum * 10 + ans[i]) % cur;
    return sum;
}

void RECURSION_R_KORBO_NA(int k) {
    if (k == m) {
        checker = true;
        return;
    }
    if (checker)
        return;
    for (int j = 0; j < 10; j++) {
        ans[k] = j;
        if (k < n - 1 or (k >= n - 1 and !isvalid(k + 1))) {
            RECURSION_R_KORBO_NA(k + 1);
            if (checker)
                return;
        }
    }
}

void solve() {
    scanf("%d %d", &n, &m);
    ans.resize(40, 0);
    checker = false;
    for (int i = 1; i < 10; i++) {
        ans[0] = i;
        RECURSION_R_KORBO_NA(1);
        if (checker) {
            for (int i = 0; i < m; i++)
                printf("%d", ans[i]);
            printf("\n");
            return;
        }
    }
    printf("-1\n");
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        printf("Case %d: ", i);
        solve();
    }
    return 0;
}