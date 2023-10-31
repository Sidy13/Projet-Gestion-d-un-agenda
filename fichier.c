//
// Created by Sidy on 23/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

t_d_cell CreateCell(int val, int level){
    t_d_cell cell;
    cell.value = val;
    cell.level = level;
    cell.next = (t_d_cell**)malloc((level+1) * sizeof(t_d_cell*));
    for (int i = 0; i <level; i++){
        cell.next[i] = NULL;
    }
    return cell;
}

t_d_list emptylist(int max_level){
    t_d_list list;
    list.head = (t_d_cell**) malloc((max_level+1) * sizeof(t_d_cell));
    list.hauteur = max_level;
    for (int i = 0; i<max_level; i++){
        list.head[i] = NULL;
    }
    return list;
}

t_d_list *addcell_headlist(t_d_cell *cell,t_d_list *list, int max_level){
    for (int i = 0; i < max_level; i++) {
        if (list->head[i] == NULL) {
            list->head[i] = cell;
        } else {
            cell->next[i] = list->head[i];
            list->head[i] = cell;
        }
    }
    return list;
}



void display_cell_list (t_d_list list, int level)
{
    if (level > list.hauteur){
        printf("Niveau supérieur à la hauteur de la liste \n");
        return;
    }
    else if (list.head[level] == NULL)
    {
        printf("[ list  head_%d @-] --> ", level);
        printf("NULL ");
    }
    else
    {
        printf("[ list  head_%d @-] --> ", level);
        for (t_d_cell *cell = list.head[level]; cell != NULL; cell = cell->next[level]) {
            printf("[ %d | @- ] --> ",cell->value);
        }
        printf("NULL ");
    }
}


void display_all_level(t_d_list list, int level){
    if (level > list.hauteur){
        printf("Niveau trop élevé pour la liste");
    }
    else {
        for (int i = 0; i < level; i++) {
            display_cell_list(list, i);
            printf("\n");
        }
        printf("\n\n");
    }
}






void addcell_anywhere_inlist(t_d_list* list, t_d_cell *cell, int level)
    {

        if(level > list->hauteur)
        {
            printf("Niveau trop élevé pour la liste");
            return;
        }

        else {

            for (int i = 0; i < level; i++) {
                if (list->head[i] == NULL  || cell->value <= list->head[i]->value)
                {
                    cell->next[i] = list->head[i];
                    list->head[i] = cell;

                }
                else{

                    t_d_cell *tmp;
                    t_d_cell *ptmp;
                    tmp = list->head[i];

                    while (tmp != NULL && cell->value > tmp->value) {
                        ptmp = tmp;
                        tmp = tmp->next[i];

                    }
                    ptmp->next[i] = cell;
                    cell->next[i] = tmp;
                }
            }
        }
    }

/*t_d_list *addcell_level(t_d_cell *cell, t_d_list *list, int level){
    if(list->head[level] == NULL)
    {
        list->head[level] = cell;
    }
    t_d_cell *tmp, *ptmp;
    tmp = list->head[level];
    ptmp = tmp;

    while(tmp != NULL && cell->value > tmp->value)
    {
        ptmp = tmp;
        tmp = *tmp->next;
    }
    ptmp->next = &cell;
    cell->next = &tmp;
}

t_d_list *addcell_list(t_d_cell *cell, t_d_list *list, int level){

}*/

//Partie 2

int create_tab(int power){
    int puissance = 2;
    for (int i = 0; i < power; i++){
        puissance *= 2;
    }
    int *tab[puissance];
}