// CCR5 - Downtown Parking Services
// gcc compile will fail unless you use the flags -lm
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEHICLES 10
#define MAX_INPUT 256
#define MAX_HOURS 24.0
#define RATES_PER_HOUR 2.0
#define RATES_PER_QUARTER 0.5
// cannot exceed $50 dollars per customer requirments
#define MAX_DAILY_CHARGE 50.0
#define SEPERATOR                                                              \
  "============================================================\n"

const char *ascii_art = "                                                      "
                        "   _________________________\n"
                        "                    /\\\\      _____          _____   "
                        "    |   |     |     |    | |  \\\n"
                        "     ,-----,       /  \\\\____/__|__\\_    "
                        "___/__|__\\___   |___|_____|_____|____|_|___\\\n"
                        "  ,--'---:---`--, /  |  _     |     `| |      |      "
                        "`| |                    | |    \\\n"
                        " ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)' "
                        "  `--(o)(o)--------------(o)--'\n"
                        "``````````````````````````````````````````````````````"
                        "```````````````````````````````\n";

double get_valid_hours(void) {
  char buffer[MAX_INPUT];
  while (1) {
    printf("Enter hours parked: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
      printf("Input error. Please try again.\n");
      while (getchar() != '\n')
        ; // Clear buffer
      continue;
    }
    // Remove newline
    buffer[strcspn(buffer, "\n")] = '\0';

    // Check for empty input
    if (buffer[0] == '\0') {
      printf("Invalid input. Please enter a non-negative number.\n");
      continue;
    }

    // Check if input is too long (more than 10 decimal places)
    char *dot = strchr(buffer, '.');
    if (dot != NULL) {
      int decimal_len = (int)strlen(dot) - 1;
      if (decimal_len > 10) {
        printf("Too many decimal places. Please enter a value with 10 or fewer "
               "decimal places.\n");
        continue;
      }
    }

    // Check for negative sign
    if (buffer[0] == '-') {
      printf("Invalid input. Please enter a non-negative number.\n");
      continue;
    }

    // Check for multiple dots
    int dot_count = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
      if (buffer[i] == '.')
        dot_count++;
    }
    if (dot_count > 1) {
      printf("Invalid input. Please enter a valid number.\n");
      continue;
    }

    // Check for non-numeric characters (except dot)
    for (int i = 0; buffer[i] != '\0'; i++) {
      if (buffer[i] != '.' && !isdigit((unsigned char)buffer[i])) {
        printf("Invalid input. Please enter a non-negative number.\n");
        continue;
      }
    }

    // Parse as double
    char *endptr;
    double hours = strtod(buffer, &endptr);

    // Check for valid conversion
    if (endptr == buffer || *endptr != '\0') {
      printf("Invalid input. Please enter a non-negative number.\n");
      continue;
    }

    // Check for negative or zero
    if (hours < 0) {
      printf("Invalid input. Please enter a non-negative number.\n");
      continue;
    }

    // Check maximum hours
    if (hours > MAX_HOURS) {
      printf("Maximum parking hours is %.1f. Please enter a value between 0 "
             "and %.1f.\n",
             MAX_HOURS, MAX_HOURS);
      continue;
    }

    return hours;
  }
}

double calculate_charge(double hours) {
  // Calculate charge based on hours and quarter hours
  double charge = 0.0;

  // Full hours at $2/hour
  double full_hours = floor(hours);
  charge += full_hours * RATES_PER_HOUR;

  // Remaining time as quarter hours (rounded up to nearest quarter)
  double remaining = hours - full_hours;
  if (remaining > 0) {
    // Round up to nearest 0.25 hours
    double quarters = ceil(remaining / 0.25);
    charge += quarters * RATES_PER_QUARTER;
  }

  // Cap at maximum daily charge
  if (charge > MAX_DAILY_CHARGE) {
    charge = MAX_DAILY_CHARGE;
  }

  return charge;
}

int main(void) {
  double vehicles[MAX_VEHICLES];
  int count = 0;
  char more[2];

  printf("Welcome to Downtown Parking Services!\n\n");

  // Initial 3 vehicles
  for (int i = 0; i < 3; i++) {
    printf("Vehicle %d - Hours Parked: ", i + 1);
    vehicles[count++] = get_valid_hours();

    if (count >= MAX_VEHICLES) {
      printf("Maximum number of vehicles reached.\n");
      break;
    }
  }

  // Ask if user wants to add more vehicles
  printf("More vehicles? (y/n): ");
  if (fgets(more, sizeof(more), stdin) == NULL) {
    // No more vehicles, proceed to summary
  } else {
    more[strcspn(more, "\n")] = '\0';

    // Continue adding vehicles if user says yes
    while ((more[0] == 'y' || more[0] == 'Y') && count < MAX_VEHICLES) {
      printf("Vehicle %d - Hours Parked: ", count + 1);
      vehicles[count++] = get_valid_hours();

      if (count >= MAX_VEHICLES) {
        printf("Maximum number of vehicles reached.\n");
        break;
      }

      printf("More vehicles? (y/n): ");
      if (fgets(more, sizeof(more), stdin) == NULL) {
        break;
      }
      more[strcspn(more, "\n")] = '\0';
    }
  }

  // Print summary
  printf("\n");
  printf(SEPERATOR);
  printf("%s", ascii_art);
  printf("\tDowntown Parking Services Parking Summary\n");
  printf(SEPERATOR);

  double total_revenue = 0.0;

  for (int i = 0; i < count; i++) {
    double charge = calculate_charge(vehicles[i]);
    printf("Vehicle %d Charge: $%.2f\n", i + 1, charge);
    total_revenue += charge;
  }

  printf("\n%s", SEPERATOR);
  printf("\nVehicles Processed: %d\n", count);
  printf("Total Revenue: $%.2f\n", total_revenue);

  if (count > 0) {
    double average = total_revenue / count;
    printf("Average Parking Fee: $%.2f\n", average);
  } else {
    printf("Average Parking Fee: $0.00\n");
  }

  printf("\n%s", SEPERATOR);

  return 0;
}
