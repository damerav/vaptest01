# FormatArray Solution in C++

## Problem Description
Given an array of integers and an integer K, output a string that presents the integers in tabular form where:
- Each row contains exactly K numbers (the last row may contain fewer)
- Numbers are right-aligned within cells
- Each cell is surrounded by borders using `+`, `-`, and `|` characters
- Cell width adjusts to accommodate the widest number in the array
- Adjacent rows share edges

## Algorithm

1. **Find Maximum Width**: Iterate through all numbers to find the maximum digit count
2. **Process Rows**:
   - Divide the array into chunks of size K
   - For each row:
     - Create a border of `+` and `-` characters
     - Format numbers right-aligned within cells
     - Add vertical separators `|` between cells
3. **Handle Last Row**: The last row may have fewer than K elements

## Time Complexity
- O(N) where N is the number of elements in the array
- Finding max width: O(N)
- Building output string: O(N)

## Space Complexity
- O(N * W) where W is the width of the largest number
- Output string size is proportional to number of elements and their width

## Example

Input: A = [4, 35, 80, 123, 12345, 44, 8, 5, 24, 3], K = 4

Output:
```
+-----+-----+-----+-----+
|    4|   35|   80|  123|
+-----+-----+-----+-----+
|12345|   44|    8|    5|
+-----+-----+
|   24|    3|
+-----+-----+
```

## Implementation Details

- Uses C++ `std::string` and `std::vector` for efficient string building
- `to_string()` for integer to string conversion
- `string(n, char)` constructor for creating repeated characters
- Right-alignment achieved by calculating padding and adding spaces

## Files
- `solution.cpp`: Contains the Solution class with the main algorithm and test cases

## Building and Running

```bash
# Compile
g++ -std=c++11 -o solution solution.cpp

# Run
./solution
```

## Assumptions
- N is within range [1..200]
- K is within range [1..1,000,000,000]
- Array elements are within range [0..1,000,000,000]
- Focus on correctness (performance is not critical)
