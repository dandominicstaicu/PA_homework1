#include <fstream>

using namespace std;

#define MOD 1000000007
#define H 'H'
#define V 'V'

long long mod_exp(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) { 
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD; 
        exp >>= 1;
    }
    return result;
}

int main() {
    ifstream fin ("colorare.in");
    ofstream fout ("colorare.out");

    int n;
    char prev_type = ' ';
    long long res = 1;

    int x;
    char t;

    fin >> n;
    fin >> x >> t;

    //culoarea initiala
    if (t == H) {
        res = 6;
    } else {
        res = 3;
    }
            
    prev_type = t;
    --x;

    for (int i = 0; i < n; ++i) {
        if (prev_type != t) {
            if (t == V) {
                res = (res * 1) % MOD; // V dupa H
            } else {
                res = (res * 2) % MOD; // H dupa V
            }

            --x;
        }

        if (t == H) { //secvente de H uri dupa H
            res = (res * mod_exp(3, x)) % MOD;
        }

        if (t == V) { // secv de V uri dupa V
            res = (res * mod_exp(2, x)) % MOD;
        }
        
        prev_type = t;

        fin >> x >> t;
    }

    res = res % MOD;

    fout << res << '\n';

    return 0;
}
