test cases for the receipt printer

1. Entering in a full first and last name with a space when prompted to enter just the first name:
    EX: Enter first name: John Doe
    - Originally the code let this execute causing miss information and incorrect formatting for the receipt printout
    - why?: to see if the program would allow incorrect formatting and let the output be wonky

2. Entering in a number while prompted to enter a name:
    EX: Enter first name: John123
    - Originally the code would also allow this to execute no problem
    - why?: to see if the program would allow numbers in areas that would be invalid and useless

3. Entering in a character when prompted to enter an int value:
    EX: Enter customer's age: abc
    - why?: to see if the program would allow invalid character placement where there should only be a number

4. After user has entered age value over 65, seeing if the program would tell the user that they qualify for senior discount:
    EX: Enter customer's age: 70
        FYI customer applies for senior discount
    - why?: to make sure the senior discount notification actually triggers when age > 65

5. Entering in a customer's age over three digits or over 120:
    EX: Enter customer's age: 125 && 1000 && ETC
    - why?: to see if the program would accept a dumb number that would be impossible for human nature

6. Similar to the last, entering in an out of scope number for monthly membership price:
    EX: Enter monthly membership price: 500 && 6000 && ETC
    - why?: to see if the program would correct for outrageous ints when talking about a gym membership price

7. Testing spaces and blank enters:
    EX: Enter monthly membership price: <BLANK>
    - why?: to see how the program handles not entering information where required

8. Entering in a blank first or last name (just pressing enter):
    EX: Enter first name: <ENTER>
    - why?: to make sure the program rejects empty input and forces the user to enter something

9. Entering in a character when prompted for membership price:
    EX: Enter monthly membership price: abc
    - why?: to see if the program would catch non-numeric input where a dollar amount is expected

10. Testing yes/no prompt for optional fields (phone number and gender):
    EX: Would you like to provide optional information (phone number and gender)? (y/n): y
        Enter phone number (format: XXX-XXX-XXXX): 555-123-4567
        Enter gender: Male
    - why?: to make sure the optional fields work when user says yes

11. Testing yes/no prompt for optional fields - no:
    EX: Would you like to provide optional information (phone number and gender)? (y/n: n
    - why?: to make sure the program skips phone and gender when user says no

12. Testing invalid response to yes/no prompt:
    EX: Would you like to provide optional information (phone number and gender)? (y/n): maybe
        Please enter 'y' or 'n'.
    - why?: to see if the program rejects invalid responses and re-prompts the user

13. Entering in a blank last name (just pressing enter for last name):
    EX: Enter first name: John
        Enter last name: <ENTER>
    - why?: to see if the program allows a blank last name and how it handles the receipt output when last name is NULL or empty
