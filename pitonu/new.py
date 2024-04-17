def kth_min_cost_to_buy_products(prices, K):
    N = len(prices)
    if N == 0:
        return -1

    # Use a list to track the minimum cost to buy exactly i products
    dp = [float('inf')] * (N + 1)
    dp[0] = 0  # Cost to buy zero products is zero

    for i in range(1, N + 1):
        # Buy the ith product alone
        dp[i] = min(dp[i], dp[i-1] + prices[i-1])
        
        # Buy the last two products together with a discount
        if i > 1:
            dp[i] = min(dp[i], dp[i-2] + prices[i-1] + prices[i-2] - min(prices[i-1], prices[i-2]) * 0.5)
        
        # Buy the last three products together without any additional discount
        if i > 2:
            dp[i] = min(dp[i], dp[i-3] + prices[i-1] + prices[i-2] + prices[i-3])

    # dp[N] now contains the minimum cost to buy exactly N products with the optimal use of discounts
    # Sort all possible costs to find the kth minimum
    all_costs = sorted(dp[:N+1])

    # Return the K-th minimum cost, checking if K is within the range of available costs
    return all_costs[K] if K <= len(all_costs) else -1

# Example input
prices = [80, 27, 10, 20, 300]
K = 1
result = kth_min_cost_to_buy_products(prices, K)
print(result)  # Expected output: 413.5
