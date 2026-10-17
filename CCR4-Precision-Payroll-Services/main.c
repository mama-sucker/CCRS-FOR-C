#include <stdio.h>
#include <string.h>

/* Returns 1 if the line contains a valid employee entry (name, hours), 0
 * otherwise */
int is_valid_employee_line(const char *line) {
  /* Skip empty or whitespace-only lines */
  int i = 0;
  while (line[i] != '\0') {
    if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' &&
        line[i] != '\r') {
      /* Found a non-whitespace character, stop skipping */
      break;
    }
    i++;
  }
  if (line[i] == '\0') {
    return 0; /* Line is all whitespace or empty */
  }

  /* Must contain a comma (name, hours format) */
  const char *comma = strchr(line, ',');
  if (!comma) {
    return 0;
  }

  /* After the comma, there must be at least one digit (the hours) */
  const char *p = comma + 1;
  while (*p != '\0') {
    if (*p >= '0' && *p <= '9') {
      return 1; /* Valid employee line */
    }
    p++;
  }

  return 0; /* No digit found after comma */
}

int main(void) {
  const char *input_file = "employee_hours.txt";
  const char *output_file = "numbered_hours.txt";

  FILE *fin = fopen(input_file, "r");
  if (!fin) {
    fprintf(stderr, "Error: Could not open input file '%s'\n", input_file);
    return 1;
  }

  FILE *fout = fopen(output_file, "w");
  if (!fout) {
    fprintf(stderr, "Error: Could not open output file '%s'\n", output_file);
    fclose(fin);
    return 1;
  }

  char line[1024];
  long lines_copied = 0;
  long chars_copied = 0;

  while (fgets(line, sizeof(line), fin)) {
    /* Skip blank or invalid lines (no name/hours) */
    if (!is_valid_employee_line(line)) {
      continue;
    }
    lines_copied++;
    /* Write line number followed by ". " and the original line */
    fprintf(fout, "%ld. %s", lines_copied, line);
    chars_copied += (long)strlen(line) + 3; /* +3 for "%ld. " */
  }

  fclose(fin);
  fclose(fout);

  printf("================================\n");
  printf("Precision Payroll Services\n");
  printf("File Processing Summary\n");
  printf("================================\n");
  printf("Input File: %s\n", input_file);
  printf("Output File: %s\n", output_file);
  printf("\nLines Copied: %ld\n", lines_copied);
  printf("Characters Copied: %ld\n", chars_copied);
  printf("\nFile Copied and numbered Successfully. Thank you!\n");

  return 0;
}
