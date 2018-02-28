#include "dijkstra_exo2.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/* @requires   matrix non null,s,t,n non null
   @assigns    cherche un chemin plus court entre s et t
   @ensures    ...
*/
void dijkstra(int ** matrix,int s,int t,int n)
{
    int i,j,k;
    int min = INF;
    int flag[n];       /* flag[i]==1 c'est à dire qu'on a réussi à obtenir le chemin le plus court entre s et i*/ 
    int pred[n];       /* pred [i] stocke le prédécesseur dans le chemin le plus court*/
    long dist[n];       /* dist[i] stocke la distance la plus court entre i et s*/
    list chemin= inti_list();     /* stocker le chemin le plus court entre s et t*/

    if(s == t){
        printf("%d\n",s+1);
        exit (0);
    }
    
    for(i = 0; i<n;i++)            /*inistialisation*/
    {
        flag[i]=0;             /* on a pas encore trouvé le chemin le plus court de i*/
        pred[i]=0;             /* le prédecesseur de i est 0*/
        dist[i]=INF;  /* la distance la plus court entre i et s*/
    }

    dist[s]=0;   /* la distance entre s et s est 0*/
   
    /* parcourir n-1 fois , chaque fois on trouve un chemin le plus court*/
    for (i = 0;i < n; i++)
    {
        int max = INF;
        for (j = 0;j < n ; j++)     /* trouve le chemin le plus long */
        {
            if ( flag[j]==0 && dist[j] > max)
            {
                max = dist[j];
            }
        }
        min = max;
        for (j = 0;j < n ; j++)     /* trouver le chemin le plus court*/
        {
            if ( flag[j]==0 && dist[j] <= min && dist[j]!=INF)
            {
                min = dist[j];
                k = j;
            }
        }
       
        flag[k]=1;      /* on pose qu'on a trouvé le chemin le plus court du noeud k*/
        /* mise à jour les chemin les plus court des tous les noeud et stocker le predécesseur pour l'instant*/
        for (j = 0; j < n; j++)
        {
            if (flag[j]==0 && matrix[k][j]!=INF ) /* si flag[j]==0 et dist[k]+matrix[k][j] < dist[j], misq à jour*/
            {
                if (dist[j]==INF)
                {
                    dist[j]=matrix[k][j]+dist[k];          
                    pred[j]=k;
                }
                else if ( (min+matrix[k][j])< dist[j])
                {
                    dist[j]=min+matrix[k][j];
                    pred[j]=k;
                }
            }
        }
        
    }
    if (flag[t] == 0)
    {
        printf("Not connected\n");
        exit (1);
    }
    else 
    {
       insert_Head(&chemin,t); 
       while (t != s)
       { 
       insert_Head(&chemin,pred[t]);
       t = pred[t]; 
       }
    }

    print_list(chemin);

}
