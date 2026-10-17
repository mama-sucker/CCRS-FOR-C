# CCR13 - Data Analytics Solutions

**Course:** COP-3515: Introduction to C & Rust

---

## Acceptance Criteria

The program must:

- [x] Create a child process using `fork()`
- [x] Establish pipe communication between parent and child
- [x] Generate exactly 10 random numbers (1-100) in the child process
- [x] Send numbers from child to parent through the pipe
- [x] Calculate and display: count, minimum, maximum, sum, average, percentage above average
- [x] Display PIDs of both parent and child processes
- [x] Display all generated numbers in the output
- [x] Parent waits for child to finish before termination
- [x] Handle pipe creation, fork, read/write, and waitpid errors
- [x] Output only to TUI (no file saving)

---

## Test Cases

### 1. Normal Execution
**Description:** Run the program under normal conditions.
**Expected Result:**
- Program compiles without errors
- Child process generates 10 random numbers (1-100)
- Parent receives all 10 numbers via pipe
- All statistics are calculated correctly
- Both PIDs are displayed
- Output matches expected format

**Status:** ✅ PASSED

---

### 2. Random Number Range Validation
**Description:** Verify all generated numbers are between 1-100.
**Expected Result:**
- Every number in the output is ≥ 1 and ≤ 100
- No zeros, negatives, or numbers > 100 appear

**Status:** ✅ PASSED

---

### 3. Statistics Accuracy
**Description:** Manually verify the calculated statistics match the generated numbers.
**Expected Result:**
- Count = 10
- Minimum = smallest number in the list
- Maximum = largest number in the list
- Sum = sum of all 10 numbers
- Average = Sum / 10
- Percentage Above Average = (count of numbers > average) / 10 × 100

**Status:** ✅ PASSED

---

### 4. Process Communication (Pipe)
**Description:** Verify parent and child communicate correctly via pipe.
**Expected Result:**
- All 10 numbers are received by the parent
- No data loss or corruption
- No errors about pipe read/write failures

**Status:** ✅ PASSED

---

### 5. Process Synchronization
**Description:** Verify parent waits for child to finish.
**Expected Result:**
- "Child Process Finished" appears before "Parent Process Finished"
- No zombie processes left behind
- Clean exit with return code 0

**Status:** ✅ PASSED

---

### 6. PID Display
**Description:** Verify both process IDs are displayed.
**Expected Result:**
- Parent PID is displayed
- Child PID is displayed
- Both PIDs are valid (non-zero, different from each other)

**Status:** ✅ PASSED

---

### 7. Error Handling - Pipe Creation
**Description:** Test behavior when pipe creation fails.
**Expected Result:**
- Program prints: `Error: Could not create pipe`
- Program exits with return code 1

**Status:** ✅ PASSED

---

### 8. Error Handling - Fork Failure
**Description:** Test behavior when fork() fails.
**Expected Result:**
- Program prints: `Error: Could not fork process`
- Program exits with return code 1

**Status:** ✅ PASSED

---

### 9. Error Handling - Pipe Read/Write Failure
**Description:** Test behavior when pipe communication fails.
**Expected Result:**
- Program prints appropriate error message
- Program exits with return code 1

**Status:** ✅ PASSED

---

### 10. Multiple Executions
**Description:** Run the program multiple times to verify consistent behavior.
**Expected Result:**
- Each run produces different random numbers
- Each run completes successfully
- No memory leaks or resource leaks

**Status:** ✅ PASSED

---

### 11. Output Format Validation
**Description:** Verify output matches the expected format from requirements.
**Expected Result:**
- Header "Data Analytic Solutions / Statistics Processing" is displayed
- All sections appear in correct order
- Statistics are formatted with 2 decimal places for average and percentage
- Separator lines (---) are present

**Status:** ✅ PASSED

---

### 12. No File Output
**Description:** Verify program does not create or modify any files.
**Expected Result:**
- No new files are created in the working directory
- All output goes to stdout (TUI)

**Status:** ✅ PASSED

---

## Summary

| Test Case | Status |
|-----------|--------|
| Normal Execution | ✅ PASSED |
| Random Number Range | ✅ PASSED |
| Statistics Accuracy | ✅ PASSED |
| Process Communication | ✅ PASSED |
| Process Synchronization | ✅ PASSED |
| PID Display | ✅ PASSED |
| Error Handling - Pipe | ✅ PASSED |
| Error Handling - Fork | ✅ PASSED |
| Error Handling - Pipe I/O | ✅ PASSED |
| Multiple Executions | ✅ PASSED |
| Output Format | ✅ PASSED |
| No File Output | ✅ PASSED |

**All 12 test cases passed successfully.**
