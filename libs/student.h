#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

struct student_t
{ 
    char nim[12]; 
    char nama[40]; 
    char tahun[5]; 
    enum gender_t gender;
    struct dorm_t *dorm;
};

struct student_t create_student(char *_nim, char *_nama, char *_tahun, enum gender_t _gender);
void print_student(struct student_t *_student, int a);
void print_student_detail(struct student_t *_student, int a);
void assign_student(struct student_t *_student,struct dorm_t *_dorm, char *nim, char *nama);
void student_leave(struct student_t *_student, struct dorm_t *_dorm);

#endif