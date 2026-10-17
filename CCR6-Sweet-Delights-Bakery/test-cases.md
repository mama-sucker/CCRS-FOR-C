Acceptance Critera:
    student@9b36e72c8c17:/workspace/c/CCR6-Sweet-Delights-Bakery$ ./CCR6-Delight
    Order Amount: $25

    ========================================
                    Sweet Delights Bakery
                    Customer Receipt
    ========================================

    Original Order: $25.00
    Sales Tax: $1.50
    Discount: None

    ========================================

    Final Total: $26.50
    ========================================

Test-Cases:

- (More or less a personal question):
    - i was wondering about the customer discount and how it should be implemented,
    after hearing that the customer discount wont always be the same amount i thought
    how to impliment that and i make it so it would be random 50/50 chance they get it
    and the customer could possibly recieve a 100% discount

- What if for the (Order Amount) the user enters non numeric characters:
    - Order Amount: $ABC
    Error: Invalid input. Please enter a numeric value (e.g., 25.00).

- What if the user enters in a negative Order amount:
    -Order Amount: $-10
    Error: Invalid input. Please enter a numeric value (e.g., 25.00).

- What if the user tries to do a buffer-overflow:
    -Order Amount: $999999999999999999999999999999999999999999999999999999999999999999999999
    Error: Order amount cannot exceed $5000.00.
