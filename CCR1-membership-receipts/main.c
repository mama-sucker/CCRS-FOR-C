#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUF 256

/* Clear the input buffer */
void clear_input_buffer(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

/* Validate that a string is not blank/empty */
int is_valid_string(const char *str) {
  if (str == NULL || strlen(str) == 0)
    return 0;
  for (int i = 0; str[i]; i++) {
    if (!isspace((unsigned char)str[i]))
      return 1;
  }
  return 0;
}

// Validate age input and return a valid age, if over 65, notify user of senior
// discount eligibility
int get_valid_age(void) {
  int age;
  char buf[MAX_BUF];
  while (1) {
    printf("Enter customer's age: ");
    if (fgets(buf, sizeof(buf), stdin) != NULL) {
      /* Remove trailing newline */
      buf[strcspn(buf, "\n")] = '\0';
      /* Skip blank or whitespace-only input */
      if (!is_valid_string(buf)) {
        printf("Input cannot be blank. Please try again.\n");
        continue;
      }
      /* Parse the number from the string */
      if (sscanf(buf, "%d", &age) == 1 && age > 0 && age < 121) {
        /* Senior discount notification */
        if (age > 65) {
          printf("FYI customer applies for senior discount\n");
        }
        return age;
      }
    }
    printf("Customer must be old damn!\n");
    printf("Invalid age. Please enter a valid number (1-120): \n");
  }
}

/* Get a non-blank string input */
void get_non_blank_input(const char *prompt, char *buffer, int size) {
  while (1) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) != NULL) {
      /* Remove trailing newline */
      buffer[strcspn(buffer, "\n")] = '\0';
      if (is_valid_string(buffer)) {
        return;
      }
    }
    printf("Input cannot be blank. Please try again.\n");
  }
}

/*
 * Updated function to get non-blank input without spaces or digits, spaces
 * caused problems with the receipt ID generation, so we are disallowing spaces
 * in the first and last name fields. Also rejects numeric input (ints).
 */
void get_non_blank_no_spaces_input(const char *prompt, char *buffer, int size) {
  while (1) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) != NULL) {
      /* Remove trailing newline */
      buffer[strcspn(buffer, "\n")] = '\0';
      int has_space = strchr(buffer, ' ') != NULL;
      int has_digit = 0;
      for (int i = 0; buffer[i]; i++) {
        if (isdigit((unsigned char)buffer[i])) {
          has_digit = 1;
          break;
        }
      }
      if (is_valid_string(buffer) && !has_space && !has_digit) {
        return;
      }
    }
    printf("Input cannot be blank, cannot contain spaces or numbers. "
           "Please try again.\n");
  }
}

/*
 * Get input for last name — allows blank input but rejects spaces and digits
 * if something is entered.
 */
void get_last_name_input(const char *prompt, char *buffer, int size) {
  while (1) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) != NULL) {
      /* Remove trailing newline */
      buffer[strcspn(buffer, "\n")] = '\0';
      /* If blank, accept it */
      if (!is_valid_string(buffer)) {
        buffer[0] = '\0';
        return;
      }
      /* If not blank, check for spaces and digits */
      int has_space = strchr(buffer, ' ') != NULL;
      int has_digit = 0;
      for (int i = 0; buffer[i]; i++) {
        if (isdigit((unsigned char)buffer[i])) {
          has_digit = 1;
          break;
        }
      }
      if (!has_space && !has_digit) {
        return;
      }
    }
    printf("Input cannot contain spaces or numbers. "
           "Please try again.\n");
  }
}

// Get yes or no input from user, to see if they want to provide optional
// information
int get_yes_no(const char *prompt) {
  char buf[MAX_BUF];
  while (1) {
    printf("%s (y/n): ", prompt);
    if (fgets(buf, sizeof(buf), stdin) != NULL) {
      buf[strcspn(buf, "\n")] = '\0';
      if (buf[0] == 'y' || buf[0] == 'Y')
        return 1;
      if (buf[0] == 'n' || buf[0] == 'N')
        return 0;
    }
    printf("Please enter 'y' or 'n'.\n");
  }
}

