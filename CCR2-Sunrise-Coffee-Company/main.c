// CCR2 main.c for Sunrise Coffee Company

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int sales[5];
  int total = 0;

  printf("Sunrise Coffee Company\n");

  for (int i = 0; i < 5; i++) {
    char input[16];
    int valid = 0;

    while (!valid) {
      printf("Enter the amount of coffee sold in the %s hour: ",
             (i == 0)   ? "first"
             : (i == 1) ? "second"
             : (i == 2) ? "third"
             : (i == 3) ? "fourth"
                        : "fifth");

      if (fgets(input, sizeof(input), stdin) == NULL || input[0] == '\n' ||
          input[0] == '\0') {
        printf("    Number of cups sold for the hour will be 0 (y/n): ");
        char confirm[4];
        if (fgets(confirm, sizeof(confirm), stdin) != NULL &&
            (confirm[0] == 'y' || confirm[0] == 'Y')) {
          sales[i] = 0;
          valid = 1;
        }
        /* if 'n' or invalid, loop continues */
      } else {
        /* Check for decimal point */
        if (strchr(input, '.') != NULL) {
          printf("    Error: enter a whole number\n");
          continue;
        }

        /* Check each character is a digit (no minus sign allowed) */
        int all_digits = 1;
        for (int j = 0; input[j] != '\0' && input[j] != '\n'; j++) {
          if (input[j] < '0' || input[j] > '9') {
            all_digits = 0;
            break;
          }
        }

        if (!all_digits) {
          printf("    Error: enter a whole number\n");
          /* Clear remaining input from buffer */
          int c;
          while ((c = getchar()) != '\n' && c != EOF)
            ;
        } else {
          /* Use strtol to detect overflow */
          char *endptr;
          errno = 0;
          long value = strtol(input, &endptr, 10);
          if (errno == ERANGE || value > INT_MAX || value < 0) {
            printf("    Error: number too large\n");
            /* Clear remaining input from buffer */
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
              ;
          } else {
            sales[i] = (int)value;
            valid = 1;
          }
        }
      }
    }

    printf("    Number stored, %d left for the day\n", 4 - i);
    total += sales[i];
  }

  printf("\nTotal Coffee sold for the 5 hour period of day: %d\n", total);
  printf("Hour 1: %d  Hour 2: %d  Hour 3: %d  Hour 4: %d  Hour 5: %d\n",
         sales[0], sales[1], sales[2], sales[3], sales[4]);

  return 0;
}
