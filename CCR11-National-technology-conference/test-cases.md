# CCR11 - Test Cases

## Acceptance Criteria

**Command:**

```bash
student@9b36e72c8c17:/workspace/c/CCR11-National-technology-conference$ ./CCR11-National "Alice Johnson" "Brian Smith" "Emily Brown"
```

**Expected Output:**

```
----------------------------------------------------
National Technology Conference
Presenter Summary
-----------------------------------------------------
Presenters
1. Alice Johnson
2. Brian Smith
3. Emily Brown
-----------------------------------------------------
Total Presenters: 3
-----------------------------------------------------
Longest Presenter Name: Alice Johnson
Characters: 13
-----------------------------------------------------
```

---

## Test Cases

### Test Case 1: Invalid Name with Numbers

| Field | Value |
|-------|-------|
| **Description** | Try to enter a name with numbers |
| **Command** | `./CCR11-National "John123"` |
| **Expected Output** | `Error: Invalid name 'John123'. Names can only contain letters and spaces. Please re-enter the name.` |

---

### Test Case 2: Exceeding the 10-Name Limit

| Field | Value |
|-------|-------|
| **Description** | Try to exceed the 10 names input cap |
| **Command** | `./CCR11-National "John Doe" "Jane Doe" "Alice" "Peter Rocks" "Ippsec" "Elliot Brown" "Jimmy" "Bob Smith" "Barry" "thomas" "William"` |
| **Expected Output** | `Error: Maximum number of presenters (10) exceeded. Please enter 10 or fewer names.` |

---

### Test Case 3: No Arguments Provided

| Field | Value |
|-------|-------|
| **Description** | Running the program without any names (should show usage) |
| **Command** | `./CCR11-National` |
| **Expected Output** | `Usage: ./CCR11-National "Presenter Name" ["Presenter Name2"] ...`<br>`Example: ./CCR11-National "Alice Johnson" "Brian Smith" "Emily Brown"` |

---

### Test Case 4: Buffer Overflow Attempt

| Field | Value |
|-------|-------|
| **Description** | Trying to do a buffer overflow on a name |
| **Command** | `./CCR11-National "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" "Jane Doe"` |
| **Observed Output** | Program accepts the crazy input — it does not break, but it should not be accepted. |
| **Fix Applied** | Set `MAX_NAME_LEN = 100` to limit name length |
