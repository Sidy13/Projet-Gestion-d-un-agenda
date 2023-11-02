//
// Created by Sidy on 23/10/2023.
//

#ifndef PROJET_GESTION_D_UN_AGENDA_FICHIER_H
#define PROJET_GESTION_D_UN_AGENDA_FICHIER_H
#include <stdio.h>
#include <stdlib.h>
#include "timer.h"

typedef struct s_d_cell
{
    int value;
    struct s_d_cell ** next;
    int level;
} t_d_cell;

typedef struct s_d_list
{
    t_d_cell **head;
    int hauteur;
} t_d_list;


t_d_cell CreateCell(int val, int level);
t_d_list emptylist(int max_level);
t_d_list *addcell_headlist(t_d_cell *cell,t_d_list *list, int max_level);
void display_cell_list(t_d_list list, int level);
void display_all_level(t_d_list list, int level);
void display_aligned_cell(t_d_cell cell, t_d_list list, int level);
void addcell_anywhere_inlist(t_d_list* list, t_d_cell *cell);

//Partie 2

int puissance_deux (int power);
t_d_list create_tab(int power);


#endif //PROJET_GESTION_D_UN_AGENDA_FICHIER_H
