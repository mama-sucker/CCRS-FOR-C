# CCR5 - Downtown Parking Services

For COP-3515 Programming in C Class

---

## Requirements

- One day parking activity only
- Start by asking for user input of three vehicles
- When inputting vehicle hours, only allow for ints and do not allow buffer overflow
- Maximum amount of hours for the vehicle to stay in the garage is:
- This will just be a print to TUI application, nothing will be saved to a file
- The parking garage fee is $2 per hour

## Updated Requirements

- Parking fee can be based per hour and a 1/4 hour
- Minimum parking charge can be $0 for zero hours
  - Like the customer went in and out of the garage
- Maximum daily parking charge: $50
- Customers can park in fractions, example 2.5 hours
  - Make sure this is safe and has error handling if the user tries to enter 2.5555555555555
- Negative parking times should also be denied and have error handling
- The average parking fee should be rounded to two decimal places
- If no vehicles are processed in the day, a value of $0.00 is valid

## Example Run

### Input

- Vehicle 1 Hours Parked: 2
- Vehicle 2 Hours Parked: 5
- Vehicle 3 Hours Parked: 3

**More Vehicles?** (Ask if the user wants to add more vehicles)

- `(y/n)` in the form `y` for yes, `n` for no

If more vehicles is `y` (yes):

- Vehicle 4 Hours Parked: 7
  - Start by adding another vehicle number and ask for the same input as above

### Print Output

When all user input is received:

```
------------------------------------------------------------
    Downtown Parking Services
    Parking Summary
------------------------------------------------------------

Vehicle 1 Charge: $4.00
Vehicle 2 Charge: $10.00
Vehicle 3 Charge: $6.00
Vehicle 4 Charge: $14.00

-------------------------------------------------------------

Vehicles Processed: 4 (the amount the user entered)

Total Revenue: $34.00 (Add up all the charges)

Average Parking Fee: $8.50

-------------------------------------------------------------
```
