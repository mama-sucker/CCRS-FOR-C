# Developer Software Requirements — CCR-001

## Tampa Fitness Center Membership Receipt Printer

---

## 1. Project Overview

**Project Name:** CCR-001 — Tampa Fitness Center Membership Receipt Printer
**Course:** COP-3515 (Object-Oriented Concepts)
**Language:** C (ISO C99 or later)
**Interface Type:** Text User Interface (TUI) — command-line only
**Purpose:** Collect customer membership information and generate a professional receipt displayed in the terminal and saved to disk.

---

## 2. Development Environment

### 2.1 Required Software

| Software | Minimum Version | Purpose |
|---|---|---|
| GCC (GNU C Compiler) | 9.0+ | Compile the C source code |
| Make | 4.0+ | Build automation (optional; manual `gcc` also supported) |
| Valgrind | 3.16+ | Memory leak detection and profiling |
| Git | 2.30+ | Version control |
| VS Code (recommended) | Latest | Editor with C/C++ extension |

### 2.2 Recommended Tools

| Tool | Purpose |
|---|---|
| `clang-format` | Code formatting |
| `clang-tidy` / `cppcheck` | Static analysis and linting |
| `gdb` | Debugging |
| `tree` | Project structure visualization |

### 2.3 Operating System

- **Primary:** Linux (Ubuntu 24.04 LTS or later)

### 2.4 Dev Container

A Docker-based dev container is provided. Rebuild with:

```bash
docker compose build
docker compose up -d
```

---

## 3. Build Requirements

### 3.1 Compilation

```bash
# Using Make (recommended)
make

# Manual compilation
gcc -g -o CCR-001 main.c
```

### 3.2 Compiler Flags

| Flag | Purpose |
|---|---|
| `-g` | Include debug symbols |
| `-Wall` | Enable all warnings |
| `-Wextra` | Enable extra warnings |
| `-std=c99` | Use C99 standard |
| `-O0` | No optimization (debug builds) |

### 3.3 Makefile Targets

| Target | Description |
|---|---|
| `make` / `make all` | Compile the program |
| `make run` | Build and run the program |
| `make format` | Format source code with `clang-format` |
| `make lint` | Run static analysis with `clang-tidy` |
| `make valgrind` | Run the program under Valgrind |
| `make clean` | Remove compiled binaries and artifacts |

---

## 4. Functional Requirements

### 4.1 Required Fields

| Field | Type | Validation Rules |
|---|---|---|
| **First Name** | String | Non-blank, no spaces, no digits |
| **Last Name** | String | Non-blank, no spaces, no digits |
| **Age** | Integer | 1–120 (inclusive); must be a valid integer |
| **Membership Price** | Float/Double | $0.00–$200.00 (inclusive); must be numeric |

### 4.2 Optional Fields

| Field | Type | Validation Rules |
|---|---|---|
| **Phone Number** | String | Free-form; format suggestion: `XXX-XXX-XXXX` |
| **Gender** | String | Free-form input |

### 4.3 Business Logic

1. **Senior Discount:** Customers with age > 65 receive a notification:
   `FYI customer applies for senior discount`
2. **Receipt ID:** Generated as `LastName-Age` (e.g., `Smith-45`)
3. **Date/Time:** Automatically captured at receipt generation time
4. **Annual Fee:** Calculated as `monthly_fee × 12`

### 4.4 Input Flow

```
1. Display business banner
2. Prompt for required fields (first name, last name, age, price)
3. Ask user if they want to provide optional fields (y/n)
4. If yes → prompt for phone number and gender
5. Display formatted receipt in terminal
6. Save receipt to disk
7. Print confirmation message
```

---

## 5. Output Requirements

### 5.1 Terminal Display (TUI)

The receipt must be displayed in the terminal with the following structure:

```
========================================================
       TAMPA FITNESS CENTER - MEMBERSHIP RECEIPT
========================================================

Date: YYYY-MM-DD HH:MM:SS
Receipt ID: LastName-Age

--------------------------------------------------------
  CUSTOMER INFORMATION
--------------------------------------------------------
  Customer Name: FirstName LastName
  Age:           <age>
  Senior Discount: Yes/No
  Phone Number:  <phone>        (if provided)
  Gender:        <gender>       (if provided)

--------------------------------------------------------
  MEMBERSHIP DETAILS
--------------------------------------------------------
  Monthly Fee:   $XX.XX
  Annual Fee:    $XXX.XX

========================================================
  Thank you for joining Tampa Fitness Center!
========================================================
```

### 5.2 File Output

| Property | Specification |
|---|---|
| **Format** | Markdown (`.md`) |
| **Destination** | `customers/` folder within the project directory |
| **Filename** | `LastName-Age.md` (e.g., `Smith-45.md`) |
| **Auto-create** | The `customers/` folder must be created if it does not exist |

---

## 6. Input Validation Rules

### 6.1 Name Fields (First & Last)

- Must not be blank or contain only whitespace
- Must not contain spaces
- Must not contain digits
- Must contain at least one alphabetic character

### 6.2 Age Field

- Must be a positive integer
- Must be between 1 and 120 (inclusive)
- Must not exceed three digits
- Rejects non-numeric input with a retry prompt

