# CCR-001 Assignment — Tampa Fitness Center Receipt Printer

**Course:** COP-3515 (Object-Oriented Concepts)
**Assignment:** CCR-001 — Basic Receipt Printer
**Language:** C (ISO C99 or later)

## Overview

This project is a **Tampa Fitness Center Receipt Printer** developed as part of the **CCR-001 Assignment** for **COP-3515**. It is a command-line (TUI) application that collects customer information and generates a professional membership receipt.

## Features

### Required Fields

- **First Name & Last Name**
  - Validated: non-blank, no spaces, no digits
  - Each name must contain at least one alphabetic character
- **Customer Age**
  - Validated: must be between 1 and 120 (inclusive)
  - Must be a valid integer
- **Monthly Membership Price**
  - Validated: must be between $0.00 and $200.00 (inclusive)
  - Must be numeric (rejects character input)

### Optional Fields

- **Phone Number** (format suggestion: XXX-XXX-XXXX)
- **Gender**

### Senior Discount

- Customers with age > 65 receive a notification:
  ```
  FYI customer applies for senior discount
  ```
- The receipt displays: `Senior Discount: YES - Qualifies for senior discount`

### Receipt Output

- **Terminal Display (TUI):** Formatted receipt with:
  - Date and time of generation
  - Receipt ID formatted as `LastName-Age`
  - Customer information (name, age, senior discount status)
  - Optional fields (phone, gender) if provided
  - Membership fee details (monthly fee)
- **File Output:** (Planned) Save receipt as `.md` in `customers/` folder

## Building & Running

### Prerequisites

- **GCC (GNU C Compiler)** version 9.0 or later
- **Make (GNU Make)** version 4.0 or later (optional; manual compilation also supported)
- **Git** for version control

### Build

```bash
# Using Make (recommended)
make

# Manual compilation
gcc -g -o CCR-001 main.c
```

### Run

```bash
./CCR-001
```

### Additional Makefile Targets

| Target | Description |
|--------|-------------|
| `make run` | Build and run the program |
| `make format` | Format source code with `clang-format` |
| `make lint` | Run static analysis with `clang-tidy` |
| `make valgrind` | Run the program under Valgrind for memory leak detection |
| `make clean` | Remove compiled binaries and artifacts |

## Project Structure

```
c/CCR1-membership-receipts/
├── main.c                          # Main source file (all application logic)
├── CCR-001                         # Compiled binary
├── Makefile                        # Build configuration
├── README.md                       # This file
├── requirements.txt                # Assignment requirements
├── re-edits.txt                    # Code re-edits and fixes log
├── developer-software-requirements.md  # Complete developer requirements
├── "CCR 1.pdf"                     # Assignment PDF (if applicable)
└── customers/                      # Output directory for saved receipts (planned)
```

## How It Works

1. The program starts by displaying the business banner: **"Tampa Fitness Center - Membership Receipt"**
2. It prompts the user for all **required fields** (first name, last name, age, membership price)
3. Each input is validated according to the rules specified above
4. It asks whether to provide **optional fields** (phone number, gender) with a yes/no prompt
5. A formatted receipt is displayed in the terminal (TUI)
6. The program exits with a success message

### Input Flow Diagram

```
┌─────────────────────────────────┐
│ Display Business Banner         │
└──────────────┬──────────────────┘
               ▼
┌─────────────────────────────────┐
│ Required Fields                 │
│  • First Name (no spaces/digits)│
│  • Last Name (no spaces/digits) │
│  • Age (1-120)                  │
│  • Membership Price ($0-$200)   │
└──────────────┬──────────────────┘
               ▼
┌─────────────────────────────────┐
│ Optional Fields (y/n prompt)    │
│  • Phone Number                 │
│  • Gender                       │
└──────────────┬──────────────────┘
               ▼
┌─────────────────────────────────┐
│ Display Formatted Receipt (TUI) │
└──────────────┬──────────────────┘
               ▼
┌─────────────────────────────────┐
│ Exit with Success Message       │
└─────────────────────────────────┘
```

## Input Validation Rules

### Name Fields (First & Last)

- Must not be blank or contain only whitespace
- Must not contain spaces
- Must not contain digits
- Must contain at least one alphabetic character

### Age Field

- Must be a positive integer
- Must be between 1 and 120 (inclusive)
- Rejects non-numeric input with a retry prompt

### Membership Price Field

- Must be a non-negative number
- Must not exceed $200.00
- Rejects character/letter input with a retry prompt

### Yes/No Prompts

- Accepts: `y`, `Y`, `n`, `N`
- Rejects all other input with a retry prompt

## Code Structure

### Key Functions

| Function | Purpose |
|----------|---------|
| `clear_input_buffer()` | Flush stdin after numeric input |
| `is_valid_string()` | Check if a string is non-blank |
| `get_valid_age()` | Prompt and validate age input (1-120) |
| `get_non_blank_input()` | Prompt and validate non-blank string |
| `get_non_blank_no_spaces_input()` | Prompt and validate name fields (no spaces/digits) |
| `get_yes_no()` | Prompt for yes/no response |
| `get_membership_price()` | Prompt and validate membership price ($0-$200) |
| `print_receipt_tui()` | Display formatted receipt in terminal |
| `main()` | Orchestrate the application flow |

## Testing

### Test Cases

| Category | Test | Expected Result |
|----------|------|-----------------|
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

### Valgrind Check

```bash
make valgrind
```

Expected output: **0 bytes in 0 blocks** — no memory leaks or errors.

## Dependencies

- **Standard Library Only** — No external libraries required
- Headers used: `<stdio.h>`, `<stdlib.h>`, `<string.h>`, `<ctype.h>`, `<time.h>`

## Future Enhancements (Out of Scope)

| Feature | Description |
|---------|-------------|
| **File Output** | Save receipts as `.md` or `.pdf` in `customers/` folder |
| **PDF Generation** | Generate PDF receipts using `libharu` or `wkhtmltopdf` |
| **Database Storage** | Persist receipts to SQLite or similar |
| **GUI** | Port to a graphical interface (GTK, Qt) |
| **Multiple Receipts** | Process multiple customers in a single session |
| **Receipt Lookup** | Search and retrieve past receipts by ID or name |
| **Discount Tiers** | Implement graduated senior discount percentages |

## License

This project is for educational purposes as part of COP-3515.
