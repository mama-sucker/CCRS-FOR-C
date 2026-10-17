# CCR8 - Sunshine Elementary School

**Course:** COP-3515 Programming in C

## Overview

Sunshine Elementary School's Grade Adjustment Program calculates corrected grades by adding extra credit to original grades. The program processes one student at a time and displays the results in a terminal user interface (TUI).

## Features

- **Input Validation**: Accepts only numerical input (including fractional numbers like 84.5)
- **Buffer Overflow Protection**: Safely handles input up to 64 characters
- **Grade Limits**:
  - Original Grade: 0–100
  - Maximum Possible Grade: 120 (original + extra credit combined)
- **Negative Number Rejection**: All inputs must be non-negative
- **Flexible Extra Credit**: Empty input for Total Credit is treated as 0
- **Clear Error Messages**: Guides users when invalid input is provided

## Building

```bash
gcc -Wall -Wextra -g main.c -o CCR8-Sunshine-Elementary-School
```

## Running

```bash
./CCR8-Sunshine-Elementary-School
```

## Usage

The program prompts for two inputs:

1. **Original Grade** – The student's current grade (0–100, accepts decimals)
2. **Total Credit** – Extra credit to add (optional; combined total must not exceed 120)

### Example Run

```
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

## Input Validation Examples

| Input | Result |
|-------|--------|
| `ABC` | `Error: Invalid input. Please enter a non-negative number (0-100)` |
| `100.999...` | `Error: Original grade cannot exceed 100` |
| Original: `100`, Credit: `50` | `Error: Total (Original + Credit) cannot exceed 120` |
| `-100` | `Error: Invalid input. Please enter a non-negative number (0-100)` |
| Empty (for Total Credit) | Treated as 0 (valid) |

## Project Structure

```
CCR8-Sunshine-Elementary-School/
├── main.c              # Source code
├── README.md           # This file
├── requirments.md      # Requirements document
└── test-cases.md       # Test cases and acceptance criteria
```

## Requirements

See [requirments.md](./requirments.md) for full requirements specification.

## Test Cases

See [test-cases.md](./test-cases.md) for test cases and acceptance criteria.
