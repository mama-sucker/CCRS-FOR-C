test cases output for the receipt printer

1. Entering in a full first and last name with a space when prompted to enter just the first name:
    EX: Enter first name: John Doe
    PROGRAM OUTPUT:
    Enter first name: John Doe
    Input cannot be blank, cannot contain spaces or numbers. Please try again.
    Enter first name:
    - The program rejected the input because it contained a space and re-prompted the user

2. Entering in a number while prompted to enter a name:
    EX: Enter first name: John123
    PROGRAM OUTPUT:
    Enter first name: John123
    Input cannot be blank, cannot contain spaces or numbers. Please try again.
    Enter first name:
    - The program rejected the input because it contained numbers and re-prompted the user

3. Entering in a character when prompted to enter an int value:
    EX: Enter customer's age: abc
    PROGRAM OUTPUT:
    Enter customer's age: abc
    Customer must be old damn!
    Invalid age. Please enter a valid number (1-120):
    - The program rejected the non-numeric input and re-prompted the user

4. After user has entered age value over 65, seeing if the program would tell the user that they qualify for senior discount:
    EX: Enter customer's age: 70
    PROGRAM OUTPUT:
    Enter customer's age: 70
    FYI customer applies for senior discount
    - The program accepted the age and displayed the senior discount notification

5. Entering in a customer's age over three digits or over 120:
    EX: Enter customer's age: 125
    PROGRAM OUTPUT:
    Enter customer's age: 125
    Customer must be old damn!
    Invalid age. Please enter a valid number (1-120):
    - The program rejected the age because it exceeded 120 and re-prompted the user

6. Similar to the last, entering in an out of scope number for monthly membership price:
    EX: Enter monthly membership price: 500
    PROGRAM OUTPUT:
    Enter monthly membership price: $500
    membership price should not exceed $200 you scammer!
    Invalid price. Please enter a valid number ($0 - $200):
    - The program rejected the price because it exceeded $200 and re-prompted the user

7. Testing spaces and blank enters:
    EX: Enter monthly membership price: <SPACES>
    PROGRAM OUTPUT:
    Enter monthly membership price: $
    Input cannot be blank. Please try again.
    Enter monthly membership price: $
    - The program rejected the blank/space-only input and re-prompted the user

8. Entering in a blank first or last name (just pressing enter):
    EX: Enter first name: <ENTER>
    PROGRAM OUTPUT:
    Enter first name:
    Input cannot be blank, cannot contain spaces or numbers. Please try again.
    Enter first name:
    - The program rejected the blank input and re-prompted the user

9. Entering in a character when prompted for membership price:
    EX: Enter monthly membership price: abc
    PROGRAM OUTPUT:
    Enter monthly membership price: $abc
    membership price should not exceed $200 you scammer!
    Invalid price. Please enter a valid number ($0 - $200):
    - The program rejected the non-numeric input and re-prompted the user

10. Testing yes/no prompt for optional fields (phone number and gender):
    EX: Would you like to provide optional information (phone number and gender)? (y/n): y
    PROGRAM OUTPUT:
    Would you like to provide optional information (phone number and gender)? (y/n): y
    Enter phone number (format: XXX-XXX-XXXX): 555-123-4567
    Enter gender: Male
    - The program accepted the yes response and prompted for phone number and gender

11. Testing yes/no prompt for optional fields - no:
    EX: Would you like to provide optional information (phone number and gender)? (y/n): n
    PROGRAM OUTPUT:
    Would you like to provide optional information (phone number and gender)? (y/n): n
    - The program accepted the no response and skipped the optional fields

12. Testing invalid response to yes/no prompt:
    EX: Would you like to provide optional information (phone number and gender)? (y/n): maybe
    PROGRAM OUTPUT:
    Would you like to provide optional information (phone number and gender)? (y/n): maybe
    Please enter 'y' or 'n'.
    Would you like to provide optional information (phone number and gender)? (y/n):
    - The program rejected the invalid response and re-prompted the user

13. Entering in a blank last name (just pressing enter for last name):
    EX: Enter first name: John
        Enter last name: <ENTER>
    PROGRAM OUTPUT:
    Enter first name: John
    Enter last name:
    Enter customer's age: 30
    Enter monthly membership price: $50
    Would you like to provide optional information (phone number and gender)? (y/n): n

    ========================================================
           TAMPA FITNESS CENTER - MEMBERSHIP RECEIPT
    ========================================================

    Date: 2026-08-28 13:39:31
    Receipt ID: -30

    --------------------------------------------------------
      CUSTOMER INFORMATION
    --------------------------------------------------------
      Customer Name: John
      Age:           30
      Senior Discount: No

    --------------------------------------------------------
      MEMBERSHIP DETAILS
    --------------------------------------------------------
      Monthly Fee:   $50.00

    ========================================================
      Thank you for joining Tampa Fitness Center!
    ========================================================

    Program completed successfully.
    - The program accepted the blank last name and displayed the receipt with an empty last name. The Receipt ID shows "-30" because the last name was NULL/empty. The Customer Name line shows only "John" with no last name appended.
