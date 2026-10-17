# CCR4 — Precision Payroll Services

> **COP-3515 In-Class Assignment**

## Overview

A C program that reads employee hours from an input file, adds line numbers to each entry, and writes the result to a new output file. The program also prints a summary of the operation to the console.

## Features

- Reads employee data from `employee_hours.txt`
- Validates each line to ensure it contains a name and hours (format: `Name, Hours`)
- Adds sequential line numbers to each valid entry
- Writes numbered output to `numbered_hours.txt`
- Prints a formatted processing summary to stdout
- Skips blank or invalid lines automatically

## Project Structure

```
CCR4-Precision-Payroll-Services/
├── main.c                  # Source code
├── employee_hours.txt      # Input data file
├── numbered_hours.txt      # Generated output file
├── requirments.md          # Assignment requirements
├── test-cases.md           # Test cases
├── IMPORTANT.md            # Additional notes
└── README.md               # This file
```

## Building

Compile the program using `gcc`:

```bash
gcc -g -o CCR4-Precision main.c
```

Or use the provided Makefile:

```bash
make build
```

## Running

Ensure `employee_hours.txt` exists in the project directory, then run:

```bash
./CCR4-Precision
```

### Input Format

Each line in `employee_hours.txt` should follow the format:

```
Name, Hours
```

Example:

```
John Smith, 40
Jane Doe, 32
```

### Output

The program generates `numbered_hours.txt` with each valid line prefixed by its line number:

```
1. John Smith, 40
2. Jane Doe, 32
```

A summary is also printed to the console:

```
================================
Precision Payroll Services
File Processing Summary
================================
Input File: employee_hours.txt
Output File: numbered_hours.txt

Lines Copied: 2
Characters Copied: 38

File Copied and numbered Successfully. Thank you!
```

## Requirements

See [requirments.md](requirments.md) for the full assignment requirements.

## Test Cases

See [test-cases.md](test-cases.md) for all test cases.

## License

COP-3515 Course Project