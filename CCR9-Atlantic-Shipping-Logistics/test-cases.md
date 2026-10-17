# CCR9 - Test Cases

## Acceptance Criteria

```
student@9b36e72c8c17:/workspace/c/CCR9-Atlantic-Shipping-Logistics$ ./CCR9-Atlantic
Input the shipping box dimensions (in inches)
Length: 10
Width: 8
Height: 6
---------------------------------------------------
Atlantic Shipping and Logistics
Package Measurement Report
---------------------------------------------------
Length: 10.00 Width: 8.00 Height: 6.00
---------------------------------------------------
Volume: 480.00 cubic units
Surface Area: 376.00 square units
```

## Test Cases

### 1. Negative Dimension Input

| Aspect | Detail |
|--------|--------|
| **Description** | Trying to input a negative dimension |
| **Input** | `Length: -10` |
| **Expected Output** | `Invalid Input, make sure you input valid dimensions` |

### 2. Buffer Overflow (Exceeds Maximum Dimension)

| Aspect | Detail |
|--------|--------|
| **Description** | Trying to overload the dimension function (buffer overflow) |
| **Input** | `Length: 999999999999999999999999999999999999999999999999999999999999999999999` |
| **Expected Output** | `Invalid Input, dimension exceeds maximum allowed value` |
| **Retry** | `Length: Invalid Input, dimension exceeds maximum allowed value` |

### 3. Character Values as Dimensions

| Aspect | Detail |
|--------|--------|
| **Description** | Trying to input character values as dimensions |
| **Input** | `Length: ABC` |
| **Expected Output** | `Invalid Input, make sure you input valid dimensions` |

### 4. Zero as Dimension Input

| Aspect | Detail |
|--------|--------|
| **Description** | Trying to input zero to a dimension input |
| **Input** | `Length: 0` |
| **Expected Output** | `Invalid Input, make sure you input valid dimensions` |

### 5. Empty Input (Press Enter)

| Aspect | Detail |
|--------|--------|
| **Description** | Input nothing, just press enter when asked for dimension input |
| **Input** | `Length: <no input, just enter>` |
| **Expected Output** | `Invalid Input, make sure you input valid dimensions` |
