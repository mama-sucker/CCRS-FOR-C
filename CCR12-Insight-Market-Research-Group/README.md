# CCR12 - Insight Market Research Group

A C program for COP-3515 (Intro to C & Rust) that collects and analyzes survey scores for the Insight Market Research Group.

## Overview

This program provides a text user interface (TUI) for entering survey scores and displays a summary report including the highest score, lowest score, and average score.

## Features

- **Input Validation**: Accepts only valid integer inputs for the number of scores and numeric inputs (including decimals) for scores
- **Score Range**: Each score must be between 0 and 100
- **Maximum Entries**: Supports up to 10 survey scores
- **Dynamic Memory Allocation**: Allocates exactly the amount of memory needed for the specified number of scores
- **Memory Management**: All allocated memory is properly freed before program exit
- **Error Handling**: Handles invalid input, empty input, out-of-range values, and memory allocation failures

## Requirements

- A C compiler (e.g., `gcc`)
- A Unix-like or Linux environment

## Building

Compile the program using `gcc`:

```bash
gcc -Wall -Wextra -g main.c -o CCR12-Insight
```

Or use the provided Makefile target:

```bash
make build
```

## Usage

Run the compiled program:

```bash
./CCR12-Insight
```

### Example Run

```
Number of Survey Scores: 5
Score 1: 85
Score 2: 92
Score 3: 78
Score 4: 96
Score 5: 89

----------------------------------------------
Insight Market Research Group
Survey Summary Report
----------------------------------------------
Survey Responses: 5
Highest Score: 96.0
Lowest Score: 78.0
Average Score: 88.0
----------------------------------------------
Memory released successfully
program completed.
----------------------------------------------
```

## Input Rules

| Input Type | Constraints |
|------------|-------------|
| Number of Scores | Positive integer, maximum of 10 |
| Each Score | Floating-point number between 0 and 100 (inclusive) |

## Output

The program displays:
- **Survey Responses**: Total number of scores entered
- **Highest Score**: The maximum score entered
- **Lowest Score**: The minimum score entered
- **Average Score**: The arithmetic mean of all scores (displayed to one decimal place)

## Memory Management

- Memory is dynamically allocated using `malloc()` for exactly the number of scores specified
- All memory is freed using `free()` before program termination
- A "Memory cannot be allocated" error is displayed if `malloc()` fails

## Author

Addison Roy
