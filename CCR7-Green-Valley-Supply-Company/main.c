// CCR7 - Green Valley Supply Company
// Inventory Management System

#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define INPUT_BUFFER_SIZE 256
#define INVENTORY_FILE "storage/inventory.txt"

// Function to read a line of input safely
int get_line(char *buffer, int size) {
  if (fgets(buffer, size, stdin) == NULL) {
    return -1;
  }
  // Remove trailing newline
  size_t len = strlen(buffer);
  if (len > 0 && buffer[len - 1] == '\n') {
    buffer[len - 1] = '\0';
  } else {
    // Line was too long or no newline found, clear remaining input
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
      ;
  }
  return 0;
}

// Function to parse a long integer from string with validation
// Returns 0 on success, -1 on failure
int parse_long(const char *str, long *result) {
  if (str == NULL || strlen(str) == 0) {
    return -1;
  }

  char *endptr;
  errno = 0;
  long value = strtol(str, &endptr, 10);

  // Check for conversion errors
  if (errno == ERANGE || *endptr != '\0' || endptr == str) {
    return -1;
  }

  *result = value;
  return 0;
}

// Function to ensure the storage directory exists
void ensure_storage_dir() {
  struct stat st = {0};
  if (stat("storage", &st) == -1) {
    mkdir("storage", 0755);
  }
}

// Function to load inventory from file
long load_inventory_from_file() {
  ensure_storage_dir();
  FILE *file = fopen(INVENTORY_FILE, "r");
  if (file == NULL) {
    printf("Error: File '%s' does not exist. Creating new inventory file.\n",
           INVENTORY_FILE);
    // Create the file with default value of 0
    FILE *new_file = fopen(INVENTORY_FILE, "w");
    if (new_file != NULL) {
      fprintf(new_file, "0\n");
      fclose(new_file);
    }
    return 0;
  }

  char buffer[INPUT_BUFFER_SIZE];
  if (fgets(buffer, sizeof(buffer), file) == NULL) {
    fclose(file);
    return -1;
  }
  fclose(file);

  // Remove trailing newline
  size_t len = strlen(buffer);
  if (len > 0 && buffer[len - 1] == '\n') {
    buffer[len - 1] = '\0';
  }

  long inventory = 0;
  if (parse_long(buffer, &inventory) != 0) {
    return -1;
  }

  return inventory;
}

// Function to save inventory to file
void save_inventory_to_file(long inventory) {
  FILE *file = fopen(INVENTORY_FILE, "w");
  if (file == NULL) {
    printf("Warning: Could not save inventory to file '%s'.\n", INVENTORY_FILE);
    return;
  }

  fprintf(file, "%ld\n", inventory);
  fclose(file);
}

// Function to get valid inventory input
long get_inventory() {
  char buffer[INPUT_BUFFER_SIZE];
  long inventory;

  while (1) {
    printf("Current Inventory: ");
    if (get_line(buffer, sizeof(buffer)) != 0) {
      printf("Error: Input failed.\n");
      continue;
    }

    // Check if user wants to load from file (enter 0)
    if (strcmp(buffer, "0") == 0) {
      inventory = load_inventory_from_file();
      if (inventory >= 0) {
        printf("Loaded inventory from file: %ld\n", inventory);
        return inventory;
      } else {
        printf("Error: Could not load inventory from file. Please enter a "
               "valid number.\n");
        continue;
      }
    }

    if (parse_long(buffer, &inventory) != 0) {
      printf("Error: Invalid input. Please enter a valid integer.\n");
      continue;
    }

    if (inventory < 0) {
      printf("Error: Negative input is not allowed.\n");
      continue;
    }

    if (inventory > 100) {
      printf("Error: Inventory cannot exceed 100.\n");
      continue;
    }

    // Allow 0 as per updated requirements
    return inventory;
  }
}

// Function to get valid purchase amount
long get_purchase(long inventory) {
  char buffer[INPUT_BUFFER_SIZE];
  long purchase;

  while (1) {
    printf("Products Purchased: ");
    if (get_line(buffer, sizeof(buffer)) != 0) {
      printf("Error: Input failed.\n");
      continue;
    }

    if (parse_long(buffer, &purchase) != 0) {
      printf("Error: Invalid input. Please enter a valid integer.\n");
      continue;
    }

    if (purchase < 0) {
      printf("Error: Negative input is not allowed.\n");
      continue;
    }

    if (purchase > inventory) {
      printf("Error: Cannot purchase more than available inventory (%ld). "
             "Please try again.\n",
             inventory);
      continue;
    }

    return purchase;
  }
}

int main() {
  printf("=======================================\n");
  printf("Green Valley Supply Company\n");
  printf("Inventory Management System\n");
  printf("=======================================\n\n");

  // Get inventory
  long inventory = get_inventory();

  // Get purchase amount
  long purchased = get_purchase(inventory);

  // Calculate results
  long remaining = inventory - purchased;

  // Display transaction summary
  printf("\n=======================================\n");
  printf("Green Valley Supply Company\n");
  printf("Inventory Transaction Summary\n");
  printf("=======================================\n\n");
  printf("Inventory Before Sale: %ld\n", inventory);
  printf("Products Sold: %ld\n", purchased);
  printf("Inventory Remaining: %ld\n", remaining);
  printf("\n=======================================\n");

  // Save updated inventory to file
  save_inventory_to_file(remaining);

  return 0;
}
