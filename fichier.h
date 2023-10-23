//
// Created by Sidy on 23/10/2023.
//

#ifndef PROJET_GESTION_D_UN_AGENDA_FICHIER_H
#define PROJET_GESTION_D_UN_AGENDA_FICHIER_H
#include <stdio.h>
#include <stdlib.h>


typedef struct s_d_cell
{
    int value;
    struct s_d_cell *next_0;
    struct s_d_cell *next_1;
} t_d_cell;

typedef struct s_d_list
{
    t_d_cell *head_0;
    t_d_cell *head_1;
} t_d_list;

#endif //PROJET_GESTION_D_UN_AGENDA_FICHIER_H