### 6.3 Membership Price Field

- Must be a non-negative number
- Must not exceed $200.00
- Must not exceed three digits before the decimal point
- Rejects character/letter input with a retry prompt

### 6.4 Yes/No Prompts

- Accepts: `y`, `Y`, `n`, `N`
- Rejects all other input with a retry prompt

---

## 7. Code Structure

### 7.1 Source File

| File | Purpose |
|---|---|
| `main.c` | All application logic in a single translation unit |

### 7.2 Key Functions

| Function | Purpose |
|---|---|
| `clear_input_buffer()` | Flush stdin after numeric input |
| `is_valid_string()` | Check if a string is non-blank |
| `get_valid_age()` | Prompt and validate age input |
| `get_non_blank_input()` | Prompt and validate non-blank string |
| `get_non_blank_no_spaces_input()` | Prompt and validate name fields |
| `get_yes_no()` | Prompt for yes/no response |
| `get_membership_price()` | Prompt and validate membership price |
| `print_receipt_tui()` | Display formatted receipt in terminal |
| `save_receipt_to_file()` | Write receipt to `.md` file |
| `main()` | Orchestrate the application flow |

---

## 8. Memory & Resource Requirements

| Resource | Requirement |
|---|---|
| **Memory** | Minimal — uses stack-allocated buffers (`MAX_BUF = 256`) |
| **Stack Usage** | Each buffer: 256 bytes × 4 variables = ~1 KB |
| **No dynamic allocation** | All memory is statically/stack allocated |
| **No memory leaks** | No `malloc`/`free` calls; Valgrind-clean by design |

---

## 9. Testing Requirements

### 9.1 Test Cases

| Category | Test | Expected Result |
|---|---|---|
| **Names** | Enter blank first name | Prompt repeats |
| **Names** | Enter name with space (e.g., "John Smith") | Rejects, prompts again |
| **Names** | Enter name with digits (e.g., "John1") | Rejects, prompts again |
| **Names** | Enter valid name (e.g., "John") | Accepted |
| **Age** | Enter age 0 or negative | Rejects |
| **Age** | Enter age 121 or above | Rejects |
| **Age** | Enter age 66 | Accepts + shows senior discount notice |
| **Age** | Enter age 65 | Accepts, no senior discount |
| **Price** | Enter price > $200 | Rejects |
| **Price** | Enter price as characters (e.g., "abc") | Rejects |
| **Price** | Enter valid price ($50.00) | Accepted |
| **Optional** | Enter 'y' for optional fields | Prompts for phone and gender |
| **Optional** | Enter 'n' for optional fields | Skips phone and gender |
| **Optional** | Enter invalid response (e.g., "maybe") | Rejects, re-prompts |

### 9.2 Valgrind Check

```bash
make valgrind
```

Expected output: **0 bytes in 0 blocks** — no memory leaks or errors.

---

## 10. Coding Standards

### 10.1 Style

- **Indentation:** 2 spaces (no tabs)
- **Line length:** Maximum 80 characters where practical
- **Naming:**
  - Functions: `snake_case`, descriptive names
  - Constants: `UPPER_SNAKE_CASE`
  - Variables: `snake_case`, descriptive names
- **Comments:** Document each function's purpose, parameters, and return value

### 10.2 Error Handling

- All user input is validated in a `while(1)` loop until valid
- Input buffer is cleared after every `scanf()` call
- `NULL` checks on all string inputs
- `unsigned char` casts for `ctype.h` functions to avoid undefined behavior

---

## 11. Dependencies

| Dependency | Status |
|---|---|
| **Standard Library Only** | ✅ No external libraries required |
| Headers used | `<stdio.h>`, `<stdlib.h>` |
| | `<string.h>`, `<ctype.h>`, `<time.h>` |

---

## 12. Deployment

### 12.1 Distribution

- Distribute the compiled binary (`CCR-001`) and `main.c` source
- Include this `developer-software-requirements.md` document
- Include the `customers/` folder as the output directory

### 12.2 Installation

No installation required. The program is a single binary with no dependencies.

```bash
# Copy binary to desired location
cp CCR-001 /usr/local/bin/

# Run
CCR-001
```

---

## 13. Future Enhancements (Out of Scope)

| Feature | Description |
|---|---|
| **PDF Output** | Generate PDF receipts using `libharu` or `wkhtmltopdf` |
| **Database Storage** | Persist receipts to SQLite or similar |
| **GUI** | Port to a graphical interface (GTK, Qt) |
| **Multiple Receipts** | Process multiple customers in a single session |
| **Receipt Lookup** | Search and retrieve past receipts by ID or name |
| **Discount Tiers** | Implement graduated senior discount percentages |

---

## 14. Revision History

| Version | Date | Author | Changes |
|---|---|---|---|
| 1.0 | 2025-08-28 | COP-3515 Team | Initial developer software requirements |
| 1.1 | 2025-08-28 | COP-3515 Team | Added re-edits: space/digit validation for names, age max 120, price max $200, senior discount notification |

---

*This document defines all final developer software requirements for the CCR-001 Tampa Fitness Center Membership Receipt Printer.*
