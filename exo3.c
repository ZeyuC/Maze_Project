#include "customlibs/A_star.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  int n;
  scanf("%d",&n);fgetc(stdin);
  
  char matrix[1000][1002] = { "" };
  int i;
  for(i = 0; i < n; i++){
    fgets(matrix[i], 1002, stdin);
  }

  int timer;
  scanf("%d", &timer);fgetc(stdin);
  long numbre = n*n;
  char map[numbre];
    
    for (i = 0; i < numbre;i++)
    {
        map[i]=matrix[i/n][i%n];
    }
    A_star(map,n);

  return 0;
}
