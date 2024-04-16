def find_kth_smallest_unique_cost(prices, k):
    from heapq import heappush, heappop

    N = len(prices)
    if N == 0:
        return -1

    # Initialize dp as a list of empty sets to store the cumulative costs up to each item
    dp = [set() for _ in range(N + 1)]
    dp[0].add(0)  # Initialize with a base case: cost of 0 with 0 items
    unique_costs = set()

    # Generate costs dynamically
    for i in range(N):
        heap = []
        # Buy current item alone or with combinations
        for j in range(max(0, i - 2), i + 1):
            if j == i - 1:  # Pair with the previous one
                cost = prices[i] + prices[j] - min(prices[i], prices[j]) * 0.5
                if i > 1:
                    for previous_cost in dp[j]:
                        heappush(heap, previous_cost + cost)
            elif j == i - 2:  # Trio with two previous ones
                cost = prices[i] + prices[j] + prices[j+1] - min(prices[i], prices[j], prices[j+1])
                for previous_cost in dp[j]:
                    heappush(heap, previous_cost + cost)
            elif j == i:  # Buying current item alone
                for previous_cost in dp[j]:
                    heappush(heap, previous_cost + prices[i])

        # Flush heap to dp[i + 1] and unique_costs
        while heap:
            new_cost = heappop(heap)
            if new_cost not in dp[i + 1]:
                dp[i + 1].add(new_cost)
                unique_costs.add(new_cost)

    # All costs are stored in unique_costs set
    sorted_costs = sorted(unique_costs)
    if k-1 < len(sorted_costs):
        return sorted_costs[k-1]
    else:
        return -1

# Test the function with the given setup, for K = 3
example_prices = [80, 27, 10, 20, 300]
print(find_kth_smallest_unique_cost(example_prices, 3))
