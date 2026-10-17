Acceptance Criteria:
    anonymous-mac@pop-os:~/code/COP3515-repo/c/CCR2-Sunrise-Coffee-Company$ ./CCR2-sunrise
    Sunrise Coffee Company
    Enter the amount of coffee sold in the first hour: 12
        Number stored, 4 left for the day
    Enter the amount of coffee sold in the second hour: 6
        Number stored, 3 left for the day
    Enter the amount of coffee sold in the third hour: 0
        Number stored, 2 left for the day
    Enter the amount of coffee sold in the fourth hour: 23
        Number stored, 1 left for the day
    Enter the amount of coffee sold in the fifth hour: 9
        Number stored, 0 left for the day

    Total Coffee sold for the 5 hour period of day: 50
    Hour 1: 12  Hour 2: 6  Hour 3: 0  Hour 4: 23  Hour 5: 9


Test-Cases:

- what if you enter no number and just press enter:
    - Set the value to zero but ask user to confirm zero for the hour first

        Sunrise Coffee Company
        Enter the amount of coffee sold in the first hour:
            Number of cups sold for the hour will be 0 (y/n): y
            Number stored, 4 left for the day
        Enter the amount of coffee sold in the second hour:

- what if the user enters chars instead of ints (ABC)
        Sunrise Coffee Company
        Enter the amount of coffee sold in the first hour: abxc
            Error: enter a whole number
        Enter the amount of coffee sold in the first hour:


- what if the user enters a decimal (5.123) instead of a whole number
        Enter the amount of coffee sold in the first hour: 5.123
            Error: enter a whole number
        Enter the amount of coffee sold in the first hour:

- what is the user inputs a negative value (-10)
        Sunrise Coffee Company
        Enter the amount of coffee sold in the first hour: -10
            Error: enter a whole number
        Enter the amount of coffee sold in the first hour

- what is the number of cups sold is out of this world: 999999999999999999999999999999
        Sunrise Coffee Company
        Enter the amount of coffee sold in the first hour: 99999999999999999999999999999999999999999999999999999999999999999
            Error: number too large
        Enter the amount of coffee sold in the first hour:
