
CCR 7 - For COP-3515 Programming in C

Green Valley Supply Company
------------------------------------------------

Program Requirments:

- Enter the current amount of products avalible in inventory
	- Only allow the input of ints, no chars and no decimal leading numbers
	- negative numbers are not allowed, also no 0
	- max limit for products avalible is: 100

- Enter the number of products purchased by a customer
	- Only allow the input of ints, no chars and no decimal leading numbers
	- negative numbers are not allowed, also no 0
	- max limit for products purchased by customer is matched with the inventory

- The program should:
	- Determine the updated inventory after the user input
	- Display the number of products sold during the current customer purchase
	- Display the updated inventory remaining after the sale

- Do not allow for bufferoverflow on any of the user inputs
- When any information by the user is not of the appropriate input reject with proper 	 	error handling such as
			EX: Current Inventory: -10 -- Negative input is not allowed

- Saving any information to a file is not needed all output will just be tempororary in 	the TUI window
- This will be a simple math conversion and print to TUI program


Updated Requirments after customer communication or (PowerPoint) updated slides:
- customer cannot purchase more than what the invetory allows ERROR & Retry
- Inventory value of 0 is allowed
- Inventory should be updated after every successful sale
- Inventory can be stored in a file name (inventory.txt) when a new number is entered for inventory it will be overwritten, but if the user enters in 0 for inventory it will pull from the file assuming the inventory has not changed



---------------------------------------------------------
Example Run:

Input:
Current Inventory: 250
Products Purchased: 18
Output:
=======================================
Green Valley Supply Company
Inventory Transaction Summary
=======================================

Inventory Before Sale: 250
Products Sold: 18
Inventory Remaining: 232

=======================================
----------------------------------------------------------
