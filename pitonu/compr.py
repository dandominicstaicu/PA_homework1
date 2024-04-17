def find_maximum_common_subarray_length(n, A, m, B):
    # Step 1: Calculate prefix sums for both arrays
    prefix_A = [0] * (n + 1)
    prefix_B = [0] * (m + 1)
    
    # prefix_A[0] = A[0]
    # prefix_B[0] = B[0]


    for i in range(n):
        prefix_A[i + 1] = prefix_A[i] + A[i]
        # print(prefix_A[i + 1])
    # print(prefix_A[0])

    print()
    print()
    for i in range(m):
        prefix_B[i + 1] = prefix_B[i] + B[i]
        # print(prefix_B[i + 1])


    # Step 2: Utilize two pointers technique to find maximum common subarray sum
    i, j = 1, 1  # Start from 1 because prefix sums start from index 1 for actual sums
    max_length = 0
    
    while i <= n and j <= m:
        # Sum from last found indexes to current i, j (exclusive)
        # current_sum_A = prefix_A[i] - prefix_A[i - 1]
        # current_sum_B = prefix_B[j] - prefix_B[j - 1]
        
        if prefix_A[i] == prefix_B[j]:
            # Since the entire sums up to i and j are equal, increment pointers to find further sync
            print("i ", i)
            print("j ", j)

            
            i += 1
            j += 1
            max_length += 1
        elif prefix_A[i] < prefix_B[j]:
            i += 1
        else:
            j += 1
    
    return max_length if max_length > 0 else -1

# Test the function with the provided example
n = 6
A = [11, 2, 2, 1, 8, 6]
m = 7
B = [3, 8, 2, 1, 2, 11, 3]


print(find_maximum_common_subarray_length(n, A, m, B))
