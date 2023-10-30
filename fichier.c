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
    for(int i = 0; i<max_level; i++){
        list->head[i] = *cell->next;
    }
    list->head[0] = cell;
    return list;
}

void display_cell_list(t_d_list list, int level) {
    if (level < list.hauteur){
        t_d_cell *newcell = list.head[level];
        while (newcell != NULL){
            printf("%d ", newcell->value);
            newcell = newcell->next[level];
        }
    }
}


void display_all_level(t_d_list list, int level) {
    if (level < list.hauteur) {
        for (int i = 0; i < level; i++) {
            t_d_cell *newcell = list.head[i];
            printf("Niveau %d: ", i);
            while (newcell != NULL) {
                printf("%d ", newcell->value);
                newcell = newcell->next[i];
            }
            printf("\n");
        }
    } else {
        printf("Niveau supérieur à la hauteur de la liste.\n");
    }
}

void display_aligned_cell(t_d_cell cell, t_d_list list, int level){

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
