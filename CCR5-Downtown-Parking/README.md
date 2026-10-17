# CCR5 - Downtown Parking Services

A C program for COP-3515 (Programming in C) that simulates a parking garage billing system for Downtown Parking Services.

## Overview

This application calculates parking fees based on the duration each vehicle stays in the garage. It provides a text-based user interface (TUI) where users can input parking hours for multiple vehicles and receive a detailed billing summary.

## Features

- **Initial Vehicle Input**: Collects parking hours for 3 vehicles by default
- **Additional Vehicles**: Option to add more vehicles after the initial 3
- **Flexible Time Input**: Supports fractional hours (e.g., 2.5 hours)
- **Smart Billing**:
  - $2.00 per hour
  - $0.50 per quarter-hour (for partial hours, rounded up to nearest 15 minutes)
  - Maximum daily charge capped at $50.00
  - Zero charge for zero hours parked
- **Input Validation**:
  - Accepts only non-negative numbers
  - Rejects negative values
  - Limits decimal places to 10 for safety
  - Prevents buffer overflow (max 256 characters)
  - Rejects invalid characters and multiple decimal points
- **Comprehensive Summary**:
  - Individual vehicle charges
  - Total vehicles processed
  - Total revenue collected
  - Average parking fee (rounded to 2 decimal places)

## Building

Compile the program with GCC, linking the math library:

```bash
gcc main.c -o CCR5-Downtown-Parking -lm
```

## Running

```bash
./CCR5-Downtown-Parking
```

## Usage

1. Enter parking hours for each of the 3 initial vehicles
2. When prompted "More vehicles? (y/n)", enter:
   - **y** - Add more vehicles (continue entering hours)
   - **n** - View the parking summary
3. Review the detailed billing summary

### Example Session

```
Welcome to Downtown Parking Services!

Vehicle 1 - Hours Parked: 2
Vehicle 2 - Hours Parked: 5
Vehicle 3 - Hours Parked: 3
More vehicles? (y/n): y
Vehicle 4 - Hours Parked: 7
More vehicles? (y/n): n

------------------------------------------------------------
	Downtown Parking Services
	parking Summary
------------------------------------------------------------
Vehicle 1 Charge: $4.00
Vehicle 2 Charge: $10.00
Vehicle 3 Charge: $6.00
Vehicle 4 Charge: $14.00

------------------------------------------------------------

Vehicles Processed: 4
Total Revenue: $34.00
Average Parking Fee: $8.50

------------------------------------------------------------
```

## Billing Rules

| Duration | Calculation | Charge |
|----------|-------------|--------|
| 0 hours | No charge | $0.00 |
| 1 hour | 1 × $2.00 | $2.00 |
| 1.5 hours | (1 × $2.00) + (2 × $0.50) | $3.00 |
| 2.5 hours | (2 × $2.00) + (2 × $0.50) | $5.00 |
| 24+ hours | Capped at maximum | $50.00 |

## Technical Details

- **Language**: C (C11 or later)
- **Dependencies**: Standard C library, math library (`-lm`)
- **Maximum Vehicles**: 100
- **Maximum Hours**: 24.0
- **Input Buffer**: 256 characters (prevents overflow)

## Files

| File | Description |
|------|-------------|
| `main.c` | Main program source code |
| `requirments.md` | Project requirements |
| `test-cases.md` | Test cases |
| `README.md` | This file |

## Author

COP-3515 Programming in C - CCR5 Assignment
