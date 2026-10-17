// CCR11 - National Technology Conference
// COP-3515 Intro to C & Rust

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_PRESENTERS 10
#define MAX_NAME_LEN 100 // was 256
#define SEP "=====================================================\n"

// Check if a name is valid (only letters and spaces, must have at least one
// non-space character, and within max length)
int is_valid_name(const char *name) {
  if (name == NULL || strlen(name) == 0) {
    return 0;
  }

  // Check for excessive length
  if ((int)strlen(name) > MAX_NAME_LEN) {
    return 0;
  }

  int has_letter = 0;
  for (int i = 0; name[i] != '\0'; i++) {
    char c = name[i];
    if (c == ' ') {
      // Allow spaces
      continue;
    } else if (isalpha((unsigned char)c)) {
      has_letter = 1;
    } else {
      // Invalid character (number, special char, etc.)
      return 0;
    }
  }

  // Must have at least one letter (first name required)
  return has_letter;
}

// Check if a name is a duplicate (case-insensitive comparison)
int is_duplicate(const char *names[], int count, const char *new_name) {
  for (int i = 0; i < count; i++) {
    if (strcasecmp(names[i], new_name) == 0) {
      return 1;
    }
  }
  return 0;
}

// Find the longest name in the array
int find_longest_index(const char *names[], int count) {
  int longest_idx = 0;
  int longest_len = (int)strlen(names[0]);

  for (int i = 1; i < count; i++) {
    int name_len = (int)strlen(names[i]);
    if (name_len > longest_len) {
      longest_len = name_len;
      longest_idx = i;
    }
  }

  return longest_idx;
}

void print_usage(const char *program_name) {
  printf("Usage: %s \"Presenter Name\" [\"Presenter Name2\"] ...\n",
         program_name);
  printf("Example: %s \"Alice Johnson\" \"Brian Smith\" \"Emily Brown\"\n",
         program_name);
}

int main(int argc, char *argv[]) {
  // Check if any names were provided
  if (argc < 2) {
    print_usage(argv[0]);
    return 1;
  }

  // Array to store presenter names
  const char *presenters[MAX_PRESENTERS];
  int presenter_count = 0;

  // Process each argument
  for (int i = 1; i < argc; i++) {
    // Check if we've reached the maximum number of presenters
    if (presenter_count >= MAX_PRESENTERS) {
      printf("Error: Maximum number of presenters (%d) exceeded. Please enter "
             "%d or fewer names.\n",
             MAX_PRESENTERS, MAX_PRESENTERS);
      return 1;
    }

    // Validate the name
    if (!is_valid_name(argv[i])) {
      printf("Error: Please enter a valid name.\n");
      return 1;
    }

    // Check for duplicates (case-insensitive)
    if (is_duplicate(presenters, presenter_count, argv[i])) {
      printf("Warning: Duplicate name '%s' - only displaying once.\n", argv[i]);
      continue;
    }

    // Add the presenter
    presenters[presenter_count] = argv[i];
    presenter_count++;
  }

  // Print the summary
  printf(SEP);
  printf("National Technology Conference\n");
  printf("Presenter Summary\n");
  printf(SEP);
  printf("Presenters\n");

  for (int i = 0; i < presenter_count; i++) {
    printf("%d. %s\n", i + 1, presenters[i]);
  }

  printf(SEP);
  printf("Total Presenters: %d\n", presenter_count);
  printf(SEP);

  // Find and display the longest name
  if (presenter_count > 0) {
    int longest_idx = find_longest_index(presenters, presenter_count);
    printf("Longest Presenter Name: %s\n", presenters[longest_idx]);
    printf("Characters: %d\n", (int)strlen(presenters[longest_idx]));
  }

  printf(SEP);

  return 0;
}
