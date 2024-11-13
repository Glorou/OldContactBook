#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "contactDefns.h"
void contactDetails(struct contact_data *record, int contact_number, int *k){
    char action;
    char string[101];
    int i;
    unsigned int phone_number; 
    action = '\0';

    printf("Contact #%d\n", contact_number + 1);
    if(record[contact_number].first_name[0]){
        printf("First Name: %s\n",record[contact_number].first_name);
    }else{
        printf("First Name: \n");
    }
    if(record[contact_number].last_name[0]){
        printf("Last Name: %s\n",record[contact_number].last_name);
    }else{
        printf("Last Name: \n");
    }
    if(record[contact_number].company_name[0]){
        printf("Company Name: %s\n",record[contact_number].company_name);
    }else{
        printf("Company Name: \n");
    }
    printf("Phone Number: %lu\n",record[contact_number].phone_number);
    printf("Email: %s\n",record[contact_number].email);
    printf("Action:");
    do{
        action = fgetc(stdin);
        fgetc(stdin);
        if(action == 'E'){
            printf("Contact #%d\n", contact_number + 1);
            printf("First Name: %s\n",record[contact_number].first_name);
            printf("Last Name: %s\n",record[contact_number].last_name);
            printf("Company Name: %s\n",record[contact_number].company_name);
            do{
                printf("Phone Number: ");
                fgets(string, 100, stdin);
                phone_number = strtoul(string,NULL, 10);
            }while(phone_number != 0 && (strlen(string) == 7 || strlen(string) == 10));
            do{
                i = 0;
                printf("Email: ");
                fgets(string, 100, stdin);
                i = sscanf(string,"%*s@%*s.%*c%*c%*c");
            }while( i > 0);
            printf("Action:");
            do{
                action = fgetc(stdin);
                fgetc(stdin);
                if(action == 'S'){
                    record[contact_number].phone_number = phone_number;
                    strcpy(record[contact_number].email, string);
                    action = 'R';
                }
            }while(action != 'R' || action != 'D');
        }
        if(action == 'D'){
            for(i = contact_number; i < *k; i++){
                record[i] = record[i+1];
            }
            free(record[*k]);
            k--;
        }
    }while(action != 'R');
    return;
}

