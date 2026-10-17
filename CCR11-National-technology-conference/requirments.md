# CCR11 - National Technology Conference

**Course:** COP-3515 Intro to C & Rust

---

## Requirements

### Core Requirements

- The program should be able to accept a list of presenter names as CLI arguments.
- The program should display a summary of the presenters, including:
  - The total number of presenters.
  - The longest presenter name and its character count.
- This program will only need to print to the terminal; no saving to a file is required.
- Do not allow non-names to be entered as names.
  - **Examples of invalid names:** `"1234"`, `"John123"`, `"John!"`
  - Create an error message for invalid names and prompt the user to re-enter the name.
- Presenter names should be entered when the program is run, e.g.:
  ```bash
  ./CCR11-National "Alice Johnson" "Brian Smith" "Emily Brown"
  ```
- Do not allow for buffer overflow or memory leaks.

### Presenter Limits

- The maximum number of presenters should be limited to **10**.
  - If the user tries to enter more than 10 names, the program should show an error:
    ```
    Error: Maximum number of presenters (10) exceeded. Please enter 10 or fewer names.
    ```
- If the user runs the program without any names, the program should show a usage example.

---

## Additional Requirements (Post-Customer Discussion / In-Class PowerPoint)

> **Note:** If the above contradicts anything here, follow what's stated below.

- Presenter names do not need to include a last name, but it will need a first name.
- Presenter names should not include spaces.
- If two names are entered with the same characters, print out both names in the summary.
- "Dr." or "Professor" titles should not be included in the names.
- Duplicate presenter names should only be displayed once in the summary.

---

## Example Run

**Command:**

```bash
./CCR11-National "Alice Johnson" "Brian Smith" "Emily Brown"
```

**Output:**

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
