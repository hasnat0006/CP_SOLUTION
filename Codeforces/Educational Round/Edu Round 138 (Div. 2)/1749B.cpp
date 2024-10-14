#include <bits/stdc++.h>
#define int long long
#define float double
// using namespace std;
void solve() {
    int n;
    std ::cin >> n;
    bool f = false;
    int health[n], spell[n];
    for (int i = 0; i < n; i++)
        std ::cin >> health[i];
    for (int i = 0; i < n; i++)
        std ::cin >> spell[i];
    int sec = 0, id = -1;
    int *mx;
    mx = std::max_element(spell, spell + n);
    std::vector<std::pair<int, int>> monster;
    for (int i = 0; i < n; i++)
        monster.push_back(std::make_pair(health[i], spell[i]));
    sort(monster.rbegin(), monster.rend());
    for (int i = 0; i < n; i++)
        sec += monster[i].first + monster[i].second;
    std ::cout << (sec - *mx) << std::endl;
    return;
}
int32_t main() {
    int t = 1;
    std ::cin >> t;
    while (t--)
        solve();
    return 0;
}