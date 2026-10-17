# CCR7 - Green Valley Supply Company - Test Cases

## Acceptance Criteria

### Successful Transaction

```bash
student@9b36e72c8c17:/workspace/c/CCR7-Green-Valley-Supply-Company$ ./CCR7-Green-Valley
=======================================
Green Valley Supply Company
Inventory Management System
=======================================

Current Inventory: 100
Products Purchased: 10

=======================================
Green Valley Supply Company
Inventory Transaction Summary
=======================================

Inventory Before Sale: 100
Products Sold: 10
Inventory Remaining: 90

=======================================
```

---

## Test Cases

### Test Case 1: Load Inventory from File (Enter 0)

**Scenario:** Inventory is 0 but `inventory.txt` already has inventory (should pull from the text file).

**Expected Output:**
```
Error: Could not load inventory from file. Please enter a valid number.
```

**Issue:** `fgets` includes newline character in the buffer, causing `parse_long` to fail.

**Fix Applied:** Strip newline before parsing.

**Result:**
```
Loaded inventory from file: 90
```

---

### Test Case 2: Negative Inventory Input

**Scenario:** User enters a negative number for current inventory.

**Expected Output:**
```
Error: Negative input is not allowed.
```

---

### Test Case 3: Non-Integer Input (Characters)

**Scenario:** User enters characters instead of a number (e.g., `ABC`).

**Expected Output:**
```
Error: Invalid input. Please enter a valid integer.
```

---

### Test Case 4: Inventory Exceeds Maximum (100)

**Scenario:** User enters an inventory value over 100 (e.g., `101`).

**Expected Output:**
```
Error: Inventory cannot exceed 100.
```

---

### Test Case 5: Purchase Exceeds Inventory

**Scenario:** User tries to purchase more than available inventory.

**Input:**
- Inventory: 80
- Purchased: 90

**Expected Output:**
```
Error: Cannot purchase more than available inventory (80). Please try again.
```

---

### Test Case 6: Buffer Overflow Protection

**Scenario:** User enters an extremely large number to test buffer overflow protection.

**Input:**
```
Current Inventory: 122323123123123123123123131999999999999999999
```

**Expected Output:**
```
Error: Invalid input. Please enter a valid integer.
```
