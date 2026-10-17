// CCR10 - Riverside Public Library
// COP-3515 Programming in C

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 41

// Validate name: no numbers, allow spaces, hyphens, and apostrophes
// Returns: 1 = valid, 0 = invalid (too long), -1 = contains numbers
int validate_name(const char *name) {
  if (strlen(name) == 0)
    return 0;
  if (strlen(name) >= MAX_NAME_LEN)
    return 0; // Too long
  for (int i = 0; i < (int)strlen(name); i++) {
    if (isdigit((unsigned char)name[i]))
      return -1;
  }
  return 1;
}

// Capitalize first letter of each word in a name
void capitalize_name(char *name) {
  int capitalize_next = 1;
  for (int i = 0; name[i] != '\0'; i++) {
    if (isspace((unsigned char)name[i])) {
      capitalize_next = 1;
    } else {
      if (capitalize_next) {
        name[i] = toupper((unsigned char)name[i]);
        capitalize_next = 0;
      } else {
        name[i] = tolower((unsigned char)name[i]);
      }
    }
  }
}

// Helper to read a line and strip trailing newline, clearing excess input
// Returns 1 if input was truncated, 0 otherwise
static int read_line(char *buf, int size) {
  if (fgets(buf, size, stdin) == NULL) {
    buf[0] = '\0';
    return 0;
  }
  // Strip trailing newline
  size_t len = strlen(buf);
  if (len > 0 && buf[len - 1] == '\n') {
    buf[len - 1] = '\0';
    return 0; // Not truncated
  } else {
    // Line was too long, clear remaining input from buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
      ;
    return 1; // Truncated
  }
}

// Get member name with validation
void get_member_name(int member_num, char *first, char *last) {
  printf("\nMember %d\n", member_num);

  // Get first name (required, cannot be blank)
  while (1) {
    printf("First Name: ");
    int truncated = read_line(first, MAX_NAME_LEN);
    if (truncated) {
      printf("Error: Character limit exceeded (max 40 characters).\n");
      continue;
    }
    int result = validate_name(first);
    if (strlen(first) == 0) {
      printf("Error: First name is required.\n");
      continue;
    }
    if (result == 0)
      printf("Error: Character limit exceeded (max 40 characters).\n");
    else if (result == -1)
      printf("Error: Invalid input. No numbers allowed.\n");
    else
      break;
  }

  // Get last name (can be blank only if first name is blank)
  while (1) {
    printf("Last Name: ");
    int truncated = read_line(last, MAX_NAME_LEN);
    if (truncated) {
      printf("Error: Character limit exceeded (max 40 characters).\n");
      continue;
    }
    int result = validate_name(last);
    if (strlen(last) == 0 || result == 1)
      break;
    if (result == 0)
      printf("Error: Character limit exceeded (max 40 characters).\n");
    else
      printf("Error: Invalid input. No numbers allowed.\n");
  }
}

// Compare names case-sensitively (Bob ≠ bob)
int names_identical(const char *first1, const char *last1, const char *first2,
                    const char *last2) {
  return (strcmp(first1, first2) == 0 && strcmp(last1, last2) == 0);
}

int main() {
  char member1_first[MAX_NAME_LEN];
  char member1_last[MAX_NAME_LEN];
  char member2_first[MAX_NAME_LEN];
  char member2_last[MAX_NAME_LEN];

  // Get member names
  get_member_name(1, member1_first, member1_last);
  get_member_name(2, member2_first, member2_last);

  // Capitalize all names
  capitalize_name(member1_first);
  capitalize_name(member1_last);
  capitalize_name(member2_first);
  capitalize_name(member2_last);

  // Calculate letter counts (only alphabetic characters, no spaces/punctuation)
  int len1 = 0;
  for (int i = 0; member1_first[i] != '\0'; i++)
    if (isalpha((unsigned char)member1_first[i]))
      len1++;
  for (int i = 0; member1_last[i] != '\0'; i++)
    if (isalpha((unsigned char)member1_last[i]))
      len1++;
  int len2 = 0;
  for (int i = 0; member2_first[i] != '\0'; i++)
    if (isalpha((unsigned char)member2_first[i]))
      len2++;
  for (int i = 0; member2_last[i] != '\0'; i++)
    if (isalpha((unsigned char)member2_last[i]))
      len2++;

  // Print report
  printf("\n------------------------------------------\n");
  printf("Riverside Public Library\n");
  printf("Member Name Report\n");
  printf("------------------------------------------\n");
  printf("Member 1: %s %s\n", member1_first, member1_last);
  printf("Letters: %d\n", len1);
  printf("\n");
  printf("Member 2: %s %s\n", member2_first, member2_last);
  printf("Letters: %d\n", len2);

  // Compare names
  printf(
      "\nThe names are %sidentical\n",
      names_identical(member1_first, member1_last, member2_first, member2_last)
          ? ""
          : "NOT ");

  // Alphabetical order (case-sensitive, based on full name)
  printf("------------------------------------------\n");
  printf("Alphabetical Order:\n");

  char full1[MAX_NAME_LEN * 2];
  char full2[MAX_NAME_LEN * 2];
  if (strlen(member1_first) > 0 && strlen(member1_last) > 0)
    snprintf(full1, sizeof(full1), "%s %s", member1_first, member1_last);
  else if (strlen(member1_first) > 0)
    snprintf(full1, sizeof(full1), "%s", member1_first);
  else
    snprintf(full1, sizeof(full1), "%s", member1_last);

  if (strlen(member2_first) > 0 && strlen(member2_last) > 0)
    snprintf(full2, sizeof(full2), "%s %s", member2_first, member2_last);
  else if (strlen(member2_first) > 0)
    snprintf(full2, sizeof(full2), "%s", member2_first);
  else
    snprintf(full2, sizeof(full2), "%s", member2_last);

  int cmp = strcmp(full1, full2);
  if (cmp < 0) {
    if (strlen(member1_first) > 0 && strlen(member1_last) > 0)
      printf("1. %s %s\n", member1_first, member1_last);
    else if (strlen(member1_first) > 0)
      printf("1. %s\n", member1_first);
    else
      printf("1. %s\n", member1_last);
    if (strlen(member2_first) > 0 && strlen(member2_last) > 0)
      printf("2. %s %s\n", member2_first, member2_last);
    else if (strlen(member2_first) > 0)
      printf("2. %s\n", member2_first);
    else
      printf("2. %s\n", member2_last);
  } else {
    if (strlen(member2_first) > 0 && strlen(member2_last) > 0)
      printf("1. %s %s\n", member2_first, member2_last);
    else if (strlen(member2_first) > 0)
      printf("1. %s\n", member2_first);
    else
      printf("1. %s\n", member2_last);
    if (strlen(member1_first) > 0 && strlen(member1_last) > 0)
      printf("2. %s %s\n", member1_first, member1_last);
    else if (strlen(member1_first) > 0)
      printf("2. %s\n", member1_first);
    else
      printf("2. %s\n", member1_last);
  }

  printf("------------------------------------------\n");

  return 0;
}
