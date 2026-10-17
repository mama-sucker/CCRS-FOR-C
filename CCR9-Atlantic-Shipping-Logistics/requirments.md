# CCR9 - Atlantic Shipping & Logistics

For COP-3515 Programming in C

---

## Requirements

- The program will only need to process one package at a time
- The program will only be a simple TUI based app
- The user input of all dimensions should be limited to only the input of numbers
  - no characters, but i can accept decimal numbers
- The input of measurements should be sanitized to not allow bufferoverflow states
- If the user inputs an invalid measurment (EX: ABC), the program should promt and error
  - (EX: Invalid Input, make sure you input valid dimenstions) then allow the user to retry
- The program must accuratly calculate the boxes cubic units & square units based on
  users inputs

- There should be a limit on the maximum dimensions (input from user)
  - Length maximum: 39'
  - Width maximum: 7' 5"
  - Height maximum: 7' 6"

## Requirements after customer discussion / (in class powerpoint)

> *IF THE ABOVE CONTRADICTS ANYTHING HERE FOLLOW WHATS STATED HERE*

- units of measurments: inches
- decimal values allowed
- input of zero not allowed
- negative values not allowed
- decimal places two spaces
- do not round calculations
- calculations should be performed independently (in a function)

---

## Example Run

```
---------------------------------------------------
Input the shipping box dimensions (in inches)
-INPUT:
Length: 10
Width: 8
Height: 6
---------------------------------------------------
-OUTPUT:
---------------------------------------------------
Atlantic Shipping and Logistics
Package Measurment Report
---------------------------------------------------
Length: 10.00 Width: 8.00 Height: 6.00
---------------------------------------------------
Volume: 480.00 cubic units
Surface Area: 376.00 square units
```
