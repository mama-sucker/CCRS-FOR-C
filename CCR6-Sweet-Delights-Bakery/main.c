// CCR6 - Sweet Delights Bakery
// COP-3515 Programming in C

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ============================================================
// CONFIGURABLE RATES - Edit these values as needed
// ============================================================
#define SALES_TAX_RATE 0.06 // 6% sales tax
// ============================================================

#define MAX_ORDER_AMOUNT 5000.00 // Maximum order total: $5,000
#define INPUT_BUFFER_SIZE 64     // Prevent buffer overflow
#define SEP "========================================\n"

/**
 * Round to the nearest nickel (5 cents)
 * Multiply by 20, round to nearest integer, divide by 20
 */
double round_to_nickel(double amount) { return round(amount * 20.0) / 20.0; }

/**
 * Validate and get order amount from user
 * - Only accepts numeric values
 * - No negative amounts
 * - No zero
 * - Maximum $5,000
 * - Prevents buffer overflow
 */
double get_order_amount() {
  char input[INPUT_BUFFER_SIZE];
  double amount;

  while (1) {
    printf("Order Amount: $");

    // Read input safely with buffer overflow protection
    if (fgets(input, sizeof(input), stdin) == NULL) {
      printf("Error reading input.\n");
      continue;
    }

    // Remove trailing newline if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
      input[len - 1] = '\0';
    }

    // Check for empty input
    if (strlen(input) == 0) {
      printf("Error: Please enter a valid order amount.\n");
      continue;
    }

    // Validate that input contains only numeric characters (digits and one
    // decimal point)
    int has_dot = 0;
    int valid = 1;
    for (int i = 0; input[i] != '\0'; i++) {
      if (input[i] == '.') {
        if (has_dot) { // More than one decimal point
          valid = 0;
          break;
        }
        has_dot = 1;
      } else if (input[i] < '0' || input[i] > '9') {
        // Not a digit or decimal point
        valid = 0;
        break;
      }
    }

    if (!valid) {
      printf("Error: Invalid input. Please enter a numeric value (e.g., "
             "25.00).\n");
      continue;
    }

    // Convert to double
    amount = atof(input);

    // Check for zero or negative
    if (amount <= 0.0) {
      printf("Error: Order amount must be greater than zero.\n");
      continue;
    }

    // Check for maximum order amount
    if (amount > MAX_ORDER_AMOUNT) {
      printf("Error: Order amount cannot exceed $%.2f.\n", MAX_ORDER_AMOUNT);
      continue;
    }

    // Valid input
    return amount;
  }
}

/**
 * Print the customer receipt
 */
void print_receipt(double original, double discount, double tax,
                   double final_total, int gets_discount,
                   double discount_percentage) {
  printf("\n");
  printf("%s", SEP);
  printf("\t\tSweet Delights Bakery\n");
  printf("\t\t   Customer Receipt\n");
  printf("%s", SEP);
  printf("\n");
  printf("Original Order: $%.2f\n", original);
  printf("Sales Tax: $%.2f\n", tax);
  if (gets_discount) {
    printf("Discount: %.0f%% ($%.2f)\n", discount_percentage * 100.0, discount);
  } else {
    printf("Discount: None\n");
  }
  printf("\n");
  printf("%s", SEP);
  printf("\n");
  printf("Final Total: $%.2f\n", final_total);
  printf("%s", SEP);
}

int main() {
  // Seed the random number generator
  srand((unsigned int)time(NULL));

  // Get order amount from user
  double order_amount = get_order_amount();

  // Calculate sales tax on original order amount
  double sales_tax = order_amount * SALES_TAX_RATE;

  // Add tax to get subtotal
  double subtotal_with_tax = order_amount + sales_tax;

  // Randomly determine if customer gets a discount (50/50 chance)
  int gets_discount = rand() % 2; // 0 = no discount, 1 = gets discount

  double discount_amount = 0.0;
  double discount_percentage = 0.0;

  if (gets_discount) {
    // Random discount percentage between 1% and 100%
    discount_percentage = (double)(rand() % 100 + 1) / 100.0;
    discount_amount = subtotal_with_tax * discount_percentage;
  }

  // Calculate final total
  double final_total = subtotal_with_tax - discount_amount;

  // Round to nearest nickel
  final_total = round_to_nickel(final_total);

  // Print the receipt
  print_receipt(order_amount, discount_amount, sales_tax, final_total,
                gets_discount, discount_percentage);

  return 0;
}
