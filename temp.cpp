#include <bits/stdc++.h>

#include "testlib.h"
using namespace std;
typedef long long ll;

ll gen_random(ll l, ll r) { return rnd.next(l, r); }


int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    ll t = gen_random(1, 100);
    cout << t << "\n";
    while(t--) {
        ll n = gen_random(1LL, 100);
        ll m = gen_random(n, 110);
        ll x = gen_random(0, 100);
        ll y = gen_random(1, 100);
        cout << n << " " << m << " " << x << " " << y << "\n";
    }
}

/*

<#list 1..10 as s>
    Generator_Small  ${s} > $
</#list>

*/