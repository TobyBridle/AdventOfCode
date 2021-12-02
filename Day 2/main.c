#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHUNK_SIZE 255
#define STRING_SEPERATOR " "

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filename>", argv[0]);
    exit(1);
  }

  // argv[1] is the argument passed (e.g input.txt when ./main.o input.txt is
  // command line input)
  char *file_path = argv[1];
  int line = 0;
  FILE *input_file;
  input_file = fopen(file_path, "r");

  // Make sure that the file has been opened correctly
  if (input_file == NULL) {
    printf("Cannot read File");
    exit(1);
  }

  char chunk[MAX_CHUNK_SIZE + 1];
  int hPos = 0, vPos = 0;
  while(fgets(chunk, sizeof(chunk), input_file))
  {
    char* direction = strtok( (char*) chunk, STRING_SEPERATOR );
    int hPosChange = 0, vPosChange = 0;
    char* nptr;
    if(strcmp(direction, "forward") == 0){
      hPosChange = strtol(strtok(NULL, STRING_SEPERATOR), &nptr, 10);
      printf("%s:+%d\t%d\n", direction, hPosChange, hPos);
    } else if(strcmp(direction, "up"))
    {
      vPosChange = strtol(strtok(NULL, STRING_SEPERATOR), &nptr, 10);
    } else {
      vPosChange = -strtol(strtok(NULL, STRING_SEPERATOR), &nptr, 10);
    }
    hPos += hPosChange;
    vPos += vPosChange;
  }

  printf("%d", hPos * vPos);
  return 0;
}
