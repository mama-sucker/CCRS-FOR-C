# Test Cases

## Acceptance Criteria

```bash
student@9b36e72c8c17:/workspace/c/CCR8-Sunshine-Elementary-School$ ./CCR8-Sunshine
===============================================
Sunshine Elementary School
Grade Adjustment Report
===============================================

Original Grade: 84
Total Credit: 5

===============================================
Sunshine Elementary School
Grade Adjustment Report
===============================================
Original Grade: 84.0
Extra Credit: 5.0
Corrected Grade: 89.0
===============================================
```

## Test Cases

### Test Case 1: Non-Numeric Input

**Question:** What if the (Original Grade) is a character instead of a number?

- **Input:** `Original Grade: ABC`
- **Expected Output:** `Error: Invalid input. Please enter a non-negative number (0-100)`

### Test Case 2: Overflow on Original Grade

**Question:** What if I try to overflow the (Original Grade)?

- **Input:** `Original Grade: 100.99999999999999999999999999999999999999999999999`
- **Expected Output:** `Error: Original grade cannot exceed 100`

### Test Case 3: Combined Total Exceeds 120

**Question:** What if both (Original Grade) & (Total Credit) are going to exceed 120 total?

- **Input:** `Original Grade: 100`, `Total Credit: 50`
- **Expected Output:** `Error: Total (Original + Credit) cannot exceed 120`

### Test Case 4: Negative Grade

**Question:** What if I try to input a negative grade?

- **Input:** `Original Grade: -100`
- **Expected Output:** `Error: Invalid input. Please enter a non-negative number (0-100)`
