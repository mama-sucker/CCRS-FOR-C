# Grand Cinema Theater - Ticket Classification

A C program that classifies cinema tickets based on customer age and day type.

## Overview

This program prompts the user for a customer's age and the type of day (weekday or weekend), then determines the appropriate ticket category.

## Features

- **Age Validation**: Accepts ages between 1-99 (integers only)
- **Day Type Selection**: Choose between weekday (W) or weekend (E)
- **Input Validation**: Rejects invalid input and prompts the user to retry
- **Ticket Classification**: Categorizes customers into three ticket types

## Ticket Categories

| Category | Age Range |
|----------|-----------|
| Child Ticket | 1-12 years |
| Adult Ticket | 13-59 years |
| Senior Ticket | 60-99 years |

## Building

```bash
gcc -Wall -Wextra -o SIMS main.c
```

## Running

```bash
./SIMS
```

## Example Usage

```
Customer Age: 10
What type of day is it press W for weekday or E for weekend
Day Type: E

Grand Cinema Theater

Ticket Classification
===============================

Customer Age: 10
Day Type: Weekend
===============================
Ticket Type: Child ticket
```

## Input Validation

- **Age**: Must be an integer between 1 and 99. Non-integer or out-of-range values display: `Try again. Age should be between 1-99`
- **Day Type**: Must be `W` (weekday) or `E` (weekend), case-insensitive

## Requirements

- C99 or later
- Standard C library (`stdio.h`, `ctype.h`)
