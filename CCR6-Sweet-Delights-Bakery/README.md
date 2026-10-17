# CCR6 - Sweet Delights Bakery

A C program for COP-3515 (Programming in C) that simulates a bakery checkout system with random customer discounts.

## Overview

This program calculates customer receipts for Sweet Delights Bakery, applying sales tax and a random discount to each order. Each customer has a 50/50 chance of receiving a discount, and if they do, the discount percentage is randomly determined between 1% and 100%.

## Features

- **Input Validation**: Accepts only numeric values, rejects negative numbers, zero, and amounts exceeding $5,000
- **Buffer Overflow Protection**: Uses `fgets` with a 64-byte input buffer
- **Random Discount System**: Each customer has a 50/50 chance of receiving a discount
- **Variable Discount Percentages**: If a customer qualifies, the discount is randomly determined between 1% and 100%
- **Sales Tax Calculation**: Applies a configurable 6% sales tax
- **Nickel Rounding**: Final totals are rounded to the nearest nickel (5 cents)
- **Receipt Display**: Outputs a formatted customer receipt to the terminal

## Configuration

The following values can be modified at the top of `main.c`:

| Constant | Default | Description |
|----------|---------|-------------|
| `SALES_TAX_RATE` | 0.06 (6%) | Sales tax rate applied to orders |
| `MAX_ORDER_AMOUNT` | 5000.00 | Maximum allowed order total |

## Building

Compile the program using GCC:

```bash
gcc -g -Wall -Wextra -o CCR6-Sweet-Delights-Bakery main.c -lm
```

## Running

```bash
./CCR6-Sweet-Delights-Bakery
```

## Example Output

```
Order Amount: $25.00

========================================
		Sweet Delights Bakery
		   Customer Receipt
========================================

Original Order: $25.00
Sales Tax: $1.50
Discount: 40% ($11.40)

========================================

Final Total: $15.05
---------------------------------------------------------------------
```

## How It Works

1. User enters an order amount
2. Sales tax (6%) is calculated on the original order amount
3. A random number determines if the customer receives a discount (50/50 chance)
4. If the customer qualifies, a random discount percentage (1-100%) is applied to the taxed total
5. The final total is rounded to the nearest nickel
6. A formatted receipt is displayed

## Requirements

- C11 or later
- GCC compiler
- Standard C library (`math.h`, `stdio.h`, `stdlib.h`, `string.h`, `time.h`)

## Author

COP-3515 Programming in C - CCR6 Assignment
