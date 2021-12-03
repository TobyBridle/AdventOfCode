#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BIT_LENGTH 12 // How many Bits in the Binary

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Usage: %s <filename>", argv[0]);
    exit(1);
  }

  // argv[1] is the argument passed (e.g input.txt when ./main.o input.txt is command line input)
  char *file_path = argv[1];
  FILE *input_file;
  input_file = fopen(file_path, "r");

  // Size of File (lines)
  fseek(input_file, 0L, SEEK_END);
  size_t file_line_count = ftell(input_file) / (BIT_LENGTH + 1);
  fseek(input_file, 0L, SEEK_SET);

  // Make sure that the file has been opened correctly 
  if(input_file == NULL)
  {
    printf("Cannot read File");
    exit(1);
  }

  // Used as the pointer in `strtol`
  char *nptr;

  // Size of Chunk is the Maximum amount of Characters read per line
  char chunk[BIT_LENGTH + 2];

  // Stores how many more 1s there are than 0s
  int bit_cols[BIT_LENGTH] = { 0 };
  
  // Read Lines from File and Add to according Index of bit_cols
  while(fgets(chunk, BIT_LENGTH + 2, input_file) != NULL)
  {
    for (size_t ch = 0; ch < BIT_LENGTH; ++ch)
    {
      if(chunk[ch] == '1')
      {
        bit_cols[ch] += 1;
      } else {
        bit_cols[ch] -= 1;
      }
    }
  }
  
  // Epsilon not defined since we can apply a bitmask to the integer value of Gamma
  char gamma_binary_string[BIT_LENGTH + 1] = { 0 };

  for (size_t col = 0; col < BIT_LENGTH; ++col)
  {
    if(bit_cols[col] > 0) 
    {
      gamma_binary_string[col] = '1';
    } else gamma_binary_string[col] = '0';
  }

  // Converts the string to a Base 2 Value (binary)
  int gamma = strtol(gamma_binary_string, &nptr, 2);

  // Applies an XOR mask of 1111 (as many 1s as the Bit Length)
  int epsilon = gamma ^ (1 << BIT_LENGTH) - 1;


  printf("%d", gamma * epsilon);

  fclose(input_file);
  return 0;
}
