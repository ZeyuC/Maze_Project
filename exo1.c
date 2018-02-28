#include <stdio.h>
#include <stdlib.h>
#include "customlibs/Breadth-First-Search.h"
#include "customlibs/list.h"

int main(void){
  int n;
  scanf("%d",&n);
  
  int ** matrix = (int**) malloc(n*sizeof(int*));
  int i,j;
  for(i = 0; i < n; i++){
    int* line = (int*) malloc(n * sizeof(int));
    matrix[i] = line;
    for(j = 0; j < n; j++)
      scanf("%d", &line[j]);
  }

  int s;
  int t;
  scanf("%d", &s);
  scanf("%d", &t);
  s--;
  t--;
  parcour(matrix,s,t,n);
  for(i = 0; i < n; i++)
    free(matrix[i]);
  free(matrix);

  return 0;

}
