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

    return 0;
}
