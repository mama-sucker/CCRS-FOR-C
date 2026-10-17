# CCR12 - Insight Market Research Group

**Course:** COP-3515 Intro to C & Rust

---

## Requirements

### General Requirements

- This program does not need to save any information to a file
- Everything will be a TUI (Text User Interface) program

### Survey Responses Input

- Maximum number of survey scores: **10**
- Only integers should be accepted (no floats, no strings, no special characters)
- A response of `0` should be invalid and create an error

### Scores Input

- Users should be able to enter numbers including decimals
- Scores must be between **0 and 100** (inclusive)

### General Input Rules

- Negative inputs should be clearly marked as invalid
- All user inputs must be validated

### Memory Management

- Release all memory used when finished with execution
- Reserve the proper amount of memory during program execution
- Data management and collection is crucial
- The program should reserve enough memory to hold **exactly** the number of survey scores specified

---

## Additional Requirements (Customer Discussion / In-Class PowerPoint)

> **Note:** If the above contradicts anything here, follow what is stated here.

- Maximum surveys: **10**
- Memory cannot be allocated error must be included
- All scores must be printed to **one decimal place**

---

## Example Run

### Input

```
Number of Survey Scores: 5
Score 1: 85
Score 2: 92
Score 3: 78
Score 4: 96
Score 5: 89
```

### Output

```
----------------------------------------------
Insight Market Research Group
Survey Summary Report
----------------------------------------------
Survey Responses: 5
Highest Score: 96
Lowest Score: 78
Average Score: 88.0
----------------------------------------------
Memory released successfully
program completed.
----------------------------------------------
```
