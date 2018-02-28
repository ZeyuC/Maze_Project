#include "list.h"

#include <stdio.h>
#include <stdlib.h>


/* @requires   
   @assigns    initialisation de la liste
   @ensures    retourne un NULL list
*/
list inti_list()

{
    list front_node = (list)malloc(sizeof(struct node));
    front_node->value=0;
    front_node->next=NULL;
    return front_node;
}

/* @requires   l non null
   @assigns    l
   @ensures    retourne un NULL list
*/
int if_empty(list l)
{
    l=l->next;
    if (l== NULL)
    return 0;
    else return 1; 
}

/* @requires   l non null
   @assigns    currentList
   @ensures    retourne le longeur de list L
   */
int longeur_list (list l)
{
    int n=0;
  list currentList = l;
  while (if_empty(currentList))
  {
    n++;
    currentList=currentList->next;
  }
  return n;
}
/* @requires   l non null,value non null, d non dull
   @assigns    ajoute un nouvaux neoud dans l
   @ensures    retourne un nouveaux l
*/
list insert_head(list l, int  value)
{
    list newnode = (list)malloc(sizeof(struct node));
    list t = l;
    newnode->next=t->next;
    newnode->value=value;
    t->value+=1.0;
    t->next=newnode;

    return l;
}
  
void insert_Head(list* ql, double value) 
{
    *ql=insert_head(*ql,value); 
} 

/* @requires   l non null
   @assigns    print l
   @ensures    ...
*/
void print_list(list l)
{
    list currentList = l;
    while (if_empty(currentList))
    {
        currentList=currentList->next;
        currentList->value++;
        printf("%d\n", currentList->value);        
    }
}
