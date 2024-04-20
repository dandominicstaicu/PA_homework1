#include <fstream>
#include <iomanip>
#include <cmath>

#define MAX_LEN 100005
#define MAX_P_C 10e9 + 5
#define EPS 1e-6

using namespace std;

// Compute the minimum power of a server when supplied with a given amount
double compute_power(double *p, double *c, int srv_cnt, double current) {
    double min_power = MAX_P_C;

    for (int i = 0; i < srv_cnt; ++i) {
        // Calculate power decrement from current mismatch
        double power = p[i] - abs(c[i] - current);

        // Update minimum power if the new computed power is lower
        if (min_power > power)
            min_power = power;
    }

    return min_power;
}

int main(void) {
    ifstream fin("servere.in");
    ofstream fout("servere.out");

    // Arrays to store power and current of servers
    double p[MAX_LEN], c[MAX_LEN];

    // To store maximum current needed by any server
    double max_ci = 0;

    int srv_cnt;
    fin >> srv_cnt;
    for (int i = 0; i < srv_cnt; ++i)
        fin >> p[i];

    for (int i = 0; i < srv_cnt; ++i) {
        fin >> c[i];

        // Search for the highest necesary current
        if (c[i] > max_ci) {
            // Save the maximum current requirement
            max_ci = c[i];
        }
    }

    // Use binary search within range [1, max_ci]
    double left = 1;
    double right = max_ci;

    // Binary search to find the optimal amount that maximizes the min power
    while (right - left > EPS) {
        double mid = (left + right) / 2;

        // Decide the direction of binary search based on comparing
        // power at mid and mid + epsilon
        if (compute_power(p, c, srv_cnt, mid)
            < compute_power(p, c, srv_cnt, mid + EPS)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    fout << fixed << setprecision(1);  // Set decimal precision
    fout << compute_power(p, c, srv_cnt, (left + right) / 2) << '\n';

    return 0;
}
