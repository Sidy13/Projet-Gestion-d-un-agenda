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





void addcell_anywhere_inlist(t_d_list* list, t_d_cell *cell)
    {

        if(cell->level > list->hauteur)
        {
            printf("Niveau trop élevé pour la liste \n");
            return;
        }

        else {
            for (int i = 0; i < cell->level; i++) {
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


//Partie 2

int puissance_deux (int power){
    int puissance = 2;
    if (power == 0){
        puissance = 1;
        return puissance;
    }
    for (int i = 1; i < power; i++){
        puissance *= 2;
    }
    return puissance;
}
/*t_d_list create_tab(int value) {

    int val_max = puissance_deux(value) ;

    t_d_list list = emptylist(value);

    for (int i = 1; i < val_max; i++) {
        int level = 1;
        while (i % (1 << level) == 0) {
            level++;
        }
        t_d_cell tmp = (CreateCell(i, level));
        addcell_anywhere_inlist(&list, &tmp);
    }

    // Retourner la liste
    return list;
}*/


t_d_list create_tab(int power){

    t_d_cell newcell;
    t_d_cell *tmp = (t_d_cell*) malloc(sizeof(t_d_cell));
    t_d_list list = emptylist(power);
    int nbcell = puissance_deux(power) - 1;
    int niveau[nbcell];
    for (int i = 0; i< nbcell; i++){
        niveau[i] = -1;
    }
    for(int i = 0; i < nbcell; i++) {
        for (int j = 0; j < power; j++) {
            if ((i+1) % puissance_deux(j) == 0){
                niveau[i]++;
            }
        }
    }
    for (int k = 0; k < 1; k++){
        newcell = CreateCell(k+1, niveau[k]);
        addcell_headlist(&newcell, &list, power);
    }

    return list;
}

int search_at_zero(t_d_list list, int val){
    int compteur = 0;
    t_d_cell *tmp = list.head[0];
    if (tmp == NULL){
        return 0;
    }
    while (tmp != NULL) {
        if (tmp->value == val) {
            printf("Valeur %d trouvée au niveau 0", val);
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

/*int search_from_top(t_d_list list, int val){
    int compteur = 0;
    int hauteur = list.hauteur;
    t_d_cell *tmp;
    for (int i = hauteur-1; i >=0; i--){
        tmp = list.head[i];
        while (tmp != NULL) {
            if (tmp->value == val) {
                printf("%d trouvé au niveau %d", val, i);
                return 1;
            }
            tmp = tmp->next;
        }
    }
    return 0;
}*/

/*int search_from_top(t_d_list list, int val) { // Recherche dichotomique
    printf("test");
    int hauteur = list.hauteur;
    t_d_cell *tmp;
    printf("test");
    int gauche = 0;
    int droite = 0;

    for (int i = hauteur - 1; i >= 0; i--) {
        tmp = list.head[i];
        droite = 0;
        gauche = 0;
        while (tmp != NULL) {
            droite++;
            tmp = tmp->next;
        }
        tmp = list.head[i];
            while (gauche <= droite) {
                int milieu = (gauche + droite) / 2;
                if ((tmp != NULL) && (tmp->next[milieu] != NULL)){
                    if (tmp->next[milieu]->value == val) {
                        printf("%d trouvée au niveau %d\n", val, i);
                        return 1;
                    } else if (tmp->next[milieu]->value < val) {
                        gauche = milieu + 1;
                    } else {
                        droite = milieu - 1;
                    }
            }
        }
    }
    printf("%d absent de la liste\n", val);
    return 0;
}*/

int search_from_top(t_d_list list, int val) {
    int hauteur = list.hauteur;
    t_d_cell *tmp;
    int gauche, droite, milieu;

    for (int i = hauteur - 1; i >= 0; i--) {
        tmp = list.head[i];

        // Initialisation de gauche et droite en fonction de la taille de la liste
        gauche = 0;
        droite = 0;
        while (tmp != NULL) {
            droite++;
            tmp = tmp->next;
        }

        tmp = list.head[i];

        while (gauche <= droite) {
            milieu = (gauche + droite) / 2;

            if ((tmp != NULL) && (tmp->next != NULL)) {
                // Accéder à l'élément à la position milieu dans la liste du niveau i
                t_d_cell *current = tmp->next[milieu];

                if (current != NULL) {
                    if (current->value == val) {
                        printf("%d trouvée au niveau %d\n", val, i);
                        return 1;
                    } else if (current->value < val) {
                        gauche = milieu + 1;
                    } else {
                        droite = milieu - 1;
                    }
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }

    printf("%d est absent de la liste\n", val);
    return 0;
}
