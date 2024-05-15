#include <stdio.h>
#include <string.h>
#include "dorm.h"

Dorm create_dorm(char *_name, unsigned short _capacity, enum gender_t gender) {
    Dorm dorm_;
    strcpy(dorm_.name, _name);
    dorm_.capacity = _capacity;
    dorm_.gender = gender;
    dorm_.residents_num = 0;
    return dorm_;
}

void print_dorm(Dorm dorm_to_print) {
    printf("Dorm Name: %s\nCapacity: %d\nGender: %s\nResidents: %d\n",
           dorm_to_print.name, dorm_to_print.capacity,
           dorm_to_print.gender == GENDER_MALE ? "Male" : "Female",
           dorm_to_print.residents_num);
}

void printDormDetails(Dorm dorm_to_print) {
    printf("Dorm Details:\n");
    print_dorm(dorm_to_print);
}

short int findDormIdx(char *name, Dorm *dorms, unsigned short totalDorm) {
    for (short i = 0; i < totalDorm; i++) {
        if (strcmp(dorms[i].name, name) == 0) {
            return i;
        }
    }
    return -1;  
}
