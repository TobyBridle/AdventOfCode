#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS 9

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filename>", argv[0]);
    exit(1);
  }

  char *file_path = argv[1];
  FILE *input_file;
  input_file = fopen(file_path, "r");

  if(input_file == NULL)
  {
    printf("Cannot read File");
    exit(1);
  }

  char chunk[MAX_CHARS + 1];
  int increases = 0;
  long previous_number = -1;
  char *nptr;

  while(fgets(chunk, sizeof(chunk), input_file) != NULL)
  {
    long current_number = strtol(chunk, &nptr, 10);

    if(previous_number == -1) previous_number = current_number;
    if(current_number > previous_number) increases++;

    previous_number = current_number;
  }

  printf("Increases: %d", increases);
  return 0;
}

