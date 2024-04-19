# Tema 1 Proiectarea Algoritmilor

### Staicu Dan-Dominic
### 321CA 2024

## SERVERS (Servere)

### Solution Description
The solution involves a binary search over possible current values to find the optimal current that maximizes the minimum power among all servers. The `compute_power` function calculates the minimum power for a given current by considering power losses due to mismatches between required and supplied currents.

### Approach
- **Binary Search**: Implemented to efficiently find the optimal current value within a predefined range, from 1 to the maximum required current of any server.
- **Complexity**: The overall time complexity is O(N log M) where N is the number of servers and M is the range of potential current values.

### Key Features
- **Precision Handling**: Calculations are carefully handled with floating-point precision to ensure accurate results up to one decimal place.
- **Robust and Scalable**: Efficiently handles up to 100,000 servers with diverse power and current requirements.

### How does this work?
- **Initial range**: The search range for the optimal current is set between 1 and max_ci, where max_ci is the maximum current requirement of any server. This range is reasonable because supplying less than 1 unit of current or more than any server's maximum requirement doesn't yield better outcomes due to the linear reduction in computing power with current mismatch.

- **Midpoint Calculation and Evaluation**: At each step of the binary search the midpoint of the current range (left to right) is calculated. The function compute_power is used twice: once at mid and once slightly above mid (mid + EPS). These two calculations determine the effect on the minimal server power if the current supply is slightly increased.

- **Direction Decision**: The binary search adjusts its range based on the comparison if the power at mid + 1e-6 is greater than or equal to the power at mid, it implies that increasing the current might improve or maintain the minimal power output, so the search range is adjusted to left = mid. If the power at mid is greater, then supplying more current beyond this point leads to a decrease in minimal power, hence the search shifts to right = mid.

- **Precision and Termination**: The loop continues until the difference between left and right is less than a very small epsilon (1e-6), ensuring high precision. This st


