#include <stdio.h>
#include <stdlib.h>
#include "contactDefns.h"
int main(){
    int i;
    int j;
    int *k;
    struct contact_data *record;
    
    i = 0;
    j = 0;
    k = &j;
    record = malloc(sizeof(struct contact_data*));
    loadContacts(k, record);
/*        printf("\e[H\e[2J");*/
    displayContacts(k, record);
    printf("2");
    saveContacts(record, k);
    return 0;
}
