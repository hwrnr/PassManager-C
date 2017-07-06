#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void decrypt(char str[]){
  int i, j = 1;
  for (i = 0; str[i] != '\0'; ++i){
    str[i] -= j;
    if (j == 5) j = 1;
    ++j;
  }
}

int main(int argc, char const *argv[]) {
  char temp[999];
  if (argc != 2){
    printf("Greska\n");
    return FALSE;
  }
  FILE * file;
  file = fopen(argv[1], "r");
  fgets(temp, 999, file);
  printf("Username: ");
  printf("%s", temp);
  printf("Lozinka: ");
  fgets(temp, 999, file);
  decrypt(temp);
  printf("%s\n", temp);
  fclose(file);

  return 0;
}
