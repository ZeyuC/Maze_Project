#ifndef IPI_LIST_H
#define IPI_LIST_H

typedef struct node* list;
struct node                            /*j'utilise list pour realsier cette fonction */
{
    int  value;
    list next;             /* si il est ete visité, 0 non, 1 oui*/
   /* int distance;          la distance du point s*/
};
/* @requires   
   @assigns    initialisation de la liste
   @ensures    retourne un NULL list
*/
list inti_list();
/* @requires   l non null
   @assigns    l
   @ensures    retourne un NULL list
*/
int if_empty(list l);
/* @requires   l non null
   @assigns    currentList
   @ensures    retourne le longeur de list L
   */
int longeur_list (list l);
/* @requires   l non null,value non null, d non dull
   @assigns    ajoute un nouvaux neoud dans l
   @ensures    retourne un nouveaux l
*/
list insert_head(list l, int  value);
void insert_Head(list* ql, double value) ;
/* @requires   l non null
   @assigns    print l
   @ensures    ...
*/
void print_list(list l);
/* @requires   matrix non null,s,t,n non null
   @assigns    cherche un chemin plus court entre s et t
   @ensures    ...
*/
#endif