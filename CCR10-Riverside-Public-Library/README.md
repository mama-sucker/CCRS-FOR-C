# CCR10 - Riverside Public Library

## Description

A terminal-based C program for the Riverside Public Library that collects and displays information about two library members. The program validates input, handles edge cases, and displays a formatted member name report.

## Features

- **Input Validation**: Rejects numbers in names, enforces 40-character limit
- **Flexible Names**: Supports spaces, hyphens, and apostrophes in names
- **Automatic Capitalization**: Capitalizes the first letter of each word in names
- **Case-Sensitive Comparison**: Treats "Bob" and "bob" as different names
- **Blank Last Names**: Allows blank last names when first name is provided
- **Alphabetical Ordering**: Displays members in alphabetical order by full name
- **Letter Counting**: Counts only alphabetic characters (ignores spaces, hyphens, apostrophes)

## Requirements

- COP-3515 Programming in C
- GCC compiler
- Linux/macOS/Unix environment

## Building

```bash
gcc -Wall -Wextra -o CCR10-Riverside main.c
```

## Running

```bash
./CCR10-Riverside
```

## Example Usage

```
Member 1
First Name: Alice
Last Name: Johnson

Member 2
First Name: Brian
Last Name: Smith

------------------------------------------
Riverside Public Library
Member Name Report
------------------------------------------
Member 1: Alice Johnson
Letters: 12

Member 2: Brian Smith
Letters: 10

The names are NOT identical
------------------------------------------
Alphabetical Order:
1. Alice Johnson
2. Brian Smith
------------------------------------------
```

## Input Rules

| Field | Required | Max Length | Allowed Characters |
|-------|----------|------------|-------------------|
| First Name | Yes | 40 | Letters, spaces, hyphens, apostrophes |
| Last Name | No | 40 | Letters, spaces, hyphens, apostrophes |

## Error Messages

- **"First name is required"** — First name cannot be blank
- **"Character limit exceeded (max 40 characters)"** — Name exceeds maximum length
- **"No numbers allowed"** — Name contains numeric characters

## Author

COP-3515 Student
