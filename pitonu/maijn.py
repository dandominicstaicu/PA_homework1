
### VF1

# def kth_min_cost_to_buy_products(prices, K):
#     N = len(prices)
#     if N == 0:
#         return -1

#     # dp list will store all costs up to each index
#     dp = [set() for _ in range(N + 1)]
#     dp[0].add(0)  # No cost if no products are bought

#     for i in range(1, N + 1):
#         # Buy the ith product alone
#         for cost in dp[i-1]:
#             dp[i].add(cost + prices[i-1])
        
#         if i > 1:  # Combine the last two products
#             for cost in dp[i-2]:
#                 dp[i].add(cost + prices[i-1] + prices[i-2] - min(prices[i-1], prices[i-2]) * 0.5)
        
#         if i > 2:  # Combine the last three products
#             for cost in dp[i-3]:
#                 dp[i].add(cost + prices[i-1] + prices[i-2] + prices[i-3] - min(prices[i-1], prices[i-2], prices[i-3]))

#     # Extract all unique costs from the final set
#     all_costs = sorted(dp[N])

#     return all_costs[K-1] if K <= len(all_costs) else -1


### VF2

# def kth_min_cost_to_buy_products(prices, K):
#     from heapq import heappush, heappop

#     N = len(prices)
#     if N == 0:
#         return -1

#     # Using a list of min-heaps to store the K smallest costs
#     dp = [[] for _ in range(N + 1)]
#     heappush(dp[1], prices[0])  # Single product purchase

#     if N > 1:
#         cost = prices[0] + prices[1] - min(prices[0], prices[1]) * 0.5
#         heappush(dp[2], prices[0] + prices[1])  # Buy first two products without discount
#         heappush(dp[2], cost)  # Buy first two products with discount

#     for i in range(3, N + 1):
#         current_costs = []

#         # Buy the ith product alone
#         for cost in dp[i-1]:
#             current_costs.append(cost + prices[i-1])
        
#         # Combine the last two products
#         for cost in dp[i-2]:
#             new_cost = cost + prices[i-1] + prices[i-2] - min(prices[i-1], prices[i-2]) * 0.5
#             current_costs.append(new_cost)

#         # Combine the last three products
#         if i > 2:
#             for cost in dp[i-3]:
#                 new_cost = cost + prices[i-1] + prices[i-2] + prices[i-3] - min(prices[i-1], prices[i-2], prices[i-3])
#                 current_costs.append(new_cost)

#         # Now only keep the smallest K unique costs in dp[i]
#         seen = set()
#         for cost in sorted(current_costs):
#             if len(seen) < K and cost not in seen:
#                 heappush(dp[i], cost)
#                 seen.add(cost)
#             if len(dp[i]) > K:  # Keep the size of heap to K
#                 heappop(dp[i])

#     # The K-th smallest cost might not always exist if there are fewer than K unique costs
#     if len(dp[N]) >= K:
#         return sorted(dp[N])[K-1]
#     return -1


import heapq

def kth_min_cost_to_buy_products(prices, K):
    N = len(prices)
    if N == 0 or K == 0:
        return -1
    
    # Min-heap to keep track of the lowest costs
    min_heap = [0]  # Start with zero cost (no products bought)

    for price in prices:
        current_costs = []
        size = len(min_heap)
        
        # Generate new costs from the heap
        for _ in range(size):
            cost = heapq.heappop(min_heap)
            # Buy the current product alone
            current_costs.append(cost + price)
        
        # Push the new costs to the heap while ensuring we do not exceed K elements
        for cost in current_costs:
            heapq.heappush(min_heap, cost)
            if len(min_heap) > K:  # Maintain heap size to be at most K
                heapq.heappop(min_heap)
    
    # After processing all products, sort the remaining costs in the heap
    sorted_costs = sorted(min_heap)

    # Return the K-th smallest cost or -1 if there are less than K costs
    return sorted_costs[K-1] if K <= len(sorted_costs) else -1



# Example usage
def main():
    with open('pitonu/input.in', 'r') as file:
        first_line = file.readline().strip()
        N, K = map(int, first_line.split())
        
        second_line = file.readline().strip()
        prices = list(map(int, second_line.split()))

    result = kth_min_cost_to_buy_products(prices, K)
    print(result)

if __name__ == "__main__":
    main()