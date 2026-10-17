CCR 1 - Basic Receipt Printer for Tampa Fitness Center
		** Do they have to be made by AI???
		** I made the requirments my self and had ai format them

Business:
	- Business name: "Tampa Fitness Center - Receipt Printer"
		- start program with a banner like this

Requirements:
- User Input
	- Application must accept user input via TUI (Text User Interface) only
	- Membership fee will also be an input by employee

Required Fields:
	- First name & Last name
		- make sure that when the input for name is ran that just pressing enter or a (BLANK)
			input should be considered invalid
	- Customers Age
		- Based on age if the customer is over the age of 65 the receipt should state
			that they qualify for a senior discount
	- Monthly membership price, an input from a user of the program

Optional Fields:
	- **** go through required fields first then ask y/n for optional
	- Phone number
	- Gender

Running:
	- well simple enough ask for all the inputs note down whats required and whats not
	- combile all into a professional looking receipt printer based on the TUI

Output:
	- Generate a professional receipt in `.md` or `.pdf` format
		- perferred & easier would be a mark down file
	- Save all receipts in a `customers` folder within the project directory
	- Store receipt in the project directory as `lastnamefirstname-age`
	- should be firstly shown in the TUI exactly like it should be a receipt
	- then print where the receipt has been saved
