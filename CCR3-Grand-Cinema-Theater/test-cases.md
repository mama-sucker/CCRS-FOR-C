Acceptance Criteria:
    student@9b36e72c8c17:/workspace/c/CCR3-Grand-Cinema-Theater$ ./CCR3-Cinema
    Customer Age: 10
    What type of day is it press W for weekday or E for weekend
    Day Type: e

    Grand Cinema Theater

    Ticket Classification
    ===============================

    Customer Age: 10
    Day Type: Weekend
    ===============================
    Ticket Type: Child ticket

Test-cases:

- What is a char is entered for age instead of a number
    Customer Age: aa
    Try again. Age should be between 1-99
    Customer Age:

- what if a fraction number is entered for age instead of a whole number
    Customer Age: 12.8
    Try again. Age should be between 1-99
    Customer Age:

- what if for the weekday selection you put in lowercase "e" or "w"
    Day Type: e

    Grand Cinema Theater

    Ticket Classification
    ===============================

    Customer Age: 18
    Day Type: Weekend
    ===============================
    Ticket Type: Adult ticket

- what if the user enters a int for the weekday instead of "W" or "E"
    Day Type: 11
    Try again!
    What type of day is it press W for weekday or E for weekend
    Day Type:
