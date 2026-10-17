// CCR9 - Atlantic Shipping & Logistics

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I like = instead of - for the separator line, so I defined it as a constant
#define SEP "===================================================\n"
// Maximum dimensions in inches
#define MAX_LENGTH (39.0 * 12.0 + 0.0) // 39' = 468 inches Maximum
#define MAX_WIDTH (7.0 * 12.0 + 5.0)   // 7' 5" = 89 inches Maximum
#define MAX_HEIGHT (7.0 * 12.0 + 6.0)  // 7' 6" = 90 inches Maximum

// Function prototypes
double get_dimension(const char *dimension_name, double max_value);
double calculate_volume(double length, double width, double height);
double calculate_surface_area(double length, double width, double height);
void print_report(double length, double width, double height, double volume,
                  double surface_area);

int main(void) {
  double length = 0.0;
  double width = 0.0;
  double height = 0.0;
  double volume = 0.0;
  double surface_area = 0.0;

  printf("Input the shipping box dimensions (in inches)\n");

  // Get each dimension with validation
  length = get_dimension("Length", MAX_LENGTH);
  width = get_dimension("Width", MAX_WIDTH);
  height = get_dimension("Height", MAX_HEIGHT);

  // Calculate volume and surface area independently
  volume = calculate_volume(length, width, height);
  surface_area = calculate_surface_area(length, width, height);

  // Print the report
  print_report(length, width, height, volume, surface_area);

  return 0;
}

/**
 * Get a dimension from the user with validation.
 * - Only accepts numeric input (including decimals)
 * - Rejects zero, negative values, and values exceeding max_value
 * - Prompts user to retry on invalid input
 */
double get_dimension(const char *dimension_name, double max_value) {
  char input[64];
  double value = 0.0;

  while (1) {
    printf("%s: ", dimension_name);

    // Read input safely (prevent buffer overflow)
    if (fgets(input, sizeof(input), stdin) == NULL) {
      printf("Error reading input. Please try again.\n");
      continue;
    }

    // Remove trailing newline if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
      input[len - 1] = '\0';
    }

    // Check for empty input
    if (strlen(input) == 0) {
      printf("Invalid Input, make sure you input valid dimensions!\n");
      continue;
    }

    // Validate that all characters are digits or a single decimal point
    int has_dot = 0;
    int valid = 1;
    for (size_t i = 0; i < strlen(input); i++) {
      if (input[i] == '.') {
        if (has_dot) // More than one decimal point
        {
          valid = 0;
          break;
        }
        has_dot = 1;
      } else if (!isdigit((unsigned char)input[i])) {
        valid = 0;
        break;
      }
    }

    if (!valid) {
      printf("Invalid Input, make sure you input valid dimensions\n");
      continue;
    }

    // Convert to double
    value = atof(input);

    // Check for zero or negative values
    if (value <= 0.0) {
      printf("Invalid Input, make sure you input valid dimensions\n");
      continue;
    }

    // Check against maximum dimension
    if (value > max_value) {
      printf("Invalid Input, dimension exceeds maximum allowed value\n");
      continue;
    }

    // Valid input received
    break;
  }

  return value;
}

/**
 * Calculate the volume (cubic units) of the package.
 * Volume = length * width * height
 */
double calculate_volume(double length, double width, double height) {
  return length * width * height;
}

/**
 * Calculate the surface area (square units) of the package.
 * Surface Area = 2 * (length*width + length*height + width*height)
 */
double calculate_surface_area(double length, double width, double height) {
  return 2.0 * (length * width + length * height + width * height);
}

/**
 * Print the package measurement report.
 */
void print_report(double length, double width, double height, double volume,
                  double surface_area) {

  printf(SEP);
  printf("Atlantic Shipping and Logistics\n");
  printf("Package Measurement Report\n");

  printf(SEP);
  printf("Length: %.2f Width: %.2f Height: %.2f\n", length, width, height);
  printf(SEP);
  printf("Volume: %.2f cubic units\n", volume);
  printf("Surface Area: %.2f square units\n", surface_area);
}
