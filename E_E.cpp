//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 08|04|2024 11:49:02            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

string canMakeAllZero(vector<int>& arr) {
    int xor_all = 0;
    for (int num : arr) {
        xor_all ^= num;
    }
    if (xor_all == 0) {
        return "YES";
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); ++i) {
        int num = arr[i];
        int modified_num = num ^ xor_all;
        if (modified_num != 0) {
            int left = 0, right = arr.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] == modified_num && mid != i) {
                    return "NO";
                }
                else if (arr[mid] < modified_num) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
    }
    if(arr.front() != 0)
        return "NO";
    return "YES";
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    if(n % 2 == 0){
        cout << "YES" << endl;
        return;
    }
    auto cal = [](int a, int b) { return a ^ b; };
    int XOR = accumulate(vf(arr), 0ll, cal);
    cout << (XOR == 0 ? "YES" : "NO") << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}