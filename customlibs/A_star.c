#include "A_star.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* @requires   open_file non null,j,in,out,f non null
   @assigns    insere j dans openfile d'apres les valeur de f
   @ensures    ...
*/
void insert_openfile(int open_file[],int j,int in,int out,int f[])
{
    int i=0,reg=in;
    for(i=in;i<out;i++)
    {
        if(f[open_file[i]]>f[j])
            break;
        else
            reg++;
    }
    for (i = out-1; i >=reg; i--)
    {
        open_file[i+1]=open_file[i];
    }
    open_file[reg]=j;
}
/* @requires   map non null,n non null
   @assigns    cherche un chemin plus court entre s et t
   @ensures    ...
*/
int A(char map[],int n,long s,long t,int *count,char chemin[],int *exist)  /*on cherche du s jusqu'a le point final t*/
{
    long i=0,j=0, k=0,tmp=0,b;
    long numbre=n*n;
    
    int *f=malloc(sizeof(int)*numbre);/* f = g+h */
    int *g=malloc(sizeof(int)*numbre);
    int *h=malloc(sizeof(int)*numbre);
    int *open=malloc(sizeof(int)*numbre);  /*open[i]==1 represente que noeud i est dans le open_list*/
    int *close=malloc(sizeof(int)*numbre);/*close[i]==1 represent que noeud i est dans le chemin le plus court*/
    int *pred=malloc(sizeof(int)*numbre); /* pred [i] stocke le prédécesseur dans le chemin le plus court*/
      
    int *open_file=malloc(sizeof(int)*numbre);/* c'est pour stocker les valeur de f de noeud qui sont dans open*/
    int in=0,out=0; /*in pointe ver le head et out pointe ver la queue */
    char point;
    *count=0;
    *exist=1;
    for (i = 0; i < numbre;i++) /*initialisation*/
    {
        pred[i]=0;       /* le prédecesseur de i est 0*/
        close[i]=0;
        f[i]=INF;
        open[i]=0;
        open_file[i]=0;
        chemin[i]=0;
    }
    point = map[t]; /*le point final*/
     
    h[s]= labs(t-s)/n+labs(t-s)%n;  /*estimer h */
    g[s]= 0;
    f[s]= h[s]+g[s];
    open[s]=1;
    open_file[out++]=s;/*au début, dans open_list il ny a que le point debut*/  
    pred[s]=-1; /*le predésseure de S et -1*/  
    int porte=0;
    while(out!=in)
    {
        long min=INF;
        k=open_file[in++];   /*cherche le f le plus petit*/
       
        open[k]=0;
        close[k]=1;   /*add x to closedset */
        if(map[k]=='A') porte=1;
        if(map[k]==point) /*map[k]=='E' ça veut dire qu'on a trouvé le point final*/
        {
            i=0;
            while(pred[t]!=-1)
            {
                if (g[pred[t]]==g[t] &&close[pred[t]]==1)/* ça c'est une propriété très important pour juger si on a utilisé TP */
                    chemin[i++]='T';
                else if(pred[t]-t==1)
                    chemin[i++]='D';
                else if (pred[t]-t==-1)
                    chemin[i++]='G';
                else if (pred[t]-t==n)
                    chemin[i++]='B';
                else if (pred[t]-t==-n)
                    chemin[i++]='H';
                t=pred[t];      
                (*count)++;
            }     
            break;
        }
        tmp=k;
        int change=0;
        for (i = 0; i<5;i++) /*Nous faisons un cycle 5 fois car il y a au plus 4 voisins et un voisin de TP par noeud*/
        {       
            min=g[k]+1;
            if (i==0 )           /*dessus*/
            {
                if(tmp-n<0 || map[tmp-n]=='X') /*k-n<0 || map[k-n]=='X' on continue*/
                    continue;
                else
                    {
                        j=tmp-n;
                        change=1;
                    }
            }
            if (i==1)           /*desous*/
            {
                if(tmp+n>=numbre || map[tmp+n]=='X' )
                    continue;
                else
                    {
                        j=tmp+n;
                        change=1;
                    }
            }
            if (i==2 )           /*gauche*/ /*garder le noeud k-1 et le noeud k sont dans la même ligne*/
            {
                if( tmp-1<0 || map[tmp-1]=='X' || (tmp-1)/n != tmp/n )
                    continue;
                else 
                    {
                        j=tmp-1;
                        change=1;
                    }
            }
            if (i==3)           /*droit*/
            {
                if(tmp+1>=numbre || map[tmp+1]=='X'|| (tmp+1)/n != tmp/n)    /*k+1>=numbre || map[k+1]=='X' on continue*/
                    continue;
                /*garder le noeud k+1 et le noeud k sont dans la même ligne*/   
                else   
                    {
                        j=tmp+1;
                        change=1;
                    }
            }

            if (i==4) /*son un des voisin est TP */
            {
                if((map[tmp]=='*' || map[tmp]=='%' ||map[tmp]=='$' ||map[tmp]=='#' ||
                    map[tmp]=='&'|| map[tmp]=='-'|| map[tmp]=='+'|| map[tmp]=='@'|| map[tmp]=='^'|| map[tmp]=='!'|| map[tmp]=='?'))
                {
                    
                    for(b=numbre-2;b>0;b--) /*cherche du numbre-2 jusqu'à le point début lautre tp*/
                    {
                        if(map[b] == map[k])
                        {
                            /*continue,parce qu'on a trouvé le meme noeud*/
                            if (b==k) 
                                continue;
                            else
                            {
                                j=b;  /*on pose noeud i est un voisin de k*/
                                min=g[k]; /*on peut y arrive nstantanément*/
                                change=1;
                            }
                        }
                    }
                }
            }
            if(change==0)   /**/
                *exist=0;
            /*on a deja noeud j dans close,mais si g[j]-g[tmp]!=1,ça veut dire qu'on a besion de mise a jout f de tous les noeud */
            if (close[j]==1) 
                continue;
            if (open[j]==0)    /*si noeud j est pas dans open,on le mets dans open*/
            { 
                open[j]=1;
                pred[j]=tmp;   /*on pose pred[j]=tmp anisi que si on a rencontré un tp,on peut se déplace instantanément en néligant le point k*/
                g[j]=min;
                h[j]=labs(t-j)/n+labs(t-j)%n;
                f[j]=g[j]+h[j];
                open_file[out++]=j;
            }
            else if (min < g[j]) /*quand min >= g[j] ça veut dire que si on passe de k à j, le coût est plus élevé,donc,on fais pas pred[j]=k*/
            {
                pred[j]=tmp;
                g[j]=min;
                h[j]=labs(t-j)/n+labs(t-j)%n;
                f[j]=g[j]+h[j];
                insert_openfile(open_file,j,out,in,f);
            }
        }
    }
        return porte;
}
/* @requires   map non null,n non null
   @assigns    cherche un chemin plus court entre le point depart et le point final
   @ensures    ...
*/
void A_star(char map[],int n)
{
    long numbre=n*n;
    int count_1=0;
    int count_2=0;
    int count_s;
    int count_t;
    char chemin_1[numbre];
    char chemin_2[numbre];
    char chemin_s[numbre];
    char chemin_t[numbre];
    
    int exist;   /*si 0 il y a pas de chemin*/
    
    long i,tmp;
    int porte;
    for (i=0;i<numbre;i++)
    {
        chemin_1[i]=0;
        chemin_2[i]=0;
        chemin_s[i]=0;
        chemin_t[i]=0;
    }
   
    porte=A(map,n,0,n*n-1,&count_1,chemin_1,&exist);
    /*chercher la position de clef*/
    if(porte==1) 
    {
        for(i=0;i<numbre;i++) 
        {
            if(map[i]=='a') /*chercher la position de clef*/
                tmp=i; 
            if(map[i]=='A')  /* chercher la position de clef*/
                porte=i;
        }
        map[porte]='X';
        A(map,n,0,tmp,&count_1,chemin_1,&exist);
        map[porte]='A';
      
        A(map,n,tmp,n*n-1,&count_2,chemin_2,&exist);
        count_s=count_1+count_2;
        
        for(i=0;i<count_s;i++)
        {
            if(i<count_2)
                chemin_s[i]=chemin_2[i];
            else
                chemin_s[i]=chemin_1[i-count_2];
        }
       
        map[porte]='X';
        A(map,n,0,n*n-1,&count_t,chemin_t,&exist);
       
        if (exist == 1 && count_t && count_t <count_s)          /*si on vois A comme un mur , il y aura d'autre chemin plus court*/
        {
            for (i=0;i<count_s;i++)
                {
                    if(i<count_t)
                    chemin_s[i]=chemin_t[i];
                    
                    else
                        chemin_s[i]=0;
                }
        }
      
    }
        else 
        A(map,n,0,n*n-1,&count_s,chemin_s,&exist); /*235on n'a pas bosin de le clef*/  
        
        for(i=strlen(chemin_s)-1;i>=0;i--)
            {
                if(chemin_s[i]=='T')
                    printf("TP\n");
                else if(chemin_s[i]=='D')
                    printf("GAUCHE\n");
                else if(chemin_s[i]=='G')
                    printf("DROITE\n");
                else if(chemin_s[i]=='H')
                    printf("BAS\n");
                else if(chemin_s[i]=='B')
                    printf("HAUT\n");
            }
}
