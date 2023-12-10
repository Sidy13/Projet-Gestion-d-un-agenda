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
    for (int i = 0; i < level; i++){
        cell.next[i] = NULL;
    }
    return cell;
}

// Initialise une liste avec un certain nombre de niveaux
t_d_list emptylist(int max_level){
    t_d_list list;
    list.head = (t_d_cell**) malloc((max_level+1) * sizeof(t_d_cell));
    list.hauteur = max_level;
    for (int i = 0; i < max_level; i++){
        list.head[i] = NULL;
    }
    return list;
}

// Ajoute une cellule en tant que nouvelle tête dans tous les niveaux de la liste
t_d_list *addcell_headlist(t_d_cell *cell, t_d_list *list, int max_level){
    for (int i = 0; i < max_level; i++) {
        // Si la tête du niveau est vide, la nouvelle cellule devient la tête
        if (list->head[i] == NULL) {
            list->head[i] = cell;
        } else {
            // Sinon, la nouvelle cellule pointe vers l'ancienne tête, et elle devient la nouvelle tête
            cell->next[i] = list->head[i];
            list->head[i] = cell;
        }
    }
    return list;
}

// Affiche tous les éléments d'un niveau de la liste
void display_one_level(t_d_list list, int level) {
    if (level > list.hauteur) {
        printf("Niveau supérieur à la hauteur de la liste \n");
        return;
    } else if (list.head[level] == NULL) {
        printf("[ list  head_%d @-] --> ", level);
        printf("NULL ");
    } else {
        printf("[ list  head_%d @-] --> ", level);
        // Parcourt tous les éléments du niveau et les affiche
        for (t_d_cell *cell = list.head[level]; cell != NULL; cell = cell->next[level]) {
            printf("[ %d | @- ] --> ", cell->value);
        }
        printf("NULL ");
    }
}

// Affiche tous les niveaux de la liste jusqu'à un certain niveau
void display_all_level(t_d_list list, int level) {
    if (level > list.hauteur) {
        printf("Niveau trop élevé pour la liste");
    } else {
        for (int i = 0; i < level; i++) {
            // Affiche les éléments de chaque niveau
            display_one_level(list, i);
            printf("\n");
        }
        printf("\n\n");
    }
}

