// C++ Program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to print the maximum rooks
// and their positions
int pos[1000][1000];
void countRooks(int n, int k) {
    int row[n] = {0};
    int col[n] = {0};

    // Initialize row and col array
    for (int i = 0; i < n; i++) {
        row[i] = 0;
        col[i] = 0;
    }

    // Marking the location of
    // already placed rooks
    for (int i = 0; i < k; i++) {
        row[pos[i][0] - 1] = 1;
        col[pos[i][1] - 1] = 1;
    }

    int res = n - k;

    // Print number of non-attacking
    // rooks that can be placed
    cout << res << " " << endl;

    // To store the placed rook
    // location
    int ri = 0, ci = 0;
    while (res-- > 0) {
        // Print lexicographically
        // smallest order
        while (row[ri] == 1) {
            ri++;
        }
        while (col[ci] == 1) {
            ci++;
        }
        cout << (ri + 1) << " " << (ci + 1) << " " << endl;
        ri++;
        ci++;
    }
}

// Driver Code
int main() {
    // Size of board
    int N;
    cin >> N;
    // Number of rooks already placed
    int K = 0;

    // Position of rooks

    // Function call
    countRooks(N, K);
}
// This code is contributed by shikhasingrajput
