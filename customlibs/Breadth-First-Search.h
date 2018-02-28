#ifndef IPI_EXO1_PARCOUR_H
#define IPI_EXO1_PARCOUR_H
#define INF 65535
/* @requires   matrix non null,s,t,n non null
   @assigns    cherche un chemin plus court entre s et t
   @ensures    ...
*/
void parcour(int ** matrix,int s,int t,int n);

#endif