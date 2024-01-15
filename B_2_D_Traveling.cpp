    #ifndef _GLIBCXX_NO_ASSERT
    #include <cassert>
    #endif
    #include <cctype>
    #include <cerrno>
    #include <cfloat>
    #include <ciso646>
    #include <climits>
    #include <clocale>
    #include <cmath>
    #include <csetjmp>
    #include <csignal>
    #include <cstdarg>
    #include <cstddef>
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #include <ctime>
    #if __cplusplus >= 201103
    #include <ccomplex>
    #include <cfenv>
    #include <cinttypes>
    #include <cstdalign>
    #include <cstdbool>
    #include <cstdint>
    #include <ctgmath>
    #include <cuchar>
    #include <cwchar>
    #include <cwctype>
    #endif
    #include <algorithm>
    #include <bitset>
    #include <complex>
    #include <deque>
    #include <exception>
    #include <fstream>
    #include <functional>
    #include <iomanip>
    #include <ios>
    #include <iosfwd>
    #include <iostream>
    #include <istream>
    #include <iterator>
    #include <limits>
    #include <list>
    #include <locale>
    #include <map>
    #include <memory>
    #include <new>
    #include <numeric>
    #include <ostream>
    #include <queue>
    #include <set>
    #include <sstream>
    #include <stack>
    #include <stdexcept>
    #include <streambuf>
    #include <string>
    #include <typeinfo>
    #include <utility>
    #include <valarray>
    #include <vector>
    #if __cplusplus >= 201103L
    #include <array>
    #include <atomic>
    #include <chrono>
    #include <codecvt>
    #include <condition_variable>
    #include <forward_list>
    #include <future>
    #include <initializer_list>
    #include <mutex>
    #include <random>
    #include <ratio>
    #include <regex>
    #include <scoped_allocator>
    #include <system_error>
    #include <thread>
    #include <tuple>
    #include <type_traits>
    #include <typeindex>
    #include <unordered_map>
    #include <unordered_set>
    #endif
    #if __cplusplus >= 201402L
    #include <shared_mutex>
    #endif
    #ifndef ONLINE_JUDGE
    #include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
    #else
    #define dbg(x...)
    #define dbgc(x...)
    #endif
    using namespace std;
    #define int long long
    #define float long double
    #define endl "\n"
    const int INFI = 1e18;
    const int MOD = 1e9 + 7;

    void ami_keno_kiso_pari_na() {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i] = {x, y};
        }
        if (a <= m and b <= m) {
            cout << 0 << endl;
            return;
        }
        if (a <= m and b > m) {
            int cost = 1e18, id = -1;
            for (int i = 0; i < m; i++) {
                // jekono prime theke end point
                int temp = abs(arr[i].first - arr[b - 1].first) +
                        abs(arr[i].second - arr[b - 1].second);
                if (temp < cost)
                    cost = temp, id = i;
            }
            cout << cost << endl;
        }
        else if (a > m and b <= m) {
            int cost = 1e18;
            for (int i = 0; i < m; i++) {
                int temp = abs(arr[a - 1].first - arr[i].first) +
                        abs(arr[a - 1].second - arr[i].second);
                dbg(arr[a - 1], arr[i]);
                dbg(temp);
                if (temp < cost)
                    cost = temp;
            }
            cout << cost << endl;
        }
        else {
            int cost = 1e18, id = -1;
            for (int i = 0; i < m; i++) {
                // jekono prime theke end point
                int temp = abs(arr[i].first - arr[b - 1].first) +
                        abs(arr[i].second - arr[b - 1].second);
                if (temp < cost)
                    cost = temp, id = i;
            }
            int cost2 = 1e18;
            for (int i = 0; i < m; i++) {
                // jekono prime theke end point
                int temp = abs(arr[a - 1].first - arr[i].first) +
                        abs(arr[a - 1].second - arr[i].second);
                if (temp < cost2)
                    cost2 = temp, id = i;
            }
            int temp = abs(arr[a - 1].first - arr[b - 1].first) +
                    abs(arr[a - 1].second - arr[b - 1].second);
            cout << min(temp, cost + cost2) << endl;
        }
    }
    int32_t main() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int test_case = 1;
        cin >> test_case;
        // cin.ignore();
        while (test_case--) {
            ami_keno_kiso_pari_na();
        }
        return 0;
    }