# Grand Cinema Theater Company

## User Input

- Customer's age
- Type of day: two options — weekday or weekend
  - Use 1 for weekday or 2 for weekend

## After Input

- Three ticket categories created:
  - **Child Ticket** (age 12 or under) — do not allow the input of zero, that would be impossible
  - **Adult Ticket** (age 18+)
  - **Senior Ticket** (age 60+)

## Example Run

### Input:

```
Customer Age: 10
What type of day is it press W for weekday or E for weekend
  ** no other input should be allowed other than W & E, else reject and retry
Day Type: 2
```

### Output:

```
Grand Cinema Theater

Ticket Classification
===============================

Customer Age: 10
Day Type: Weekend
===============================
Ticket Type: Child ticket
```

## Extra Requirements

- Max age of customer should be 100
  - Age input should only allow ints, nothing else

