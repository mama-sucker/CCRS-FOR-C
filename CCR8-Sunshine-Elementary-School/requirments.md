# CCR8 - Sunshine Elementary School

**Course:** COP-3515 Programming in C

---

## Requirements

- Make sure that when the (Original Grade) is inputted it only accepts numerical input
  - 0–100 & it can accept fractional numbers EX: 84.5
- Make sure that (Original Grade) can not be buffer overflowed
- The (Total Credit) input should not be able to exceed the (Original Grade) past 120%
  - For example, if the original grade was 100 and you try to add 40 with the (Total Credit), then that would be 140, when 120 is the maximum
- For input on (Total Credits), apply the same input rules as (Original Grade)
- This program only needs to process one student at a time
- This program will only need to output to the TUI; ignore any file saving


## Requirements After Customer Discussion / (In Class PowerPoint)

> **IF THE ABOVE CONTRADICTS ANYTHING HERE, FOLLOW WHAT'S STATED HERE**

- Maximum Possible Grade: 120
- Negative Number input is not allowed
- If invalid input occurs: error message showing 120 is the maximum total
- If no (Total Credit) was awarded, either zero or no input (just enter this) should be valid


---

## Example Run

### User Input

- Original Grade: 84
- Total Credit: 5

### Program Output

```
===============================================
Sunshine Elementary School
Grade Adjustment Report
===============================================
Original Grade: 84
Extra Credit: 5
Corrected Grade: 89
===============================================
```