// Ajoute une cellule à la liste à un emplacement approprié en fonction de sa valeur
void addcell_anywhere_inlist(t_d_list* list, t_d_cell *cell) {
    if (cell->level > list->hauteur) {
        printf("Niveau trop élevé pour la liste \n");
        return;
    } else {
        for (int i = 0; i < cell->level; i++) {
            if (list->head[i] == NULL  || cell->value <= list->head[i]->value) {
                // Si la tête du niveau est vide ou si la valeur de la cellule est inférieure à la tête,
                // la cellule devient la nouvelle tête du niveau
                cell->next[i] = list->head[i];
                list->head[i] = cell;
            } else {
                // Sinon, recherche l'emplacement approprié pour la cellule dans le niveau
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



// Partie 2

// Calcule la puissance de deux pour une puissance donnée
int puissance_deux(int power) {
    int puissance = 2;
    if (power == 0) {
        puissance = 1;
        return puissance;
    }
    // Si la puissance est différente de zéro, multiplie 2 par lui-même power fois
    for (int i = 1; i < power; i++) {
        puissance *= 2;
    }
    return puissance;
}

// Crée une liste avec une seule cellule contenant la valeur 1 et le niveau approprié
t_d_list create_tab(int power) {
    t_d_cell newcell;
    t_d_cell *tmp = (t_d_cell*) malloc(sizeof(t_d_cell));
    // Initialise une liste vide avec le nombre de niveaux spécifié
    t_d_list list = emptylist(power);
    // Calcule le nombre total de cellules dans la liste
    int nbcell = puissance_deux(power) - 1;
    int niveau[nbcell];
    for (int i = 0; i < nbcell; i++) {
        niveau[i] = -1;
    }
    // Calcule le niveau de chaque cellule en fonction de sa position dans la liste
    for (int i = 0; i < nbcell; i++) {
        for (int j = 0; j < power; j++) {
            if ((i + 1) % puissance_deux(j) == 0) {
                niveau[i]++;
            }
        }
    }
    // Crée une cellule avec la valeur 1 et le niveau calculé, puis l'ajoute à la tête de la liste
    for (int k = 0; k < 1; k++) {
        newcell = CreateCell(k + 1, niveau[k]);
        addcell_headlist(&newcell, &list, power);
    }

    return list;
}

// Recherche une valeur donnée au niveau 0 de la liste
int search_at_zero(t_d_list list, int val) {
    t_d_cell *tmp = list.head[0];
    if (tmp == NULL) {
        // Si la tête du niveau 0 est nulle, la valeur n'est pas présente dans la liste
        return 0;
    }
    // Parcourt les éléments du niveau 0 jusqu'à trouver la valeur ou atteindre la fin de la liste
    while (tmp != NULL) {
        if (tmp->value == val) {
            printf("Valeur %d trouvée au niveau 0", val);
            return 1;
        }
        tmp = tmp->next;
    }
    printf("La valeur %d est absente du niveau 0\n", val);
    return 0;
}

// Recherche une valeur donnée dans la liste en utilisant la recherche dichotomique
int search_from_top(t_d_list list, int val) {
    startTimer();
    int hauteur = list.hauteur;
    t_d_cell *tmp;
    int operation = 0;

    // Parcourt les niveaux de la liste de haut en bas
    for (int i = hauteur - 1; i >= 0; i--) {
        tmp = list.head[i];
        int gauche = 0;
        int droite = 0;

        // Compte le nombre d'éléments dans le niveau actuel
        while (tmp != NULL) {
            droite++;
            tmp = tmp->next[i];
        }

        tmp = list.head[i];

        // Recherche dichotomique dans le niveau actuel
        while (gauche <= droite) {
            int milieu = (gauche + droite) / 2;
            operation++;

            if (tmp != NULL) {
                // Accède à l'élément à la position milieu dans la liste du niveau i
                t_d_cell *current = tmp;

                // Avance jusqu'à la position milieu
                for (int j = 0; j < milieu; j++) {
                    if (current != NULL) {
                        current = current->next[i];
                    }
                }

                if (current != NULL) {
                    if (current->value == val) {
                        printf("Valeur %d trouvée au niveau %d\n", val, i);
                        if (operation > 1) {
                            printf("%d opérations effectuées\n", operation);
                        } else {
                            printf("%d opération effectuée\n", operation); // Différence singulier-pluriel
                        }
                        stopTimer();
                        displayTime();
                        return 1;
                    } else if (current->value < val) {
                        gauche = milieu + 1;
                    } else {
                        droite = milieu - 1;
                    }
                } else {
                    droite = milieu - 1;
                }
            } else {
                droite = milieu - 1;
            }
        }
    }

    printf("La valeur %d est absente de la liste\n", val);
    printf("%d opérations effectuées\n", operation);
    stopTimer();
    displayTime();
    return 0;
}

// Partie 3

int menuPrinc() // Permet de séléctionner la rubrique souhaitée par l'utilisateur
{
    int ChoiceMenu = 1;

    printf("==================== Menu Principal =======================\n"
           "|                   1.Rechercher un contact                |\n"
           "|             2.Afficher les rendez-vous d'un contact      |\n"
           "|                     3.Créer un contact                   |\n"
           "|             4.Créer un rendez-vous pour un contact       |\n"
           "|               5.Supprimer un rendez-vous                 |\n"
           "|      6.Sauvegarder le fichier de tous les rendez-vous    |\n"
           "|            7.Charger un fichier de  rendez-vous          |\n"
           "|  8.Temps de calcul pour une insertion de nouveau contact |\n"
           "|                   9.Quitter le programme                 |\n");
    printf("===========================================================\n\n");
    do
    {
        printf("~~Quel est votre choix?~~\n");
        printf("Selectionnez votre choix en tapant de 1 a 9 en fonction des rubriques:");
        scanf("%d", &ChoiceMenu);
        printf("\n");
    }while (ChoiceMenu > 1 && ChoiceMenu > 9 );
    return ChoiceMenu;
}
