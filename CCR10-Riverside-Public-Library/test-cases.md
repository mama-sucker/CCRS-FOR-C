# CCR10 - Test Cases

## Acceptance Criteria

```bash
student@9b36e72c8c17:/workspace/c/CCR10-Riverside-Public-Library$ ./CCR10-Riverside

Member 1
First Name: Alice
Last Name: Johnson

Member 2
First Name: Brian
Last Name: Smith

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

---

## Test Cases

### Test Case 1: Input a number when asked for the name

- **Input**: `First Name: 123`
- **Old Output**: `Error: Invalid input. No numbers or spaces allowed.`
- **Note**: I need to fix the error handling — it still says "no spaces allowed" but in class we decided that spaces would be allowed, and the program would account for the spaces
- **New Output**: `Error: Invalid input. No numbers allowed`

### Test Case 2: Character buffer overflow

- **Input**: `Last Name: AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA`
- **Old Output**: `Program did experience a bufferover will have to fixed`
- **New Output**: `Error: Character limit exceeded (max 40 characters)`

### Test Case 3: Press enter for first name (blank)

- **Input**: Press Enter (blank first name)
- **Note**: Program had a problem, have to fix it — should allow no last name
- **Output**: `Error: First name is required`
