#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

int main()
{
    t_d_cell  cell = CreateCell(1, 2);
    t_d_cell  cell2 = CreateCell(2, 0);
    t_d_cell  cell3 = CreateCell(3, 2);
    t_d_list list = emptylist(4);
    addcell_headlist(&cell, &list, 3);
    addcell_headlist(&cell2, &list, 2);
    addcell_headlist(&cell3, &list, 5);
    display_all_level(list, 4);


    return 0;
}
