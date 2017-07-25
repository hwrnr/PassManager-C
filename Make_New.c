#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

#define PASS "\\"


void encrypt(char str[]){
  int i, j = 1;
  for (i = 0; str[i] != '\0'; ++i){
    str[i] += j;
    if (j == 5) j = 1;
    ++j;
  }
}

void srediAdresu(char sadresa[], char adresa[]){
  int i = 10, j;
  for (j = 0; adresa[j] != '0'; ++j){
    sadresa[i + j] = adresa[j];
  }
  sadresa[i+j] = adresa[j];
}

int str_cmp(char *str1, char *str2){
    int i;
    for (i = 0; str1[i] != '\0'; ++i) if ((str1[i] != str2[i]) || str2[i] == '\0') return FALSE;
    return TRUE;
}

char newRandom(){
  return rand();
}

int main()
{
    int duzina, i;
    char adresa[999], username[999], sadresa[999] = "/PassFold/", sifra[20];
    FILE * file;
    srand(time(NULL));
    printf("Unesite sifru: "); scanf(" %s", sifra);
    if (!str_cmp(PASS, sifra)) return FALSE;
    printf("Unesite naziv servisa (fajla), bez razmaka: "); scanf(" %s", adresa);
    srediAdresu(sadresa, adresa);
    //printf("%s\n", sadresa);
    file = fopen(sadresa, "w+");
    printf("Unesite username: "); scanf("%s", username);
    fputs(username, file);
    fputs("\n", file);
    printf("Unesite duzinu zeljene sifre: "); scanf("%d", &duzina);
    while (duzina < 1){
      printf("Unesite duzinu zeljene sifre: "); scanf("%d", &duzina);
    }
    ++duzina;
    char niz[duzina + 1];
    while (niz[0] < 33 || niz[0] > 126){
      niz[0] += newRandom();
      printf("%c", niz[0]);
    }
    for (i = 1; i < duzina; ++i){
      while (niz[i] < 33 || niz[i] > 126 || niz[i] == niz[i-1]){
        niz[i] += (niz[i-1] + newRandom());
      }
      printf("%c", niz[i]);
    }
    niz[duzina] = '\0';
    encrypt(niz);
    fputs(niz, file);
    fclose(file);
    printf("\n");
    return 0;
}
