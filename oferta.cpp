#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX_LEN 10005

double min_cost(int *prices, int len) {
    if (len == 0)
        return 0;

    if (len == 1) {
        return (double)prices[0]; 
    } else if (len == 2) {
        return prices[0] + prices[1] - min(prices[0], prices[1]) * 0.5;
    }

    double dp[MAX_LEN] = {0};
    dp[1] = prices[0];
    dp[2] = prices[0] + prices[1] - min(prices[0], prices[1]) * 0.5;

    for (int i = 3; i < len + 1; ++i) {
        double last_product = dp[i - 1] + prices[i - 1];
        double last_2 = dp[i - 2] + prices [i - 2] + prices [i - 1] - min(prices[i - 2], prices[i - 1]) * 0.5;

        int min_2_prices = min(prices[i - 3], prices[i - 2]);
        double last_3 = dp[i - 3] + prices[i - 3] + prices[i - 2] + prices[i - 1] - min(min_2_prices, prices[i - 1]);
    
        double min_last_2_3 = (last_2 < last_3) ? last_2 : last_3;
        dp[i] = (last_product < min_last_2_3) ? last_product : min_last_2_3;
    }

    return dp[len];
}

int main(void) {
    ifstream fin("oferta.in");
    ofstream fout("oferta.out");

    int n, k;
    int prices[MAX_LEN];

    fin >> n >> k;
    for (int i = 0; i < n; ++i) {
        fin >> prices[i];
    }

    double res = min_cost(prices, n);

    fout << res;
    cout << res;


    fin.close();
    fout.close();
    return 0;
}