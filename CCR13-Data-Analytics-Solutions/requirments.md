# CCR13 - Data Analytics Solutions

**Course:** COP-3515: Introduction to C & Rust

---

## Requirements

- The program will not need to save anything to a file
- The output of the program will only need to print out the TUI

---

## Updated Requirements (Post-Customer Discussion)

> **Note:** If the above contradicts anything below, follow what's stated here.

### Process Communication
- The first process (child) should generate 10 numbers for the other process (parent)
- The numbers should be randomly generated between 1-100
- The processes should communicate through pipes
- The parent should wait for the child process to finish before termination

### Calculations
The main program should calculate:
- Minimum
- Maximum
- Average
- Sum
- Count
- Percentage above average

### Output Requirements
- The generated numbers should be shown in the output
- The program should display the PIDs of both processes
- If the program cannot communicate/receive any data from the child, have proper error handling to notify the user

---

## Example Run

```
running program 1 (./statistics)

OUTPUT:

----------------------------------------------------
Data Analytic Solutions
Statistics Processing
----------------------------------------------------
Parent Process Started
Child Process Started
Generating Numbers...
Numbers Sent Successfully
Receiving Numbers...
Calculating Statistics.....
----------------------------------------------------
Count: 10
Minimum: 5
Maximum: 42
Average: 21.80
----------------------------------------------------
Child Process Finished
Parent Process Finished
```
