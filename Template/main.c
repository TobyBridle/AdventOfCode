#include <stdio.h>
#include <stdlib.h>

#define MAX_CHUNK_SIZE 255

int main(int argc, char *argv[]) {

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
  char chunk[MAX_CHUNK_SIZE+ 1];
  char *nptr;

  int result = 0;

  // Grabs one line at a time
  while(fgets(chunk, sizeof(chunk), input_file) != NULL)
  {
    // Do stuff with chunk 

    /* Uncomment if doing things with Array Indexes
    line++; */
  }

  printf("%d", result);
  return 0;
}
