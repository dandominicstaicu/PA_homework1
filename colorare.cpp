#include <fstream>

using namespace std;

#define MOD 1000000007
#define H 'H'
#define V 'V'

long long mod_exp(long long base, int exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) {  // exp % 2 == 1
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;  // exp /= 2
    }
    return result;
}

int main() {
    ifstream fin("colorare.in");
    ofstream fout("colorare.out");

    int n;
    char prev_type = ' ';
    long long res = 1;

    int x;
    char t;

    fin >> n;
    fin >> x >> t;

    // initial coloring
    if (t == H) {
        res = 6;
    } else {
        res = 3;
    }

    // save the type of that block
    prev_type = t;

    // already placed the 1st block of the given sequence
    --x;

    for (int i = 0; i < n; ++i) {
        // Check if it starts a seq of a diferent type
        if (prev_type != t) {
            if (t == V) {
                res = (res * 1) % MOD;  // V after H
            } else {
                res = (res * 2) % MOD;  // H after V
            }

            // already placed the 1st block of the given sequence
            --x;
        }

        if (t == H) {  // seq of H after a seq of H
            res = (res * mod_exp(3, x)) % MOD;
        } else if (t == V) {  // seq of V after a seq of V
            res = (res * mod_exp(2, x)) % MOD;
        }

        // save the prev type
        prev_type = t;

        // read the next seq
        fin >> x >> t;
    }

    // ensure the final result is in modular arithmetic
    res = res % MOD;

    fout << res << '\n';

    fin.close();
    fout.close();
    return 0;
}
