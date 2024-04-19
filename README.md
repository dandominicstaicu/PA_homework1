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


## COLORING (Colorare)

### Solution Description

This solution uses a formula found in order to calculate in how many ways the painting can be colored. The painting has a width of 2 centimeters and an arbitrary length N centimeters, and must be colored using only 1x2 tiles. These tiles can be placed either horizontally or vertically but cannot share the same color if they are adjacent.

### Approach
- **Mathematical formula**: Implemented the linear computation of a formula based on what colors can it use in a rectangle based on the colors of the previous rectangles.
- **Complexity** The overall time complexity is O(N log M) where N is the number of pairs X and T read from the input and M is the maximum length encountered. Each loop iteration involves a call to mod_exp with a complexity of O(log⁡(x)), where x typically represents the number of blocks of the same type in sequence. The loop runs n times, where n is the number of different segments described in the input file. Each iteration processes one segment, and then reads the next segment from the file.


### Key Features

- **Efficient Coloring Strategy**: Implements a coloring strategy that respects adjacency restrictions and efficiently calculates the number of valid configurations.
- **Modular Arithmetic**: Uses modular arithmetic to manage large numbers resulting from combinatorial calculations, ensuring that results stay within feasible computational limits.
- **Dynamic Input Handling**: Dynamically adjusts to varying lengths of segments and their orientations as provided in the input.

### How does this work?

- **Initial Coloring**: Starts with the first segment and initializes the number of configurations based on whether it's horizontal or vertical. Horizontal tiles can be placed in 6 ways (3 colors in 2 possible orientations), and vertical tiles can be colored in 3 ways since each occupies exactly two stacked cells.
- **Propagation**: For each subsequent segment, the solution multiplies the existing number of configurations by the number of valid configurations for the new segment, taking into account the necessary change in color if the new segment is adjacent to the previous one.
- **Modular Reduction**: Throughout the calculation, all results are taken modulo 10^9 + 7 to keep computations manageable and within integer limits.

- **Examples**:
    1. If it has to place V after H, we have 3 zones touching, so for the new V we have only one available color
    2. If it places V after V, we have 2 possible colors for the new one, because it is touching only one previous zone
    3. If it has to place a H after a V, we have 2 ways of coloring those blocks. They only touch one previous block, and each other, so we have 2 available colours for those 2 blocks. We can color them one way, and than swap. Hence, 2 ways
    4. If it places an H after an H, we can determine 3 ways of colouring those 2 new H blocks, but these ways depend on the way the previous H blocks were coloured.

### Improvement over tests
**Initial Version**

- **Direct Calculation for Each Cell**: The initial approach attempted to calculate possible configurations for each cell within a segment, which was less efficient, especially for larger inputs.
- **No Optimization**: The first version did not efficiently use modular exponentiation, resulting in slower performance for larger values.

**Final Version**

- **Use of Exponentiation**: The final version uses modular exponentiation to quickly compute the number of ways to color large segments of the same type, significantly optimizing the processing time.**
- **Improved Transition Handling**: Switching between different types of segments (from horizontal to vertical and vice versa) is handled more efficiently, correctly multiplying by the number of ways to transition based on the previously used type.

