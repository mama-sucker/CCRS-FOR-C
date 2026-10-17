# CCR9 - Atlantic Shipping & Logistics

A simple terminal-based application for calculating package dimensions, volume, and surface area for Atlantic Shipping & Logistics.

## Overview

This program accepts shipping box dimensions (length, width, height) in inches and calculates:
- **Volume** (cubic units): `length × width × height`
- **Surface Area** (square units): `2 × (length×width + length×height + width×height)`

## Requirements

- **Input units**: All dimensions must be in inches
- **Input type**: Decimal numbers only (no characters or special symbols)
- **Valid range**: Positive values only (zero and negative values are rejected)
- **Maximum dimensions**:
  - Length: 39 feet (468 inches)
  - Width: 7 feet 5 inches (89 inches)
  - Height: 7 feet 6 inches (90 inches)
- **Output precision**: Two decimal places (no rounding)
- **Calculations**: Performed independently in separate functions

## Building

```bash
gcc -Wall -Wextra -g main.c -o CCR9-Atlantic -lm
```

## Running

```bash
./CCR9-Atlantic
```

## Example Usage

```
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

## Input Validation

The program validates all user input:
- Rejects non-numeric characters
- Rejects zero and negative values
- Rejects values exceeding maximum allowed dimensions
- Rejects empty input
- Allows retry on invalid input with a clear error message

## Project Structure

| File | Description |
|------|-------------|
| `main.c` | Main application source code |
| `README.md` | This file |
| `requirments.md` | Project requirements document |
| `test-cases.md` | Test cases for validation |

## Functions

| Function | Description |
|----------|-------------|
| `get_dimension()` | Prompts user for a dimension with validation |
| `calculate_volume()` | Calculates package volume |
| `calculate_surface_area()` | Calculates package surface area |
| `print_report()` | Formats and displays the measurement report |

## Course

COP-3515: Programming in C
