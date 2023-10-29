//
// Created by Sidy on 23/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

t_d_cell CreateCell(int val, int level){
    t_d_cell cell;
    cell.value = val;
    if (level == 0){
    cell.next_0 = NULL;
    }
    else {
        cell.next_0 = NULL;
        cell.next_1 = NULL;
    }
    return cell;
}
