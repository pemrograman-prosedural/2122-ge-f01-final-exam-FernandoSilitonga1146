#ifndef DORM_H
#define DORM_H

#include "gender.h"

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

struct dorm_t
{
  char name[20];
  unsigned short capacity;
  enum gender_t gender;
  unsigned short residents_num;
} Dorm;


struct Dorm create_dorm ( char *_name, unsigned short _capacity, enum gender_t gender );
short findDormIdx ( char* _name, struct Dorm *list, int length );
void print_dorm ( struct Dorm dorm_to_print );
void printDormDetails (struct Dorm dorm_to_print );
#endif
