
# CCR2 - Sunrise Coffee Company

In-class assignment for COP-3515.

## Overview

A C program that tracks coffee sales for a 5-hour workday. The program prompts the user to enter the number of cups of coffee sold each hour, validates all inputs, and displays a summary of the day's sales.

## Features

- **5 Hour Tracking**: Records coffee sales for each of 5 hours
- **Input Validation**:
  - Rejects decimal numbers (e.g., `5.123`)
  - Rejects non-numeric input (e.g., `ABC`)
  - Rejects negative numbers (e.g., `-10`)
  - Handles overflow for very large numbers (e.g., `999999999999999999999999999999`)
  - Allows empty input with confirmation to set value to `0`
- **Progress Feedback**: Shows remaining hours after each entry
- **Summary Output**: Displays total sales and per-hour breakdown

## How It Works

1. The program displays "Sunrise Coffee Company"
2. For each of the 5 hours:
   - Prompts for the number of cups sold
   - Validates the input (must be a non-negative integer)
   - If empty input is given, asks for confirmation to set to `0`
   - Shows how many hours remain
3. After all 5 hours are entered, displays:
   - Total coffee sold for the 5-hour period
   - Per-hour breakdown

## Example Run

```
Sunrise Coffee Company
Enter the amount of coffee sold in the first hour: 12
    Number stored, 4 left for the day
Enter the amount of coffee sold in the second hour: 6
    Number stored, 3 left for the day
Enter the amount of coffee sold in the third hour: 0
    Number stored, 2 left for the day
Enter the amount of coffee sold in the fourth hour: 23
    Number stored, 1 left for the day
Enter the amount of coffee sold in the fifth hour: 9
    Number stored, 0 left for the day

Total Coffee sold for the 5 hour period of day: 50
Hour 1: 12  Hour 2: 6  Hour 3: 0  Hour 4: 23  Hour 5: 9
```

## Building

```bash
gcc -g main.c -o CCR2-sunrise
```

## Running

```bash
./CCR2-sunrise
```

## Test Cases

All test cases are documented in [test-cases.md](test-cases.md).

| Test Case | Description | Status |
|-----------|-------------|--------|
| Valid input | Enter valid positive integers | ✅ |
| Empty input | Press Enter, confirm with 'y' to set to 0 | ✅ |
| Non-numeric input | Enter letters (e.g., `ABC`) | ✅ |
| Decimal input | Enter decimal numbers (e.g., `5.123`) | ✅ |
| Negative input | Enter negative numbers (e.g., `-10`) | ✅ |
| Overflow input | Enter extremely large numbers | ✅ |

## Requirements

See [requirments.md](requirments.md) for full requirements.
