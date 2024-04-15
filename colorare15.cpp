#include <fstream>
#include <iostream>

using namespace std;

#define MOD 1000000007
#define H 'H'
#define V 'V'

int main() {
    ifstream fin ("colorare.in");
    ofstream fout ("colorare.out");

    int n;
    char prev_type = ' ';
    long long res = 1;

    int x;
    char t;


    

    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> x >> t;

        
        if (i == 0) {
            --x;
            if (t == H) {
                res = 6;
            } else {
                res = 3;
            }

            prev_type = t;
        }
        



        for (int j = 0; j < x; ++j) {
            if (prev_type == H) {
                if (t == H) {
                    res =  (res * 3) % MOD; // H dupa H
                } else {
                    res = (res * 1) % MOD; // V dupa H
                }
            } else { // if prev_type == V
                if (t == H) {
                    res = (res * 2) % MOD; // H dupa V
                } else {
                    res = (res * 2) % MOD; // V dupa V
                }
            }

            // cout << "res" << res << '\n';            

            prev_type = t;
        }

    }

    res = res % MOD;

    fout << res << '\n';

    return 0;
}
