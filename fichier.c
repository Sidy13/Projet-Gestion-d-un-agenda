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
        list->head[i] = list->head[i+1];
    }
    list->head[0] = cell;
    return list;
}

void display_cell_list(t_d_list list, int level) {
    if (level < list.hauteur) {
        t_d_cell *current = list.head[level];
        while (current != NULL) {
            printf("%d ", current->value);
            current = current->next[level];
        }
    }
}