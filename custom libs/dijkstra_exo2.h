#ifndef IPI_EXO2_H
#define IPI_EXO2_H
#define INF -1
/* @requires   matrix non null,s,t,n non null
   @assigns    cherche un chemin plus court entre s et t
   @ensures    ...
*/
void dijkstra(int ** matrix,int s,int t,int n);

#endif