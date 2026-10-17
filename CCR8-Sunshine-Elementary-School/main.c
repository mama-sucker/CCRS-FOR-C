#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 64
#define SEP "===============================================\n"

/**
 * Reads a line of input safely into the provided buffer.
 * Returns 0 on success, -1 on failure.
 */
static int read_line(char *buffer, size_t size) {
  if (buffer == NULL || size == 0) {
    return -1;
  }

  if (fgets(buffer, (int)size, stdin) == NULL) {
    return -1;
  }

  // Remove trailing newline if present
  size_t len = strlen(buffer);
  if (len > 0 && buffer[len - 1] == '\n') {
    buffer[len - 1] = '\0';
  }

  return 0;
}

/**
 * Parses a string as a double with validation.
 * - Must be a valid number
 * - Must not be negative
 * - Returns 0 on success, -1 on failure
 */
static int parse_grade(const char *input, double *result) {
  if (input == NULL || result == NULL) {
    return -1;
  }

  // Empty input is valid (treated as 0)
  if (strlen(input) == 0) {
    *result = 0.0;
    return 0;
  }

  char *endptr = NULL;
  errno = 0;
  double value = strtod(input, &endptr);

  // Check for conversion errors
  if (errno == ERANGE || endptr == input || *endptr != '\0') {
    return -1;
  }

  // Check for negative numbers
  if (value < 0.0) {
    return -1;
  }

  *result = value;
  return 0;
}

/**
 * Validates that the grade is within acceptable range.
 * For original grade: 0-100
 * For total credit: must not cause combined total to exceed 120
 */
static int validate_grade(double grade, double original_grade,
                          int is_original) {
  if (is_original) {
    // Original grade must be between 0 and 100
    if (grade > 100.0) {
      return -1;
    }
  } else {
    // Total credit: original + credit must not exceed 120
    if ((grade + original_grade) > 120.0) {
      return -1;
    }
  }
  return 0;
}

int main(void) {
  char input_buffer[MAX_INPUT];
  double original_grade = 0.0;
  double extra_credit = 0.0;
  int valid = 0;

  printf(SEP);
  printf("Sunshine Elementary School\n");
  printf("Grade Adjustment Report\n");
  printf(SEP);

  // Get Original Grade
  while (!valid) {
    printf("Original Grade: ");
    if (read_line(input_buffer, sizeof(input_buffer)) != 0) {
      printf("Error: Failed to read input.\n");
      continue;
    }

    if (parse_grade(input_buffer, &original_grade) != 0) {
      printf("ERROR: Invalid input. Please enter a non-negative number "
             "(0-100).\n");
      continue;
    }

    if (validate_grade(original_grade, 0.0, 1) != 0) {
      printf("ERROR: Original grade cannot exceed 100.\n");
      continue;
    }

    valid = 1;
  }

  // Get Extra Credit / Total Credit
  valid = 0;
  while (!valid) {
    printf("Total Credit: ");
    if (read_line(input_buffer, sizeof(input_buffer)) != 0) {
      printf("ERROR: Failed to read input.\n");
      continue;
    }

    // Empty input is valid (treated as 0 extra credit)
    if (strlen(input_buffer) == 0) {
      extra_credit = 0.0;
      valid = 1;
      break;
    }

    if (parse_grade(input_buffer, &extra_credit) != 0) {
      printf("ERROR: Invalid input. Please enter a non-negative number\n");
      continue;
    }

    if (validate_grade(extra_credit, original_grade, 0) != 0) {
      printf("ERROR: Total (Original + Credit) cannot exceed 120\n");
      continue;
    }

    valid = 1;
  }

  // Calculate corrected grade
  double corrected_grade = original_grade + extra_credit;

  // Output results
  printf(SEP);
  printf("Sunshine Elementary School\n");
  printf("Grade Adjustment Report\n");
  printf(SEP);
  printf("Original Grade: %.1f\n", original_grade);
  printf("Extra Credit: %.1f\n", extra_credit);
  printf("Corrected Grade: %.1f\n", corrected_grade);
  printf(SEP);

  return 0;
}
