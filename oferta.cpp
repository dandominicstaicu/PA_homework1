#include <fstream>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

#include <set>
#include <vector>
#include <queue>

using namespace std;

#define MAX_LEN 10005

double min_cost(int *prices, int len) {
    if (len == 0)
        return -1;

    if (len == 1) {
        // return 111111;
        return 1.0 * prices[0];
    } else if (len == 2) {
        // return 333333;
        return prices[0] + prices[1] - min(prices[0], prices[1]) * 0.5;
    }

    double dp[MAX_LEN] = {0.0};

    dp[1] = prices[0] * 1.0;
    dp[2] = prices[0] * 1.0 + prices[1] * 1.0 - min(prices[0], prices[1]) * 0.5;

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

    // vector<int> prices(MAX_LEN);
    // int element;

    // fin >> n >> k;
    // for (int i = 0; i < n; ++i) {
    //     // fin >> prices[i];
    //     fin >> element;
    //     prices.push_back(element);
    // }

    fin >> n >> k;
    for (int i = 0; i < n; ++i) {
        fin >> prices[i];
    }

    double res = min_cost(prices, n);

    // double res = kth_min_cost(prices, n, k);

    // double res = kth_min_cost_to_buy_products(prices, k);

    fout << fixed << setprecision(1) << res;
    cout << fixed << setprecision(1) << res;


    fin.close();
    fout.close();
    return 0;
}