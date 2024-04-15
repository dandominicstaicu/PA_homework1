#include <fstream>
#include <iomanip>
#include <cmath>


#define MAX_LEN 100005
#define MAX_P_C 10e9 + 5

using namespace std;

double compute_power(double *p, double *c, int srv_cnt, double current) {
    double min_power = MAX_P_C;

    for (int i = 0; i < srv_cnt; ++i) {
        double power = p[i] - abs(c[i] - current);

        if (min_power > power)
            min_power = power;
    }

    return min_power;
}

int main(void) {
    ifstream fin("servere.in");
    ofstream fout("servere.out");

    int srv_cnt;
    double p[MAX_LEN], c[MAX_LEN];
    double max_ci = 0;
    // double max_current_def = -MAX_P_C;

    fin >> srv_cnt;
    for (int i = 0; i < srv_cnt; ++i)
        fin >> p[i];

    for (int i = 0; i < srv_cnt; ++i) {
        fin >> c[i];

        // search for the highest necesary current
        if (c[i] > max_ci) {
            max_ci = c[i];
        }

        // double deficit = p[i] - c[i];
        // if (deficit > max_current_def) {
        //     max_current_def = deficit;
        // }
    }

    double left = 1;
    double right = max_ci;

    while (right - left > 1e-6) {
        double mid = (left + right) / 2;

        if (compute_power(p, c, srv_cnt, mid)
            < compute_power(p, c, srv_cnt, mid + 1e-6)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    fout << fixed << setprecision(1);
    fout << compute_power(p, c, srv_cnt, (left + right) / 2) << '\n';

    return 0;
}
