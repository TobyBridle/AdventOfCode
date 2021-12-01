#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define MAX_CHARS 9
#define ARRAY_LEN(arr) (size_t)(sizeof((size_t)arr)/sizeof((size_t)(arr)[0]))

int main(int argc, char *argv[]) {

  int *numbers = malloc(sizeof(int));
  int *windows = malloc(sizeof(int));

  if (argc != 2) {
    printf("Usage: %s <filename>", argv[0]);
    exit(1);
  }

  // argv[1] is the argument passed (e.g input.txt when ./main.o input.txt is command line input)
  char *file_path = argv[1];
  int line = 0;
  FILE *input_file;
  input_file = fopen(file_path, "r");

  // Make sure that the file has been opened correctly 
  if(input_file == NULL)
  {
   printf("Cannot read File");
    exit(1);
  }

  // Size of Chunk is the Maximum amount of Characters
  char chunk[MAX_CHARS + 1];
  char *nptr;

  int increases = 0;

  // Grabs one line at a time
  while(fgets(chunk, sizeof(chunk), input_file) != NULL)
  {
    numbers[line] = strtol(chunk, &nptr, 10);
    
    // Resize the Arrays depending on how many lines there are
    numbers = (int*) realloc(numbers, sizeof(int) * (line + 2));
    windows = (int*) realloc(numbers, sizeof(int) * (line + 2));

    line++;
  }


  // Get Window Value and check against previous
  for (size_t num = 0; num < line - 2; num++)
  {
    windows[num] = numbers[num] + numbers[num + 1] + numbers[num + 2];
    if(num > 0 && windows[num] > windows[num-1]){
      increases++;
    }
  }

  printf("increases: %d", increases);
  return 0;
}

