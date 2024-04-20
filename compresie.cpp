#include <fstream>

using namespace std;

#define MAX_LEN 300005

// Function to calculate the sum of an array.
int array_sum(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }

    return sum;
}

// Function to find the maximum length of identical subarrays after transform
int find_max_len(int *a, int n, int *b, int m) {
    // First check if the total sums of arrays A and B are the same
    if (array_sum(a, n) != array_sum(b, m)) {
        return -1;  // if not equal, no solution can be found
    }

    int prefix_a[MAX_LEN] = {0};
    int prefix_b[MAX_LEN] = {0};

    // Compute prefix sums for arrays A and B
    for (int i = 0; i < n; ++i) {
        prefix_a[i + 1] = prefix_a[i] + a[i];
    }

    for (int i = 0; i < m; ++i) {
        prefix_b[i + 1] = prefix_b[i] + b[i];
    }

    int i = 1, j = 1;  // Pointers to traverse prefix arrays of A and B.
    int max_len = 0;

    // Loop through both prefix arrays to find matching segments.
    while (i <= n && j <= m) {
        if (prefix_a[i] == prefix_b[j]) {
            // Advance both pointers if corresponding prefix sums are equal.
            ++i;
            ++j;
            ++max_len;
        } else if (prefix_a[i] < prefix_b[j]) {
            // Advance pointer i if prefix sum of A is less than B
            ++i;
        } else {
            // Advance pointer j if prefix sum of B is less than A.
            ++j;
        }
    }

    // Return max_len if any match was found; otherwise, return -1.
    return (max_len > 0 ? max_len : -1);
}

int main() {
    ifstream fin("compresie.in");
    ofstream fout("compresie.out");

    int a[MAX_LEN], b[MAX_LEN], n, m;

    // read input
    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> a[i];
    }

    fin >> m;
    for (int i = 0; i < m; ++i) {
        fin >> b[i];
    }

    int maxlen = find_max_len(a, n, b, m);

    fout << maxlen << '\n';

    fin.close();
    fout.close();

    return 0;
}