/* Get monthly membership price */
double get_membership_price(void) {
  double price;
  char buf[MAX_BUF];
  while (1) {
    printf("Enter monthly membership price: $");
    if (fgets(buf, sizeof(buf), stdin) != NULL) {
      /* Remove trailing newline */
      buf[strcspn(buf, "\n")] = '\0';
      /* Skip blank or whitespace-only input */
      if (!is_valid_string(buf)) {
        printf("Input cannot be blank. Please try again.\n");
        continue;
      }
      /* Parse the number from the string */
      if (sscanf(buf, "%lf", &price) == 1 && price >= 0 && price <= 200) {
        return price;
      }
    }
    printf("membership price should not exceed $200 you scammer!\n");
    printf("Invalid price. Please enter a valid number ($0 - $200): ");
  }
}

/* Print receipt to TUI (console) */
void print_receipt_tui(const char *firstName, const char *lastName, int age,
                       double price, const char *phone, const char *gender,
                       int has_optional) {
  printf("\n");
  printf("========================================================\n");
  printf("       TAMPA FITNESS CENTER - MEMBERSHIP RECEIPT \n");
  printf("========================================================\n\n");

  time_t now = time(NULL);
  struct tm *t = localtime(&now);
  char date_str[64];
  strftime(date_str, sizeof(date_str), "%Y-%m-%d %H:%M:%S", t);

  printf("Date: %s\n", date_str);
  printf("Receipt ID: %s-%d\n\n", lastName, age);
  printf("--------------------------------------------------------\n");
  printf("  CUSTOMER INFORMATION\n");
  printf("--------------------------------------------------------\n");
  printf("  Customer Name: %s %s\n", firstName,
         lastName); // changed to print on same line
  // printf("  First Name:    %s\n", firstName);
  // printf("  Last Name:     %s\n", lastName);
  printf("  Age:           %d\n", age);

  if (age > 65) {
    printf("  Senior Discount: YES - Qualifies for senior discount \n");
  } else {
    printf("  Senior Discount: No\n");
  }

  if (has_optional) {
    printf("  Phone Number:  %s\n", phone);
    printf("  Gender:        %s\n", gender);
  }

  printf("\n--------------------------------------------------------\n");
  printf("  MEMBERSHIP DETAILS\n");
  printf("--------------------------------------------------------\n");
  printf("  Monthly Fee:   $%.2f\n", price);

  printf("\n========================================================\n");
  printf("  Thank you for joining Tampa Fitness Center!\n");
  printf("========================================================\n\n");
}

int main(void) {
  /* Display business name */
  printf("========================================================\n");
  printf("   TAMPA FITNESS CENTER - MEMBERSHIP RECEIPT \n");
  printf("========================================================\n\n");

  /* Get required fields */
  char firstName[MAX_BUF];
  char lastName[MAX_BUF];
  char phone[MAX_BUF];
  char gender[MAX_BUF];

  printf("--- REQUIRED FIELDS ---\n\n");

  get_non_blank_no_spaces_input("Enter first name: ", firstName,
                                sizeof(firstName));
  get_last_name_input("Enter last name: ", lastName, sizeof(lastName));

  int age = get_valid_age();

  double price = get_membership_price();

  /* Ask for optional fields */
  printf("\n--- OPTIONAL FIELDS ---\n\n");
  int has_optional = get_yes_no("Would you like to provide optional "
                                "information (phone number and gender)?");

  if (has_optional) {
    char temp[MAX_BUF];
    printf("Enter phone number (format: XXX-XXX-XXXX): ");
    if (fgets(temp, sizeof(temp), stdin) != NULL) {
      temp[strcspn(temp, "\n")] = '\0';
      strncpy(phone, temp, sizeof(phone) - 1);
      phone[sizeof(phone) - 1] = '\0';
    }

    printf("Enter gender: ");
    if (fgets(temp, sizeof(temp), stdin) != NULL) {
      temp[strcspn(temp, "\n")] = '\0';
      strncpy(gender, temp, sizeof(gender) - 1);
      gender[sizeof(gender) - 1] = '\0';
    }
  }

  /* Print receipt to TUI */
  print_receipt_tui(firstName, lastName, age, price, has_optional ? phone : "",
                    has_optional ? gender : "", has_optional);

  printf("\nProgram completed successfully.\n");
  return 0;
}
