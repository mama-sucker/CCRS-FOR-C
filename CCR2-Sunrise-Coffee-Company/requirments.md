Sunrise Coffee Company

- only needs to display a single days sales
- Record the amount of coffee sold during the day
- needs to record 5 different numbers
    - each number corrisponds to 1 hour of the 5 hour day the amount of coffee sold

The program must allow the employee/user to enter the number of cups of coffee sold each hour
for a total of 5 inputs throughout the 5 hour day
- the program can stay running until 5 inputs given ints

example run:
    Sunrise Coffee Company
Enter the amount of coffee sold in the first hour: 6
    Number stored 4 left for the day
Enter thr amount of coffee sold in the seconf hour: 8
.
.
.
.
.
Total Coffee sold for the 5 hour period of day: x
Hour 1: 6 Hour 2: 8 Hour 3: X Hour 4: x Hour 5: x
        - Probably do a new line here for all the hours printed


Updated:

- Number of coffees sold can be large but not unlimited allowing a buffer overflow
- The program should not accept any other input such as chars,doubles,negatives only ints
- if the user does not enter a number and just presses enter it should be considered zero
        - but confirm with the user that this is okay
