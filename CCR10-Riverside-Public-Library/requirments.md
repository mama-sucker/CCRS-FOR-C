# CCR10 - Riverside Public Library

For COP-3515 Programming in C

---

## Requirements

- This will be a TUI (Text User Interface) based application — no need to save files, just run and output
- This is a non-production run application and will only need to process **two members at a time** for now
- Limit the maximum number of characters the user can enter for their name to prevent buffer overflow
- Do not allow any numbers to be inputted when asked for both (First & Last) names
- When asked for either (First & Last) Name, do not allow the user or the program to accept spaces between names
  - **Example**: `First Name: John Doe` is invalid because only one name is allowed when "First Name" is asked
- Create proper error handling for each case when user input is invalid:
  - No numerical characters allowed
  - No spaces between name
  - "Try again — invalid input"
  - ETC (up to you to add more)
- Tell the user if the names are identical or not
  - This directly means: if they are identical, watch out for capitalization
  - **Example**: Member 1: `John Doe`, Member 2: `john doe` — same names but one has caps, the other doesn't
  - Ensure the program catches this case
- When displaying **Alphabetical Order**, reprint the two members that were inputted by the user in alphabetical order
- If the user inputs names without first letter capitalization, add it
  - **Example**: `emily` → when reprinted throughout the program, fix to `Emily`

---

## Updated Requirements (Customer Discussion / In-Class PowerPoint)

> **IF THE ABOVE CONTRADICTS ANYTHING HERE, FOLLOW WHAT'S STATED HERE**

- If names are **BLANK**, only permit a **blank last name** (first name is required)
- Maximum length for first and last names: **40 characters**
- Hyphenated last names are supported
- Names with apostrophes are supported
- Alphabetical order is based on **Full Name** (first + last)
- When comparing names, **do NOT** ignore upper case and lower case — they are treated as different
  - **Example**: `Bob` and `bob` will be **different** when comparing

---

## Example Run

### Input (from user):

```
Member 1

First Name: Alice
Last Name: Johnson

Member 2

First Name: Brian
Last Name: Smith
```

### Output:

```
------------------------------------------
Riverside Public Library
Member Name Report
------------------------------------------
Member 1: Alice Johnson
Letters: 12

Member 2: Brian Smith
Letters: 10

The names are NOT identical
------------------------------------------
Alphabetical Order:
1. Alice Johnson
2. Brian Smith
------------------------------------------
```
