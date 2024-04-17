def min_cost_to_buy_products(prices):
    N = len(prices)
    if N == 0:
        return 0.0

    # In case there are less than 3 products, we need to handle these cases separately
    if N == 1:
        return float(prices[0])
    elif N == 2:
        return prices[0] + prices[1] - min(prices[0], prices[1]) * 0.5
    
    # dp array to store the minimum cost to buy the first i products
    dp = [0] * (N + 1)
    dp[1] = prices[0]
    dp[2] = prices[0] + prices[1] - min(prices[0], prices[1]) * 0.5

    # Fill the dp array
    for i in range(3, N + 1):
        dp[i] = min(dp[i-1] + prices[i-1],  # Buy the i-th product alone
                    dp[i-2] + prices[i-2] + prices[i-1] - min(prices[i-2], prices[i-1]) * 0.5,  # Pair i-th with (i-1)th product
                    dp[i-3] + prices[i-3] + prices[i-2] + prices[i-1] - min(prices[i-3], prices[i-2], prices[i-1]))  # Trio with i, i-1, i-2

    # The answer for the minimum cost to buy all N products

    for i in range(0, N + 1):
        print(dp[i])

    print("\n")
    return dp[N]

def read_prices_from_file(filename):
    with open(filename, 'r') as file:
        first_line = file.readline().strip().split()
        N = int(first_line[0])  # Number of products
        K = int(first_line[1])  # Not used in your case
        
        # Read the second line where all prices are stored
        prices = list(map(int, file.readline().strip().split()))
        
    return prices

# Test the function with the given example
filename = './pitonu/input.in'
prices = read_prices_from_file(filename)
min_cost = min_cost_to_buy_products(prices)
print(f"The minimum cost to buy all products is: {min_cost}")