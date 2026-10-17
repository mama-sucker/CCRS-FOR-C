Acceptance Criteria:
student@9b36e72c8c17:/workspace/c/CCR5-Downtown-Parking$ ./CCR5-Downtown
Welcome to Downtown Parking Services!

Vehicle 1 - Hours Parked: Enter hours parked: 2
More vehicles? (y/n): y
Vehicle 2 - Hours Parked: Enter hours parked: Invalid input. Please enter a non-negative number.
Enter hours parked: 5
More vehicles? (y/n): y
Vehicle 3 - Hours Parked: Enter hours parked: Invalid input. Please enter a non-negative number.
Enter hours parked: 3
More vehicles? (y/n): y
Vehicle 4 - Hours Parked: Enter hours parked: Invalid input. Please enter a non-negative number.
Enter hours parked: 7
More vehicles? (y/n): n

------------------------------------------------------------
        Downtown Parking Services
        parking Summary
------------------------------------------------------------
Vehicle 1 Charge: $4.00
Vehicle 2 Charge: $10.00
Vehicle 3 Charge: $6.00
Vehicle 4 Charge: $14.00

------------------------------------------------------------

Vehicles Processed: 4
Total Revenue: $34.00
Average Parking Fee: $8.50

------------------------------------------------------------


TEST-CASES:

- What if i put in a char for hours parked:
    - Example: Vehicle 1 - Hours Parked: Enter hours parked: ABC
    -Output: Invalid input. Please enter a non-negative number.

- what if i eneter a crazy decimal number:
    - Example: Vehicle 1 - Hours Parked: Enter hours parked: 2.555555555555555555555555555555555555555555555555555555
    - Output: Too many decimal places. Please enter a value with 10 or fewer decimal places.

- what if i enter in a negative hours for the vehicle parked:
    - Example: Enter hours parked: -5
    - Output: Invalid input. Please enter a non-negative number

- What if when asked for a input on hours parked i leave the value NULL:
    - Example: Enter hours parked: <Nothing is entered, new line>
    - Output: Invalid input. Please enter a non-negative number.
              Enter hours parked:

- What if all numbers are zero for times parked should be valid just checking:
    - Output:
        Welcome to Downtown Parking Services!

    Vehicle 1 - Hours Parked: Enter hours parked: 0
    More vehicles? (y/n): n

    ------------------------------------------------------------
            Downtown Parking Services
            parking Summary
    ------------------------------------------------------------
    Vehicle 1 Charge: $0.00

    ------------------------------------------------------------

    Vehicles Processed: 1
    Total Revenue: $0.00
    Average Parking Fee: $0.00

    ------------------------------------------------------------
