# CCR11 - National Technology Conference

**Course:** COP-3515 Intro to C & Rust

---

## Overview

A C program that manages a list of presenters for the National Technology Conference. It accepts presenter names as command-line arguments, validates them, and displays a formatted summary.

---

## Features

- **CLI Argument Input** — Pass presenter names directly when running the program.
- **Name Validation** — Only letters and spaces are allowed; rejects numbers, special characters, and empty names.
- **Duplicate Detection** — Duplicate names (case-insensitive) are displayed only once.
- **Presenter Limit** — Maximum of 10 presenters allowed.
- **Memory Safe** — No buffer overflows or memory leaks.
- **Formatted Output** — Displays a clean, readable summary of all presenters.

---

## Building

Compile the program using `gcc`:

```bash
gcc -g -Wall -Wextra -o CCR11-National main.c
```

---

## Usage

Run the program with presenter names as arguments:

```bash
./CCR11-National "Alice Johnson" "Brian Smith" "Emily Brown"
```

### Example Output

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

## Validation Rules

| Rule | Description |
|------|-------------|
| **Letters & Spaces Only** | Names must contain only alphabetic characters and spaces |
| **First Name Required** | Each name must contain at least one letter |
| **Max Length** | Each name is limited to 100 characters |
| **Max Presenters** | Up to 10 presenters allowed |
| **No Duplicates** | Duplicate names (case-insensitive) are shown only once |
| **No Titles** | "Dr." and "Professor" titles should not be included |

---

## Error Messages

| Condition | Message |
|-----------|---------|
| No arguments provided | Usage example is displayed |
| Invalid name | `Error: Please enter a valid name.` |
| Too many presenters | `Error: Maximum number of presenters (10) exceeded. Please enter 10 or fewer names.` |
| Duplicate name | `Warning: Duplicate name '...' - only displaying once.` |

---

## Example Run

```bash
./CCR11-National "Alice Johnson" "Brian Smith" "Emily Brown"
```

---

## Author

CCR11 Team — COP-3515 Intro to C & Rust
