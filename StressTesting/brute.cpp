#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

long long s[1234567];

int main() {
    int n;
    scanf("%d", &n);
    s[0] = 0;
    for (int i = 0; i < n; i++) {
        int foo;
        scanf("%d", &foo);
        s[i + 1] = s[i] + foo;
    }
    long long ans = 0;
    if (s[n] % 3 == 0) {
        long long u = s[n] / 3, v = 2 * s[n] / 3;
        long long cnt = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == v) {
                ans += cnt;
            }
            if (s[i] == u) {
                cnt++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
