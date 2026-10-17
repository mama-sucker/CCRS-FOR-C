# CCR13 - Data Analytics Solutions

**Course:** COP-3515: Introduction to C & Rust

---

## Overview

This program demonstrates inter-process communication (IPC) using **fork()** and **pipes** in C. The parent and child processes communicate via a pipe, where the child generates random numbers and the parent calculates statistical analysis on those numbers.

---

## Features

- **Process Creation:** Uses `fork()` to create a child process
- **Inter-Process Communication:** Parent and child communicate through a pipe
- **Random Number Generation:** Child generates 10 random numbers (1-100)
- **Statistical Analysis:** Parent calculates:
  - Count
  - Minimum value
  - Maximum value
  - Sum
  - Average
  - Percentage of numbers above average
- **PID Display:** Shows process IDs for both parent and child
- **Error Handling:** Proper error handling for pipe creation, fork, read/write, and process waiting

---

## How It Works

```
┌─────────────────────────────────────────────────────────────┐
│                        PARENT PROCESS                       │
│  1. Creates pipe and forks child                            │
│  2. Receives numbers from child via pipe                    │
│  3. Waits for child to finish                               │
│  4. Calculates statistics (min, max, avg, sum, etc.)        │
│  5. Displays results                                        │
└─────────────────────────────────────────────────────────────┘
                              │
                         (pipe)
                              │
┌─────────────────────────────────────────────────────────────┐
│                        CHILD PROCESS                        │
│  1. Generates 10 random numbers (1-100)                     │
│  2. Sends numbers to parent through pipe                    │
│  3. Exits                                                   │
└─────────────────────────────────────────────────────────────┘
```

---

## Building and Running

### Compile

```bash
gcc -g main.c -o CCR13-stats
```

### Run

```bash
./CCR13-stats
```

---

## Example Output

```
running program 1
----------------------------------------------------
Data Analytic Solutions
Statistics Processing
----------------------------------------------------
Parent Process Started (PID: 12345)
Child Process Started (PID: 12346)
Generating Numbers...
Numbers Sent Successfully
Receiving Numbers...
Calculating Statistics.....
----------------------------------------------------
Generated Numbers: 35, 59, 29, 18, 34, 17, 40, 90, 51, 67
Count: 10
Minimum: 17
Maximum: 90
Sum: 440
Average: 44.00
Percentage Above Average: 40.00%
----------------------------------------------------
Child Process Finished
Parent Process Finished
```

---

## Technologies Used

- **Language:** C
- **System Calls:** `fork()`, `pipe()`, `read()`, `write()`, `waitpid()`
- **Libraries:** `stdio.h`, `stdlib.h`, `unistd.h`, `sys/wait.h`, `time.h`

---

## Author

CCR13 - Data Analytics Solutions
COP-3515: Introduction to C & Rust
