// CCR12 - Insight Market Research Group
// COP-3515 Intro to C & Rust

#include <float.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int num_scores = 0;
  char buffer[256];

  // Get number of survey scores (must be > 0, integer only)
  printf("Number of Survey Scores: ");
  while (1) {
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
      printf("Error reading input.\n");
      return 1;
    }
    if (sscanf(buffer, "%d", &num_scores) != 1) {
      printf("Invalid input. Please enter a positive integer for the number of "
             "scores: ");
      continue;
    }
    if (num_scores <= 0) {
      printf("Invalid input. Please enter a positive integer for the number of "
             "scores: ");
      continue;
    }
    if (num_scores > 10) {
      printf("Invalid input. Maximum number of survey scores is 10: ");
      continue;
    }
    break;
  }

  // Allocate exact amount of memory needed
  double *scores = (double *)malloc(num_scores * sizeof(double));
  if (scores == NULL) {
    fprintf(stderr, "Memory cannot be allocated.\n");
    return 1;
  }

  // Get each score (0-100, floating point allowed)
  for (int i = 0; i < num_scores; i++) {
    printf("Score %d: ", i + 1);
    while (1) {
      if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        free(scores);
        return 1;
      }
      if (sscanf(buffer, "%lf", &scores[i]) != 1) {
        printf("Invalid input. Enter a number between 0 and 100: ");
        continue;
      }
      if (scores[i] < 0.0 || scores[i] > 100.0) {
        printf("Invalid input. Enter a number between 0 and 100: ");
        continue;
      }
      break;
    }
  }

  // Calculate statistics
  double highest = -DBL_MAX;
  double lowest = DBL_MAX;
  double sum = 0.0;

  for (int i = 0; i < num_scores; i++) {
    if (scores[i] > highest) {
      highest = scores[i];
    }
    if (scores[i] < lowest) {
      lowest = scores[i];
    }
    sum += scores[i];
  }

  double average = sum / num_scores;

  // Display report
  printf("\n----------------------------------------------\n");
  printf("Insight Market Research Group\n");
  printf("Survey Summary Report\n");
  printf("----------------------------------------------\n");
  printf("Survey Responses: %d\n", num_scores);
  printf("Highest Score: %.1f\n", highest);
  printf("Lowest Score: %.1f\n", lowest);
  printf("Average Score: %.1f\n", average);
  printf("----------------------------------------------\n");

  // Free all allocated memory
  free(scores);
  printf("Memory released successfully\n");
  printf("program completed.\n");
  printf("----------------------------------------------\n");

  return 0;
}
