# CCR6 - Sweet Delights Bakery

For COP-3515 Programming in c class

## Requirments (By-me):

- only need to run one order at a time
- no need to save receipt only terminal output
- for order total it should only accept numeric values no chars
- Don't allow for buffer overflow from user when entering in the (order amount)
- The program only need to calculate the rates for one customer at a given time
- The value of zero for (Order Amount): Should be considered invalid!
- make the sales tax and percentage easiy accessable at the top so that the user can change values as needed
- The discount should be a const in the program but it can be edited and re-compiled later
  - As for the discount apply the same logic to the sales tax

## Requirments (From Class suggestions) customer questions:

- Current tax rate: 6%
- discount based off percent
- every customer does not recieve a discount
- discount is applied after sales tax
- Round to the nearest nickle - no more pennies
- Negative amounts should not be accepted
- maximum order total: $5,0000

## Example Run:

**Input:**

```
Order Amount: $25.00
```

**Output:**

```
========================================
		Sweet Delights Bakery
		   Customer Receipt
========================================

Original Order: $25.00
Discount: $2.50
Sales Tax: $1.58

========================================

Final Total: $24.08
---------------------------------------------------------------------
```
