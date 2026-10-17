// CCR13 - Data Analytics Solutions
// COP-3515: Introduction to C & Rust
// Assignment: Statistics Processing with Fork and Pipes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define NUMBERS_COUNT 10
#define SEP "===============================================================\n"

int main() {
  int pipefd[2]; // pipe file descriptors
  pid_t pid;
  int numbers[NUMBERS_COUNT];
  int status;

  // Create pipe for parent-child communication
  if (pipe(pipefd) == -1) {
    fprintf(stderr, "Error: Could not create pipe\n");
    return 1;
  }

  printf("Program 1 Started\n");
  printf(SEP);
  printf("Data Analytic Solutions\n");
  printf("Statistics Processing\n");
  printf(SEP);

  // Fork a child process
  pid = fork();

  if (pid == -1) {
    fprintf(stderr, "Error: Could not fork process\n"); // Error Handling
    return 1;
  }

  if (pid == 0) {
    // --- CHILD PROCESS ---
    printf("Child Process Started (PID: %d)\n", getpid());

    // Close read end of pipe (child only writes)
    close(pipefd[0]);

    // Seed random number generator
    srand(time(NULL));

    printf("Generating Numbers...\n");

    // Generate 10 random numbers between 1-100
    for (int i = 0; i < NUMBERS_COUNT; i++) {
      numbers[i] = (rand() % 100) + 1;
    }

    // Send numbers to parent through pipe
    if (write(pipefd[1], numbers, NUMBERS_COUNT * sizeof(int)) == -1) {
      fprintf(stderr, "Error: Could not send data through pipe\n");
      close(pipefd[1]);
      return 1;
    }

    printf("Numbers Sent Successfully\n");
    printf("Receiving Numbers...\n");

    // Close write end of pipe
    close(pipefd[1]);

    // Child exits
    return 0;
  } else {
    // --- PARENT PROCESS ---
    printf("Parent Process Started (PID: %d)\n", getpid());
    printf("Child Process Started (PID: %d)\n", pid);

    // Close write end of pipe (parent only reads)
    close(pipefd[1]);

    // Receive numbers from child
    printf("Receiving Numbers...\n");
    if (read(pipefd[0], numbers, NUMBERS_COUNT * sizeof(int)) == -1) {
      fprintf(stderr, "Error: Could not receive data from child process\n");
      close(pipefd[0]);
      waitpid(pid, &status, 0);
      return 1;
    }

    // Close read end of pipe
    close(pipefd[0]);

    // Wait for child process to finish
    if (waitpid(pid, &status, 0) == -1) {
      fprintf(stderr, "Error: Could not wait for child process\n");
      return 1;
    }

    printf("Calculating Statistics.....\n");
    printf(SEP);

    // Calculate statistics
    int min = numbers[0];
    int max = numbers[0];
    int sum = 0;
    int count = NUMBERS_COUNT;
    int aboveAvg = 0;

    for (int i = 0; i < NUMBERS_COUNT; i++) {
      // Track min
      if (numbers[i] < min) {
        min = numbers[i];
      }
      // Track max
      if (numbers[i] > max) {
        max = numbers[i];
      }
      // Calculate sum
      sum += numbers[i];
    }

    // Calculate average
    double average = (double)sum / count;

    // Calculate percentage above average
    for (int i = 0; i < NUMBERS_COUNT; i++) {
      if (numbers[i] > average) {
        aboveAvg++;
      }
    }
    double percentageAboveAvg = ((double)aboveAvg / count) * 100.0;

    // Display generated numbers
    printf("Generated Numbers: ");
    for (int i = 0; i < NUMBERS_COUNT; i++) {
      printf("%d", numbers[i]);
      if (i < NUMBERS_COUNT - 1) {
        printf(", ");
      }
    }
    printf("\n");

    // Display statistics
    printf("Count: %d\n", count);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Percentage Above Average: %.2f%%\n", percentageAboveAvg);
    printf(SEP);

    printf("Child Process Finished\n");
    printf("Parent Process Finished\n");
  }

  return 0;
}
