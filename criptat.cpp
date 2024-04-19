#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


// code from th PA lab on ocw

// n   = numărul de obiecte din colecție
// W   = capacitatea maximă a rucsacului
// (w[i], p[i]) = caracteristicile obiectului i ($i = 1 : n)
int rucsac(int n, int W, vector<int> &w, vector<int> &p) {
    // dp este o matrice de dimensiune (n + 1) x (W + 1)
    // pentru că folosim dp[0][*] pentru mulțimea vidă
    //                   dp[*][0] pentru situația în care ghiozdanul are
    //                            capacitate 0
    vector< vector<int> > dp(n + 1, vector<int>(W + 1, 0));

    // cazul de bază
    for (int cap = 0; cap <= W; ++cap) {
        dp[0][cap] = 0;
    }

    // cazul general
    for (int i = 1; i <= n; ++i) {
        for (int cap = 0; cap <= W; ++cap) {
            // nu folosesc obiectul i => e soluția de la pasul i - 1
            dp[i][cap] = dp[i-1][cap];

            // folosesc obiectul i, deci trebuie să rezerv w[i] unități în
            // rucsac
            // înseamnă ca înainte trebuie să ocup maxim cap - w[i] unități
            if (cap - w[i] >= 0) {
                int sol_aux = dp[i-1][cap - w[i]] + p[i];

                dp[i][cap] = max(dp[i][cap], sol_aux);
            }
        }
    }

    int max_value = 0;
    for (int j = 0; j <= W; ++j) {
        if (dp[n][j] - j > dp[n][j] / 2) {
            max_value = dp[n][j];
        }
    }

    cout << '\n';

    return max_value;
}

int main(void) {
    ifstream fin("criptat.in");
    ofstream fout("criptat.out");

    int n;
    set<char> alphabet;

    vector<vector<char>> words(1005, vector<char>(10005, 0));

    fin >> n;
    for (int i = 0; i < n; ++i) {
        char word[10005];
        fin >> word;

        words[i].assign(word, word + strlen(word));

        for (int j = 0; words[i][j]; ++j) {
            alphabet.insert(words[i][j]);
        }
    }

    vector<int> lengths(n + 1, 0);
    int idx = 0;

    for (auto it = alphabet.begin(); it != alphabet.end(); ++it) {
        // weight = nr de litere care nu sunt it
        // p = lungimea cuvantului
        vector<int> p(n + 1, 0);  // len of the words
        vector<int> w(n + 1, 0);  // how many letters are not it
        int sum_w = 0;

        // build the p and w vectors
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; words[i - 1][j]; ++j) {
                if (words[i - 1][j] != *it) {
                    ++w[i];  // how many letters of word i are not it
                }

                ++p[i];  // len of the word i
            }
        }

        for (int i = 0; i < n; ++i) {
            sum_w += w[i];
        }

        lengths[idx] = rucsac(n, sum_w, w, p);
        idx++;
    }

    auto max_it = max_element(lengths.begin(), lengths.end());

    fout << *max_it << "\n";

    fin.close();
    fout.close();

    return 0;
}
