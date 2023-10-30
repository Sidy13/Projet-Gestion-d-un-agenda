#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

int main()
{
    //Test 1
    t_d_cell  cell = CreateCell(10000, 2);
    t_d_list list = emptylist(10);
    addcell_headlist(&cell,&list,10);
    display_cell_list(list, 0);
    display_all_level(list, 9);

    //Test 2
    t_d_cell cell2 = CreateCell(22222,1);
    t_d_list list2 = emptylist(10);
    addcell_headlist(&cell2,&list2,10);
    display_cell_list(list2, 0);
    display_all_level(list2, 9);
    return 0;
}
