// C++ program to print largest contiguous array sum
#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int> &a) {
    int size = a.size();
    int maxTill = INT_MIN, maxEnd = 0;
    for (int i = 0; i < size; i++) {
        maxEnd = maxEnd + a[i];
        if (maxTill < maxEnd)
            maxTill = maxEnd;
        if (maxEnd < 0)
            maxEnd = 0;
    }
    return maxTill;
}

int main() {
    vector<int> a = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = a.size();

    // Function Call
    int max_sum = maxSubArraySum(a);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}
