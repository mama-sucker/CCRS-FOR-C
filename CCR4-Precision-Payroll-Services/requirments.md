# CCR4 — Precision Payroll Services

> **COP-3515 In-Class Assignment**

---

## Overview

Read employee hours from an input file, add line numbers to each entry, and write the result to a new output file. Then print a summary of the operation.

---

## Input / Output

| Item | File |
|---|---|
| **Input file** | `employee_hours.txt` (do **not** overwrite) |
| **Output file** | `numbered_hours.txt` |

- Employee hours are stored in the input text file.
- Each line should be numbered starting from **1**.
- The output file contains the same data, each line prefixed with its line number.

---

## Example

### Input (`employee_hours.txt`)

```
John Smith, 40
John Doe, 27
Jane Doe, 32
```

### Output (`numbered_hours.txt`)

```
1. John Smith, 40
2. John Doe, 27
3. Jane Doe, 32
```

---

## Console Output

After processing, the program must print a summary to **stdout** in this exact format:

```
================================
Precision Payroll Services
File Processing Summary
================================
Input File: employee_hours.txt
Output File: numbered_hours.txt

Lines Copied: 3
Characters Copied: X

File Copied and numbered Successfully. Thank you!
```

> **Note:** Replace `X` with the actual character count.

---

## Requirements Summary

1. **Read** `employee_hours.txt` from the project directory.
2. **Do not overwrite** the input file.
3. **Add line numbers** starting at 1 to each line.
4. **Write** the numbered output to `numbered_hours.txt`.
5. **Print** the file processing summary to the console.
