========================================================================
NORMAL RUNS - FULL SCENARIOS
========================================================================

SCENARIO 1: Alice, Age: 72, Fee: $39.95 (with optional fields, senior discount)
    INPUT:
    Enter first name: Alice
    Enter last name: <BLANK>
    Enter customer's age: 72
    Enter monthly membership price: $39.95
    Would you like to provide optional information (phone number and gender)? (y/n): n

student@592119c194a5:/workspace/c/CCR1-membership-receipts$ ./CCR-001
========================================================
   TAMPA FITNESS CENTER - MEMBERSHIP RECEIPT
========================================================

--- REQUIRED FIELDS ---

Enter first name: Alice
Enter last name:
Enter customer's age: 72
FYI customer applies for senior discount
Enter monthly membership price: $39.95

--- OPTIONAL FIELDS ---

Would you like to provide optional information (phone number and gender)? (y/n): n

========================================================
       TAMPA FITNESS CENTER - MEMBERSHIP RECEIPT
========================================================

Date: 2026-08-28 13:46:20
Receipt ID: -72

--------------------------------------------------------
  CUSTOMER INFORMATION
--------------------------------------------------------
  Customer Name: Alice
  Age:           72
  Senior Discount: YES - Qualifies for senior discount

--------------------------------------------------------
  MEMBERSHIP DETAILS
--------------------------------------------------------
  Monthly Fee:   $39.95

========================================================
  Thank you for joining Tampa Fitness Center!
========================================================


Program completed successfully.




SCENARIO 2: Brian, Age: 31, Fee: $29.95 (no optional fields, no senior discount)
    INPUT:
    Enter first name: Brian
    Enter last name: <BLANK>
    Enter customer's age: 31
    Enter monthly membership price: $29.95
    Would you like to provide optional information (phone number and gender)? (y/n): n

student@592119c194a5:/workspace/c/CCR1-membership-receipts$ ./CCR-001
========================================================
   TAMPA FITNESS CENTER - MEMBERSHIP RECEIPT
========================================================

--- REQUIRED FIELDS ---

Enter first name: Brian
Enter last name:
Enter customer's age: 31
Enter monthly membership price: $29.95

--- OPTIONAL FIELDS ---

Would you like to provide optional information (phone number and gender)? (y/n): n

========================================================
       TAMPA FITNESS CENTER - MEMBERSHIP RECEIPT
========================================================

Date: 2026-08-28 13:47:42
Receipt ID: -31

--------------------------------------------------------
  CUSTOMER INFORMATION
--------------------------------------------------------
  Customer Name: Brian
  Age:           31
  Senior Discount: No

--------------------------------------------------------
  MEMBERSHIP DETAILS
--------------------------------------------------------
  Monthly Fee:   $29.95

========================================================
  Thank you for joining Tampa Fitness Center!
========================================================


Program completed successfully.
