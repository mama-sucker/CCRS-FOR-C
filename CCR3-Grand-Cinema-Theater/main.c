#include <ctype.h>
#include <stdio.h>

int main(void) {
  int age;
  char dayType;

  // Input: Customer Age (must be between 1-99, whole numbers only)
  printf("Customer Age: ");
  while (1) {
    char extra;
    if (scanf("%d", &age) != 1 || age < 1 || age > 99) {
      while (getchar() != '\n')
        ; // Clear invalid input
      printf("Try again. Age should be between 1-99\nCustomer Age: ");
      continue;
    }
    // Check for extra characters (e.g., decimal point or letters after the
    // number)
    if (scanf("%c", &extra) != 1 || extra != '\n') {
      while (getchar() != '\n')
        ; // Clear invalid input
      printf("Try again. Age should be between 1-99\nCustomer Age: ");
      continue;
    }
    break;
  }

  // Input: Day Type (W for weekday, E for weekend) - single character only
  printf("What type of day is it press W for weekday or E for weekend\nDay "
         "Type: ");
  while (1) {
    char buffer[256];
    char extra;
    if (scanf("%255s", buffer) != 1) {
      while (getchar() != '\n')
        ; // Clear invalid input
      printf("Try again!\nWhat type of day is it press W for weekday or E for "
             "weekend\nDay Type: ");
      continue;
    }
    // Check that input is exactly one character
    if (buffer[1] != '\0') {
      while (getchar() != '\n')
        ; // Clear invalid input
      printf("Try again!\nWhat type of day is it press W for weekday or E for "
             "weekend\nDay Type: ");
      continue;
    }
    dayType = buffer[0];
    if (dayType != 'W' && dayType != 'w' && dayType != 'E' && dayType != 'e') {
      while (getchar() != '\n')
        ; // Clear invalid input
      printf("Try again!\nWhat type of day is it press W for weekday or E for "
             "weekend\nDay Type: ");
      continue;
    }
    // Consume any remaining characters on the line (should be just newline)
    if (scanf("%c", &extra) != 1 || extra != '\n') {
      while (getchar() != '\n')
        ; // Clear invalid input
      printf("Try again!\nWhat type of day is it press W for weekday or E for "
             "weekend\nDay Type: ");
      continue;
    }
    break;
  }

  // Normalize to uppercase
  dayType = toupper((unsigned char)dayType);

  // Determine day type string
  const char *dayStr = (dayType == 'W') ? "Weekday" : "Weekend";

  // Determine ticket type based on age
  const char *ticketType;
  if (age <= 12) {
    ticketType = "Child ticket";
  } else if (age >= 60) {
    ticketType = "Senior ticket";
  } else {
    // Ages 13-59
    ticketType = "Adult ticket";
  }

  // Output
  printf("\nGrand Cinema Theater\n\n");
  printf("Ticket Classification\n");
  printf("===============================\n\n");
  printf("Customer Age: %d\n", age);
  printf("Day Type: %s\n", dayStr);
  printf("===============================\n");
  printf("Ticket Type: %s\n", ticketType);

  return 0;
}
