#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void encrypt(char str[]){
  int i, j = 1;
  for (i = 0; str[i] != '\0'; ++i){
    str[i] += j;
    if (j == 5) j = 1;
    ++j;
  }
}

void srediAdresu(char sadresa[], char adresa[]){
  int i = 9, j;
  for (j = 0; adresa[j] != '0'; ++j){
    sadresa[i + j] = adresa[j];
  }
  sadresa[i+j] = adresa[j];
}

int main()
{
    int duzina, i, c;
    char adresa[999], username[999], sadresa[999] = "PassFold/";
    FILE * file;
    printf("Unesite naziv servisa (fajla), bez razmaka: "); scanf("%s", adresa);
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
    while (niz[0] == 0){
      niz[0] = (int)(((long long int)username)%(256+c));
      ++c;
    }
    for (i = 1; i < duzina; ++i){
      while (niz[i] < 33 || niz[i] > 126 || niz[i] == niz[i-1]){
        niz[i] += niz[i-1] + c;
        ++c;
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
