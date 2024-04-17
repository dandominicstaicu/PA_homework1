#include <iostream>
#include <fstream>

using namespace std;

#define MAX_LEN 300005

int array_sum(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }

    return sum;
}

int find_max_len(int *a, int n, int *b, int m) {
    if (array_sum(a, n) != array_sum(b, m)) {
        return -1;
    }

    int prefix_a[MAX_LEN] = {0};
    int prefix_b[MAX_LEN] = {0};

    for (int i = 0; i < n; ++i) {
        prefix_a[i + 1] = prefix_a[i] + a[i];
    }

    for (int i = 0; i < m; ++i) {
        prefix_b[i + 1] = prefix_b[i] + b[i];
    }

    int i = 1, j = 1;
    int max_len = 0;

    while (i <= n && j <= m) {

        if (prefix_a[i] == prefix_b[j]) {
            ++i;
            ++j;
            ++max_len;
        } else if (prefix_a[i] < prefix_b[j]) {
            ++i;
        } else {
            ++j;
        }
    }

    return (max_len > 0 ? max_len : -1);

}

int main() {
    ifstream fin("compresie.in");
    ofstream fout("compresie.out");

    int a[MAX_LEN], b[MAX_LEN], n, m;

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
