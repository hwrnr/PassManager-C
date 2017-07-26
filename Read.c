#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define PASS "\\"

void decrypt(char str[]){
  int i, j = 1;
  for (i = 0; str[i] != '\0'; ++i){
    str[i] -= j;
    if (j == 5) j = 1;
    ++j;
  }
}

int str_cmp(char *str1, char *str2){
    int i;
    for (i = 0; str1[i] != '\0'; ++i) if ((str1[i] != str2[i]) || str2[i] == '\0') return FALSE;
    return TRUE;
}

int main(int argc, char const *argv[]) {
  char temp[999], sifra[20];
  if (argc != 2){
    printf("Greska\n");
    return FALSE;
  }
  printf("Unesite sifru: "); scanf(" %s", sifra);
  if (!str_cmp(PASS, sifra)) return 0;


  FILE * file, *tmp_file;
  file = fopen(argv[1], "r");
  system("rm /PassFold/tmp_file 2>>/dev/null");
  tmp_file = fopen("/PassFold/tmp_file", "w");
  fgets(temp, 999, file);
  printf("Username: ");
  printf("%s", temp);
  printf("Lozinka: ");
  fgets(temp, 999, file);
  decrypt(temp);
  fputs(temp, tmp_file);
  printf("* * * * *\n");
  fclose(file);
  fclose(tmp_file);
  system("xclip /PassFold/tmp_file");
  system("rm /PassFold/tmp_file 2>>/dev/null");

  return 0;
}
