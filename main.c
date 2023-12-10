#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

int main()
{
    t_d_cell  cell = CreateCell(1, 2);
    t_d_cell  cell2 = CreateCell(2, 0);
    t_d_list list = emptylist(4);
    addcell_headlist(&cell, &list, 4);
    display_all_level(list, 4);
    addcell_anywhere_inlist(&list, &cell);
    //J'ai ajouté le paramètre level sinon j'avais une boucle infinie
    //cell->level se transforme donc en level
    */
    t_d_cell  cell = CreateCell(1, 2);
    t_d_list list = emptylist(4);
    addcell_headlist(&cell, &list, 4);
    display_all_level(list, 4);
    t_d_list l2 = create_tab(3);
    addcell_headlist(&cell, &l2, 4);
    display_cell_list(l2, 1);

    ChoiceMenu = menuPrinc();
    do
    {
        if (ChoiceMenu == 1) ///Rechercher un contact
        {

        }
        else if (ChoiceMenu == 2) ///Afficher les rendez-vous d'un contact
        {

        }
        else if(ChoiceMenu == 3) ///Créer un contact
        {

        }
        else if (ChoiceMenu == 4)///Créer un rendez-vous pour un contact
        {

        }

        else if (ChoiceMenu == 5) ///Supprimer un rendez-vous
        {

        }
        else if (ChoiceMenu == 6)///Sauvegarder le fichier de tous les rendez-vous
        {

        }
        else if (ChoiceMenu == 7)///Charger un fichier de  rendez-vous
        {

        }
        else if (ChoiceMenu == 8)///Temps de calcul pour une insertion de nouveau contact
        {

        }
        else if (ChoiceMenu == 9)///Quitter le programme
        {
            printf("Au revoir !\n");
            QuitProg = 2;
        }
    }while (ChoiceMenu < 1 && ChoiceMenu > 9);*/

    return 0;
}
