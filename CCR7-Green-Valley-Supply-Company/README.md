# CCR7 - Green Valley Supply Company

## Overview

An inventory management system for Green Valley Supply Company that tracks product inventory and processes sales transactions. The program provides a simple text-based interface for managing inventory levels and calculating remaining stock after each sale.

## Features

- **Input Validation**: Accepts only valid integer inputs for inventory and purchase amounts
- **Inventory Limit**: Maximum inventory of 100 products
- **File-Based Storage**: Automatically saves updated inventory to `storage/inventory.txt`
- **Persistent Inventory**: On subsequent runs, enter `0` as inventory to load from the saved file
- **Error Handling**: Clear error messages for invalid inputs, negative numbers, and exceeding inventory limits
- **Buffer Overflow Protection**: Safe input handling prevents buffer overflow

## Requirements

- C compiler (GCC)
- POSIX-compliant system (Linux, macOS, etc.)

## Building

```bash
gcc main.c -o CCR7-Green-Valley
```

## Running

```bash
./CCR7-Green-Valley
```

## Usage

### First Run
1. Enter the current inventory level (0-100)
2. Enter the number of products purchased
3. View the transaction summary

### Subsequent Runs
1. Enter `0` as the current inventory to load from `storage/inventory.txt`
2. Or enter a new inventory value (overwrites the file)
3. Enter the number of products purchased
4. View the transaction summary

### Example Session

```
=======================================
Green Valley Supply Company
Inventory Management System
=======================================

Current Inventory: 100
Products Purchased: 25

=======================================
Green Valley Supply Company
Inventory Transaction Summary
=======================================

Inventory Before Sale: 100
Products Sold: 25
Inventory Remaining: 75

=======================================
```

## File Structure

```
CCR7-Green-Valley-Supply-Company/
├── main.c              # Main program source code
├── README.md           # This file
├── requirments.md      # Project requirements
├── test-cases.md       # Test cases
└── storage/
    └── inventory.txt   # Saved inventory file (auto-created)
```

## Input Validation

The program validates all user input:

| Input | Valid Range | Error Message |
|-------|-------------|---------------|
| Inventory | 0-100 | "Negative input is not allowed" / "Inventory cannot exceed 100" |
| Purchase | 0 to inventory | "Cannot purchase more than available inventory" |
| Non-integer | Any | "Invalid input. Please enter a valid integer" |

## Error Handling

- **Invalid Input**: Rejects non-integer values with clear error messages
- **Negative Numbers**: Rejects negative values for both inventory and purchases
- **Exceeding Inventory**: Prevents purchasing more than available stock
- **Missing File**: Creates `storage/inventory.txt` on first run if it doesn't exist
- **File Read Error**: Prompts user to enter inventory manually if file is corrupted

## License

This project is part of COP-3515 (Programming in C) at Florida International University.
