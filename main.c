#include <stdio.h>

#define MAX_READ 4096
#define MAX_WRITE 1024

void print_delimiter();

int main(int argc, char **argv) {
  char writeBuf[MAX_WRITE];
  char dataBuf[MAX_READ];
  int working = 1;
  int choice;
  if (argc != 2) {
    printf("Usage: %s <filename>\n\t<filename> - name of file to open",
           argv[0]);
    return -1;
  }
  FILE *file_ptr;
  const char *filename = argv[1];
  while (working) {
    printf("Menu:\n\t[1] - Write line to file\n\t[2] - Get file content\n\t[3] "
           "- Exit\n\nChoice:\t");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      file_ptr = fopen(filename, "a");
      scanf("%s", writeBuf);
      fprintf(file_ptr, "%s\n", writeBuf);
      fclose(file_ptr);
      break;
    case 2:
      print_delimiter();
      file_ptr = fopen(filename, "r");
      while (fgets(dataBuf, MAX_READ, file_ptr)) {
        printf("\t%s", dataBuf);
      }
      fclose(file_ptr);
      print_delimiter();
      break;
    default:
      working = 0;
      break;
    }
  }
  return 0;
}

void print_delimiter() {
  for (int i = 0; i < 80; ++i) {
    putchar('=');
  }
  printf("\n");
}
